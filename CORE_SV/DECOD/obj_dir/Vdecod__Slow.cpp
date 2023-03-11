// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdecod.h for the primary calling header

#include "Vdecod.h"
#include "Vdecod__Syms.h"

//==========

VL_CTOR_IMP(Vdecod) {
    Vdecod__Syms* __restrict vlSymsp = __VlSymsp = new Vdecod__Syms(this, name());
    Vdecod* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vdecod::__Vconfigure(Vdecod__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vdecod::~Vdecod() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vdecod::_initial__TOP__1(Vdecod__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecod::_initial__TOP__1\n"); );
    Vdecod* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->dec__DOT__pred_failed_sd = 0U;
    vlTOPp->dec__DOT__pc = 0U;
    vlTOPp->dec__DOT__dec2if__DOT__data_v = 0U;
    vlTOPp->dec__DOT__dec2exe__DOT__data_v = 0U;
}

void Vdecod::_settle__TOP__2(Vdecod__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecod::_settle__TOP__2\n"); );
    Vdecod* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*127:0*/ __Vtemp1[4];
    WData/*127:0*/ __Vtemp4[4];
    WData/*95:0*/ __Vtemp12[3];
    WData/*191:0*/ __Vtemp17[6];
    // Body
    vlTOPp->dec__DOT__mtvec_value = (0xfffffffcU & vlTOPp->dec__DOT__mtvec_value);
    vlTOPp->PRED_ADR_SD = vlTOPp->PRED_ADR_RI;
    vlTOPp->PRED_TAKEN_SD = vlTOPp->PRED_TAKEN_RI;
    VL_EXTEND_WI(123,32, __Vtemp1, vlTOPp->PC_IF2DEC_RI);
    vlTOPp->dec__DOT__dec2exe_x[0U] = 0U;
    vlTOPp->dec__DOT__dec2exe_x[1U] = 0U;
    vlTOPp->dec__DOT__dec2exe_x[2U] = 0U;
    vlTOPp->dec__DOT__dec2exe_x[3U] = 0U;
    vlTOPp->dec__DOT__dec2exe_x[4U] = (0xfffffffeU 
                                       & (__Vtemp1[0U] 
                                          << 1U));
    vlTOPp->dec__DOT__dec2exe_x[5U] = ((1U & (__Vtemp1[0U] 
                                              >> 0x1fU)) 
                                       | (0xfffffffeU 
                                          & (__Vtemp1[1U] 
                                             << 1U)));
    vlTOPp->dec__DOT__dec2exe_x[6U] = ((1U & (__Vtemp1[1U] 
                                              >> 0x1fU)) 
                                       | (0xfffffffeU 
                                          & (__Vtemp1[2U] 
                                             << 1U)));
    vlTOPp->dec__DOT__dec2exe_x[7U] = ((1U & (__Vtemp1[2U] 
                                              >> 0x1fU)) 
                                       | (0xfffffffeU 
                                          & (__Vtemp1[3U] 
                                             << 1U)));
    vlTOPp->dec__DOT__env_call_s_mode_sd = ((2U != (IData)(vlTOPp->CURRENT_MODE_SM)) 
                                            & (0x10200073U 
                                               == vlTOPp->INSTR_RI));
    vlTOPp->dec__DOT__env_call_wrong_mode = ((3U != (IData)(vlTOPp->CURRENT_MODE_SM)) 
                                             & (0x30200073U 
                                                == vlTOPp->INSTR_RI));
    vlTOPp->dec__DOT__mcause_val = (0xfffffffcU & (vlTOPp->MCAUSE_WDATA_SM 
                                                   << 2U));
    vlTOPp->dec__DOT__mtvec_value = ((1U & vlTOPp->dec__DOT__mtvec_value) 
                                     | (0xfffffffeU 
                                        & vlTOPp->MTVEC_VALUE_RC));
    vlTOPp->dec__DOT__sub_i_sd = (((0x33U == (0x7fU 
                                              & vlTOPp->INSTR_RI)) 
                                   & (0U == (7U & (vlTOPp->INSTR_RI 
                                                   >> 0xcU)))) 
                                  & (vlTOPp->INSTR_RI 
                                     >> 0x1eU));
    vlTOPp->dec__DOT__slt_i_sd = (((0x33U == (0x7fU 
                                              & vlTOPp->INSTR_RI)) 
                                   & (2U == (7U & (vlTOPp->INSTR_RI 
                                                   >> 0xcU)))) 
                                  & (~ (vlTOPp->INSTR_RI 
                                        >> 0x1eU)));
    vlTOPp->dec__DOT__sltu_i_sd = (((0x33U == (0x7fU 
                                               & vlTOPp->INSTR_RI)) 
                                    & (3U == (7U & 
                                              (vlTOPp->INSTR_RI 
                                               >> 0xcU)))) 
                                   & (~ (vlTOPp->INSTR_RI 
                                         >> 0x1eU)));
    vlTOPp->dec__DOT__slti_i_sd = ((0x13U == (0x7fU 
                                              & vlTOPp->INSTR_RI)) 
                                   & (2U == (7U & (vlTOPp->INSTR_RI 
                                                   >> 0xcU))));
    vlTOPp->dec__DOT__sltiu_i_sd = ((0x13U == (0x7fU 
                                               & vlTOPp->INSTR_RI)) 
                                    & (3U == (7U & 
                                              (vlTOPp->INSTR_RI 
                                               >> 0xcU))));
    vlTOPp->dec__DOT__lw_i_sd = ((3U == (0x7fU & vlTOPp->INSTR_RI)) 
                                 & (2U == (7U & (vlTOPp->INSTR_RI 
                                                 >> 0xcU))));
    vlTOPp->dec__DOT__lh_i_sd = ((3U == (0x7fU & vlTOPp->INSTR_RI)) 
                                 & (1U == (7U & (vlTOPp->INSTR_RI 
                                                 >> 0xcU))));
    vlTOPp->dec__DOT__lhu_i_sd = ((3U == (0x7fU & vlTOPp->INSTR_RI)) 
                                  & (5U == (7U & (vlTOPp->INSTR_RI 
                                                  >> 0xcU))));
    vlTOPp->dec__DOT__lb_i_sd = ((3U == (0x7fU & vlTOPp->INSTR_RI)) 
                                 & (0U == (7U & (vlTOPp->INSTR_RI 
                                                 >> 0xcU))));
    vlTOPp->dec__DOT__lbu_i_sd = ((3U == (0x7fU & vlTOPp->INSTR_RI)) 
                                  & (4U == (7U & (vlTOPp->INSTR_RI 
                                                  >> 0xcU))));
    vlTOPp->dec__DOT__sw_i_sd = ((0x23U == (0x7fU & vlTOPp->INSTR_RI)) 
                                 & (2U == (7U & (vlTOPp->INSTR_RI 
                                                 >> 0xcU))));
    vlTOPp->dec__DOT__sh_i_sd = ((0x23U == (0x7fU & vlTOPp->INSTR_RI)) 
                                 & (1U == (7U & (vlTOPp->INSTR_RI 
                                                 >> 0xcU))));
    vlTOPp->dec__DOT__sb_i_sd = ((0x23U == (0x7fU & vlTOPp->INSTR_RI)) 
                                 & (0U == (7U & (vlTOPp->INSTR_RI 
                                                 >> 0xcU))));
    vlTOPp->dec__DOT__and_i_sd = (((0x33U == (0x7fU 
                                              & vlTOPp->INSTR_RI)) 
                                   & (7U == (7U & (vlTOPp->INSTR_RI 
                                                   >> 0xcU)))) 
                                  & (~ (vlTOPp->INSTR_RI 
                                        >> 0x1eU)));
    vlTOPp->dec__DOT__or_i_sd = (((0x33U == (0x7fU 
                                             & vlTOPp->INSTR_RI)) 
                                  & (6U == (7U & (vlTOPp->INSTR_RI 
                                                  >> 0xcU)))) 
                                 & (~ (vlTOPp->INSTR_RI 
                                       >> 0x1eU)));
    vlTOPp->dec__DOT__xor_i_sd = (((0x33U == (0x7fU 
                                              & vlTOPp->INSTR_RI)) 
                                   & (4U == (7U & (vlTOPp->INSTR_RI 
                                                   >> 0xcU)))) 
                                  & (~ (vlTOPp->INSTR_RI 
                                        >> 0x1eU)));
    vlTOPp->dec__DOT__andi_i_sd = ((0x13U == (0x7fU 
                                              & vlTOPp->INSTR_RI)) 
                                   & (7U == (7U & (vlTOPp->INSTR_RI 
                                                   >> 0xcU))));
    vlTOPp->dec__DOT__ori_i_sd = ((0x13U == (0x7fU 
                                             & vlTOPp->INSTR_RI)) 
                                  & (6U == (7U & (vlTOPp->INSTR_RI 
                                                  >> 0xcU))));
    vlTOPp->dec__DOT__xori_i_sd = ((0x13U == (0x7fU 
                                              & vlTOPp->INSTR_RI)) 
                                   & (4U == (7U & (vlTOPp->INSTR_RI 
                                                   >> 0xcU))));
    vlTOPp->dec__DOT__ebreak_i_sd = (((0x73U == (0x7fU 
                                                 & vlTOPp->INSTR_RI)) 
                                      & (0U == (7U 
                                                & (vlTOPp->INSTR_RI 
                                                   >> 0xcU)))) 
                                     & (1U == (0xfffU 
                                               & (vlTOPp->INSTR_RI 
                                                  >> 0x14U))));
    vlTOPp->dec__DOT__sll_i_sd = (((0x33U == (0x7fU 
                                              & vlTOPp->INSTR_RI)) 
                                   & (1U == (7U & (vlTOPp->INSTR_RI 
                                                   >> 0xcU)))) 
                                  & (~ (vlTOPp->INSTR_RI 
                                        >> 0x1eU)));
    vlTOPp->dec__DOT__slli_i_sd = ((0x13U == (0x7fU 
                                              & vlTOPp->INSTR_RI)) 
                                   & (1U == (7U & (vlTOPp->INSTR_RI 
                                                   >> 0xcU))));
    vlTOPp->dec__DOT__ecall_i_sd = (((0x73U == (0x7fU 
                                                & vlTOPp->INSTR_RI)) 
                                     & (0U == (7U & 
                                               (vlTOPp->INSTR_RI 
                                                >> 0xcU)))) 
                                    & (0U == (0xfffU 
                                              & (vlTOPp->INSTR_RI 
                                                 >> 0x14U))));
    vlTOPp->dec__DOT__srl_i_sd = (((0x33U == (0x7fU 
                                              & vlTOPp->INSTR_RI)) 
                                   & (5U == (7U & (vlTOPp->INSTR_RI 
                                                   >> 0xcU)))) 
                                  & (~ (vlTOPp->INSTR_RI 
                                        >> 0x1eU)));
    vlTOPp->dec__DOT__sra_i_sd = (((0x33U == (0x7fU 
                                              & vlTOPp->INSTR_RI)) 
                                   & (5U == (7U & (vlTOPp->INSTR_RI 
                                                   >> 0xcU)))) 
                                  & (vlTOPp->INSTR_RI 
                                     >> 0x1eU));
    vlTOPp->dec__DOT__srli_i_sd = (((0x13U == (0x7fU 
                                               & vlTOPp->INSTR_RI)) 
                                    & (5U == (7U & 
                                              (vlTOPp->INSTR_RI 
                                               >> 0xcU)))) 
                                   & (~ (vlTOPp->INSTR_RI 
                                         >> 0x1eU)));
    vlTOPp->dec__DOT__srai_i_sd = (((0x13U == (0x7fU 
                                               & vlTOPp->INSTR_RI)) 
                                    & (5U == (7U & 
                                              (vlTOPp->INSTR_RI 
                                               >> 0xcU)))) 
                                   & (vlTOPp->INSTR_RI 
                                      >> 0x1eU));
    vlTOPp->dec__DOT__offset_branch_b = ((0xfffff000U 
                                          & ((- (IData)(
                                                        (1U 
                                                         & (vlTOPp->INSTR_RI 
                                                            >> 0x1fU)))) 
                                             << 0xcU)) 
                                         | ((0x800U 
                                             & (vlTOPp->INSTR_RI 
                                                << 4U)) 
                                            | ((0x7e0U 
                                                & (vlTOPp->INSTR_RI 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlTOPp->INSTR_RI 
                                                     >> 7U)))));
    vlTOPp->dec__DOT__offset_branch_j = ((0xfff00000U 
                                          & ((- (IData)(
                                                        (1U 
                                                         & (vlTOPp->INSTR_RI 
                                                            >> 0x1fU)))) 
                                             << 0x14U)) 
                                         | ((0xff000U 
                                             & vlTOPp->INSTR_RI) 
                                            | ((0x800U 
                                                & (vlTOPp->INSTR_RI 
                                                   >> 9U)) 
                                               | (0x7feU 
                                                  & (vlTOPp->INSTR_RI 
                                                     >> 0x14U)))));
    vlTOPp->dec__DOT__beq_i_sd = ((0x63U == (0x7fU 
                                             & vlTOPp->INSTR_RI)) 
                                  & (0U == (7U & (vlTOPp->INSTR_RI 
                                                  >> 0xcU))));
    vlTOPp->dec__DOT__bne_i_sd = ((0x63U == (0x7fU 
                                             & vlTOPp->INSTR_RI)) 
                                  & (1U == (7U & (vlTOPp->INSTR_RI 
                                                  >> 0xcU))));
    vlTOPp->dec__DOT__blt_i_sd = ((0x63U == (0x7fU 
                                             & vlTOPp->INSTR_RI)) 
                                  & (4U == (7U & (vlTOPp->INSTR_RI 
                                                  >> 0xcU))));
    vlTOPp->dec__DOT__bge_i_sd = ((0x63U == (0x7fU 
                                             & vlTOPp->INSTR_RI)) 
                                  & (5U == (7U & (vlTOPp->INSTR_RI 
                                                  >> 0xcU))));
    vlTOPp->dec__DOT__bltu_i_sd = ((0x63U == (0x7fU 
                                              & vlTOPp->INSTR_RI)) 
                                   & (6U == (7U & (vlTOPp->INSTR_RI 
                                                   >> 0xcU))));
    vlTOPp->dec__DOT__bgeu_i_sd = ((0x63U == (0x7fU 
                                              & vlTOPp->INSTR_RI)) 
                                   & (7U == (7U & (vlTOPp->INSTR_RI 
                                                   >> 0xcU))));
    vlTOPp->dec__DOT__jalr_offset = ((0xfffff000U & 
                                      ((- (IData)((1U 
                                                   & (vlTOPp->INSTR_RI 
                                                      >> 0x1fU)))) 
                                       << 0xcU)) | 
                                     (0xfffU & (vlTOPp->INSTR_RI 
                                                >> 0x14U)));
    vlTOPp->dec__DOT__op2_i_type_sd = ((0xfffff000U 
                                        & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->INSTR_RI 
                                                          >> 0x1fU)))) 
                                           << 0xcU)) 
                                       | (0xfffU & 
                                          (vlTOPp->INSTR_RI 
                                           >> 0x14U)));
    vlTOPp->dec__DOT__op2_s_type_sd = ((0xfffff000U 
                                        & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->INSTR_RI 
                                                          >> 0x1fU)))) 
                                           << 0xcU)) 
                                       | ((0xfe0U & 
                                           (vlTOPp->INSTR_RI 
                                            >> 0x14U)) 
                                          | (0x1fU 
                                             & (vlTOPp->INSTR_RI 
                                                >> 7U))));
    vlTOPp->dec__DOT__op1_u_type_sd = (0xfffff000U 
                                       & vlTOPp->INSTR_RI);
    vlTOPp->dec__DOT__op1_csri_type_sd = (0x1fU & (vlTOPp->INSTR_RI 
                                                   >> 0xfU));
    vlTOPp->dec__DOT__csrrw_i_sd = ((0x73U == (0x7fU 
                                               & vlTOPp->INSTR_RI)) 
                                    & (1U == (7U & 
                                              (vlTOPp->INSTR_RI 
                                               >> 0xcU))));
    vlTOPp->dec__DOT__csrrwi_i_sd = ((0x73U == (0x7fU 
                                                & vlTOPp->INSTR_RI)) 
                                     & (5U == (7U & 
                                               (vlTOPp->INSTR_RI 
                                                >> 0xcU))));
    vlTOPp->dec__DOT__u_type_sd = ((0x37U == (0x7fU 
                                              & vlTOPp->INSTR_RI)) 
                                   | (0x17U == (0x7fU 
                                                & vlTOPp->INSTR_RI)));
    vlTOPp->dec__DOT__csrrs_i_sd = ((0x73U == (0x7fU 
                                               & vlTOPp->INSTR_RI)) 
                                    & (2U == (7U & 
                                              (vlTOPp->INSTR_RI 
                                               >> 0xcU))));
    vlTOPp->dec__DOT__csrrc_i_sd = ((0x73U == (0x7fU 
                                               & vlTOPp->INSTR_RI)) 
                                    & (3U == (7U & 
                                              (vlTOPp->INSTR_RI 
                                               >> 0xcU))));
    vlTOPp->dec__DOT__csrrsi_i_sd = ((0x73U == (0x7fU 
                                                & vlTOPp->INSTR_RI)) 
                                     & (6U == (7U & 
                                               (vlTOPp->INSTR_RI 
                                                >> 0xcU))));
    vlTOPp->dec__DOT__csrrci_i_sd = ((0x73U == (0x7fU 
                                                & vlTOPp->INSTR_RI)) 
                                     & (7U == (7U & 
                                               (vlTOPp->INSTR_RI 
                                                >> 0xcU))));
    vlTOPp->dec__DOT__i_type_sd = ((0x13U == (0x7fU 
                                              & vlTOPp->INSTR_RI)) 
                                   | (3U == (0x7fU 
                                             & vlTOPp->INSTR_RI)));
    vlTOPp->dec__DOT__m_type_sd = ((0x33U == (0x7fU 
                                              & vlTOPp->INSTR_RI)) 
                                   & (1U == (0x7fU 
                                             & (vlTOPp->INSTR_RI 
                                                >> 0x19U))));
    vlTOPp->dec__DOT__dec2if_din[2U] = vlTOPp->PC_IF2DEC_RI;
    vlTOPp->dec__DOT__dec2if_din[3U] = ((0xfffffffeU 
                                         & vlTOPp->dec__DOT__dec2if_din[3U]) 
                                        | ((0x63U == 
                                            (0x7fU 
                                             & vlTOPp->INSTR_RI)) 
                                           | (0x6fU 
                                              == (0x7fU 
                                                  & vlTOPp->INSTR_RI))));
    vlTOPp->dec__DOT__dec2if_din[3U] = ((0xfU & vlTOPp->dec__DOT__dec2if_din[3U]) 
                                        | (0xfffffff0U 
                                           & (((IData)(4U) 
                                               + vlTOPp->PC_IF2DEC_RI) 
                                              << 4U)));
    vlTOPp->dec__DOT__dec2if_din[4U] = ((0x30U & vlTOPp->dec__DOT__dec2if_din[4U]) 
                                        | (0xfU & (
                                                   ((IData)(4U) 
                                                    + vlTOPp->PC_IF2DEC_RI) 
                                                   >> 0x1cU)));
    vlTOPp->MEM_LOAD_RD = (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                                 >> 0xdU));
    vlTOPp->DEST_RD = (0x3fU & ((vlTOPp->dec__DOT__dec2exe__DOT__data[1U] 
                                 << 0x1eU) | (vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                                              >> 2U)));
    vlTOPp->CSR_WENABLE_RD = (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[5U] 
                                    >> 0xdU));
    vlTOPp->MULT_INST_RD = (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[7U] 
                                  >> 0x1bU));
    vlTOPp->PRED_SUCCESS_RD = (1U & (vlTOPp->dec__DOT__dec2if__DOT__data[3U] 
                                     >> 1U));
    vlTOPp->PRED_FAILED_RD = (1U & (vlTOPp->dec__DOT__dec2if__DOT__data[3U] 
                                    >> 2U));
    vlTOPp->PC_RD = vlTOPp->dec__DOT__dec2if__DOT__data[0U];
    vlTOPp->ADR_TO_BRANCH_RD = vlTOPp->dec__DOT__dec2if__DOT__data[1U];
    vlTOPp->BRANCH_INST_ADR_RD = vlTOPp->dec__DOT__dec2if__DOT__data[2U];
    vlTOPp->BRANCH_INST_RD = (1U & vlTOPp->dec__DOT__dec2if__DOT__data[3U]);
    vlTOPp->RET_INST_RD = (1U & (vlTOPp->dec__DOT__dec2if__DOT__data[3U] 
                                 >> 3U));
    vlTOPp->ADR_TO_RET_RD = ((vlTOPp->dec__DOT__dec2if__DOT__data[4U] 
                              << 0x1cU) | (vlTOPp->dec__DOT__dec2if__DOT__data[3U] 
                                           >> 4U));
    vlTOPp->POP_ADR_RAS_RD = (1U & (vlTOPp->dec__DOT__dec2if__DOT__data[4U] 
                                    >> 4U));
    vlTOPp->PUSH_ADR_RAS_RD = (1U & (vlTOPp->dec__DOT__dec2if__DOT__data[4U] 
                                     >> 5U));
    vlTOPp->SELECT_OPERATION_RD = ((0xeU & (vlTOPp->dec__DOT__dec2exe__DOT__data[7U] 
                                            >> 0x17U)) 
                                   | (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                                            >> 8U)));
    vlTOPp->PC_BRANCH_VALUE_RD = ((vlTOPp->dec__DOT__dec2exe__DOT__data[7U] 
                                   << 8U) | (vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                                             >> 0x18U));
    vlTOPp->EBREAK_RD = (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                               >> 0x17U));
    vlTOPp->INSTRUCTION_ACCESS_FAULT_RD = (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                                                 >> 0x16U));
    vlTOPp->MRET_RD = (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                             >> 0x15U));
    vlTOPp->EXCEPTION_RD = (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                                  >> 0x14U));
    vlTOPp->ENV_CALL_WRONG_MODE_RD = (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                                            >> 0x13U));
    vlTOPp->ENV_CALL_U_MODE_RD = (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                                        >> 0x12U));
    vlTOPp->ILLEGAL_INSTRUCTION_RD = (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                                            >> 0x11U));
    vlTOPp->ADRESS_MISALIGNED_RD = (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                                          >> 0x10U));
    vlTOPp->ENV_CALL_M_MODE_RD = (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                                        >> 0xfU));
    vlTOPp->ENV_CALL_S_MODE_RD = (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                                        >> 0xeU));
    vlTOPp->CSR_RDATA_RD = ((vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                             << 0x12U) | (vlTOPp->dec__DOT__dec2exe__DOT__data[5U] 
                                          >> 0xeU));
    vlTOPp->CSR_WADR_RD = (0xfffU & ((vlTOPp->dec__DOT__dec2exe__DOT__data[6U] 
                                      << 0x1fU) | (
                                                   vlTOPp->dec__DOT__dec2exe__DOT__data[5U] 
                                                   >> 1U)));
    vlTOPp->PC_DEC2EXE_RD = ((vlTOPp->dec__DOT__dec2exe__DOT__data[5U] 
                              << 0x1fU) | (vlTOPp->dec__DOT__dec2exe__DOT__data[4U] 
                                           >> 1U));
    vlTOPp->BLOCK_BP_RD = (1U & vlTOPp->dec__DOT__dec2exe__DOT__data[4U]);
    vlTOPp->BP_R1_VALID_RD = (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[3U] 
                                    >> 0x1fU));
    vlTOPp->BP_R2_VALID_RD = (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[3U] 
                                    >> 0x1eU));
    vlTOPp->BP_RADR1_RD = (0x3fU & ((vlTOPp->dec__DOT__dec2exe__DOT__data[4U] 
                                     << 8U) | (vlTOPp->dec__DOT__dec2exe__DOT__data[3U] 
                                               >> 0x18U)));
    vlTOPp->BP_RADR2_RD = (0x3fU & ((vlTOPp->dec__DOT__dec2exe__DOT__data[4U] 
                                     << 0xeU) | (vlTOPp->dec__DOT__dec2exe__DOT__data[3U] 
                                                 >> 0x12U)));
    vlTOPp->CMD_RD = (3U & ((vlTOPp->dec__DOT__dec2exe__DOT__data[4U] 
                             << 0x10U) | (vlTOPp->dec__DOT__dec2exe__DOT__data[3U] 
                                          >> 0x10U)));
    vlTOPp->OP1_RD = ((vlTOPp->dec__DOT__dec2exe__DOT__data[3U] 
                       << 0x10U) | (vlTOPp->dec__DOT__dec2exe__DOT__data[2U] 
                                    >> 0x10U));
    vlTOPp->OP2_RD = ((vlTOPp->dec__DOT__dec2exe__DOT__data[2U] 
                       << 0x10U) | (vlTOPp->dec__DOT__dec2exe__DOT__data[1U] 
                                    >> 0x10U));
    vlTOPp->NEG_OP2_RD = (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[1U] 
                                >> 0xfU));
    vlTOPp->WB_RD = (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[1U] 
                           >> 0xeU));
    vlTOPp->MEM_DATA_RD = ((vlTOPp->dec__DOT__dec2exe__DOT__data[1U] 
                            << 0x12U) | (vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                                         >> 0xeU));
    vlTOPp->MEM_STORE_RD = (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                                  >> 0xcU));
    vlTOPp->MEM_SIGN_EXTEND_RD = (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                                        >> 0xbU));
    vlTOPp->MEM_SIZE_RD = (3U & ((vlTOPp->dec__DOT__dec2exe__DOT__data[1U] 
                                  << 0x17U) | (vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                                               >> 9U)));
    vlTOPp->SLT_RD = (1U & (vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                            >> 1U));
    vlTOPp->SLTU_RD = (1U & vlTOPp->dec__DOT__dec2exe__DOT__data[0U]);
    vlTOPp->DEC2IF_EMPTY_SD = (1U & (~ (IData)(vlTOPp->dec__DOT__dec2if__DOT__data_v)));
    vlTOPp->dec__DOT__dec2if_full_sd = (((IData)(vlTOPp->dec__DOT__dec2if__DOT__data_v) 
                                         & (~ (IData)(vlTOPp->DEC2IF_POP_SI)))
                                         ? 1U : 0U);
    vlTOPp->DEC2EXE_EMPTY_SD = (1U & (~ (IData)(vlTOPp->dec__DOT__dec2exe__DOT__data_v)));
    vlTOPp->dec__DOT__env_call_u_mode_sd = ((0U == (IData)(vlTOPp->CURRENT_MODE_SM)) 
                                            & (IData)(vlTOPp->dec__DOT__ecall_i_sd));
    vlTOPp->dec__DOT__env_call_m_mode_sd = ((3U == (IData)(vlTOPp->CURRENT_MODE_SM)) 
                                            & (IData)(vlTOPp->dec__DOT__ecall_i_sd));
    vlTOPp->dec__DOT__csr_radr = (((0x73U == (0x7fU 
                                              & vlTOPp->INSTR_RI)) 
                                   & ((((((IData)(vlTOPp->dec__DOT__csrrw_i_sd) 
                                          | (IData)(vlTOPp->dec__DOT__csrrs_i_sd)) 
                                         | (IData)(vlTOPp->dec__DOT__csrrc_i_sd)) 
                                        | (IData)(vlTOPp->dec__DOT__csrrwi_i_sd)) 
                                       | (IData)(vlTOPp->dec__DOT__csrrsi_i_sd)) 
                                      | (IData)(vlTOPp->dec__DOT__csrrci_i_sd)))
                                   ? (0xfffU & (vlTOPp->INSTR_RI 
                                                >> 0x14U))
                                   : 0U);
    vlTOPp->dec__DOT__rdest_sd = ((((((((0x33U == (0x7fU 
                                                   & vlTOPp->INSTR_RI)) 
                                        | (IData)(vlTOPp->dec__DOT__i_type_sd)) 
                                       | (IData)(vlTOPp->dec__DOT__u_type_sd)) 
                                      | (0x6fU == (0x7fU 
                                                   & vlTOPp->INSTR_RI))) 
                                     | (0x67U == (0x7fU 
                                                  & vlTOPp->INSTR_RI))) 
                                    | (IData)(vlTOPp->dec__DOT__m_type_sd)) 
                                   | ((((((IData)(vlTOPp->dec__DOT__csrrw_i_sd) 
                                          | (IData)(vlTOPp->dec__DOT__csrrs_i_sd)) 
                                         | (IData)(vlTOPp->dec__DOT__csrrc_i_sd)) 
                                        | (IData)(vlTOPp->dec__DOT__csrrwi_i_sd)) 
                                       | (IData)(vlTOPp->dec__DOT__csrrsi_i_sd)) 
                                      | (IData)(vlTOPp->dec__DOT__csrrci_i_sd)))
                                   ? (0x1fU & (vlTOPp->INSTR_RI 
                                               >> 7U))
                                   : 0U);
    vlTOPp->dec__DOT__div_i_sd = ((IData)(vlTOPp->dec__DOT__m_type_sd) 
                                  & (4U == (7U & (vlTOPp->INSTR_RI 
                                                  >> 0xcU))));
    vlTOPp->dec__DOT__divu_i_sd = ((IData)(vlTOPp->dec__DOT__m_type_sd) 
                                   & (5U == (7U & (vlTOPp->INSTR_RI 
                                                   >> 0xcU))));
    vlTOPp->dec__DOT__rem_i_sd = ((IData)(vlTOPp->dec__DOT__m_type_sd) 
                                  & (6U == (7U & (vlTOPp->INSTR_RI 
                                                  >> 0xcU))));
    vlTOPp->dec__DOT__mul_i_sd = ((IData)(vlTOPp->dec__DOT__m_type_sd) 
                                  & (0U == (7U & (vlTOPp->INSTR_RI 
                                                  >> 0xcU))));
    vlTOPp->dec__DOT__mulh_i_sd = ((IData)(vlTOPp->dec__DOT__m_type_sd) 
                                   & (1U == (7U & (vlTOPp->INSTR_RI 
                                                   >> 0xcU))));
    vlTOPp->dec__DOT__mulhsu_i_sd = ((IData)(vlTOPp->dec__DOT__m_type_sd) 
                                     & (2U == (7U & 
                                               (vlTOPp->INSTR_RI 
                                                >> 0xcU))));
    vlTOPp->dec__DOT__mulhu_i_sd = ((IData)(vlTOPp->dec__DOT__m_type_sd) 
                                    & (3U == (7U & 
                                              (vlTOPp->INSTR_RI 
                                               >> 0xcU))));
    vlTOPp->dec__DOT__radr2_sd = (((((0x33U == (0x7fU 
                                                & vlTOPp->INSTR_RI)) 
                                     | (0x23U == (0x7fU 
                                                  & vlTOPp->INSTR_RI))) 
                                    | (0x63U == (0x7fU 
                                                 & vlTOPp->INSTR_RI))) 
                                   | (IData)(vlTOPp->dec__DOT__m_type_sd))
                                   ? (0x1fU & (vlTOPp->INSTR_RI 
                                               >> 0x14U))
                                   : 0U);
    vlTOPp->dec__DOT__radr1_sd = (((((((0x33U == (0x7fU 
                                                  & vlTOPp->INSTR_RI)) 
                                       | (IData)(vlTOPp->dec__DOT__i_type_sd)) 
                                      | (0x23U == (0x7fU 
                                                   & vlTOPp->INSTR_RI))) 
                                     | (0x63U == (0x7fU 
                                                  & vlTOPp->INSTR_RI))) 
                                    | (0x67U == (0x7fU 
                                                 & vlTOPp->INSTR_RI))) 
                                   | (IData)(vlTOPp->dec__DOT__m_type_sd))
                                   ? (0x1fU & (vlTOPp->INSTR_RI 
                                               >> 0xfU))
                                   : 0U);
    vlTOPp->CSR_RADR_SD = vlTOPp->dec__DOT__csr_radr;
    vlTOPp->dec__DOT__rd_link = ((1U == (IData)(vlTOPp->dec__DOT__rdest_sd)) 
                                 | (5U == (IData)(vlTOPp->dec__DOT__rdest_sd)));
    vlTOPp->dec__DOT__select_operation_sd = (((((IData)(vlTOPp->dec__DOT__div_i_sd) 
                                                | (IData)(vlTOPp->dec__DOT__divu_i_sd)) 
                                               | (IData)(vlTOPp->dec__DOT__rem_i_sd)) 
                                              | ((IData)(vlTOPp->dec__DOT__m_type_sd) 
                                                 & (7U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->INSTR_RI 
                                                        >> 0xcU)))))
                                              ? 8U : 
                                             (((((IData)(vlTOPp->dec__DOT__mul_i_sd) 
                                                 | (IData)(vlTOPp->dec__DOT__mulh_i_sd)) 
                                                | (IData)(vlTOPp->dec__DOT__mulhsu_i_sd)) 
                                               | (IData)(vlTOPp->dec__DOT__mulhu_i_sd))
                                               ? 4U
                                               : ((
                                                   (((((IData)(vlTOPp->dec__DOT__sll_i_sd) 
                                                       | (IData)(vlTOPp->dec__DOT__slli_i_sd)) 
                                                      | (IData)(vlTOPp->dec__DOT__srl_i_sd)) 
                                                     | (IData)(vlTOPp->dec__DOT__srli_i_sd)) 
                                                    | (IData)(vlTOPp->dec__DOT__sra_i_sd)) 
                                                   | (IData)(vlTOPp->dec__DOT__srai_i_sd))
                                                   ? 2U
                                                   : 1U)));
    vlTOPp->dec__DOT__illegal_inst = (1U & (~ (((((
                                                   (((((((((((((((((((((((((((((((((((((((((((((((((0x33U 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlTOPp->INSTR_RI)) 
                                                                                & (0U 
                                                                                == 
                                                                                (7U 
                                                                                & (vlTOPp->INSTR_RI 
                                                                                >> 0xcU)))) 
                                                                                & (~ 
                                                                                (vlTOPp->INSTR_RI 
                                                                                >> 0x1eU))) 
                                                                                | (IData)(vlTOPp->dec__DOT__sub_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__slt_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__sltu_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__and_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__or_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__xor_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__sll_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__srl_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__sra_i_sd)) 
                                                                                | ((0x13U 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlTOPp->INSTR_RI)) 
                                                                                & (0U 
                                                                                == 
                                                                                (7U 
                                                                                & (vlTOPp->INSTR_RI 
                                                                                >> 0xcU))))) 
                                                                                | (IData)(vlTOPp->dec__DOT__slti_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__sltiu_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__andi_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__ori_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__xori_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__slli_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__srli_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__srai_i_sd)) 
                                                                               | (IData)(vlTOPp->dec__DOT__beq_i_sd)) 
                                                                              | (IData)(vlTOPp->dec__DOT__bne_i_sd)) 
                                                                             | (IData)(vlTOPp->dec__DOT__blt_i_sd)) 
                                                                            | (IData)(vlTOPp->dec__DOT__bge_i_sd)) 
                                                                           | (IData)(vlTOPp->dec__DOT__bltu_i_sd)) 
                                                                          | (IData)(vlTOPp->dec__DOT__bgeu_i_sd)) 
                                                                         | (IData)(vlTOPp->dec__DOT__u_type_sd)) 
                                                                        | (0x1bU 
                                                                           == 
                                                                           (0x7fU 
                                                                            & vlTOPp->INSTR_RI))) 
                                                                       | (0x6fU 
                                                                          == 
                                                                          (0x7fU 
                                                                           & vlTOPp->INSTR_RI))) 
                                                                      | (0x67U 
                                                                         == 
                                                                         (0x7fU 
                                                                          & vlTOPp->INSTR_RI))) 
                                                                     | (IData)(vlTOPp->dec__DOT__lw_i_sd)) 
                                                                    | (IData)(vlTOPp->dec__DOT__lh_i_sd)) 
                                                                   | (IData)(vlTOPp->dec__DOT__lhu_i_sd)) 
                                                                  | (IData)(vlTOPp->dec__DOT__lb_i_sd)) 
                                                                 | (IData)(vlTOPp->dec__DOT__lbu_i_sd)) 
                                                                | (IData)(vlTOPp->dec__DOT__sw_i_sd)) 
                                                               | (IData)(vlTOPp->dec__DOT__sh_i_sd)) 
                                                              | (IData)(vlTOPp->dec__DOT__sb_i_sd)) 
                                                             | (IData)(vlTOPp->dec__DOT__mul_i_sd)) 
                                                            | (IData)(vlTOPp->dec__DOT__mulh_i_sd)) 
                                                           | (IData)(vlTOPp->dec__DOT__mulhu_i_sd)) 
                                                          | (IData)(vlTOPp->dec__DOT__mulhsu_i_sd)) 
                                                         | (IData)(vlTOPp->dec__DOT__ecall_i_sd)) 
                                                        | (IData)(vlTOPp->dec__DOT__ebreak_i_sd)) 
                                                       | (IData)(vlTOPp->dec__DOT__csrrw_i_sd)) 
                                                      | (IData)(vlTOPp->dec__DOT__csrrs_i_sd)) 
                                                     | (IData)(vlTOPp->dec__DOT__csrrc_i_sd)) 
                                                    | (IData)(vlTOPp->dec__DOT__csrrwi_i_sd)) 
                                                   | (IData)(vlTOPp->dec__DOT__csrrsi_i_sd)) 
                                                  | (IData)(vlTOPp->dec__DOT__csrrci_i_sd)) 
                                                 | (0x30200073U 
                                                    == vlTOPp->INSTR_RI)) 
                                                | (0x10200073U 
                                                   == vlTOPp->INSTR_RI)) 
                                               | ((0xfU 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->INSTR_RI)) 
                                                  & (0U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->INSTR_RI 
                                                         >> 0xcU)))))));
    vlTOPp->REG_ADR2_SD = vlTOPp->dec__DOT__radr2_sd;
    vlTOPp->dec__DOT__bpc_ed2 = ((((IData)(vlTOPp->dec__DOT__radr2_sd) 
                                   == (IData)(vlTOPp->BP_DEST_RE)) 
                                  & (~ (IData)(vlTOPp->BP_EXE2MEM_EMPTY_SE))) 
                                 & (0U != (IData)(vlTOPp->dec__DOT__radr2_sd)));
    vlTOPp->dec__DOT__bpc_md2 = ((((IData)(vlTOPp->dec__DOT__radr2_sd) 
                                   == (IData)(vlTOPp->BP_DEST_RM)) 
                                  & (~ (IData)(vlTOPp->BP_MEM2WBK_EMPTY_SM))) 
                                 & (0U != (IData)(vlTOPp->dec__DOT__radr2_sd)));
    vlTOPp->dec__DOT__r2_valid_sd = (1U & ((((~ ((((IData)(vlTOPp->dec__DOT__radr2_sd) 
                                                   == 
                                                   (0x3fU 
                                                    & ((vlTOPp->dec__DOT__dec2exe__DOT__data[1U] 
                                                        << 0x1eU) 
                                                       | (vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                                                          >> 2U)))) 
                                                  & (IData)(vlTOPp->dec__DOT__dec2exe__DOT__data_v)) 
                                                 & (0U 
                                                    != (IData)(vlTOPp->dec__DOT__radr2_sd)))) 
                                             & (~ (
                                                   ((((IData)(vlTOPp->dec__DOT__radr2_sd) 
                                                      == (IData)(vlTOPp->BP_DEST_RE)) 
                                                     & (IData)(vlTOPp->BP_MEM_LOAD_RE)) 
                                                    & (0U 
                                                       != (IData)(vlTOPp->dec__DOT__radr2_sd))) 
                                                   & (~ (IData)(vlTOPp->BP_EXE2MEM_EMPTY_SE))))) 
                                            & (~ ((
                                                   ((IData)(vlTOPp->dec__DOT__radr2_sd) 
                                                    == (IData)(vlTOPp->BP_DEST_RE)) 
                                                   & (IData)(vlTOPp->MULT_INST_RE)) 
                                                  & (~ (IData)(vlTOPp->BP_EXE2MEM_EMPTY_SE))))) 
                                           & (~ ((((IData)(vlTOPp->dec__DOT__radr2_sd) 
                                                   == (IData)(vlTOPp->BP_DEST_RM)) 
                                                  & (IData)(vlTOPp->MULT_INST_RM)) 
                                                 & (~ (IData)(vlTOPp->BP_MEM2WBK_EMPTY_SM))))));
    vlTOPp->REG_ADR1_SD = vlTOPp->dec__DOT__radr1_sd;
    vlTOPp->dec__DOT__rs1_link = ((1U == (IData)(vlTOPp->dec__DOT__radr1_sd)) 
                                  | (5U == (IData)(vlTOPp->dec__DOT__radr1_sd)));
    vlTOPp->dec__DOT__bpc_ed1 = ((((IData)(vlTOPp->dec__DOT__radr1_sd) 
                                   == (IData)(vlTOPp->BP_DEST_RE)) 
                                  & (~ (IData)(vlTOPp->BP_EXE2MEM_EMPTY_SE))) 
                                 & (0U != (IData)(vlTOPp->dec__DOT__radr1_sd)));
    vlTOPp->dec__DOT__bpc_md1 = ((((IData)(vlTOPp->dec__DOT__radr1_sd) 
                                   == (IData)(vlTOPp->BP_DEST_RM)) 
                                  & (~ (IData)(vlTOPp->BP_MEM2WBK_EMPTY_SM))) 
                                 & (0U != (IData)(vlTOPp->dec__DOT__radr1_sd)));
    vlTOPp->dec__DOT__r1_valid_sd = (1U & ((((~ ((((IData)(vlTOPp->dec__DOT__radr1_sd) 
                                                   == 
                                                   (0x3fU 
                                                    & ((vlTOPp->dec__DOT__dec2exe__DOT__data[1U] 
                                                        << 0x1eU) 
                                                       | (vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                                                          >> 2U)))) 
                                                  & (IData)(vlTOPp->dec__DOT__dec2exe__DOT__data_v)) 
                                                 & (0U 
                                                    != (IData)(vlTOPp->dec__DOT__radr1_sd)))) 
                                             & (~ (
                                                   ((((IData)(vlTOPp->dec__DOT__radr1_sd) 
                                                      == (IData)(vlTOPp->BP_DEST_RE)) 
                                                     & (IData)(vlTOPp->BP_MEM_LOAD_RE)) 
                                                    & (0U 
                                                       != (IData)(vlTOPp->dec__DOT__radr1_sd))) 
                                                   & (~ (IData)(vlTOPp->BP_EXE2MEM_EMPTY_SE))))) 
                                            & (~ ((
                                                   ((IData)(vlTOPp->dec__DOT__radr1_sd) 
                                                    == (IData)(vlTOPp->BP_DEST_RE)) 
                                                   & (IData)(vlTOPp->MULT_INST_RE)) 
                                                  & (~ (IData)(vlTOPp->BP_EXE2MEM_EMPTY_SE))))) 
                                           & (~ ((((IData)(vlTOPp->dec__DOT__radr1_sd) 
                                                   == (IData)(vlTOPp->BP_DEST_RM)) 
                                                  & (IData)(vlTOPp->MULT_INST_RM)) 
                                                 & (~ (IData)(vlTOPp->BP_MEM2WBK_EMPTY_SM))))));
    vlTOPp->dec__DOT__dec2if_din[4U] = ((0x1fU & vlTOPp->dec__DOT__dec2if_din[4U]) 
                                        | (0xffffffe0U 
                                           & (((IData)(vlTOPp->dec__DOT__rd_link) 
                                               & ((0x6fU 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->INSTR_RI)) 
                                                  | (0x67U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->INSTR_RI)))) 
                                              << 5U)));
    vlTOPp->dec__DOT__illegal_inst_sd = ((IData)(vlTOPp->dec__DOT__illegal_inst) 
                                         & (~ (IData)(vlTOPp->IF2DEC_EMPTY_SI)));
    vlTOPp->dec__DOT__rdata2_sd = (((IData)(vlTOPp->dec__DOT__bpc_ed2) 
                                    & (~ (IData)(vlTOPp->CSR_WENABLE_RE)))
                                    ? vlTOPp->BP_EXE_RES_RE
                                    : (((IData)(vlTOPp->dec__DOT__bpc_ed2) 
                                        & (IData)(vlTOPp->CSR_WENABLE_RE))
                                        ? vlTOPp->CSR_RDATA_RE
                                        : (((IData)(vlTOPp->dec__DOT__bpc_md2) 
                                            & (~ (IData)(vlTOPp->CSR_WENABLE_RM)))
                                            ? vlTOPp->BP_MEM_RES_RM
                                            : (((IData)(vlTOPp->dec__DOT__bpc_md2) 
                                                & (IData)(vlTOPp->CSR_WENABLE_RM))
                                                ? vlTOPp->CSR_RDATA_RM
                                                : vlTOPp->RDATA2_SR))));
    vlTOPp->dec__DOT__dec2if_din[4U] = ((0x2fU & vlTOPp->dec__DOT__dec2if_din[4U]) 
                                        | (0xfffffff0U 
                                           & (((~ (IData)(vlTOPp->PRED_TAKEN_RI)) 
                                               & (((~ (IData)(vlTOPp->dec__DOT__rd_link)) 
                                                   & (IData)(vlTOPp->dec__DOT__rs1_link)) 
                                                  | (((IData)(vlTOPp->dec__DOT__rd_link) 
                                                      & (IData)(vlTOPp->dec__DOT__rs1_link)) 
                                                     & ((IData)(vlTOPp->dec__DOT__rdest_sd) 
                                                        != (IData)(vlTOPp->dec__DOT__radr1_sd))))) 
                                              << 4U)));
    vlTOPp->dec__DOT__rdata1_sd = (((IData)(vlTOPp->dec__DOT__bpc_ed1) 
                                    & (~ (IData)(vlTOPp->CSR_WENABLE_RE)))
                                    ? vlTOPp->BP_EXE_RES_RE
                                    : (((IData)(vlTOPp->dec__DOT__bpc_ed1) 
                                        & (IData)(vlTOPp->CSR_WENABLE_RE))
                                        ? vlTOPp->CSR_RDATA_RE
                                        : (((IData)(vlTOPp->dec__DOT__bpc_md1) 
                                            & (~ (IData)(vlTOPp->CSR_WENABLE_RM)))
                                            ? vlTOPp->BP_MEM_RES_RM
                                            : (((IData)(vlTOPp->dec__DOT__bpc_md1) 
                                                & (IData)(vlTOPp->CSR_WENABLE_RM))
                                                ? vlTOPp->CSR_RDATA_RM
                                                : vlTOPp->RDATA1_SR))));
    vlTOPp->dec__DOT__stall_sd = (1U & ((((((vlTOPp->dec__DOT__dec2exe__DOT__data[5U] 
                                             >> 0xdU) 
                                            & (IData)(vlTOPp->dec__DOT__dec2exe__DOT__data_v)) 
                                           | ((IData)(vlTOPp->CSR_WENABLE_RE) 
                                              & (~ (IData)(vlTOPp->BP_EXE2MEM_EMPTY_SE)))) 
                                          | (((~ (IData)(vlTOPp->dec__DOT__r1_valid_sd)) 
                                              | (~ (IData)(vlTOPp->dec__DOT__r2_valid_sd))) 
                                             & (((((0x63U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->INSTR_RI)) 
                                                   | (0x67U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->INSTR_RI))) 
                                                  | (0x6fU 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->INSTR_RI))) 
                                                 | (((((IData)(vlTOPp->dec__DOT__radr1_sd) 
                                                       == 
                                                       (0x3fU 
                                                        & ((vlTOPp->dec__DOT__dec2exe__DOT__data[1U] 
                                                            << 0x1eU) 
                                                           | (vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                                                              >> 2U)))) 
                                                      | ((IData)(vlTOPp->dec__DOT__radr2_sd) 
                                                         == 
                                                         (0x3fU 
                                                          & ((vlTOPp->dec__DOT__dec2exe__DOT__data[1U] 
                                                              << 0x1eU) 
                                                             | (vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                                                                >> 2U))))) 
                                                     & (vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                                                        >> 0xdU)) 
                                                    & (IData)(vlTOPp->dec__DOT__dec2exe__DOT__data_v))) 
                                                | (((((((((IData)(vlTOPp->dec__DOT__radr1_sd) 
                                                          == 
                                                          (0x3fU 
                                                           & ((vlTOPp->dec__DOT__dec2exe__DOT__data[1U] 
                                                               << 0x1eU) 
                                                              | (vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                                                                 >> 2U)))) 
                                                         | ((IData)(vlTOPp->dec__DOT__radr2_sd) 
                                                            == 
                                                            (0x3fU 
                                                             & ((vlTOPp->dec__DOT__dec2exe__DOT__data[1U] 
                                                                 << 0x1eU) 
                                                                | (vlTOPp->dec__DOT__dec2exe__DOT__data[0U] 
                                                                   >> 2U))))) 
                                                        & (vlTOPp->dec__DOT__dec2exe__DOT__data[7U] 
                                                           >> 0x1bU)) 
                                                       & (IData)(vlTOPp->dec__DOT__dec2exe__DOT__data_v)) 
                                                      | ((((IData)(vlTOPp->dec__DOT__radr1_sd) 
                                                           == (IData)(vlTOPp->BP_DEST_RE)) 
                                                          & (IData)(vlTOPp->MULT_INST_RE)) 
                                                         & (~ (IData)(vlTOPp->BP_EXE2MEM_EMPTY_SE)))) 
                                                     | ((((IData)(vlTOPp->dec__DOT__radr2_sd) 
                                                          == (IData)(vlTOPp->BP_DEST_RE)) 
                                                         & (IData)(vlTOPp->MULT_INST_RE)) 
                                                        & (~ (IData)(vlTOPp->BP_EXE2MEM_EMPTY_SE)))) 
                                                    | ((((IData)(vlTOPp->dec__DOT__radr1_sd) 
                                                         == (IData)(vlTOPp->BP_DEST_RM)) 
                                                        & (IData)(vlTOPp->MULT_INST_RM)) 
                                                       & (~ (IData)(vlTOPp->BP_MEM2WBK_EMPTY_SM)))) 
                                                   | ((((IData)(vlTOPp->dec__DOT__radr2_sd) 
                                                        == (IData)(vlTOPp->BP_DEST_RM)) 
                                                       & (IData)(vlTOPp->MULT_INST_RM)) 
                                                      & (~ (IData)(vlTOPp->BP_MEM2WBK_EMPTY_SM))))))) 
                                         | (IData)(vlTOPp->IF2DEC_EMPTY_SI)) 
                                        | (((IData)(vlTOPp->dec__DOT__dec2exe__DOT__data_v) 
                                            & (~ (IData)(vlTOPp->DEC2EXE_POP_SE)))
                                            ? 1U : 0U)));
    vlTOPp->dec__DOT__dec2exe_op2_sd = (((((0x33U == 
                                            (0x7fU 
                                             & vlTOPp->INSTR_RI)) 
                                           | (0x63U 
                                              == (0x7fU 
                                                  & vlTOPp->INSTR_RI))) 
                                          | ((IData)(vlTOPp->dec__DOT__u_type_sd) 
                                             & (0x1bU 
                                                != 
                                                (0x7fU 
                                                 & vlTOPp->INSTR_RI)))) 
                                         | (IData)(vlTOPp->dec__DOT__m_type_sd))
                                         ? vlTOPp->dec__DOT__rdata2_sd
                                         : (((((IData)(vlTOPp->dec__DOT__csrrs_i_sd) 
                                               | (IData)(vlTOPp->dec__DOT__csrrc_i_sd)) 
                                              | (IData)(vlTOPp->dec__DOT__csrrsi_i_sd)) 
                                             | (IData)(vlTOPp->dec__DOT__csrrci_i_sd))
                                             ? vlTOPp->CSR_RDATA_SC
                                             : ((IData)(vlTOPp->dec__DOT__i_type_sd)
                                                 ? vlTOPp->dec__DOT__op2_i_type_sd
                                                 : 
                                                ((0x23U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->INSTR_RI))
                                                  ? vlTOPp->dec__DOT__op2_s_type_sd
                                                  : 
                                                 ((0x1bU 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->INSTR_RI))
                                                   ? vlTOPp->PC_IF2DEC_RI
                                                   : 0U)))));
    vlTOPp->dec__DOT__offset_branch_jalr = (0xfffffffeU 
                                            & ((IData)(4U) 
                                               + ((vlTOPp->dec__DOT__jalr_offset 
                                                   + vlTOPp->dec__DOT__rdata1_sd) 
                                                  - vlTOPp->READ_PC_SR)));
    vlTOPp->dec__DOT__dec2exe_op1_sd = ((((((((0x33U 
                                               == (0x7fU 
                                                   & vlTOPp->INSTR_RI)) 
                                              | (IData)(vlTOPp->dec__DOT__i_type_sd)) 
                                             | (0x23U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->INSTR_RI))) 
                                            | (0x63U 
                                               == (0x7fU 
                                                   & vlTOPp->INSTR_RI))) 
                                           | (IData)(vlTOPp->dec__DOT__csrrw_i_sd)) 
                                          | (IData)(vlTOPp->dec__DOT__csrrs_i_sd)) 
                                         | (IData)(vlTOPp->dec__DOT__m_type_sd))
                                         ? vlTOPp->dec__DOT__rdata1_sd
                                         : ((IData)(vlTOPp->dec__DOT__csrrc_i_sd)
                                             ? (~ vlTOPp->dec__DOT__rdata1_sd)
                                             : (((IData)(vlTOPp->dec__DOT__csrrwi_i_sd) 
                                                 | (IData)(vlTOPp->dec__DOT__csrrsi_i_sd))
                                                 ? vlTOPp->dec__DOT__op1_csri_type_sd
                                                 : 
                                                ((IData)(vlTOPp->dec__DOT__csrrci_i_sd)
                                                  ? 
                                                 (~ vlTOPp->dec__DOT__op1_csri_type_sd)
                                                  : 
                                                 ((IData)(vlTOPp->dec__DOT__u_type_sd)
                                                   ? vlTOPp->dec__DOT__op1_u_type_sd
                                                   : 
                                                  (((0x6fU 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->INSTR_RI)) 
                                                    | (0x67U 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->INSTR_RI)))
                                                    ? vlTOPp->READ_PC_SR
                                                    : 0U))))));
    vlTOPp->IF2DEC_POP_SD = (1U & (~ (IData)(vlTOPp->dec__DOT__stall_sd)));
    vlTOPp->dec__DOT__offset_branch_sd = ((0x63U == 
                                           (0x7fU & vlTOPp->INSTR_RI))
                                           ? vlTOPp->dec__DOT__offset_branch_b
                                           : ((0x6fU 
                                               == (0x7fU 
                                                   & vlTOPp->INSTR_RI))
                                               ? vlTOPp->dec__DOT__offset_branch_j
                                               : ((0x67U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->INSTR_RI))
                                                   ? vlTOPp->dec__DOT__offset_branch_jalr
                                                   : 0U)));
    __Vtemp4[0U] = (IData)((((QData)((IData)((((((IData)(vlTOPp->dec__DOT__sub_i_sd) 
                                                 | (IData)(vlTOPp->dec__DOT__slt_i_sd)) 
                                                | (IData)(vlTOPp->dec__DOT__slti_i_sd)) 
                                               | (IData)(vlTOPp->dec__DOT__sltu_i_sd)) 
                                              | (IData)(vlTOPp->dec__DOT__sltiu_i_sd)))) 
                             << 0x2fU) | (((QData)((IData)(
                                                           ((((((((((((0x33U 
                                                                       == 
                                                                       (0x7fU 
                                                                        & vlTOPp->INSTR_RI)) 
                                                                      | (IData)(vlTOPp->dec__DOT__i_type_sd)) 
                                                                     | (IData)(vlTOPp->dec__DOT__u_type_sd)) 
                                                                    | (0x63U 
                                                                       == 
                                                                       (0x7fU 
                                                                        & vlTOPp->INSTR_RI))) 
                                                                   | (0x6fU 
                                                                      == 
                                                                      (0x7fU 
                                                                       & vlTOPp->INSTR_RI))) 
                                                                  | (0x67U 
                                                                     == 
                                                                     (0x7fU 
                                                                      & vlTOPp->INSTR_RI))) 
                                                                 | (IData)(vlTOPp->dec__DOT__csrrw_i_sd)) 
                                                                | (IData)(vlTOPp->dec__DOT__csrrs_i_sd)) 
                                                               | (IData)(vlTOPp->dec__DOT__csrrc_i_sd)) 
                                                              | (IData)(vlTOPp->dec__DOT__csrrwi_i_sd)) 
                                                             | (IData)(vlTOPp->dec__DOT__csrrsi_i_sd)) 
                                                            | (IData)(vlTOPp->dec__DOT__csrrci_i_sd)))) 
                                           << 0x2eU) 
                                          | (((QData)((IData)(
                                                              ((0x23U 
                                                                == 
                                                                (0x7fU 
                                                                 & vlTOPp->INSTR_RI))
                                                                ? vlTOPp->dec__DOT__rdata2_sd
                                                                : 0U))) 
                                              << 0xeU) 
                                             | (QData)((IData)(
                                                               (((((((IData)(vlTOPp->dec__DOT__lw_i_sd) 
                                                                     | (IData)(vlTOPp->dec__DOT__lh_i_sd)) 
                                                                    | (IData)(vlTOPp->dec__DOT__lhu_i_sd)) 
                                                                   | (IData)(vlTOPp->dec__DOT__lb_i_sd)) 
                                                                  | (IData)(vlTOPp->dec__DOT__lbu_i_sd)) 
                                                                 << 0xdU) 
                                                                | (((((IData)(vlTOPp->dec__DOT__sw_i_sd) 
                                                                      | (IData)(vlTOPp->dec__DOT__sh_i_sd)) 
                                                                     | (IData)(vlTOPp->dec__DOT__sb_i_sd)) 
                                                                    << 0xcU) 
                                                                   | ((((IData)(vlTOPp->dec__DOT__lh_i_sd) 
                                                                        | (IData)(vlTOPp->dec__DOT__lb_i_sd)) 
                                                                       << 0xbU) 
                                                                      | (((((IData)(vlTOPp->dec__DOT__lw_i_sd) 
                                                                            | (IData)(vlTOPp->dec__DOT__sw_i_sd))
                                                                            ? 0U
                                                                            : 
                                                                           ((((IData)(vlTOPp->dec__DOT__lh_i_sd) 
                                                                              | (IData)(vlTOPp->dec__DOT__lhu_i_sd)) 
                                                                             | (IData)(vlTOPp->dec__DOT__sh_i_sd))
                                                                             ? 1U
                                                                             : 
                                                                            ((((IData)(vlTOPp->dec__DOT__lb_i_sd) 
                                                                               | (IData)(vlTOPp->dec__DOT__lbu_i_sd)) 
                                                                              | (IData)(vlTOPp->dec__DOT__sb_i_sd))
                                                                              ? 2U
                                                                              : 3U))) 
                                                                          << 9U) 
                                                                         | ((0x100U 
                                                                             & ((IData)(vlTOPp->dec__DOT__select_operation_sd) 
                                                                                << 8U)) 
                                                                            | (((IData)(vlTOPp->dec__DOT__rdest_sd) 
                                                                                << 2U) 
                                                                               | ((((IData)(vlTOPp->dec__DOT__slt_i_sd) 
                                                                                | (IData)(vlTOPp->dec__DOT__slti_i_sd)) 
                                                                                << 1U) 
                                                                                | ((IData)(vlTOPp->dec__DOT__sltu_i_sd) 
                                                                                | (IData)(vlTOPp->dec__DOT__sltiu_i_sd)))))))))))))));
    __Vtemp4[1U] = ((0xffff0000U & ((IData)((((QData)((IData)(vlTOPp->dec__DOT__dec2exe_op1_sd)) 
                                              << 0x20U) 
                                             | (QData)((IData)(vlTOPp->dec__DOT__dec2exe_op2_sd)))) 
                                    << 0x10U)) | (IData)(
                                                         ((((QData)((IData)(
                                                                            (((((IData)(vlTOPp->dec__DOT__sub_i_sd) 
                                                                                | (IData)(vlTOPp->dec__DOT__slt_i_sd)) 
                                                                               | (IData)(vlTOPp->dec__DOT__slti_i_sd)) 
                                                                              | (IData)(vlTOPp->dec__DOT__sltu_i_sd)) 
                                                                             | (IData)(vlTOPp->dec__DOT__sltiu_i_sd)))) 
                                                            << 0x2fU) 
                                                           | (((QData)((IData)(
                                                                               ((((((((((((0x33U 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlTOPp->INSTR_RI)) 
                                                                                | (IData)(vlTOPp->dec__DOT__i_type_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__u_type_sd)) 
                                                                                | (0x63U 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlTOPp->INSTR_RI))) 
                                                                                | (0x6fU 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlTOPp->INSTR_RI))) 
                                                                                | (0x67U 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlTOPp->INSTR_RI))) 
                                                                                | (IData)(vlTOPp->dec__DOT__csrrw_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__csrrs_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__csrrc_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__csrrwi_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__csrrsi_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__csrrci_i_sd)))) 
                                                               << 0x2eU) 
                                                              | (((QData)((IData)(
                                                                                ((0x23U 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlTOPp->INSTR_RI))
                                                                                 ? vlTOPp->dec__DOT__rdata2_sd
                                                                                 : 0U))) 
                                                                  << 0xeU) 
                                                                 | (QData)((IData)(
                                                                                (((((((IData)(vlTOPp->dec__DOT__lw_i_sd) 
                                                                                | (IData)(vlTOPp->dec__DOT__lh_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__lhu_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__lb_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__lbu_i_sd)) 
                                                                                << 0xdU) 
                                                                                | (((((IData)(vlTOPp->dec__DOT__sw_i_sd) 
                                                                                | (IData)(vlTOPp->dec__DOT__sh_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__sb_i_sd)) 
                                                                                << 0xcU) 
                                                                                | ((((IData)(vlTOPp->dec__DOT__lh_i_sd) 
                                                                                | (IData)(vlTOPp->dec__DOT__lb_i_sd)) 
                                                                                << 0xbU) 
                                                                                | (((((IData)(vlTOPp->dec__DOT__lw_i_sd) 
                                                                                | (IData)(vlTOPp->dec__DOT__sw_i_sd))
                                                                                 ? 0U
                                                                                 : 
                                                                                ((((IData)(vlTOPp->dec__DOT__lh_i_sd) 
                                                                                | (IData)(vlTOPp->dec__DOT__lhu_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__sh_i_sd))
                                                                                 ? 1U
                                                                                 : 
                                                                                ((((IData)(vlTOPp->dec__DOT__lb_i_sd) 
                                                                                | (IData)(vlTOPp->dec__DOT__lbu_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__sb_i_sd))
                                                                                 ? 2U
                                                                                 : 3U))) 
                                                                                << 9U) 
                                                                                | ((0x100U 
                                                                                & ((IData)(vlTOPp->dec__DOT__select_operation_sd) 
                                                                                << 8U)) 
                                                                                | (((IData)(vlTOPp->dec__DOT__rdest_sd) 
                                                                                << 2U) 
                                                                                | ((((IData)(vlTOPp->dec__DOT__slt_i_sd) 
                                                                                | (IData)(vlTOPp->dec__DOT__slti_i_sd)) 
                                                                                << 1U) 
                                                                                | ((IData)(vlTOPp->dec__DOT__sltu_i_sd) 
                                                                                | (IData)(vlTOPp->dec__DOT__sltiu_i_sd)))))))))))))) 
                                                          >> 0x20U)));
    vlTOPp->dec__DOT__dec2exe_data[0U] = __Vtemp4[0U];
    vlTOPp->dec__DOT__dec2exe_data[1U] = __Vtemp4[1U];
    vlTOPp->dec__DOT__dec2exe_data[2U] = ((0xffffU 
                                           & ((IData)(
                                                      (((QData)((IData)(vlTOPp->dec__DOT__dec2exe_op1_sd)) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(vlTOPp->dec__DOT__dec2exe_op2_sd)))) 
                                              >> 0x10U)) 
                                          | (0xffff0000U 
                                             & ((IData)(
                                                        ((((QData)((IData)(vlTOPp->dec__DOT__dec2exe_op1_sd)) 
                                                           << 0x20U) 
                                                          | (QData)((IData)(vlTOPp->dec__DOT__dec2exe_op2_sd))) 
                                                         >> 0x20U)) 
                                                << 0x10U)));
    vlTOPp->dec__DOT__dec2exe_data[3U] = ((0xffff0000U 
                                           & vlTOPp->dec__DOT__dec2exe_data[3U]) 
                                          | (0xffffU 
                                             & ((IData)(
                                                        ((((QData)((IData)(vlTOPp->dec__DOT__dec2exe_op1_sd)) 
                                                           << 0x20U) 
                                                          | (QData)((IData)(vlTOPp->dec__DOT__dec2exe_op2_sd))) 
                                                         >> 0x20U)) 
                                                >> 0x10U)));
    vlTOPp->dec__DOT__res = (vlTOPp->dec__DOT__dec2exe_op1_sd 
                             ^ vlTOPp->dec__DOT__dec2exe_op2_sd);
    vlTOPp->dec__DOT__res_compare = (vlTOPp->dec__DOT__dec2exe_op1_sd 
                                     - vlTOPp->dec__DOT__dec2exe_op2_sd);
    vlTOPp->dec__DOT__different_sign = (1U & ((vlTOPp->dec__DOT__dec2exe_op1_sd 
                                               ^ vlTOPp->dec__DOT__dec2exe_op2_sd) 
                                              >> 0x1fU));
    vlTOPp->dec__DOT__dec2if_din[3U] = ((0xfffffff7U 
                                         & vlTOPp->dec__DOT__dec2if_din[3U]) 
                                        | (0xfffffff8U 
                                           & (((((0x67U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->INSTR_RI)) 
                                                 & (0U 
                                                    == (IData)(vlTOPp->dec__DOT__rdest_sd))) 
                                                & (4U 
                                                   == vlTOPp->dec__DOT__offset_branch_sd)) 
                                               & (1U 
                                                  == (IData)(vlTOPp->dec__DOT__radr1_sd))) 
                                              << 3U)));
    vlTOPp->dec__DOT__branch_adr_sd = (vlTOPp->PC_IF2DEC_RI 
                                       + vlTOPp->dec__DOT__offset_branch_sd);
    vlTOPp->dec__DOT__jump_sd = ((0x63U == (0x7fU & vlTOPp->INSTR_RI))
                                  ? (((((((IData)(vlTOPp->dec__DOT__bne_i_sd) 
                                          & (0U != vlTOPp->dec__DOT__res)) 
                                         | ((IData)(vlTOPp->dec__DOT__beq_i_sd) 
                                            & (0U == vlTOPp->dec__DOT__res))) 
                                        | ((IData)(vlTOPp->dec__DOT__blt_i_sd) 
                                           & (((IData)(vlTOPp->dec__DOT__different_sign) 
                                               & (vlTOPp->dec__DOT__dec2exe_op1_sd 
                                                  >> 0x1fU)) 
                                              | ((~ (IData)(vlTOPp->dec__DOT__different_sign)) 
                                                 & (vlTOPp->dec__DOT__res_compare 
                                                    >> 0x1fU))))) 
                                       | ((IData)(vlTOPp->dec__DOT__bltu_i_sd) 
                                          & (((IData)(vlTOPp->dec__DOT__different_sign) 
                                              & (vlTOPp->dec__DOT__dec2exe_op2_sd 
                                                 >> 0x1fU)) 
                                             | ((~ (IData)(vlTOPp->dec__DOT__different_sign)) 
                                                & (vlTOPp->dec__DOT__res_compare 
                                                   >> 0x1fU))))) 
                                      | ((IData)(vlTOPp->dec__DOT__bge_i_sd) 
                                         & (((IData)(vlTOPp->dec__DOT__different_sign) 
                                             & (vlTOPp->dec__DOT__dec2exe_op2_sd 
                                                >> 0x1fU)) 
                                            | ((~ (IData)(vlTOPp->dec__DOT__different_sign)) 
                                               & (~ 
                                                  (vlTOPp->dec__DOT__res_compare 
                                                   >> 0x1fU)))))) 
                                     | ((IData)(vlTOPp->dec__DOT__bgeu_i_sd) 
                                        & (((IData)(vlTOPp->dec__DOT__different_sign) 
                                            & (vlTOPp->dec__DOT__dec2exe_op1_sd 
                                               >> 0x1fU)) 
                                           | ((~ (IData)(vlTOPp->dec__DOT__different_sign)) 
                                              & (~ 
                                                 (vlTOPp->dec__DOT__res_compare 
                                                  >> 0x1fU))))))
                                  : ((0x6fU == (0x7fU 
                                                & vlTOPp->INSTR_RI)) 
                                     | (0x67U == (0x7fU 
                                                  & vlTOPp->INSTR_RI))));
    vlTOPp->dec__DOT__dec2if_din[1U] = vlTOPp->dec__DOT__branch_adr_sd;
    vlTOPp->IF2DEC_FLUSH_SD = (((IData)(vlTOPp->PRED_TAKEN_RI) 
                                & ((~ (IData)(vlTOPp->dec__DOT__jump_sd)) 
                                   & (~ (IData)(vlTOPp->dec__DOT__stall_sd)))) 
                               | ((~ (IData)(vlTOPp->PRED_TAKEN_RI)) 
                                  & ((IData)(vlTOPp->dec__DOT__jump_sd) 
                                     & (~ (IData)(vlTOPp->dec__DOT__stall_sd)))));
    vlTOPp->dec__DOT__add_offset_to_pc = ((IData)(vlTOPp->dec__DOT__jump_sd) 
                                          & (~ (IData)(vlTOPp->IF2DEC_EMPTY_SI)));
    vlTOPp->dec__DOT__dec2if_push_sd = (1U & (((~ (IData)(vlTOPp->dec__DOT__add_offset_to_pc)) 
                                               & (~ (IData)(vlTOPp->dec__DOT__dec2if_full_sd))) 
                                              | (((IData)(vlTOPp->dec__DOT__add_offset_to_pc) 
                                                  & (~ (IData)(vlTOPp->dec__DOT__dec2if_full_sd))) 
                                                 & (~ (IData)(vlTOPp->dec__DOT__stall_sd)))));
    vlTOPp->WRITE_PC_ENABLE_SD = (1U & (((~ (IData)(vlTOPp->dec__DOT__add_offset_to_pc)) 
                                         & (~ (IData)(vlTOPp->dec__DOT__dec2if_full_sd))) 
                                        | (((IData)(vlTOPp->dec__DOT__add_offset_to_pc) 
                                            & (~ (IData)(vlTOPp->dec__DOT__dec2if_full_sd))) 
                                           & (~ (IData)(vlTOPp->dec__DOT__stall_sd)))));
    vlTOPp->dec__DOT__dec2if_din[3U] = ((0xfffffffdU 
                                         & vlTOPp->dec__DOT__dec2if_din[3U]) 
                                        | (0xfffffffeU 
                                           & (((((IData)(vlTOPp->PRED_TAKEN_RI) 
                                                 & (IData)(vlTOPp->dec__DOT__add_offset_to_pc)) 
                                                & (~ (IData)(vlTOPp->dec__DOT__dec2if_full_sd))) 
                                               & (~ (IData)(vlTOPp->dec__DOT__stall_sd))) 
                                              << 1U)));
    vlTOPp->dec__DOT__pred_failed_sd = ((((IData)(vlTOPp->PRED_TAKEN_RI) 
                                          & (~ (IData)(vlTOPp->dec__DOT__add_offset_to_pc))) 
                                         & (~ (IData)(vlTOPp->dec__DOT__dec2if_full_sd))) 
                                        & (~ (IData)(vlTOPp->IF2DEC_EMPTY_SI)));
    vlTOPp->dec__DOT__pc = (((IData)(vlTOPp->dec__DOT__reset_sync_sd) 
                             ^ (IData)(vlTOPp->reset_n))
                             ? vlTOPp->READ_PC_SR : 
                            ((((~ (IData)(vlTOPp->dec__DOT__add_offset_to_pc)) 
                               & (~ (IData)(vlTOPp->dec__DOT__dec2if_full_sd))) 
                              & (IData)(vlTOPp->reset_n))
                              ? (((((IData)(vlTOPp->PRED_TAKEN_RI) 
                                    & (IData)(vlTOPp->dec__DOT__stall_sd)) 
                                   & (~ (vlTOPp->dec__DOT__dec2if__DOT__data[3U] 
                                         >> 1U))) & 
                                  (~ (vlTOPp->dec__DOT__dec2if__DOT__data[3U] 
                                      >> 2U))) ? ((IData)(4U) 
                                                  + vlTOPp->PRED_ADR_RI)
                                  : (((IData)(vlTOPp->PRED_TAKEN_RI) 
                                      & (~ (IData)(vlTOPp->dec__DOT__stall_sd)))
                                      ? ((IData)(4U) 
                                         + vlTOPp->PC_IF2DEC_RI)
                                      : ((IData)(4U) 
                                         + vlTOPp->READ_PC_SR)))
                              : (((((IData)(vlTOPp->dec__DOT__add_offset_to_pc) 
                                    & (~ (IData)(vlTOPp->dec__DOT__dec2if_full_sd))) 
                                   & (~ (IData)(vlTOPp->dec__DOT__stall_sd))) 
                                  & (IData)(vlTOPp->reset_n))
                                  ? (((((IData)(vlTOPp->PRED_TAKEN_RI) 
                                        & (IData)(vlTOPp->dec__DOT__add_offset_to_pc)) 
                                       & (~ (IData)(vlTOPp->dec__DOT__dec2if_full_sd))) 
                                      & (~ (IData)(vlTOPp->dec__DOT__stall_sd)))
                                      ? ((IData)(4U) 
                                         + vlTOPp->PRED_ADR_RI)
                                      : vlTOPp->dec__DOT__branch_adr_sd)
                                  : 0xabcdef00U)));
    vlTOPp->dec__DOT__dec2if_din[3U] = ((0xfffffffbU 
                                         & vlTOPp->dec__DOT__dec2if_din[3U]) 
                                        | (0xfffffffcU 
                                           & ((IData)(vlTOPp->dec__DOT__pred_failed_sd) 
                                              << 2U)));
    vlTOPp->dec__DOT__instruction_access_fault_sd = 
        (((~ (IData)(vlTOPp->EXCEPTION_SM)) & (3U != (IData)(vlTOPp->CURRENT_MODE_SM))) 
         & (0xf0000000U < vlTOPp->dec__DOT__pc));
    vlTOPp->dec__DOT__instruction_adress_misaligned_sd 
        = ((0U != (3U & vlTOPp->dec__DOT__pc)) | ((0U 
                                                   != 
                                                   (3U 
                                                    & vlTOPp->RETURN_ADRESS_SM)) 
                                                  & (IData)(vlTOPp->EXCEPTION_SM)));
    vlTOPp->dec__DOT__new_pc = ((((~ (IData)(vlTOPp->MRET_SM)) 
                                  & (IData)(vlTOPp->EXCEPTION_SM)) 
                                 & (0U == (3U & vlTOPp->MTVEC_VALUE_RC)))
                                 ? vlTOPp->MTVEC_VALUE_RC
                                 : ((((~ (IData)(vlTOPp->MRET_SM)) 
                                      & (IData)(vlTOPp->EXCEPTION_SM)) 
                                     & (1U == (3U & vlTOPp->MTVEC_VALUE_RC)))
                                     ? (vlTOPp->dec__DOT__mtvec_value 
                                        + vlTOPp->dec__DOT__mcause_val)
                                     : (((IData)(vlTOPp->MRET_SM) 
                                         & (IData)(vlTOPp->EXCEPTION_SM))
                                         ? vlTOPp->RETURN_ADRESS_SM
                                         : vlTOPp->dec__DOT__pc)));
    vlTOPp->WRITE_PC_SD = vlTOPp->dec__DOT__new_pc;
    vlTOPp->dec__DOT__dec2if_din[0U] = vlTOPp->dec__DOT__new_pc;
    __Vtemp12[2U] = ((0xf0000000U & ((((((((((IData)(vlTOPp->dec__DOT__illegal_inst_sd) 
                                             | (IData)(vlTOPp->dec__DOT__instruction_adress_misaligned_sd)) 
                                            | (IData)(vlTOPp->dec__DOT__env_call_u_mode_sd)) 
                                           | (IData)(vlTOPp->dec__DOT__env_call_m_mode_sd)) 
                                          | (IData)(vlTOPp->dec__DOT__env_call_s_mode_sd)) 
                                         | (IData)(vlTOPp->dec__DOT__env_call_wrong_mode)) 
                                        | (0x30200073U 
                                           == vlTOPp->INSTR_RI)) 
                                       | (IData)(vlTOPp->dec__DOT__instruction_access_fault_sd)) 
                                      | (IData)(vlTOPp->dec__DOT__ebreak_i_sd)) 
                                     << 0x1cU)) | (
                                                   (0xf8000000U 
                                                    & ((IData)(vlTOPp->dec__DOT__env_call_wrong_mode) 
                                                       << 0x1bU)) 
                                                   | ((0xfc000000U 
                                                       & ((IData)(vlTOPp->dec__DOT__env_call_u_mode_sd) 
                                                          << 0x1aU)) 
                                                      | ((0xfe000000U 
                                                          & ((IData)(vlTOPp->dec__DOT__illegal_inst_sd) 
                                                             << 0x19U)) 
                                                         | ((0xff000000U 
                                                             & ((IData)(vlTOPp->dec__DOT__instruction_adress_misaligned_sd) 
                                                                << 0x18U)) 
                                                            | ((0xff800000U 
                                                                & ((IData)(vlTOPp->dec__DOT__env_call_m_mode_sd) 
                                                                   << 0x17U)) 
                                                               | ((0xffc00000U 
                                                                   & ((IData)(vlTOPp->dec__DOT__env_call_s_mode_sd) 
                                                                      << 0x16U)) 
                                                                  | (0x3fffffU 
                                                                     & (vlTOPp->CSR_RDATA_SC 
                                                                        >> 0xaU)))))))));
    __Vtemp17[0U] = (IData)((((QData)((IData)(vlTOPp->dec__DOT__radr2_sd)) 
                              << 0x22U) | (((QData)((IData)(
                                                            ((8U 
                                                              == (IData)(vlTOPp->dec__DOT__select_operation_sd))
                                                              ? 
                                                             ((IData)(vlTOPp->dec__DOT__div_i_sd)
                                                               ? 1U
                                                               : 
                                                              ((IData)(vlTOPp->dec__DOT__divu_i_sd)
                                                                ? 2U
                                                                : 
                                                               ((IData)(vlTOPp->dec__DOT__rem_i_sd)
                                                                 ? 3U
                                                                 : 0U)))
                                                              : 
                                                             ((4U 
                                                               == (IData)(vlTOPp->dec__DOT__select_operation_sd))
                                                               ? 
                                                              ((IData)(vlTOPp->dec__DOT__mul_i_sd)
                                                                ? 1U
                                                                : 
                                                               ((IData)(vlTOPp->dec__DOT__mulh_i_sd)
                                                                 ? 2U
                                                                 : 
                                                                ((IData)(vlTOPp->dec__DOT__mulhu_i_sd)
                                                                  ? 3U
                                                                  : 0U)))
                                                               : 
                                                              (((((((IData)(vlTOPp->dec__DOT__and_i_sd) 
                                                                    | (IData)(vlTOPp->dec__DOT__andi_i_sd)) 
                                                                   | (IData)(vlTOPp->dec__DOT__srl_i_sd)) 
                                                                  | (IData)(vlTOPp->dec__DOT__srli_i_sd)) 
                                                                 | (IData)(vlTOPp->dec__DOT__csrrc_i_sd)) 
                                                                | (IData)(vlTOPp->dec__DOT__csrrci_i_sd))
                                                                ? 1U
                                                                : 
                                                               (((((((IData)(vlTOPp->dec__DOT__or_i_sd) 
                                                                     | (IData)(vlTOPp->dec__DOT__ori_i_sd)) 
                                                                    | (IData)(vlTOPp->dec__DOT__sra_i_sd)) 
                                                                   | (IData)(vlTOPp->dec__DOT__srai_i_sd)) 
                                                                  | (IData)(vlTOPp->dec__DOT__csrrs_i_sd)) 
                                                                 | (IData)(vlTOPp->dec__DOT__csrrsi_i_sd))
                                                                 ? 2U
                                                                 : 
                                                                (((IData)(vlTOPp->dec__DOT__xor_i_sd) 
                                                                  | (IData)(vlTOPp->dec__DOT__xori_i_sd))
                                                                  ? 3U
                                                                  : 0U))))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlTOPp->dec__DOT__dec2exe_op1_sd)))));
    __Vtemp17[1U] = ((0xffffff00U & ((IData)((((QData)((IData)(
                                                               ((((((IData)(vlTOPp->dec__DOT__csrrw_i_sd) 
                                                                    | (IData)(vlTOPp->dec__DOT__csrrs_i_sd)) 
                                                                   | (IData)(vlTOPp->dec__DOT__csrrc_i_sd)) 
                                                                  | (IData)(vlTOPp->dec__DOT__csrrwi_i_sd)) 
                                                                 | (IData)(vlTOPp->dec__DOT__csrrsi_i_sd)) 
                                                                | (IData)(vlTOPp->dec__DOT__csrrci_i_sd)))) 
                                               << 0x35U) 
                                              | (((QData)((IData)(vlTOPp->dec__DOT__csr_radr)) 
                                                  << 0x29U) 
                                                 | (((QData)((IData)(vlTOPp->PC_IF2DEC_RI)) 
                                                     << 9U) 
                                                    | (QData)((IData)(
                                                                      (((0x67U 
                                                                         == 
                                                                         (0x7fU 
                                                                          & vlTOPp->INSTR_RI)) 
                                                                        << 8U) 
                                                                       | (((IData)(vlTOPp->dec__DOT__r1_valid_sd) 
                                                                           << 7U) 
                                                                          | (((IData)(vlTOPp->dec__DOT__r2_valid_sd) 
                                                                              << 6U) 
                                                                             | (IData)(vlTOPp->dec__DOT__radr1_sd)))))))))) 
                                     << 8U)) | (IData)(
                                                       ((((QData)((IData)(vlTOPp->dec__DOT__radr2_sd)) 
                                                          << 0x22U) 
                                                         | (((QData)((IData)(
                                                                             ((8U 
                                                                               == (IData)(vlTOPp->dec__DOT__select_operation_sd))
                                                                               ? 
                                                                              ((IData)(vlTOPp->dec__DOT__div_i_sd)
                                                                                ? 1U
                                                                                : 
                                                                               ((IData)(vlTOPp->dec__DOT__divu_i_sd)
                                                                                 ? 2U
                                                                                 : 
                                                                                ((IData)(vlTOPp->dec__DOT__rem_i_sd)
                                                                                 ? 3U
                                                                                 : 0U)))
                                                                               : 
                                                                              ((4U 
                                                                                == (IData)(vlTOPp->dec__DOT__select_operation_sd))
                                                                                ? 
                                                                               ((IData)(vlTOPp->dec__DOT__mul_i_sd)
                                                                                 ? 1U
                                                                                 : 
                                                                                ((IData)(vlTOPp->dec__DOT__mulh_i_sd)
                                                                                 ? 2U
                                                                                 : 
                                                                                ((IData)(vlTOPp->dec__DOT__mulhu_i_sd)
                                                                                 ? 3U
                                                                                 : 0U)))
                                                                                : 
                                                                               (((((((IData)(vlTOPp->dec__DOT__and_i_sd) 
                                                                                | (IData)(vlTOPp->dec__DOT__andi_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__srl_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__srli_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__csrrc_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__csrrci_i_sd))
                                                                                 ? 1U
                                                                                 : 
                                                                                (((((((IData)(vlTOPp->dec__DOT__or_i_sd) 
                                                                                | (IData)(vlTOPp->dec__DOT__ori_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__sra_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__srai_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__csrrs_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__csrrsi_i_sd))
                                                                                 ? 2U
                                                                                 : 
                                                                                (((IData)(vlTOPp->dec__DOT__xor_i_sd) 
                                                                                | (IData)(vlTOPp->dec__DOT__xori_i_sd))
                                                                                 ? 3U
                                                                                 : 0U))))))) 
                                                             << 0x20U) 
                                                            | (QData)((IData)(vlTOPp->dec__DOT__dec2exe_op1_sd)))) 
                                                        >> 0x20U)));
    __Vtemp17[2U] = ((0xffU & ((IData)((((QData)((IData)(
                                                         ((((((IData)(vlTOPp->dec__DOT__csrrw_i_sd) 
                                                              | (IData)(vlTOPp->dec__DOT__csrrs_i_sd)) 
                                                             | (IData)(vlTOPp->dec__DOT__csrrc_i_sd)) 
                                                            | (IData)(vlTOPp->dec__DOT__csrrwi_i_sd)) 
                                                           | (IData)(vlTOPp->dec__DOT__csrrsi_i_sd)) 
                                                          | (IData)(vlTOPp->dec__DOT__csrrci_i_sd)))) 
                                         << 0x35U) 
                                        | (((QData)((IData)(vlTOPp->dec__DOT__csr_radr)) 
                                            << 0x29U) 
                                           | (((QData)((IData)(vlTOPp->PC_IF2DEC_RI)) 
                                               << 9U) 
                                              | (QData)((IData)(
                                                                (((0x67U 
                                                                   == 
                                                                   (0x7fU 
                                                                    & vlTOPp->INSTR_RI)) 
                                                                  << 8U) 
                                                                 | (((IData)(vlTOPp->dec__DOT__r1_valid_sd) 
                                                                     << 7U) 
                                                                    | (((IData)(vlTOPp->dec__DOT__r2_valid_sd) 
                                                                        << 6U) 
                                                                       | (IData)(vlTOPp->dec__DOT__radr1_sd)))))))))) 
                               >> 0x18U)) | (0xffffff00U 
                                             & ((0xc0000000U 
                                                 & (vlTOPp->CSR_RDATA_SC 
                                                    << 0x1eU)) 
                                                | ((IData)(
                                                           ((((QData)((IData)(
                                                                              ((((((IData)(vlTOPp->dec__DOT__csrrw_i_sd) 
                                                                                | (IData)(vlTOPp->dec__DOT__csrrs_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__csrrc_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__csrrwi_i_sd)) 
                                                                                | (IData)(vlTOPp->dec__DOT__csrrsi_i_sd)) 
                                                                               | (IData)(vlTOPp->dec__DOT__csrrci_i_sd)))) 
                                                              << 0x35U) 
                                                             | (((QData)((IData)(vlTOPp->dec__DOT__csr_radr)) 
                                                                 << 0x29U) 
                                                                | (((QData)((IData)(vlTOPp->PC_IF2DEC_RI)) 
                                                                    << 9U) 
                                                                   | (QData)((IData)(
                                                                                (((0x67U 
                                                                                == 
                                                                                (0x7fU 
                                                                                & vlTOPp->INSTR_RI)) 
                                                                                << 8U) 
                                                                                | (((IData)(vlTOPp->dec__DOT__r1_valid_sd) 
                                                                                << 7U) 
                                                                                | (((IData)(vlTOPp->dec__DOT__r2_valid_sd) 
                                                                                << 6U) 
                                                                                | (IData)(vlTOPp->dec__DOT__radr1_sd))))))))) 
                                                            >> 0x20U)) 
                                                   << 8U))));
    __Vtemp17[3U] = ((0xffU & ((0xffU & (vlTOPp->CSR_RDATA_SC 
                                         >> 2U)) | 
                               ((IData)(((((QData)((IData)(
                                                           ((((((IData)(vlTOPp->dec__DOT__csrrw_i_sd) 
                                                                | (IData)(vlTOPp->dec__DOT__csrrs_i_sd)) 
                                                               | (IData)(vlTOPp->dec__DOT__csrrc_i_sd)) 
                                                              | (IData)(vlTOPp->dec__DOT__csrrwi_i_sd)) 
                                                             | (IData)(vlTOPp->dec__DOT__csrrsi_i_sd)) 
                                                            | (IData)(vlTOPp->dec__DOT__csrrci_i_sd)))) 
                                           << 0x35U) 
                                          | (((QData)((IData)(vlTOPp->dec__DOT__csr_radr)) 
                                              << 0x29U) 
                                             | (((QData)((IData)(vlTOPp->PC_IF2DEC_RI)) 
                                                 << 9U) 
                                                | (QData)((IData)(
                                                                  (((0x67U 
                                                                     == 
                                                                     (0x7fU 
                                                                      & vlTOPp->INSTR_RI)) 
                                                                    << 8U) 
                                                                   | (((IData)(vlTOPp->dec__DOT__r1_valid_sd) 
                                                                       << 7U) 
                                                                      | (((IData)(vlTOPp->dec__DOT__r2_valid_sd) 
                                                                          << 6U) 
                                                                         | (IData)(vlTOPp->dec__DOT__radr1_sd))))))))) 
                                         >> 0x20U)) 
                                >> 0x18U))) | (0xffffff00U 
                                               & (__Vtemp12[2U] 
                                                  << 8U)));
    vlTOPp->dec__DOT__dec2exe_data[2U] = ((0xffffU 
                                           & vlTOPp->dec__DOT__dec2exe_data[2U]) 
                                          | (0xffff0000U 
                                             & (__Vtemp17[0U] 
                                                << 0x10U)));
    vlTOPp->dec__DOT__dec2exe_data[3U] = ((0xffffU 
                                           & (__Vtemp17[0U] 
                                              >> 0x10U)) 
                                          | (0xffff0000U 
                                             & (__Vtemp17[1U] 
                                                << 0x10U)));
    vlTOPp->dec__DOT__dec2exe_data[4U] = ((0xffffU 
                                           & (__Vtemp17[1U] 
                                              >> 0x10U)) 
                                          | (0xffff0000U 
                                             & (__Vtemp17[2U] 
                                                << 0x10U)));
    vlTOPp->dec__DOT__dec2exe_data[5U] = ((0xffffU 
                                           & (__Vtemp17[2U] 
                                              >> 0x10U)) 
                                          | (0xffff0000U 
                                             & (__Vtemp17[3U] 
                                                << 0x10U)));
    vlTOPp->dec__DOT__dec2exe_data[6U] = ((0xffffU 
                                           & (__Vtemp17[3U] 
                                              >> 0x10U)) 
                                          | (0xffff0000U 
                                             & ((0xff0000U 
                                                 & ((0x800000U 
                                                     & ((IData)(vlTOPp->dec__DOT__ebreak_i_sd) 
                                                        << 0x17U)) 
                                                    | ((0xc00000U 
                                                        & ((IData)(vlTOPp->dec__DOT__instruction_access_fault_sd) 
                                                           << 0x16U)) 
                                                       | ((0xe00000U 
                                                           & ((0x30200073U 
                                                               == vlTOPp->INSTR_RI) 
                                                              << 0x15U)) 
                                                          | (0xff0000U 
                                                             & (__Vtemp12[2U] 
                                                                >> 8U)))))) 
                                                | (0xff000000U 
                                                   & (vlTOPp->dec__DOT__new_pc 
                                                      << 0x18U)))));
    vlTOPp->dec__DOT__dec2exe_data[7U] = ((0xffffU 
                                           & (vlTOPp->dec__DOT__new_pc 
                                              >> 8U)) 
                                          | (0xffff0000U 
                                             & ((0xf8000000U 
                                                 & (((((IData)(vlTOPp->dec__DOT__mul_i_sd) 
                                                       | (IData)(vlTOPp->dec__DOT__mulh_i_sd)) 
                                                      | (IData)(vlTOPp->dec__DOT__mulhsu_i_sd)) 
                                                     | (IData)(vlTOPp->dec__DOT__mulhu_i_sd)) 
                                                    << 0x1bU)) 
                                                | ((0x7000000U 
                                                    & ((IData)(vlTOPp->dec__DOT__select_operation_sd) 
                                                       << 0x17U)) 
                                                   | (0xff0000U 
                                                      & (vlTOPp->dec__DOT__new_pc 
                                                         >> 8U))))));
    if (vlTOPp->EXCEPTION_SM) {
        vlTOPp->dec__DOT__dec2exe_din[0U] = vlTOPp->dec__DOT__dec2exe_x[0U];
        vlTOPp->dec__DOT__dec2exe_din[1U] = vlTOPp->dec__DOT__dec2exe_x[1U];
        vlTOPp->dec__DOT__dec2exe_din[2U] = vlTOPp->dec__DOT__dec2exe_x[2U];
        vlTOPp->dec__DOT__dec2exe_din[3U] = vlTOPp->dec__DOT__dec2exe_x[3U];
        vlTOPp->dec__DOT__dec2exe_din[4U] = vlTOPp->dec__DOT__dec2exe_x[4U];
        vlTOPp->dec__DOT__dec2exe_din[5U] = vlTOPp->dec__DOT__dec2exe_x[5U];
        vlTOPp->dec__DOT__dec2exe_din[6U] = vlTOPp->dec__DOT__dec2exe_x[6U];
        vlTOPp->dec__DOT__dec2exe_din[7U] = vlTOPp->dec__DOT__dec2exe_x[7U];
    } else {
        vlTOPp->dec__DOT__dec2exe_din[0U] = vlTOPp->dec__DOT__dec2exe_data[0U];
        vlTOPp->dec__DOT__dec2exe_din[1U] = vlTOPp->dec__DOT__dec2exe_data[1U];
        vlTOPp->dec__DOT__dec2exe_din[2U] = vlTOPp->dec__DOT__dec2exe_data[2U];
        vlTOPp->dec__DOT__dec2exe_din[3U] = vlTOPp->dec__DOT__dec2exe_data[3U];
        vlTOPp->dec__DOT__dec2exe_din[4U] = vlTOPp->dec__DOT__dec2exe_data[4U];
        vlTOPp->dec__DOT__dec2exe_din[5U] = vlTOPp->dec__DOT__dec2exe_data[5U];
        vlTOPp->dec__DOT__dec2exe_din[6U] = vlTOPp->dec__DOT__dec2exe_data[6U];
        vlTOPp->dec__DOT__dec2exe_din[7U] = vlTOPp->dec__DOT__dec2exe_data[7U];
    }
}

void Vdecod::_eval_initial(Vdecod__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecod::_eval_initial\n"); );
    Vdecod* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset_n = vlTOPp->reset_n;
}

void Vdecod::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecod::final\n"); );
    // Variables
    Vdecod__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vdecod* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vdecod::_eval_settle(Vdecod__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecod::_eval_settle\n"); );
    Vdecod* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vdecod::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecod::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset_n = VL_RAND_RESET_I(1);
    RDATA1_SR = VL_RAND_RESET_I(32);
    RDATA2_SR = VL_RAND_RESET_I(32);
    REG_ADR1_SD = VL_RAND_RESET_I(6);
    REG_ADR2_SD = VL_RAND_RESET_I(6);
    WRITE_PC_SD = VL_RAND_RESET_I(32);
    WRITE_PC_ENABLE_SD = VL_RAND_RESET_I(1);
    READ_PC_SR = VL_RAND_RESET_I(32);
    OP1_RD = VL_RAND_RESET_I(32);
    OP2_RD = VL_RAND_RESET_I(32);
    CMD_RD = VL_RAND_RESET_I(2);
    NEG_OP2_RD = VL_RAND_RESET_I(1);
    WB_RD = VL_RAND_RESET_I(1);
    DEST_RD = VL_RAND_RESET_I(6);
    SELECT_OPERATION_RD = VL_RAND_RESET_I(4);
    SLT_RD = VL_RAND_RESET_I(1);
    SLTU_RD = VL_RAND_RESET_I(1);
    MEM_DATA_RD = VL_RAND_RESET_I(32);
    MEM_LOAD_RD = VL_RAND_RESET_I(1);
    MEM_STORE_RD = VL_RAND_RESET_I(1);
    MEM_SIGN_EXTEND_RD = VL_RAND_RESET_I(1);
    MEM_SIZE_RD = VL_RAND_RESET_I(2);
    PC_DEC2EXE_RD = VL_RAND_RESET_I(32);
    PC_BRANCH_VALUE_RD = VL_RAND_RESET_I(32);
    CSR_WENABLE_RD = VL_RAND_RESET_I(1);
    CSR_WADR_RD = VL_RAND_RESET_I(12);
    CSR_RDATA_RD = VL_RAND_RESET_I(32);
    DEC2IF_POP_SI = VL_RAND_RESET_I(1);
    DEC2IF_EMPTY_SD = VL_RAND_RESET_I(1);
    PC_RD = VL_RAND_RESET_I(32);
    INSTR_RI = VL_RAND_RESET_I(32);
    PC_IF2DEC_RI = VL_RAND_RESET_I(32);
    IF2DEC_EMPTY_SI = VL_RAND_RESET_I(1);
    IF2DEC_POP_SD = VL_RAND_RESET_I(1);
    IF2DEC_FLUSH_SD = VL_RAND_RESET_I(1);
    PRED_FAILED_RD = VL_RAND_RESET_I(1);
    PRED_SUCCESS_RD = VL_RAND_RESET_I(1);
    BRANCH_INST_RD = VL_RAND_RESET_I(1);
    BRANCH_INST_ADR_RD = VL_RAND_RESET_I(32);
    ADR_TO_BRANCH_RD = VL_RAND_RESET_I(32);
    PRED_ADR_SD = VL_RAND_RESET_I(32);
    PRED_TAKEN_SD = VL_RAND_RESET_I(1);
    PUSH_ADR_RAS_RD = VL_RAND_RESET_I(1);
    POP_ADR_RAS_RD = VL_RAND_RESET_I(1);
    ADR_TO_RET_RD = VL_RAND_RESET_I(32);
    RET_INST_RD = VL_RAND_RESET_I(1);
    PRED_ADR_RI = VL_RAND_RESET_I(32);
    PRED_TAKEN_RI = VL_RAND_RESET_I(1);
    DEC2EXE_POP_SE = VL_RAND_RESET_I(1);
    DEC2EXE_EMPTY_SD = VL_RAND_RESET_I(1);
    MULT_INST_RD = VL_RAND_RESET_I(1);
    MULT_INST_RE = VL_RAND_RESET_I(1);
    MULT_INST_RM = VL_RAND_RESET_I(1);
    BP_DEST_RE = VL_RAND_RESET_I(6);
    BP_EXE_RES_RE = VL_RAND_RESET_I(32);
    BP_MEM_LOAD_RE = VL_RAND_RESET_I(1);
    BP_EXE2MEM_EMPTY_SE = VL_RAND_RESET_I(1);
    BP_MEM2WBK_EMPTY_SM = VL_RAND_RESET_I(1);
    BP_DEST_RM = VL_RAND_RESET_I(6);
    BP_MEM_RES_RM = VL_RAND_RESET_I(32);
    BP_R1_VALID_RD = VL_RAND_RESET_I(1);
    BP_R2_VALID_RD = VL_RAND_RESET_I(1);
    BP_RADR1_RD = VL_RAND_RESET_I(6);
    BP_RADR2_RD = VL_RAND_RESET_I(6);
    BLOCK_BP_RD = VL_RAND_RESET_I(1);
    CSR_WENABLE_RE = VL_RAND_RESET_I(1);
    CSR_WENABLE_RM = VL_RAND_RESET_I(1);
    CSR_RDATA_RE = VL_RAND_RESET_I(32);
    CSR_RDATA_RM = VL_RAND_RESET_I(32);
    CSR_RADR_SD = VL_RAND_RESET_I(12);
    CSR_RDATA_SC = VL_RAND_RESET_I(32);
    EXCEPTION_RI = VL_RAND_RESET_I(1);
    ILLEGAL_INSTRUCTION_RD = VL_RAND_RESET_I(1);
    ADRESS_MISALIGNED_RD = VL_RAND_RESET_I(1);
    ENV_CALL_U_MODE_RD = VL_RAND_RESET_I(1);
    ENV_CALL_M_MODE_RD = VL_RAND_RESET_I(1);
    ENV_CALL_S_MODE_RD = VL_RAND_RESET_I(1);
    ENV_CALL_WRONG_MODE_RD = VL_RAND_RESET_I(1);
    INSTRUCTION_ACCESS_FAULT_RD = VL_RAND_RESET_I(1);
    MRET_RD = VL_RAND_RESET_I(1);
    EXCEPTION_RD = VL_RAND_RESET_I(1);
    EBREAK_RD = VL_RAND_RESET_I(1);
    CURRENT_MODE_SM = VL_RAND_RESET_I(2);
    EXCEPTION_SM = VL_RAND_RESET_I(1);
    MTVEC_VALUE_RC = VL_RAND_RESET_I(32);
    MCAUSE_WDATA_SM = VL_RAND_RESET_I(32);
    RETURN_ADRESS_SM = VL_RAND_RESET_I(32);
    MRET_SM = VL_RAND_RESET_I(1);
    dec__DOT__reset_sync_sd = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(134, dec__DOT__dec2if_din);
    dec__DOT__dec2if_full_sd = VL_RAND_RESET_I(1);
    dec__DOT__dec2if_push_sd = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(252, dec__DOT__dec2exe_din);
    VL_RAND_RESET_W(252, dec__DOT__dec2exe_data);
    VL_RAND_RESET_W(252, dec__DOT__dec2exe_x);
    dec__DOT__i_type_sd = VL_RAND_RESET_I(1);
    dec__DOT__u_type_sd = VL_RAND_RESET_I(1);
    dec__DOT__m_type_sd = VL_RAND_RESET_I(1);
    dec__DOT__sub_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__slt_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__sltu_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__and_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__or_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__xor_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__sll_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__srl_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__sra_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__slti_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__sltiu_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__andi_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__ori_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__xori_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__slli_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__srli_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__srai_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__lw_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__lh_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__lhu_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__lb_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__lbu_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__sw_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__sh_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__sb_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__beq_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__bne_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__blt_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__bge_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__bltu_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__bgeu_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__mul_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__mulh_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__mulhsu_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__mulhu_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__div_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__divu_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__rem_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__ecall_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__ebreak_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__csrrw_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__csrrs_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__csrrc_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__csrrwi_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__csrrsi_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__csrrci_i_sd = VL_RAND_RESET_I(1);
    dec__DOT__env_call_u_mode_sd = VL_RAND_RESET_I(1);
    dec__DOT__env_call_s_mode_sd = VL_RAND_RESET_I(1);
    dec__DOT__env_call_m_mode_sd = VL_RAND_RESET_I(1);
    dec__DOT__env_call_wrong_mode = VL_RAND_RESET_I(1);
    dec__DOT__illegal_inst = VL_RAND_RESET_I(1);
    dec__DOT__illegal_inst_sd = VL_RAND_RESET_I(1);
    dec__DOT__instruction_access_fault_sd = VL_RAND_RESET_I(1);
    dec__DOT__instruction_adress_misaligned_sd = VL_RAND_RESET_I(1);
    dec__DOT__op1_csri_type_sd = VL_RAND_RESET_I(32);
    dec__DOT__mtvec_value = VL_RAND_RESET_I(32);
    dec__DOT__mcause_val = VL_RAND_RESET_I(32);
    dec__DOT__csr_radr = VL_RAND_RESET_I(12);
    dec__DOT__dec2exe_op1_sd = VL_RAND_RESET_I(32);
    dec__DOT__dec2exe_op2_sd = VL_RAND_RESET_I(32);
    dec__DOT__op1_u_type_sd = VL_RAND_RESET_I(32);
    dec__DOT__op2_i_type_sd = VL_RAND_RESET_I(32);
    dec__DOT__op2_s_type_sd = VL_RAND_RESET_I(32);
    dec__DOT__radr1_sd = VL_RAND_RESET_I(6);
    dec__DOT__radr2_sd = VL_RAND_RESET_I(6);
    dec__DOT__rdest_sd = VL_RAND_RESET_I(6);
    dec__DOT__rdata1_sd = VL_RAND_RESET_I(32);
    dec__DOT__rdata2_sd = VL_RAND_RESET_I(32);
    dec__DOT__select_operation_sd = VL_RAND_RESET_I(4);
    dec__DOT__offset_branch_sd = VL_RAND_RESET_I(32);
    dec__DOT__offset_branch_j = VL_RAND_RESET_I(32);
    dec__DOT__offset_branch_jalr = VL_RAND_RESET_I(32);
    dec__DOT__jalr_offset = VL_RAND_RESET_I(32);
    dec__DOT__offset_branch_b = VL_RAND_RESET_I(32);
    dec__DOT__jump_sd = VL_RAND_RESET_I(1);
    dec__DOT__different_sign = VL_RAND_RESET_I(1);
    dec__DOT__res = VL_RAND_RESET_I(32);
    dec__DOT__res_compare = VL_RAND_RESET_I(32);
    dec__DOT__add_offset_to_pc = VL_RAND_RESET_I(1);
    dec__DOT__pc = VL_RAND_RESET_I(32);
    dec__DOT__new_pc = VL_RAND_RESET_I(32);
    dec__DOT__branch_adr_sd = VL_RAND_RESET_I(32);
    dec__DOT__rd_link = VL_RAND_RESET_I(1);
    dec__DOT__rs1_link = VL_RAND_RESET_I(1);
    dec__DOT__pred_failed_sd = VL_RAND_RESET_I(1);
    dec__DOT__stall_sd = VL_RAND_RESET_I(1);
    dec__DOT__r1_valid_sd = VL_RAND_RESET_I(1);
    dec__DOT__r2_valid_sd = VL_RAND_RESET_I(1);
    dec__DOT__bpc_ed1 = VL_RAND_RESET_I(1);
    dec__DOT__bpc_md1 = VL_RAND_RESET_I(1);
    dec__DOT__bpc_ed2 = VL_RAND_RESET_I(1);
    dec__DOT__bpc_md2 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(134, dec__DOT__dec2if__DOT__data);
    dec__DOT__dec2if__DOT__data_v = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(252, dec__DOT__dec2exe__DOT__data);
    dec__DOT__dec2exe__DOT__data_v = VL_RAND_RESET_I(1);
}
