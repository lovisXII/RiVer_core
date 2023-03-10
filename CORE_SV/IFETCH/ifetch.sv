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


    enum logic [1:0] {strongly_taken, weakly_taken, weakly_not_taken, strongly_not_taken} pred_state_t;

    parameter PRED_REG_SIZE = 4;
    parameter RET_PRED_REG_SIZE = 4;
    parameter PRED_POINTER_SIZE = 2;
    parameter RET_PRED_POINTER_SIZE = 2;
    parameter RET_STACK_SIZE = 8;

    logic [96:0] if2dec_din, if2dec_dout;
    logic [PRED_REG_SIZE-1:0][31:0] branch_adr_reg, predicted_adr_reg;
    logic [PRED_REG_SIZE-1:0] pred_valid_reg;
    logic [PRED_REG_SIZE-1:0] pred_state_reg;
    logic [RET_PRED_REG_SIZE-1:0] ret_valid_reg;
    logic [RET_PRED_REG_SIZE-1:0][31:0] ret_adr_reg;
    logic [RET_STACK_SIZE-1:0][31:0] ret_stack_reg;

    logic [1:0] next_pred_state = weakly_taken;

    logic stall_si;

always_ff @(posedge PC_RD) begin
    bit found, pred_good;
    found = 1'b0;
    pred_good = 1'b0;
    
    for (int i=0; i<PRED_REG_SIZE; i++) begin
        if (branch_adr_reg[i] == PC_RD && pred_valid_reg[i] == 1'b1) begin
            if (found == 1'b0) begin
                found = 1'b1;
                pred_branch_next_adr <= predicted_adr_reg[i];
                if (pred_state_reg[i] == strongly_taken || pred_state_reg[i] == weakly_taken) begin
                    pred_good = 1'b1;
                end else begin
                    pred_good = 1'b0;
                end
            end
        end
    end
    
    if (found == 1'b1 && pred_good == 1'b1) begin
        pred_branch_taken <= 1'b1;
    end else begin
        pred_branch_taken <= 1'b0;
    end
end

always_ff @(posedge clk or negedge reset_n) begin
    bit found;
    if (!reset_n) begin
        ret_write_pointer_si <= one_ext_ret_size;
        ret_valid_reg <= '0;
    end else if (falling_edge(clk)) begin
        found = 1'b0;
        if (RET_INST_RD && !if2dec_empty) begin
            for (int i=0; i<RET_PRED_REG_SIZE; i++) begin
                if (ret_adr_reg[i] == BRANCH_INST_ADR_RD) begin
                    found = 1'b1;
                end
            end
            
            if (found == 1'b0) begin
                ret_adr_reg[unsigned'(ret_write_pointer_si)] <= BRANCH_INST_ADR_RD;
                ret_valid_reg[unsigned'(ret_write_pointer_si)] <= 1'b1;
                ret_write_pointer_si <= {ret_write_pointer_si[RET_PRED_POINTER_SIZE-2:0], 1'b0};
            end
        end
    end
end
// fifo
// Input

assign if2dec_din[31:0] = PRED_ADR_SD ? ((PRED_TAKEN_SD && !PRED_FAILED_RD) ? PRED_ADR_SD : PC_RD) : PC_RD;
assign if2dec_din[63:32] = EXCEPTION_SM ? nop_i : IC_INST_SI;

assign if2dec_din[95:64] = pred_branch_taken ? pred_branch_next_adr :
pred_ret_taken ? pred_ret_next_adr : 32'h44444400;

assign if2dec_din[96] = pred_branch_taken || pred_ret_taken;

// Output
assign PC_IF2DEC_RI = if2dec_dout[31:0];
assign INSTR_RI = if2dec_dout[63:32];
assign PRED_ADR_RI = if2dec_dout[95:64];
assign PRED_TAKEN_RI = if2dec_dout[96];

endmodule
