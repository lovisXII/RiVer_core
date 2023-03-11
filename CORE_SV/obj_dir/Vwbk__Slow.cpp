// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vwbk.h for the primary calling header

#include "Vwbk.h"
#include "Vwbk__Syms.h"

//==========

VL_CTOR_IMP(Vwbk) {
    Vwbk__Syms* __restrict vlSymsp = __VlSymsp = new Vwbk__Syms(this, name());
    Vwbk* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vwbk::__Vconfigure(Vwbk__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vwbk::~Vwbk() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vwbk::_eval_initial(Vwbk__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwbk::_eval_initial\n"); );
    Vwbk* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vwbk::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwbk::final\n"); );
    // Variables
    Vwbk__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vwbk* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vwbk::_eval_settle(Vwbk__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwbk::_eval_settle\n"); );
    Vwbk* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vwbk::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwbk::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset_n = VL_RAND_RESET_I(1);
    MEM_RES_RM = VL_RAND_RESET_I(32);
    MEM_DEST_RM = VL_RAND_RESET_I(6);
    WB_RM = VL_RAND_RESET_I(1);
    PC_MEM2WBK_RM = VL_RAND_RESET_I(32);
    CSR_RDATA_RM = VL_RAND_RESET_I(32);
    CSR_WENABLE_RM = VL_RAND_RESET_I(1);
    CURRENT_MODE_SM = VL_RAND_RESET_I(2);
    MEM2WBK_EMPTY_SM = VL_RAND_RESET_I(1);
    MEM2WBK_POP_SW = VL_RAND_RESET_I(1);
    MULT_INST_RM = VL_RAND_RESET_I(1);
    RES_RX2 = VL_RAND_RESET_I(32);
    DATA_SW = VL_RAND_RESET_I(32);
    DEST_SW = VL_RAND_RESET_I(6);
    WB_SW = VL_RAND_RESET_I(1);
}
