// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdivider.h for the primary calling header

#include "Vdivider.h"
#include "Vdivider__Syms.h"

//==========

void Vdivider::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdivider::eval\n"); );
    Vdivider__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vdivider* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("EXE/divider.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vdivider::_eval_initial_loop(Vdivider__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("EXE/divider.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vdivider::_sequent__TOP__3(Vdivider__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider::_sequent__TOP__3\n"); );
    Vdivider* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->divider__DOT__quotient_reg = vlTOPp->divider__DOT__quotient_se;
    vlTOPp->divider__DOT__divisor_reg = vlTOPp->divider__DOT__divisor_se;
    if ((((IData)(vlTOPp->divider__DOT__setup_regs) 
          | (IData)(vlTOPp->divider__DOT__same)) | (IData)(vlTOPp->divider__DOT__zero_div))) {
        vlTOPp->divider__DOT__reminder_sign_reg = (
                                                   (vlTOPp->divider__DOT__op1 
                                                    >> 0x1fU) 
                                                   & (IData)(vlTOPp->divider__DOT__signed_inst));
    }
    if ((((IData)(vlTOPp->divider__DOT__setup_regs) 
          | (IData)(vlTOPp->divider__DOT__same)) | (IData)(vlTOPp->divider__DOT__zero_div))) {
        vlTOPp->divider__DOT__quotient_sign_reg = (
                                                   ((vlTOPp->divider__DOT__op1 
                                                     ^ vlTOPp->divider__DOT__op2) 
                                                    >> 0x1fU) 
                                                   & (IData)(vlTOPp->divider__DOT__signed_inst));
    }
    if (((((IData)(vlTOPp->divider__DOT__setup_regs) 
           | (IData)(vlTOPp->divider__DOT__zero_div)) 
          | (IData)(vlTOPp->divider__DOT__same)) | 
         ((IData)(vlTOPp->divider__DOT__running) & (IData)(vlTOPp->divider__DOT__division)))) {
        vlTOPp->divider__DOT__reminder_reg = vlTOPp->divider__DOT__reminder_se;
    }
    vlTOPp->divider__DOT__quotient = ((IData)(vlTOPp->divider__DOT__quotient_sign_reg)
                                       ? (~ ((IData)(1U) 
                                             + vlTOPp->divider__DOT__quotient_reg))
                                       : vlTOPp->divider__DOT__quotient_reg);
    vlTOPp->divider__DOT__division = (vlTOPp->divider__DOT__divisor_reg 
                                      > vlTOPp->divider__DOT__reminder_reg);
}

VL_INLINE_OPT void Vdivider::_sequent__TOP__4(Vdivider__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider::_sequent__TOP__4\n"); );
    Vdivider* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*2:0*/ __Vdly__divider__DOT__EP;
    // Body
    __Vdly__divider__DOT__EP = vlTOPp->divider__DOT__EP;
    if (vlTOPp->reset_n) {
        if (vlTOPp->START_DIV) {
            vlTOPp->divider__DOT__cmd_reg = vlTOPp->CMD_RD;
        }
    }
    if (vlTOPp->reset_n) {
        if (vlTOPp->START_DIV) {
            vlTOPp->divider__DOT__op1 = vlTOPp->OP1_SE;
        }
    }
    if (vlTOPp->reset_n) {
        if (vlTOPp->START_DIV) {
            vlTOPp->divider__DOT__op2 = vlTOPp->OP2_SE;
        }
    }
    __Vdly__divider__DOT__EP = ((IData)(vlTOPp->reset_n)
                                 ? (IData)(vlTOPp->divider__DOT__EF)
                                 : 0U);
    if ((4U & (IData)(vlTOPp->divider__DOT__EP))) {
        if ((2U & (IData)(vlTOPp->divider__DOT__EP))) {
            vlTOPp->divider__DOT__EF = 0U;
        } else {
            if ((1U & (IData)(vlTOPp->divider__DOT__EP))) {
                vlTOPp->divider__DOT__EF = 0U;
            } else {
                vlTOPp->divider__DOT__EF = 4U;
                if ((0x1fU == (IData)(vlTOPp->divider__DOT__shift_cpt_reg))) {
                    vlTOPp->divider__DOT__EF = 5U;
                }
            }
        }
    } else {
        if ((2U & (IData)(vlTOPp->divider__DOT__EP))) {
            vlTOPp->divider__DOT__EF = 5U;
        } else {
            if ((1U & (IData)(vlTOPp->divider__DOT__EP))) {
                vlTOPp->divider__DOT__EF = 4U;
            } else {
                vlTOPp->divider__DOT__EF = 0U;
                if ((((IData)(vlTOPp->START_DIV) & 
                      (0U != vlTOPp->OP2_SE)) & (vlTOPp->OP1_SE 
                                                 == vlTOPp->OP2_SE))) {
                    vlTOPp->divider__DOT__EF = 3U;
                } else {
                    if (((IData)(vlTOPp->START_DIV) 
                         & (0U != vlTOPp->OP2_SE))) {
                        vlTOPp->divider__DOT__EF = 1U;
                    } else {
                        if (((IData)(vlTOPp->START_DIV) 
                             & (0U == vlTOPp->OP2_SE))) {
                            vlTOPp->divider__DOT__EF = 2U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->divider__DOT__EP = __Vdly__divider__DOT__EP;
    vlTOPp->RES_DIV = (((3U == (IData)(vlTOPp->divider__DOT__cmd_reg)) 
                        | (0U == (IData)(vlTOPp->divider__DOT__cmd_reg)))
                        ? ((IData)(vlTOPp->divider__DOT__reminder_sign_reg)
                            ? (~ ((IData)(1U) + (IData)(vlTOPp->divider__DOT__reminder_reg)))
                            : (IData)(vlTOPp->divider__DOT__reminder_reg))
                        : vlTOPp->divider__DOT__quotient);
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
}

VL_INLINE_OPT void Vdivider::_sequent__TOP__5(Vdivider__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider::_sequent__TOP__5\n"); );
    Vdivider* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->divider__DOT__shift_cpt_reg = vlTOPp->divider__DOT__shift_cpt_se;
}

VL_INLINE_OPT void Vdivider::_combo__TOP__6(Vdivider__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider::_combo__TOP__6\n"); );
    Vdivider* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->divider__DOT__signed_inst = ((IData)(vlTOPp->divider__DOT__setup_regs) 
                                         & ((3U == (IData)(vlTOPp->CMD_RD)) 
                                            | (1U == (IData)(vlTOPp->CMD_RD))));
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

VL_INLINE_OPT void Vdivider::_sequent__TOP__7(Vdivider__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider::_sequent__TOP__7\n"); );
    Vdivider* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->divider__DOT__shift_cpt_se = ((IData)(vlTOPp->divider__DOT__running)
                                           ? (0x3fU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlTOPp->divider__DOT__shift_cpt_reg)))
                                           : 0U);
}

void Vdivider::_eval(Vdivider__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider::_eval\n"); );
    Vdivider* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->reset_n)) & (IData)(vlTOPp->__Vclklast__TOP__reset_n)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    vlTOPp->_combo__TOP__6(vlSymsp);
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->reset_n)) & (IData)(vlTOPp->__Vclklast__TOP__reset_n)))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset_n = vlTOPp->reset_n;
}

VL_INLINE_OPT QData Vdivider::_change_request(Vdivider__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider::_change_request\n"); );
    Vdivider* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vdivider::_change_request_1(Vdivider__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider::_change_request_1\n"); );
    Vdivider* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vdivider::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivider::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset_n & 0xfeU))) {
        Verilated::overWidthError("reset_n");}
    if (VL_UNLIKELY((CMD_RD & 0xfcU))) {
        Verilated::overWidthError("CMD_RD");}
    if (VL_UNLIKELY((START_DIV & 0xfeU))) {
        Verilated::overWidthError("START_DIV");}
}
#endif  // VL_DEBUG
