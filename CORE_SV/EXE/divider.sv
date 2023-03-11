module divider(
    input logic clk, reset_n,
    input logic [31:0] OP1_SE, OP2_SE,
    input logic [1:0] CMD_RD,
    input logic START_DIV,
    output logic DONE_DIV, BUSY_DIV,
    output logic [31:0] RES_DIV
);

typedef enum logic [2:0] {idle, setup, zero, same_ops, run, done} state_e;
state_e EP, EF; 

logic [1:0] cmd_reg = 2'b00;

logic [31:0] op1, op2;
logic [5:0] shift_cpt_se, shift_cpt_reg = 6'h00;

logic [63:0] divisor_se, reminder_se = 64'h0000_0000_0000_0000;
logic [63:0] divisor_reg, reminder_reg = 64'h0000_0000_0000_0000;
logic [63:0] divisor_setup;

logic [31:0] quotient_se, quotient_reg, quotient = 32'h0000_0000;

logic quotient_sign_se, reminder_sign_se;
logic quotient_sign_reg, reminder_sign_reg;

logic [31:0] remind;

logic signed_inst, division;

logic [31:0] op1_div, op2_div, op1_setup, op2_setup;
logic setup_regs, same, zero_div, running; 

// state transition
always_ff @(posedge clk, negedge reset_n)
begin 
    if (!reset_n) begin
        EP  <=  idle; 
        //divisor_reg     <=  x"0000000000000000";
        //quotient_reg    <=  x"00000000";
        //reminder_reg    <=  x"0000000000000000";
        //shift_cpt_reg   <=  6'b0;
        
    end else begin 
        EP  <=  EF;

        if (START_DIV) begin 
            cmd_reg <= CMD_RD; 
            op1     <=  OP1_SE; 
            op2     <=  OP2_SE;   
        end 
    end 
    case (EP)
        idle: begin
            EF = idle;
            if (START_DIV && OP2_SE != 32'h0000_0000 && OP1_SE == OP2_SE) begin 
                EF  =  same_ops;    
            end else if (START_DIV && OP2_SE != 32'h0000_0000) begin 
                EF  =  setup;  
            end else if (START_DIV && OP2_SE == 32'h0000_0000) begin 
                EF  =  zero;   
            end 
        end
        setup: begin
            EF = run;
        end
        zero: begin
            EF = done;  
        end
        same_ops: begin
            EF = done;      
        end
        run: begin
            EF = run;
            if (shift_cpt_reg == 6'h1F) begin 
                EF  =  done; 
            end 
        end
        done: begin
            EF = idle;  
        end
        default: begin
            EF = idle; 
        end
    endcase 
end 

always_ff @ (posedge EP) begin 
    case (EP)
        idle: begin 
            setup_regs <= 1'b0;
            same <= 1'b0;
            zero_div <= 1'b0;
            running <= 1'b0;
            DONE_DIV <= 1'b0;
            BUSY_DIV <= 1'b0;
        end
        setup: begin
            setup_regs <= 1'b1;
            same <= 1'b0;
            zero_div <= 1'b0;
            running <= 1'b0;
            DONE_DIV <= 1'b0;
            BUSY_DIV <= 1'b1;
        end
        same_ops: begin
            setup_regs <= 1'b0;
            same <= 1'b1;
            zero_div <= 1'b0;
            running <= 1'b0;
            DONE_DIV <= 1'b0;
            BUSY_DIV <= 1'b1;
        end
        zero: begin
            setup_regs <= 1'b0;
            same <= 1'b0;
            zero_div <= 1'b1;
            running <= 1'b0;
            DONE_DIV <= 1'b0;
            BUSY_DIV <= 1'b1;
        end
        run: begin
            setup_regs <= 1'b0;
            same <= 1'b0;
            zero_div <= 1'b0;
            running <= 1'b1;
            DONE_DIV <= 1'b0;
            BUSY_DIV <= 1'b1;
        end
        done: begin
            setup_regs <= 1'b0;
            same <= 1'b0;
            zero_div <= 1'b0;
            running <= 1'b0;
            DONE_DIV <= 1'b1;
            BUSY_DIV <= 1'b1;
        end
        default: begin
            setup_regs <= 1'b0;
            same <= 1'b0;
            zero_div <= 1'b0;
            running <= 1'b0;
            DONE_DIV <= 1'b0;
            BUSY_DIV <= 1'b0;
        end
    endcase
end

always_ff @ (posedge clk) begin 
    if (setup_regs || same || zero_div) begin 
        reminder_sign_reg <= reminder_sign_se;
        quotient_sign_reg <= quotient_sign_se;
    end
    if (setup_regs || zero_div || same || (running && division)) begin 
        reminder_reg <= reminder_se;
    end
    divisor_reg <= divisor_se;
    quotient_reg <= quotient_se;
    shift_cpt_reg <= shift_cpt_se;
end

assign division = (divisor_reg > reminder_reg) ? 1'b1 : 1'b0;

divisor_setup[62:31] <= op2_div; 
divisor_setup[63]    <= 1'b0; 
divisor_setup[30:0]  <= '0;

divisor_se = (setup_regs) ? divisor_setup :
              (running) ? {1'b0, divisor_reg[63:1]} :
              64'h0000000000000000;

quotient_se = (setup_regs) ? 32'h0 :
               (same) ? 32'h00000001 :
               (zero_div) ? 32'hFFFFFFFF :
               {quotient_reg[30:0], division} when running else
               32'h0;

reminder_se = (setup_regs || zero_div) ? {32'h0, op1_div} :
               (running && division) ? $signed(reminder_reg) - $signed(divisor_reg) :
               64'h0000000000000000;

shift_cpt_se = (running) ? $signed(shift_cpt_reg) + $signed(one_ext_6) :
                6'b000000;

op1_div = (setup_regs && signed_inst && op1[31]) ? $signed(~op1) + $signed(one_ext_32) : op1;

op2_div = (setup_regs && signed_inst && op2[31]) ? $signed(~op2) + $signed(one_ext_32) : op2;

signed_inst = (setup_regs && (CMD_RD == 2'b11 || CMD_RD == 2'b01)) ? 1'b1 : 1'b0;

quotient_sign_se = (op1[31] ^ op2[31]) && signed_inst ? 1'b1 : 1'b0;

reminder_sign_se = op1[31] && signed_inst ? 1'b1 : 1'b0;

// Output
remind = (reminder_sign_reg) ? std_logic_vector(unsigned(~reminder_reg[31:0]) + unsigned(one_ext_32)) : reminder_reg[31:0];
quotient = (quotient_sign_reg) ? std_logic_vector(unsigned(~quotient_reg) + unsigned(one_ext_32)) : quotient_reg;
RES_DIV = (cmd_reg == 2'b11 || cmd_reg == 2'b00) ? remind : quotient;

endmodule