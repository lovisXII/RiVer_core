// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VCORE_H_
#define _VCORE_H_  // guard

#include "systemc.h"
#include "verilated_sc.h"
#include "verilated.h"

//==========

class Vcore__Syms;

//----------

SC_MODULE(Vcore) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    sc_in<bool> clk;
    sc_in<bool> reset_n;
    sc_in<bool> MCACHE_STALL_SM;
    sc_out<bool> MCACHE_ADR_VALID_SM;
    sc_out<bool> MCACHE_STORE_SM;
    sc_out<bool> MCACHE_LOAD_SM;
    sc_out<uint32_t> byt_sel;
    sc_in<bool> IC_STALL_SI;
    sc_out<bool> ADR_VALID_SI;
    sc_in<uint32_t> MCACHE_RESULT_SM;
    sc_out<uint32_t> MCACHE_DATA_SM;
    sc_out<uint32_t> MCACHE_ADR_SM;
    sc_in<uint32_t> IC_INST_SI;
    sc_out<uint32_t> ADR_SI;
    sc_in<uint32_t> PC_INIT;
    sc_out<uint32_t> DEBUG_PC_READ;
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ core__DOT__DEC2IF_POP_SI;
        CData/*0:0*/ core__DOT__IF2DEC_FLUSH_SD;
        CData/*0:0*/ core__DOT__DEC2EXE_POP_SE;
        CData/*3:0*/ core__DOT__SELECT_OPERATION_RD;
        CData/*0:0*/ core__DOT__WRITE_PC_ENABLE_SD;
        CData/*0:0*/ core__DOT__EXE2MEM_POP_SM;
        CData/*5:0*/ core__DOT__MEM_DEST_RM;
        CData/*0:0*/ core__DOT__WB_RM;
        CData/*0:0*/ core__DOT__MEM2WBK_EMPTY_SM;
        CData/*0:0*/ core__DOT__CSR_ENABLE_SM;
        CData/*0:0*/ core__DOT__CSR_WENABLE_RM;
        CData/*1:0*/ core__DOT__CURRENT_MODE_SM;
        CData/*0:0*/ core__DOT__MULT_INST_RM;
        CData/*0:0*/ core__DOT__X0X1_POP_SX1;
        CData/*0:0*/ core__DOT__SELECT_MSB_RX1;
        CData/*0:0*/ core__DOT__X1X2_EMPTY_SX1;
        CData/*0:0*/ core__DOT__ifetch_i__DOT__if2dec_push_si;
        CData/*0:0*/ core__DOT__ifetch_i__DOT__stall_si;
        CData/*1:0*/ core__DOT__ifetch_i__DOT__next_pred_state;
        CData/*3:0*/ core__DOT__ifetch_i__DOT__pred_valid_reg;
        CData/*0:0*/ core__DOT__ifetch_i__DOT__pred_branch_taken;
        CData/*0:0*/ core__DOT__ifetch_i__DOT__unnamedblk2__DOT__found;
        CData/*1:0*/ core__DOT__ifetch_i__DOT__unnamedblk2__DOT__pred_write_pointer;
        CData/*0:0*/ core__DOT__ifetch_i__DOT__unnamedblk4__DOT__found;
        CData/*0:0*/ core__DOT__ifetch_i__DOT__unnamedblk4__DOT__pred_good;
        CData/*0:0*/ core__DOT__ifetch_i__DOT__if2dec__DOT__data_v;
        CData/*0:0*/ core__DOT__dec_i__DOT__reset_sync_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__dec2if_full_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__dec2if_push_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__i_type_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__u_type_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__m_type_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__sub_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__slt_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__sltu_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__and_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__or_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__xor_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__sll_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__srl_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__sra_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__slti_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__sltiu_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__andi_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__ori_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__xori_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__slli_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__srli_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__srai_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__lw_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__lh_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__lhu_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__lb_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__lbu_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__sw_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__sh_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__sb_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__beq_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__bne_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__blt_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__bge_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__bltu_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__bgeu_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__mul_i_sd;
    };
    struct {
        CData/*0:0*/ core__DOT__dec_i__DOT__mulh_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__mulhsu_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__mulhu_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__div_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__divu_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__rem_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__ecall_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__ebreak_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__csrrw_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__csrrs_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__csrrc_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__csrrwi_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__csrrsi_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__csrrci_i_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__env_call_u_mode_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__env_call_s_mode_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__env_call_m_mode_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__env_call_wrong_mode;
        CData/*0:0*/ core__DOT__dec_i__DOT__illegal_inst;
        CData/*0:0*/ core__DOT__dec_i__DOT__illegal_inst_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__instruction_access_fault_sd;
        CData/*5:0*/ core__DOT__dec_i__DOT__radr1_sd;
        CData/*5:0*/ core__DOT__dec_i__DOT__radr2_sd;
        CData/*5:0*/ core__DOT__dec_i__DOT__rdest_sd;
        CData/*3:0*/ core__DOT__dec_i__DOT__select_operation_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__jump_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__different_sign;
        CData/*0:0*/ core__DOT__dec_i__DOT__add_offset_to_pc;
        CData/*0:0*/ core__DOT__dec_i__DOT__rd_link;
        CData/*0:0*/ core__DOT__dec_i__DOT__rs1_link;
        CData/*0:0*/ core__DOT__dec_i__DOT__pred_failed_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__stall_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__r1_valid_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__r2_valid_sd;
        CData/*0:0*/ core__DOT__dec_i__DOT__bpc_ed1;
        CData/*0:0*/ core__DOT__dec_i__DOT__bpc_md1;
        CData/*0:0*/ core__DOT__dec_i__DOT__bpc_ed2;
        CData/*0:0*/ core__DOT__dec_i__DOT__bpc_md2;
        CData/*0:0*/ core__DOT__dec_i__DOT__dec2if__DOT__data_v;
        CData/*0:0*/ core__DOT__dec_i__DOT__dec2exe__DOT__data_v;
        CData/*0:0*/ core__DOT__exec_i__DOT__stall_se;
        CData/*0:0*/ core__DOT__exec_i__DOT__r1_valid_se;
        CData/*0:0*/ core__DOT__exec_i__DOT__r2_valid_se;
        CData/*0:0*/ core__DOT__exec_i__DOT__bpc_disable2;
        CData/*0:0*/ core__DOT__exec_i__DOT__adress_misaligned;
        CData/*0:0*/ core__DOT__exec_i__DOT__load_adress_misaligned_se;
        CData/*0:0*/ core__DOT__exec_i__DOT__store_adress_misaligned_se;
        CData/*0:0*/ core__DOT__exec_i__DOT__access_fault;
        CData/*0:0*/ core__DOT__exec_i__DOT__load_access_fault_se;
        CData/*0:0*/ core__DOT__exec_i__DOT__store_access_fault_se;
        CData/*0:0*/ core__DOT__exec_i__DOT__exception_se;
        CData/*0:0*/ core__DOT__exec_i__DOT__start_div;
        CData/*0:0*/ core__DOT__exec_i__DOT__done_div;
        CData/*0:0*/ core__DOT__exec_i__DOT__busy_div;
        CData/*0:0*/ core__DOT__exec_i__DOT__exe2mem__DOT__data_v;
        CData/*2:0*/ core__DOT__exec_i__DOT__divider_i__DOT__EP;
        CData/*2:0*/ core__DOT__exec_i__DOT__divider_i__DOT__EF;
        CData/*1:0*/ core__DOT__exec_i__DOT__divider_i__DOT__cmd_reg;
        CData/*5:0*/ core__DOT__exec_i__DOT__divider_i__DOT__shift_cpt_se;
        CData/*5:0*/ core__DOT__exec_i__DOT__divider_i__DOT__shift_cpt_reg;
        CData/*0:0*/ core__DOT__exec_i__DOT__divider_i__DOT__quotient_sign_reg;
        CData/*0:0*/ core__DOT__exec_i__DOT__divider_i__DOT__reminder_sign_reg;
        CData/*0:0*/ core__DOT__exec_i__DOT__divider_i__DOT__signed_inst;
        CData/*0:0*/ core__DOT__exec_i__DOT__divider_i__DOT__division;
    };
    struct {
        CData/*0:0*/ core__DOT__exec_i__DOT__divider_i__DOT__setup_regs;
        CData/*0:0*/ core__DOT__exec_i__DOT__divider_i__DOT__same;
        CData/*0:0*/ core__DOT__exec_i__DOT__divider_i__DOT__zero_div;
        CData/*0:0*/ core__DOT__exec_i__DOT__divider_i__DOT__running;
        CData/*0:0*/ core__DOT__x0_mult__DOT__signed_type;
        CData/*0:0*/ core__DOT__x0_mult__DOT__stall_sx0;
        CData/*0:0*/ core__DOT__x0_mult__DOT__x0x1__DOT__data_v;
        CData/*0:0*/ core__DOT__x1_mult__DOT__stall_sx1;
        CData/*0:0*/ core__DOT__x1_mult__DOT__x1x2_push;
        CData/*0:0*/ core__DOT__x1_mult__DOT__x1x2_full;
        CData/*0:0*/ core__DOT__x1_mult__DOT__x1x2__DOT__data_v;
        SData/*11:0*/ core__DOT__CSR_WADR_SM;
        SData/*11:0*/ core__DOT__dec_i__DOT__csr_radr;
        IData/*31:0*/ core__DOT__MEM_RES_RM;
        IData/*31:0*/ core__DOT__CSR_WDATA_SM;
        IData/*31:0*/ core__DOT__CSR_RDATA_SC;
        IData/*31:0*/ core__DOT__CSR_RDATA_RM;
        WData/*127:0*/ core__DOT__RES_RX1[4];
        WData/*96:0*/ core__DOT__ifetch_i__DOT__if2dec_din[4];
        IData/*31:0*/ core__DOT__ifetch_i__DOT__pred_branch_next_adr;
        IData/*31:0*/ core__DOT__ifetch_i__DOT__unnamedblk2__DOT__index;
        IData/*31:0*/ core__DOT__ifetch_i__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i;
        WData/*96:0*/ core__DOT__ifetch_i__DOT__if2dec__DOT__data[4];
        WData/*133:0*/ core__DOT__dec_i__DOT__dec2if_din[5];
        WData/*251:0*/ core__DOT__dec_i__DOT__dec2exe_data[8];
        IData/*31:0*/ core__DOT__dec_i__DOT__op1_csri_type_sd;
        IData/*31:0*/ core__DOT__dec_i__DOT__dec2exe_op1_sd;
        IData/*31:0*/ core__DOT__dec_i__DOT__dec2exe_op2_sd;
        IData/*31:0*/ core__DOT__dec_i__DOT__op1_u_type_sd;
        IData/*31:0*/ core__DOT__dec_i__DOT__op2_i_type_sd;
        IData/*31:0*/ core__DOT__dec_i__DOT__op2_s_type_sd;
        IData/*31:0*/ core__DOT__dec_i__DOT__rdata1_sd;
        IData/*31:0*/ core__DOT__dec_i__DOT__rdata2_sd;
        IData/*31:0*/ core__DOT__dec_i__DOT__offset_branch_sd;
        IData/*31:0*/ core__DOT__dec_i__DOT__offset_branch_j;
        IData/*31:0*/ core__DOT__dec_i__DOT__offset_branch_jalr;
        IData/*31:0*/ core__DOT__dec_i__DOT__jalr_offset;
        IData/*31:0*/ core__DOT__dec_i__DOT__offset_branch_b;
        IData/*31:0*/ core__DOT__dec_i__DOT__res;
        IData/*31:0*/ core__DOT__dec_i__DOT__res_compare;
        IData/*31:0*/ core__DOT__dec_i__DOT__pc;
        IData/*31:0*/ core__DOT__dec_i__DOT__branch_adr_sd;
        WData/*133:0*/ core__DOT__dec_i__DOT__dec2if__DOT__data[5];
        WData/*251:0*/ core__DOT__dec_i__DOT__dec2exe__DOT__data[8];
        WData/*199:0*/ core__DOT__exec_i__DOT__exe2mem_data[7];
        IData/*31:0*/ core__DOT__exec_i__DOT__op1;
        IData/*31:0*/ core__DOT__exec_i__DOT__op2;
        IData/*31:0*/ core__DOT__exec_i__DOT__alu_op2;
        IData/*31:0*/ core__DOT__exec_i__DOT__alu_res;
        IData/*31:0*/ core__DOT__exec_i__DOT__exe_res;
        IData/*31:0*/ core__DOT__exec_i__DOT__shifter_i__DOT__lshift16;
        IData/*31:0*/ core__DOT__exec_i__DOT__shifter_i__DOT__lshift8;
        IData/*31:0*/ core__DOT__exec_i__DOT__shifter_i__DOT__lshift4;
        IData/*31:0*/ core__DOT__exec_i__DOT__shifter_i__DOT__lshift2;
        IData/*31:0*/ core__DOT__exec_i__DOT__shifter_i__DOT__rshift16;
        IData/*31:0*/ core__DOT__exec_i__DOT__shifter_i__DOT__rshift8;
        IData/*31:0*/ core__DOT__exec_i__DOT__shifter_i__DOT__rshift4;
        IData/*31:0*/ core__DOT__exec_i__DOT__shifter_i__DOT__rshift2;
        WData/*199:0*/ core__DOT__exec_i__DOT__exe2mem__DOT__data[7];
        IData/*31:0*/ core__DOT__exec_i__DOT__divider_i__DOT__op1;
        IData/*31:0*/ core__DOT__exec_i__DOT__divider_i__DOT__op2;
        IData/*31:0*/ core__DOT__exec_i__DOT__divider_i__DOT__quotient_se;
        IData/*31:0*/ core__DOT__exec_i__DOT__divider_i__DOT__quotient_reg;
        IData/*31:0*/ core__DOT__exec_i__DOT__divider_i__DOT__quotient;
    };
    struct {
        IData/*31:0*/ core__DOT__csr_i__DOT__reg_mvendorid;
        IData/*31:0*/ core__DOT__csr_i__DOT__reg_marchid;
        IData/*31:0*/ core__DOT__csr_i__DOT__reg_mimpid;
        IData/*31:0*/ core__DOT__csr_i__DOT__reg_mstatus;
        IData/*31:0*/ core__DOT__csr_i__DOT__reg_misa;
        IData/*31:0*/ core__DOT__csr_i__DOT__reg_mie;
        IData/*31:0*/ core__DOT__csr_i__DOT__reg_mtvec;
        IData/*31:0*/ core__DOT__csr_i__DOT__reg_mstatush;
        IData/*31:0*/ core__DOT__csr_i__DOT__reg_mepc;
        IData/*31:0*/ core__DOT__csr_i__DOT__reg_mcause;
        IData/*31:0*/ core__DOT__csr_i__DOT__reg_mtval;
        IData/*31:0*/ core__DOT__csr_i__DOT__reg_mip;
        IData/*31:0*/ core__DOT__csr_i__DOT__reg_mscratch;
        IData/*31:0*/ core__DOT__x0_mult__DOT__op1;
        IData/*31:0*/ core__DOT__x0_mult__DOT__op2;
        WData/*321:0*/ core__DOT__x0_mult__DOT__x0x1_din[11];
        WData/*321:0*/ core__DOT__x0_mult__DOT__x0x1__DOT__data[11];
        WData/*129:0*/ core__DOT__x1_mult__DOT__x1x2_din[5];
        WData/*129:0*/ core__DOT__x1_mult__DOT__x1x2__DOT__data[5];
        QData/*63:0*/ core__DOT__exec_i__DOT__divider_i__DOT__divisor_se;
        QData/*63:0*/ core__DOT__exec_i__DOT__divider_i__DOT__reminder_se;
        QData/*63:0*/ core__DOT__exec_i__DOT__divider_i__DOT__divisor_reg;
        QData/*63:0*/ core__DOT__exec_i__DOT__divider_i__DOT__reminder_reg;
        QData/*63:0*/ core__DOT__exec_i__DOT__divider_i__DOT__divisor_setup;
        QData/*63:0*/ core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        QData/*63:0*/ core__DOT__x0_mult__DOT__csa2_6__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__csa2_6__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__csa3_4__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__csa3_4__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk1__BRA__0__KET____DOT__csa1__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk1__BRA__0__KET____DOT__csa1__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk1__BRA__1__KET____DOT__csa1__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk1__BRA__1__KET____DOT__csa1__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk1__BRA__2__KET____DOT__csa1__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk1__BRA__2__KET____DOT__csa1__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk1__BRA__3__KET____DOT__csa1__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk1__BRA__3__KET____DOT__csa1__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk1__BRA__4__KET____DOT__csa1__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk1__BRA__4__KET____DOT__csa1__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk1__BRA__5__KET____DOT__csa1__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk1__BRA__5__KET____DOT__csa1__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk1__BRA__6__KET____DOT__csa1__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk1__BRA__6__KET____DOT__csa1__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk1__BRA__7__KET____DOT__csa1__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk1__BRA__7__KET____DOT__csa1__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk1__BRA__8__KET____DOT__csa1__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk1__BRA__8__KET____DOT__csa1__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk1__BRA__9__KET____DOT__csa1__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk1__BRA__9__KET____DOT__csa1__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk2__BRA__0__KET____DOT__csa2__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk2__BRA__0__KET____DOT__csa2__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk2__BRA__1__KET____DOT__csa2__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk2__BRA__1__KET____DOT__csa2__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk2__BRA__2__KET____DOT__csa2__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk2__BRA__2__KET____DOT__csa2__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk2__BRA__3__KET____DOT__csa2__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk2__BRA__3__KET____DOT__csa2__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk2__BRA__4__KET____DOT__csa2__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk2__BRA__4__KET____DOT__csa2__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk2__BRA__5__KET____DOT__csa2__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__genblk2__BRA__5__KET____DOT__csa2__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__csa_instance__BRA__0__KET____DOT__csa3__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__csa_instance__BRA__0__KET____DOT__csa3__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__csa_instance__BRA__1__KET____DOT__csa3__DOT__AxB;
    };
    struct {
        QData/*63:0*/ core__DOT__x0_mult__DOT__csa_instance__BRA__1__KET____DOT__csa3__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__csa_instance__BRA__2__KET____DOT__csa3__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__csa_instance__BRA__2__KET____DOT__csa3__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__csa_instance__BRA__3__KET____DOT__csa3__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__csa_instance__BRA__3__KET____DOT__csa3__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__stage4__BRA__0__KET____DOT__csa4__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__stage4__BRA__0__KET____DOT__csa4__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__stage4__BRA__1__KET____DOT__csa4__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__stage4__BRA__1__KET____DOT__csa4__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__stage4__BRA__2__KET____DOT__csa4__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__stage4__BRA__2__KET____DOT__csa4__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__stage5__BRA__0__KET____DOT__csa5__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__stage5__BRA__0__KET____DOT__csa5__DOT__shf;
        QData/*63:0*/ core__DOT__x0_mult__DOT__stage5__BRA__1__KET____DOT__csa5__DOT__AxB;
        QData/*63:0*/ core__DOT__x0_mult__DOT__stage5__BRA__1__KET____DOT__csa5__DOT__shf;
        QData/*63:0*/ core__DOT__x1_mult__DOT__csa6__DOT__AxB;
        QData/*63:0*/ core__DOT__x1_mult__DOT__csa6__DOT__shf;
        QData/*63:0*/ core__DOT__x1_mult__DOT__csa7__DOT__AxB;
        QData/*63:0*/ core__DOT__x1_mult__DOT__csa7__DOT__shf;
        QData/*63:0*/ core__DOT__x1_mult__DOT__csa8__DOT__AxB;
        QData/*63:0*/ core__DOT__x1_mult__DOT__csa8__DOT__shf;
        QData/*63:0*/ core__DOT__x2_mult__DOT__res;
        IData/*31:0*/ core__DOT__ifetch_i__DOT__branch_adr_reg[4];
        IData/*31:0*/ core__DOT__ifetch_i__DOT__predicted_adr_reg[4];
        CData/*1:0*/ core__DOT__ifetch_i__DOT__pred_state_reg[4];
        IData/*31:0*/ core__DOT__reg_i__DOT__registers[33];
        QData/*63:0*/ core__DOT__x0_mult__DOT__product[32];
        QData/*63:0*/ core__DOT__x0_mult__DOT__product_s1[20];
        QData/*63:0*/ core__DOT__x0_mult__DOT__product_s2[14];
        QData/*63:0*/ core__DOT__x0_mult__DOT__product_s3[10];
        QData/*63:0*/ core__DOT__x0_mult__DOT__product_s4[6];
        QData/*63:0*/ core__DOT__x0_mult__DOT__product_s5[4];
        QData/*63:0*/ core__DOT__x1_mult__DOT__x0_data[6];
        QData/*63:0*/ core__DOT__x1_mult__DOT__product_s6[2];
        QData/*63:0*/ core__DOT__x1_mult__DOT__product_s7[2];
        QData/*63:0*/ core__DOT__x1_mult__DOT__product_s8[2];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vcellinp__core__reset_n;
    CData/*0:0*/ __Vcellinp__core__clk;
    CData/*0:0*/ __Vcellinp__core__IC_STALL_SI;
    CData/*3:0*/ __Vcellout__core__byt_sel;
    CData/*0:0*/ __Vcellout__core__MCACHE_LOAD_SM;
    CData/*0:0*/ __Vcellout__core__MCACHE_STORE_SM;
    CData/*0:0*/ __Vcellout__core__MCACHE_ADR_VALID_SM;
    CData/*2:0*/ __Vtableidx1;
    CData/*0:0*/ __Vdly__core__DOT__ifetch_i__DOT__if2dec__DOT__data_v;
    CData/*0:0*/ __Vdly__core__DOT__dec_i__DOT__dec2if__DOT__data_v;
    CData/*0:0*/ __Vdly__core__DOT__dec_i__DOT__dec2exe__DOT__data_v;
    CData/*0:0*/ __VinpClk__TOP____Vcellinp__core__reset_n;
    CData/*0:0*/ __Vclklast__TOP____Vcellinp__core__clk;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP____Vcellinp__core__reset_n;
    CData/*0:0*/ __Vchglast__TOP____Vcellinp__core__reset_n;
    IData/*31:0*/ __Vcellinp__core__PC_INIT;
    IData/*31:0*/ __Vcellinp__core__IC_INST_SI;
    IData/*31:0*/ __Vcellout__core__MCACHE_ADR_SM;
    IData/*31:0*/ __Vcellout__core__MCACHE_DATA_SM;
    IData/*31:0*/ core__DOT__reg_i__DOT____Vlvbound1;
    static CData/*0:0*/ __Vtable1_core__DOT__exec_i__DOT__divider_i__DOT__setup_regs[8];
    static CData/*0:0*/ __Vtable1_core__DOT__exec_i__DOT__divider_i__DOT__same[8];
    static CData/*0:0*/ __Vtable1_core__DOT__exec_i__DOT__divider_i__DOT__zero_div[8];
    static CData/*0:0*/ __Vtable1_core__DOT__exec_i__DOT__divider_i__DOT__running[8];
    static CData/*0:0*/ __Vtable1_core__DOT__exec_i__DOT__done_div[8];
    static CData/*0:0*/ __Vtable1_core__DOT__exec_i__DOT__busy_div[8];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vcore__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vcore);  ///< Copying not allowed
  public:
    SC_CTOR(Vcore);
    virtual ~Vcore();
    
    // API METHODS
  private:
    void eval();
  public:
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vcore__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vcore__Syms* symsp, bool first);
  private:
    static QData _change_request(Vcore__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__10(Vcore__Syms* __restrict vlSymsp);
    static void _combo__TOP__3(Vcore__Syms* __restrict vlSymsp);
    static void _combo__TOP__7(Vcore__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vcore__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vcore__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vcore__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__2(Vcore__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__5(Vcore__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vcore__Syms* __restrict vlSymsp);
    static void _sequent__TOP__8(Vcore__Syms* __restrict vlSymsp);
    static void _sequent__TOP__9(Vcore__Syms* __restrict vlSymsp);
    static void _settle__TOP__1(Vcore__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__4(Vcore__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
