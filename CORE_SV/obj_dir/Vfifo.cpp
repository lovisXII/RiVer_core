// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfifo.h for the primary calling header

#include "Vfifo.h"
#include "Vfifo__Syms.h"

//==========

void Vfifo::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfifo::eval\n"); );
    Vfifo__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vfifo* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("USEFULL/fifo.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vfifo::_eval_initial_loop(Vfifo__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("USEFULL/fifo.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vfifo::_sequent__TOP__1(Vfifo__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfifo::_sequent__TOP__1\n"); );
    Vfifo* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__fifo__DOT__data_v;
    // Body
    __Vdly__fifo__DOT__data_v = vlTOPp->fifo__DOT__data_v;
    if (vlTOPp->reset_n) {
        __Vdly__fifo__DOT__data_v = (1U & ((IData)(vlTOPp->fifo__DOT__data_v)
                                            ? ((~ (IData)(vlTOPp->POP)) 
                                               | (IData)(vlTOPp->PUSH))
                                            : (IData)(vlTOPp->PUSH)));
        if (vlTOPp->fifo__DOT__data_v) {
            if (((IData)(vlTOPp->PUSH) & (IData)(vlTOPp->POP))) {
                vlTOPp->fifo__DOT__data = vlTOPp->DIN;
            }
        } else {
            if (vlTOPp->PUSH) {
                vlTOPp->fifo__DOT__data = vlTOPp->DIN;
            }
        }
    } else {
        __Vdly__fifo__DOT__data_v = 0U;
    }
    vlTOPp->fifo__DOT__data_v = __Vdly__fifo__DOT__data_v;
    vlTOPp->DOUT = vlTOPp->fifo__DOT__data;
    vlTOPp->EMPTY = (1U & (~ (IData)(vlTOPp->fifo__DOT__data_v)));
}

VL_INLINE_OPT void Vfifo::_combo__TOP__4(Vfifo__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfifo::_combo__TOP__4\n"); );
    Vfifo* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->FULL = (((IData)(vlTOPp->fifo__DOT__data_v) 
                     & (~ (IData)(vlTOPp->POP))) ? 1U
                     : 0U);
}

void Vfifo::_eval(Vfifo__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfifo::_eval\n"); );
    Vfifo* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vfifo::_change_request(Vfifo__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfifo::_change_request\n"); );
    Vfifo* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vfifo::_change_request_1(Vfifo__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfifo::_change_request_1\n"); );
    Vfifo* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vfifo::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfifo::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset_n & 0xfeU))) {
        Verilated::overWidthError("reset_n");}
    if (VL_UNLIKELY((DIN & 0xfeU))) {
        Verilated::overWidthError("DIN");}
    if (VL_UNLIKELY((PUSH & 0xfeU))) {
        Verilated::overWidthError("PUSH");}
    if (VL_UNLIKELY((POP & 0xfeU))) {
        Verilated::overWidthError("POP");}
}
#endif  // VL_DEBUG
