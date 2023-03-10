module mem (
    // global interface
    input  logic clk, reset_n,

    // Mcache interface
    input  logic [31:0] MCACHE_RESULT_SM,
    input  logic MCACHE_STALL_SM,
    output logic [31:0] MCACHE_ADR_SM, MCACHE_DATA_SM,
    output logic MCACHE_ADR_VALID_SM,
    output logic MCACHE_STORE_SM, MCACHE_LOAD_SM,
    output logic [3:0] byt_sel,

    // Exe interface
    input  logic [31:0] RES_RE, MEM_DATA_RE,
    input  logic [5:0] DEST_RE,
    input  logic [1:0] MEM_SIZE_RE,
    input  logic WB_RE, SIGN_EXTEND_RE,
    input  logic LOAD_RE, STORE_RE,

    input  logic [31:0] PC_EXE2MEM_RE,

    // Multiplier
    input  logic MULT_INST_RE,
    output logic MULT_INST_RM,

    // exe2mem interface
    input  logic EXE2MEM_EMPTY_SE,
    output logic EXE2MEM_POP_SM,

    // mem2wbk interface
    input  logic MEM2WBK_POP_SW,
    output logic MEM2WBK_EMPTY_SM,

    // Wbk interface
    output logic [31:0] MEM_RES_RM,
    output logic [5:0] MEM_DEST_RM,
    output logic WB_RM,
    output logic [31:0] CSR_RDATA_RM,
    output logic CSR_WENABLE_RM,

    // CSR
    input  logic CSR_WENABLE_RE,
    input  logic [11:0] CSR_WADR_RE,
    input  logic [31:0] CSR_RDATA_RE,

    output logic [11:0] CSR_WADR_SM,
    output logic [31:0] CSR_WDATA_SM,
    output logic CSR_ENABLE_SM,

    output logic [31:0] MSTATUS_WDATA_SM,
    output logic [31:0] MIP_WDATA_SM,
    output logic [31:0] MEPC_WDATA_SM,
    output logic [31:0] MCAUSE_WDATA_SM,
    output logic [31:0] MTVAL_WDATA_SM,

    // Exception
    input  logic EXCEPTION_RE,
    input  logic LOAD_ADRESS_MISALIGNED_RE,
    input  logic LOAD_ACCESS_FAULT_RE,
    input  logic ILLEGAL_INSTRUCTION_RE,
    input  logic INSTRUCTION_ADRESS_MISALIGNED_RE,
    input  logic INSTRUCTION_ACCESS_FAULT_RE,
    input  logic STORE_ADRESS_MISALIGNED_RE,
    input  logic STORE_ACCESS_FAULT_RE,
    input  logic ENV_CALL_U_MODE_RE,
    input  logic ENV_CALL_S_MODE_RE,
    input  logic ENV_CALL_M_MODE_RE,
    input  logic ENV_CALL_WRONG_MODE_RE,
    input  logic MRET_RE,
    input  logic EBREAK_RE,
    input  logic [31:0] PC_BRANCH_VALUE_RE,

    input  logic BUS_ERROR_SX,

    output logic EXCEPTION_SM,
    output logic [1:0] CURRENT_MODE_SM,
    output logic [31:0] RETURN_ADRESS_SM,
    output logic MRET_SM
);

logic [72:0] mem2wbk_din, mem2wbk_dout;
logic mem2wbk_push, mem2wbk_full, stall_sm, wb;
logic [31:0] load_data, load_byte, load_halfword, load_word, data_sm, data_store_sm, data_byte_store_sm, data_half_store_sm;
logic lb_sign, lh_sign, byt_sel_sm [3:0];
logic exception, machine_mode_condition;
logic [1:0] mode_sm, new_mode, old_mode;
logic [31:0] mstatus_x, mcause_x, mtval_x;
logic mem_fifo_mult_inst;

fifo #(73) mem2wbk (
  .clk(clk),
  .reset_n(reset_n),
  .DIN(mem2wbk_din),
  .PUSH(mem2wbk_push),
  .POP(MEM2WBK_POP_SW),
  .FULL(mem2wbk_full),
  .EMPTY(MEM2WBK_EMPTY_SM),
  .DOUT(mem2wbk_dout)
);

// fifo concat   
assign mem2wbk_din[31:0] = data_sm; 
assign mem2wbk_din[37:32] = DEST_RE; 
assign mem2wbk_din[38] = wb;
assign mem2wbk_din[39] = CSR_WENABLE_RE; 
assign mem2wbk_din[71:40] = CSR_RDATA_RE;
assign mem2wbk_din[72] = MULT_INST_RE; 

// fifo unconcat 
assign MEM_RES_RM = mem2wbk_dout[31:0];
assign MEM_DEST_RM = mem2wbk_dout[37:32];
assign WB_RM = mem2wbk_dout[38];
assign CSR_WENABLE_RM = mem2wbk_dout[39];
assign CSR_RDATA_RM = mem2wbk_dout[71:40];
assign mem_fifo_mult_inst = mem2wbk_dout[72];

// fifo manage 
assign stall_sm = MCACHE_STALL_SM || mem2wbk_full || EXE2MEM_EMPTY_SE;
assign wb = WB_RE || LOAD_RE;
assign mem2wbk_push = (!stall_sm) && wb;
assign EXE2MEM_POP_SM = !stall_sm;

assign data_byte_store_sm[31:8] = 0;
assign data_byte_store_sm[7:0] = MEM_DATA_RE[7:0];

assign data_half_store_sm[31:16] = 0;
assign data_half_store_sm[15:0] = MEM_DATA_RE[15:0];

assign data_store_sm = (MEM_SIZE_RE == 2'b10) ? data_byte_store_sm : 
                       (MEM_SIZE_RE == 2'b01) ? data_half_store_sm : 
                                                MEM_DATA_RE;

// Mcache 
assign MCACHE_DATA_SM = data_store_sm; 
assign MCACHE_ADR_SM = RES_RE;
assign MCACHE_LOAD_SM = LOAD_RE;
assign MCACHE_STORE_SM = STORE_RE;
assign MCACHE_ADR_VALID_SM = (!EXE2MEM_EMPTY_SE || !mem_fifo_mult_inst) && (STORE_RE || LOAD_RE);

// sign extend and load size 
assign lb_sign = (byt_sel_sm == 4'b1000) ? MCACHE_RESULT_SM[31] :
                 (byt_sel_sm == 4'b0100) ? MCACHE_RESULT_SM[23] :
                 (byt_sel_sm == 4'b0010) ? MCACHE_RESULT_SM[15] :
                 (byt_sel_sm == 4'b0001) ? MCACHE_RESULT_SM[7]  :
                 1'b0;

assign load_byte[31:8] = (SIGN_EXTEND_RE == 1'b0) ? 24'd0 :
                         {lb_sign, {24{lb_sign[7]}}};

assign load_byte[7:0] = (byt_sel_sm == 4'b1000) ? MCACHE_RESULT_SM[31:24] :
                        (byt_sel_sm == 4'b0100) ? MCACHE_RESULT_SM[23:16] :
                        (byt_sel_sm == 4'b0010) ? MCACHE_RESULT_SM[15:8] :
                        (byt_sel_sm == 4'b0001) ? MCACHE_RESULT_SM[7:0]  :
                        8'h00;

assign lh_sign = (byt_sel_sm == 4'b1100) ? MCACHE_RESULT_SM[31] :
                 (byt_sel_sm == 4'b0011) ? MCACHE_RESULT_SM[15] :
                 1'b0;

assign load_halfword[31:16] = (SIGN_EXTEND_RE == 1'b0) ? 16'd0 :
                             {lh_sign, {16{lh_sign[7]}}};

assign load_halfword[15:0] = (byt_sel_sm == 4'b0011) ? MCACHE_RESULT_SM[15:0] :
                             (byt_sel_sm == 4'b1100) ? MCACHE_RESULT_SM[31:16] :
                             16'h0000;

assign load_word = MCACHE_RESULT_SM;

assign load_data = (MEM_SIZE_RE == 2'b10) ? load_byte :
                   (MEM_SIZE_RE == 2'b01) ? load_halfword :
                   load_word;

// byte select
assign byt_sel_sm = (MEM_SIZE_RE == 2'b10 && RES_RE[1:0] == 2'b00) ? 4'b0001 :
                    (MEM_SIZE_RE == 2'b10 && RES_RE[1:0] == 2'b01) ? 4'b0010 :
                    (MEM_SIZE_RE == 2'b10 && RES_RE[1:0] == 2'b10) ? 4'b0100 :
                    (MEM_SIZE_RE == 2'b10 && RES_RE[1:0] == 2'b11) ? 4'b1000 :
                    (MEM_SIZE_RE == 2'b01 && RES_RE[1:0] == 2'b00) ? 4'b0011 :
                    (MEM_SIZE_RE == 2'b01 && RES_RE[1:0] == 2'b10) ? 4'b1100 :
                    (MEM_SIZE_RE == 2'b00 && RES_RE[1:0] == 2'b00) ? 4'b1111 :
                    4'b0000;

assign byt_sel = byt_sel_sm;

// Data selection to be written in register file
assign data_sm = (LOAD_RE == 1'b1) ? load_data :
                 RES_RE;

// CSR & Exception
assign exception = (EXCEPTION_RE || BUS_ERROR_SX) ? 1'b1 : 1'b0;

// CSR write
assign CSR_WADR_SM     = CSR_WADR_RE;
assign CSR_WDATA_SM    = RES_RE;
assign CSR_ENABLE_SM   = CSR_WENABLE_RE && !exception;

// MSTATUS 
assign mstatus_x[31]           = 1'b0;
assign mstatus_x[30:13]        = MSTATUS_RC[30:13];
assign mstatus_x[12:11]        = old_mode;
assign mstatus_x[10:8]         = MSTATUS_RC[10:8];
assign mstatus_x[7]            = MSTATUS_RC[3];
assign mstatus_x[6:4]          = MSTATUS_RC[6:4];
assign mstatus_x[3]            = 1'b0;
assign mstatus_x[2:0]          = MSTATUS_RC[2:0];

// MCAUSE
assign mcause_x    =  (ENV_CALL_WRONG_MODE_RE)           ? 32'h00000018 : 
                    (STORE_ACCESS_FAULT_RE)            ? 32'h00000007 :
                    (LOAD_ACCESS_FAULT_RE)             ? 32'h00000005 : 
                    (ENV_CALL_WRONG_MODE_RE)           ? 32'h00000005 : 
                    (STORE_ADRESS_MISALIGNED_RE)       ? 32'h00000006 : 
                    (LOAD_ADRESS_MISALIGNED_RE)        ? 32'h00000004 : 
                    (ENV_CALL_M_MODE_RE)               ? 32'h0000000B : 
                    (ENV_CALL_S_MODE_RE)               ? 32'h00000009 : 
                    (ENV_CALL_U_MODE_RE)               ? 32'h00000008 : 
                    (EBREAK_RE)                        ? 32'h00000003 : 
                    (INSTRUCTION_ADRESS_MISALIGNED_RE) ? 32'h00000000 : 
                    (ILLEGAL_INSTRUCTION_RE)           ? 32'h00000002 : 
                    (INSTRUCTION_ACCESS_FAULT_RE)      ? 32'h00000001 : 
                                                      32'h00000000; // or debug value

// MTVAL
assign mtval_x     =  ((STORE_ACCESS_FAULT_RE || LOAD_ACCESS_FAULT_RE || STORE_ADRESS_MISALIGNED_RE || LOAD_ADRESS_MISALIGNED_RE) ? RES_RE : 
                    (INSTRUCTION_ADRESS_MISALIGNED_RE) ? PC_BRANCH_VALUE_RE : 
                    (EBREAK_RE) ? PC_EXE2MEM_RE : 
                    32'h00000000); 

assign machine_mode_condition  =  ENV_CALL_WRONG_MODE_RE              || 
                            STORE_ACCESS_FAULT_RE               || 
                            LOAD_ACCESS_FAULT_RE                || 
                            STORE_ADRESS_MISALIGNED_RE          || 
                            LOAD_ADRESS_MISALIGNED_RE           || 
                            ENV_CALL_M_MODE_RE                  || 
                            ENV_CALL_S_MODE_RE                  || 
                            ENV_CALL_U_MODE_RE                  || 
                            EBREAK_RE                           || 
                            INSTRUCTION_ADRESS_MISALIGNED_RE    || 
                            ILLEGAL_INSTRUCTION_RE              || 
                            INSTRUCTION_ACCESS_FAULT_RE;   

assign new_mode = (machine_mode_condition) ? 2'b11 : 2'b00;

always_ff @(posedge clk or negedge reset_n) begin 
    if (~reset_n) begin
        old_mode <= 2'b11;
    end else begin
        old_mode <= mode_sm; 
    end
end

assign mode_sm = (exception) ? new_mode : old_mode; 

// RETURN_ADRESS_SM
assign RETURN_ADRESS_SM = (MRET_RE == 1) ? MEPC_SC : 32'h00000000;

// Ouput affectation 
assign EXCEPTION_SM     = (EXCEPTION_RE == 1 || BUS_ERROR_SX == 1) ? 1'b1 : 1'b0;
assign MEPC_WDATA_SM    = PC_EXE2MEM_RE;
assign MSTATUS_WDATA_SM = {1'b0, MSTATUS_RC[30:13], old_mode, MSTATUS_RC[10:8], MSTATUS_RC[3], MSTATUS_RC[6:4], 1'b0, MSTATUS_RC[2:0]};
assign CURRENT_MODE_SM  = (exception == 1) ? new_mode : old_mode;
assign MRET_SM          = (MRET_RE == 1 && exception == 1) ? 1'b1 : 1'b0;
assign MIP_WDATA_SM     = 32'h00000000;
assign MTVAL_WDATA_SM   = ((STORE_ACCESS_FAULT_RE || LOAD_ACCESS_FAULT_RE || STORE_ADRESS_MISALIGNED_RE || LOAD_ADRESS_MISALIGNED_RE) == 1) ? RES_RE : 
                         (INSTRUCTION_ADRESS_MISALIGNED_RE == 1) ? PC_BRANCH_VALUE_RE :
                         (EBREAK_RE == 1) ? PC_EXE2MEM_RE : 32'h00000000;
assign MCAUSE_WDATA_SM  = (ENV_CALL_WRONG_MODE_RE == 1) ? 32'h00000018 :
                         (STORE_ACCESS_FAULT_RE == 1) ? 32'h00000007 :
                         (LOAD_ACCESS_FAULT_RE == 1) ? 32'h00000005 :
                         (ENV_CALL_WRONG_MODE_RE == 1) ? 32'h00000005 :
                         (STORE_ADRESS_MISALIGNED_RE == 1) ? 32'h00000006 :
                         (LOAD_ADRESS_MISALIGNED_RE == 1) ? 32'h00000004 :
                         (ENV_CALL_M_MODE_RE == 1) ? 32'h0000000B :
                         (ENV_CALL_S_MODE_RE == 1) ? 32'h00000009 :
                         (ENV_CALL_U_MODE_RE == 1) ? 32'h00000008 :
                         (EBREAK_RE == 1) ? 32'h00000003 :
                         (INSTRUCTION_ADRESS_MISALIGNED_RE == 1) ? 32'h00000000 :
                         (ILLEGAL_INSTRUCTION_RE == 1) ? 32'h00000002 :
                         (INSTRUCTION_ACCESS_FAULT_RE == 1) ? 32'h00000001 : 32'h00000000;
assign MULT_INST_RM     = mem_fifo_mult_inst;

endmodule;