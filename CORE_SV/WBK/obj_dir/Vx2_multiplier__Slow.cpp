// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vx2_multiplier.h for the primary calling header

#include "Vx2_multiplier.h"
#include "Vx2_multiplier__Syms.h"

//==========

VL_CTOR_IMP(Vx2_multiplier) {
    Vx2_multiplier__Syms* __restrict vlSymsp = __VlSymsp = new Vx2_multiplier__Syms(this, name());
    Vx2_multiplier* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vx2_multiplier::__Vconfigure(Vx2_multiplier__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vx2_multiplier::~Vx2_multiplier() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vx2_multiplier::_settle__TOP__2(Vx2_multiplier__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vx2_multiplier::_settle__TOP__2\n"); );
    Vx2_multiplier* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->X1X2_POP_SX2 = (1U & (~ (IData)(vlTOPp->X1X2_EMPTY_SX1)));
    vlTOPp->RES_RX2 = ((IData)(vlTOPp->SELECT_MSB_RX1)
                        ? (IData)((vlTOPp->x2_multiplier__DOT__res 
                                   >> 0x20U)) : (IData)(vlTOPp->x2_multiplier__DOT__res));
}

void Vx2_multiplier::_eval_initial(Vx2_multiplier__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vx2_multiplier::_eval_initial\n"); );
    Vx2_multiplier* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset_n = vlTOPp->reset_n;
}

void Vx2_multiplier::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vx2_multiplier::final\n"); );
    // Variables
    Vx2_multiplier__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vx2_multiplier* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vx2_multiplier::_eval_settle(Vx2_multiplier__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vx2_multiplier::_eval_settle\n"); );
    Vx2_multiplier* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vx2_multiplier::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vx2_multiplier::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset_n = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, RES_RX1);
    SELECT_MSB_RX1 = VL_RAND_RESET_I(1);
    SIGNED_RES_RX1 = VL_RAND_RESET_I(1);
    X1X2_EMPTY_SX1 = VL_RAND_RESET_I(1);
    RES_RX2 = VL_RAND_RESET_I(32);
    X1X2_POP_SX2 = VL_RAND_RESET_I(1);
    x2_multiplier__DOT__res = VL_RAND_RESET_Q(64);
}
