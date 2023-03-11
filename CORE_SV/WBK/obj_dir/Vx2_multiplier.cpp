// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vx2_multiplier.h for the primary calling header

#include "Vx2_multiplier.h"
#include "Vx2_multiplier__Syms.h"

//==========

void Vx2_multiplier::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vx2_multiplier::eval\n"); );
    Vx2_multiplier__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vx2_multiplier* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("x2_multiplier.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vx2_multiplier::_eval_initial_loop(Vx2_multiplier__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("x2_multiplier.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vx2_multiplier::_combo__TOP__1(Vx2_multiplier__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vx2_multiplier::_combo__TOP__1\n"); );
    Vx2_multiplier* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->X1X2_POP_SX2 = (1U & (~ (IData)(vlTOPp->X1X2_EMPTY_SX1)));
}

VL_INLINE_OPT void Vx2_multiplier::_sequent__TOP__3(Vx2_multiplier__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vx2_multiplier::_sequent__TOP__3\n"); );
    Vx2_multiplier* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->x2_multiplier__DOT__res = ((IData)(vlTOPp->reset_n)
                                        ? ((((QData)((IData)(
                                                             vlTOPp->RES_RX1[1U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlTOPp->RES_RX1[0U]))) 
                                           + (((QData)((IData)(
                                                               vlTOPp->RES_RX1[3U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlTOPp->RES_RX1[2U]))))
                                        : 0ULL);
}

VL_INLINE_OPT void Vx2_multiplier::_combo__TOP__4(Vx2_multiplier__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vx2_multiplier::_combo__TOP__4\n"); );
    Vx2_multiplier* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->RES_RX2 = ((IData)(vlTOPp->SELECT_MSB_RX1)
                        ? (IData)((vlTOPp->x2_multiplier__DOT__res 
                                   >> 0x20U)) : (IData)(vlTOPp->x2_multiplier__DOT__res));
}

void Vx2_multiplier::_eval(Vx2_multiplier__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vx2_multiplier::_eval\n"); );
    Vx2_multiplier* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->reset_n)) & (IData)(vlTOPp->__Vclklast__TOP__reset_n)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset_n = vlTOPp->reset_n;
}

VL_INLINE_OPT QData Vx2_multiplier::_change_request(Vx2_multiplier__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vx2_multiplier::_change_request\n"); );
    Vx2_multiplier* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vx2_multiplier::_change_request_1(Vx2_multiplier__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vx2_multiplier::_change_request_1\n"); );
    Vx2_multiplier* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vx2_multiplier::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vx2_multiplier::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset_n & 0xfeU))) {
        Verilated::overWidthError("reset_n");}
    if (VL_UNLIKELY((SELECT_MSB_RX1 & 0xfeU))) {
        Verilated::overWidthError("SELECT_MSB_RX1");}
    if (VL_UNLIKELY((SIGNED_RES_RX1 & 0xfeU))) {
        Verilated::overWidthError("SIGNED_RES_RX1");}
    if (VL_UNLIKELY((X1X2_EMPTY_SX1 & 0xfeU))) {
        Verilated::overWidthError("X1X2_EMPTY_SX1");}
}
#endif  // VL_DEBUG
