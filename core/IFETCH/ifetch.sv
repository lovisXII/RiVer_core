module ifetch(
    // global interface
    input logic clk,
    input logic reset_n,

    // Icache interface
    input logic [31:0] IC_INST_SI,
    input logic IC_STALL_SI,
    output logic [31:0] ADR_SI,
    output logic ADR_VALID_SI,

    // dec2if interface
    input logic DEC2IF_EMPTY_SD,
    output logic DEC2IF_POP_SI,

    // if2dec interface
    input logic IF2DEC_FLUSH_SD,
    input logic IF2DEC_POP_SD,
    output logic IF2DEC_EMPTY_SI,

    input logic [31:0] PC_RD,
    output logic [31:0] INSTR_RI,
    output logic [31:0] PC_IF2DEC_RI,

    // Exception
    input logic EXCEPTION_SM,
    output logic EXCEPTION_RI,

    // Branch prediction
    input logic PRED_FAILED_RD,
    input logic PRED_SUCCESS_RD,
    input logic BRANCH_INST_RD,
    input logic [31:0] BRANCH_INST_ADR_RD,
    input logic [31:0] ADR_TO_BRANCH_RD,

    input logic [31:0] PRED_ADR_SD,
    input logic PRED_TAKEN_SD,

    input logic PUSH_ADR_RAS_RD,
    input logic POP_ADR_RAS_RD,
    input logic [31:0] ADR_TO_RET_RD,
    input logic RET_INST_RD,

    output logic [31:0] PRED_ADR_RI,
    output logic PRED_TAKEN_RI
);

    logic if2dec_push_si, if2dec_full_si, if2dec_empty;
    logic stall_si;
    enum logic [1:0] {strongly_taken, weakly_taken, weakly_not_taken, strongly_not_taken} pred_state_t;
    const logic [31:0] nop_i = 32'h13;

    parameter PRED_REG_SIZE = 4;
    parameter RET_PRED_REG_SIZE = 4;
    parameter PRED_POINTER_SIZE = 2;
    parameter RET_PRED_POINTER_SIZE = 2;
    parameter RET_STACK_SIZE = 8;

    // Internal signals

    logic [96:0] if2dec_din, if2dec_dout;

    logic [1:0] next_pred_state ;

    logic [31:0] branch_adr_reg   [PRED_REG_SIZE-1:0];
    logic [31:0] predicted_adr_reg[PRED_REG_SIZE-1:0];

    logic [1:0] pred_state_reg [PRED_REG_SIZE-1:0];
    logic [PRED_REG_SIZE-1:0]      pred_valid_reg ;

    logic [31:0] pred_next_adr_si = 32'h11111100;
    logic [PRED_POINTER_SIZE-1:0] pred_write_pointer_si;

    // Ret prediction 
    //logic [31:0] ret_adr_reg[0:RET_PRED_REG_SIZE-1];
    //logic [31:0] ret_stack_reg[0:RET_STACK_SIZE-1];
    //logic [RET_PRED_REG_SIZE-1:0] ret_valid_reg;
    //logic [RET_PRED_POINTER_SIZE-1:0] ret_write_pointer_si;
    logic [31:0] pred_branch_next_adr = 32'h22222200;
    //logic [RET_STACK_SIZE-1:0] ret_stack_pointer_si;
    //logic [31:0] pred_ret_next_adr = 32'h33333300;

    logic pred_branch_taken;
    //logic pred_ret_taken;

    fifo #(.N(97)) if2dec (
        .clk(clk),
        .reset_n(reset_n),
        .DIN(if2dec_din),
        .PUSH(if2dec_push_si),
        .POP(IF2DEC_POP_SD),
        .FULL(if2dec_full_si),
        .EMPTY(if2dec_empty),
        .DOUT(if2dec_dout)
    );

    assign stall_si = IC_STALL_SI || if2dec_full_si || DEC2IF_EMPTY_SD;

    assign if2dec_push_si = (IF2DEC_FLUSH_SD && !EXCEPTION_SM) ? !stall_si : 1'b0;
    assign DEC2IF_POP_SI = (!IF2DEC_FLUSH_SD && !EXCEPTION_SM) ? !stall_si : 1'b1;
    assign ADR_VALID_SI = (!DEC2IF_EMPTY_SD && (IF2DEC_FLUSH_SD == 1'b0) && (EXCEPTION_SM == 1'b0)) ? 1'b1 : 1'b0;

    assign ADR_SI = (PRED_TAKEN_SD && !PRED_FAILED_RD) ? PRED_ADR_SD : PC_RD;

    //----------------------
    //-- Branch prediction
    //----------------------
    always_ff @(posedge clk or negedge reset_n) begin
        if (!reset_n) begin
            next_pred_state <= weakly_taken;
        end
        else begin
            if (PRED_FAILED_RD || PRED_SUCCESS_RD) begin
                for (integer i=0; i<PRED_REG_SIZE; i++) begin
                    if ((branch_adr_reg[i] != 32'h0) && (BRANCH_INST_ADR_RD != 32'h0)) begin
                        case (pred_state_reg[i])
                            strongly_taken: begin
                                next_pred_state <= strongly_taken;
                                if (!PRED_SUCCESS_RD) begin
                                    next_pred_state <= weakly_taken;
                                end
                            end
                            
                            weakly_taken: begin
                                next_pred_state <= strongly_taken;
                                if (!PRED_SUCCESS_RD) begin
                                    next_pred_state <= weakly_not_taken;
                                end
                            end
                            
                            weakly_not_taken: begin
                                next_pred_state <= weakly_taken;
                                if (!PRED_SUCCESS_RD) begin
                                    next_pred_state <= strongly_not_taken;
                                end
                            end
                            
                            strongly_not_taken: begin
                                next_pred_state <= weakly_not_taken;
                                if (!PRED_SUCCESS_RD) begin
                                    next_pred_state <= strongly_not_taken;
                                end
                            end
                        endcase
                    end
                end
            end
        end
    end
    always_ff @(posedge clk or negedge reset_n) begin
        integer index;
        logic found;
        logic [PRED_POINTER_SIZE-1:0] pred_write_pointer;

        if (!reset_n) begin
            pred_write_pointer <= '0;
            pred_valid_reg <= '0;
        end
        else begin
            if (BRANCH_INST_RD && !if2dec_empty) begin
                found = 0;
                for (integer i = 0; index < PRED_REG_SIZE; index++) begin
                    if (branch_adr_reg[index] == BRANCH_INST_ADR_RD) begin
                        if (!found) begin
                            index = i;
                        end
                        found = 1;
                    end
                end
                
                if (!found) begin
                    branch_adr_reg[pred_write_pointer] <= BRANCH_INST_ADR_RD;
                    predicted_adr_reg[pred_write_pointer] <= ADR_TO_BRANCH_RD;
                    pred_state_reg[pred_write_pointer] <= weakly_taken;
                    pred_valid_reg[pred_write_pointer] <= 1;
                    pred_write_pointer <= pred_write_pointer + { { PRED_POINTER_SIZE - 2 {1'b0} }, 1'b1 };
                end
                else begin
                    pred_state_reg[index] <= next_pred_state;
                end
                
                pred_write_pointer_si <= pred_write_pointer;
            end
        end
    end
    always_comb begin
        integer i;
        logic found, pred_good;
        found = 0;
        pred_good = 0;
        
        for (i = 0; i < PRED_REG_SIZE; i++) begin
            if ((branch_adr_reg[i] == PC_RD) && (pred_valid_reg[i] == 1'b1)) begin
                if (!found) begin
                    found = 1;
                    pred_branch_next_adr = predicted_adr_reg[i];
                    if ((pred_state_reg[i] == strongly_taken) || (pred_state_reg[i] == weakly_taken)) begin
                        pred_good = 1;
                    end else begin
                        pred_good = 0;
                    end
                end
            end
        end
        
        if (found && pred_good) begin
            pred_branch_taken = 1'b1;
        end else begin
            pred_branch_taken = 1'b0;
        end
    end


    /*
    //----------------------
    //-- Ret prediction
    //----------------------
    always_ff @(posedge clk or negedge reset_n) begin
    logic found;
    
    if (!reset_n) begin
        ret_write_pointer_si <= { { PRED_POINTER_SIZE - 2 {1'b0} }, 1'b1 };
        ret_valid_reg <= '0;
    end else begin
        found = 0;
        if (RET_INST_RD && !if2dec_empty) begin
            for (integer i = 0; i < RET_PRED_REG_SIZE; i++) begin
                if (ret_adr_reg[i] == BRANCH_INST_ADR_RD) begin
                    found = 1;
                end
            end
            if (!found) begin
                ret_adr_reg[ret_write_pointer_si] <= BRANCH_INST_ADR_RD;
                ret_valid_reg[ret_write_pointer_si] <= 1'b1;
                ret_write_pointer_si <= {ret_write_pointer_si[RET_PRED_POINTER_SIZE-2:0], 1'b0};
            end
        end
    end
end

always_ff @(posedge clk or negedge reset_n) begin
    logic found, adr_pushed;
    logic [RET_STACK_SIZE-1:0] ret_stack_pointer;
    
    if (!reset_n) begin 
        pred_ret_taken <= 1'b0;
        ret_stack_pointer <= { { RET_STACK_SIZE - 2 {1'b0} }, 1'b1 };
    end else begin 
        found = 0;
        adr_pushed = 0;
        ret_stack_pointer = ret_stack_pointer_si;
        
        for (integer i = 0; i < RET_PRED_REG_SIZE; i++) begin
            if (ret_adr_reg[i] == PC_RD && ret_valid_reg[i]) begin
                found = 1;
            end
        end
        
        pred_ret_taken <= found;
        
        if (!if2dec_empty) begin
            if (PUSH_ADR_RAS_RD) begin
                for (integer i = 0; i < RET_STACK_SIZE; i++) begin
                    if (ret_stack_pointer[i]) begin
                        ret_stack_reg[i] <= ADR_TO_RET_RD;
                        adr_pushed = 1;
                    end
                end
                ret_stack_pointer <= {ret_stack_pointer[RET_STACK_SIZE-2:0], 1'b0};
            end else if (POP_ADR_RAS_RD) begin
                ret_stack_pointer <= {1'b0, ret_stack_pointer[RET_STACK_SIZE-1:1]};
            end
            
            if (found) begin
                for (integer i = 0; i < RET_STACK_SIZE-1; i++) begin
                    if (ret_stack_pointer[i+1]) begin
                        if (adr_pushed) begin
                            pred_ret_next_adr <= ADR_TO_RET_RD;
                        end else begin
                            pred_ret_next_adr <= ret_stack_reg[i];
                        end
                    end
                end
                ret_stack_pointer <= {1'b0, ret_stack_pointer[RET_PRED_REG_SIZE-1:1]};
            end
        end
    end
    ret_stack_pointer_si <= ret_stack_pointer;
end
*/
assign EXCEPTION_RI = 1'b0; 
assign IF2DEC_EMPTY_SI = if2dec_empty; 

//----------------------
//-- fifo
//----------------------
//-- Input

assign if2dec_din[31:0] = (PRED_TAKEN_SD && !PRED_FAILED_RD) ? PRED_ADR_SD : PC_RD ;
assign if2dec_din[63:32] = EXCEPTION_SM ? nop_i : IC_INST_SI;

assign if2dec_din[95:64] =  pred_branch_next_adr;//pred_branch_taken ? pred_branch_next_adr : pred_ret_taken ? pred_ret_next_adr : 32'h44444400;

assign if2dec_din[96] = pred_branch_taken; //| pred_ret_taken;

// Output
assign PC_IF2DEC_RI = if2dec_dout[31:0];
assign INSTR_RI = if2dec_dout[63:32];
assign PRED_ADR_RI = if2dec_dout[95:64];
assign PRED_TAKEN_RI = if2dec_dout[96];

endmodule
