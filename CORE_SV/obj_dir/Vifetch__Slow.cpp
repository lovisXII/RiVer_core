// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vifetch.h for the primary calling header

#include "Vifetch.h"
#include "Vifetch__Syms.h"

//==========

VL_CTOR_IMP(Vifetch) {
    Vifetch__Syms* __restrict vlSymsp = __VlSymsp = new Vifetch__Syms(this, name());
    Vifetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vifetch::__Vconfigure(Vifetch__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vifetch::~Vifetch() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vifetch::_initial__TOP__1(Vifetch__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vifetch::_initial__TOP__1\n"); );
    Vifetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->EXCEPTION_RI = 0U;
    vlTOPp->ifetch__DOT__pred_branch_next_adr = 0x22222200U;
    vlTOPp->ifetch__DOT__if2dec__DOT__data_v = 0U;
}

void Vifetch::_settle__TOP__3(Vifetch__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vifetch::_settle__TOP__3\n"); );
    Vifetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ADR_VALID_SI = (1U & (((~ (IData)(vlTOPp->DEC2IF_EMPTY_SD)) 
                                   & (~ (IData)(vlTOPp->IF2DEC_FLUSH_SD))) 
                                  & (~ (IData)(vlTOPp->EXCEPTION_SM))));
    vlTOPp->ADR_SI = (((IData)(vlTOPp->PRED_TAKEN_SD) 
                       & (~ (IData)(vlTOPp->PRED_FAILED_RD)))
                       ? vlTOPp->PRED_ADR_SD : vlTOPp->PC_RD);
    vlTOPp->ifetch__DOT__if2dec_din[1U] = ((IData)(vlTOPp->EXCEPTION_SM)
                                            ? 0x13U
                                            : vlTOPp->IC_INST_SI);
    vlTOPp->ifetch__DOT__if2dec_din[0U] = (((IData)(vlTOPp->PRED_TAKEN_SD) 
                                            & (~ (IData)(vlTOPp->PRED_FAILED_RD)))
                                            ? vlTOPp->PRED_ADR_SD
                                            : vlTOPp->PC_RD);
    vlTOPp->PC_IF2DEC_RI = vlTOPp->ifetch__DOT__if2dec__DOT__data[0U];
    vlTOPp->INSTR_RI = vlTOPp->ifetch__DOT__if2dec__DOT__data[1U];
    vlTOPp->PRED_ADR_RI = vlTOPp->ifetch__DOT__if2dec__DOT__data[2U];
    vlTOPp->PRED_TAKEN_RI = (1U & vlTOPp->ifetch__DOT__if2dec__DOT__data[3U]);
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
    vlTOPp->IF2DEC_EMPTY_SI = (1U & (~ (IData)(vlTOPp->ifetch__DOT__if2dec__DOT__data_v)));
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

void Vifetch::_eval_initial(Vifetch__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vifetch::_eval_initial\n"); );
    Vifetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset_n = vlTOPp->reset_n;
}

void Vifetch::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vifetch::final\n"); );
    // Variables
    Vifetch__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vifetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vifetch::_eval_settle(Vifetch__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vifetch::_eval_settle\n"); );
    Vifetch* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

void Vifetch::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vifetch::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset_n = VL_RAND_RESET_I(1);
    IC_INST_SI = VL_RAND_RESET_I(32);
    IC_STALL_SI = VL_RAND_RESET_I(1);
    ADR_SI = VL_RAND_RESET_I(32);
    ADR_VALID_SI = VL_RAND_RESET_I(1);
    DEC2IF_EMPTY_SD = VL_RAND_RESET_I(1);
    DEC2IF_POP_SI = VL_RAND_RESET_I(1);
    IF2DEC_FLUSH_SD = VL_RAND_RESET_I(1);
    IF2DEC_POP_SD = VL_RAND_RESET_I(1);
    IF2DEC_EMPTY_SI = VL_RAND_RESET_I(1);
    PC_RD = VL_RAND_RESET_I(32);
    INSTR_RI = VL_RAND_RESET_I(32);
    PC_IF2DEC_RI = VL_RAND_RESET_I(32);
    EXCEPTION_SM = VL_RAND_RESET_I(1);
    EXCEPTION_RI = VL_RAND_RESET_I(1);
    PRED_FAILED_RD = VL_RAND_RESET_I(1);
    PRED_SUCCESS_RD = VL_RAND_RESET_I(1);
    BRANCH_INST_RD = VL_RAND_RESET_I(1);
    BRANCH_INST_ADR_RD = VL_RAND_RESET_I(32);
    ADR_TO_BRANCH_RD = VL_RAND_RESET_I(32);
    PRED_ADR_SD = VL_RAND_RESET_I(32);
    PRED_TAKEN_SD = VL_RAND_RESET_I(1);
    PUSH_ADR_RAS_RD = VL_RAND_RESET_I(1);
    POP_ADR_RAS_RD = VL_RAND_RESET_I(1);
    ADR_TO_RET_RD = VL_RAND_RESET_I(32);
    RET_INST_RD = VL_RAND_RESET_I(1);
    PRED_ADR_RI = VL_RAND_RESET_I(32);
    PRED_TAKEN_RI = VL_RAND_RESET_I(1);
    ifetch__DOT__if2dec_push_si = VL_RAND_RESET_I(1);
    ifetch__DOT__stall_si = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(97, ifetch__DOT__if2dec_din);
    ifetch__DOT__next_pred_state = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            ifetch__DOT__branch_adr_reg[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            ifetch__DOT__predicted_adr_reg[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            ifetch__DOT__pred_state_reg[__Vi0] = VL_RAND_RESET_I(2);
    }}
    ifetch__DOT__pred_valid_reg = VL_RAND_RESET_I(4);
    ifetch__DOT__pred_branch_next_adr = VL_RAND_RESET_I(32);
    ifetch__DOT__pred_branch_taken = VL_RAND_RESET_I(1);
    ifetch__DOT__unnamedblk2__DOT__index = VL_RAND_RESET_I(32);
    ifetch__DOT__unnamedblk2__DOT__found = VL_RAND_RESET_I(1);
    ifetch__DOT__unnamedblk2__DOT__pred_write_pointer = VL_RAND_RESET_I(2);
    ifetch__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i = VL_RAND_RESET_I(32);
    ifetch__DOT__unnamedblk4__DOT__found = VL_RAND_RESET_I(1);
    ifetch__DOT__unnamedblk4__DOT__pred_good = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(97, ifetch__DOT__if2dec__DOT__data);
    ifetch__DOT__if2dec__DOT__data_v = VL_RAND_RESET_I(1);
}
