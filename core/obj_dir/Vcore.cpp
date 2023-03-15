// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcore.h for the primary calling header

#include "Vcore.h"
#include "Vcore__Syms.h"

//==========

void Vcore::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcore::eval\n"); );
    Vcore__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vcore* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("core.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vcore::_eval_initial_loop(Vcore__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
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
            VL_FATAL_MT("core.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vcore::_combo__TOP__3(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_combo__TOP__3\n"); );
    Vcore* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__core__IC_INST_SI, vlTOPp->IC_INST_SI);
    VL_ASSIGN_ISI(32,vlTOPp->__Vcellinp__core__MCACHE_RESULT_SM, vlTOPp->MCACHE_RESULT_SM);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__core__IC_STALL_SI, vlTOPp->IC_STALL_SI);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__core__MCACHE_STALL_SM, vlTOPp->MCACHE_STALL_SM);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__core__clk, vlTOPp->clk);
}

VL_INLINE_OPT void Vcore::_sequent__TOP__5(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_sequent__TOP__5\n"); );
    Vcore* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__core__DOT__x1_mult__DOT__x1x2__DOT__data_v 
        = vlTOPp->core__DOT__x1_mult__DOT__x1x2__DOT__data_v;
    vlTOPp->__Vdly__core__DOT__dec_i__DOT__dec2if__DOT__data_v 
        = vlTOPp->core__DOT__dec_i__DOT__dec2if__DOT__data_v;
    vlTOPp->__Vdly__core__DOT__x0_mult__DOT__x0x1__DOT__data_v 
        = vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data_v;
    vlTOPp->__Vdly__core__DOT__dec_i__DOT__dec2exe__DOT__data_v 
        = vlTOPp->core__DOT__dec_i__DOT__dec2exe__DOT__data_v;
    vlTOPp->__Vdly__core__DOT__mem_i__DOT__mem2wbk__DOT__data_v 
        = vlTOPp->core__DOT__mem_i__DOT__mem2wbk__DOT__data_v;
    vlTOPp->__Vdly__core__DOT__exec_i__DOT__exe2mem__DOT__data_v 
        = vlTOPp->core__DOT__exec_i__DOT__exe2mem__DOT__data_v;
    vlTOPp->__Vdly__core__DOT__ifetch_i__DOT__if2dec__DOT__data_v 
        = vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data_v;
    vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__i = 0x20U;
    if ((1U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x20U;
    }
    if ((2U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x21U;
    }
    if ((4U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x22U;
    }
    if ((8U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x23U;
    }
    if ((0x10U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x24U;
    }
    if ((0x20U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x25U;
    }
    if ((0x40U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x26U;
    }
    if ((0x80U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x27U;
    }
    if ((0x100U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x28U;
    }
    if ((0x200U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x29U;
    }
    if ((0x400U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x2aU;
    }
    if ((0x800U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x2bU;
    }
    if ((0x1000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x2cU;
    }
    if ((0x2000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x2dU;
    }
    if ((0x4000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x2eU;
    }
    if ((0x8000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x2fU;
    }
    if ((0x10000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x30U;
    }
    if ((0x20000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x31U;
    }
    if ((0x40000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x32U;
    }
    if ((0x80000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x33U;
    }
    if ((0x100000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x34U;
    }
    if ((0x200000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x35U;
    }
    if ((0x400000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x36U;
    }
    if ((0x800000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x37U;
    }
    if ((0x1000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x38U;
    }
    if ((0x2000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x39U;
    }
    if ((0x4000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x3aU;
    }
    if ((0x8000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x3bU;
    }
    if ((0x10000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x3cU;
    }
    if ((0x20000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x3dU;
    }
    if ((0x40000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x3eU;
    }
    if ((0x80000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk3__DOT__j = 0x3fU;
    }
    if ((1U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((2U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((4U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((8U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x10U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x20U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x40U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x80U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x100U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x200U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x400U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x800U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x1000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x2000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x4000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x8000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x10000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x20000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x40000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x80000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x100000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x200000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x400000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x800000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x1000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x2000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x4000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x8000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x10000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x20000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x40000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
    if ((0x80000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__unnamedblk4__DOT__k = 0x40U;
        }
    }
}

VL_INLINE_OPT void Vcore::_sequent__TOP__6(Vcore__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcore::_sequent__TOP__6\n"); );
    Vcore* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v0;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v1;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v2;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v3;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v4;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v5;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v6;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v7;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v8;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v9;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v10;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v11;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v12;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v13;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v14;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v15;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v16;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v17;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v18;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v19;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v20;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v21;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v22;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v23;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v24;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v25;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v26;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v27;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v28;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v29;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v30;
    CData/*0:0*/ __Vdlyvset__core__DOT__x0_mult__DOT__product__v31;
    WData/*127:0*/ __Vtemp34[4];
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v0;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v1;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v2;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v3;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v4;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v5;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v6;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v7;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v8;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v9;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v10;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v11;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v12;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v13;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v14;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v15;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v16;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v17;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v18;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v19;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v20;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v21;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v22;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v23;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v24;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v25;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v26;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v27;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v28;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v29;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v30;
    QData/*63:0*/ __Vdlyvval__core__DOT__x0_mult__DOT__product__v31;
    // Body
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v0 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v1 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v2 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v3 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v4 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v5 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v6 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v7 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v8 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v9 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v10 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v11 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v12 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v13 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v14 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v15 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v16 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v17 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v18 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v19 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v20 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v21 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v22 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v23 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v24 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v25 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v26 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v27 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v28 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v29 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v30 = 0U;
    __Vdlyvset__core__DOT__x0_mult__DOT__product__v31 = 0U;
    vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__divisor_reg 
        = vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__divisor_se;
    vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__quotient_reg 
        = vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__quotient_se;
    if (vlTOPp->__Vcellinp__core__reset_n) {
        vlTOPp->__Vdly__core__DOT__x1_mult__DOT__x1x2__DOT__data_v 
            = ((IData)(vlTOPp->core__DOT__x1_mult__DOT__x1x2__DOT__data_v)
                ? ((IData)(vlTOPp->core__DOT__X1X2_EMPTY_SX1) 
                   | (IData)(vlTOPp->core__DOT__x1_mult__DOT__x1x2_push))
                : (IData)(vlTOPp->core__DOT__x1_mult__DOT__x1x2_push));
        if (vlTOPp->core__DOT__x1_mult__DOT__x1x2__DOT__data_v) {
            if (((IData)(vlTOPp->core__DOT__x1_mult__DOT__x1x2_push) 
                 & (~ (IData)(vlTOPp->core__DOT__X1X2_EMPTY_SX1)))) {
                vlTOPp->core__DOT__x1_mult__DOT__x1x2__DOT__data[0U] 
                    = vlTOPp->core__DOT__x1_mult__DOT__x1x2_din[0U];
                vlTOPp->core__DOT__x1_mult__DOT__x1x2__DOT__data[1U] 
                    = vlTOPp->core__DOT__x1_mult__DOT__x1x2_din[1U];
                vlTOPp->core__DOT__x1_mult__DOT__x1x2__DOT__data[2U] 
                    = vlTOPp->core__DOT__x1_mult__DOT__x1x2_din[2U];
                vlTOPp->core__DOT__x1_mult__DOT__x1x2__DOT__data[3U] 
                    = vlTOPp->core__DOT__x1_mult__DOT__x1x2_din[3U];
                vlTOPp->core__DOT__x1_mult__DOT__x1x2__DOT__data[4U] 
                    = vlTOPp->core__DOT__x1_mult__DOT__x1x2_din[4U];
            }
        } else {
            if (vlTOPp->core__DOT__x1_mult__DOT__x1x2_push) {
                vlTOPp->core__DOT__x1_mult__DOT__x1x2__DOT__data[0U] 
                    = vlTOPp->core__DOT__x1_mult__DOT__x1x2_din[0U];
                vlTOPp->core__DOT__x1_mult__DOT__x1x2__DOT__data[1U] 
                    = vlTOPp->core__DOT__x1_mult__DOT__x1x2_din[1U];
                vlTOPp->core__DOT__x1_mult__DOT__x1x2__DOT__data[2U] 
                    = vlTOPp->core__DOT__x1_mult__DOT__x1x2_din[2U];
                vlTOPp->core__DOT__x1_mult__DOT__x1x2__DOT__data[3U] 
                    = vlTOPp->core__DOT__x1_mult__DOT__x1x2_din[3U];
                vlTOPp->core__DOT__x1_mult__DOT__x1x2__DOT__data[4U] 
                    = vlTOPp->core__DOT__x1_mult__DOT__x1x2_din[4U];
            }
        }
    } else {
        vlTOPp->__Vdly__core__DOT__x1_mult__DOT__x1x2__DOT__data_v = 0U;
    }
    if (vlTOPp->__Vcellinp__core__reset_n) {
        vlTOPp->__Vdly__core__DOT__x0_mult__DOT__x0x1__DOT__data_v 
            = (1U & ((IData)(vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data_v)
                      ? ((~ (IData)(vlTOPp->core__DOT__X0X1_POP_SX1)) 
                         | (~ (IData)(vlTOPp->core__DOT__x0_mult__DOT__stall_sx0)))
                      : (~ (IData)(vlTOPp->core__DOT__x0_mult__DOT__stall_sx0))));
        if (vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data_v) {
            if (((~ (IData)(vlTOPp->core__DOT__x0_mult__DOT__stall_sx0)) 
                 & (IData)(vlTOPp->core__DOT__X0X1_POP_SX1))) {
                vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[0U] 
                    = vlTOPp->core__DOT__x0_mult__DOT__x0x1_din[0U];
                vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[1U] 
                    = vlTOPp->core__DOT__x0_mult__DOT__x0x1_din[1U];
                vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[2U] 
                    = vlTOPp->core__DOT__x0_mult__DOT__x0x1_din[2U];
                vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[3U] 
                    = vlTOPp->core__DOT__x0_mult__DOT__x0x1_din[3U];
                vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[4U] 
                    = vlTOPp->core__DOT__x0_mult__DOT__x0x1_din[4U];
                vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[5U] 
                    = vlTOPp->core__DOT__x0_mult__DOT__x0x1_din[5U];
                vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[6U] 
                    = vlTOPp->core__DOT__x0_mult__DOT__x0x1_din[6U];
                vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[7U] 
                    = vlTOPp->core__DOT__x0_mult__DOT__x0x1_din[7U];
                vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[8U] 
                    = vlTOPp->core__DOT__x0_mult__DOT__x0x1_din[8U];
                vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[9U] 
                    = vlTOPp->core__DOT__x0_mult__DOT__x0x1_din[9U];
                vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[0xaU] 
                    = vlTOPp->core__DOT__x0_mult__DOT__x0x1_din[0xaU];
            }
        } else {
            if ((1U & (~ (IData)(vlTOPp->core__DOT__x0_mult__DOT__stall_sx0)))) {
                vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[0U] 
                    = vlTOPp->core__DOT__x0_mult__DOT__x0x1_din[0U];
                vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[1U] 
                    = vlTOPp->core__DOT__x0_mult__DOT__x0x1_din[1U];
                vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[2U] 
                    = vlTOPp->core__DOT__x0_mult__DOT__x0x1_din[2U];
                vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[3U] 
                    = vlTOPp->core__DOT__x0_mult__DOT__x0x1_din[3U];
                vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[4U] 
                    = vlTOPp->core__DOT__x0_mult__DOT__x0x1_din[4U];
                vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[5U] 
                    = vlTOPp->core__DOT__x0_mult__DOT__x0x1_din[5U];
                vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[6U] 
                    = vlTOPp->core__DOT__x0_mult__DOT__x0x1_din[6U];
                vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[7U] 
                    = vlTOPp->core__DOT__x0_mult__DOT__x0x1_din[7U];
                vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[8U] 
                    = vlTOPp->core__DOT__x0_mult__DOT__x0x1_din[8U];
                vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[9U] 
                    = vlTOPp->core__DOT__x0_mult__DOT__x0x1_din[9U];
                vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[0xaU] 
                    = vlTOPp->core__DOT__x0_mult__DOT__x0x1_din[0xaU];
            }
        }
    } else {
        vlTOPp->__Vdly__core__DOT__x0_mult__DOT__x0x1__DOT__data_v = 0U;
    }
    if ((((IData)(vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__setup_regs) 
          | (IData)(vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__same)) 
         | (IData)(vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__zero_div))) {
        vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__reminder_sign_reg 
            = ((vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__op1 
                >> 0x1fU) & (IData)(vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__signed_inst));
    }
    if ((((IData)(vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__setup_regs) 
          | (IData)(vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__same)) 
         | (IData)(vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__zero_div))) {
        vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__quotient_sign_reg 
            = (((vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__op1 
                 ^ vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__op2) 
                >> 0x1fU) & (IData)(vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__signed_inst));
    }
    if (((((IData)(vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__setup_regs) 
           | (IData)(vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__zero_div)) 
          | (IData)(vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__same)) 
         | ((IData)(vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__running) 
            & (IData)(vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__division)))) {
        vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__reminder_reg 
            = vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__reminder_se;
    }
    if (vlTOPp->__Vcellinp__core__reset_n) {
        vlTOPp->__Vdly__core__DOT__ifetch_i__DOT__if2dec__DOT__data_v 
            = ((IData)(vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data_v)
                ? ((IData)(vlTOPp->core__DOT__dec_i__DOT__stall_sd) 
                   | (IData)(vlTOPp->core__DOT__ifetch_i__DOT__if2dec_push_si))
                : (IData)(vlTOPp->core__DOT__ifetch_i__DOT__if2dec_push_si));
        if (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data_v) {
            if (((IData)(vlTOPp->core__DOT__ifetch_i__DOT__if2dec_push_si) 
                 & (~ (IData)(vlTOPp->core__DOT__dec_i__DOT__stall_sd)))) {
                vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[0U] 
                    = vlTOPp->core__DOT__ifetch_i__DOT__if2dec_din[0U];
                vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                    = vlTOPp->core__DOT__ifetch_i__DOT__if2dec_din[1U];
                vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                    = vlTOPp->core__DOT__ifetch_i__DOT__if2dec_din[2U];
                vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[3U] 
                    = vlTOPp->core__DOT__ifetch_i__DOT__if2dec_din[3U];
            }
        } else {
            if (vlTOPp->core__DOT__ifetch_i__DOT__if2dec_push_si) {
                vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[0U] 
                    = vlTOPp->core__DOT__ifetch_i__DOT__if2dec_din[0U];
                vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                    = vlTOPp->core__DOT__ifetch_i__DOT__if2dec_din[1U];
                vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                    = vlTOPp->core__DOT__ifetch_i__DOT__if2dec_din[2U];
                vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[3U] 
                    = vlTOPp->core__DOT__ifetch_i__DOT__if2dec_din[3U];
            }
        }
    } else {
        vlTOPp->__Vdly__core__DOT__ifetch_i__DOT__if2dec__DOT__data_v = 0U;
    }
    if ((1U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffffeULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | (IData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                        & vlTOPp->core__DOT__x0_mult__DOT__op2)))));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffffdULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 1U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffffbULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 2U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffff7ULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 3U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffefULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 4U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffdfULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 5U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffbfULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 6U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffff7fULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 7U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffeffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 8U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffdffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 9U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffbffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 0xaU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 0xbU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 0xcU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 0xdU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 0xeU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 0xfU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 0x10U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 0x11U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 0x12U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 0x13U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 0x14U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 0x15U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & vlTOPp->core__DOT__x0_mult__DOT__op2)))) 
                  << 0x1fU));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v0 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v0 = 1U;
    }
    if ((2U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffffdULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 1U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffffbULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 1U)))) 
                  << 2U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffff7ULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 1U))))) 
                  << 3U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffefULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 1U))))) 
                  << 4U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffdfULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 1U))))) 
                  << 5U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffbfULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 1U))))) 
                  << 6U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffff7fULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 1U))))) 
                  << 7U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffeffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 1U))))) 
                  << 8U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffdffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 1U))))) 
                  << 9U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffbffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 1U))))) 
                  << 0xaU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 0xbU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 0xcU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 0xdU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 0xeU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 0xfU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 0x10U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 0x11U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 0x12U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 0x13U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 0x14U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 0x15U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 1U))))) 
                  << 0x20U));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v1 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v1 = 1U;
    }
    if ((4U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffffbULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 2U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffff7ULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 2U))))) 
                  << 3U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffefULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 2U)))) 
                  << 4U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffdfULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 2U))))) 
                  << 5U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffbfULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 2U))))) 
                  << 6U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffff7fULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 2U))))) 
                  << 7U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffeffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 2U))))) 
                  << 8U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffdffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 2U))))) 
                  << 9U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffbffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 2U))))) 
                  << 0xaU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 2U))))) 
                  << 0xbU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 0xcU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 0xdU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 0xeU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 0xfU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 0x10U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 0x11U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 0x12U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 0x13U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 0x14U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 0x15U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 2U))))) 
                  << 0x21U));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v2 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v2 = 1U;
    }
    if ((8U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffff7ULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 3U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffefULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 3U))))) 
                  << 4U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffdfULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 3U))))) 
                  << 5U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffbfULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 3U)))) 
                  << 6U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffff7fULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 3U))))) 
                  << 7U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffeffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 3U))))) 
                  << 8U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffdffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 3U))))) 
                  << 9U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffbffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 3U))))) 
                  << 0xaU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 3U))))) 
                  << 0xbU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 3U))))) 
                  << 0xcU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 0xdU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 0xeU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 0xfU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 0x10U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 0x11U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 0x12U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 0x13U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 0x14U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 0x15U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 3U))))) 
                  << 0x22U));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v3 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v3 = 1U;
    }
    if ((0x10U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffefULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 4U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffdfULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 4U))))) 
                  << 5U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffbfULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 4U))))) 
                  << 6U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffff7fULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 4U))))) 
                  << 7U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffeffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 4U)))) 
                  << 8U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffdffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 4U))))) 
                  << 9U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffbffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 4U))))) 
                  << 0xaU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 4U))))) 
                  << 0xbU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 4U))))) 
                  << 0xcU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 4U))))) 
                  << 0xdU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 0xeU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 0xfU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 0x10U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 0x11U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 0x12U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 0x13U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 0x14U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 0x15U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 4U))))) 
                  << 0x23U));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v4 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v4 = 1U;
    }
    if ((0x20U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffdfULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 5U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffbfULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 5U))))) 
                  << 6U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffff7fULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 5U))))) 
                  << 7U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffeffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 5U))))) 
                  << 8U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffdffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 5U))))) 
                  << 9U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffbffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 5U)))) 
                  << 0xaU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 5U))))) 
                  << 0xbU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 5U))))) 
                  << 0xcU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 5U))))) 
                  << 0xdU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 5U))))) 
                  << 0xeU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 0xfU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 0x10U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 0x11U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 0x12U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 0x13U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 0x14U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 0x15U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 5U))))) 
                  << 0x24U));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v5 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v5 = 1U;
    }
    if ((0x40U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffbfULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 6U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffff7fULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 6U))))) 
                  << 7U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffeffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 6U))))) 
                  << 8U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffdffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 6U))))) 
                  << 9U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffbffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 6U))))) 
                  << 0xaU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 6U))))) 
                  << 0xbU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 6U)))) 
                  << 0xcU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 6U))))) 
                  << 0xdU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 6U))))) 
                  << 0xeU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 6U))))) 
                  << 0xfU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 0x10U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 0x11U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 0x12U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 0x13U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 0x14U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 0x15U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 6U))))) 
                  << 0x25U));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v6 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v6 = 1U;
    }
    if ((0x80U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffff7fULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 7U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffeffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 7U))))) 
                  << 8U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffdffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 7U))))) 
                  << 9U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffbffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 7U))))) 
                  << 0xaU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 7U))))) 
                  << 0xbU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 7U))))) 
                  << 0xcU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 7U))))) 
                  << 0xdU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 7U)))) 
                  << 0xeU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 7U))))) 
                  << 0xfU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 7U))))) 
                  << 0x10U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 0x11U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 0x12U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 0x13U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 0x14U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 0x15U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 7U))))) 
                  << 0x26U));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v7 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v7 = 1U;
    }
    if ((0x100U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffeffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 8U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffdffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 8U))))) 
                  << 9U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffbffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 8U))))) 
                  << 0xaU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 8U))))) 
                  << 0xbU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 8U))))) 
                  << 0xcU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 8U))))) 
                  << 0xdU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 8U))))) 
                  << 0xeU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 8U))))) 
                  << 0xfU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 8U)))) 
                  << 0x10U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 8U))))) 
                  << 0x11U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 0x12U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 0x13U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 0x14U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 0x15U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 8U))))) 
                  << 0x27U));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v8 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v8 = 1U;
    }
    if ((0x200U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffdffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 9U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffbffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 9U))))) 
                  << 0xaU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 9U))))) 
                  << 0xbU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 9U))))) 
                  << 0xcU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 9U))))) 
                  << 0xdU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 9U))))) 
                  << 0xeU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 9U))))) 
                  << 0xfU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 9U))))) 
                  << 0x10U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 9U))))) 
                  << 0x11U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 9U)))) 
                  << 0x12U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 0x13U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 0x14U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 0x15U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 9U))))) 
                  << 0x28U));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v9 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v9 = 1U;
    }
    if ((0x400U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffbffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xaU))))) 
                  << 0xaU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xaU))))) 
                  << 0xbU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xaU))))) 
                  << 0xcU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xaU))))) 
                  << 0xdU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xaU))))) 
                  << 0xeU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xaU))))) 
                  << 0xfU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xaU))))) 
                  << 0x10U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xaU))))) 
                  << 0x11U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xaU))))) 
                  << 0x12U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xaU))))) 
                  << 0x13U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 0xaU)))) 
                  << 0x14U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x15U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x28U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x29U));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v10 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v10 = 1U;
    }
    if ((0x800U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xbU))))) 
                  << 0xbU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xbU))))) 
                  << 0xcU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xbU))))) 
                  << 0xdU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xbU))))) 
                  << 0xeU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xbU))))) 
                  << 0xfU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xbU))))) 
                  << 0x10U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xbU))))) 
                  << 0x11U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xbU))))) 
                  << 0x12U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xbU))))) 
                  << 0x13U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xbU))))) 
                  << 0x14U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x15U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 0xbU)))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x28U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x29U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x2aU));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v11 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v11 = 1U;
    }
    if ((0x1000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xcU))))) 
                  << 0xcU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xcU))))) 
                  << 0xdU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xcU))))) 
                  << 0xeU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xcU))))) 
                  << 0xfU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xcU))))) 
                  << 0x10U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xcU))))) 
                  << 0x11U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xcU))))) 
                  << 0x12U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xcU))))) 
                  << 0x13U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xcU))))) 
                  << 0x14U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xcU))))) 
                  << 0x15U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 0xcU)))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x28U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x29U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x2aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x2bU));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v12 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v12 = 1U;
    }
    if ((0x2000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xdU))))) 
                  << 0xdU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xdU))))) 
                  << 0xeU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xdU))))) 
                  << 0xfU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xdU))))) 
                  << 0x10U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xdU))))) 
                  << 0x11U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xdU))))) 
                  << 0x12U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xdU))))) 
                  << 0x13U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xdU))))) 
                  << 0x14U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xdU))))) 
                  << 0x15U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xdU))))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 0xdU)))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x28U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x29U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x2aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x2bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x2cU));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v13 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v13 = 1U;
    }
    if ((0x4000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xeU))))) 
                  << 0xeU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xeU))))) 
                  << 0xfU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xeU))))) 
                  << 0x10U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xeU))))) 
                  << 0x11U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xeU))))) 
                  << 0x12U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xeU))))) 
                  << 0x13U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xeU))))) 
                  << 0x14U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xeU))))) 
                  << 0x15U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xeU))))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xeU))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 0xeU)))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x28U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x29U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x2aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x2bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x2cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x2dU));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v14 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v14 = 1U;
    }
    if ((0x8000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xfU))))) 
                  << 0xfU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xfU))))) 
                  << 0x10U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xfU))))) 
                  << 0x11U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xfU))))) 
                  << 0x12U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xfU))))) 
                  << 0x13U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xfU))))) 
                  << 0x14U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xfU))))) 
                  << 0x15U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xfU))))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xfU))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0xfU))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 0xfU)))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x28U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x29U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x2aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x2bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x2cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x2dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x2eU));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v15 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v15 = 1U;
    }
    if ((0x10000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x10U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x10U))))) 
                  << 0x11U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x10U))))) 
                  << 0x12U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x10U))))) 
                  << 0x13U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x10U))))) 
                  << 0x14U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x10U))))) 
                  << 0x15U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x10U))))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x10U))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x10U))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x10U))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 0x10U)))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x28U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x29U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x2aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x2bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x2cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x2dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x2eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x2fU));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v16 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v16 = 1U;
    }
    if ((0x20000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x11U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x11U))))) 
                  << 0x12U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x11U))))) 
                  << 0x13U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x11U))))) 
                  << 0x14U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x11U))))) 
                  << 0x15U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x11U))))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x11U))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x11U))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x11U))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x11U))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 0x11U)))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x28U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x29U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x2aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x2bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x2cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x2dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x2eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x2fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x30U));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v17 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v17 = 1U;
    }
    if ((0x40000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x12U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x12U))))) 
                  << 0x13U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x12U))))) 
                  << 0x14U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x12U))))) 
                  << 0x15U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x12U))))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x12U))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x12U))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x12U))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x12U))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x12U))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 0x12U)))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x28U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x29U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x2aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x2bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x2cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x2dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x2eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x2fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x30U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x31U));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v18 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v18 = 1U;
    }
    if ((0x80000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x13U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x13U))))) 
                  << 0x14U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x13U))))) 
                  << 0x15U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x13U))))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x13U))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x13U))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x13U))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x13U))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x13U))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x13U))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 0x13U)))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x28U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x29U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x2aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x2bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x2cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x2dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x2eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x2fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x30U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x31U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x32U));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v19 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v19 = 1U;
    }
    if ((0x100000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x14U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x14U))))) 
                  << 0x15U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x14U))))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x14U))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x14U))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x14U))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x14U))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x14U))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x14U))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x14U))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 0x14U)))) 
                  << 0x28U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x29U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x2aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x2bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x2cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x2dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x2eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x2fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x30U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x31U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x32U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x33U));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v20 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v20 = 1U;
    }
    if ((0x200000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x15U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x15U))))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x15U))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x15U))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x15U))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x15U))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x15U))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x15U))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x15U))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x15U))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x28U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x29U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 0x15U)))) 
                  << 0x2aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x2bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x2cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x2dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x2eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x2fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x30U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x31U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x32U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x33U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffefffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x34U));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v21 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v21 = 1U;
    }
    if ((0x400000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x16U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x16U))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x16U))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x16U))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x16U))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x16U))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x16U))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x16U))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x16U))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x16U))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x28U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x29U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x2aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x2bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 0x16U)))) 
                  << 0x2cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x2dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x2eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x2fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x30U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x31U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x32U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x33U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffefffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x34U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffdfffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x35U));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v22 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v22 = 1U;
    }
    if ((0x800000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x17U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x17U))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x17U))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x17U))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x17U))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x17U))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x17U))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x17U))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x17U))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x17U))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x28U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x29U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x2aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x2bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x2cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x2dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 0x17U)))) 
                  << 0x2eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x2fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x30U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x31U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x32U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x33U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffefffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x34U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffdfffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x35U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffbfffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x36U));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v23 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v23 = 1U;
    }
    if ((0x1000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x18U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x18U))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x18U))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x18U))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x18U))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x18U))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x18U))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x18U))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x18U))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x18U))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x28U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x29U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x2aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x2bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x2cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x2dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x2eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x2fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 0x18U)))) 
                  << 0x30U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x31U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x32U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x33U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffefffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x34U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffdfffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x35U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffbfffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x36U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xff7fffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x37U));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v24 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v24 = 1U;
    }
    if ((0x2000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x19U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x19U))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x19U))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x19U))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x19U))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x19U))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x19U))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x19U))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x19U))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x19U))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x28U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x29U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x2aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x2bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x2cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x2dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x2eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x2fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x30U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x31U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 0x19U)))) 
                  << 0x32U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x33U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffefffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x34U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffdfffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x35U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffbfffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x36U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xff7fffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x37U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfeffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x38U));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v25 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v25 = 1U;
    }
    if ((0x4000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x1aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1aU))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1aU))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1aU))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1aU))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1aU))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1aU))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1aU))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1aU))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1aU))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x28U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x29U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x2aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x2bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x2cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x2dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x2eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x2fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x30U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x31U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x32U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x33U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffefffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 0x1aU)))) 
                  << 0x34U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffdfffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x35U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffbfffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x36U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xff7fffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x37U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfeffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x38U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfdffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x39U));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v26 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v26 = 1U;
    }
    if ((0x8000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x1bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1bU))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1bU))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1bU))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1bU))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1bU))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1bU))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1bU))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1bU))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1bU))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x28U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x29U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x2aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x2bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x2cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x2dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x2eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x2fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x30U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x31U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x32U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x33U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffefffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x34U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffdfffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x35U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffbfffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 0x1bU)))) 
                  << 0x36U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xff7fffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x37U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfeffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x38U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfdffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x39U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfbffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x3aU));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v27 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v27 = 1U;
    }
    if ((0x10000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x1cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1cU))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1cU))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1cU))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1cU))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1cU))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1cU))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1cU))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1cU))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1cU))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x28U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x29U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x2aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x2bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x2cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x2dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x2eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x2fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x30U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x31U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x32U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x33U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffefffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x34U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffdfffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x35U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffbfffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x36U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xff7fffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x37U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfeffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 0x1cU)))) 
                  << 0x38U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfdffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x39U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfbffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x3aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xf7ffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x3bU));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v28 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v28 = 1U;
    }
    if ((0x20000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x1dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1dU))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1dU))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1dU))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1dU))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1dU))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1dU))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1dU))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1dU))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1dU))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x28U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x29U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x2aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x2bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x2cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x2dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x2eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x2fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x30U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x31U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x32U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x33U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffefffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x34U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffdfffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x35U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffbfffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x36U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xff7fffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x37U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfeffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x38U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfdffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x39U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfbffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 0x1dU)))) 
                  << 0x3aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xf7ffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x3bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xefffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x3cU));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v29 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v29 = 1U;
    }
    if ((0x40000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x1eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1eU))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1eU))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1eU))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1eU))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1eU))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1eU))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1eU))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1eU))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1eU))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x28U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x29U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x2aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x2bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x2cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x2dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x2eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x2fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x30U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x31U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x32U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x33U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffefffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x34U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffdfffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x35U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffbfffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x36U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xff7fffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x37U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfeffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x38U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfdffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x39U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfbffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x3aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xf7ffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x3bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xefffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 0x1eU)))) 
                  << 0x3cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xdfffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x3dU));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v30 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v30 = 1U;
    }
    if ((0x80000000U & vlTOPp->core__DOT__x0_mult__DOT__op2)) {
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x1fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1fU))))) 
                  << 0x20U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1fU))))) 
                  << 0x21U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1fU))))) 
                  << 0x22U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1fU))))) 
                  << 0x23U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1fU))))) 
                  << 0x24U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1fU))))) 
                  << 0x25U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1fU))))) 
                  << 0x26U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1fU))))) 
                  << 0x27U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                          >> 0x1fU))))) 
                  << 0x28U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x29U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x2aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x2bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x2cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x2dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x2eU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x2fU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x30U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x31U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x32U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x33U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffefffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x34U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffdfffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x35U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffbfffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x36U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xff7fffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x37U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfeffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x38U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfdffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x39U));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfbffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x3aU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xf7ffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x3bU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xefffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x3cU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xdfffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->core__DOT__x0_mult__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x3dU));
        vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xbfffffffffffffffULL & vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->core__DOT__x0_mult__DOT__op1 
                                          & vlTOPp->core__DOT__x0_mult__DOT__op2) 
                                         >> 0x1fU)))) 
                  << 0x3eU));
        if (((IData)(vlTOPp->core__DOT__x0_mult__DOT__signed_type) 
             & (vlTOPp->core__DOT__x0_mult__DOT__op1 
                >> 0x1fU))) {
            vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        __Vdlyvval__core__DOT__x0_mult__DOT__product__v31 
            = vlTOPp->core__DOT__x0_mult__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        __Vdlyvset__core__DOT__x0_mult__DOT__product__v31 = 1U;
    }
    vlTOPp->core__DOT__x1_mult__DOT__x1x2__DOT__data_v 
        = vlTOPp->__Vdly__core__DOT__x1_mult__DOT__x1x2__DOT__data_v;
    vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data_v 
        = vlTOPp->__Vdly__core__DOT__x0_mult__DOT__x0x1__DOT__data_v;
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v0) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0U] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v0;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v1) {
        vlTOPp->core__DOT__x0_mult__DOT__product[1U] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v1;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v2) {
        vlTOPp->core__DOT__x0_mult__DOT__product[2U] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v2;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v3) {
        vlTOPp->core__DOT__x0_mult__DOT__product[3U] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v3;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v4) {
        vlTOPp->core__DOT__x0_mult__DOT__product[4U] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v4;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v5) {
        vlTOPp->core__DOT__x0_mult__DOT__product[5U] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v5;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v6) {
        vlTOPp->core__DOT__x0_mult__DOT__product[6U] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v6;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v7) {
        vlTOPp->core__DOT__x0_mult__DOT__product[7U] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v7;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v8) {
        vlTOPp->core__DOT__x0_mult__DOT__product[8U] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v8;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v9) {
        vlTOPp->core__DOT__x0_mult__DOT__product[9U] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v9;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v10) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0xaU] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v10;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v11) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0xbU] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v11;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v12) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0xcU] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v12;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v13) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0xdU] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v13;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v14) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0xeU] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v14;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v15) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0xfU] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v15;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v16) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0x10U] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v16;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v17) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0x11U] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v17;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v18) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0x12U] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v18;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v19) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0x13U] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v19;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v20) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0x14U] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v20;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v21) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0x15U] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v21;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v22) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0x16U] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v22;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v23) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0x17U] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v23;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v24) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0x18U] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v24;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v25) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0x19U] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v25;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v26) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0x1aU] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v26;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v27) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0x1bU] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v27;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v28) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0x1cU] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v28;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v29) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0x1dU] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v29;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v30) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0x1eU] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v30;
    }
    if (__Vdlyvset__core__DOT__x0_mult__DOT__product__v31) {
        vlTOPp->core__DOT__x0_mult__DOT__product[0x1fU] 
            = __Vdlyvval__core__DOT__x0_mult__DOT__product__v31;
    }
    vlTOPp->core__DOT__SIGNED_RES_RX1 = (1U & (vlTOPp->core__DOT__x1_mult__DOT__x1x2__DOT__data[4U] 
                                               >> 1U));
    vlTOPp->core__DOT__X1X2_EMPTY_SX1 = (1U & (~ (IData)(vlTOPp->core__DOT__x1_mult__DOT__x1x2__DOT__data_v)));
    vlTOPp->core__DOT__x1_mult__DOT__x1x2_full = (((IData)(vlTOPp->core__DOT__x1_mult__DOT__x1x2__DOT__data_v) 
                                                   & (~ (IData)(vlTOPp->core__DOT__x1_mult__DOT__x1x2__DOT__data_v)))
                                                   ? 1U
                                                   : 0U);
    vlTOPp->core__DOT__x1_mult__DOT__x0_data[4U] = 
        (((QData)((IData)(vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[9U])) 
          << 0x20U) | (QData)((IData)(vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[8U])));
    vlTOPp->core__DOT__x1_mult__DOT__x0_data[3U] = 
        (((QData)((IData)(vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[7U])) 
          << 0x20U) | (QData)((IData)(vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[6U])));
    vlTOPp->core__DOT__x1_mult__DOT__x0_data[2U] = 
        (((QData)((IData)(vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[5U])) 
          << 0x20U) | (QData)((IData)(vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[4U])));
    vlTOPp->core__DOT__x1_mult__DOT__x0_data[1U] = 
        (((QData)((IData)(vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[3U])) 
          << 0x20U) | (QData)((IData)(vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[2U])));
    vlTOPp->core__DOT__x1_mult__DOT__x0_data[0U] = 
        (((QData)((IData)(vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[1U])) 
          << 0x20U) | (QData)((IData)(vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data[0U])));
    vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__quotient 
        = ((IData)(vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__quotient_sign_reg)
            ? (~ ((IData)(1U) + vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__quotient_reg))
            : vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__quotient_reg);
    vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__division 
        = (vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__divisor_reg 
           > vlTOPp->core__DOT__exec_i__DOT__divider_i__DOT__reminder_reg);
    VL_EXTEND_WI(123,32, __Vtemp34, vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[0U]);
    vlTOPp->core__DOT__dec_i__DOT__dec2exe_x[0U] = 0U;
    vlTOPp->core__DOT__dec_i__DOT__dec2exe_x[1U] = 0U;
    vlTOPp->core__DOT__dec_i__DOT__dec2exe_x[2U] = 0U;
    vlTOPp->core__DOT__dec_i__DOT__dec2exe_x[3U] = 0U;
    vlTOPp->core__DOT__dec_i__DOT__dec2exe_x[4U] = 
        (0xfffffffeU & (__Vtemp34[0U] << 1U));
    vlTOPp->core__DOT__dec_i__DOT__dec2exe_x[5U] = 
        ((1U & (__Vtemp34[0U] >> 0x1fU)) | (0xfffffffeU 
                                            & (__Vtemp34[1U] 
                                               << 1U)));
    vlTOPp->core__DOT__dec_i__DOT__dec2exe_x[6U] = 
        ((1U & (__Vtemp34[1U] >> 0x1fU)) | (0xfffffffeU 
                                            & (__Vtemp34[2U] 
                                               << 1U)));
    vlTOPp->core__DOT__dec_i__DOT__dec2exe_x[7U] = 
        ((1U & (__Vtemp34[2U] >> 0x1fU)) | (0xfffffffeU 
                                            & (__Vtemp34[3U] 
                                               << 1U)));
    vlTOPp->core__DOT__dec_i__DOT__sub_i_sd = (((0x33U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                & (0U 
                                                   == 
                                                   (7U 
                                                    & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                        << 0x14U) 
                                                       | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                          >> 0xcU))))) 
                                               & (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                  >> 0x1eU));
    vlTOPp->core__DOT__dec_i__DOT__slt_i_sd = (((0x33U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                & (2U 
                                                   == 
                                                   (7U 
                                                    & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                        << 0x14U) 
                                                       | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                          >> 0xcU))))) 
                                               & (~ 
                                                  (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                   >> 0x1eU)));
    vlTOPp->core__DOT__dec_i__DOT__sltu_i_sd = (((0x33U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                 & (3U 
                                                    == 
                                                    (7U 
                                                     & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                         << 0x14U) 
                                                        | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                           >> 0xcU))))) 
                                                & (~ 
                                                   (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                    >> 0x1eU)));
    vlTOPp->core__DOT__dec_i__DOT__slti_i_sd = ((0x13U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                & (2U 
                                                   == 
                                                   (7U 
                                                    & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                        << 0x14U) 
                                                       | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                          >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__sltiu_i_sd = ((0x13U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                 & (3U 
                                                    == 
                                                    (7U 
                                                     & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                         << 0x14U) 
                                                        | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                           >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__lw_i_sd = ((3U == 
                                               (0x7fU 
                                                & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                              & (2U 
                                                 == 
                                                 (7U 
                                                  & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                      << 0x14U) 
                                                     | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                        >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__lh_i_sd = ((3U == 
                                               (0x7fU 
                                                & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                              & (1U 
                                                 == 
                                                 (7U 
                                                  & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                      << 0x14U) 
                                                     | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                        >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__lhu_i_sd = ((3U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                               & (5U 
                                                  == 
                                                  (7U 
                                                   & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                       << 0x14U) 
                                                      | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                         >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__lb_i_sd = ((3U == 
                                               (0x7fU 
                                                & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                              & (0U 
                                                 == 
                                                 (7U 
                                                  & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                      << 0x14U) 
                                                     | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                        >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__lbu_i_sd = ((3U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                               & (4U 
                                                  == 
                                                  (7U 
                                                   & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                       << 0x14U) 
                                                      | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                         >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__sw_i_sd = ((0x23U 
                                               == (0x7fU 
                                                   & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                              & (2U 
                                                 == 
                                                 (7U 
                                                  & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                      << 0x14U) 
                                                     | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                        >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__sh_i_sd = ((0x23U 
                                               == (0x7fU 
                                                   & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                              & (1U 
                                                 == 
                                                 (7U 
                                                  & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                      << 0x14U) 
                                                     | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                        >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__sb_i_sd = ((0x23U 
                                               == (0x7fU 
                                                   & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                              & (0U 
                                                 == 
                                                 (7U 
                                                  & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                      << 0x14U) 
                                                     | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                        >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__and_i_sd = (((0x33U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                & (7U 
                                                   == 
                                                   (7U 
                                                    & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                        << 0x14U) 
                                                       | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                          >> 0xcU))))) 
                                               & (~ 
                                                  (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                   >> 0x1eU)));
    vlTOPp->core__DOT__dec_i__DOT__or_i_sd = (((0x33U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                               & (6U 
                                                  == 
                                                  (7U 
                                                   & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                       << 0x14U) 
                                                      | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                         >> 0xcU))))) 
                                              & (~ 
                                                 (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                  >> 0x1eU)));
    vlTOPp->core__DOT__dec_i__DOT__xor_i_sd = (((0x33U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                & (4U 
                                                   == 
                                                   (7U 
                                                    & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                        << 0x14U) 
                                                       | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                          >> 0xcU))))) 
                                               & (~ 
                                                  (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                   >> 0x1eU)));
    vlTOPp->core__DOT__dec_i__DOT__andi_i_sd = ((0x13U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                & (7U 
                                                   == 
                                                   (7U 
                                                    & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                        << 0x14U) 
                                                       | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                          >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__ori_i_sd = ((0x13U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                               & (6U 
                                                  == 
                                                  (7U 
                                                   & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                       << 0x14U) 
                                                      | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                         >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__xori_i_sd = ((0x13U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                & (4U 
                                                   == 
                                                   (7U 
                                                    & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                        << 0x14U) 
                                                       | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                          >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__ebreak_i_sd = ((
                                                   (0x73U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                   & (0U 
                                                      == 
                                                      (7U 
                                                       & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                           << 0x14U) 
                                                          | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                             >> 0xcU))))) 
                                                  & (1U 
                                                     == 
                                                     (0xfffU 
                                                      & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                          << 0xcU) 
                                                         | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                            >> 0x14U)))));
    vlTOPp->core__DOT__dec_i__DOT__sll_i_sd = (((0x33U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                & (1U 
                                                   == 
                                                   (7U 
                                                    & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                        << 0x14U) 
                                                       | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                          >> 0xcU))))) 
                                               & (~ 
                                                  (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                   >> 0x1eU)));
    vlTOPp->core__DOT__dec_i__DOT__slli_i_sd = ((0x13U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                & (1U 
                                                   == 
                                                   (7U 
                                                    & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                        << 0x14U) 
                                                       | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                          >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__ecall_i_sd = (((0x73U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                  & (0U 
                                                     == 
                                                     (7U 
                                                      & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                          << 0x14U) 
                                                         | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                            >> 0xcU))))) 
                                                 & (0U 
                                                    == 
                                                    (0xfffU 
                                                     & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                         << 0xcU) 
                                                        | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                           >> 0x14U)))));
    vlTOPp->core__DOT__dec_i__DOT__srl_i_sd = (((0x33U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                & (5U 
                                                   == 
                                                   (7U 
                                                    & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                        << 0x14U) 
                                                       | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                          >> 0xcU))))) 
                                               & (~ 
                                                  (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                   >> 0x1eU)));
    vlTOPp->core__DOT__dec_i__DOT__sra_i_sd = (((0x33U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                & (5U 
                                                   == 
                                                   (7U 
                                                    & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                        << 0x14U) 
                                                       | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                          >> 0xcU))))) 
                                               & (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                  >> 0x1eU));
    vlTOPp->core__DOT__dec_i__DOT__srli_i_sd = (((0x13U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                 & (5U 
                                                    == 
                                                    (7U 
                                                     & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                         << 0x14U) 
                                                        | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                           >> 0xcU))))) 
                                                & (~ 
                                                   (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                    >> 0x1eU)));
    vlTOPp->core__DOT__dec_i__DOT__srai_i_sd = (((0x13U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                 & (5U 
                                                    == 
                                                    (7U 
                                                     & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                         << 0x14U) 
                                                        | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                           >> 0xcU))))) 
                                                & (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                   >> 0x1eU));
    vlTOPp->core__DOT__dec_i__DOT__offset_branch_b 
        = ((0xfffff000U & ((- (IData)((1U & (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                             >> 0x1fU)))) 
                           << 0xcU)) | ((0x800U & (
                                                   vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                   << 4U)) 
                                        | ((0x7e0U 
                                            & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                << 0xcU) 
                                               | (0xfe0U 
                                                  & (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                     >> 0x14U)))) 
                                           | (0x1eU 
                                              & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                  << 0x19U) 
                                                 | (0x1fffffeU 
                                                    & (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                       >> 7U)))))));
    vlTOPp->core__DOT__dec_i__DOT__offset_branch_j 
        = ((0xfff00000U & ((- (IData)((1U & (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                             >> 0x1fU)))) 
                           << 0x14U)) | ((0xff000U 
                                          & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U]) 
                                         | ((0x800U 
                                             & (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                >> 9U)) 
                                            | (0x7feU 
                                               & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                   << 0xcU) 
                                                  | (0xffeU 
                                                     & (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                        >> 0x14U)))))));
    vlTOPp->core__DOT__dec_i__DOT__jalr_offset = ((0xfffff000U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                                     >> 0x1fU)))) 
                                                      << 0xcU)) 
                                                  | (0xfffU 
                                                     & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                         << 0xcU) 
                                                        | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                           >> 0x14U))));
    vlTOPp->core__DOT__dec_i__DOT__beq_i_sd = ((0x63U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                               & (0U 
                                                  == 
                                                  (7U 
                                                   & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                       << 0x14U) 
                                                      | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                         >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__bne_i_sd = ((0x63U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                               & (1U 
                                                  == 
                                                  (7U 
                                                   & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                       << 0x14U) 
                                                      | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                         >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__blt_i_sd = ((0x63U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                               & (4U 
                                                  == 
                                                  (7U 
                                                   & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                       << 0x14U) 
                                                      | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                         >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__bge_i_sd = ((0x63U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                               & (5U 
                                                  == 
                                                  (7U 
                                                   & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                       << 0x14U) 
                                                      | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                         >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__bltu_i_sd = ((0x63U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                & (6U 
                                                   == 
                                                   (7U 
                                                    & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                        << 0x14U) 
                                                       | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                          >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__bgeu_i_sd = ((0x63U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                & (7U 
                                                   == 
                                                   (7U 
                                                    & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                        << 0x14U) 
                                                       | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                          >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__op2_i_type_sd = 
        ((0xfffff000U & ((- (IData)((1U & (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                           >> 0x1fU)))) 
                         << 0xcU)) | (0xfffU & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                 << 0xcU) 
                                                | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                   >> 0x14U))));
    vlTOPp->core__DOT__dec_i__DOT__op2_s_type_sd = 
        ((0xfffff000U & ((- (IData)((1U & (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                           >> 0x1fU)))) 
                         << 0xcU)) | ((0xfe0U & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                  << 0xcU) 
                                                 | (0xfe0U 
                                                    & (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                       >> 0x14U)))) 
                                      | (0x1fU & ((
                                                   vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                   << 0x19U) 
                                                  | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                     >> 7U)))));
    vlTOPp->core__DOT__dec_i__DOT__op1_u_type_sd = 
        (0xfffff000U & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U]);
    vlTOPp->core__DOT__dec_i__DOT__op1_csri_type_sd 
        = (0x1fU & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                     << 0x11U) | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                  >> 0xfU)));
    vlTOPp->core__DOT__dec_i__DOT__u_type_sd = ((0x37U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                | (0x17U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])));
    vlTOPp->core__DOT__dec_i__DOT__csrrw_i_sd = ((0x73U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                 & (1U 
                                                    == 
                                                    (7U 
                                                     & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                         << 0x14U) 
                                                        | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                           >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__csrrwi_i_sd = ((0x73U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                  & (5U 
                                                     == 
                                                     (7U 
                                                      & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                          << 0x14U) 
                                                         | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                            >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__csrrs_i_sd = ((0x73U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                 & (2U 
                                                    == 
                                                    (7U 
                                                     & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                         << 0x14U) 
                                                        | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                           >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__csrrc_i_sd = ((0x73U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                 & (3U 
                                                    == 
                                                    (7U 
                                                     & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                         << 0x14U) 
                                                        | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                           >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__csrrsi_i_sd = ((0x73U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                  & (6U 
                                                     == 
                                                     (7U 
                                                      & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                          << 0x14U) 
                                                         | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                            >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__csrrci_i_sd = ((0x73U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                  & (7U 
                                                     == 
                                                     (7U 
                                                      & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                          << 0x14U) 
                                                         | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                            >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__i_type_sd = ((0x13U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                | (3U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])));
    vlTOPp->core__DOT__dec_i__DOT__m_type_sd = ((0x33U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                & (1U 
                                                   == 
                                                   (0x7fU 
                                                    & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                        << 7U) 
                                                       | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                          >> 0x19U)))));
    vlTOPp->core__DOT__x0_mult__DOT__genblk1__BRA__0__KET____DOT__csa1__DOT__AxB 
        = (vlTOPp->core__DOT__x0_mult__DOT__product
           [0U] ^ vlTOPp->core__DOT__x0_mult__DOT__product
           [1U]);
    vlTOPp->core__DOT__x0_mult__DOT__genblk1__BRA__1__KET____DOT__csa1__DOT__AxB 
        = (vlTOPp->core__DOT__x0_mult__DOT__product
           [3U] ^ vlTOPp->core__DOT__x0_mult__DOT__product
           [4U]);
    vlTOPp->core__DOT__x0_mult__DOT__genblk1__BRA__2__KET____DOT__csa1__DOT__AxB 
        = (vlTOPp->core__DOT__x0_mult__DOT__product
           [6U] ^ vlTOPp->core__DOT__x0_mult__DOT__product
           [7U]);
    vlTOPp->core__DOT__x0_mult__DOT__genblk1__BRA__3__KET____DOT__csa1__DOT__AxB 
        = (vlTOPp->core__DOT__x0_mult__DOT__product
           [9U] ^ vlTOPp->core__DOT__x0_mult__DOT__product
           [0xaU]);
    vlTOPp->core__DOT__x0_mult__DOT__genblk1__BRA__4__KET____DOT__csa1__DOT__AxB 
        = (vlTOPp->core__DOT__x0_mult__DOT__product
           [0xcU] ^ vlTOPp->core__DOT__x0_mult__DOT__product
           [0xdU]);
    vlTOPp->core__DOT__x0_mult__DOT__genblk1__BRA__5__KET____DOT__csa1__DOT__AxB 
        = (vlTOPp->core__DOT__x0_mult__DOT__product
           [0xfU] ^ vlTOPp->core__DOT__x0_mult__DOT__product
           [0x10U]);
    vlTOPp->core__DOT__x0_mult__DOT__genblk1__BRA__6__KET____DOT__csa1__DOT__AxB 
        = (vlTOPp->core__DOT__x0_mult__DOT__product
           [0x12U] ^ vlTOPp->core__DOT__x0_mult__DOT__product
           [0x13U]);
    vlTOPp->core__DOT__x0_mult__DOT__genblk1__BRA__7__KET____DOT__csa1__DOT__AxB 
        = (vlTOPp->core__DOT__x0_mult__DOT__product
           [0x15U] ^ vlTOPp->core__DOT__x0_mult__DOT__product
           [0x16U]);
    vlTOPp->core__DOT__x0_mult__DOT__genblk1__BRA__8__KET____DOT__csa1__DOT__AxB 
        = (vlTOPp->core__DOT__x0_mult__DOT__product
           [0x18U] ^ vlTOPp->core__DOT__x0_mult__DOT__product
           [0x19U]);
    vlTOPp->core__DOT__x0_mult__DOT__genblk1__BRA__9__KET____DOT__csa1__DOT__AxB 
        = (vlTOPp->core__DOT__x0_mult__DOT__product
           [0x1bU] ^ vlTOPp->core__DOT__x0_mult__DOT__product
           [0x1cU]);
    vlTOPp->core__DOT__x1_mult__DOT__stall_sx1 = (1U 
                                                  & ((IData)(vlTOPp->core__DOT__x1_mult__DOT__x1x2_full) 
                                                     | (~ (IData)(vlTOPp->core__DOT__x0_mult__DOT__x0x1__DOT__data_v))));
    vlTOPp->core__DOT__x1_mult__DOT__csa6__DOT__AxB 
        = (vlTOPp->core__DOT__x1_mult__DOT__x0_data
           [0U] ^ vlTOPp->core__DOT__x1_mult__DOT__x0_data
           [1U]);
    vlTOPp->core__DOT__dec_i__DOT__csr_radr = (((0x73U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                & ((((((IData)(vlTOPp->core__DOT__dec_i__DOT__csrrw_i_sd) 
                                                       | (IData)(vlTOPp->core__DOT__dec_i__DOT__csrrs_i_sd)) 
                                                      | (IData)(vlTOPp->core__DOT__dec_i__DOT__csrrc_i_sd)) 
                                                     | (IData)(vlTOPp->core__DOT__dec_i__DOT__csrrwi_i_sd)) 
                                                    | (IData)(vlTOPp->core__DOT__dec_i__DOT__csrrsi_i_sd)) 
                                                   | (IData)(vlTOPp->core__DOT__dec_i__DOT__csrrci_i_sd)))
                                                ? (0xfffU 
                                                   & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                       << 0xcU) 
                                                      | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                         >> 0x14U)))
                                                : 0U);
    vlTOPp->core__DOT__dec_i__DOT__rdest_sd = (((((
                                                   (((0x33U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                     | (IData)(vlTOPp->core__DOT__dec_i__DOT__i_type_sd)) 
                                                    | (IData)(vlTOPp->core__DOT__dec_i__DOT__u_type_sd)) 
                                                   | (0x6fU 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U]))) 
                                                  | (0x67U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U]))) 
                                                 | (IData)(vlTOPp->core__DOT__dec_i__DOT__m_type_sd)) 
                                                | ((((((IData)(vlTOPp->core__DOT__dec_i__DOT__csrrw_i_sd) 
                                                       | (IData)(vlTOPp->core__DOT__dec_i__DOT__csrrs_i_sd)) 
                                                      | (IData)(vlTOPp->core__DOT__dec_i__DOT__csrrc_i_sd)) 
                                                     | (IData)(vlTOPp->core__DOT__dec_i__DOT__csrrwi_i_sd)) 
                                                    | (IData)(vlTOPp->core__DOT__dec_i__DOT__csrrsi_i_sd)) 
                                                   | (IData)(vlTOPp->core__DOT__dec_i__DOT__csrrci_i_sd)))
                                                ? (0x1fU 
                                                   & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                       << 0x19U) 
                                                      | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                         >> 7U)))
                                                : 0U);
    vlTOPp->core__DOT__dec_i__DOT__div_i_sd = ((IData)(vlTOPp->core__DOT__dec_i__DOT__m_type_sd) 
                                               & (4U 
                                                  == 
                                                  (7U 
                                                   & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                       << 0x14U) 
                                                      | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                         >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__divu_i_sd = ((IData)(vlTOPp->core__DOT__dec_i__DOT__m_type_sd) 
                                                & (5U 
                                                   == 
                                                   (7U 
                                                    & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                        << 0x14U) 
                                                       | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                          >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__rem_i_sd = ((IData)(vlTOPp->core__DOT__dec_i__DOT__m_type_sd) 
                                               & (6U 
                                                  == 
                                                  (7U 
                                                   & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                       << 0x14U) 
                                                      | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                         >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__mul_i_sd = ((IData)(vlTOPp->core__DOT__dec_i__DOT__m_type_sd) 
                                               & (0U 
                                                  == 
                                                  (7U 
                                                   & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                       << 0x14U) 
                                                      | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                         >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__mulh_i_sd = ((IData)(vlTOPp->core__DOT__dec_i__DOT__m_type_sd) 
                                                & (1U 
                                                   == 
                                                   (7U 
                                                    & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                        << 0x14U) 
                                                       | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                          >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__mulhsu_i_sd = ((IData)(vlTOPp->core__DOT__dec_i__DOT__m_type_sd) 
                                                  & (2U 
                                                     == 
                                                     (7U 
                                                      & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                          << 0x14U) 
                                                         | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                            >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__mulhu_i_sd = ((IData)(vlTOPp->core__DOT__dec_i__DOT__m_type_sd) 
                                                 & (3U 
                                                    == 
                                                    (7U 
                                                     & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                         << 0x14U) 
                                                        | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                           >> 0xcU)))));
    vlTOPp->core__DOT__dec_i__DOT__radr2_sd = (((((0x33U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                  | (0x23U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U]))) 
                                                 | (0x63U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U]))) 
                                                | (IData)(vlTOPp->core__DOT__dec_i__DOT__m_type_sd))
                                                ? (0x1fU 
                                                   & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                       << 0xcU) 
                                                      | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                         >> 0x14U)))
                                                : 0U);
    vlTOPp->core__DOT__dec_i__DOT__radr1_sd = (((((
                                                   ((0x33U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U])) 
                                                    | (IData)(vlTOPp->core__DOT__dec_i__DOT__i_type_sd)) 
                                                   | (0x23U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U]))) 
                                                  | (0x63U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U]))) 
                                                 | (0x67U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U]))) 
                                                | (IData)(vlTOPp->core__DOT__dec_i__DOT__m_type_sd))
                                                ? (0x1fU 
                                                   & ((vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[2U] 
                                                       << 0x11U) 
                                                      | (vlTOPp->core__DOT__ifetch_i__DOT__if2dec__DOT__data[1U] 
                                                         >> 0xfU)))
                                                : 0U);
    vlTOPp->core__DOT__x0_mult__DOT__product_s1[0U] 
        = (vlTOPp->core__DOT__x0_mult__DOT__genblk1__BRA__0__KET____DOT__csa1__DOT__AxB 
           ^ vlTOPp->core__DOT__x0_mult__DOT__product
           [2U]);
    vlTOPp->core__DOT__x0_mult__DOT__genblk1__BRA__0__KET____DOT__csa1__DOT__shf 
        = ((vlTOPp->core__DOT__x0_mult__DOT__product
            [0U] & vlTOPp->core__DOT__x0_mult__DOT__product
            [1U]) | (vlTOPp->core__DOT__x0_mult__DOT__genblk1__BRA__0__KET____DOT__csa1__DOT__AxB 
                     & vlTOPp->core__DOT__x0_mult__DOT__product
                     [2U]));
    vlTOPp->core__DOT__x0_mult__DOT__product_s1[2U] 
        = (vlTOPp->core__DOT__x0_mult__DOT__genblk1__BRA__1__KET____DOT__csa1__DOT__AxB 
           ^ vlTOPp->core__DOT__x0_mult__DOT__product
           [5U]);
    vlTOPp->core__DOT__x0_mult__DOT__genblk1__BRA__1__KET____DOT__csa1__DOT__shf 
        = ((vlTOPp->core__DOT__x0_mult__DOT__product
            [3U] & vlTOPp->core__DOT__x0_mult__DOT__product
            [4U]) | (vlTOPp->core__DOT__x0_mult__DOT__genblk1__BRA__1__KET____DOT__csa1__DOT__AxB 
                     & vlTOPp->core__DOT__x0_mult__DOT__product
                     [5U]));
    vlTOPp->core__DOT__x0_mult__DOT__product_s1[4U] 
        = (vlTOPp->core__DOT__x0_mult__DOT__genblk1__BRA__2__KET____DOT__csa1__DOT__AxB 
           ^ vlTOPp->core__DOT__x0_mult__DOT__product
           [8U]);
    vlTOPp->core__DOT__x0_mult__DOT__genblk1__BRA__2__KET____DOT__csa1__DOT__shf 
        = ((vlTOPp->core__DOT__x0_mult__DOT__product
            [6U] & vlTOPp->core__DOT__x0_mult__DOT__product
            [7U]) | (vlTOPp->core__DOT__x0_mult__DOT__genblk1__BRA__2__KET____DOT__csa1__DOT__AxB 
                     & vlTOPp->core__DOT__x0_mult__DOT__product
                     [8U]));
    vlTOPp->core__DOT__x0_mult__DOT__product_s1[6U] 
        = (vlTOPp->core__DOT__x0_mult__DOT__genblk1__BRA__3__KET____DOT__csa1__DOT__AxB 
           ^ vlTOPp->core__DOT__x0_mult__DOT__product
           [0xbU]);
    vlTOPp->core__DOT__x0_mult__DOT__genblk1__BRA__3__KET____DOT__csa1__DOT__shf 
        = ((vlTOPp->core__DOT__x0_mult__DOT__product
            [9U] & vlTOPp->core__DOT__x0_mult__DOT__product
            [0xaU]) | (vlTOPp->core__DOT__x0_mult__DOT__genblk1__BRA__3__KET____DOT__csa1__DOT__AxB 
                       & vlTOPp->core__DOT__x0_mult__DOT__product
                       [0xbU]));
}
