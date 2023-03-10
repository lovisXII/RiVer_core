module exe (
    // global interface
    input logic clk,
    input logic reset_n,

    input logic [31:0] OP1_RD, OP2_RD,
    input logic [5:0] RADR1_RD, RADR2_RD,
    input logic [31:0] MEM_DATA_RD,
    input logic [5:0] DEST_RD,
    input logic [1:0] CMD_RD,
    input logic [1:0] MEM_SIZE_RD,
    input logic NEG_OP2_RD,
    input logic WB_RD,
    input logic MEM_SIGN_EXTEND_RD,
    input logic [3:0] SELECT_OPERATION_RD,
    input logic MEM_LOAD_RD, MEM_STORE_RD,
    input logic EXE2MEM_POP_SM,
    input logic DEC2EXE_EMPTY_SD,
    input logic SLT_RD, SLTU_RD,

    output logic [31:0] RES_RE,
    output logic [31:0] MEM_DATA_RE,
    output logic [5:0] DEST_RE,
    output logic [1:0] MEM_SIZE_RE,
    output logic WB_RE,
    output logic MEM_SIGN_EXTEND_RE,
    output logic MEM_LOAD_RE, MEM_STORE_RE,
    output logic EXE2MEM_EMPTY_SE,
    output logic DEC2EXE_POP_SE,

    input logic [31:0] PC_DEC2EXE_RD,
    output logic [31:0] PC_EXE2MEM_RE,

    // bypasses
    input logic BLOCK_BP_RD,
    input logic [5:0] MEM_DEST_RM,
    input logic [31:0] MEM_RES_RM,
    input logic CSR_WENABLE_RM,
    input logic [31:0] CSR_RDATA_RM,
    input logic BP_MEM2WBK_EMPTY_SM,

    // CSR
    input logic CSR_WENABLE_RD,
    input logic [11:0] CSR_WADR_RD,
    input logic [31:0] CSR_RDATA_RD,

    // Multiplier
    input logic MULT_INST_RM,
    input logic MULT_INST_RD,
    output logic MULT_INST_RE,
    output logic [31:0] OP1_SE, OP2_SE,

    // Exception
    input logic EXCEPTION_SM,
    input logic EXCEPTION_RD,
    input logic [1:0] CURRENT_MODE_SM,
    input logic [31:0] PC_BRANCH_VALUE_RD,
    output logic [31:0] PC_BRANCH_VALUE_RE,

    input logic ILLEGAL_INSTRUCTION_RD,
    input logic ADRESS_MISALIGNED_RD,
    input logic INSTRUCTION_ACCESS_FAULT_RD,
    input logic ENV_CALL_U_MODE_RD,
    input logic ENV_CALL_S_MODE_RD,
    input logic ENV_CALL_M_MODE_RD,
    input logic ENV_CALL_WRONG_MODE_RD,
    input logic MRET_RD,
    input logic EBREAK_RD,

    output logic EXCEPTION_RE,
    output logic ILLEGAL_INSTRUCTION_RE,
    output logic ADRESS_MISALIGNED_RE,
    output logic INSTRUCTION_ACCESS_FAULT_RE,
    output logic ENV_CALL_U_MODE_RE,
    output logic ENV_CALL_S_MODE_RE,
    output logic ENV_CALL_M_MODE_RE,
    output logic ENV_CALL_WRONG_MODE_RE,
    output logic LOAD_ADRESS_MISALIGNED_RE,
    output logic LOAD_ACCESS_FAULT_RE,
    output logic STORE_ADRESS_MISALIGNED_RE,
    output logic STORE_ACCESS_FAULT_RE,
    output logic MRET_RE,
    output logic EBREAK_RE,

    output logic CSR_WENABLE_RE,
    output logic [11:0] CSR_WADR_RE,
    output logic [31:0] CSR_RDATA_RE
);

logic [199:0] exe2mem_data, exe2mem_x;
logic [199:0] exe2mem_din, exe2mem_dout;

logic [31:0] op1, op2;
logic [31:0] alu_op2;
logic [31:0] alu_res;

logic [31:0] shifter_res;

logic [31:0] exe_res;

logic exe2mem_push;
logic exe2mem_full;
logic exe2mem_empty;

logic [31:0] slt_res, sltu_res;

logic wb_se, load_se, store_se;

logic stall_se;
logic blocked_se;
logic [31:0] bp_mem_data;
logic r1_valid_se, r2_valid_se;

// bypass
logic bpc_ee1, bpc_me1;
logic bpc_ee2, bpc_me2;
logic bpc_disable1, bpc_disable2;

// exception
logic adress_misaligned = 1'b0;
logic load_adress_misaligned_se = 1'b0;
logic store_adress_misaligned_se = 1'b0;
logic access_fault = 1'b0;
logic load_access_fault_se = 1'b0;
logic store_access_fault_se = 1'b0;
logic exception_se = 1'b0;

// divider
logic start_div;
logic done_div;
logic busy_div;
logic [31:0] res_div;

// exe output readable
logic [31:0] exe_fifo_res;
logic [5:0] exe_fifo_dest;
logic exe_fifo_mem_store, exe_fifo_mem_load;
logic exe_fifo_wb;
logic [31:0] exe_fifo_csr_data;
logic exe_fifo_csr_wenable;
logic exe_fifo_mult_inst;

alu alu_i (
    .OP1_SE(op1),
    .OP2_SE(alu_op2),
    .CIN_SE(NEG_OP2_RD),
    .CMD_SE(CMD_RD),
    .RES_SE(alu_res)
);

shifter shifter_i (
    .DIN_SE(OP1),
    .SHIFT_VAL_SE(OP2[4:0]),
    .CMD_SE(CMD_RD),
    .DOUT_SE(shifter_res)
);

fifo #(.N(200)) exe2mem (
    .clk(clk),
    .reset_n(reset_n),
    .DIN(exe2mem_din),
    .PUSH(exe2mem_push),
    .POP(EXE2MEM_POP_SM),
    .FULL(exe2mem_full),
    .EMPTY(exe2mem_empty),
    .DOUT(exe2mem_dout)
);

divider divider_i (
    .clk(clk),
    .reset_n(reset_n),
    .OP1_SE(op1),
    .OP2_SE(op2),
    .CMD_RD(CMD_RD),
    .START_DIV(start_div),
    .DONE_DIV(done_div),
    .BUSY_DIV(busy_div),
    .RES_DIV(res_div)
);

// ALU OP2 selection
assign alu_op2 = (NEG_OP2_RD == 1'b1) ? ~op2 : op2;

// SLT/SLTU operation
assign slt_res = ((op1[31] == 1'b1) && (op2[31] == 1'b0)) ? 32'b00000000000000000000000000000001 :
((op1[31] == 1'b0) && (op2[31] == 1'b1)) ? 32'b00000000000000000000000000000000 :
(op1 == op2) ? 32'b00000000000000000000000000000000 :
{alu_res[31], {3'b0, alu_res[30:0]}};

assign sltu_res = ((op1[31] == 1'b1) && (op2[31] == 1'b0)) ? 32'b00000000000000000000000000000000 :
((op1[31] == 1'b0) && (op2[31] == 1'b1)) ? 32'b00000000000000000000000000000001 :
(op1 == op2) ? 32'b00000000000000000000000000000000 :
{alu_res[31], {3'b0, alu_res[30:0]}};

// exe result selection
always_comb begin
if (SELECT_OPERATION_RD == 4'b1000) begin
exe_res = res_div;
end
else if (SELECT_OPERATION_RD == 4'b0010) begin
exe_res = shifter_res;
end
else if ((SELECT_OPERATION_RD == 4'b0001) && (SLT_RD == 1'b1)) begin
exe_res = slt_res;
end
else if ((SELECT_OPERATION_RD == 4'b0001) && (SLTU_RD == 1'b1)) begin
exe_res = sltu_res;
end
else begin
exe_res = alu_res;
end
end

// divider
assign start_div = ((SELECT_OPERATION_RD == 4'b1000) && (DEC2EXE_EMPTY_SD == 1'b0) && (busy_div == 1'b0) && (done_div == 1'b0)) ? 1'b1 : 1'b0;

// fifo
assign stall_se = (exe2mem_full || DEC2EXE_EMPTY_SD || blocked_se || !r1_valid_se || !r2_valid_se || (busy_div && !done_div));
assign exe2mem_push = !stall_se;
assign DEC2EXE_POP_SE = !(stall_se || start_div);

// bypasses
assign bpc_disable1 = (RADR1_RD == 6'h00 || BLOCK_BP_RD == 1'b1) ? 1'b1 : 1'b0;
assign bpc_disable2 = ((RADR2_RD == 6'h00) || (BLOCK_BP_RD == 1'b1) || (MEM_LOAD_RD == 1'b1)) ? 1'b1 : 1'b0;

assign bpc_ee1 = (exe_fifo_dest == RADR1_RD) && (exe_fifo_mem_load == 1'b0) && !bpc_disable1;
assign bpc_me1 = (MEM_DEST_RM == RADR1_RD) && !bpc_disable1;
assign bpc_ee2 = (exe_fifo_dest == RADR2_RD && exe_fifo_mem_load == 0 && bpc_disable2 == 0) ? 1'b1 : 1'b0;
assign bpc_me2 = (MEM_DEST_RM == RADR2_RD && bpc_disable2 == 0) ? 1'b1 : 1'b0;

assign bp_mem_data = (exe_fifo_dest == RADR2_RD && exe_fifo_mem_load == 0 && exe_fifo_mult_inst == 0 && bpc_disable2 == 0 && exe_fifo_csr_wenable == 1) ? exe_fifo_csr_data :
                     (exe_fifo_dest == RADR2_RD && exe_fifo_mem_load == 0 && exe_fifo_mult_inst == 0 && bpc_disable2 == 0) ? exe_fifo_res :
                     (MEM_DEST_RM == RADR2_RD && MEM_STORE_RD == 1 && MULT_INST_RM == 0 && bpc_disable2 == 0) ? MEM_RES_RM :
                     MEM_DATA_RD;

assign op1 = (RADR1_RD == 6'b0 || BLOCK_BP_RD == 1) ? OP1_RD :
              (exe_fifo_dest == RADR1_RD && exe_fifo_csr_wenable == 1) ? exe_fifo_csr_data :
              (exe_fifo_dest == RADR1_RD && exe_fifo_mem_load == 0) ? exe_fifo_res :
              (exe_fifo_dest == RADR1_RD && CSR_WENABLE_RM == 1) ? CSR_RDATA_RM :
              (MEM_DEST_RM == RADR1_RD) ? MEM_RES_RM :
              OP1_RD;

assign op2 = (RADR2_RD == 6'b0 || MEM_LOAD_RD || BLOCK_BP_RD) ? OP2_RD :
             (exe_fifo_dest == RADR2_RD && !exe_fifo_mem_load && !MEM_STORE_RD && !exe_fifo_mult_inst) ? exe_fifo_res :
             (MEM_DEST_RM == RADR2_RD && MEM_STORE_RD && !MULT_INST_RM) ? OP2_RD :
             (MEM_DEST_RM == RADR2_RD && !MEM_STORE_RD && !MULT_INST_RM) ? MEM_RES_RM : OP2_RD;

assign blocked_se = ((exe_fifo_dest == RADR1_RD && exe_fifo_mem_load && !exe2mem_empty) ||
                     (exe_fifo_dest == RADR2_RD && exe_fifo_mem_load && !exe2mem_empty)) ? 1'b1 : 1'b0;

assign adress_misaligned = ((alu_res[1:0] != 2'b00 && MEM_SIZE_RD == 2'b00) ||
                            (alu_res[0] && MEM_SIZE_RD == 2'b01)) ? 1'b1 : 1'b0;

assign load_adress_misaligned_se = MEM_LOAD_RD & adress_misaligned;
assign store_adress_misaligned_se = MEM_STORE_RD & adress_misaligned;

assign access_fault = (alu_res > kernel_adr && CURRENT_MODE_SM == 2'b00) ? 1'b1 : 1'b0;
assign load_access_fault_se = MEM_LOAD_RD & access_fault;
assign store_access_fault_se = MEM_STORE_RD & access_fault;

assign exception_se = (EXCEPTION_RD || load_adress_misaligned_se || load_access_fault_se ||
                       store_access_fault_se || store_adress_misaligned_se) & reset_n;

assign wb_se = exception_se ? 1'b0 : WB_RD;
assign load_se = exception_se ? 1'b0 : MEM_LOAD_RD;
assign store_se = exception_se ? 1'b0 : MEM_STORE_RD;

// Output

assign RES_RE = exe_fifo_res;
assign DEST_RE = exe_fifo_dest; 
assign EXE2MEM_EMPTY_SE = exe2mem_empty;
assign MEM_LOAD_RE = exe_fifo_mem_load; 
assign MEM_STORE_RE = exe_fifo_mem_store; 
assign WB_RE = exe_fifo_wb;
assign CSR_RDATA_RE = exe_fifo_csr_data; 
assign CSR_WENABLE_RE = exe_fifo_csr_wenable; 
assign MULT_INST_RE = exe_fifo_mult_inst;

// Multiplier and divider operands 
assign OP1_SE = op1;
assign OP2_SE = op2; 

// fifo 
assign exe2mem_data[31:0] = exe_res;
assign exe2mem_data[63:32] = bp_mem_data;
assign exe2mem_data[69:64] = DEST_RD;
assign exe2mem_data[71:70] = MEM_SIZE_RD; 
assign exe2mem_data[72] = wb_se;
assign exe2mem_data[73] = load_se; 
assign exe2mem_data[74] = store_se; 
assign exe2mem_data[75] = MEM_SIGN_EXTEND_RD;
assign exe2mem_data[107:76] = PC_DEC2EXE_RD; 
assign exe2mem_data[108] = CSR_WENABLE_RD;
assign exe2mem_data[120:109] = CSR_WADR_RD;
assign exe2mem_data[152:121] = CSR_RDATA_RD; 
assign exe2mem_data[153] = ENV_CALL_S_MODE_RD; 
assign exe2mem_data[154] = ENV_CALL_WRONG_MODE_RD; 
assign exe2mem_data[155] = ILLEGAL_INSTRUCTION_RD; 
assign exe2mem_data[156] = ADRESS_MISALIGNED_RD; 
assign exe2mem_data[157] = ENV_CALL_U_MODE_RD;
assign exe2mem_data[158] = ENV_CALL_M_MODE_RD;
assign exe2mem_data[159] = exception_se; 
assign exe2mem_data[160] = load_adress_misaligned_se; 
assign exe2mem_data[161] = load_access_fault_se; 
assign exe2mem_data[162] = MRET_RD; 
assign exe2mem_data[163] = store_adress_misaligned_se; 
assign exe2mem_data[164] = store_access_fault_se; 
assign exe2mem_data[165] = INSTRUCTION_ACCESS_FAULT_RD; 
assign exe2mem_data[166] = EBREAK_RD; 
assign exe2mem_data[198:167] = PC_BRANCH_VALUE_RD; 
assign exe2mem_data[199] = MULT_INST_RD; 

assign exe2mem_x[75:0] = 0;
assign exe2mem_x[107:76] = PC_DEC2EXE_RD; 
assign exe2mem_x[199:108] = 0;

assign exe2mem_din = (EXCEPTION_SM == 0) ? exe2mem_data : exe2mem_x; 

assign exe_fifo_res = exe2mem_dout[31:0];
assign MEM_DATA_RE = exe2mem_dout[63:32]; 
assign exe_fifo_dest = exe2mem_dout[69:64];  
assign MEM_SIZE_RE = exe2mem_dout[71:70]; 
assign exe_fifo_wb = exe2mem_dout[72];   
assign exe_fifo_mem_load = exe2mem_dout[73];   
assign exe_fifo_mem_store = exe2mem_dout[74];   
assign MEM_SIGN_EXTEND_RE = exe2mem_dout[75];   
assign PC_EXE2MEM_RE = exe2mem_dout[107:76];
assign exe_fifo_csr_wenable = exe2mem_dout[108];
assign CSR_WADR_RE = exe2mem_dout[120:109];
assign exe_fifo_csr_data = exe2mem_dout[152:121];
assign ENV_CALL_S_MODE_RE = exe2mem_dout[153];
assign ENV_CALL_WRONG_MODE_RE = exe2mem_dout[154];
assign ILLEGAL_INSTRUCTION_RE = exe2mem_dout[155];
assign ADRESS_MISALIGNED_RE = exe2mem_dout[156];
assign ENV_CALL_U_MODE_RE = exe2mem_dout[157];
assign ENV_CALL_M_MODE_RE = exe2mem_dout[158];
assign EXCEPTION_RE = exe2mem_dout[159];
assign LOAD_ADRESS_MISALIGNED_RE = exe2mem_dout[160];
assign LOAD_ACCESS_FAULT_RE = exe2mem_dout[161];
assign MRET_RE = exe2mem_dout[162];
assign STORE_ADRESS_MISALIGNED_RE = exe2mem_dout[163];
assign STORE_ACCESS_FAULT_RE = exe2mem_dout[164];
assign INSTRUCTION_ACCESS_FAULT_RE = exe2mem_dout[165];
assign EBREAK_RE = exe2mem_dout[166];
assign PC_BRANCH_VALUE_RE = exe2mem_dout[198:167];
assign exe_fifo_mult_inst = exe2mem_dout[199];

endmodule