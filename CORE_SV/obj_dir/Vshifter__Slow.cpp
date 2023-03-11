// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vshifter.h for the primary calling header

#include "Vshifter.h"
#include "Vshifter__Syms.h"

//==========

VL_CTOR_IMP(Vshifter) {
    Vshifter__Syms* __restrict vlSymsp = __VlSymsp = new Vshifter__Syms(this, name());
    Vshifter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vshifter::__Vconfigure(Vshifter__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vshifter::~Vshifter() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vshifter::_eval_initial(Vshifter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshifter::_eval_initial\n"); );
    Vshifter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vshifter::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshifter::final\n"); );
    // Variables
    Vshifter__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vshifter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vshifter::_eval_settle(Vshifter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshifter::_eval_settle\n"); );
    Vshifter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vshifter::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshifter::_ctor_var_reset\n"); );
    // Body
    DIN_SE = VL_RAND_RESET_I(32);
    SHIFT_VAL_SE = VL_RAND_RESET_I(5);
    CMD_SE = VL_RAND_RESET_I(2);
    DOUT_SE = VL_RAND_RESET_I(32);
    shifter__DOT__lshift16 = VL_RAND_RESET_I(32);
    shifter__DOT__lshift8 = VL_RAND_RESET_I(32);
    shifter__DOT__lshift4 = VL_RAND_RESET_I(32);
    shifter__DOT__lshift2 = VL_RAND_RESET_I(32);
    shifter__DOT__rshift16 = VL_RAND_RESET_I(32);
    shifter__DOT__rshift8 = VL_RAND_RESET_I(32);
    shifter__DOT__rshift4 = VL_RAND_RESET_I(32);
    shifter__DOT__rshift2 = VL_RAND_RESET_I(32);
}
