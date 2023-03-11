// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdivider.h for the primary calling header

#include "Vdivider.h"
#include "Vdivider__Syms.h"

//==========
CData/*0:0*/ Vdivider::__Vtable1_divider__DOT__setup_regs[8];
CData/*0:0*/ Vdivider::__Vtable1_divider__DOT__same[8];
CData/*0:0*/ Vdivider::__Vtable1_divider__DOT__zero_div[8];
CData/*0:0*/ Vdivider::__Vtable1_divider__DOT__running[8];
CData/*0:0*/ Vdivider::__Vtable1_DONE_DIV[8];
CData/*0:0*/ Vdivider::__Vtable1_BUSY_DIV[8];

VL_CTOR_IMP(Vdivider) {
    Vdivider__Syms* __restrict vlSymsp = __VlSymsp = new Vdivider__Syms(this, name());
    Vdivider* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vdivider::__Vconfigure(Vdivider__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vdivider::~Vdivider() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vdivider::_initial__TOP__1(Vdivider__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider::_initial__TOP__1\n"); );
    Vdivider* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->divider__DOT__cmd_reg = 0U;
    vlTOPp->divider__DOT__quotient = 0U;
    vlTOPp->divider__DOT__reminder_reg = 0ULL;
    vlTOPp->divider__DOT__reminder_se = 0ULL;
    vlTOPp->divider__DOT__shift_cpt_reg = 0U;
}

void Vdivider::_settle__TOP__2(Vdivider__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider::_settle__TOP__2\n"); );
    Vdivider* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->divider__DOT__divisor_setup = (0x7fffffffffffffffULL 
                                           & vlTOPp->divider__DOT__divisor_setup);
    vlTOPp->divider__DOT__divisor_setup = (0xffffffff80000000ULL 
                                           & vlTOPp->divider__DOT__divisor_setup);
    vlTOPp->divider__DOT__quotient = ((IData)(vlTOPp->divider__DOT__quotient_sign_reg)
                                       ? (~ ((IData)(1U) 
                                             + vlTOPp->divider__DOT__quotient_reg))
                                       : vlTOPp->divider__DOT__quotient_reg);
    vlTOPp->__Vtableidx1 = vlTOPp->divider__DOT__EP;
    vlTOPp->divider__DOT__setup_regs = vlTOPp->__Vtable1_divider__DOT__setup_regs
        [vlTOPp->__Vtableidx1];
    vlTOPp->divider__DOT__same = vlTOPp->__Vtable1_divider__DOT__same
        [vlTOPp->__Vtableidx1];
    vlTOPp->divider__DOT__zero_div = vlTOPp->__Vtable1_divider__DOT__zero_div
        [vlTOPp->__Vtableidx1];
    vlTOPp->divider__DOT__running = vlTOPp->__Vtable1_divider__DOT__running
        [vlTOPp->__Vtableidx1];
    vlTOPp->DONE_DIV = vlTOPp->__Vtable1_DONE_DIV[vlTOPp->__Vtableidx1];
    vlTOPp->BUSY_DIV = vlTOPp->__Vtable1_BUSY_DIV[vlTOPp->__Vtableidx1];
    vlTOPp->divider__DOT__division = (vlTOPp->divider__DOT__divisor_reg 
                                      > vlTOPp->divider__DOT__reminder_reg);
    vlTOPp->RES_DIV = (((3U == (IData)(vlTOPp->divider__DOT__cmd_reg)) 
                        | (0U == (IData)(vlTOPp->divider__DOT__cmd_reg)))
                        ? ((IData)(vlTOPp->divider__DOT__reminder_sign_reg)
                            ? (~ ((IData)(1U) + (IData)(vlTOPp->divider__DOT__reminder_reg)))
                            : (IData)(vlTOPp->divider__DOT__reminder_reg))
                        : vlTOPp->divider__DOT__quotient);
    vlTOPp->divider__DOT__shift_cpt_se = ((IData)(vlTOPp->divider__DOT__running)
                                           ? (0x3fU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlTOPp->divider__DOT__shift_cpt_reg)))
                                           : 0U);
    vlTOPp->divider__DOT__signed_inst = ((IData)(vlTOPp->divider__DOT__setup_regs) 
                                         & ((3U == (IData)(vlTOPp->CMD_RD)) 
                                            | (1U == (IData)(vlTOPp->CMD_RD))));
    vlTOPp->divider__DOT__quotient_se = ((IData)(vlTOPp->divider__DOT__setup_regs)
                                          ? 0U : ((IData)(vlTOPp->divider__DOT__same)
                                                   ? 1U
                                                   : 
                                                  ((IData)(vlTOPp->divider__DOT__zero_div)
                                                    ? 0xffffffffU
                                                    : 
                                                   ((IData)(vlTOPp->divider__DOT__running)
                                                     ? 
                                                    ((0xfffffffeU 
                                                      & (vlTOPp->divider__DOT__quotient_reg 
                                                         << 1U)) 
                                                     | (IData)(vlTOPp->divider__DOT__division))
                                                     : 0U))));
    vlTOPp->divider__DOT__reminder_se = (((IData)(vlTOPp->divider__DOT__setup_regs) 
                                          | (IData)(vlTOPp->divider__DOT__zero_div))
                                          ? (QData)((IData)(
                                                            ((((IData)(vlTOPp->divider__DOT__setup_regs) 
                                                               & (IData)(vlTOPp->divider__DOT__signed_inst)) 
                                                              & (vlTOPp->divider__DOT__op1 
                                                                 >> 0x1fU))
                                                              ? 
                                                             ((IData)(1U) 
                                                              + 
                                                              (~ vlTOPp->divider__DOT__op1))
                                                              : vlTOPp->divider__DOT__op1)))
                                          : (((IData)(vlTOPp->divider__DOT__running) 
                                              & (IData)(vlTOPp->divider__DOT__division))
                                              ? (vlTOPp->divider__DOT__reminder_reg 
                                                 - vlTOPp->divider__DOT__divisor_reg)
                                              : 0ULL));
    vlTOPp->divider__DOT__divisor_setup = ((0x800000007fffffffULL 
                                            & vlTOPp->divider__DOT__divisor_setup) 
                                           | ((QData)((IData)(
                                                              ((((IData)(vlTOPp->divider__DOT__setup_regs) 
                                                                 & (IData)(vlTOPp->divider__DOT__signed_inst)) 
                                                                & (vlTOPp->divider__DOT__op2 
                                                                   >> 0x1fU))
                                                                ? 
                                                               ((IData)(1U) 
                                                                + 
                                                                (~ vlTOPp->divider__DOT__op2))
                                                                : vlTOPp->divider__DOT__op2))) 
                                              << 0x1fU));
    vlTOPp->divider__DOT__divisor_se = ((IData)(vlTOPp->divider__DOT__setup_regs)
                                         ? vlTOPp->divider__DOT__divisor_setup
                                         : ((IData)(vlTOPp->divider__DOT__running)
                                             ? (0x7fffffffffffffffULL 
                                                & (vlTOPp->divider__DOT__divisor_reg 
                                                   >> 1U))
                                             : 0ULL));
}

void Vdivider::_eval_initial(Vdivider__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider::_eval_initial\n"); );
    Vdivider* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset_n = vlTOPp->reset_n;
}

void Vdivider::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider::final\n"); );
    // Variables
    Vdivider__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vdivider* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vdivider::_eval_settle(Vdivider__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider::_eval_settle\n"); );
    Vdivider* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vdivider::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset_n = VL_RAND_RESET_I(1);
    OP1_SE = VL_RAND_RESET_I(32);
    OP2_SE = VL_RAND_RESET_I(32);
    CMD_RD = VL_RAND_RESET_I(2);
    START_DIV = VL_RAND_RESET_I(1);
    DONE_DIV = VL_RAND_RESET_I(1);
    BUSY_DIV = VL_RAND_RESET_I(1);
    RES_DIV = VL_RAND_RESET_I(32);
    divider__DOT__EP = VL_RAND_RESET_I(3);
    divider__DOT__EF = VL_RAND_RESET_I(3);
    divider__DOT__cmd_reg = VL_RAND_RESET_I(2);
    divider__DOT__op1 = VL_RAND_RESET_I(32);
    divider__DOT__op2 = VL_RAND_RESET_I(32);
    divider__DOT__shift_cpt_se = VL_RAND_RESET_I(6);
    divider__DOT__shift_cpt_reg = VL_RAND_RESET_I(6);
    divider__DOT__divisor_se = VL_RAND_RESET_Q(64);
    divider__DOT__reminder_se = VL_RAND_RESET_Q(64);
    divider__DOT__divisor_reg = VL_RAND_RESET_Q(64);
    divider__DOT__reminder_reg = VL_RAND_RESET_Q(64);
    divider__DOT__divisor_setup = VL_RAND_RESET_Q(64);
    divider__DOT__quotient_se = VL_RAND_RESET_I(32);
    divider__DOT__quotient_reg = VL_RAND_RESET_I(32);
    divider__DOT__quotient = VL_RAND_RESET_I(32);
    divider__DOT__quotient_sign_reg = VL_RAND_RESET_I(1);
    divider__DOT__reminder_sign_reg = VL_RAND_RESET_I(1);
    divider__DOT__signed_inst = VL_RAND_RESET_I(1);
    divider__DOT__division = VL_RAND_RESET_I(1);
    divider__DOT__setup_regs = VL_RAND_RESET_I(1);
    divider__DOT__same = VL_RAND_RESET_I(1);
    divider__DOT__zero_div = VL_RAND_RESET_I(1);
    divider__DOT__running = VL_RAND_RESET_I(1);
    __Vtableidx1 = 0;
    __Vtable1_divider__DOT__setup_regs[0] = 0U;
    __Vtable1_divider__DOT__setup_regs[1] = 1U;
    __Vtable1_divider__DOT__setup_regs[2] = 0U;
    __Vtable1_divider__DOT__setup_regs[3] = 0U;
    __Vtable1_divider__DOT__setup_regs[4] = 0U;
    __Vtable1_divider__DOT__setup_regs[5] = 0U;
    __Vtable1_divider__DOT__setup_regs[6] = 0U;
    __Vtable1_divider__DOT__setup_regs[7] = 0U;
    __Vtable1_divider__DOT__same[0] = 0U;
    __Vtable1_divider__DOT__same[1] = 0U;
    __Vtable1_divider__DOT__same[2] = 0U;
    __Vtable1_divider__DOT__same[3] = 1U;
    __Vtable1_divider__DOT__same[4] = 0U;
    __Vtable1_divider__DOT__same[5] = 0U;
    __Vtable1_divider__DOT__same[6] = 0U;
    __Vtable1_divider__DOT__same[7] = 0U;
    __Vtable1_divider__DOT__zero_div[0] = 0U;
    __Vtable1_divider__DOT__zero_div[1] = 0U;
    __Vtable1_divider__DOT__zero_div[2] = 1U;
    __Vtable1_divider__DOT__zero_div[3] = 0U;
    __Vtable1_divider__DOT__zero_div[4] = 0U;
    __Vtable1_divider__DOT__zero_div[5] = 0U;
    __Vtable1_divider__DOT__zero_div[6] = 0U;
    __Vtable1_divider__DOT__zero_div[7] = 0U;
    __Vtable1_divider__DOT__running[0] = 0U;
    __Vtable1_divider__DOT__running[1] = 0U;
    __Vtable1_divider__DOT__running[2] = 0U;
    __Vtable1_divider__DOT__running[3] = 0U;
    __Vtable1_divider__DOT__running[4] = 1U;
    __Vtable1_divider__DOT__running[5] = 0U;
    __Vtable1_divider__DOT__running[6] = 0U;
    __Vtable1_divider__DOT__running[7] = 0U;
    __Vtable1_DONE_DIV[0] = 0U;
    __Vtable1_DONE_DIV[1] = 0U;
    __Vtable1_DONE_DIV[2] = 0U;
    __Vtable1_DONE_DIV[3] = 0U;
    __Vtable1_DONE_DIV[4] = 0U;
    __Vtable1_DONE_DIV[5] = 1U;
    __Vtable1_DONE_DIV[6] = 0U;
    __Vtable1_DONE_DIV[7] = 0U;
    __Vtable1_BUSY_DIV[0] = 0U;
    __Vtable1_BUSY_DIV[1] = 1U;
    __Vtable1_BUSY_DIV[2] = 1U;
    __Vtable1_BUSY_DIV[3] = 1U;
    __Vtable1_BUSY_DIV[4] = 1U;
    __Vtable1_BUSY_DIV[5] = 1U;
    __Vtable1_BUSY_DIV[6] = 0U;
    __Vtable1_BUSY_DIV[7] = 0U;
}
