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
logic reset_sync;
logic resetting ;

// fifo
logic [133:0] dec2if_din, dec2if_dout;
logic dec2if_full, dec2if_push;
logic [251:0] dec2exe_din, dec2exe_data, dec2exe_x, dec2exe_dout;
logic dec2exe_full, dec2exe_push;

// Instructions
logic r_type, i_type, s_type, b_type, u_type, j_type, jalr_type;
logic load_type, nmem_type;
logic m_type;

logic add, sub, slt, sltu, andd, orr, xorr, sll, srl, sra;
logic addi, slti, sltiu, andi, ori, xori, slli, srli, srai;

logic lw, lh, lhu, lb, lbu, sw, sh, sb;

logic beq, bne, blt, bge, bltu, bgeu;

logic lui;
logic auipc;

logic jal, jalr;

logic mul, mulh, mulhsu, mulhu;
logic div, divu, rem, remu;

// System instructions
logic system_inst;
logic ecall;
logic ebreak;
logic csrrw, csrrs, csrrc;
logic csrrwi, csrrsi, csrrci;
logic sret;
logic mret ;
logic csr_in_progress;

logic fence;

logic env_call_u_mode ;
logic env_call_s_mode ;
logic env_call_m_mode ;
logic env_call_wrong_mode;

logic exception ;

logic csr_wenable;

logic illegal_inst ;
logic instruction_access_fault ;
logic instruction_adress_misaligned ;
logic instruction_adress_fault ;

logic [31:0] op1_csri_type;

logic [31:0] mtvec_value, mcause_val;

logic [11:0] csr_radr;

// dec2exe data andd commands
logic [31:0] dec2exe_op1, dec2exe_op2, op1_u_type, op2_i_type, op2_s_type;
logic [5:0] radr1, radr2, rdest;
logic [31:0] rdata1, rdata2;
logic neg_op2;
logic [1:0] exe_cmd, alu_cmd, mult_cmd, div_cmd;
logic [3:0] select_operation;
logic [31:0] mem_data;
logic mem_load, mem_store, mem_sign_extend;
logic [1:0] mem_size;
logic wb;
// branch andd pc gestion
logic [31:0] offset_branch, offset_branch_j, offset_branch_jalr, jalr_offset;
logic [31:0] offset_branch_b;
logic [31:0] jalr_offset_calc;
logic jump;
logic different_sign;
logic [31:0] res;
logic [31:0] res_compare;
logic add_offset_to_pc;
logic [31:0] pc = 32'h0;
logic [31:0] init_pc;
logic [31:0] new_pc;
logic [31:0] pc_branch_value;
logic [31:0] branch_adr;
logic rd_link, rs1_link;
logic pred_success, pred_failed = 1'b0;
logic ret;

logic [31:0] pc_no_jump, pc_jump;
logic pop_adr_ras, push_adr_ras;

// bypass
logic stall, block_in_dec;
logic r1_valid, r2_valid;
logic block_bp;
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
    .PUSH(dec2if_push),
    .POP(DEC2IF_POP_SI),
    .FULL(dec2if_full),
    .EMPTY(DEC2IF_EMPTY_SD),
    .DOUT(dec2if_dout)
);

fifo #(
    .N(252)
    ) dec2exe (
    .clk(clk),
    .reset_n(reset_n),
    .DIN(dec2exe_din),
    .PUSH(dec2exe_push),
    .POP(DEC2EXE_POP_SE),
    .FULL(dec2exe_full),
    .EMPTY(dec2exe_empty),
    .DOUT(dec2exe_dout)
);

// fifo gestion 
assign csr_in_progress = (csr_wenable_fifo & !dec2exe_empty) | (CSR_WENABLE_RE & !BP_EXE2MEM_EMPTY_SE);

assign stall = ((csr_in_progress | ((!r1_valid | !r2_valid) & (b_type | jalr_type | j_type | block_in_dec | mult_dependency))) | IF2DEC_EMPTY_SI | dec2exe_full) ? 1'b1 : 1'b0;

// if2dec 
assign IF2DEC_POP_SD = !stall;

assign IF2DEC_FLUSH_SD = (PRED_TAKEN_RI & (!jump & !stall)) | (!PRED_TAKEN_RI & (jump & !stall)) ? 1'b1 : 1'b0;

assign dec2if_push = (!add_offset_to_pc & !dec2if_full) | (add_offset_to_pc & !dec2if_full & !stall) ? 1'b1 : 1'b0;

// dec2exe
assign dec2exe_push = !stall; 

// Instruction type 
assign r_type        = INSTR_RI[6:0] == 7'b0110011 ;
assign i_type        = INSTR_RI[6:0] == 7'b0010011 | INSTR_RI[6:0] == 7'b0000011 ;
assign s_type        = INSTR_RI[6:0] == 7'b0100011 ;
assign b_type        = INSTR_RI[6:0] == 7'b1100011 ;
assign u_type        = INSTR_RI[6:0] == 7'b0110111 | INSTR_RI[6:0] == 7'b0010111 ;
assign j_type        = INSTR_RI[6:0] == 7'b1101111 ;
assign jalr_type     = INSTR_RI[6:0] == 7'b1100111 ;
assign load_type     = INSTR_RI[6:0] == 7'b0000011 ;
assign nmem_type     = INSTR_RI[6:0] == 7'b0010011 ; // not mem type but i type
assign system_inst   = INSTR_RI[6:0] == 7'b1110011 ;
assign m_type        = INSTR_RI[6:0] == 7'b0110011 & INSTR_RI[31:25] == 7'b0000001 ; 

//-------------------------
// Instruction decoding
//-------------------------
// R Type
assign add         = r_type & INSTR_RI[14:12] == 3'b000 & !INSTR_RI[30] ;
assign sub         = r_type & INSTR_RI[14:12] == 3'b000 &  INSTR_RI[30] ;
assign slt         = r_type & INSTR_RI[14:12] == 3'b010 & !INSTR_RI[30] ;
assign sltu        = r_type & INSTR_RI[14:12] == 3'b011 & !INSTR_RI[30] ;
assign andd         = r_type & INSTR_RI[14:12] == 3'b111 & !INSTR_RI[30] ;
assign orr          = r_type & INSTR_RI[14:12] == 3'b110 & !INSTR_RI[30] ;
assign xorr         = r_type & INSTR_RI[14:12] == 3'b100 & !INSTR_RI[30] ;
assign sll         = r_type & INSTR_RI[14:12] == 3'b001 & !INSTR_RI[30] ;
assign srl         = r_type & INSTR_RI[14:12] == 3'b101 & !INSTR_RI[30] ;
assign sra         = r_type & INSTR_RI[14:12] == 3'b101 &  INSTR_RI[30] ;

// I type
assign addi        = nmem_type & INSTR_RI[14:12] == 3'b000 ;
assign slti        = nmem_type & INSTR_RI[14:12] == 3'b010 ;
assign sltiu       = nmem_type & INSTR_RI[14:12] == 3'b011 ;
assign andi        = nmem_type & INSTR_RI[14:12] == 3'b111 ;
assign ori         = nmem_type & INSTR_RI[14:12] == 3'b110 ;
assign xori        = nmem_type & INSTR_RI[14:12] == 3'b100 ;
assign slli        = nmem_type & INSTR_RI[14:12] == 3'b001 ;
assign srli        = nmem_type & INSTR_RI[14:12] == 3'b101 & !INSTR_RI[30] ;
assign srai        = nmem_type & INSTR_RI[14:12] == 3'b101 &  INSTR_RI[30] ;

// B type
assign beq         = b_type & INSTR_RI[14:12] == 3'b000 ;
assign bne         = b_type & INSTR_RI[14:12] == 3'b001 ;
assign blt         = b_type & INSTR_RI[14:12] == 3'b100 ;
assign bge         = b_type & INSTR_RI[14:12] == 3'b101 ;
assign bltu        = b_type & INSTR_RI[14:12] == 3'b110 ;
assign bgeu        = b_type & INSTR_RI[14:12] == 3'b111 ;

// U type
assign lui         = u_type;
assign auipc       = INSTR_RI[6:0] == 7'b0010111 ;

// J type
assign jal         = j_type;
assign jalr        = jalr_type;

// Mem access
assign lw          = load_type & INSTR_RI[14:12] == 3'b010 ;
assign lh          = load_type & INSTR_RI[14:12] == 3'b001 ;
assign lhu         = load_type & INSTR_RI[14:12] == 3'b101 ;
assign lb          = load_type & INSTR_RI[14:12] == 3'b000 ;
assign lbu         = load_type & INSTR_RI[14:12] == 3'b100 ;

assign sw          = s_type & INSTR_RI[14:12] == 3'b010 ;
assign sh          = s_type & INSTR_RI[14:12] == 3'b001 ;
assign sb          = s_type & INSTR_RI[14:12] == 3'h0   ;

// M type
assign mul         = m_type & INSTR_RI[14:12] == 3'h0 ;
assign mulh        = m_type & INSTR_RI[14:12] == 3'h1 ;
assign mulhsu      = m_type & INSTR_RI[14:12] == 3'h2 ;
assign mulhu       = m_type & INSTR_RI[14:12] == 3'h3 ;
assign div         = m_type & INSTR_RI[14:12] == 3'h4 ;
assign divu        = m_type & INSTR_RI[14:12] == 3'h5 ;
assign rem         = m_type & INSTR_RI[14:12] == 3'h6 ;
assign remu        = m_type & INSTR_RI[14:12] == 3'h7 ;

// System type
assign ecall       = system_inst & INSTR_RI[14:12] == 3'h0 & INSTR_RI[31:20] == 12'h000 ;
assign ebreak      = system_inst & INSTR_RI[14:12] == 3'h0 & INSTR_RI[31:20] == 12'h001 ;
assign csrrw       = system_inst & INSTR_RI[14:12] == 3'h1 ;
assign csrrs       = system_inst & INSTR_RI[14:12] == 3'h2 ;
assign csrrc       = system_inst & INSTR_RI[14:12] == 3'h3 ;
assign csrrwi      = system_inst & INSTR_RI[14:12] == 3'h5 ;
assign csrrsi      = system_inst & INSTR_RI[14:12] == 3'h6 ;
assign csrrci      = system_inst & INSTR_RI[14:12] == 3'h7 ;
assign mret        = INSTR_RI == 32'h30200073;
assign sret        = INSTR_RI == 32'h10200073;
assign fence       = INSTR_RI[6:0] == 7'h0F & INSTR_RI[14:12] == 3'h0;

assign illegal_inst = !(add | sub | slt | sltu | andd | orr | xorr | sll | srl | sra |
                        addi | slti | sltiu | andi | ori | xori |
                        slli | srli | srai |
                        beq | bne | blt | bge | bltu | bgeu | lui | auipc | jal | jalr |
                        lw | lh | lhu | lb | lbu | sw | sh | sb |
                        mul | mulh | mulhu | mulhsu |
                        ecall | ebreak | csrrw | csrrs | csrrc | csrrwi | csrrsi | csrrci | mret | sret | fence);

assign illegal_inst = illegal_inst & !IF2DEC_EMPTY_SI;

// Env call  

assign env_call_u_mode  = CURRENT_MODE_SM  == 2'b00 & ecall ;
assign env_call_s_mode  = CURRENT_MODE_SM  == 2'b10 & sret  ;
assign env_call_m_mode  = CURRENT_MODE_SM  == 2'b11 & ecall ;

assign env_call_wrong_mode = CURRENT_MODE_SM != 2'b11 & mret ;

//------------------------------------
//-- Registers andd operands selection
//------------------------------------
//-- Registers affectation 

// Registers andd operands selection
// Registers affectation 

assign radr1 = (r_type | i_type | s_type | b_type | jalr_type | m_type  | csrrw | csrrs | csrrc) 
                    ? {1'b0, INSTR_RI[19:15]} : 6'h00;

assign radr2 = (r_type | s_type | b_type | m_type) ? {1'b0, INSTR_RI[24:20]} : 6'h00;
assign rdest = (r_type | i_type | u_type | j_type | jalr_type | m_type | csrrw | csrrs | csrrc | csrrwi 
                | csrrsi | csrrci) ? {1'b0, INSTR_RI[11:7]} : 6'h00;
assign csr_radr = (system_inst & (csrrw | csrrs | csrrc | csrrwi | csrrsi | csrrci)) ? INSTR_RI[31:20] : 12'h0;


// Operand 1 selection
assign op1_u_type[31:12] = INSTR_RI[31:12];
assign op1_u_type[11:0] = 12'h0;

assign op1_csri_type[31:5] = 27'd0;
assign op1_csri_type[4:0] = INSTR_RI[19:15];

assign dec2exe_op1 = (r_type | i_type | s_type | b_type | csrrw | csrrs | m_type) ? rdata1 :
                    (csrrc) ? ~rdata1 : (csrrwi | csrrsi) ? op1_csri_type : 
                    (csrrci) ? ~op1_csri_type : (u_type) ? op1_u_type : 
                    (j_type | jalr_type) ? READ_PC_SR : 32'h0;

// Operand 2 selection
assign op2_i_type[31:12] = {20{INSTR_RI[31]}};
assign op2_i_type[11:0] = INSTR_RI[31:20];

assign op2_s_type[31:12] = {20{INSTR_RI[31]}};
assign op2_s_type[11:5] = INSTR_RI[31:25];
assign op2_s_type[4:0] = INSTR_RI[11:7];

assign dec2exe_op2 = (r_type | b_type | (u_type & !auipc) | m_type) ? rdata2 :
                    (csrrs | csrrc | csrrsi | csrrci) ? CSR_RDATA_SC :
                    (i_type) ? op2_i_type : (s_type) ? op2_s_type : 
                    (auipc) ? PC_IF2DEC_RI : 32'h0; 

//-------------------------
//-- Exec commands  
//-------------------------
//-- neg

assign neg_op2 = sub | slt | slti | sltu | sltiu; 

// exe command 
assign alu_cmd =  (andd | andi | srl | srli | csrrc | csrrci) ? 2'b01 :
                  (orr | ori | sra | srai | csrrs | csrrsi) ? 2'b10 :
                  (xorr | xori) ? 2'b11 : 2'b00;

assign mult_cmd = {2{mulhu}} | {mulh, 1'b0} | {1'b0, mul};

assign div_cmd =  (div) ? 2'b01 :
                  (divu) ? 2'b10 :
                  (rem) ? 2'b11 : 2'b00;  

assign exe_cmd = (select_operation == 4'b1000) ? div_cmd :
                    (select_operation == 4'b0100) ? mult_cmd :
                    alu_cmd;

assign select_operation =  (div | divu | rem | remu) ? 4'b1000 :
                             (mul | mulh | mulhsu | mulhu) ? 4'b0100 :
                             (sll | slli | srl | srli | sra | srai) ? 4'b0010 :
                             4'b0001;

assign wb = r_type | i_type | u_type | b_type | j_type | jalr_type | 
               csrrw | csrrs | csrrc | csrrwi | csrrsi | csrrci;

assign mem_data = (s_type) ? rdata2 : 32'h0;
assign mem_load = lw | lh | lhu | lb | lbu;

assign mem_store = sw | sh | sb;

assign mem_size =  (lw | sw) ? 2'b00 :  // word size 
                      (lh | lhu | sh) ? 2'b01 : // halfword size
                      (lb | lbu | sb) ? 2'b10 : // byte size
                      2'b11; // not a mem access

assign mem_sign_extend = lh | lb; 

assign csr_wenable = csrrw | csrrs | csrrc | csrrwi | csrrsi | csrrci; 

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

assign jalr_offset_calc = jalr_offset + rdata1 - READ_PC_SR + inc_value;

assign offset_branch_jalr[31:1] = jalr_offset_calc[31:1];
assign offset_branch_jalr[0] = 1'b0;

assign offset_branch = (b_type) ? offset_branch_b :
(j_type) ? offset_branch_j :
(jalr_type) ? offset_branch_jalr : 32'h0;

assign res = dec2exe_op1 ^ dec2exe_op2;
assign res_compare = $unsigned(dec2exe_op1) - $unsigned(dec2exe_op2);
assign different_sign = dec2exe_op1[31] ^ dec2exe_op2[31];

assign jump = (b_type) ?
                ((bne & (res != 32'h0)) |
                (beq & (res == 32'h0)) |
                (blt & ((different_sign & dec2exe_op1[31]) |
                (!different_sign & res_compare[31]))) |
                (bltu & ((different_sign & dec2exe_op2[31]) |
                (!different_sign & res_compare[31]))) |
                (bge & ((different_sign & dec2exe_op2[31]) |
                (!different_sign & !res_compare[31])) ) |
                (bgeu & ((different_sign & dec2exe_op1[31]) |
                (!different_sign & !res_compare[31])))) :
                (j_type | jalr_type);

assign add_offset_to_pc = jump & !IF2DEC_EMPTY_SI;

// PC
assign WRITE_PC_ENABLE_SD = (add_offset_to_pc == 1'b0 & dec2if_full == 1'b0) |
                            (add_offset_to_pc == 1'b1 & dec2if_full == 1'b0 & stall == 1'b0);

assign branch_adr = PC_IF2DEC_RI + offset_branch;

// initialize pc
always_ff @(posedge clk, negedge reset_n)
begin
    if (!reset_n) begin
        reset_sync <= 1'b0;
    end else begin
        reset_sync <= reset_n;
    end
end

assign resetting = reset_sync ^ reset_n;

assign pc_no_jump = (PRED_TAKEN_RI & stall & !dec_fifo_pred_success & !dec_fifo_pred_failed) ?
                    (PRED_ADR_RI + inc_value) :
                    (PRED_TAKEN_RI & !stall) ?
                    (PC_IF2DEC_RI + inc_value) :
                    (READ_PC_SR + inc_value);

assign pc_jump = (PRED_TAKEN_RI & add_offset_to_pc & !dec2if_full & !stall) ?
                 (PRED_ADR_RI + inc_value) :
                 branch_adr;

assign pc = resetting ? READ_PC_SR :
       (add_offset_to_pc == 0 & !dec2if_full & reset_n) ? pc_no_jump :
       (add_offset_to_pc == 1 & !dec2if_full & !stall & reset_n) ? pc_jump :
        32'hABCDEF00;

assign instruction_access_fault = (EXCEPTION_SM == 0 & CURRENT_MODE_SM != 2'b11 & pc > 32'hF0000000) ? 1'b1 : 1'b0;
assign instruction_adress_misaligned = (pc[1:0] != 2'b00 | (RETURN_ADRESS_SM[1:0] != 2'b00 & EXCEPTION_SM == 1)) ? 1'b1 : 1'b0;

assign mtvec_value[31:1] = MTVEC_VALUE_RC[31:1];
assign mtvec_value[1:0] = 2'b00;

assign mcause_val[31:2] = MCAUSE_WDATA_SM[29:0];
assign mcause_val[1:0] = 2'b00;

assign new_pc = (MRET_SM == 0 & EXCEPTION_SM == 1'b1 & MTVEC_VALUE_RC[1:0] == 2'b00) ? MTVEC_VALUE_RC :
         (MRET_SM == 1'b0 & EXCEPTION_SM == 1'b1 & MTVEC_VALUE_RC[1:0] == 2'b01) ? mtvec_value + mcause_val :
         (MRET_SM == 1'b1 & EXCEPTION_SM == 1'b1) ? RETURN_ADRESS_SM :
         pc;

assign pc_branch_value = new_pc;

assign WRITE_PC_SD = new_pc;

//-- branch prediction 

assign pred_success = (PRED_TAKEN_RI & add_offset_to_pc & !dec2if_full & !stall) ? 1'b1 : 1'b0;
assign pred_failed = (PRED_TAKEN_RI & !add_offset_to_pc & !dec2if_full & !IF2DEC_EMPTY_SI) ? 1'b1 : 1'b0;

assign PRED_ADR_SD     = PRED_ADR_RI;
assign PRED_TAKEN_SD   = PRED_TAKEN_RI;

assign rd_link = (rdest == 6'b000001 | rdest == 6'b000101) ? 1'b1 : 1'b0;
assign rs1_link = (radr1 == 6'b000001 | radr1 == 6'b000101) ? 1'b1 : 1'b0;

assign pop_adr_ras = (PRED_TAKEN_RI == 1'b0 & ((rd_link == 1'b0 & rs1_link == 1'b1) | (rd_link == 1'b1 & rs1_link == 1'b1 & (rdest != radr1)))) ? 1'b1 : 1'b0;
assign push_adr_ras = (rd_link == 1'b1 & (jal | jalr)) ? 1'b1 : 1'b0;

assign ret = (jalr_type & rdest == 6'b0 & offset_branch == 32'h4 & radr1 == 6'b1) ? 1'b1 : 1'b0;

//-------------------------
// Bypass
//-------------------------

assign block_in_dec = (radr1 == dec_fifo_rdest | radr2 == dec_fifo_rdest) & mem_load_fifo & !dec2exe_empty;
assign block_bp = jalr_type;      

assign mult_dependency = (radr1 == dec_fifo_rdest & dec_fifo_mult_inst & !dec2exe_empty) | 
                         (radr2 == dec_fifo_rdest & dec_fifo_mult_inst & !dec2exe_empty) | 
                         (radr1 == BP_DEST_RE & MULT_INST_RE & !BP_EXE2MEM_EMPTY_SE) | 
                         (radr2 == BP_DEST_RE & MULT_INST_RE & !BP_EXE2MEM_EMPTY_SE) | 
                         (radr1 == BP_DEST_RM & MULT_INST_RM & !BP_MEM2WBK_EMPTY_SM) | 
                         (radr2 == BP_DEST_RM & MULT_INST_RM & !BP_MEM2WBK_EMPTY_SM);

// Conditions

assign bpc_instr_in_exe1 = (radr1 == dec_fifo_rdest) & !dec2exe_empty & (radr1 != 6'b0);
assign bpc_load_in_mem1 = (radr1 == BP_DEST_RE) & BP_MEM_LOAD_RE & (radr1 != 6'b0) & !BP_EXE2MEM_EMPTY_SE;
assign bpc_ed1 = (radr1 == BP_DEST_RE) & !BP_EXE2MEM_EMPTY_SE & (radr1 != 6'b0);
assign bpc_md1 = (radr1 == BP_DEST_RM) & !BP_MEM2WBK_EMPTY_SM & (radr1 != 6'b0);

assign bpc_instr_in_exe2 = (radr2 == dec_fifo_rdest) & !dec2exe_empty & (radr2 != 6'b0);
assign bpc_load_in_mem2 = (radr2 == BP_DEST_RE) & BP_MEM_LOAD_RE & (radr2 != 6'b0) & !BP_EXE2MEM_EMPTY_SE;
assign bpc_ed2 = (radr2 == BP_DEST_RE) & !BP_EXE2MEM_EMPTY_SE & (radr2 != 6'b0);
assign bpc_md2 = (radr2 == BP_DEST_RM) & !BP_MEM2WBK_EMPTY_SM & (radr2 != 6'b0);

assign bpc_mult_exe1 = (radr1 == BP_DEST_RE) & MULT_INST_RE & !BP_EXE2MEM_EMPTY_SE;
assign bpc_mult_exe2 = (radr2 == BP_DEST_RE) & MULT_INST_RE & !BP_EXE2MEM_EMPTY_SE;

assign bpc_mult_mem1 = (radr1 == BP_DEST_RM) & MULT_INST_RM & !BP_MEM2WBK_EMPTY_SM;
assign bpc_mult_mem2 = (radr2 == BP_DEST_RM) & MULT_INST_RM & !BP_MEM2WBK_EMPTY_SM;

assign rdata1 = (bpc_ed1 & !CSR_WENABLE_RE) ? BP_EXE_RES_RE :
                    (bpc_ed1 & CSR_WENABLE_RE) ? CSR_RDATA_RE :
                    (bpc_md1 & !CSR_WENABLE_RM) ? BP_MEM_RES_RM :
                    (bpc_md1 & CSR_WENABLE_RM) ? CSR_RDATA_RM :
                    RDATA1_SR;

assign r1_valid = !bpc_instr_in_exe1 & !bpc_load_in_mem1 & !bpc_mult_exe1 & !bpc_mult_mem1;

assign rdata2 = (bpc_ed2 & !CSR_WENABLE_RE) ? BP_EXE_RES_RE :
                    (bpc_ed2 & CSR_WENABLE_RE) ? CSR_RDATA_RE :
                    (bpc_md2 & !CSR_WENABLE_RM) ? BP_MEM_RES_RM :
                    (bpc_md2 & CSR_WENABLE_RM) ? CSR_RDATA_RM :
                    RDATA2_SR;

assign r2_valid = !bpc_instr_in_exe2 & !bpc_load_in_mem2 & !bpc_mult_exe2 & !bpc_mult_mem2;

assign exception = illegal_inst | instruction_adress_misaligned | env_call_u_mode |
env_call_m_mode | env_call_s_mode | env_call_wrong_mode | mret |
instruction_access_fault | ebreak;

//-------------------------
//-- Ouput
//-------------------------
//-- affectation 

assign DEC2EXE_EMPTY_SD = dec2exe_empty;
assign REG_ADR1_SD = radr1;
assign REG_ADR2_SD = radr2;
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
assign dec2if_din[63:32] = branch_adr; 
assign dec2if_din[95:64] = PC_IF2DEC_RI; 
assign dec2if_din[96] = b_type | j_type; 
assign dec2if_din[97] = pred_success; 
assign dec2if_din[98] = pred_failed; 
assign dec2if_din[99] = ret; 
assign dec2if_din[131:100] = $unsigned(PC_IF2DEC_RI) + $unsigned(inc_value);
assign dec2if_din[132] = pop_adr_ras; 
assign dec2if_din[133] = push_adr_ras; 

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
assign dec2exe_data[251]        = mul | mulh | mulhsu | mulhu;  
assign dec2exe_data[250:248]    = select_operation[3:1];
assign dec2exe_data[247:216]    = pc_branch_value;
assign dec2exe_data[215]        = ebreak; 
assign dec2exe_data[214]        = instruction_access_fault; 
assign dec2exe_data[213]        = mret; 
assign dec2exe_data[212]        = exception; 
assign dec2exe_data[211]        = env_call_wrong_mode;
assign dec2exe_data[210]        = env_call_u_mode;
assign dec2exe_data[209]        = illegal_inst;
assign dec2exe_data[208]        = instruction_adress_misaligned;
assign dec2exe_data[207]        = env_call_m_mode;
assign dec2exe_data[206]        = env_call_s_mode;
assign dec2exe_data[205:174]    = CSR_RDATA_SC; 
assign dec2exe_data[173]        = csr_wenable;
assign dec2exe_data[172:161]    = csr_radr;
assign dec2exe_data[160:129]    = PC_IF2DEC_RI; 
assign dec2exe_data[128]        = block_bp; 
assign dec2exe_data[127]        = r1_valid; 
assign dec2exe_data[126]        = r2_valid;
assign dec2exe_data[125:120]    = radr1; 
assign dec2exe_data[119:114]    = radr2;
assign dec2exe_data[113:112]    = exe_cmd;
assign dec2exe_data[111:80]     = dec2exe_op1;
assign dec2exe_data[111:80]     = dec2exe_op1;
assign dec2exe_data[79:48]      = dec2exe_op2;
assign dec2exe_data[47]         = neg_op2; 
assign dec2exe_data[46]         = wb; 
assign dec2exe_data[45:14]      = mem_data;
assign dec2exe_data[13]         = mem_load;
assign dec2exe_data[12]         = mem_store; 
assign dec2exe_data[11]         = mem_sign_extend; 
assign dec2exe_data[10:9]       = mem_size; 
assign dec2exe_data[8]          = select_operation[0]; 
assign dec2exe_data[7:2]        = rdest; 
assign dec2exe_data[1]          = (slt | slti);
assign dec2exe_data[0]          = (sltu | sltiu);

assign dec2exe_x[251:161] = 0;
assign dec2exe_x[160:129] = PC_IF2DEC_RI;
assign dec2exe_x[128:0] = 0;

assign dec2exe_din = (EXCEPTION_SM == 1) ? dec2exe_x : dec2exe_data;

assign dec_fifo_mult_inst           = dec2exe_dout[251];
assign SELECT_OPERATION_RD[3:1]     = dec2exe_dout[250:248];
assign PC_BRANCH_VALUE_RD           = dec2exe_dout[247:216]; 
assign EBREAK_RD                    = dec2exe_dout[215];
assign INSTRUCTION_ACCESS_FAULT_RD  = dec2exe_dout[214];
assign MRET_RD                      = dec2exe_dout[213];
assign EXCEPTION_RD                 = dec2exe_dout[212];
assign ENV_CALL_WRONG_MODE_RD       = dec2exe_dout[211];
assign ENV_CALL_U_MODE_RD           = dec2exe_dout[210];
assign ILLEGAL_INSTRUCTION_RD       = dec2exe_dout[209];
assign ADRESS_MISALIGNED_RD         = dec2exe_dout[208];
assign ENV_CALL_M_MODE_RD           = dec2exe_dout[207];
assign ENV_CALL_S_MODE_RD           = dec2exe_dout[206];                
assign CSR_RDATA_RD                 = dec2exe_dout[205:174];
assign csr_wenable_fifo             = dec2exe_dout[173];
assign CSR_WADR_RD                  = dec2exe_dout[172:161];
assign PC_DEC2EXE_RD                = dec2exe_dout[160:129];
assign BLOCK_BP_RD                  = dec2exe_dout[128];
assign BP_R1_VALID_RD               = dec2exe_dout[127];
assign BP_R2_VALID_RD               = dec2exe_dout[126];
assign BP_RADR1_RD                  = dec2exe_dout[125:120];
assign BP_RADR2_RD                  = dec2exe_dout[119:114];
assign CMD_RD                       = dec2exe_dout[113:112];
assign OP1_RD                       = dec2exe_dout[111:80];
assign OP2_RD                       = dec2exe_dout[79:48];
assign NEG_OP2_RD                   = dec2exe_dout[47];
assign WB_RD                        = dec2exe_dout[46];
assign MEM_DATA_RD                  = dec2exe_dout[45:14];
assign mem_load_fifo                = dec2exe_dout[13];
assign MEM_STORE_RD                 = dec2exe_dout[12];
assign MEM_SIGN_EXTEND_RD           = dec2exe_dout[11];
assign MEM_SIZE_RD                  = dec2exe_dout[10:9];
assign SELECT_OPERATION_RD[0]       = dec2exe_dout[8];
assign dec_fifo_rdest               = dec2exe_dout[7:2];
assign SLT_RD                       = dec2exe_dout[1];
assign SLTU_RD                      = dec2exe_dout[0];

endmodule