module dec (
    input logic clk,
    input logic reset_n,

    // Reg interface
    input logic [31:0] RDATA1_SR, RDATA2_SR,
    output logic [5:0] REG_ADR1_SD, REG_ADR2_SD,
    output logic [31:0] WRITE_PC_SD,
    output logic WRITE_PC_ENABLE_SD,
    input logic [31:0] READ_PC_SR,

    // Exe interface 
    output [31:0] OP1_RD, OP2_RD,
    output [1:0] CMD_RD,
    output logic NEG_OP2_RD,
    output logic WB_RD,
    output logic [5:0] DEST_RD,
    output logic [3:0] SELECT_OPERATION_RD,
    output logic SLT_RD, SLTU_RD,    
    output logic [31:0] MEM_DATA_RD,
    output logic MEM_LOAD_RD, MEM_STORE_RD,
    output logic MEM_SIGN_EXTEND_RD,
    output logic [1:0] MEM_SIZE_RD,

    output [31:0] PC_DEC2EXE_RD,
    output [31:0] PC_BRANCH_VALUE_RD,

    output logic CSR_WENABLE_RD, 
    output logic [11:0] CSR_WADR_RD,
    output [31:0] CSR_RDATA_RD,

    // dec2if interface
    input DEC2IF_POP_SI,
    output logic DEC2IF_EMPTY_SD,
    output logic [31:0] PC_RD,

    // if2dec interface
    input [31:0] INSTR_RI, PC_IF2DEC_RI,
    input IF2DEC_EMPTY_SI,
    output logic IF2DEC_POP_SD,
    output logic IF2DEC_FLUSH_SD,

    // branch prediction
    output logic PRED_FAILED_RD,
    output logic PRED_SUCCESS_RD,
    output logic BRANCH_INST_RD,
    output logic [31:0] BRANCH_INST_ADR_RD,
    output logic [31:0] ADR_TO_BRANCH_RD,

    output logic [31:0] PRED_ADR_SD,
    output logic PRED_TAKEN_SD,

    output logic PUSH_ADR_RAS_RD,
    output logic POP_ADR_RAS_RD,
    output logic [31:0] ADR_TO_RET_RD,
    output logic RET_INST_RD,

    input [31:0] PRED_ADR_RI,
    input PRED_TAKEN_RI,

    // dec2exe interface
    input DEC2EXE_POP_SE,
    output logic DEC2EXE_EMPTY_SD,

    // Multiplier
    output logic MULT_INST_RD,
    input MULT_INST_RE, MULT_INST_RM,

    // Bypasses
    input [5:0] BP_DEST_RE,
    input [31:0] BP_EXE_RES_RE,
    input BP_MEM_LOAD_RE,
    input BP_EXE2MEM_EMPTY_SE, BP_MEM2WBK_EMPTY_SM,
    input [5:0] BP_DEST_RM,
    input [31:0] BP_MEM_RES_RM,
    output logic BP_R1_VALID_RD, BP_R2_VALID_RD,
    output logic [5:0] BP_RADR1_RD, BP_RADR2_RD,    
    output logic BLOCK_BP_RD,

    input CSR_WENABLE_RE, CSR_WENABLE_RM,
    input [31:0] CSR_RDATA_RE, CSR_RDATA_RM,

    output [11:0] CSR_RADR_SD,
    input [31:0] CSR_RDATA_SC,

    // Exception 
    input EXCEPTION_RI,
    output logic ILLEGAL_INSTRUCTION_RD,
    output logic ADRESS_MISALIGNED_RD, 
    output logic ENV_CALL_U_MODE_RD, ENV_CALL_M_MODE_RD, ENV_CALL_S_MODE_RD,
    output logic ENV_CALL_WRONG_MODE_RD, INSTRUCTION_ACCESS_FAULT_RD, MRET_RD, EXCEPTION_RD, EBREAK_RD,

    input logic [1:0] CURRENT_MODE_SM,
    input logic EXCEPTION_SM,
    input logic [31:0] MTVEC_VALUE_RC, MCAUSE_WDATA_SM, RETURN_ADRESS_SM,
    input logic MRET_SM
);

const logic [31:0] inc_value = 32'h4;

// Declare signals
logic reset_sync_sd;
logic resetting_sd ;

// fifo
logic [133:0] dec2if_din, dec2if_dout;
logic dec2if_full_sd, dec2if_push_sd;
logic [251:0] dec2exe_din, dec2exe_data, dec2exe_x, dec2exe_dout;
logic dec2exe_full_sd, dec2exe_push_sd;

// Instructions
logic r_type_sd, i_type_sd, s_type_sd, b_type_sd, u_type_sd, j_type_sd, jalr_type_sd;
logic load_type_sd, nmem_type_sd;
logic m_type_sd;

logic add_i_sd, sub_i_sd, slt_i_sd, sltu_i_sd, and_i_sd, or_i_sd, xor_i_sd, sll_i_sd, srl_i_sd, sra_i_sd;
logic addi_i_sd, slti_i_sd, sltiu_i_sd, andi_i_sd, ori_i_sd, xori_i_sd, slli_i_sd, srli_i_sd, srai_i_sd;

logic lw_i_sd, lh_i_sd, lhu_i_sd, lb_i_sd, lbu_i_sd, sw_i_sd, sh_i_sd, sb_i_sd;

logic beq_i_sd, bne_i_sd, blt_i_sd, bge_i_sd, bltu_i_sd, bgeu_i_sd;

logic lui_i_sd;
logic auipc_i_sd;

logic jal_i_sd, jalr_i_sd;

logic mul_i_sd, mulh_i_sd, mulhsu_i_sd, mulhu_i_sd;
logic div_i_sd, divu_i_sd, rem_i_sd, remu_i_sd;

// System instructions
logic system_inst_sd;
logic ecall_i_sd;
logic ebreak_i_sd;
logic csrrw_i_sd, csrrs_i_sd, csrrc_i_sd;
logic csrrwi_i_sd, csrrsi_i_sd, csrrci_i_sd;
logic sret_i_sd;
logic mret_i_sd ;
logic csr_in_progress;

logic fence_i_sd;

logic env_call_u_mode_sd ;
logic env_call_s_mode_sd ;
logic env_call_m_mode_sd ;
logic env_call_wrong_mode;

logic exception_sd ;

logic csr_wenable_sd;

logic illegal_inst ;
logic illegal_inst_sd ;
logic instruction_access_fault_sd ;
logic instruction_adress_misaligned_sd ;
logic instruction_adress_fault_sd ;

logic [31:0] op1_csri_type_sd;

logic [31:0] mtvec_value, mcause_val;

logic [11:0] csr_radr;

// dec2exe data and commands
logic [31:0] dec2exe_op1_sd, dec2exe_op2_sd, op1_u_type_sd, op2_i_type_sd, op2_s_type_sd;
logic [5:0] radr1_sd, radr2_sd, rdest_sd;
logic [31:0] rdata1_sd, rdata2_sd;
logic neg_op2_sd;
logic [1:0] exe_cmd_sd, alu_cmd, mult_cmd, div_cmd;
logic [3:0] select_operation_sd;
logic [31:0] mem_data_sd;
logic mem_load_sd, mem_store_sd, mem_sign_extend_sd;
logic [1:0] mem_size_sd;
logic wb_sd;
// branch and pc gestion
logic [31:0] offset_branch_sd, offset_branch_j, offset_branch_jalr, jalr_offset;
logic [31:0] offset_branch_b;
logic [31:0] jalr_offset_calc;
logic jump_sd;
logic different_sign;
logic [31:0] res;
logic [31:0] res_compare;
logic add_offset_to_pc;
logic [31:0] pc = 32'h0;
logic [31:0] init_pc;
logic [31:0] new_pc;
logic [31:0] pc_branch_value_sd;
logic [31:0] branch_adr_sd;
logic rd_link, rs1_link;
logic pred_success_sd, pred_failed_sd = 1'b0;
logic ret_sd;

logic [31:0] pc_no_jump, pc_jump;
logic pop_adr_ras_sd, push_adr_ras_sd;

// bypass
logic stall_sd, block_in_dec;
logic r1_valid_sd, r2_valid_sd;
logic block_bp_sd;
logic mult_dependency;

// Bypass Conditions
logic bpc_instr_in_exe1, bpc_load_in_mem1, bpc_ed1, bpc_md1;
logic bpc_instr_in_exe2, bpc_load_in_mem2, bpc_ed2, bpc_md2;
logic bpc_mult_exe1, bpc_mult_exe2, bpc_mult_mem1, bpc_mult_mem2;

// readable signals (output ports)
logic mem_load_fifo;
logic dec2exe_empty;
logic [5:0] dec_fifo_rdest;
logic csr_wenable_fifo;
logic dec_fifo_mult_inst;
logic dec_fifo_pred_success, dec_fifo_pred_failed;



fifo #(
    .N(134)
    ) dec2if (
    .clk(clk),
    .reset_n(reset_n),
    .DIN(dec2if_din),
    .PUSH(dec2if_push_sd),
    .POP(DEC2IF_POP_SI),
    .FULL(dec2if_full_sd),
    .EMPTY(DEC2IF_EMPTY_SD),
    .DOUT(dec2if_dout)
);

fifo #(
    .N(252)
    ) dec2exe (
    .clk(clk),
    .reset_n(reset_n),
    .DIN(dec2exe_din),
    .PUSH(dec2exe_push_sd),
    .POP(DEC2EXE_POP_SE),
    .FULL(dec2exe_full_sd),
    .EMPTY(dec2exe_empty),
    .DOUT(dec2exe_dout)
);

// fifo gestion 
assign csr_in_progress = (csr_wenable_fifo & !dec2exe_empty) || (CSR_WENABLE_RE & !BP_EXE2MEM_EMPTY_SE);

assign stall_sd = ((csr_in_progress || ((!r1_valid_sd || !r2_valid_sd) && (b_type_sd || jalr_type_sd || j_type_sd || block_in_dec || mult_dependency))) || IF2DEC_EMPTY_SI || dec2exe_full_sd) ? 1'b1 : 1'b0;

// if2dec 
assign IF2DEC_POP_SD = !stall_sd;

assign IF2DEC_FLUSH_SD = (PRED_TAKEN_RI & (!jump_sd & !stall_sd)) || (!PRED_TAKEN_RI & (jump_sd & !stall_sd)) ? 1'b1 : 1'b0;

assign dec2if_push_sd = (!add_offset_to_pc && !dec2if_full_sd) || (add_offset_to_pc && !dec2if_full_sd && !stall_sd) ? 1'b1 : 1'b0;

// dec2exe
assign dec2exe_push_sd = !stall_sd; 

// Instruction type 
assign r_type_sd = (INSTR_RI[6:0] == 7'b0110011) ? 1'b1 : 1'b0;
assign i_type_sd = (INSTR_RI[6:0] == 7'b0010011 || INSTR_RI[6:0] == 7'b0000011) ? 1'b1 : 1'b0;
assign s_type_sd = (INSTR_RI[6:0] == 7'b0100011) ? 1'b1 : 1'b0;
assign b_type_sd = (INSTR_RI[6:0] == 7'b1100011) ? 1'b1 : 1'b0;
assign u_type_sd = (INSTR_RI[6:0] == 7'b0110111 || INSTR_RI[6:0] == 7'b0010111) ? 1'b1 : 1'b0;
assign j_type_sd = (INSTR_RI[6:0] == 7'b1101111) ? 1'b1 : 1'b0;
assign jalr_type_sd = (INSTR_RI[6:0] == 7'b1100111) ? 1'b1 : 1'b0;
assign load_type_sd = (INSTR_RI[6:0] == 7'b0000011) ? 1'b1 : 1'b0;
assign nmem_type_sd = (INSTR_RI[6:0] == 7'b0010011) ? 1'b1 : 1'b0; // not mem type but i type
assign system_inst_sd = (INSTR_RI[6:0] == 7'b1110011) ? 1'b1 : 1'b0;
assign m_type_sd = (INSTR_RI[6:0] == 7'b0110011 && INSTR_RI[31:25] == 7'b0000001) ? 1'b1 : 1'b0; 

//-------------------------
// Instruction decoding
//-------------------------
// R Type
assign add_i_sd = (r_type_sd && (INSTR_RI[14:12] == 3'b000) && (!INSTR_RI[30])) ? 1'b1 : 1'b0;
assign sub_i_sd = (r_type_sd && (INSTR_RI[14:12] == 3'b000) && (INSTR_RI[30])) ? 1'b1 : 1'b0;
assign slt_i_sd = (r_type_sd && (INSTR_RI[14:12] == 3'b010) && (!INSTR_RI[30])) ? 1'b1 : 1'b0;
assign sltu_i_sd = (r_type_sd && (INSTR_RI[14:12] == 3'b011) && (!INSTR_RI[30])) ? 1'b1 : 1'b0;
assign and_i_sd = (r_type_sd && (INSTR_RI[14:12] == 3'b111) && (!INSTR_RI[30])) ? 1'b1 : 1'b0;
assign or_i_sd = (r_type_sd && (INSTR_RI[14:12] == 3'b110) && (!INSTR_RI[30])) ? 1'b1 : 1'b0;
assign xor_i_sd = (r_type_sd && (INSTR_RI[14:12] == 3'b100) && (!INSTR_RI[30])) ? 1'b1 : 1'b0;
assign sll_i_sd = (r_type_sd && (INSTR_RI[14:12] == 3'b001) && (!INSTR_RI[30])) ? 1'b1 : 1'b0;
assign srl_i_sd = (r_type_sd && (INSTR_RI[14:12] == 3'b101) && (!INSTR_RI[30])) ? 1'b1 : 1'b0;
assign sra_i_sd = (r_type_sd && (INSTR_RI[14:12] == 3'b101) && (INSTR_RI[30])) ? 1'b1 : 1'b0;

// I type
assign addi_i_sd = (nmem_type_sd && (INSTR_RI[14:12] == 3'b000)) ? 1'b1 : 1'b0;
assign slti_i_sd = (nmem_type_sd && (INSTR_RI[14:12] == 3'b010)) ? 1'b1 : 1'b0;
assign sltiu_i_sd = (nmem_type_sd && (INSTR_RI[14:12] == 3'b011)) ? 1'b1 : 1'b0;
assign andi_i_sd = (nmem_type_sd && (INSTR_RI[14:12] == 3'b111)) ? 1'b1 : 1'b0;
assign ori_i_sd = (nmem_type_sd && (INSTR_RI[14:12] == 3'b110)) ? 1'b1 : 1'b0;
assign xori_i_sd = (nmem_type_sd && (INSTR_RI[14:12] == 3'b100)) ? 1'b1 : 1'b0;
assign slli_i_sd = (nmem_type_sd == 1 && INSTR_RI[14:12] == 3'b001) ? 1'b1 : 1'b0;
assign srli_i_sd = (nmem_type_sd == 1 && INSTR_RI[14:12] == 3'b101 && INSTR_RI[30] == 1'b0) ? 1'b1 : 1'b0;
assign srai_i_sd = (nmem_type_sd == 1 && INSTR_RI[14:12] == 3'b101 && INSTR_RI[30] == 1'b1) ? 1'b1 : 1'b0;

// B type_sd
assign beq_i_sd = (b_type_sd == 1 && INSTR_RI[14:12] == 3'b000) ? 1'b1 : 1'b0;
assign bne_i_sd = (b_type_sd == 1 && INSTR_RI[14:12] == 3'b001) ? 1'b1 : 1'b0;
assign blt_i_sd = (b_type_sd == 1 && INSTR_RI[14:12] == 3'b100) ? 1'b1 : 1'b0;
assign bge_i_sd = (b_type_sd == 1 && INSTR_RI[14:12] == 3'b101) ? 1'b1 : 1'b0;
assign bltu_i_sd = (b_type_sd == 1 && INSTR_RI[14:12] == 3'b110) ? 1'b1 : 1'b0;
assign bgeu_i_sd = (b_type_sd == 1 && INSTR_RI[14:12] == 3'b111) ? 1'b1 : 1'b0;

// U type
assign lui_i_sd = u_type_sd;
assign auipc_i_sd = (INSTR_RI[6:0] == 7'h1B) ? 1'b1 : 1'b0;

// J type
assign jal_i_sd = j_type_sd;
assign jalr_i_sd = jalr_type_sd;

// Mem access
assign lw_i_sd = (load_type_sd == 1 && INSTR_RI[14:12] == 3'b010) ? 1'b1 : 1'b0;
assign lh_i_sd = (load_type_sd == 1 && INSTR_RI[14:12] == 3'b001) ? 1'b1 : 1'b0;
assign lhu_i_sd = (load_type_sd == 1 && INSTR_RI[14:12] == 3'b101) ? 1'b1 : 1'b0;
assign lb_i_sd = (load_type_sd == 1 && INSTR_RI[14:12] == 3'b000) ? 1'b1 : 1'b0;
assign lbu_i_sd = (load_type_sd == 1 && INSTR_RI[14:12] == 3'b100) ? 1'b1 : 1'b0;

assign sw_i_sd = (s_type_sd == 1 && INSTR_RI[14:12] == 3'b010) ? 1'b1 : 1'b0;
assign sh_i_sd = (s_type_sd == 1 && INSTR_RI[14:12] == 3'b001) ? 1'b1 : 1'b0;
assign sb_i_sd = (s_type_sd && (INSTR_RI[14:12] == 3'h0)) ? 1'b1 : 1'b0;

// M type
assign mul_i_sd = (m_type_sd && (INSTR_RI[14:12] == 3'h0)) ? 1'b1 : 1'b0;
assign mulh_i_sd = (m_type_sd && (INSTR_RI[14:12] == 3'h1)) ? 1'b1 : 1'b0;
assign mulhsu_i_sd = (m_type_sd && (INSTR_RI[14:12] == 3'h2)) ? 1'b1 : 1'b0;
assign mulhu_i_sd = (m_type_sd && (INSTR_RI[14:12] == 3'h3)) ? 1'b1 : 1'b0;
assign div_i_sd = (m_type_sd && (INSTR_RI[14:12] == 3'h4)) ? 1'b1 : 1'b0;
assign divu_i_sd = (m_type_sd && (INSTR_RI[14:12] == 3'h5)) ? 1'b1 : 1'b0;
assign rem_i_sd = (m_type_sd && (INSTR_RI[14:12] == 3'h6)) ? 1'b1 : 1'b0;
assign remu_i_sd = (m_type_sd && (INSTR_RI[14:12] == 3'h7)) ? 1'b1 : 1'b0;

// System type
assign ecall_i_sd = (system_inst_sd && (INSTR_RI[14:12] == 3'h0) && (INSTR_RI[31:20] == 12'h000)) ? 1'b1 : 1'b0;
assign ebreak_i_sd = (system_inst_sd && (INSTR_RI[14:12] == 3'h0) && (INSTR_RI[31:20] == 12'h001)) ? 1'b1 : 1'b0;
assign csrrw_i_sd = (system_inst_sd && (INSTR_RI[14:12] == 3'h1)) ? 1'b1 : 1'b0;
assign csrrs_i_sd = (system_inst_sd && (INSTR_RI[14:12] == 3'h2)) ? 1'b1 : 1'b0;
assign csrrc_i_sd = (system_inst_sd && (INSTR_RI[14:12] == 3'h3)) ? 1'b1 : 1'b0;
assign csrrwi_i_sd = (system_inst_sd && (INSTR_RI[14:12] == 3'h5)) ? 1'b1 : 1'b0;
assign csrrsi_i_sd = (system_inst_sd && (INSTR_RI[14:12] == 3'h6)) ? 1'b1 : 1'b0;
assign csrrci_i_sd = (system_inst_sd && (INSTR_RI[14:12] == 3'h7)) ? 1'b1 : 1'b0;
assign mret_i_sd = (INSTR_RI == 32'h30200073) ? 1'b1 : 1'b0;
assign sret_i_sd = (INSTR_RI == 32'h10200073) ? 1'b1 : 1'b0;

assign fence_i_sd = (INSTR_RI[6:0] == 7'h0F) && (INSTR_RI[14:12] == 3'h0) ? 1'b1 : 1'b0;

assign illegal_inst = !(add_i_sd || sub_i_sd || slt_i_sd || sltu_i_sd || and_i_sd || or_i_sd || xor_i_sd || sll_i_sd || srl_i_sd || sra_i_sd ||
                        addi_i_sd || slti_i_sd || sltiu_i_sd || andi_i_sd || ori_i_sd || xori_i_sd ||
                        slli_i_sd || srli_i_sd || srai_i_sd ||
                        beq_i_sd || bne_i_sd || blt_i_sd || bge_i_sd || bltu_i_sd || bgeu_i_sd || lui_i_sd || auipc_i_sd || jal_i_sd || jalr_i_sd ||
                        lw_i_sd || lh_i_sd || lhu_i_sd || lb_i_sd || lbu_i_sd || sw_i_sd || sh_i_sd || sb_i_sd ||
                        mul_i_sd || mulh_i_sd || mulhu_i_sd || mulhsu_i_sd ||
                        ecall_i_sd || ebreak_i_sd || csrrw_i_sd || csrrs_i_sd || csrrc_i_sd || csrrwi_i_sd || csrrsi_i_sd || csrrci_i_sd || mret_i_sd || sret_i_sd || fence_i_sd);

assign illegal_inst_sd = illegal_inst && !IF2DEC_EMPTY_SI;

// Env call  

assign env_call_u_mode_sd = (CURRENT_MODE_SM == 2'b00) && ecall_i_sd ? 1'b1 : 1'b0;
assign env_call_s_mode_sd = (CURRENT_MODE_SM != 2'b10) && sret_i_sd ? 1'b1 : 1'b0;
assign env_call_m_mode_sd = (CURRENT_MODE_SM == 2'b11) && ecall_i_sd ? 1'b1 : 1'b0;

assign env_call_wrong_mode = (CURRENT_MODE_SM != 2'b11) && mret_i_sd ? 1'b1 : 1'b0;

//------------------------------------
//-- Registers and operands selection
//------------------------------------
//-- Registers affectation 

// Registers and operands selection
// Registers affectation 

assign radr1_sd = (r_type_sd || i_type_sd || s_type_sd || b_type_sd || jalr_type_sd || m_type_sd  || csrrw_i_sd || csrrs_i_sd || csrrc_i_sd) 
                    ? {1'b0, INSTR_RI[19:15]} : 6'h00;

assign radr2_sd = (r_type_sd || s_type_sd || b_type_sd || m_type_sd) ? {1'b0, INSTR_RI[24:20]} : 6'h00;
assign rdest_sd = (r_type_sd || i_type_sd || u_type_sd || j_type_sd || jalr_type_sd || m_type_sd || csrrw_i_sd || csrrs_i_sd || csrrc_i_sd || csrrwi_i_sd 
                || csrrsi_i_sd || csrrci_i_sd) ? {1'b0, INSTR_RI[11:7]} : 6'h00;
assign csr_radr = (system_inst_sd && (csrrw_i_sd || csrrs_i_sd || csrrc_i_sd || csrrwi_i_sd || csrrsi_i_sd || csrrci_i_sd)) ? INSTR_RI[31:20] : 12'h0;


// Operand 1 selection
assign op1_u_type_sd[31:12] = INSTR_RI[31:12];
assign op1_u_type_sd[11:0] = 12'h0;

assign op1_csri_type_sd[31:5] = 27'd0;
assign op1_csri_type_sd[4:0] = INSTR_RI[19:15];

assign dec2exe_op1_sd = (r_type_sd || i_type_sd || s_type_sd || b_type_sd || csrrw_i_sd || csrrs_i_sd || m_type_sd) ? rdata1_sd :
                    (csrrc_i_sd) ? ~rdata1_sd : (csrrwi_i_sd || csrrsi_i_sd) ? op1_csri_type_sd : 
                    (csrrci_i_sd) ? ~op1_csri_type_sd : (u_type_sd) ? op1_u_type_sd : 
                    (j_type_sd || jalr_type_sd) ? READ_PC_SR : 32'h0;

// Operand 2 selection
assign op2_i_type_sd[31:12] = {20{INSTR_RI[31]}};
assign op2_i_type_sd[11:0] = INSTR_RI[31:20];

assign op2_s_type_sd[31:12] = {20{INSTR_RI[31]}};
assign op2_s_type_sd[11:5] = INSTR_RI[31:25];
assign op2_s_type_sd[4:0] = INSTR_RI[11:7];

assign dec2exe_op2_sd = (r_type_sd || b_type_sd || (u_type_sd && !auipc_i_sd) || m_type_sd) ? rdata2_sd :
                    (csrrs_i_sd || csrrc_i_sd || csrrsi_i_sd || csrrci_i_sd) ? CSR_RDATA_SC :
                    (i_type_sd) ? op2_i_type_sd : (s_type_sd) ? op2_s_type_sd : 
                    (auipc_i_sd) ? PC_IF2DEC_RI : 32'h0; 

//-------------------------
//-- Exec commands  
//-------------------------
//-- neg

assign neg_op2_sd = sub_i_sd || slt_i_sd || slti_i_sd || sltu_i_sd || sltiu_i_sd; 

// exe command 
assign alu_cmd =  (and_i_sd || andi_i_sd || srl_i_sd || srli_i_sd || csrrc_i_sd || csrrci_i_sd) ? 2'b01 :
                  (or_i_sd || ori_i_sd || sra_i_sd || srai_i_sd || csrrs_i_sd || csrrsi_i_sd) ? 2'b10 :
                  (xor_i_sd || xori_i_sd) ? 2'b11 : 2'b00;

assign mult_cmd = (mul_i_sd) ? 2'b01 :
                  (mulh_i_sd) ? 2'b10 :
                  (mulhu_i_sd) ? 2'b11 : 2'b00;

assign div_cmd =  (div_i_sd) ? 2'b01 :
                  (divu_i_sd) ? 2'b10 :
                  (rem_i_sd) ? 2'b11 : 2'b00;  

assign exe_cmd_sd = (select_operation_sd == 4'b1000) ? div_cmd :
                    (select_operation_sd == 4'b0100) ? mult_cmd :
                    alu_cmd;

assign select_operation_sd =  (div_i_sd || divu_i_sd || rem_i_sd || remu_i_sd) ? 4'b1000 :
                             (mul_i_sd || mulh_i_sd || mulhsu_i_sd || mulhu_i_sd) ? 4'b0100 :
                             (sll_i_sd || slli_i_sd || srl_i_sd || srli_i_sd || sra_i_sd || srai_i_sd) ? 4'b0010 :
                             4'b0001;

assign wb_sd = r_type_sd || i_type_sd || u_type_sd || b_type_sd || j_type_sd || jalr_type_sd || 
               csrrw_i_sd || csrrs_i_sd || csrrc_i_sd || csrrwi_i_sd || csrrsi_i_sd || csrrci_i_sd;

assign mem_data_sd = (s_type_sd) ? rdata2_sd : 32'h0;
assign mem_load_sd = lw_i_sd || lh_i_sd || lhu_i_sd || lb_i_sd || lbu_i_sd;

assign mem_store_sd = sw_i_sd || sh_i_sd || sb_i_sd;

assign mem_size_sd =  (lw_i_sd || sw_i_sd) ? 2'b00 :  // word size 
                      (lh_i_sd || lhu_i_sd || sh_i_sd) ? 2'b01 : // halfword size
                      (lb_i_sd || lbu_i_sd || sb_i_sd) ? 2'b10 : // byte size
                      2'b11; // not a mem access

assign mem_sign_extend_sd = lh_i_sd || lb_i_sd; 

assign csr_wenable_sd = csrrw_i_sd || csrrs_i_sd || csrrc_i_sd || csrrwi_i_sd || csrrsi_i_sd || csrrci_i_sd; 

//-------------------------
// Branch offset
//-------------------------
assign offset_branch_b[31:12] = {20{INSTR_RI[31]}};
assign offset_branch_b[11] = INSTR_RI[7];
assign offset_branch_b[10:5] = INSTR_RI[30:25];
assign offset_branch_b[4:1] = INSTR_RI[11:8];
assign offset_branch_b[0] = 1'b0;

assign offset_branch_j[31:20] = {12{INSTR_RI[31]}};
assign offset_branch_j[19:12] = INSTR_RI[19:12];
assign offset_branch_j[11] = INSTR_RI[20];
assign offset_branch_j[10:1] = INSTR_RI[30:21];
assign offset_branch_j[0] = 1'b0;

assign jalr_offset[31:12] = {20{INSTR_RI[31]}};
assign jalr_offset[11:0] = INSTR_RI[31:20];

assign jalr_offset_calc = jalr_offset + rdata1_sd - READ_PC_SR + inc_value;

assign offset_branch_jalr[31:1] = jalr_offset_calc[31:1];
assign offset_branch_jalr[0] = 1'b0;

assign offset_branch_sd = (b_type_sd) ? offset_branch_b :
(j_type_sd) ? offset_branch_j :
(jalr_type_sd) ? offset_branch_jalr : 32'h0;

assign res = dec2exe_op1_sd ^ dec2exe_op2_sd;
assign res_compare = $unsigned(dec2exe_op1_sd) - $unsigned(dec2exe_op2_sd);
assign different_sign = dec2exe_op1_sd[31] ^ dec2exe_op2_sd[31];

assign jump_sd = (b_type_sd) ?
                ((bne_i_sd && (res != 32'h0)) ||
                (beq_i_sd && (res == 32'h0)) ||
                (blt_i_sd && ((different_sign && dec2exe_op1_sd[31]) ||
                (!different_sign && res_compare[31]))) ||
                (bltu_i_sd && ((different_sign && dec2exe_op2_sd[31]) ||
                (!different_sign && res_compare[31]))) ||
                (bge_i_sd && ((different_sign && dec2exe_op2_sd[31]) ||
                (!different_sign && !res_compare[31])) ) ||
                (bgeu_i_sd && ((different_sign && dec2exe_op1_sd[31]) ||
                (!different_sign && !res_compare[31])))) :
                (j_type_sd || jalr_type_sd);

assign add_offset_to_pc = jump_sd & !IF2DEC_EMPTY_SI;

// PC
assign WRITE_PC_ENABLE_SD = (add_offset_to_pc == 1'b0 && dec2if_full_sd == 1'b0) ||
                            (add_offset_to_pc == 1'b1 && dec2if_full_sd == 1'b0 && stall_sd == 1'b0);

assign branch_adr_sd = PC_IF2DEC_RI + offset_branch_sd;

// initialize pc
always_ff @(posedge clk, negedge reset_n)
begin
    if (!reset_n) begin
        reset_sync_sd <= 1'b0;
    end else begin
        reset_sync_sd <= reset_n;
    end
end

assign resetting_sd = reset_sync_sd ^ reset_n;

assign pc_no_jump = (PRED_TAKEN_RI && stall_sd && !dec_fifo_pred_success && !dec_fifo_pred_failed) ?
                    (PRED_ADR_RI + inc_value) :
                    (PRED_TAKEN_RI && !stall_sd) ?
                    (PC_IF2DEC_RI + inc_value) :
                    (READ_PC_SR + inc_value);

assign pc_jump = (PRED_TAKEN_RI && add_offset_to_pc && !dec2if_full_sd && !stall_sd) ?
                 (PRED_ADR_RI + inc_value) :
                 branch_adr_sd;

assign pc = resetting_sd ? READ_PC_SR :
       (add_offset_to_pc == 0 && !dec2if_full_sd && reset_n) ? pc_no_jump :
       (add_offset_to_pc == 1 && !dec2if_full_sd && !stall_sd && reset_n) ? pc_jump :
        32'hABCDEF00;

assign instruction_access_fault_sd = (EXCEPTION_SM == 0 && CURRENT_MODE_SM != 2'b11 && pc > 32'hF0000000) ? 1'b1 : 1'b0;
assign instruction_adress_misaligned_sd = (pc[1:0] != 2'b00 || (RETURN_ADRESS_SM[1:0] != 2'b00 && EXCEPTION_SM == 1)) ? 1'b1 : 1'b0;

assign mtvec_value[31:1] = MTVEC_VALUE_RC[31:1];
assign mtvec_value[1:0] = 2'b00;

assign mcause_val[31:2] = MCAUSE_WDATA_SM[29:0];
assign mcause_val[1:0] = 2'b00;

assign new_pc = (MRET_SM == 0 && EXCEPTION_SM == 1'b1 && MTVEC_VALUE_RC[1:0] == 2'b00) ? MTVEC_VALUE_RC :
         (MRET_SM == 1'b0 && EXCEPTION_SM == 1'b1 && MTVEC_VALUE_RC[1:0] == 2'b01) ? mtvec_value + mcause_val :
         (MRET_SM == 1'b1 && EXCEPTION_SM == 1'b1) ? RETURN_ADRESS_SM :
         pc;

assign pc_branch_value_sd = new_pc;

assign WRITE_PC_SD = new_pc;

//-- branch prediction 

assign pred_success_sd = (PRED_TAKEN_RI && add_offset_to_pc && !dec2if_full_sd && !stall_sd) ? 1'b1 : 1'b0;
assign pred_failed_sd = (PRED_TAKEN_RI && !add_offset_to_pc && !dec2if_full_sd && !IF2DEC_EMPTY_SI) ? 1'b1 : 1'b0;

assign PRED_ADR_SD     = PRED_ADR_RI;
assign PRED_TAKEN_SD   = PRED_TAKEN_RI;

assign rd_link = (rdest_sd == 6'b000001 || rdest_sd == 6'b000101) ? 1'b1 : 1'b0;
assign rs1_link = (radr1_sd == 6'b000001 || radr1_sd == 6'b000101) ? 1'b1 : 1'b0;

assign pop_adr_ras_sd = (PRED_TAKEN_RI == 1'b0 && ((rd_link == 1'b0 && rs1_link == 1'b1) || (rd_link == 1'b1 && rs1_link == 1'b1 && (rdest_sd != radr1_sd)))) ? 1'b1 : 1'b0;
assign push_adr_ras_sd = (rd_link == 1'b1 && (jal_i_sd || jalr_i_sd)) ? 1'b1 : 1'b0;

assign ret_sd = (jalr_type_sd && rdest_sd == 6'b0 && offset_branch_sd == 32'h4 && radr1_sd == 6'b1) ? 1'b1 : 1'b0;

//-------------------------
// Bypass
//-------------------------

assign block_in_dec = (radr1_sd == dec_fifo_rdest || radr2_sd == dec_fifo_rdest) && mem_load_fifo && !dec2exe_empty;
assign block_bp_sd = jalr_type_sd;      

assign mult_dependency = (radr1_sd == dec_fifo_rdest && dec_fifo_mult_inst && !dec2exe_empty) || 
                         (radr2_sd == dec_fifo_rdest && dec_fifo_mult_inst && !dec2exe_empty) || 
                         (radr1_sd == BP_DEST_RE && MULT_INST_RE && !BP_EXE2MEM_EMPTY_SE) || 
                         (radr2_sd == BP_DEST_RE && MULT_INST_RE && !BP_EXE2MEM_EMPTY_SE) || 
                         (radr1_sd == BP_DEST_RM && MULT_INST_RM && !BP_MEM2WBK_EMPTY_SM) || 
                         (radr2_sd == BP_DEST_RM && MULT_INST_RM && !BP_MEM2WBK_EMPTY_SM);

// Conditions

assign bpc_instr_in_exe1 = (radr1_sd == dec_fifo_rdest) && !dec2exe_empty && (radr1_sd != 6'b0);
assign bpc_load_in_mem1 = (radr1_sd == BP_DEST_RE) && BP_MEM_LOAD_RE && (radr1_sd != 6'b0) && !BP_EXE2MEM_EMPTY_SE;
assign bpc_ed1 = (radr1_sd == BP_DEST_RE) && !BP_EXE2MEM_EMPTY_SE && (radr1_sd != 6'b0);
assign bpc_md1 = (radr1_sd == BP_DEST_RM) && !BP_MEM2WBK_EMPTY_SM && (radr1_sd != 6'b0);

assign bpc_instr_in_exe2 = (radr2_sd == dec_fifo_rdest) && !dec2exe_empty && (radr2_sd != 6'b0);
assign bpc_load_in_mem2 = (radr2_sd == BP_DEST_RE) && BP_MEM_LOAD_RE && (radr2_sd != 6'b0) && !BP_EXE2MEM_EMPTY_SE;
assign bpc_ed2 = (radr2_sd == BP_DEST_RE) && !BP_EXE2MEM_EMPTY_SE && (radr2_sd != 6'b0);
assign bpc_md2 = (radr2_sd == BP_DEST_RM) && !BP_MEM2WBK_EMPTY_SM && (radr2_sd != 6'b0);

assign bpc_mult_exe1 = (radr1_sd == BP_DEST_RE) && MULT_INST_RE && !BP_EXE2MEM_EMPTY_SE;
assign bpc_mult_exe2 = (radr2_sd == BP_DEST_RE) && MULT_INST_RE && !BP_EXE2MEM_EMPTY_SE;

assign bpc_mult_mem1 = (radr1_sd == BP_DEST_RM) && MULT_INST_RM && !BP_MEM2WBK_EMPTY_SM;
assign bpc_mult_mem2 = (radr2_sd == BP_DEST_RM) && MULT_INST_RM && !BP_MEM2WBK_EMPTY_SM;

assign rdata1_sd = (bpc_ed1 && !CSR_WENABLE_RE) ? BP_EXE_RES_RE :
                    (bpc_ed1 && CSR_WENABLE_RE) ? CSR_RDATA_RE :
                    (bpc_md1 && !CSR_WENABLE_RM) ? BP_MEM_RES_RM :
                    (bpc_md1 && CSR_WENABLE_RM) ? CSR_RDATA_RM :
                    RDATA1_SR;

assign r1_valid_sd = !bpc_instr_in_exe1 && !bpc_load_in_mem1 && !bpc_mult_exe1 && !bpc_mult_mem1;

assign rdata2_sd = (bpc_ed2 && !CSR_WENABLE_RE) ? BP_EXE_RES_RE :
                    (bpc_ed2 && CSR_WENABLE_RE) ? CSR_RDATA_RE :
                    (bpc_md2 && !CSR_WENABLE_RM) ? BP_MEM_RES_RM :
                    (bpc_md2 && CSR_WENABLE_RM) ? CSR_RDATA_RM :
                    RDATA2_SR;

assign r2_valid_sd = !bpc_instr_in_exe2 && !bpc_load_in_mem2 && !bpc_mult_exe2 && !bpc_mult_mem2;

assign exception_sd = illegal_inst_sd || instruction_adress_misaligned_sd || env_call_u_mode_sd ||
env_call_m_mode_sd || env_call_s_mode_sd || env_call_wrong_mode || mret_i_sd ||
instruction_access_fault_sd || ebreak_i_sd;

//-------------------------
//-- Ouput
//-------------------------
//-- affectation 

assign DEC2EXE_EMPTY_SD = dec2exe_empty;
assign REG_ADR1_SD = radr1_sd;
assign REG_ADR2_SD = radr2_sd;
assign MEM_LOAD_RD = mem_load_fifo;
assign DEST_RD = dec_fifo_rdest;
assign CSR_WENABLE_RD = csr_wenable_fifo;
assign CSR_RADR_SD = csr_radr;
assign MULT_INST_RD = dec_fifo_mult_inst;
assign PRED_SUCCESS_RD = dec_fifo_pred_success;
assign PRED_FAILED_RD = dec_fifo_pred_failed;

// fifo  
// dec2if 
assign dec2if_din[31:0] = new_pc;
assign dec2if_din[63:32] = branch_adr_sd; 
assign dec2if_din[95:64] = PC_IF2DEC_RI; 
assign dec2if_din[96] = b_type_sd | j_type_sd; 
assign dec2if_din[97] = pred_success_sd; 
assign dec2if_din[98] = pred_failed_sd; 
assign dec2if_din[99] = ret_sd; 
assign dec2if_din[131:100] = $unsigned(PC_IF2DEC_RI) + $unsigned(inc_value);
assign dec2if_din[132] = pop_adr_ras_sd; 
assign dec2if_din[133] = push_adr_ras_sd; 

assign PC_RD = dec2if_dout[31:0];
assign ADR_TO_BRANCH_RD = dec2if_dout[63:32];
assign BRANCH_INST_ADR_RD = dec2if_dout[95:64];
assign BRANCH_INST_RD = dec2if_dout[96];
assign dec_fifo_pred_success = dec2if_dout[97];
assign dec_fifo_pred_failed = dec2if_dout[98];
assign RET_INST_RD = dec2if_dout[99];
assign ADR_TO_RET_RD = dec2if_dout[131:100];
assign POP_ADR_RAS_RD = dec2if_dout[132];
assign PUSH_ADR_RAS_RD = dec2if_dout[133];

// dec2exe 
assign dec2exe_data[251] = mul_i_sd | mulh_i_sd | mulhsu_i_sd | mulhu_i_sd;  
assign dec2exe_data[250:248] = select_operation_sd[3:1];
assign dec2exe_data[247:216] = pc_branch_value_sd;
assign dec2exe_data[215] = ebreak_i_sd; 
assign dec2exe_data[214] = instruction_access_fault_sd; 
assign dec2exe_data[213] = mret_i_sd; 
assign dec2exe_data[212] = exception_sd; 
assign dec2exe_data[211] = env_call_wrong_mode;
assign dec2exe_data[210] = env_call_u_mode_sd;
assign dec2exe_data[209] = illegal_inst_sd;
assign dec2exe_data[208] = instruction_adress_misaligned_sd;
assign dec2exe_data[207] = env_call_m_mode_sd;
assign dec2exe_data[206] = env_call_s_mode_sd;
assign dec2exe_data[205:174] = CSR_RDATA_SC; 
assign dec2exe_data[173] = csr_wenable_sd;
assign dec2exe_data[172:161] = csr_radr;
assign dec2exe_data[160:129] = PC_IF2DEC_RI; 
assign dec2exe_data[128] = block_bp_sd; 
assign dec2exe_data[127] = r1_valid_sd; 
assign dec2exe_data[126] = r2_valid_sd;
assign dec2exe_data[125:120] = radr1_sd; 
assign dec2exe_data[119:114] = radr2_sd;
assign dec2exe_data[113:112] = exe_cmd_sd;
assign dec2exe_data[111:80] = dec2exe_op1_sd;
assign dec2exe_data[111:80] = dec2exe_op1_sd;
assign dec2exe_data[79:48] = dec2exe_op2_sd;
assign dec2exe_data[47] = neg_op2_sd; 
assign dec2exe_data[46] = wb_sd; 
assign dec2exe_data[45:14] = mem_data_sd;
assign dec2exe_data[13] = mem_load_sd;
assign dec2exe_data[12] = mem_store_sd; 
assign dec2exe_data[11] = mem_sign_extend_sd; 
assign dec2exe_data[10:9] = mem_size_sd; 
assign dec2exe_data[8] = select_operation_sd[0]; 
assign dec2exe_data[7:2] = rdest_sd; 
assign dec2exe_data[1] = (slt_i_sd | slti_i_sd);
assign dec2exe_data[0] = (sltu_i_sd | sltiu_i_sd);

assign dec2exe_x[251:161] = 0;
assign dec2exe_x[160:129] = PC_IF2DEC_RI;
assign dec2exe_x[128:0] = 0;

assign dec2exe_din = (EXCEPTION_SM == 1) ? dec2exe_x : dec2exe_data;

assign dec_fifo_mult_inst = dec2exe_dout[251];
assign SELECT_OPERATION_RD[3:1] = dec2exe_dout[250:248];
assign PC_BRANCH_VALUE_RD = dec2exe_dout[247:216]; 
assign EBREAK_RD = dec2exe_dout[215];
assign INSTRUCTION_ACCESS_FAULT_RD = dec2exe_dout[214];
assign MRET_RD = dec2exe_dout[213];
assign EXCEPTION_RD = dec2exe_dout[212];
assign ENV_CALL_WRONG_MODE_RD = dec2exe_dout[211];
assign ENV_CALL_U_MODE_RD = dec2exe_dout[210];
assign ILLEGAL_INSTRUCTION_RD = dec2exe_dout[209];
assign ADRESS_MISALIGNED_RD = dec2exe_dout[208];
assign ENV_CALL_M_MODE_RD = dec2exe_dout[207];
assign ENV_CALL_S_MODE_RD = dec2exe_dout[206];                
assign CSR_RDATA_RD = dec2exe_dout[205:174];
assign csr_wenable_fifo = dec2exe_dout[173];
assign CSR_WADR_RD = dec2exe_dout[172:161];
assign PC_DEC2EXE_RD = dec2exe_dout[160:129];
assign BLOCK_BP_RD = dec2exe_dout[128];
assign BP_R1_VALID_RD = dec2exe_dout[127];
assign BP_R2_VALID_RD = dec2exe_dout[126];
assign BP_RADR1_RD = dec2exe_dout[125:120];
assign BP_RADR2_RD = dec2exe_dout[119:114];
assign CMD_RD = dec2exe_dout[113:112];
assign OP1_RD = dec2exe_dout[111:80];
assign OP2_RD = dec2exe_dout[79:48];
assign NEG_OP2_RD = dec2exe_dout[47];
assign WB_RD = dec2exe_dout[46];
assign MEM_DATA_RD = dec2exe_dout[45:14];
assign mem_load_fifo = dec2exe_dout[13];
assign MEM_STORE_RD = dec2exe_dout[12];
assign MEM_SIGN_EXTEND_RD = dec2exe_dout[11];
assign MEM_SIZE_RD = dec2exe_dout[10:9];
assign SELECT_OPERATION_RD[0] = dec2exe_dout[8];
assign dec_fifo_rdest = dec2exe_dout[7:2];
assign SLT_RD = dec2exe_dout[1];
assign SLTU_RD = dec2exe_dout[0];

endmodule