// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfifo.h for the primary calling header

#include "Vfifo.h"
#include "Vfifo__Syms.h"

//==========

VL_CTOR_IMP(Vfifo) {
    Vfifo__Syms* __restrict vlSymsp = __VlSymsp = new Vfifo__Syms(this, name());
    Vfifo* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vfifo::__Vconfigure(Vfifo__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vfifo::~Vfifo() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vfifo::_initial__TOP__2(Vfifo__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfifo::_initial__TOP__2\n"); );
    Vfifo* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->fifo__DOT__data_v = 0U;
}

void Vfifo::_settle__TOP__3(Vfifo__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfifo::_settle__TOP__3\n"); );
    Vfifo* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->DOUT = vlTOPp->fifo__DOT__data;
    vlTOPp->EMPTY = (1U & (~ (IData)(vlTOPp->fifo__DOT__data_v)));
    vlTOPp->FULL = (((IData)(vlTOPp->fifo__DOT__data_v) 
                     & (~ (IData)(vlTOPp->POP))) ? 1U
                     : 0U);
}

void Vfifo::_eval_initial(Vfifo__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfifo::_eval_initial\n"); );
    Vfifo* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->_initial__TOP__2(vlSymsp);
}

void Vfifo::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfifo::final\n"); );
    // Variables
    Vfifo__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vfifo* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfifo::_eval_settle(Vfifo__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfifo::_eval_settle\n"); );
    Vfifo* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

void Vfifo::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfifo::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset_n = VL_RAND_RESET_I(1);
    DIN = VL_RAND_RESET_I(1);
    PUSH = VL_RAND_RESET_I(1);
    POP = VL_RAND_RESET_I(1);
    FULL = VL_RAND_RESET_I(1);
    EMPTY = VL_RAND_RESET_I(1);
    DOUT = VL_RAND_RESET_I(1);
    fifo__DOT__data = VL_RAND_RESET_I(1);
    fifo__DOT__data_v = VL_RAND_RESET_I(1);
}
