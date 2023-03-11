// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vshifter.h for the primary calling header

#include "Vshifter.h"
#include "Vshifter__Syms.h"

//==========

void Vshifter::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vshifter::eval\n"); );
    Vshifter__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vshifter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("EXE/shifter.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vshifter::_eval_initial_loop(Vshifter__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("EXE/shifter.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vshifter::_combo__TOP__1(Vshifter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshifter::_combo__TOP__1\n"); );
    Vshifter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((0x10U & (IData)(vlTOPp->SHIFT_VAL_SE))) {
        vlTOPp->shifter__DOT__lshift16 = (0xffff0000U 
                                          & (vlTOPp->DIN_SE 
                                             << 0x10U));
        vlTOPp->shifter__DOT__rshift16 = ((((2U & (IData)(vlTOPp->CMD_SE))
                                             ? (0xffffU 
                                                & (- (IData)(
                                                             (1U 
                                                              & (vlTOPp->DIN_SE 
                                                                 >> 0x1fU)))))
                                             : 0U) 
                                           << 0x10U) 
                                          | (0xffffU 
                                             & (vlTOPp->DIN_SE 
                                                >> 0x10U)));
    } else {
        vlTOPp->shifter__DOT__lshift16 = vlTOPp->DIN_SE;
        vlTOPp->shifter__DOT__rshift16 = vlTOPp->DIN_SE;
    }
    if ((8U & (IData)(vlTOPp->SHIFT_VAL_SE))) {
        vlTOPp->shifter__DOT__lshift8 = (0xffffff00U 
                                         & (vlTOPp->shifter__DOT__lshift16 
                                            << 8U));
        vlTOPp->shifter__DOT__rshift8 = ((((2U & (IData)(vlTOPp->CMD_SE))
                                            ? (0xffU 
                                               & (- (IData)(
                                                            (1U 
                                                             & (vlTOPp->DIN_SE 
                                                                >> 0x1fU)))))
                                            : 0U) << 0x18U) 
                                         | (0xffffffU 
                                            & (vlTOPp->shifter__DOT__rshift16 
                                               >> 8U)));
    } else {
        vlTOPp->shifter__DOT__lshift8 = vlTOPp->shifter__DOT__lshift16;
        vlTOPp->shifter__DOT__rshift8 = vlTOPp->shifter__DOT__rshift16;
    }
    if ((4U & (IData)(vlTOPp->SHIFT_VAL_SE))) {
        vlTOPp->shifter__DOT__lshift4 = (0xfffffff0U 
                                         & (vlTOPp->shifter__DOT__lshift8 
                                            << 4U));
        vlTOPp->shifter__DOT__rshift4 = ((((2U & (IData)(vlTOPp->CMD_SE))
                                            ? (0xfU 
                                               & (- (IData)(
                                                            (1U 
                                                             & (vlTOPp->DIN_SE 
                                                                >> 0x1fU)))))
                                            : 0U) << 0x1cU) 
                                         | (0xfffffffU 
                                            & (vlTOPp->shifter__DOT__rshift8 
                                               >> 4U)));
    } else {
        vlTOPp->shifter__DOT__lshift4 = vlTOPp->shifter__DOT__lshift8;
        vlTOPp->shifter__DOT__rshift4 = vlTOPp->shifter__DOT__rshift8;
    }
    if ((2U & (IData)(vlTOPp->SHIFT_VAL_SE))) {
        vlTOPp->shifter__DOT__lshift2 = (0xfffffffcU 
                                         & (vlTOPp->shifter__DOT__lshift4 
                                            << 2U));
        vlTOPp->shifter__DOT__rshift2 = ((((2U & (IData)(vlTOPp->CMD_SE))
                                            ? (3U & 
                                               (- (IData)(
                                                          (1U 
                                                           & (vlTOPp->DIN_SE 
                                                              >> 0x1fU)))))
                                            : 0U) << 0x1eU) 
                                         | (0x3fffffffU 
                                            & (vlTOPp->shifter__DOT__rshift4 
                                               >> 2U)));
    } else {
        vlTOPp->shifter__DOT__lshift2 = vlTOPp->shifter__DOT__lshift4;
        vlTOPp->shifter__DOT__rshift2 = vlTOPp->shifter__DOT__rshift4;
    }
    vlTOPp->DOUT_SE = ((0U == (IData)(vlTOPp->CMD_SE))
                        ? ((1U & (IData)(vlTOPp->SHIFT_VAL_SE))
                            ? (0xfffffffeU & (vlTOPp->shifter__DOT__lshift2 
                                              << 1U))
                            : vlTOPp->shifter__DOT__lshift2)
                        : ((1U & (IData)(vlTOPp->SHIFT_VAL_SE))
                            ? ((0x80000000U & (((IData)(vlTOPp->CMD_SE) 
                                                << 0x1eU) 
                                               & vlTOPp->DIN_SE)) 
                               | (0x7fffffffU & (vlTOPp->shifter__DOT__rshift2 
                                                 >> 1U)))
                            : vlTOPp->shifter__DOT__rshift2));
}

void Vshifter::_eval(Vshifter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshifter::_eval\n"); );
    Vshifter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vshifter::_change_request(Vshifter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshifter::_change_request\n"); );
    Vshifter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vshifter::_change_request_1(Vshifter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshifter::_change_request_1\n"); );
    Vshifter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vshifter::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshifter::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((SHIFT_VAL_SE & 0xe0U))) {
        Verilated::overWidthError("SHIFT_VAL_SE");}
    if (VL_UNLIKELY((CMD_SE & 0xfcU))) {
        Verilated::overWidthError("CMD_SE");}
}
#endif  // VL_DEBUG
