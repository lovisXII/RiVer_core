// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vifetch.h for the primary calling header

#include "Vifetch.h"
#include "Vifetch__Syms.h"

//==========

void Vifetch::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vifetch::eval\n"); );
    Vifetch__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vifetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("IFETCH/ifetch.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vifetch::_eval_initial_loop(Vifetch__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("IFETCH/ifetch.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vifetch::_combo__TOP__2(Vifetch__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vifetch::_combo__TOP__2\n"); );
    Vifetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ADR_VALID_SI = (1U & (((~ (IData)(vlTOPp->DEC2IF_EMPTY_SD)) 
                                   & (~ (IData)(vlTOPp->IF2DEC_FLUSH_SD))) 
                                  & (~ (IData)(vlTOPp->EXCEPTION_SM))));
    vlTOPp->ADR_SI = (((IData)(vlTOPp->PRED_TAKEN_SD) 
                       & (~ (IData)(vlTOPp->PRED_FAILED_RD)))
                       ? vlTOPp->PRED_ADR_SD : vlTOPp->PC_RD);
}

VL_INLINE_OPT void Vifetch::_sequent__TOP__4(Vifetch__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vifetch::_sequent__TOP__4\n"); );
    Vifetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*1:0*/ __Vdlyvdim0__ifetch__DOT__pred_state_reg__v0;
    CData/*1:0*/ __Vdlyvval__ifetch__DOT__pred_state_reg__v0;
    CData/*0:0*/ __Vdlyvset__ifetch__DOT__pred_state_reg__v0;
    CData/*1:0*/ __Vdlyvdim0__ifetch__DOT__branch_adr_reg__v0;
    CData/*0:0*/ __Vdlyvset__ifetch__DOT__branch_adr_reg__v0;
    CData/*1:0*/ __Vdlyvdim0__ifetch__DOT__predicted_adr_reg__v0;
    CData/*1:0*/ __Vdlyvdim0__ifetch__DOT__pred_state_reg__v1;
    IData/*31:0*/ __Vdlyvval__ifetch__DOT__branch_adr_reg__v0;
    IData/*31:0*/ __Vdlyvval__ifetch__DOT__predicted_adr_reg__v0;
    // Body
    __Vdlyvset__ifetch__DOT__pred_state_reg__v0 = 0U;
    __Vdlyvset__ifetch__DOT__branch_adr_reg__v0 = 0U;
    if (vlTOPp->reset_n) {
        if (((IData)(vlTOPp->BRANCH_INST_RD) & (IData)(vlTOPp->ifetch__DOT__if2dec__DOT__data_v))) {
            vlTOPp->ifetch__DOT__unnamedblk2__DOT__found = 0U;
            vlTOPp->ifetch__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i = 0U;
            while (VL_GTS_III(1,32,32, 4U, vlTOPp->ifetch__DOT__unnamedblk2__DOT__index)) {
                if ((vlTOPp->ifetch__DOT__branch_adr_reg
                     [(3U & vlTOPp->ifetch__DOT__unnamedblk2__DOT__index)] 
                     == vlTOPp->BRANCH_INST_ADR_RD)) {
                    if ((1U & (~ (IData)(vlTOPp->ifetch__DOT__unnamedblk2__DOT__found)))) {
                        vlTOPp->ifetch__DOT__unnamedblk2__DOT__index 
                            = vlTOPp->ifetch__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i;
                    }
                    vlTOPp->ifetch__DOT__unnamedblk2__DOT__found = 1U;
                }
                vlTOPp->ifetch__DOT__unnamedblk2__DOT__index 
                    = ((IData)(1U) + vlTOPp->ifetch__DOT__unnamedblk2__DOT__index);
            }
            if (vlTOPp->ifetch__DOT__unnamedblk2__DOT__found) {
                __Vdlyvval__ifetch__DOT__pred_state_reg__v0 
                    = vlTOPp->ifetch__DOT__next_pred_state;
                __Vdlyvset__ifetch__DOT__pred_state_reg__v0 = 1U;
                __Vdlyvdim0__ifetch__DOT__pred_state_reg__v0 
                    = (3U & vlTOPp->ifetch__DOT__unnamedblk2__DOT__index);
            } else {
                __Vdlyvval__ifetch__DOT__branch_adr_reg__v0 
                    = vlTOPp->BRANCH_INST_ADR_RD;
                __Vdlyvset__ifetch__DOT__branch_adr_reg__v0 = 1U;
                __Vdlyvdim0__ifetch__DOT__branch_adr_reg__v0 
                    = vlTOPp->ifetch__DOT__unnamedblk2__DOT__pred_write_pointer;
                __Vdlyvval__ifetch__DOT__predicted_adr_reg__v0 
                    = vlTOPp->ADR_TO_BRANCH_RD;
                __Vdlyvdim0__ifetch__DOT__predicted_adr_reg__v0 
                    = vlTOPp->ifetch__DOT__unnamedblk2__DOT__pred_write_pointer;
                __Vdlyvdim0__ifetch__DOT__pred_state_reg__v1 
                    = vlTOPp->ifetch__DOT__unnamedblk2__DOT__pred_write_pointer;
                vlTOPp->ifetch__DOT__pred_valid_reg 
                    = ((IData)(vlTOPp->ifetch__DOT__pred_valid_reg) 
                       | ((IData)(1U) << (IData)(vlTOPp->ifetch__DOT__unnamedblk2__DOT__pred_write_pointer)));
                vlTOPp->ifetch__DOT__unnamedblk2__DOT__pred_write_pointer 
                    = (3U & ((IData)(1U) + (IData)(vlTOPp->ifetch__DOT__unnamedblk2__DOT__pred_write_pointer)));
            }
        }
    } else {
        vlTOPp->ifetch__DOT__unnamedblk2__DOT__pred_write_pointer = 0U;
        vlTOPp->ifetch__DOT__pred_valid_reg = 0U;
    }
    if (__Vdlyvset__ifetch__DOT__branch_adr_reg__v0) {
        vlTOPp->ifetch__DOT__predicted_adr_reg[__Vdlyvdim0__ifetch__DOT__predicted_adr_reg__v0] 
            = __Vdlyvval__ifetch__DOT__predicted_adr_reg__v0;
    }
    if (vlTOPp->reset_n) {
        if (((IData)(vlTOPp->PRED_FAILED_RD) | (IData)(vlTOPp->PRED_SUCCESS_RD))) {
            if (((0U != vlTOPp->ifetch__DOT__branch_adr_reg
                  [0U]) & (0U != vlTOPp->BRANCH_INST_ADR_RD))) {
                if ((2U & vlTOPp->ifetch__DOT__pred_state_reg
                     [0U])) {
                    if ((1U & vlTOPp->ifetch__DOT__pred_state_reg
                         [0U])) {
                        vlTOPp->ifetch__DOT__next_pred_state = 2U;
                        if ((1U & (~ (IData)(vlTOPp->PRED_SUCCESS_RD)))) {
                            vlTOPp->ifetch__DOT__next_pred_state = 3U;
                        }
                    } else {
                        vlTOPp->ifetch__DOT__next_pred_state = 1U;
                        if ((1U & (~ (IData)(vlTOPp->PRED_SUCCESS_RD)))) {
                            vlTOPp->ifetch__DOT__next_pred_state = 3U;
                        }
                    }
                } else {
                    if ((1U & vlTOPp->ifetch__DOT__pred_state_reg
                         [0U])) {
                        vlTOPp->ifetch__DOT__next_pred_state = 0U;
                        if ((1U & (~ (IData)(vlTOPp->PRED_SUCCESS_RD)))) {
                            vlTOPp->ifetch__DOT__next_pred_state = 2U;
                        }
                    } else {
                        vlTOPp->ifetch__DOT__next_pred_state = 0U;
                        if ((1U & (~ (IData)(vlTOPp->PRED_SUCCESS_RD)))) {
                            vlTOPp->ifetch__DOT__next_pred_state = 1U;
                        }
                    }
                }
            }
            if (((0U != vlTOPp->ifetch__DOT__branch_adr_reg
                  [1U]) & (0U != vlTOPp->BRANCH_INST_ADR_RD))) {
                if ((2U & vlTOPp->ifetch__DOT__pred_state_reg
                     [1U])) {
                    if ((1U & vlTOPp->ifetch__DOT__pred_state_reg
                         [1U])) {
                        vlTOPp->ifetch__DOT__next_pred_state = 2U;
                        if ((1U & (~ (IData)(vlTOPp->PRED_SUCCESS_RD)))) {
                            vlTOPp->ifetch__DOT__next_pred_state = 3U;
                        }
                    } else {
                        vlTOPp->ifetch__DOT__next_pred_state = 1U;
                        if ((1U & (~ (IData)(vlTOPp->PRED_SUCCESS_RD)))) {
                            vlTOPp->ifetch__DOT__next_pred_state = 3U;
                        }
                    }
                } else {
                    if ((1U & vlTOPp->ifetch__DOT__pred_state_reg
                         [1U])) {
                        vlTOPp->ifetch__DOT__next_pred_state = 0U;
                        if ((1U & (~ (IData)(vlTOPp->PRED_SUCCESS_RD)))) {
                            vlTOPp->ifetch__DOT__next_pred_state = 2U;
                        }
                    } else {
                        vlTOPp->ifetch__DOT__next_pred_state = 0U;
                        if ((1U & (~ (IData)(vlTOPp->PRED_SUCCESS_RD)))) {
                            vlTOPp->ifetch__DOT__next_pred_state = 1U;
                        }
                    }
                }
            }
            if (((0U != vlTOPp->ifetch__DOT__branch_adr_reg
                  [2U]) & (0U != vlTOPp->BRANCH_INST_ADR_RD))) {
                if ((2U & vlTOPp->ifetch__DOT__pred_state_reg
                     [2U])) {
                    if ((1U & vlTOPp->ifetch__DOT__pred_state_reg
                         [2U])) {
                        vlTOPp->ifetch__DOT__next_pred_state = 2U;
                        if ((1U & (~ (IData)(vlTOPp->PRED_SUCCESS_RD)))) {
                            vlTOPp->ifetch__DOT__next_pred_state = 3U;
                        }
                    } else {
                        vlTOPp->ifetch__DOT__next_pred_state = 1U;
                        if ((1U & (~ (IData)(vlTOPp->PRED_SUCCESS_RD)))) {
                            vlTOPp->ifetch__DOT__next_pred_state = 3U;
                        }
                    }
                } else {
                    if ((1U & vlTOPp->ifetch__DOT__pred_state_reg
                         [2U])) {
                        vlTOPp->ifetch__DOT__next_pred_state = 0U;
                        if ((1U & (~ (IData)(vlTOPp->PRED_SUCCESS_RD)))) {
                            vlTOPp->ifetch__DOT__next_pred_state = 2U;
                        }
                    } else {
                        vlTOPp->ifetch__DOT__next_pred_state = 0U;
                        if ((1U & (~ (IData)(vlTOPp->PRED_SUCCESS_RD)))) {
                            vlTOPp->ifetch__DOT__next_pred_state = 1U;
                        }
                    }
                }
            }
            if (((0U != vlTOPp->ifetch__DOT__branch_adr_reg
                  [3U]) & (0U != vlTOPp->BRANCH_INST_ADR_RD))) {
                if ((2U & vlTOPp->ifetch__DOT__pred_state_reg
                     [3U])) {
                    if ((1U & vlTOPp->ifetch__DOT__pred_state_reg
                         [3U])) {
                        vlTOPp->ifetch__DOT__next_pred_state = 2U;
                        if ((1U & (~ (IData)(vlTOPp->PRED_SUCCESS_RD)))) {
                            vlTOPp->ifetch__DOT__next_pred_state = 3U;
                        }
                    } else {
                        vlTOPp->ifetch__DOT__next_pred_state = 1U;
                        if ((1U & (~ (IData)(vlTOPp->PRED_SUCCESS_RD)))) {
                            vlTOPp->ifetch__DOT__next_pred_state = 3U;
                        }
                    }
                } else {
                    if ((1U & vlTOPp->ifetch__DOT__pred_state_reg
                         [3U])) {
                        vlTOPp->ifetch__DOT__next_pred_state = 0U;
                        if ((1U & (~ (IData)(vlTOPp->PRED_SUCCESS_RD)))) {
                            vlTOPp->ifetch__DOT__next_pred_state = 2U;
                        }
                    } else {
                        vlTOPp->ifetch__DOT__next_pred_state = 0U;
                        if ((1U & (~ (IData)(vlTOPp->PRED_SUCCESS_RD)))) {
                            vlTOPp->ifetch__DOT__next_pred_state = 1U;
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->ifetch__DOT__next_pred_state = 1U;
    }
    if (__Vdlyvset__ifetch__DOT__branch_adr_reg__v0) {
        vlTOPp->ifetch__DOT__branch_adr_reg[__Vdlyvdim0__ifetch__DOT__branch_adr_reg__v0] 
            = __Vdlyvval__ifetch__DOT__branch_adr_reg__v0;
    }
    if (__Vdlyvset__ifetch__DOT__pred_state_reg__v0) {
        vlTOPp->ifetch__DOT__pred_state_reg[__Vdlyvdim0__ifetch__DOT__pred_state_reg__v0] 
            = __Vdlyvval__ifetch__DOT__pred_state_reg__v0;
    }
    if (__Vdlyvset__ifetch__DOT__branch_adr_reg__v0) {
        vlTOPp->ifetch__DOT__pred_state_reg[__Vdlyvdim0__ifetch__DOT__pred_state_reg__v1] = 1U;
    }
}

VL_INLINE_OPT void Vifetch::_sequent__TOP__5(Vifetch__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vifetch::_sequent__TOP__5\n"); );
    Vifetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__ifetch__DOT__if2dec__DOT__data_v;
    // Body
    __Vdly__ifetch__DOT__if2dec__DOT__data_v = vlTOPp->ifetch__DOT__if2dec__DOT__data_v;
    if (vlTOPp->reset_n) {
        __Vdly__ifetch__DOT__if2dec__DOT__data_v = 
            (1U & ((IData)(vlTOPp->ifetch__DOT__if2dec__DOT__data_v)
                    ? ((~ (IData)(vlTOPp->IF2DEC_POP_SD)) 
                       | (IData)(vlTOPp->ifetch__DOT__if2dec_push_si))
                    : (IData)(vlTOPp->ifetch__DOT__if2dec_push_si)));
        if (vlTOPp->ifetch__DOT__if2dec__DOT__data_v) {
            if (((IData)(vlTOPp->ifetch__DOT__if2dec_push_si) 
                 & (IData)(vlTOPp->IF2DEC_POP_SD))) {
                vlTOPp->ifetch__DOT__if2dec__DOT__data[0U] 
                    = vlTOPp->ifetch__DOT__if2dec_din[0U];
                vlTOPp->ifetch__DOT__if2dec__DOT__data[1U] 
                    = vlTOPp->ifetch__DOT__if2dec_din[1U];
                vlTOPp->ifetch__DOT__if2dec__DOT__data[2U] 
                    = vlTOPp->ifetch__DOT__if2dec_din[2U];
                vlTOPp->ifetch__DOT__if2dec__DOT__data[3U] 
                    = vlTOPp->ifetch__DOT__if2dec_din[3U];
            }
        } else {
            if (vlTOPp->ifetch__DOT__if2dec_push_si) {
                vlTOPp->ifetch__DOT__if2dec__DOT__data[0U] 
                    = vlTOPp->ifetch__DOT__if2dec_din[0U];
                vlTOPp->ifetch__DOT__if2dec__DOT__data[1U] 
                    = vlTOPp->ifetch__DOT__if2dec_din[1U];
                vlTOPp->ifetch__DOT__if2dec__DOT__data[2U] 
                    = vlTOPp->ifetch__DOT__if2dec_din[2U];
                vlTOPp->ifetch__DOT__if2dec__DOT__data[3U] 
                    = vlTOPp->ifetch__DOT__if2dec_din[3U];
            }
        }
    } else {
        __Vdly__ifetch__DOT__if2dec__DOT__data_v = 0U;
    }
    vlTOPp->ifetch__DOT__if2dec__DOT__data_v = __Vdly__ifetch__DOT__if2dec__DOT__data_v;
    vlTOPp->PC_IF2DEC_RI = vlTOPp->ifetch__DOT__if2dec__DOT__data[0U];
    vlTOPp->INSTR_RI = vlTOPp->ifetch__DOT__if2dec__DOT__data[1U];
    vlTOPp->PRED_ADR_RI = vlTOPp->ifetch__DOT__if2dec__DOT__data[2U];
    vlTOPp->PRED_TAKEN_RI = (1U & vlTOPp->ifetch__DOT__if2dec__DOT__data[3U]);
    vlTOPp->IF2DEC_EMPTY_SI = (1U & (~ (IData)(vlTOPp->ifetch__DOT__if2dec__DOT__data_v)));
}

VL_INLINE_OPT void Vifetch::_combo__TOP__6(Vifetch__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vifetch::_combo__TOP__6\n"); );
    Vifetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ifetch__DOT__unnamedblk4__DOT__found = 0U;
    vlTOPp->ifetch__DOT__unnamedblk4__DOT__pred_good = 0U;
    if (((vlTOPp->ifetch__DOT__branch_adr_reg[0U] == vlTOPp->PC_RD) 
         & (IData)(vlTOPp->ifetch__DOT__pred_valid_reg))) {
        if ((1U & (~ (IData)(vlTOPp->ifetch__DOT__unnamedblk4__DOT__found)))) {
            vlTOPp->ifetch__DOT__unnamedblk4__DOT__found = 1U;
            vlTOPp->ifetch__DOT__pred_branch_next_adr 
                = vlTOPp->ifetch__DOT__predicted_adr_reg
                [0U];
            vlTOPp->ifetch__DOT__unnamedblk4__DOT__pred_good 
                = ((0U == vlTOPp->ifetch__DOT__pred_state_reg
                    [0U]) | (1U == vlTOPp->ifetch__DOT__pred_state_reg
                             [0U]));
        }
    }
    if (((vlTOPp->ifetch__DOT__branch_adr_reg[1U] == vlTOPp->PC_RD) 
         & ((IData)(vlTOPp->ifetch__DOT__pred_valid_reg) 
            >> 1U))) {
        if ((1U & (~ (IData)(vlTOPp->ifetch__DOT__unnamedblk4__DOT__found)))) {
            vlTOPp->ifetch__DOT__unnamedblk4__DOT__found = 1U;
            vlTOPp->ifetch__DOT__pred_branch_next_adr 
                = vlTOPp->ifetch__DOT__predicted_adr_reg
                [1U];
            vlTOPp->ifetch__DOT__unnamedblk4__DOT__pred_good 
                = ((0U == vlTOPp->ifetch__DOT__pred_state_reg
                    [1U]) | (1U == vlTOPp->ifetch__DOT__pred_state_reg
                             [1U]));
        }
    }
    if (((vlTOPp->ifetch__DOT__branch_adr_reg[2U] == vlTOPp->PC_RD) 
         & ((IData)(vlTOPp->ifetch__DOT__pred_valid_reg) 
            >> 2U))) {
        if ((1U & (~ (IData)(vlTOPp->ifetch__DOT__unnamedblk4__DOT__found)))) {
            vlTOPp->ifetch__DOT__unnamedblk4__DOT__found = 1U;
            vlTOPp->ifetch__DOT__pred_branch_next_adr 
                = vlTOPp->ifetch__DOT__predicted_adr_reg
                [2U];
            vlTOPp->ifetch__DOT__unnamedblk4__DOT__pred_good 
                = ((0U == vlTOPp->ifetch__DOT__pred_state_reg
                    [2U]) | (1U == vlTOPp->ifetch__DOT__pred_state_reg
                             [2U]));
        }
    }
    if (((vlTOPp->ifetch__DOT__branch_adr_reg[3U] == vlTOPp->PC_RD) 
         & ((IData)(vlTOPp->ifetch__DOT__pred_valid_reg) 
            >> 3U))) {
        if ((1U & (~ (IData)(vlTOPp->ifetch__DOT__unnamedblk4__DOT__found)))) {
            vlTOPp->ifetch__DOT__unnamedblk4__DOT__found = 1U;
            vlTOPp->ifetch__DOT__pred_branch_next_adr 
                = vlTOPp->ifetch__DOT__predicted_adr_reg
                [3U];
            vlTOPp->ifetch__DOT__unnamedblk4__DOT__pred_good 
                = ((0U == vlTOPp->ifetch__DOT__pred_state_reg
                    [3U]) | (1U == vlTOPp->ifetch__DOT__pred_state_reg
                             [3U]));
        }
    }
    vlTOPp->ifetch__DOT__pred_branch_taken = ((IData)(vlTOPp->ifetch__DOT__unnamedblk4__DOT__found) 
                                              & (IData)(vlTOPp->ifetch__DOT__unnamedblk4__DOT__pred_good));
    vlTOPp->ifetch__DOT__if2dec_din[1U] = ((IData)(vlTOPp->EXCEPTION_SM)
                                            ? 0x13U
                                            : vlTOPp->IC_INST_SI);
    vlTOPp->ifetch__DOT__if2dec_din[0U] = (((IData)(vlTOPp->PRED_TAKEN_SD) 
                                            & (~ (IData)(vlTOPp->PRED_FAILED_RD)))
                                            ? vlTOPp->PRED_ADR_SD
                                            : vlTOPp->PC_RD);
    vlTOPp->ifetch__DOT__stall_si = (1U & (((IData)(vlTOPp->IC_STALL_SI) 
                                            | (((IData)(vlTOPp->ifetch__DOT__if2dec__DOT__data_v) 
                                                & (~ (IData)(vlTOPp->IF2DEC_POP_SD)))
                                                ? 1U
                                                : 0U)) 
                                           | (IData)(vlTOPp->DEC2IF_EMPTY_SD)));
    vlTOPp->ifetch__DOT__if2dec_din[3U] = vlTOPp->ifetch__DOT__pred_branch_taken;
    vlTOPp->ifetch__DOT__if2dec_din[2U] = vlTOPp->ifetch__DOT__pred_branch_next_adr;
    vlTOPp->ifetch__DOT__if2dec_push_si = (1U & (((~ (IData)(vlTOPp->ifetch__DOT__stall_si)) 
                                                  & (~ (IData)(vlTOPp->IF2DEC_FLUSH_SD))) 
                                                 & (~ (IData)(vlTOPp->EXCEPTION_SM))));
    vlTOPp->DEC2IF_POP_SI = (1U & (~ (((~ (IData)(vlTOPp->ifetch__DOT__stall_si)) 
                                       & (~ (IData)(vlTOPp->IF2DEC_FLUSH_SD))) 
                                      & (~ (IData)(vlTOPp->EXCEPTION_SM)))));
}

void Vifetch::_eval(Vifetch__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vifetch::_eval\n"); );
    Vifetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->reset_n)) & (IData)(vlTOPp->__Vclklast__TOP__reset_n)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    vlTOPp->_combo__TOP__6(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset_n = vlTOPp->reset_n;
}

VL_INLINE_OPT QData Vifetch::_change_request(Vifetch__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vifetch::_change_request\n"); );
    Vifetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vifetch::_change_request_1(Vifetch__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vifetch::_change_request_1\n"); );
    Vifetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vifetch::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vifetch::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset_n & 0xfeU))) {
        Verilated::overWidthError("reset_n");}
    if (VL_UNLIKELY((IC_STALL_SI & 0xfeU))) {
        Verilated::overWidthError("IC_STALL_SI");}
    if (VL_UNLIKELY((DEC2IF_EMPTY_SD & 0xfeU))) {
        Verilated::overWidthError("DEC2IF_EMPTY_SD");}
    if (VL_UNLIKELY((IF2DEC_FLUSH_SD & 0xfeU))) {
        Verilated::overWidthError("IF2DEC_FLUSH_SD");}
    if (VL_UNLIKELY((IF2DEC_POP_SD & 0xfeU))) {
        Verilated::overWidthError("IF2DEC_POP_SD");}
    if (VL_UNLIKELY((EXCEPTION_SM & 0xfeU))) {
        Verilated::overWidthError("EXCEPTION_SM");}
    if (VL_UNLIKELY((PRED_FAILED_RD & 0xfeU))) {
        Verilated::overWidthError("PRED_FAILED_RD");}
    if (VL_UNLIKELY((PRED_SUCCESS_RD & 0xfeU))) {
        Verilated::overWidthError("PRED_SUCCESS_RD");}
    if (VL_UNLIKELY((BRANCH_INST_RD & 0xfeU))) {
        Verilated::overWidthError("BRANCH_INST_RD");}
    if (VL_UNLIKELY((PRED_TAKEN_SD & 0xfeU))) {
        Verilated::overWidthError("PRED_TAKEN_SD");}
    if (VL_UNLIKELY((PUSH_ADR_RAS_RD & 0xfeU))) {
        Verilated::overWidthError("PUSH_ADR_RAS_RD");}
    if (VL_UNLIKELY((POP_ADR_RAS_RD & 0xfeU))) {
        Verilated::overWidthError("POP_ADR_RAS_RD");}
    if (VL_UNLIKELY((RET_INST_RD & 0xfeU))) {
        Verilated::overWidthError("RET_INST_RD");}
}
#endif  // VL_DEBUG
