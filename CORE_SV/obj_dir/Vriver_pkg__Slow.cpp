// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vriver_pkg.h for the primary calling header

#include "Vriver_pkg.h"
#include "Vriver_pkg__Syms.h"

//==========
CData/*0:0*/ Vriver_pkg::__Vtable1_exe__DOT__divider_i__DOT__setup_regs[8];
CData/*0:0*/ Vriver_pkg::__Vtable1_exe__DOT__divider_i__DOT__same[8];
CData/*0:0*/ Vriver_pkg::__Vtable1_exe__DOT__divider_i__DOT__zero_div[8];
CData/*0:0*/ Vriver_pkg::__Vtable1_exe__DOT__divider_i__DOT__running[8];
CData/*0:0*/ Vriver_pkg::__Vtable1_exe__DOT__done_div[8];
CData/*0:0*/ Vriver_pkg::__Vtable1_exe__DOT__busy_div[8];

VL_SC_CTOR_IMP(Vriver_pkg) {
    Vriver_pkg__Syms* __restrict vlSymsp = __VlSymsp = new Vriver_pkg__Syms(this, name());
    Vriver_pkg* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Sensitivities on all clocks and combo inputs
    SC_METHOD(eval);
    sensitive << csr__02Eclk;
    sensitive << csr__02Ereset_n;
    sensitive << csr__02ECSR_WADR_SM;
    sensitive << csr__02ECSR_WDATA_SM;
    sensitive << csr__02ECSR_ENABLE_SM;
    sensitive << csr__02EEXCEPTION_SM;
    sensitive << csr__02EMSTATUS_WDATA_SM;
    sensitive << csr__02EMIP_WDATA_SM;
    sensitive << csr__02EMEPC_WDATA_SM;
    sensitive << csr__02EMCAUSE_WDATA_SM;
    sensitive << csr__02EMTVAL_WDATA_SM;
    sensitive << csr__02ECSR_RADR_SD;
    sensitive << register_file__02Eclk;
    sensitive << register_file__02Ereset_n;
    sensitive << register_file__02EPC_INIT;
    sensitive << RADR1_SD;
    sensitive << RADR2_SD;
    sensitive << WDATA_SW;
    sensitive << WADR_SW;
    sensitive << WENABLE_SW;
    sensitive << register_file__02EWRITE_PC_SD;
    sensitive << register_file__02EWRITE_PC_ENABLE_SD;
    sensitive << wbk__02EMEM_RES_RM;
    sensitive << wbk__02EMEM_DEST_RM;
    sensitive << wbk__02EWB_RM;
    sensitive << wbk__02ECSR_RDATA_RM;
    sensitive << wbk__02ECSR_WENABLE_RM;
    sensitive << wbk__02EMEM2WBK_EMPTY_SM;
    sensitive << wbk__02EMULT_INST_RM;
    sensitive << wbk__02ERES_RX2;
    sensitive << x2_multiplier__02Eclk;
    sensitive << x2_multiplier__02Ereset_n;
    sensitive << x2_multiplier__02ERES_RX1;
    sensitive << x2_multiplier__02ESELECT_MSB_RX1;
    sensitive << x2_multiplier__02EX1X2_EMPTY_SX1;
    sensitive << x1_multiplier__02Eclk;
    sensitive << x1_multiplier__02Ereset_n;
    sensitive << x1_multiplier__02ERES_RX0;
    sensitive << x1_multiplier__02ESELECT_MSB_RX0;
    sensitive << x1_multiplier__02ESIGNED_RES_RX0;
    sensitive << x1_multiplier__02EX0X1_EMPTY_SX0;
    sensitive << x1_multiplier__02EX1X2_POP_SX2;
    sensitive << mem__02Eclk;
    sensitive << mem__02Ereset_n;
    sensitive << mem__02EMCACHE_RESULT_SM;
    sensitive << mem__02EMCACHE_STALL_SM;
    sensitive << mem__02ERES_RE;
    sensitive << mem__02EMEM_DATA_RE;
    sensitive << mem__02EDEST_RE;
    sensitive << mem__02EMEM_SIZE_RE;
    sensitive << mem__02EWB_RE;
    sensitive << SIGN_EXTEND_RE;
    sensitive << LOAD_RE;
    sensitive << STORE_RE;
    sensitive << mem__02EPC_EXE2MEM_RE;
    sensitive << mem__02EMULT_INST_RE;
    sensitive << mem__02EEXE2MEM_EMPTY_SE;
    sensitive << mem__02EMEM2WBK_POP_SW;
    sensitive << mem__02ECSR_WENABLE_RE;
    sensitive << mem__02ECSR_WADR_RE;
    sensitive << mem__02ECSR_RDATA_RE;
    { int __Vi0=0; for (; __Vi0<=31; ++__Vi0) {
            sensitive << mem__02EMEPC_SC[__Vi0];
    }}
    { int __Vi0=0; for (; __Vi0<=31; ++__Vi0) {
            sensitive << mem__02EMSTATUS_RC[__Vi0];
    }}
    sensitive << mem__02EEXCEPTION_RE;
    sensitive << mem__02ELOAD_ADRESS_MISALIGNED_RE;
    sensitive << mem__02ELOAD_ACCESS_FAULT_RE;
    sensitive << mem__02EILLEGAL_INSTRUCTION_RE;
    sensitive << INSTRUCTION_ADRESS_MISALIGNED_RE;
    sensitive << mem__02EINSTRUCTION_ACCESS_FAULT_RE;
    sensitive << mem__02ESTORE_ADRESS_MISALIGNED_RE;
    sensitive << mem__02ESTORE_ACCESS_FAULT_RE;
    sensitive << mem__02EENV_CALL_U_MODE_RE;
    sensitive << mem__02EENV_CALL_S_MODE_RE;
    sensitive << mem__02EENV_CALL_M_MODE_RE;
    sensitive << mem__02EENV_CALL_WRONG_MODE_RE;
    sensitive << mem__02EMRET_RE;
    sensitive << mem__02EEBREAK_RE;
    sensitive << mem__02EPC_BRANCH_VALUE_RE;
    sensitive << BUS_ERROR_SX;
    sensitive << dec__02Eclk;
    sensitive << dec__02Ereset_n;
    sensitive << dec__02ERDATA1_SR;
    sensitive << dec__02ERDATA2_SR;
    sensitive << dec__02EREAD_PC_SR;
    sensitive << dec__02EDEC2IF_POP_SI;
    sensitive << dec__02EINSTR_RI;
    sensitive << dec__02EPC_IF2DEC_RI;
    sensitive << dec__02EIF2DEC_EMPTY_SI;
    sensitive << dec__02EPRED_ADR_RI;
    sensitive << dec__02EPRED_TAKEN_RI;
    sensitive << dec__02EDEC2EXE_POP_SE;
    sensitive << dec__02EMULT_INST_RE;
    sensitive << dec__02EMULT_INST_RM;
    sensitive << BP_DEST_RE;
    sensitive << BP_EXE_RES_RE;
    sensitive << BP_MEM_LOAD_RE;
    sensitive << BP_EXE2MEM_EMPTY_SE;
    sensitive << dec__02EBP_MEM2WBK_EMPTY_SM;
    sensitive << BP_DEST_RM;
    sensitive << BP_MEM_RES_RM;
    sensitive << dec__02ECSR_WENABLE_RE;
    sensitive << dec__02ECSR_WENABLE_RM;
    sensitive << dec__02ECSR_RDATA_RE;
    sensitive << dec__02ECSR_RDATA_RM;
    sensitive << dec__02ECSR_RDATA_SC;
    sensitive << dec__02ECURRENT_MODE_SM;
    sensitive << dec__02EEXCEPTION_SM;
    sensitive << dec__02EMTVEC_VALUE_RC;
    sensitive << dec__02EMCAUSE_WDATA_SM;
    sensitive << dec__02ERETURN_ADRESS_SM;
    sensitive << dec__02EMRET_SM;
    sensitive << x0_multiplier__02Eclk;
    sensitive << x0_multiplier__02Ereset_n;
    sensitive << x0_multiplier__02EOP1_SE;
    sensitive << x0_multiplier__02EOP2_SE;
    sensitive << MULT_CMD_RD;
    sensitive << x0_multiplier__02EX0X1_POP_SX1;
    sensitive << DEC2X0_EMPTY_SD;
    sensitive << exe__02Eclk;
    sensitive << exe__02Ereset_n;
    sensitive << exe__02EOP1_RD;
    sensitive << exe__02EOP2_RD;
    sensitive << RADR1_RD;
    sensitive << RADR2_RD;
    sensitive << exe__02EMEM_DATA_RD;
    sensitive << exe__02EDEST_RD;
    sensitive << exe__02ECMD_RD;
    sensitive << exe__02EMEM_SIZE_RD;
    sensitive << exe__02ENEG_OP2_RD;
    sensitive << exe__02EWB_RD;
    sensitive << exe__02EMEM_SIGN_EXTEND_RD;
    sensitive << exe__02ESELECT_OPERATION_RD;
    sensitive << exe__02EMEM_LOAD_RD;
    sensitive << exe__02EMEM_STORE_RD;
    sensitive << exe__02EEXE2MEM_POP_SM;
    sensitive << exe__02EDEC2EXE_EMPTY_SD;
    sensitive << exe__02ESLT_RD;
    sensitive << exe__02ESLTU_RD;
    sensitive << exe__02EPC_DEC2EXE_RD;
    sensitive << exe__02EBLOCK_BP_RD;
    sensitive << exe__02EMEM_DEST_RM;
    sensitive << exe__02EMEM_RES_RM;
    sensitive << exe__02ECSR_WENABLE_RM;
    sensitive << exe__02ECSR_RDATA_RM;
    sensitive << exe__02ECSR_WENABLE_RD;
    sensitive << exe__02ECSR_WADR_RD;
    sensitive << exe__02ECSR_RDATA_RD;
    sensitive << exe__02EMULT_INST_RM;
    sensitive << exe__02EMULT_INST_RD;
    sensitive << exe__02EEXCEPTION_SM;
    sensitive << exe__02EEXCEPTION_RD;
    sensitive << exe__02ECURRENT_MODE_SM;
    sensitive << exe__02EPC_BRANCH_VALUE_RD;
    sensitive << exe__02EILLEGAL_INSTRUCTION_RD;
    sensitive << exe__02EADRESS_MISALIGNED_RD;
    sensitive << exe__02EINSTRUCTION_ACCESS_FAULT_RD;
    sensitive << exe__02EENV_CALL_U_MODE_RD;
    sensitive << exe__02EENV_CALL_S_MODE_RD;
    sensitive << exe__02EENV_CALL_M_MODE_RD;
    sensitive << exe__02EENV_CALL_WRONG_MODE_RD;
    sensitive << exe__02EMRET_RD;
    sensitive << exe__02EEBREAK_RD;
    sensitive << ifetch__02Eclk;
    sensitive << ifetch__02Ereset_n;
    sensitive << ifetch__02EIC_INST_SI;
    sensitive << ifetch__02EIC_STALL_SI;
    sensitive << ifetch__02EDEC2IF_EMPTY_SD;
    sensitive << ifetch__02EIF2DEC_FLUSH_SD;
    sensitive << ifetch__02EIF2DEC_POP_SD;
    sensitive << ifetch__02EPC_RD;
    sensitive << ifetch__02EEXCEPTION_SM;
    sensitive << ifetch__02EPRED_FAILED_RD;
    sensitive << ifetch__02EPRED_SUCCESS_RD;
    sensitive << ifetch__02EBRANCH_INST_RD;
    sensitive << ifetch__02EBRANCH_INST_ADR_RD;
    sensitive << ifetch__02EADR_TO_BRANCH_RD;
    sensitive << ifetch__02EPRED_ADR_SD;
    sensitive << ifetch__02EPRED_TAKEN_SD;
    
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vriver_pkg::__Vconfigure(Vriver_pkg__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vriver_pkg::~Vriver_pkg() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vriver_pkg::_initial__TOP__1(Vriver_pkg__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriver_pkg::_initial__TOP__1\n"); );
    Vriver_pkg* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ifetch__DOT__pred_branch_next_adr = 0x22222200U;
    vlTOPp->dec__DOT__pred_failed_sd = 0U;
    vlTOPp->x0_multiplier__DOT__stage5__BRA__0__KET____DOT__csa5__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__stage5__BRA__1__KET____DOT__csa5__DOT__shf = 0ULL;
    vlTOPp->exe__DOT__divider_i__DOT__cmd_reg = 0U;
    vlTOPp->exe__DOT__divider_i__DOT__quotient = 0U;
    vlTOPp->exe__DOT__divider_i__DOT__reminder_reg = 0ULL;
    vlTOPp->exe__DOT__exception_se = 0U;
    vlTOPp->dec__DOT__pc = 0U;
    vlTOPp->exe__DOT__load_adress_misaligned_se = 0U;
    vlTOPp->exe__DOT__store_adress_misaligned_se = 0U;
    vlTOPp->exe__DOT__load_access_fault_se = 0U;
    vlTOPp->exe__DOT__store_access_fault_se = 0U;
    vlTOPp->x0_multiplier__DOT__stage4__BRA__0__KET____DOT__csa4__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__stage4__BRA__1__KET____DOT__csa4__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__stage4__BRA__2__KET____DOT__csa4__DOT__shf = 0ULL;
    vlTOPp->exe__DOT__adress_misaligned = 0U;
    vlTOPp->exe__DOT__access_fault = 0U;
    vlTOPp->x0_multiplier__DOT__csa3_4__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__csa_instance__BRA__0__KET____DOT__csa3__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__csa_instance__BRA__1__KET____DOT__csa3__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__csa_instance__BRA__2__KET____DOT__csa3__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__csa_instance__BRA__3__KET____DOT__csa3__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__csa2_6__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__0__KET____DOT__csa2__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__1__KET____DOT__csa2__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__2__KET____DOT__csa2__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__3__KET____DOT__csa2__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__4__KET____DOT__csa2__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__5__KET____DOT__csa2__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__0__KET____DOT__csa1__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__1__KET____DOT__csa1__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__2__KET____DOT__csa1__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__3__KET____DOT__csa1__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__4__KET____DOT__csa1__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__5__KET____DOT__csa1__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__6__KET____DOT__csa1__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__7__KET____DOT__csa1__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__8__KET____DOT__csa1__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__9__KET____DOT__csa1__DOT__shf = 0ULL;
    vlTOPp->exe__DOT__divider_i__DOT__reminder_se = 0ULL;
    vlTOPp->exe__DOT__divider_i__DOT__shift_cpt_reg = 0U;
    vlTOPp->x0_multiplier__DOT__x0x1__DOT__data_v = 0U;
    vlTOPp->exe__DOT__exe2mem__DOT__data_v = 0U;
    vlTOPp->mem__DOT__mem2wbk__DOT__data_v = 0U;
    vlTOPp->ifetch__DOT__if2dec__DOT__data_v = 0U;
    vlTOPp->x1_multiplier__DOT__x1x2__DOT__data_v = 0U;
    vlTOPp->dec__DOT__dec2if__DOT__data_v = 0U;
    vlTOPp->dec__DOT__dec2exe__DOT__data_v = 0U;
}

void Vriver_pkg::_settle__TOP__2(Vriver_pkg__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriver_pkg::_settle__TOP__2\n"); );
    Vriver_pkg* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*319:0*/ __Vtemp3[10];
    WData/*127:0*/ __Vtemp5[4];
    WData/*127:0*/ __Vtemp8[4];
    WData/*127:0*/ __Vtemp9[4];
    WData/*95:0*/ __Vtemp20[3];
    WData/*191:0*/ __Vtemp25[6];
    // Body
    VL_ASSIGN_SII(32,vlTOPp->mem__02EMIP_WDATA_SM, 0U);
    VL_ASSIGN_SII(1,vlTOPp->ifetch__02EEXCEPTION_RI, 0U);
    VL_ASSIGN_SII(32,vlTOPp->DEBUG_PC_READ, vlTOPp->__Vcellout__core__DEBUG_PC_READ);
    VL_ASSIGN_SII(1,vlTOPp->core__02EADR_VALID_SI, vlTOPp->__Vcellout__core__core__02EADR_VALID_SI);
    VL_ASSIGN_SII(32,vlTOPp->core__02EADR_SI, vlTOPp->__Vcellout__core__core__02EADR_SI);
    VL_ASSIGN_SII(4,vlTOPp->core__02Ebyt_sel, vlTOPp->__Vcellout__core__core__02Ebyt_sel);
    VL_ASSIGN_SII(32,vlTOPp->core__02EMCACHE_ADR_SM, vlTOPp->__Vcellout__core__core__02EMCACHE_ADR_SM);
    VL_ASSIGN_SII(32,vlTOPp->core__02EMCACHE_DATA_SM, vlTOPp->__Vcellout__core__core__02EMCACHE_DATA_SM);
    VL_ASSIGN_SII(1,vlTOPp->core__02EMCACHE_LOAD_SM, vlTOPp->__Vcellout__core__core__02EMCACHE_LOAD_SM);
    VL_ASSIGN_SII(1,vlTOPp->core__02EMCACHE_STORE_SM, vlTOPp->__Vcellout__core__core__02EMCACHE_STORE_SM);
    VL_ASSIGN_SII(1,vlTOPp->core__02EMCACHE_ADR_VALID_SM, vlTOPp->__Vcellout__core__core__02EMCACHE_ADR_VALID_SM);
    vlTOPp->exe__DOT__exe2mem_x[0U] = 0U;
    vlTOPp->exe__DOT__exe2mem_x[1U] = 0U;
    vlTOPp->exe__DOT__exe2mem_x[2U] = (0xfffff000U 
                                       & vlTOPp->exe__DOT__exe2mem_x[2U]);
    vlTOPp->exe__DOT__exe2mem_x[3U] = (0xfffU & vlTOPp->exe__DOT__exe2mem_x[3U]);
    vlTOPp->exe__DOT__exe2mem_x[4U] = 0U;
    vlTOPp->exe__DOT__exe2mem_x[5U] = 0U;
    vlTOPp->exe__DOT__exe2mem_x[6U] = 0U;
    vlTOPp->exe__DOT__divider_i__DOT__divisor_setup 
        = (0x7fffffffffffffffULL & vlTOPp->exe__DOT__divider_i__DOT__divisor_setup);
    vlTOPp->exe__DOT__divider_i__DOT__divisor_setup 
        = (0xffffffff80000000ULL & vlTOPp->exe__DOT__divider_i__DOT__divisor_setup);
    vlTOPp->dec__DOT__mtvec_value = (0xfffffffcU & vlTOPp->dec__DOT__mtvec_value);
    VL_ASSIGN_ISI(6,vlTOPp->__Vcellinp__wbk__wbk__02EMEM_DEST_RM, vlTOPp->wbk__02EMEM_DEST_RM);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__x2_multiplier__x2_multiplier__02EX1X2_EMPTY_SX1, vlTOPp->x2_multiplier__02EX1X2_EMPTY_SX1);
    VL_ASSIGN_ISI(12,vlTOPp->__Vcellinp__mem__mem__02ECSR_WADR_RE, vlTOPp->mem__02ECSR_WADR_RE);
    VL_ASSIGN_ISI(6,vlTOPp->__Vcellinp__register_file__RADR2_SD, vlTOPp->RADR2_SD);
    VL_ASSIGN_ISI(6,vlTOPp->__Vcellinp__register_file__RADR1_SD, vlTOPp->RADR1_SD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__wbk__wbk__02EWB_RM, vlTOPp->wbk__02EWB_RM);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__x2_multiplier__x2_multiplier__02ESELECT_MSB_RX1, vlTOPp->x2_multiplier__02ESELECT_MSB_RX1);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__x0_multiplier__DEC2X0_EMPTY_SD, vlTOPp->DEC2X0_EMPTY_SD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02EEXCEPTION_SM, vlTOPp->exe__02EEXCEPTION_SM);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__wbk__wbk__02ERES_RX2, vlTOPp->wbk__02ERES_RX2);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__wbk__wbk__02EMULT_INST_RM, vlTOPp->wbk__02EMULT_INST_RM);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__wbk__wbk__02ECSR_WENABLE_RM, vlTOPp->wbk__02ECSR_WENABLE_RM);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__wbk__wbk__02ECSR_RDATA_RM, vlTOPp->wbk__02ECSR_RDATA_RM);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__wbk__wbk__02EMEM_RES_RM, vlTOPp->wbk__02EMEM_RES_RM);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__wbk__wbk__02EMEM2WBK_EMPTY_SM, vlTOPp->wbk__02EMEM2WBK_EMPTY_SM);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMRET_RE, vlTOPp->mem__02EMRET_RE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__STORE_RE, vlTOPp->STORE_RE);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__ifetch__ifetch__02EIC_INST_SI, vlTOPp->ifetch__02EIC_INST_SI);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__mem__mem__02EPC_BRANCH_VALUE_RE, vlTOPp->mem__02EPC_BRANCH_VALUE_RE);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__mem__mem__02ECSR_RDATA_RE, vlTOPp->mem__02ECSR_RDATA_RE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMULT_INST_RE, vlTOPp->mem__02EMULT_INST_RE);
    VL_ASSIGN_ISI(6,vlTOPp->__Vcellinp__mem__mem__02EDEST_RE, vlTOPp->mem__02EDEST_RE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__x1_multiplier__x1_multiplier__02ESIGNED_RES_RX0, vlTOPp->x1_multiplier__02ESIGNED_RES_RX0);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__x1_multiplier__x1_multiplier__02ESELECT_MSB_RX0, vlTOPp->x1_multiplier__02ESELECT_MSB_RX0);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__mem__mem__02EPC_EXE2MEM_RE, vlTOPp->mem__02EPC_EXE2MEM_RE);
    VL_ASSIGN_ISI(12,vlTOPp->__Vcellinp__csr__csr__02ECSR_RADR_SD, vlTOPp->csr__02ECSR_RADR_SD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__ifetch__ifetch__02EIF2DEC_FLUSH_SD, vlTOPp->ifetch__02EIF2DEC_FLUSH_SD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02ECSR_WENABLE_RE, vlTOPp->mem__02ECSR_WENABLE_RE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__ifetch__ifetch__02EPRED_TAKEN_SD, vlTOPp->ifetch__02EPRED_TAKEN_SD);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__ifetch__ifetch__02EPRED_ADR_SD, vlTOPp->ifetch__02EPRED_ADR_SD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMCACHE_STALL_SM, vlTOPp->mem__02EMCACHE_STALL_SM);
    VL_ASSIGN_ISI(2,vlTOPp->__Vcellinp__x0_multiplier__MULT_CMD_RD, vlTOPp->MULT_CMD_RD);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__x0_multiplier__x0_multiplier__02EOP2_SE, vlTOPp->x0_multiplier__02EOP2_SE);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__x0_multiplier__x0_multiplier__02EOP1_SE, vlTOPp->x0_multiplier__02EOP1_SE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__ifetch__ifetch__02EEXCEPTION_SM, vlTOPp->ifetch__02EEXCEPTION_SM);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__ifetch__ifetch__02EIC_STALL_SI, vlTOPp->ifetch__02EIC_STALL_SI);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EEXE2MEM_EMPTY_SE, vlTOPp->mem__02EEXE2MEM_EMPTY_SE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0x1fU], vlTOPp->mem__02EMEPC_SC[0x1fU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0x1eU], vlTOPp->mem__02EMEPC_SC[0x1eU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0x1dU], vlTOPp->mem__02EMEPC_SC[0x1dU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0x1cU], vlTOPp->mem__02EMEPC_SC[0x1cU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0x1bU], vlTOPp->mem__02EMEPC_SC[0x1bU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0x1aU], vlTOPp->mem__02EMEPC_SC[0x1aU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0x19U], vlTOPp->mem__02EMEPC_SC[0x19U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0x18U], vlTOPp->mem__02EMEPC_SC[0x18U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0x17U], vlTOPp->mem__02EMEPC_SC[0x17U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0x16U], vlTOPp->mem__02EMEPC_SC[0x16U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0x15U], vlTOPp->mem__02EMEPC_SC[0x15U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0x14U], vlTOPp->mem__02EMEPC_SC[0x14U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0x13U], vlTOPp->mem__02EMEPC_SC[0x13U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0x12U], vlTOPp->mem__02EMEPC_SC[0x12U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0x11U], vlTOPp->mem__02EMEPC_SC[0x11U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0x10U], vlTOPp->mem__02EMEPC_SC[0x10U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0xfU], vlTOPp->mem__02EMEPC_SC[0xfU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0xeU], vlTOPp->mem__02EMEPC_SC[0xeU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0xdU], vlTOPp->mem__02EMEPC_SC[0xdU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0xcU], vlTOPp->mem__02EMEPC_SC[0xcU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0xbU], vlTOPp->mem__02EMEPC_SC[0xbU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0xaU], vlTOPp->mem__02EMEPC_SC[0xaU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [9U], vlTOPp->mem__02EMEPC_SC[9U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [8U], vlTOPp->mem__02EMEPC_SC[8U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [7U], vlTOPp->mem__02EMEPC_SC[7U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [6U], vlTOPp->mem__02EMEPC_SC[6U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [5U], vlTOPp->mem__02EMEPC_SC[5U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [4U], vlTOPp->mem__02EMEPC_SC[4U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [3U], vlTOPp->mem__02EMEPC_SC[3U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [2U], vlTOPp->mem__02EMEPC_SC[2U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [1U], vlTOPp->mem__02EMEPC_SC[1U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC
                  [0U], vlTOPp->mem__02EMEPC_SC[0U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__ifetch__ifetch__02EDEC2IF_EMPTY_SD, vlTOPp->ifetch__02EDEC2IF_EMPTY_SD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02EDEC2EXE_EMPTY_SD, vlTOPp->exe__02EDEC2EXE_EMPTY_SD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EWB_RE, vlTOPp->mem__02EWB_RE);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__mem__mem__02EMEM_DATA_RE, vlTOPp->mem__02EMEM_DATA_RE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0x1fU], vlTOPp->mem__02EMSTATUS_RC
                  [0x1fU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0x1eU], vlTOPp->mem__02EMSTATUS_RC
                  [0x1eU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0x1dU], vlTOPp->mem__02EMSTATUS_RC
                  [0x1dU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0x1cU], vlTOPp->mem__02EMSTATUS_RC
                  [0x1cU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0x1bU], vlTOPp->mem__02EMSTATUS_RC
                  [0x1bU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0x1aU], vlTOPp->mem__02EMSTATUS_RC
                  [0x1aU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0x19U], vlTOPp->mem__02EMSTATUS_RC
                  [0x19U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0x18U], vlTOPp->mem__02EMSTATUS_RC
                  [0x18U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0x17U], vlTOPp->mem__02EMSTATUS_RC
                  [0x17U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0x16U], vlTOPp->mem__02EMSTATUS_RC
                  [0x16U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0x15U], vlTOPp->mem__02EMSTATUS_RC
                  [0x15U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0x14U], vlTOPp->mem__02EMSTATUS_RC
                  [0x14U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0x13U], vlTOPp->mem__02EMSTATUS_RC
                  [0x13U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0x12U], vlTOPp->mem__02EMSTATUS_RC
                  [0x12U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0x11U], vlTOPp->mem__02EMSTATUS_RC
                  [0x11U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0x10U], vlTOPp->mem__02EMSTATUS_RC
                  [0x10U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0xfU], vlTOPp->mem__02EMSTATUS_RC
                  [0xfU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0xeU], vlTOPp->mem__02EMSTATUS_RC
                  [0xeU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0xdU], vlTOPp->mem__02EMSTATUS_RC
                  [0xdU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0xcU], vlTOPp->mem__02EMSTATUS_RC
                  [0xcU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0xbU], vlTOPp->mem__02EMSTATUS_RC
                  [0xbU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0xaU], vlTOPp->mem__02EMSTATUS_RC
                  [0xaU]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [9U], vlTOPp->mem__02EMSTATUS_RC[9U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [8U], vlTOPp->mem__02EMSTATUS_RC[8U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [7U], vlTOPp->mem__02EMSTATUS_RC[7U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [6U], vlTOPp->mem__02EMSTATUS_RC[6U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [5U], vlTOPp->mem__02EMSTATUS_RC[5U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [4U], vlTOPp->mem__02EMSTATUS_RC[4U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [3U], vlTOPp->mem__02EMSTATUS_RC[3U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [2U], vlTOPp->mem__02EMSTATUS_RC[2U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [1U], vlTOPp->mem__02EMSTATUS_RC[1U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMSTATUS_RC
                  [0U], vlTOPp->mem__02EMSTATUS_RC[0U]);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__x2_multiplier__x2_multiplier__02Eclk, vlTOPp->x2_multiplier__02Eclk);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__BUS_ERROR_SX, vlTOPp->BUS_ERROR_SX);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EENV_CALL_WRONG_MODE_RE, vlTOPp->mem__02EENV_CALL_WRONG_MODE_RE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EENV_CALL_M_MODE_RE, vlTOPp->mem__02EENV_CALL_M_MODE_RE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EENV_CALL_S_MODE_RE, vlTOPp->mem__02EENV_CALL_S_MODE_RE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EENV_CALL_U_MODE_RE, vlTOPp->mem__02EENV_CALL_U_MODE_RE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EINSTRUCTION_ACCESS_FAULT_RE, vlTOPp->mem__02EINSTRUCTION_ACCESS_FAULT_RE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EILLEGAL_INSTRUCTION_RE, vlTOPp->mem__02EILLEGAL_INSTRUCTION_RE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EEXCEPTION_RE, vlTOPp->mem__02EEXCEPTION_RE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EEBREAK_RE, vlTOPp->mem__02EEBREAK_RE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02ESTORE_ACCESS_FAULT_RE, vlTOPp->mem__02ESTORE_ACCESS_FAULT_RE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02ESTORE_ADRESS_MISALIGNED_RE, vlTOPp->mem__02ESTORE_ADRESS_MISALIGNED_RE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__INSTRUCTION_ADRESS_MISALIGNED_RE, vlTOPp->INSTRUCTION_ADRESS_MISALIGNED_RE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02ELOAD_ACCESS_FAULT_RE, vlTOPp->mem__02ELOAD_ACCESS_FAULT_RE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02ELOAD_ADRESS_MISALIGNED_RE, vlTOPp->mem__02ELOAD_ADRESS_MISALIGNED_RE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02EEBREAK_RD, vlTOPp->exe__02EEBREAK_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02EMRET_RD, vlTOPp->exe__02EMRET_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02EENV_CALL_WRONG_MODE_RD, vlTOPp->exe__02EENV_CALL_WRONG_MODE_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02EENV_CALL_M_MODE_RD, vlTOPp->exe__02EENV_CALL_M_MODE_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02EENV_CALL_S_MODE_RD, vlTOPp->exe__02EENV_CALL_S_MODE_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02EENV_CALL_U_MODE_RD, vlTOPp->exe__02EENV_CALL_U_MODE_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02EINSTRUCTION_ACCESS_FAULT_RD, vlTOPp->exe__02EINSTRUCTION_ACCESS_FAULT_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02EADRESS_MISALIGNED_RD, vlTOPp->exe__02EADRESS_MISALIGNED_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02EILLEGAL_INSTRUCTION_RD, vlTOPp->exe__02EILLEGAL_INSTRUCTION_RD);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__exe__exe__02EPC_BRANCH_VALUE_RD, vlTOPp->exe__02EPC_BRANCH_VALUE_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02EMULT_INST_RD, vlTOPp->exe__02EMULT_INST_RD);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__exe__exe__02ECSR_RDATA_RD, vlTOPp->exe__02ECSR_RDATA_RD);
    VL_ASSIGN_ISI(12,vlTOPp->__Vcellinp__exe__exe__02ECSR_WADR_RD, vlTOPp->exe__02ECSR_WADR_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02ECSR_WENABLE_RD, vlTOPp->exe__02ECSR_WENABLE_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02EMEM_SIGN_EXTEND_RD, vlTOPp->exe__02EMEM_SIGN_EXTEND_RD);
    VL_ASSIGN_ISI(6,vlTOPp->__Vcellinp__exe__exe__02EDEST_RD, vlTOPp->exe__02EDEST_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02EWB_RD, vlTOPp->exe__02EWB_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__LOAD_RE, vlTOPp->LOAD_RE);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__exe__exe__02EMEM_DATA_RD, vlTOPp->exe__02EMEM_DATA_RD);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__ifetch__ifetch__02EPC_RD, vlTOPp->ifetch__02EPC_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__SIGN_EXTEND_RE, vlTOPp->SIGN_EXTEND_RE);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__exe__exe__02EPC_DEC2EXE_RD, vlTOPp->exe__02EPC_DEC2EXE_RD);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__mem__mem__02EMCACHE_RESULT_SM, vlTOPp->mem__02EMCACHE_RESULT_SM);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02ESLTU_RD, vlTOPp->exe__02ESLTU_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02ESLT_RD, vlTOPp->exe__02ESLT_RD);
    VL_ASSIGN_ISI(4,vlTOPp->__Vcellinp__exe__exe__02ESELECT_OPERATION_RD, vlTOPp->exe__02ESELECT_OPERATION_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__x1_multiplier__x1_multiplier__02EX0X1_EMPTY_SX0, vlTOPp->x1_multiplier__02EX0X1_EMPTY_SX0);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__dec__dec__02EMRET_SM, vlTOPp->dec__02EMRET_SM);
    VL_ASSIGN_ISI(2,vlTOPp->__Vcellinp__mem__mem__02EMEM_SIZE_RE, vlTOPp->mem__02EMEM_SIZE_RE);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__mem__mem__02ERES_RE, vlTOPp->mem__02ERES_RE);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__dec__dec__02ERETURN_ADRESS_SM, vlTOPp->dec__02ERETURN_ADRESS_SM);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__dec__dec__02EMCAUSE_WDATA_SM, vlTOPp->dec__02EMCAUSE_WDATA_SM);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__dec__dec__02EEXCEPTION_SM, vlTOPp->dec__02EEXCEPTION_SM);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__dec__dec__02EMTVEC_VALUE_RC, vlTOPp->dec__02EMTVEC_VALUE_RC);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02EEXCEPTION_RD, vlTOPp->exe__02EEXCEPTION_RD);
    VL_ASSIGN_ISI(2,vlTOPp->__Vcellinp__dec__dec__02ECURRENT_MODE_SM, vlTOPp->dec__02ECURRENT_MODE_SM);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__register_file__register_file__02Eclk, vlTOPp->register_file__02Eclk);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__dec__dec__02EPRED_ADR_RI, vlTOPp->dec__02EPRED_ADR_RI);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__dec__dec__02EPRED_TAKEN_RI, vlTOPp->dec__02EPRED_TAKEN_RI);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02Eclk, vlTOPp->mem__02Eclk);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__csr__csr__02Eclk, vlTOPp->csr__02Eclk);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__dec__dec__02EIF2DEC_EMPTY_SI, vlTOPp->dec__02EIF2DEC_EMPTY_SI);
    VL_ASSIGN_ISI(2,vlTOPp->__Vcellinp__exe__exe__02ECURRENT_MODE_SM, vlTOPp->exe__02ECURRENT_MODE_SM);
    VL_ASSIGN_ISI(2,vlTOPp->__Vcellinp__exe__exe__02EMEM_SIZE_RD, vlTOPp->exe__02EMEM_SIZE_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__x1_multiplier__x1_multiplier__02Eclk, vlTOPp->x1_multiplier__02Eclk);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__ifetch__ifetch__02Eclk, vlTOPp->ifetch__02Eclk);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__dec__BP_MEM_LOAD_RE, vlTOPp->BP_MEM_LOAD_RE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__dec__dec__02EMULT_INST_RM, vlTOPp->dec__02EMULT_INST_RM);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__dec__dec__02EMULT_INST_RE, vlTOPp->dec__02EMULT_INST_RE);
    VL_ASSIGN_WSW(320,vlTOPp->__Vcellinp__x1_multiplier__x1_multiplier__02ERES_RX0, vlTOPp->x1_multiplier__02ERES_RX0);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__dec__dec__02ECSR_RDATA_SC, vlTOPp->dec__02ECSR_RDATA_SC);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__dec__dec__02EPC_IF2DEC_RI, vlTOPp->dec__02EPC_IF2DEC_RI);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__exe__exe__02ECSR_RDATA_RM, vlTOPp->exe__02ECSR_RDATA_RM);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02ECSR_WENABLE_RM, vlTOPp->exe__02ECSR_WENABLE_RM);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__exe__exe__02EOP1_RD, vlTOPp->exe__02EOP1_RD);
    VL_ASSIGN_ISI(6,vlTOPp->__Vcellinp__exe__RADR1_RD, vlTOPp->RADR1_RD);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__dec__dec__02EREAD_PC_SR, vlTOPp->dec__02EREAD_PC_SR);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02ENEG_OP2_RD, vlTOPp->exe__02ENEG_OP2_RD);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__exe__exe__02EOP2_RD, vlTOPp->exe__02EOP2_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02EMULT_INST_RM, vlTOPp->exe__02EMULT_INST_RM);
    VL_ASSIGN_ISI(6,vlTOPp->__Vcellinp__exe__RADR2_RD, vlTOPp->RADR2_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02EMEM_STORE_RD, vlTOPp->exe__02EMEM_STORE_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02EMEM_LOAD_RD, vlTOPp->exe__02EMEM_LOAD_RD);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__dec__dec__02ERDATA2_SR, vlTOPp->dec__02ERDATA2_SR);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__dec__dec__02ERDATA1_SR, vlTOPp->dec__02ERDATA1_SR);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__exe__exe__02EMEM_RES_RM, vlTOPp->exe__02EMEM_RES_RM);
    VL_ASSIGN_ISI(6,vlTOPp->__Vcellinp__exe__exe__02EMEM_DEST_RM, vlTOPp->exe__02EMEM_DEST_RM);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02EBLOCK_BP_RD, vlTOPp->exe__02EBLOCK_BP_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__dec__dec__02Eclk, vlTOPp->dec__02Eclk);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__dec__dec__02ECSR_RDATA_RM, vlTOPp->dec__02ECSR_RDATA_RM);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__dec__dec__02ECSR_RDATA_RE, vlTOPp->dec__02ECSR_RDATA_RE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__dec__dec__02ECSR_WENABLE_RM, vlTOPp->dec__02ECSR_WENABLE_RM);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__dec__BP_MEM_RES_RM, vlTOPp->BP_MEM_RES_RM);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__dec__BP_EXE_RES_RE, vlTOPp->BP_EXE_RES_RE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__dec__dec__02ECSR_WENABLE_RE, vlTOPp->dec__02ECSR_WENABLE_RE);
    VL_ASSIGN_ISI(6,vlTOPp->__Vcellinp__dec__BP_DEST_RM, vlTOPp->BP_DEST_RM);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__dec__dec__02EBP_MEM2WBK_EMPTY_SM, vlTOPp->dec__02EBP_MEM2WBK_EMPTY_SM);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__dec__BP_EXE2MEM_EMPTY_SE, vlTOPp->BP_EXE2MEM_EMPTY_SE);
    VL_ASSIGN_ISI(6,vlTOPp->__Vcellinp__dec__BP_DEST_RE, vlTOPp->BP_DEST_RE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02Eclk, vlTOPp->exe__02Eclk);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__dec__dec__02EINSTR_RI, vlTOPp->dec__02EINSTR_RI);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__x0_multiplier__x0_multiplier__02Eclk, vlTOPp->x0_multiplier__02Eclk);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__csr__csr__02Ereset_n, vlTOPp->csr__02Ereset_n);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__register_file__register_file__02Ereset_n, vlTOPp->register_file__02Ereset_n);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__x2_multiplier__x2_multiplier__02Ereset_n, vlTOPp->x2_multiplier__02Ereset_n);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02Ereset_n, vlTOPp->mem__02Ereset_n);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__dec__dec__02Ereset_n, vlTOPp->dec__02Ereset_n);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__csr__csr__02EMTVAL_WDATA_SM, vlTOPp->csr__02EMTVAL_WDATA_SM);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__csr__csr__02EMCAUSE_WDATA_SM, vlTOPp->csr__02EMCAUSE_WDATA_SM);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__csr__csr__02EMEPC_WDATA_SM, vlTOPp->csr__02EMEPC_WDATA_SM);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__csr__csr__02EMIP_WDATA_SM, vlTOPp->csr__02EMIP_WDATA_SM);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__csr__csr__02EMSTATUS_WDATA_SM, vlTOPp->csr__02EMSTATUS_WDATA_SM);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__csr__csr__02EEXCEPTION_SM, vlTOPp->csr__02EEXCEPTION_SM);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__csr__csr__02ECSR_ENABLE_SM, vlTOPp->csr__02ECSR_ENABLE_SM);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__csr__csr__02ECSR_WDATA_SM, vlTOPp->csr__02ECSR_WDATA_SM);
    VL_ASSIGN_ISI(12,vlTOPp->__Vcellinp__csr__csr__02ECSR_WADR_SM, vlTOPp->csr__02ECSR_WADR_SM);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__register_file__register_file__02EWRITE_PC_ENABLE_SD, vlTOPp->register_file__02EWRITE_PC_ENABLE_SD);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__register_file__register_file__02EWRITE_PC_SD, vlTOPp->register_file__02EWRITE_PC_SD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__register_file__WENABLE_SW, vlTOPp->WENABLE_SW);
    VL_ASSIGN_ISI(6,vlTOPp->__Vcellinp__register_file__WADR_SW, vlTOPp->WADR_SW);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__register_file__WDATA_SW, vlTOPp->WDATA_SW);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__register_file__register_file__02EPC_INIT, vlTOPp->register_file__02EPC_INIT);
    VL_ASSIGN_WSW(128,vlTOPp->__Vcellinp__x2_multiplier__x2_multiplier__02ERES_RX1, vlTOPp->x2_multiplier__02ERES_RX1);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__x1_multiplier__x1_multiplier__02Ereset_n, vlTOPp->x1_multiplier__02Ereset_n);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__x0_multiplier__x0_multiplier__02Ereset_n, vlTOPp->x0_multiplier__02Ereset_n);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__ifetch__ifetch__02EADR_TO_BRANCH_RD, vlTOPp->ifetch__02EADR_TO_BRANCH_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__ifetch__ifetch__02EBRANCH_INST_RD, vlTOPp->ifetch__02EBRANCH_INST_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__x0_multiplier__x0_multiplier__02EX0X1_POP_SX1, vlTOPp->x0_multiplier__02EX0X1_POP_SX1);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02EEXE2MEM_POP_SM, vlTOPp->exe__02EEXE2MEM_POP_SM);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__mem__mem__02EMEM2WBK_POP_SW, vlTOPp->mem__02EMEM2WBK_POP_SW);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__ifetch__ifetch__02EIF2DEC_POP_SD, vlTOPp->ifetch__02EIF2DEC_POP_SD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__x1_multiplier__x1_multiplier__02EX1X2_POP_SX2, vlTOPp->x1_multiplier__02EX1X2_POP_SX2);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__dec__dec__02EDEC2EXE_POP_SE, vlTOPp->dec__02EDEC2EXE_POP_SE);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__dec__dec__02EDEC2IF_POP_SI, vlTOPp->dec__02EDEC2IF_POP_SI);
    VL_ASSIGN_ISI(2,vlTOPp->__Vcellinp__exe__exe__02ECMD_RD, vlTOPp->exe__02ECMD_RD);
    VL_ASSIGN_SII(32,vlTOPp->register_file__02EREAD_PC_SR, 
                  vlTOPp->register_file__DOT__registers
                  [0x20U]);
    VL_ASSIGN_SII(1,vlTOPp->mem__02ECSR_WENABLE_RM, 
                  (1U & (vlTOPp->mem__DOT__mem2wbk__DOT__data[1U] 
                         >> 7U)));
    VL_ASSIGN_SII(32,vlTOPp->mem__02ECSR_RDATA_RM, 
                  ((vlTOPp->mem__DOT__mem2wbk__DOT__data[2U] 
                    << 0x18U) | (vlTOPp->mem__DOT__mem2wbk__DOT__data[1U] 
                                 >> 8U)));
    VL_ASSIGN_SII(1,vlTOPp->mem__02EWB_RM, (1U & (vlTOPp->mem__DOT__mem2wbk__DOT__data[1U] 
                                                  >> 6U)));
    VL_ASSIGN_SII(6,vlTOPp->mem__02EMEM_DEST_RM, (0x3fU 
                                                  & vlTOPp->mem__DOT__mem2wbk__DOT__data[1U]));
    VL_ASSIGN_SII(32,vlTOPp->mem__02EMEM_RES_RM, vlTOPp->mem__DOT__mem2wbk__DOT__data[0U]);
    VL_ASSIGN_SII(1,vlTOPp->mem__02EMULT_INST_RM, (1U 
                                                   & (vlTOPp->mem__DOT__mem2wbk__DOT__data[2U] 
                                                      >> 8U)));
    VL_ASSIGN_SII(1,vlTOPp->dec__02EEBREAK_RD, (1U 
                                                & (vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                                                   >> 0x17U)));
    VL_ASSIGN_SII(1,vlTOPp->dec__02EEXCEPTION_RD, (1U 
                                                   & (vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                                                      >> 0x14U)));
    VL_ASSIGN_SII(1,vlTOPp->dec__02EMRET_RD, (1U & 
                                              (vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                                               >> 0x15U)));
    VL_ASSIGN_SII(1,vlTOPp->dec__02EINSTRUCTION_ACCESS_FAULT_RD, 
                  (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                         >> 0x16U)));
    VL_ASSIGN_SII(1,vlTOPp->dec__02EENV_CALL_WRONG_MODE_RD, 
                  (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                         >> 0x13U)));
    VL_ASSIGN_SII(1,vlTOPp->dec__02EENV_CALL_S_MODE_RD, 
                  (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                         >> 0xeU)));
    VL_ASSIGN_SII(1,vlTOPp->dec__02EENV_CALL_M_MODE_RD, 
                  (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                         >> 0xfU)));
    VL_ASSIGN_SII(1,vlTOPp->dec__02EENV_CALL_U_MODE_RD, 
                  (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                         >> 0x12U)));
    VL_ASSIGN_SII(1,vlTOPp->dec__02EADRESS_MISALIGNED_RD, 
                  (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                         >> 0x10U)));
    VL_ASSIGN_SII(1,vlTOPp->dec__02EILLEGAL_INSTRUCTION_RD, 
                  (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                         >> 0x11U)));
    VL_ASSIGN_SII(1,vlTOPp->dec__02EBLOCK_BP_RD, (1U 
                                                  & vlTOPp->dec__DOT__dec2exe__DOT__data[4U]));
    VL_ASSIGN_SII(6,vlTOPp->BP_RADR2_RD, (0x3fU & (
                                                   (vlTOPp->dec__DOT__dec2exe__DOT__data[4U] 
                                                    << 0xeU) 
                                                   | (vlTOPp->dec__DOT__dec2exe__DOT__data[3U] 
                                                      >> 0x12U))));
    VL_ASSIGN_SII(6,vlTOPp->BP_RADR1_RD, (0x3fU & (
                                                   (vlTOPp->dec__DOT__dec2exe__DOT__data[4U] 
                                                    << 8U) 
                                                   | (vlTOPp->dec__DOT__dec2exe__DOT__data[3U] 
                                                      >> 0x18U))));
    VL_ASSIGN_SII(1,vlTOPp->BP_R2_VALID_RD, (1U & (
                                                   vlTOPp->dec__DOT__dec2exe__DOT__data[3U] 
                                                   >> 0x1eU)));
    VL_ASSIGN_SII(1,vlTOPp->BP_R1_VALID_RD, (1U & (
                                                   vlTOPp->dec__DOT__dec2exe__DOT__data[3U] 
                                                   >> 0x1fU)));
    VL_ASSIGN_SII(1,vlTOPp->dec__02EMULT_INST_RD, (1U 
                                                   & (vlTOPp->dec__DOT__dec2exe__DOT__data[7U] 
                                                      >> 0x1bU)));
    VL_ASSIGN_SII(1,vlTOPp->dec__02ERET_INST_RD, (1U 
                                                  & (vlTOPp->dec__DOT__dec2if__DOT__data[3U] 
                                                     >> 3U)));
    VL_ASSIGN_SII(32,vlTOPp->dec__02EADR_TO_RET_RD, 
                  ((vlTOPp->dec__DOT__dec2if__DOT__data[4U] 
                    << 0x1cU) | (vlTOPp->dec__DOT__dec2if__DOT__data[3U] 
                                 >> 4U)));
    VL_ASSIGN_SII(1,vlTOPp->dec__02EPOP_ADR_RAS_RD, 
                  (1U & (vlTOPp->dec__DOT__dec2if__DOT__data[4U] 
                         >> 4U)));
    VL_ASSIGN_SII(1,vlTOPp->dec__02EPUSH_ADR_RAS_RD, 
                  (1U & (vlTOPp->dec__DOT__dec2if__DOT__data[4U] 
                         >> 5U)));
    VL_ASSIGN_SII(32,vlTOPp->dec__02EADR_TO_BRANCH_RD, 
                  vlTOPp->dec__DOT__dec2if__DOT__data[1U]);
    VL_ASSIGN_SII(32,vlTOPp->dec__02EBRANCH_INST_ADR_RD, 
                  vlTOPp->dec__DOT__dec2if__DOT__data[2U]);
    VL_ASSIGN_SII(1,vlTOPp->dec__02EBRANCH_INST_RD, 
                  (1U & vlTOPp->dec__DOT__dec2if__DOT__data[3U]));
    VL_ASSIGN_SII(1,vlTOPp->dec__02EPRED_SUCCESS_RD, 
                  (1U & (vlTOPp->dec__DOT__dec2if__DOT__data[3U] 
                         >> 1U)));
    VL_ASSIGN_SII(1,vlTOPp->dec__02EPRED_FAILED_RD, 
                  (1U & (vlTOPp->dec__DOT__dec2if__DOT__data[3U] 
                         >> 2U)));
    VL_ASSIGN_SII(32,vlTOPp->dec__02EPC_RD, vlTOPp->dec__DOT__dec2if__DOT__data[0U]);
    VL_ASSIGN_SII(32,vlTOPp->dec__02ECSR_RDATA_RD, 
                  ((vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                    << 0x12U) | (vlTOPp->dec__DOT__dec2exe__DOT__data[5U] 
                                 >> 0xeU)));
    VL_ASSIGN_SII(12,vlTOPp->dec__02ECSR_WADR_RD, (0xfffU 
                                                   & ((vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                                                       << 0x1fU) 
                                                      | (vlTOPp->dec__DOT__dec2exe__DOT__data[5U] 
                                                         >> 1U))));
    VL_ASSIGN_SII(1,vlTOPp->dec__02ECSR_WENABLE_RD, 
                  (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[5U] 
                         >> 0xdU)));
    VL_ASSIGN_SII(32,vlTOPp->dec__02EPC_BRANCH_VALUE_RD, 
                  ((vlTOPp->dec__DOT__dec2exe__DOT__data[7U] 
                    << 8U) | (vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                              >> 0x18U)));
    VL_ASSIGN_SII(32,vlTOPp->dec__02EPC_DEC2EXE_RD, 
                  ((vlTOPp->dec__DOT__dec2exe__DOT__data[5U] 
                    << 0x1fU) | (vlTOPp->dec__DOT__dec2exe__DOT__data[4U] 
                                 >> 1U)));
    VL_ASSIGN_SII(2,vlTOPp->dec__02EMEM_SIZE_RD, (3U 
                                                  & ((vlTOPp->dec__DOT__dec2exe__DOT__data[1U] 
                                                      << 0x17U) 
                                                     | (vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                                                        >> 9U))));
    VL_ASSIGN_SII(1,vlTOPp->dec__02EMEM_SIGN_EXTEND_RD, 
                  (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                         >> 0xbU)));
    VL_ASSIGN_SII(1,vlTOPp->dec__02EMEM_STORE_RD, (1U 
                                                   & (vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                                                      >> 0xcU)));
    VL_ASSIGN_SII(1,vlTOPp->dec__02EMEM_LOAD_RD, (1U 
                                                  & (vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                                                     >> 0xdU)));
    VL_ASSIGN_SII(32,vlTOPp->dec__02EMEM_DATA_RD, (
                                                   (vlTOPp->dec__DOT__dec2exe__DOT__data[1U] 
                                                    << 0x12U) 
                                                   | (vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                                                      >> 0xeU)));
    VL_ASSIGN_SII(1,vlTOPp->dec__02ESLTU_RD, (1U & 
                                              vlTOPp->dec__DOT__dec2exe__DOT__data[0U]));
    VL_ASSIGN_SII(1,vlTOPp->dec__02ESLT_RD, (1U & (
                                                   vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                                                   >> 1U)));
    VL_ASSIGN_SII(6,vlTOPp->dec__02EDEST_RD, (0x3fU 
                                              & ((vlTOPp->dec__DOT__dec2exe__DOT__data[1U] 
                                                  << 0x1eU) 
                                                 | (vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                                                    >> 2U))));
    VL_ASSIGN_SII(1,vlTOPp->dec__02EWB_RD, (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[1U] 
                                                  >> 0xeU)));
    VL_ASSIGN_SII(1,vlTOPp->dec__02ENEG_OP2_RD, (1U 
                                                 & (vlTOPp->dec__DOT__dec2exe__DOT__data[1U] 
                                                    >> 0xfU)));
    VL_ASSIGN_SII(2,vlTOPp->dec__02ECMD_RD, (3U & (
                                                   (vlTOPp->dec__DOT__dec2exe__DOT__data[4U] 
                                                    << 0x10U) 
                                                   | (vlTOPp->dec__DOT__dec2exe__DOT__data[3U] 
                                                      >> 0x10U))));
    VL_ASSIGN_SII(32,vlTOPp->dec__02EOP2_RD, ((vlTOPp->dec__DOT__dec2exe__DOT__data[2U] 
                                               << 0x10U) 
                                              | (vlTOPp->dec__DOT__dec2exe__DOT__data[1U] 
                                                 >> 0x10U)));
    VL_ASSIGN_SII(32,vlTOPp->dec__02EOP1_RD, ((vlTOPp->dec__DOT__dec2exe__DOT__data[3U] 
                                               << 0x10U) 
                                              | (vlTOPp->dec__DOT__dec2exe__DOT__data[2U] 
                                                 >> 0x10U)));
    VL_ASSIGN_SII(1,vlTOPp->x0_multiplier__02ESIGNED_RES_RX0, 
                  (1U & vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[0xaU]));
    VL_ASSIGN_SII(1,vlTOPp->x0_multiplier__02ESELECT_MSB_RX0, 
                  (1U & (vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[0xaU] 
                         >> 1U)));
    __Vtemp3[0U] = vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[0U];
    __Vtemp3[1U] = vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[1U];
    __Vtemp3[2U] = vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[2U];
    __Vtemp3[3U] = vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[3U];
    __Vtemp3[4U] = vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[4U];
    __Vtemp3[5U] = vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[5U];
    __Vtemp3[6U] = vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[6U];
    __Vtemp3[7U] = vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[7U];
    __Vtemp3[8U] = vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[8U];
    __Vtemp3[9U] = vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[9U];
    VL_ASSIGN_SWW(320,vlTOPp->x0_multiplier__02ERES_RX0, __Vtemp3);
    VL_ASSIGN_SII(32,vlTOPp->exe__02ECSR_RDATA_RE, 
                  ((vlTOPp->exe__DOT__exe2mem__DOT__data[4U] 
                    << 7U) | (vlTOPp->exe__DOT__exe2mem__DOT__data[3U] 
                              >> 0x19U)));
    VL_ASSIGN_SII(12,vlTOPp->exe__02ECSR_WADR_RE, (0xfffU 
                                                   & ((vlTOPp->exe__DOT__exe2mem__DOT__data[4U] 
                                                       << 0x13U) 
                                                      | (vlTOPp->exe__DOT__exe2mem__DOT__data[3U] 
                                                         >> 0xdU))));
    VL_ASSIGN_SII(1,vlTOPp->exe__02ECSR_WENABLE_RE, 
                  (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[3U] 
                         >> 0xcU)));
    VL_ASSIGN_SII(1,vlTOPp->exe__02EEBREAK_RE, (1U 
                                                & (vlTOPp->exe__DOT__exe2mem__DOT__data[5U] 
                                                   >> 6U)));
    VL_ASSIGN_SII(1,vlTOPp->exe__02EMRET_RE, (1U & 
                                              (vlTOPp->exe__DOT__exe2mem__DOT__data[5U] 
                                               >> 2U)));
    VL_ASSIGN_SII(1,vlTOPp->exe__02ESTORE_ACCESS_FAULT_RE, 
                  (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[5U] 
                         >> 4U)));
    VL_ASSIGN_SII(1,vlTOPp->exe__02ESTORE_ADRESS_MISALIGNED_RE, 
                  (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[5U] 
                         >> 3U)));
    VL_ASSIGN_SII(1,vlTOPp->exe__02ELOAD_ACCESS_FAULT_RE, 
                  (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[5U] 
                         >> 1U)));
    VL_ASSIGN_SII(1,vlTOPp->exe__02ELOAD_ADRESS_MISALIGNED_RE, 
                  (1U & vlTOPp->exe__DOT__exe2mem__DOT__data[5U]));
    VL_ASSIGN_SII(1,vlTOPp->exe__02EENV_CALL_WRONG_MODE_RE, 
                  (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[4U] 
                         >> 0x1aU)));
    VL_ASSIGN_SII(1,vlTOPp->exe__02EENV_CALL_M_MODE_RE, 
                  (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[4U] 
                         >> 0x1eU)));
    VL_ASSIGN_SII(1,vlTOPp->exe__02EENV_CALL_S_MODE_RE, 
                  (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[4U] 
                         >> 0x19U)));
    VL_ASSIGN_SII(1,vlTOPp->exe__02EENV_CALL_U_MODE_RE, 
                  (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[4U] 
                         >> 0x1dU)));
    VL_ASSIGN_SII(1,vlTOPp->exe__02EINSTRUCTION_ACCESS_FAULT_RE, 
                  (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[5U] 
                         >> 5U)));
    VL_ASSIGN_SII(1,vlTOPp->ADRESS_MISALIGNED_RE, (1U 
                                                   & (vlTOPp->exe__DOT__exe2mem__DOT__data[4U] 
                                                      >> 0x1cU)));
    VL_ASSIGN_SII(1,vlTOPp->exe__02EILLEGAL_INSTRUCTION_RE, 
                  (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[4U] 
                         >> 0x1bU)));
    VL_ASSIGN_SII(1,vlTOPp->exe__02EEXCEPTION_RE, (1U 
                                                   & (vlTOPp->exe__DOT__exe2mem__DOT__data[4U] 
                                                      >> 0x1fU)));
    VL_ASSIGN_SII(32,vlTOPp->exe__02EPC_BRANCH_VALUE_RE, 
                  ((vlTOPp->exe__DOT__exe2mem__DOT__data[6U] 
                    << 0x19U) | (vlTOPp->exe__DOT__exe2mem__DOT__data[5U] 
                                 >> 7U)));
    VL_ASSIGN_SII(1,vlTOPp->exe__02EMULT_INST_RE, (1U 
                                                   & (vlTOPp->exe__DOT__exe2mem__DOT__data[6U] 
                                                      >> 7U)));
    VL_ASSIGN_SII(32,vlTOPp->exe__02EPC_EXE2MEM_RE, 
                  ((vlTOPp->exe__DOT__exe2mem__DOT__data[3U] 
                    << 0x14U) | (vlTOPp->exe__DOT__exe2mem__DOT__data[2U] 
                                 >> 0xcU)));
    VL_ASSIGN_SII(1,vlTOPp->MEM_STORE_RE, (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[2U] 
                                                 >> 0xaU)));
    VL_ASSIGN_SII(1,vlTOPp->MEM_LOAD_RE, (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[2U] 
                                                >> 9U)));
    VL_ASSIGN_SII(1,vlTOPp->MEM_SIGN_EXTEND_RE, (1U 
                                                 & (vlTOPp->exe__DOT__exe2mem__DOT__data[2U] 
                                                    >> 0xbU)));
    VL_ASSIGN_SII(1,vlTOPp->exe__02EWB_RE, (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[2U] 
                                                  >> 8U)));
    VL_ASSIGN_SII(2,vlTOPp->exe__02EMEM_SIZE_RE, (3U 
                                                  & ((vlTOPp->exe__DOT__exe2mem__DOT__data[3U] 
                                                      << 0x1aU) 
                                                     | (vlTOPp->exe__DOT__exe2mem__DOT__data[2U] 
                                                        >> 6U))));
    VL_ASSIGN_SII(6,vlTOPp->exe__02EDEST_RE, (0x3fU 
                                              & vlTOPp->exe__DOT__exe2mem__DOT__data[2U]));
    VL_ASSIGN_SII(32,vlTOPp->exe__02EMEM_DATA_RE, vlTOPp->exe__DOT__exe2mem__DOT__data[1U]);
    VL_ASSIGN_SII(32,vlTOPp->exe__02ERES_RE, vlTOPp->exe__DOT__exe2mem__DOT__data[0U]);
    VL_ASSIGN_SII(1,vlTOPp->ifetch__02EPRED_TAKEN_RI, 
                  (1U & vlTOPp->ifetch__DOT__if2dec__DOT__data[3U]));
    VL_ASSIGN_SII(32,vlTOPp->ifetch__02EPRED_ADR_RI, 
                  vlTOPp->ifetch__DOT__if2dec__DOT__data[2U]);
    VL_ASSIGN_SII(32,vlTOPp->ifetch__02EPC_IF2DEC_RI, 
                  vlTOPp->ifetch__DOT__if2dec__DOT__data[0U]);
    VL_ASSIGN_SII(32,vlTOPp->ifetch__02EINSTR_RI, vlTOPp->ifetch__DOT__if2dec__DOT__data[1U]);
    vlTOPp->__Vcellout__dec__dec__02ESELECT_OPERATION_RD 
        = ((0xeU & (vlTOPp->dec__DOT__dec2exe__DOT__data[7U] 
                    >> 0x17U)) | (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                                        >> 8U)));
    vlTOPp->__Vcellout__csr__csr__02EMEPC_SC = vlTOPp->csr__DOT__reg_mepc;
    vlTOPp->__Vcellout__csr__csr__02EMSTATUS_RC = vlTOPp->csr__DOT__reg_mstatus;
    vlTOPp->__Vcellout__csr__csr__02EMTVEC_VALUE_RC 
        = vlTOPp->csr__DOT__reg_mtvec;
    vlTOPp->__Vcellout__csr__csr__02EMIP_VALUE_RC = vlTOPp->csr__DOT__reg_mip;
    vlTOPp->__Vcellout__csr__csr__02EMIE_VALUE_RC = vlTOPp->csr__DOT__reg_mie;
    vlTOPp->__Vcellout__csr__MCAUSE_SC = vlTOPp->csr__DOT__reg_mcause;
    vlTOPp->__Vcellout__x1_multiplier__x1_multiplier__02ESIGNED_RES_RX1 
        = (1U & (vlTOPp->x1_multiplier__DOT__x1x2__DOT__data[4U] 
                 >> 1U));
    vlTOPp->__Vcellout__x1_multiplier__x1_multiplier__02ESELECT_MSB_RX1 
        = (1U & vlTOPp->x1_multiplier__DOT__x1x2__DOT__data[4U]);
    vlTOPp->__Vcellout__x1_multiplier__x1_multiplier__02ERES_RX1[0U] 
        = vlTOPp->x1_multiplier__DOT__x1x2__DOT__data[0U];
    vlTOPp->__Vcellout__x1_multiplier__x1_multiplier__02ERES_RX1[1U] 
        = vlTOPp->x1_multiplier__DOT__x1x2__DOT__data[1U];
    vlTOPp->__Vcellout__x1_multiplier__x1_multiplier__02ERES_RX1[2U] 
        = vlTOPp->x1_multiplier__DOT__x1x2__DOT__data[2U];
    vlTOPp->__Vcellout__x1_multiplier__x1_multiplier__02ERES_RX1[3U] 
        = vlTOPp->x1_multiplier__DOT__x1x2__DOT__data[3U];
    vlTOPp->exe__DOT__divider_i__DOT__quotient = ((IData)(vlTOPp->exe__DOT__divider_i__DOT__quotient_sign_reg)
                                                   ? 
                                                  (~ 
                                                   ((IData)(1U) 
                                                    + vlTOPp->exe__DOT__divider_i__DOT__quotient_reg))
                                                   : vlTOPp->exe__DOT__divider_i__DOT__quotient_reg);
    vlTOPp->__Vtableidx1 = vlTOPp->exe__DOT__divider_i__DOT__EP;
    vlTOPp->exe__DOT__divider_i__DOT__setup_regs = 
        vlTOPp->__Vtable1_exe__DOT__divider_i__DOT__setup_regs
        [vlTOPp->__Vtableidx1];
    vlTOPp->exe__DOT__divider_i__DOT__same = vlTOPp->__Vtable1_exe__DOT__divider_i__DOT__same
        [vlTOPp->__Vtableidx1];
    vlTOPp->exe__DOT__divider_i__DOT__zero_div = vlTOPp->__Vtable1_exe__DOT__divider_i__DOT__zero_div
        [vlTOPp->__Vtableidx1];
    vlTOPp->exe__DOT__divider_i__DOT__running = vlTOPp->__Vtable1_exe__DOT__divider_i__DOT__running
        [vlTOPp->__Vtableidx1];
    vlTOPp->exe__DOT__done_div = vlTOPp->__Vtable1_exe__DOT__done_div
        [vlTOPp->__Vtableidx1];
    vlTOPp->exe__DOT__busy_div = vlTOPp->__Vtable1_exe__DOT__busy_div
        [vlTOPp->__Vtableidx1];
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__0__KET____DOT__csa1__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                           [0U])) ^ (QData)((IData)(
                                                    vlTOPp->x0_multiplier__DOT__product
                                                    [1U])));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__1__KET____DOT__csa1__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                           [3U])) ^ (QData)((IData)(
                                                    vlTOPp->x0_multiplier__DOT__product
                                                    [4U])));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__2__KET____DOT__csa1__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                           [6U])) ^ (QData)((IData)(
                                                    vlTOPp->x0_multiplier__DOT__product
                                                    [7U])));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__3__KET____DOT__csa1__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                           [9U])) ^ (QData)((IData)(
                                                    vlTOPp->x0_multiplier__DOT__product
                                                    [0xaU])));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__4__KET____DOT__csa1__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                           [0xcU])) ^ (QData)((IData)(
                                                      vlTOPp->x0_multiplier__DOT__product
                                                      [0xdU])));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__5__KET____DOT__csa1__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                           [0xfU])) ^ (QData)((IData)(
                                                      vlTOPp->x0_multiplier__DOT__product
                                                      [0x10U])));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__6__KET____DOT__csa1__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                           [0x12U])) ^ (QData)((IData)(
                                                       vlTOPp->x0_multiplier__DOT__product
                                                       [0x13U])));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__7__KET____DOT__csa1__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                           [0x15U])) ^ (QData)((IData)(
                                                       vlTOPp->x0_multiplier__DOT__product
                                                       [0x16U])));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__8__KET____DOT__csa1__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                           [0x18U])) ^ (QData)((IData)(
                                                       vlTOPp->x0_multiplier__DOT__product
                                                       [0x19U])));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__9__KET____DOT__csa1__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                           [0x1bU])) ^ (QData)((IData)(
                                                       vlTOPp->x0_multiplier__DOT__product
                                                       [0x1cU])));
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__exe__exe__02Ereset_n, vlTOPp->exe__02Ereset_n);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__ifetch__ifetch__02Ereset_n, vlTOPp->ifetch__02Ereset_n);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__ifetch__ifetch__02EBRANCH_INST_ADR_RD, vlTOPp->ifetch__02EBRANCH_INST_ADR_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__ifetch__ifetch__02EPRED_SUCCESS_RD, vlTOPp->ifetch__02EPRED_SUCCESS_RD);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__ifetch__ifetch__02EPRED_FAILED_RD, vlTOPp->ifetch__02EPRED_FAILED_RD);
    vlTOPp->exe__DOT__divider_i__DOT__division = (vlTOPp->exe__DOT__divider_i__DOT__divisor_reg 
                                                  > vlTOPp->exe__DOT__divider_i__DOT__reminder_reg);
    VL_ASSIGN_SII(1,vlTOPp->x0_multiplier__02EX0X1_EMPTY_SX0, 
                  (1U & (~ (IData)(vlTOPp->x0_multiplier__DOT__x0x1__DOT__data_v))));
    VL_ASSIGN_SII(1,vlTOPp->exe__02EEXE2MEM_EMPTY_SE, 
                  (1U & (~ (IData)(vlTOPp->exe__DOT__exe2mem__DOT__data_v))));
    VL_ASSIGN_SII(1,vlTOPp->mem__02EMEM2WBK_EMPTY_SM, 
                  (1U & (~ (IData)(vlTOPp->mem__DOT__mem2wbk__DOT__data_v))));
    VL_ASSIGN_SII(1,vlTOPp->ifetch__02EIF2DEC_EMPTY_SI, 
                  (1U & (~ (IData)(vlTOPp->ifetch__DOT__if2dec__DOT__data_v))));
    VL_ASSIGN_SII(1,vlTOPp->x1_multiplier__02EX1X2_EMPTY_SX1, 
                  (1U & (~ (IData)(vlTOPp->x1_multiplier__DOT__x1x2__DOT__data_v))));
    VL_ASSIGN_SII(1,vlTOPp->dec__02EDEC2IF_EMPTY_SD, 
                  (1U & (~ (IData)(vlTOPp->dec__DOT__dec2if__DOT__data_v))));
    VL_ASSIGN_SII(1,vlTOPp->dec__02EDEC2EXE_EMPTY_SD, 
                  (1U & (~ (IData)(vlTOPp->dec__DOT__dec2exe__DOT__data_v))));
    VL_ASSIGN_SII(6,vlTOPp->DEST_SW, vlTOPp->__Vcellinp__wbk__wbk__02EMEM_DEST_RM);
    VL_ASSIGN_SII(1,vlTOPp->x2_multiplier__02EX1X2_POP_SX2, 
                  (1U & (~ (IData)(vlTOPp->__Vcellinp__x2_multiplier__x2_multiplier__02EX1X2_EMPTY_SX1))));
    VL_ASSIGN_SII(12,vlTOPp->mem__02ECSR_WADR_SM, vlTOPp->__Vcellinp__mem__mem__02ECSR_WADR_RE);
    VL_ASSIGN_SII(32,vlTOPp->register_file__02ERDATA2_SR, 
                  ((0x20U >= (IData)(vlTOPp->__Vcellinp__register_file__RADR2_SD))
                    ? vlTOPp->register_file__DOT__registers
                   [vlTOPp->__Vcellinp__register_file__RADR2_SD]
                    : 0U));
    VL_ASSIGN_SII(32,vlTOPp->register_file__02ERDATA1_SR, 
                  ((0x20U >= (IData)(vlTOPp->__Vcellinp__register_file__RADR1_SD))
                    ? vlTOPp->register_file__DOT__registers
                   [vlTOPp->__Vcellinp__register_file__RADR1_SD]
                    : 0U));
    VL_ASSIGN_SII(32,vlTOPp->x2_multiplier__02ERES_RX2, 
                  ((IData)(vlTOPp->__Vcellinp__x2_multiplier__x2_multiplier__02ESELECT_MSB_RX1)
                    ? (IData)((vlTOPp->x2_multiplier__DOT__res 
                               >> 0x20U)) : (IData)(vlTOPp->x2_multiplier__DOT__res)));
    VL_ASSIGN_SII(32,vlTOPp->DATA_SW, ((IData)(vlTOPp->__Vcellinp__wbk__wbk__02ECSR_WENABLE_RM)
                                        ? vlTOPp->__Vcellinp__wbk__wbk__02ECSR_RDATA_RM
                                        : ((IData)(vlTOPp->__Vcellinp__wbk__wbk__02EMULT_INST_RM)
                                            ? vlTOPp->__Vcellinp__wbk__wbk__02ERES_RX2
                                            : vlTOPp->__Vcellinp__wbk__wbk__02EMEM_RES_RM)));
    VL_ASSIGN_SII(1,vlTOPp->wbk__02EMEM2WBK_POP_SW, 
                  (1U & (~ (IData)(vlTOPp->__Vcellinp__wbk__wbk__02EMEM2WBK_EMPTY_SM))));
    VL_ASSIGN_SII(1,vlTOPp->WB_SW, ((IData)(vlTOPp->__Vcellinp__wbk__wbk__02EWB_RM) 
                                    & (~ (IData)(vlTOPp->__Vcellinp__wbk__wbk__02EMEM2WBK_EMPTY_SM))));
    VL_ASSIGN_SII(1,vlTOPp->mem__02EMCACHE_STORE_SM, vlTOPp->__Vcellinp__mem__STORE_RE);
    vlTOPp->mem__DOT__mem2wbk_din[1U] = ((0xffU & vlTOPp->mem__DOT__mem2wbk_din[1U]) 
                                         | (0xffffff00U 
                                            & (vlTOPp->__Vcellinp__mem__mem__02ECSR_RDATA_RE 
                                               << 8U)));
    vlTOPp->mem__DOT__mem2wbk_din[2U] = ((0x100U & 
                                          vlTOPp->mem__DOT__mem2wbk_din[2U]) 
                                         | (0xffU & 
                                            (vlTOPp->__Vcellinp__mem__mem__02ECSR_RDATA_RE 
                                             >> 0x18U)));
    vlTOPp->mem__DOT__mem2wbk_din[2U] = ((0xffU & vlTOPp->mem__DOT__mem2wbk_din[2U]) 
                                         | (0xffffff00U 
                                            & ((IData)(vlTOPp->__Vcellinp__mem__mem__02EMULT_INST_RE) 
                                               << 8U)));
    vlTOPp->mem__DOT__mem2wbk_din[1U] = ((0xffffffc0U 
                                          & vlTOPp->mem__DOT__mem2wbk_din[1U]) 
                                         | (IData)(vlTOPp->__Vcellinp__mem__mem__02EDEST_RE));
    VL_ASSIGN_SII(32,vlTOPp->mem__02EMEPC_WDATA_SM, vlTOPp->__Vcellinp__mem__mem__02EPC_EXE2MEM_RE);
    VL_ASSIGN_SII(32,vlTOPp->csr__02ECSR_RDATA_SC, 
                  ((0xf11U == (IData)(vlTOPp->__Vcellinp__csr__csr__02ECSR_RADR_SD))
                    ? vlTOPp->csr__DOT__reg_mvendorid
                    : ((0xf12U == (IData)(vlTOPp->__Vcellinp__csr__csr__02ECSR_RADR_SD))
                        ? vlTOPp->csr__DOT__reg_marchid
                        : ((0xf13U == (IData)(vlTOPp->__Vcellinp__csr__csr__02ECSR_RADR_SD))
                            ? vlTOPp->csr__DOT__reg_mimpid
                            : ((0x300U == (IData)(vlTOPp->__Vcellinp__csr__csr__02ECSR_RADR_SD))
                                ? vlTOPp->csr__DOT__reg_mstatus
                                : ((0x301U == (IData)(vlTOPp->__Vcellinp__csr__csr__02ECSR_RADR_SD))
                                    ? vlTOPp->csr__DOT__reg_misa
                                    : ((0x304U == (IData)(vlTOPp->__Vcellinp__csr__csr__02ECSR_RADR_SD))
                                        ? vlTOPp->csr__DOT__reg_mie
                                        : ((0x305U 
                                            == (IData)(vlTOPp->__Vcellinp__csr__csr__02ECSR_RADR_SD))
                                            ? vlTOPp->csr__DOT__reg_mtvec
                                            : ((0x310U 
                                                == (IData)(vlTOPp->__Vcellinp__csr__csr__02ECSR_RADR_SD))
                                                ? vlTOPp->csr__DOT__reg_mstatush
                                                : (
                                                   (0x341U 
                                                    == (IData)(vlTOPp->__Vcellinp__csr__csr__02ECSR_RADR_SD))
                                                    ? vlTOPp->csr__DOT__reg_mepc
                                                    : 
                                                   ((0x342U 
                                                     == (IData)(vlTOPp->__Vcellinp__csr__csr__02ECSR_RADR_SD))
                                                     ? vlTOPp->csr__DOT__reg_mcause
                                                     : 
                                                    ((0x343U 
                                                      == (IData)(vlTOPp->__Vcellinp__csr__csr__02ECSR_RADR_SD))
                                                      ? vlTOPp->csr__DOT__reg_mtval
                                                      : 
                                                     ((0x344U 
                                                       == (IData)(vlTOPp->__Vcellinp__csr__csr__02ECSR_RADR_SD))
                                                       ? vlTOPp->csr__DOT__reg_mip
                                                       : 
                                                      ((0x340U 
                                                        == (IData)(vlTOPp->__Vcellinp__csr__csr__02ECSR_RADR_SD))
                                                        ? vlTOPp->csr__DOT__reg_mscratch
                                                        : 0U))))))))))))));
    vlTOPp->mem__DOT__mem2wbk_din[1U] = ((0xffffff7fU 
                                          & vlTOPp->mem__DOT__mem2wbk_din[1U]) 
                                         | (0xffffff80U 
                                            & ((IData)(vlTOPp->__Vcellinp__mem__mem__02ECSR_WENABLE_RE) 
                                               << 7U)));
    vlTOPp->x0_multiplier__DOT__signed_type = ((~ (
                                                   ((2U 
                                                     == (IData)(vlTOPp->__Vcellinp__x0_multiplier__MULT_CMD_RD)) 
                                                    | (1U 
                                                       == (IData)(vlTOPp->__Vcellinp__x0_multiplier__MULT_CMD_RD))) 
                                                   & ((vlTOPp->__Vcellinp__x0_multiplier__x0_multiplier__02EOP1_SE 
                                                       & vlTOPp->__Vcellinp__x0_multiplier__x0_multiplier__02EOP2_SE) 
                                                      >> 0x1fU))) 
                                               & (3U 
                                                  != (IData)(vlTOPp->__Vcellinp__x0_multiplier__MULT_CMD_RD)));
    if ((((vlTOPp->__Vcellinp__x0_multiplier__x0_multiplier__02EOP1_SE 
           & vlTOPp->__Vcellinp__x0_multiplier__x0_multiplier__02EOP2_SE) 
          >> 0x1fU) & ((2U == (IData)(vlTOPp->__Vcellinp__x0_multiplier__MULT_CMD_RD)) 
                       | (1U == (IData)(vlTOPp->__Vcellinp__x0_multiplier__MULT_CMD_RD))))) {
        vlTOPp->x0_multiplier__DOT__op1 = ((IData)(1U) 
                                           + (~ vlTOPp->__Vcellinp__x0_multiplier__x0_multiplier__02EOP1_SE));
        vlTOPp->x0_multiplier__DOT__op2 = ((IData)(1U) 
                                           + (~ vlTOPp->__Vcellinp__x0_multiplier__x0_multiplier__02EOP2_SE));
    } else {
        vlTOPp->x0_multiplier__DOT__op1 = ((((~ (vlTOPp->__Vcellinp__x0_multiplier__x0_multiplier__02EOP1_SE 
                                                 >> 0x1fU)) 
                                             & (vlTOPp->__Vcellinp__x0_multiplier__x0_multiplier__02EOP2_SE 
                                                >> 0x1fU)) 
                                            & ((2U 
                                                == (IData)(vlTOPp->__Vcellinp__x0_multiplier__MULT_CMD_RD)) 
                                               | (1U 
                                                  == (IData)(vlTOPp->__Vcellinp__x0_multiplier__MULT_CMD_RD))))
                                            ? vlTOPp->__Vcellinp__x0_multiplier__x0_multiplier__02EOP1_SE
                                            : vlTOPp->__Vcellinp__x0_multiplier__x0_multiplier__02EOP2_SE);
        vlTOPp->x0_multiplier__DOT__op2 = ((((~ (vlTOPp->__Vcellinp__x0_multiplier__x0_multiplier__02EOP1_SE 
                                                 >> 0x1fU)) 
                                             & (vlTOPp->__Vcellinp__x0_multiplier__x0_multiplier__02EOP2_SE 
                                                >> 0x1fU)) 
                                            & ((2U 
                                                == (IData)(vlTOPp->__Vcellinp__x0_multiplier__MULT_CMD_RD)) 
                                               | (1U 
                                                  == (IData)(vlTOPp->__Vcellinp__x0_multiplier__MULT_CMD_RD))))
                                            ? vlTOPp->__Vcellinp__x0_multiplier__x0_multiplier__02EOP2_SE
                                            : vlTOPp->__Vcellinp__x0_multiplier__x0_multiplier__02EOP1_SE);
    }
    vlTOPp->ifetch__DOT__if2dec_din[1U] = ((IData)(vlTOPp->__Vcellinp__ifetch__ifetch__02EEXCEPTION_SM)
                                            ? 0x13U
                                            : vlTOPp->__Vcellinp__ifetch__ifetch__02EIC_INST_SI);
    VL_ASSIGN_SII(32,vlTOPp->mem__02ERETURN_ADRESS_SM, 
                  ((IData)(vlTOPp->__Vcellinp__mem__mem__02EMRET_RE)
                    ? (IData)(vlTOPp->__Vcellinp__mem__mem__02EMEPC_SC)
                    : 0U));
    VL_ASSIGN_SII(1,vlTOPp->ifetch__02EADR_VALID_SI, 
                  (1U & (((~ (IData)(vlTOPp->__Vcellinp__ifetch__ifetch__02EDEC2IF_EMPTY_SD)) 
                          & (~ (IData)(vlTOPp->__Vcellinp__ifetch__ifetch__02EIF2DEC_FLUSH_SD))) 
                         & (~ (IData)(vlTOPp->__Vcellinp__ifetch__ifetch__02EEXCEPTION_SM)))));
    vlTOPp->mem__DOT__data_byte_store_sm = (0xffU & vlTOPp->__Vcellinp__mem__mem__02EMEM_DATA_RE);
    vlTOPp->mem__DOT__data_half_store_sm = (0xffffU 
                                            & vlTOPp->__Vcellinp__mem__mem__02EMEM_DATA_RE);
    vlTOPp->mem__DOT__mstatus_x = (((1U & 