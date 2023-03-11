// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vwbk.h for the primary calling header

#include "Vwbk.h"
#include "Vwbk__Syms.h"

//==========

void Vwbk::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vwbk::eval\n"); );
    Vwbk__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vwbk* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("WBK/wbk.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vwbk::_eval_initial_loop(Vwbk__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("WBK/wbk.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vwbk::_combo__TOP__1(Vwbk__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwbk::_combo__TOP__1\n"); );
    Vwbk* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->DEST_SW = vlTOPp->MEM_DEST_RM;
    vlTOPp->MEM2WBK_POP_SW = (1U & (~ (IData)(vlTOPp->MEM2WBK_EMPTY_SM)));
    vlTOPp->WB_SW = ((IData)(vlTOPp->WB_RM) & (~ (IData)(vlTOPp->MEM2WBK_EMPTY_SM)));
    vlTOPp->DATA_SW = ((IData)(vlTOPp->CSR_WENABLE_RM)
                        ? vlTOPp->CSR_RDATA_RM : ((IData)(vlTOPp->MULT_INST_RM)
                                                   ? vlTOPp->RES_RX2
                                                   : vlTOPp->MEM_RES_RM));
}

void Vwbk::_eval(Vwbk__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwbk::_eval\n"); );
    Vwbk* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vwbk::_change_request(Vwbk__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwbk::_change_request\n"); );
    Vwbk* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vwbk::_change_request_1(Vwbk__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwbk::_change_request_1\n"); );
    Vwbk* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vwbk::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwbk::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset_n & 0xfeU))) {
        Verilated::overWidthError("reset_n");}
    if (VL_UNLIKELY((MEM_DEST_RM & 0xc0U))) {
        Verilated::overWidthError("MEM_DEST_RM");}
    if (VL_UNLIKELY((WB_RM & 0xfeU))) {
        Verilated::overWidthError("WB_RM");}
    if (VL_UNLIKELY((CSR_WENABLE_RM & 0xfeU))) {
        Verilated::overWidthError("CSR_WENABLE_RM");}
    if (VL_UNLIKELY((CURRENT_MODE_SM & 0xfcU))) {
        Verilated::overWidthError("CURRENT_MODE_SM");}
    if (VL_UNLIKELY((MEM2WBK_EMPTY_SM & 0xfeU))) {
        Verilated::overWidthError("MEM2WBK_EMPTY_SM");}
    if (VL_UNLIKELY((MULT_INST_RM & 0xfeU))) {
        Verilated::overWidthError("MULT_INST_RM");}
}
#endif  // VL_DEBUG
