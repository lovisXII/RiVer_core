module core (
        // global interface
        input logic clk, reset_n,

        // Mcache interface
        input logic [31:0] MCACHE_RESULT_SM,
        input logic MCACHE_STALL_SM,

        output logic MCACHE_ADR_VALID_SM, MCACHE_STORE_SM, MCACHE_LOAD_SM,
        output logic[31:0] MCACHE_DATA_SM,
        output logic[31:0] MCACHE_ADR_SM, 
        output logic[3:0]  byt_sel, 

        // Icache interface
        input logic[31:0]   IC_INST_SI,
        input logic         IC_STALL_SI, 

        output logic[31:0] ADR_SI,
        output logic ADR_VALID_SI, 

        // Debug 
        input logic[31:0] PC_INIT,
        output logic[31:0] DEBUG_PC_READ 
);

// dec2if
logic DEC2IF_EMPTY_SD, DEC2IF_POP_SI;

// if2dec
logic IF2DEC_FLUSH_SD, IF2DEC_POP_SD, IF2DEC_EMPTY_SI;
logic [31:0] PC_RD, INSTR_RI, PC_IF2DEC_RI;

// dec2exe
logic DEC2EXE_POP_SE, DEC2EXE_EMPTY_SD;
logic [31:0] OP1_RD, OP2_RD;
logic [5:0] RADR1_RD, RADR2_RD;
logic [31:0] MEM_DATA_RD;
logic [5:0] DEST_RD;
logic [1:0] CMD_RD;
logic [1:0] MEM_SIZE_RD;
logic NEG_OP2_RD, WB_RD;
logic [3:0] SELECT_OPERATION_RD;
logic MEM_LOAD_RD, MEM_STORE_RD, MEM_SIGN_EXTEND_RD;
logic SLT_RD, SLTU_RD;

// Decod Reg interface
logic [31:0] RDATA1_SR, RDATA2_SR;
logic [5:0] RADR1_SD, RADR2_SD;
logic [31:0] WRITE_PC_SD;
logic WRITE_PC_ENABLE_SD;
logic [31:0] READ_PC_SR;

// exe2mem
logic EXE2MEM_POP_SM, EXE2MEM_EMPTY_SE;
logic [31:0] RES_RE, MEM_DATA_RE;
logic [5:0] DEST_RE;
logic [1:0] MEM_SIZE_RE;
logic WB_RE, MEM_SIGN_EXTEND_RE, MEM_LOAD_RE, MEM_STORE_RE;

// mem2wbk
logic [31:0] MEM_RES_RM;
logic [5:0] MEM_DEST_RM;
logic [1:0] MEM_SIZE_RM;
logic WB_RM, SIGN_EXTEND_RM, LOAD_RM;
logic MEM2WBK_EMPTY_SM, MEM2WBK_POP_SW;

// Reg interface
logic [31:0] REG_DATA_SW;
logic [5:0] REG_DEST_SW;
logic REG_WB_SW;

// Bypasses
logic [5:0] BP_DEST_RE;
logic [31:0] BP_EXE_RES_RE;
logic BP_MEM_LOAD_RE, BP_EXE2MEM_EMPTY_SE;
logic [5:0] BP_DEST_RM;
logic [31:0] BP_MEM_RES_RM;
logic BP_R1_VALID_RD, BP_R2_VALID_RD;
logic [5:0] BP_RADR1_RD, BP_RADR2_RD;

logic BLOCK_BP_RD;

// CSR
logic [11:0] CSR_WADR_SM;
logic [31:0] CSR_WDATA_SM;
logic CSR_ENABLE_SM, CSR_WENABLE_RD;
logic EXCEPTION_SM = 1'b0;
logic [31:0] MSTATUS_WDATA_SM;
logic [31:0] MIP_WDATA_SM;
logic [31:0] MEPC_WDATA_SM;
logic [31:0] MCAUSE_WDATA_SM;
logic [31:0] MTVAL_WDATA_SM;
logic [31:0] MEPC_SC;
logic [31:0] MSTATUS_RC;
logic [31:0] MTVEC_VALUE_RC;
logic [31:0] MIP_VALUE_RC;
logic [31:0] MIE_VALUE_RC;
logic [31:0] MCAUSE_SC;
logic [11:0] CSR_RADR_SD, CSR_WADR_RD;
logic [31:0] CSR_RDATA_SC, CSR_RDATA_RD;

// Exception
logic ILLEGAL_INSTRUCTION_RD, ADRESS_MISALIGNED_RD, INSTRUCTION_ACCESS_FAULT_RD, EBREAK_RD;
logic ILLEGAL_INSTRUCTION_RE, ADRESS_MISALIGNED_RE, INSTRUCTION_ACCESS_FAULT_RE, EBREAK_RE;
logic EXCEPTION_RI, EXCEPTION_RD, EXCEPTION_RE;
logic STORE_ADRESS_MISALIGNED_RE, STORE_ACCESS_FAULT_RE;
logic LOAD_ADRESS_MISALIGNED_RE, LOAD_ACCESS_FAULT_RE;
logic ENV_CALL_U_MODE_RD, ENV_CALL_S_MODE_RD, ENV_CALL_M_MODE_RD;
logic ENV_CALL_U_MODE_RE, ENV_CALL_S_MODE_RE, ENV_CALL_M_MODE_RE;
logic ENV_CALL_WRONG_MODE_RE, ENV_CALL_WRONG_MODE_RD;
logic MRET_RD, MRET_RE;

logic CSR_WENABLE_RE, CSR_WENABLE_RM;
logic [31:0] CSR_RDATA_RE, CSR_RDATA_RM;
logic [11:0] CSR_WADR_RE;
logic [31:0] PC_BRANCH_VALUE_RE;

logic BUS_ERROR_SX;

logic [1:0] CURRENT_MODE_SM;
logic [31:0] RETURN_ADRESS_SM;
logic MRET_SM;

logic [31:0] PC_EXE2MEM_RE, PC_DEC2EXE_RD, PC_BRANCH_VALUE_RD, PC_MEM2WBK_RM;

logic MULT_INST_RM, MULT_INST_RD, MULT_INST_RE;

// x0 multiplier
logic X0X1_POP_SX1;
logic [319:0] RES_RX0;
logic SELECT_MSB_RX0;
logic SIGNED_RES_RX0;
logic X0X1_EMPTY_SX0;

logic [31:0] OP1_SE, OP2_SE;

// x1 multiplier
logic X1X2_POP_SX2;
logic [127:0] RES_RX1;
logic SELECT_MSB_RX1;
logic SIGNED_RES_RX1;
logic X1X2_EMPTY_SX1;
logic [31:0] RES_RX2;

// Branch prediction
logic PRED_FAILED_RD, PRED_SUCCESS_RD;
logic BRANCH_INST_RD;
logic [31:0] BRANCH_INST_ADR_RD;
logic [31:0] ADR_TO_BRANCH_RD;

logic [31:0] PRED_ADR_SD;
logic PRED_TAKEN_SD;

logic PUSH_ADR_RAS_RD;
logic POP_ADR_RAS_RD;
logic [31:0] ADR_TO_RET_RD;
logic RET_INST_RD;

logic [31:0] PRED_ADR_RI;
logic PRED_TAKEN_RI;

//-------------------------
//-- Instanciation 
//-------------------------

ifetch ifetch_i (
    // global interface
    .clk                (clk),
    .reset_n            (reset_n),

    // Icache interface
    .IC_INST_SI         (IC_INST_SI),
    .IC_STALL_SI        (IC_STALL_SI),
    .ADR_SI             (ADR_SI),
    .ADR_VALID_SI       (ADR_VALID_SI),

    // dec2if interface
    .DEC2IF_EMPTY_SD    (DEC2IF_EMPTY_SD),
    .DEC2IF_POP_SI      (DEC2IF_POP_SI),

    // if2dec interface
    .IF2DEC_FLUSH_SD    (IF2DEC_FLUSH_SD),
    .IF2DEC_POP_SD      (IF2DEC_POP_SD),
    .IF2DEC_EMPTY_SI    (IF2DEC_EMPTY_SI),

    .PC_RD              (PC_RD),
    .INSTR_RI           (INSTR_RI),
    .PC_IF2DEC_RI       (PC_IF2DEC_RI),

    // Exception
    .EXCEPTION_SM       (EXCEPTION_SM),
    .EXCEPTION_RI       (EXCEPTION_RI),

    // Branch prediction
    .PRED_FAILED_RD     (PRED_FAILED_RD),
    .PRED_SUCCESS_RD    (PRED_SUCCESS_RD),
    .BRANCH_INST_RD     (BRANCH_INST_RD),
    .BRANCH_INST_ADR_RD (BRANCH_INST_ADR_RD),
    .ADR_TO_BRANCH_RD   (ADR_TO_BRANCH_RD),

    .PRED_ADR_SD        (PRED_ADR_SD),
    .PRED_TAKEN_SD      (PRED_TAKEN_SD),

    .PUSH_ADR_RAS_RD    (PUSH_ADR_RAS_RD),
    .POP_ADR_RAS_RD     (POP_ADR_RAS_RD),
    .ADR_TO_RET_RD      (ADR_TO_RET_RD),
    .RET_INST_RD        (RET_INST_RD),

    .PRED_ADR_RI        (PRED_ADR_RI),
    .PRED_TAKEN_RI      (PRED_TAKEN_RI)
);

dec dec_i
(
// global interface
.clk(clk),
.reset_n(reset_n),
    // Reg interface
    .RDATA1_SR(RDATA1_SR),
    .RDATA2_SR(RDATA2_SR),
    .REG_ADR1_SD(RADR1_SD),
    .REG_ADR2_SD(RADR2_SD),
    .WRITE_PC_SD(WRITE_PC_SD),
    .WRITE_PC_ENABLE_SD(WRITE_PC_ENABLE_SD),
    .READ_PC_SR(READ_PC_SR),

    // Exe interface 
    .OP1_RD(OP1_RD),
    .OP2_RD(OP2_RD),
    .CMD_RD(CMD_RD),
    .NEG_OP2_RD(NEG_OP2_RD),
    .WB_RD(WB_RD),
    .DEST_RD(DEST_RD),
    .SELECT_OPERATION_RD(SELECT_OPERATION_RD),
    .SLT_RD(SLT_RD),
    .SLTU_RD(SLTU_RD),
    .MEM_DATA_RD(MEM_DATA_RD),
    .MEM_LOAD_RD(MEM_LOAD_RD),
    .MEM_STORE_RD(MEM_STORE_RD),
    .MEM_SIGN_EXTEND_RD(MEM_SIGN_EXTEND_RD),
    .MEM_SIZE_RD(MEM_SIZE_RD),
    .CSR_WENABLE_RD(CSR_WENABLE_RD),
    .CSR_WADR_RD(CSR_WADR_RD),
    .CSR_RDATA_RD(CSR_RDATA_RD),
    .PC_DEC2EXE_RD(PC_DEC2EXE_RD),
    .PC_BRANCH_VALUE_RD(PC_BRANCH_VALUE_RD),

    // dec2if interface 
    .DEC2IF_POP_SI(DEC2IF_POP_SI),
    .DEC2IF_EMPTY_SD(DEC2IF_EMPTY_SD),
    .PC_RD(PC_RD),

    // if2dec interface 
    .INSTR_RI(INSTR_RI),
    .PC_IF2DEC_RI(PC_IF2DEC_RI),
    .IF2DEC_EMPTY_SI(IF2DEC_EMPTY_SI),
    .IF2DEC_POP_SD(IF2DEC_POP_SD),
    .IF2DEC_FLUSH_SD(IF2DEC_FLUSH_SD),

    // branch prediction 
    .PRED_FAILED_RD(PRED_FAILED_RD),
    .PRED_SUCCESS_RD(PRED_SUCCESS_RD),
    .BRANCH_INST_ADR_RD(BRANCH_INST_ADR_RD),
    .BRANCH_INST_RD(BRANCH_INST_RD),
    .ADR_TO_BRANCH_RD(ADR_TO_BRANCH_RD),
    .PRED_ADR_SD(PRED_ADR_SD),
    .PRED_TAKEN_SD(PRED_TAKEN_SD),
    .PUSH_ADR_RAS_RD(PUSH_ADR_RAS_RD),
    .POP_ADR_RAS_RD(POP_ADR_RAS_RD),
    .ADR_TO_RET_RD(ADR_TO_RET_RD),
    .RET_INST_RD(RET_INST_RD),
    .PRED_ADR_RI(PRED_ADR_RI),
    .PRED_TAKEN_RI(PRED_TAKEN_RI),

    // dec2exe interface 
    .DEC2EXE_POP_SE(DEC2EXE_POP_SE),
    .DEC2EXE_EMPTY_SD(DEC2EXE_EMPTY_SD),

    // Multiplier 
    .MULT_INST_RD(MULT_INST_RD),
    .MULT_INST_RE(MULT_INST_RE),
    .MULT_INST_RM(MULT_INST_RM),

    // Bypasses 
    .BP_DEST_RE(DEST_RE),
    .BP_EXE_RES_RE(RES_RE),
    .BP_MEM_LOAD_RE(MEM_LOAD_RE),
    .BP_EXE2MEM_EMPTY_SE(EXE2MEM_EMPTY_SE),
    .BP_MEM2WBK_EMPTY_SM(MEM2WBK_EMPTY_SM),
    .BP_DEST_RM(MEM_DEST_RM),
    .BP_MEM_RES_RM(MEM_RES_RM),
    
    .BP_R1_VALID_RD(BP_R1_VALID_RD), 
    .BP_R2_VALID_RD(BP_R2_VALID_RD), 
    .BP_RADR1_RD(BP_RADR1_RD), 
    .BP_RADR2_RD(BP_RADR2_RD),
    .BLOCK_BP_RD(BLOCK_BP_RD),
    
    .CSR_WENABLE_RE(CSR_WENABLE_RE), 
    .CSR_WENABLE_RM(CSR_WENABLE_RM), 
    .CSR_RDATA_RE(CSR_RDATA_RE), 
    .CSR_RDATA_RM(CSR_RDATA_RM),
    
    .CSR_RADR_SD(CSR_RADR_SD), 
    .CSR_RDATA_SC(CSR_RDATA_SC),
    
    // Exception
    .EXCEPTION_RI(EXCEPTION_RI), 
    .ILLEGAL_INSTRUCTION_RD(ILLEGAL_INSTRUCTION_RD), 
    .ADRESS_MISALIGNED_RD(ADRESS_MISALIGNED_RD), 
    .ENV_CALL_U_MODE_RD(ENV_CALL_U_MODE_RD), 
    .ENV_CALL_M_MODE_RD(ENV_CALL_M_MODE_RD), 
    .ENV_CALL_S_MODE_RD(ENV_CALL_S_MODE_RD), 
    .ENV_CALL_WRONG_MODE_RD(ENV_CALL_WRONG_MODE_RD), 
    .INSTRUCTION_ACCESS_FAULT_RD(INSTRUCTION_ACCESS_FAULT_RD), 
    .MRET_RD(MRET_RD), 
    .EXCEPTION_RD(EXCEPTION_RD), 
    .EBREAK_RD(EBREAK_RD), 
    
    .CURRENT_MODE_SM(CURRENT_MODE_SM), 
    .EXCEPTION_SM(EXCEPTION_SM), 
    .MTVEC_VALUE_RC(MTVEC_VALUE_RC), 
    .MCAUSE_WDATA_SM(MCAUSE_WDATA_SM), 
    .MRET_SM(MRET_SM), 
    .RETURN_ADRESS_SM(RETURN_ADRESS_SM)
);

exe exec_i (
    // global interface
    .clk(clk),
    .reset_n(reset_n),

    .OP1_RD(OP1_RD), 
    .OP2_RD(OP2_RD),
    .RADR1_RD(BP_RADR1_RD), 
    .RADR2_RD(BP_RADR2_RD),
    .MEM_DATA_RD(MEM_DATA_RD),
    .DEST_RD(DEST_RD),
    .CMD_RD(CMD_RD),
    .MEM_SIZE_RD(MEM_SIZE_RD),
    .NEG_OP2_RD(NEG_OP2_RD),
    .WB_RD(WB_RD),
    .MEM_SIGN_EXTEND_RD(MEM_SIGN_EXTEND_RD),
    .SELECT_OPERATION_RD(SELECT_OPERATION_RD),
    .MEM_LOAD_RD(MEM_LOAD_RD), 
    .MEM_STORE_RD(MEM_STORE_RD),
    .EXE2MEM_POP_SM(EXE2MEM_POP_SM),
    .DEC2EXE_EMPTY_SD(DEC2EXE_EMPTY_SD),
    .SLT_RD(SLT_RD), 
    .SLTU_RD(SLTU_RD),

    .RES_RE(RES_RE),    
    .MEM_DATA_RE(MEM_DATA_RE),
    .DEST_RE(DEST_RE),
    .MEM_SIZE_RE(MEM_SIZE_RE),
    .WB_RE(WB_RE),
    .MEM_SIGN_EXTEND_RE(MEM_SIGN_EXTEND_RE),
    .MEM_LOAD_RE(MEM_LOAD_RE), 
    .MEM_STORE_RE(MEM_STORE_RE),
    .EXE2MEM_EMPTY_SE(EXE2MEM_EMPTY_SE),
    .DEC2EXE_POP_SE(DEC2EXE_POP_SE),

    .PC_DEC2EXE_RD(PC_DEC2EXE_RD),
    .PC_EXE2MEM_RE(PC_EXE2MEM_RE),

    .BLOCK_BP_RD(BLOCK_BP_RD),
    .MEM_DEST_RM(MEM_DEST_RM), 
    .MEM_RES_RM(MEM_RES_RM),

    .CSR_WENABLE_RM(CSR_WENABLE_RM),
    .CSR_RDATA_RM(CSR_RDATA_RM),

    .BP_MEM2WBK_EMPTY_SM(MEM2WBK_EMPTY_SM),

    // CSR 
    .CSR_WENABLE_RD(CSR_WENABLE_RD),
    .CSR_WADR_RD(CSR_WADR_RD), 
    .CSR_RDATA_RD(CSR_RDATA_RD), 

    // Multiplier 
    .MULT_INST_RM(MULT_INST_RM),
    .MULT_INST_RD(MULT_INST_RD),
    .MULT_INST_RE(MULT_INST_RE),
    .OP1_SE(OP1_SE),
    .OP2_SE(OP2_SE),

    // Exception 
    .EXCEPTION_SM(EXCEPTION_SM), 
    .EXCEPTION_RD(EXCEPTION_RD), 
    .CURRENT_MODE_SM(CURRENT_MODE_SM),
    .PC_BRANCH_VALUE_RD(PC_BRANCH_VALUE_RD), 
    .PC_BRANCH_VALUE_RE(PC_BRANCH_VALUE_RE), 

    .ILLEGAL_INSTRUCTION_RD(ILLEGAL_INSTRUCTION_RD),
    .ADRESS_MISALIGNED_RD(ADRESS_MISALIGNED_RD), 
    .INSTRUCTION_ACCESS_FAULT_RD(INSTRUCTION_ACCESS_FAULT_RD), 
    .ENV_CALL_U_MODE_RD(ENV_CALL_U_MODE_RD), 
    .ENV_CALL_S_MODE_RD(ENV_CALL_S_MODE_RD), 
    .ENV_CALL_M_MODE_RD(ENV_CALL_M_MODE_RD),
    .ENV_CALL_WRONG_MODE_RD(ENV_CALL_WRONG_MODE_RD), 
    .MRET_RD(MRET_RD),
    .EBREAK_RD(EBREAK_RD),

    .EXCEPTION_RE(EXCEPTION_RE),
    .ILLEGAL_INSTRUCTION_RE      ( ILLEGAL_INSTRUCTION_RE), 
    .ADRESS_MISALIGNED_RE        ( ADRESS_MISALIGNED_RE), 
    .INSTRUCTION_ACCESS_FAULT_RE ( INSTRUCTION_ACCESS_FAULT_RE),  
    .ENV_CALL_U_MODE_RE          ( ENV_CALL_U_MODE_RE), 
    .ENV_CALL_S_MODE_RE          ( ENV_CALL_S_MODE_RE), 
    .ENV_CALL_M_MODE_RE          ( ENV_CALL_M_MODE_RE),
    .ENV_CALL_WRONG_MODE_RE      ( ENV_CALL_WRONG_MODE_RE),
    .LOAD_ADRESS_MISALIGNED_RE   ( LOAD_ADRESS_MISALIGNED_RE), 
    .LOAD_ACCESS_FAULT_RE        ( LOAD_ACCESS_FAULT_RE),
    .STORE_ADRESS_MISALIGNED_RE  ( STORE_ADRESS_MISALIGNED_RE),
    .STORE_ACCESS_FAULT_RE       ( STORE_ACCESS_FAULT_RE),
    .MRET_RE                     ( MRET_RE),
    .EBREAK_RE                   ( EBREAK_RE), 

    .CSR_WENABLE_RE              (CSR_WENABLE_RE),
    .CSR_WADR_RE                 (CSR_WADR_RE),     
    .CSR_RDATA_RE                (CSR_RDATA_RE)
);

mem mem_i (
        //-- global interface
        .clk( clk),
        .reset_n( reset_n), 

        //-- Mcache interface
        .MCACHE_RESULT_SM( MCACHE_RESULT_SM),
        .MCACHE_STALL_SM( MCACHE_STALL_SM),
        .MCACHE_ADR_SM( MCACHE_ADR_SM), 
        .MCACHE_DATA_SM( MCACHE_DATA_SM),
        .MCACHE_ADR_VALID_SM(MCACHE_ADR_VALID_SM), 
        .MCACHE_STORE_SM( MCACHE_STORE_SM), 
        .MCACHE_LOAD_SM( MCACHE_LOAD_SM),
        .byt_sel( byt_sel), 

        //-- Exe interface
        .RES_RE( RES_RE),
        .MEM_DATA_RE( MEM_DATA_RE),
        .DEST_RE( DEST_RE),
        .MEM_SIZE_RE( MEM_SIZE_RE),      
        .WB_RE( WB_RE), 
        .SIGN_EXTEND_RE( MEM_SIGN_EXTEND_RE), 
        .LOAD_RE( MEM_LOAD_RE),
        .STORE_RE( MEM_STORE_RE),
        .PC_EXE2MEM_RE( PC_EXE2MEM_RE),

        //-- Multiplier
        .MULT_INST_RE( MULT_INST_RE),
        .MULT_INST_RM( MULT_INST_RM),

        //-- exe2mem interface
        .EXE2MEM_EMPTY_SE( EXE2MEM_EMPTY_SE),
        .EXE2MEM_POP_SM( EXE2MEM_POP_SM),

        //-- mem2wbk interface
        .MEM2WBK_POP_SW( MEM2WBK_POP_SW), 
        .MEM2WBK_EMPTY_SM( MEM2WBK_EMPTY_SM),
        
        //-- Wbk interface
        .MEM_RES_RM( MEM_RES_RM),
        .MEM_DEST_RM( MEM_DEST_RM),
        .WB_RM( WB_RM),
        .CSR_RDATA_RM( CSR_RDATA_RM),
        .CSR_WENABLE_RM( CSR_WENABLE_RM),


        //-- CSR 
        .CSR_WENABLE_RE( CSR_WENABLE_RE),
        .CSR_WADR_RE( CSR_WADR_RE),     
        .CSR_RDATA_RE( CSR_RDATA_RE),    

        .CSR_WADR_SM( CSR_WADR_SM),
        .CSR_WDATA_SM( CSR_WDATA_SM),   
        .CSR_ENABLE_SM( CSR_ENABLE_SM), 

        .MSTATUS_WDATA_SM( mstatus_wdata_sm),    
        .MIP_WDATA_SM( MIP_WDATA_SM),    
        .MEPC_WDATA_SM( MEPC_WDATA_SM),    
        .MCAUSE_WDATA_SM( MCAUSE_WDATA_SM),    
        .MTVAL_WDATA_SM( MTVAL_WDATA_SM),    

        .MEPC_SC( MEPC_SC),      
        .MSTATUS_RC( MSTATUS_RC),      
        .MTVEC_VALUE_RC( MTVEC_VALUE_RC),      
        .MIP_VALUE_RC( MIP_VALUE_RC),      
        .MIE_VALUE_RC( MIE_VALUE_RC),      

        //-- Exception 
        .EXCEPTION_RE (EXCEPTION_RE),    
        .LOAD_ADRESS_MISALIGNED_RE (LOAD_ADRESS_MISALIGNED_RE), 
        .LOAD_ACCESS_FAULT_RE (LOAD_ACCESS_FAULT_RE), 
        .ILLEGAL_INSTRUCTION_RE (ILLEGAL_INSTRUCTION_RE), 
        .INSTRUCTION_ADRESS_MISALIGNED_RE (ADRESS_MISALIGNED_RE), 
        .INSTRUCTION_ACCESS_FAULT_RE (INSTRUCTION_ACCESS_FAULT_RE),
        .STORE_ADRESS_MISALIGNED_RE (STORE_ADRESS_MISALIGNED_RE), 
        .STORE_ACCESS_FAULT_RE (STORE_ACCESS_FAULT_RE), 
        .ENV_CALL_U_MODE_RE (ENV_CALL_U_MODE_RE), 
        .ENV_CALL_S_MODE_RE (ENV_CALL_S_MODE_RE),
        .ENV_CALL_M_MODE_RE (ENV_CALL_M_MODE_RE),
        .ENV_CALL_WRONG_MODE_RE (ENV_CALL_WRONG_MODE_RE),
        .MRET_RE (MRET_RE),
        .EBREAK_RE (EBREAK_RE),
        .PC_BRANCH_VALUE_RE (PC_BRANCH_VALUE_RE),

        .BUS_ERROR_SX (BUS_ERROR_SX), 

        .EXCEPTION_SM( EXCEPTION_SM),
        .CURRENT_MODE_SM( CURRENT_MODE_SM),
        .RETURN_ADRESS_SM( RETURN_ADRESS_SM),
        .MRET_SM( MRET_SM)
);

wbk wbk_i (
    // global interface
    .clk(clk),
    .reset_n(reset_n),

    // Mem 
    .MEM_RES_RM(MEM_RES_RM),
    .MEM_DEST_RM(MEM_DEST_RM),
    .WB_RM(WB_RM),

    .PC_MEM2WBK_RM(PC_MEM2WBK_RM),
    .CSR_RDATA_RM(CSR_RDATA_RM),
    .CSR_WENABLE_RM(CSR_WENABLE_RM),
    .CURRENT_MODE_SM(CURRENT_MODE_SM),

    // mem2wbk interface
    .MEM2WBK_EMPTY_SM(MEM2WBK_EMPTY_SM),
    .MEM2WBK_POP_SW(MEM2WBK_POP_SW),

    // Multiplier 
    .MULT_INST_RM(MULT_INST_RM),      
    .RES_RX2(RES_RX2),

    // Reg interface
    .DATA_SW(REG_DATA_SW),
    .DEST_SW(REG_DEST_SW),
    .WB_SW(REG_WB_SW)
);

register_file reg_i (
    // global interface
    .clk(clk),
    .reset_n(reset_n),

    .PC_INIT(PC_INIT),

    // read
    .RDATA1_SR(RDATA1_SR),
    .RDATA2_SR(RDATA2_SR),
    .RADR1_SD(RADR1_SD),
    .RADR2_SD(RADR2_SD),

    // write 
    .WDATA_SW(REG_DATA_SW),
    .WADR_SW(REG_DEST_SW),
    .WENABLE_SW(REG_WB_SW),

    .WRITE_PC_SD(WRITE_PC_SD),
    .WRITE_PC_ENABLE_SD(WRITE_PC_ENABLE_SD),
    .READ_PC_SR(READ_PC_SR)
);
csr csr_i (
    // global interface
    .clk(clk),
    .reset_n(reset_n),

    .CSR_WADR_SM(CSR_WADR_SM),
    .CSR_WDATA_SM(CSR_WDATA_SM),
    .CSR_ENABLE_SM(CSR_ENABLE_SM),

    .EXCEPTION_SM(EXCEPTION_SM),
    .MSTATUS_WDATA_SM(MSTATUS_WDATA_SM),
    .MIP_WDATA_SM(MIP_WDATA_SM),
    .MEPC_WDATA_SM(MEPC_WDATA_SM),
    .MCAUSE_WDATA_SM(MCAUSE_WDATA_SM),
    .MTVAL_WDATA_SM(MTVAL_WDATA_SM),

    .MEPC_SC(MEPC_SC),
    .MSTATUS_RC(MSTATUS_RC),
    .MTVEC_VALUE_RC(MTVEC_VALUE_RC),
    .MIP_VALUE_RC(MIP_VALUE_RC),
    .MIE_VALUE_RC(MIE_VALUE_RC),
    .MCAUSE_SC(MCAUSE_SC),

    .CSR_RADR_SD(CSR_RADR_SD),
    .CSR_RDATA_SC(CSR_RDATA_SC)
);

x0_multiplier x0_mult (
    .clk                (clk),
    .reset_n            (reset_n),
    .OP1_SE             (OP1_SE),
    .OP2_SE             (OP2_SE),
    .MULT_CMD_RD        (CMD_RD),
    .X0X1_POP_SX1       (X0X1_POP_SX1),
    .DEC2X0_EMPTY_SD   (DEC2EXE_EMPTY_SD),
    .RES_RX0            (RES_RX0),
    .SELECT_MSB_RX0     (SELECT_MSB_RX0),
    .SIGNED_RES_RX0     (SIGNED_RES_RX0),
    .X0X1_EMPTY_SX0     (X0X1_EMPTY_SX0)
);

x1_multiplier x1_mult (
    .clk                (clk),
    .reset_n            (reset_n),
    .RES_RX0            (RES_RX0),
    .SELECT_MSB_RX0     (SELECT_MSB_RX0),
    .SIGNED_RES_RX0     (SIGNED_RES_RX0),
    .X0X1_EMPTY_SX0     (X0X1_EMPTY_SX0),
    .X1X2_POP_SX2       (X1X2_POP_SX2),
    .RES_RX1            (RES_RX1),
    .SELECT_MSB_RX1     (SELECT_MSB_RX1),
    .SIGNED_RES_RX1     (SIGNED_RES_RX1),
    .X1X2_EMPTY_SX1     (X1X2_EMPTY_SX1),
    .X0X1_POP_SX1       (X0X1_POP_SX1)
);

x2_multiplier x2_mult (
    .clk                (clk),
    .reset_n            (reset_n),
    .RES_RX1            (RES_RX1),
    .SELECT_MSB_RX1     (SELECT_MSB_RX1),
    .SIGNED_RES_RX1     (SIGNED_RES_RX1),
    .X1X2_EMPTY_SX1     (X1X2_EMPTY_SX1),
    .RES_RX2            (RES_RX2),
    .X1X2_POP_SX2       (X1X2_POP_SX2)
);


assign DEBUG_PC_READ = READ_PC_SR;
assign BUS_ERROR_SX = 1'b0;

endmodule