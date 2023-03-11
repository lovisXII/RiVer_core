// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vexe.h for the primary calling header

#include "Vexe.h"
#include "Vexe__Syms.h"

//==========

void Vexe::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vexe::eval\n"); );
    Vexe__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vexe* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("EXE/exe.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vexe::_eval_initial_loop(Vexe__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("EXE/exe.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vexe::_combo__TOP__3(Vexe__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexe::_combo__TOP__3\n"); );
    Vexe* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->exe__DOT__exe2mem_x[2U] = ((0xfffU & vlTOPp->exe__DOT__exe2mem_x[2U]) 
                                       | (0xfffff000U 
                                          & (vlTOPp->PC_DEC2EXE_RD 
                                             << 0xcU)));
    vlTOPp->exe__DOT__exe2mem_x[3U] = ((0xfffff000U 
                                        & vlTOPp->exe__DOT__exe2mem_x[3U]) 
                                       | (0xfffU & 
                                          (vlTOPp->PC_DEC2EXE_RD 
                                           >> 0x14U)));
    vlTOPp->exe__DOT__exe2mem_data[2U] = ((0xffffffc0U 
                                           & vlTOPp->exe__DOT__exe2mem_data[2U]) 
                                          | (IData)(vlTOPp->DEST_RD));
    vlTOPp->exe__DOT__exe2mem_data[2U] = ((0xffffff3fU 
                                           & vlTOPp->exe__DOT__exe2mem_data[2U]) 
                                          | (0xffffffc0U 
                                             & ((IData)(vlTOPp->MEM_SIZE_RD) 
                                                << 6U)));
    vlTOPp->exe__DOT__exe2mem_data[2U] = ((0xfffff7ffU 
                                           & vlTOPp->exe__DOT__exe2mem_data[2U]) 
                                          | (0xfffff800U 
                                             & ((IData)(vlTOPp->MEM_SIGN_EXTEND_RD) 
                                                << 0xbU)));
    vlTOPp->exe__DOT__exe2mem_data[2U] = ((0xfffU & 
                                           vlTOPp->exe__DOT__exe2mem_data[2U]) 
                                          | (0xfffff000U 
                                             & (vlTOPp->PC_DEC2EXE_RD 
                                                << 0xcU)));
    vlTOPp->exe__DOT__exe2mem_data[3U] = ((0xfffff000U 
                                           & vlTOPp->exe__DOT__exe2mem_data[3U]) 
                                          | (0xfffU 
                                             & (vlTOPp->PC_DEC2EXE_RD 
                                                >> 0x14U)));
    vlTOPp->exe__DOT__exe2mem_data[3U] = ((0xffffefffU 
                                           & vlTOPp->exe__DOT__exe2mem_data[3U]) 
                                          | (0xfffff000U 
                                             & ((IData)(vlTOPp->CSR_WENABLE_RD) 
                                                << 0xcU)));
    vlTOPp->exe__DOT__exe2mem_data[3U] = ((0xfe001fffU 
                                           & vlTOPp->exe__DOT__exe2mem_data[3U]) 
                                          | (0xffffe000U 
                                             & ((IData)(vlTOPp->CSR_WADR_RD) 
                                                << 0xdU)));
    vlTOPp->exe__DOT__exe2mem_data[3U] = ((0x1ffffffU 
                                           & vlTOPp->exe__DOT__exe2mem_data[3U]) 
                                          | (0xfe000000U 
                                             & (vlTOPp->CSR_RDATA_RD 
                                                << 0x19U)));
    vlTOPp->exe__DOT__exe2mem_data[4U] = ((0xfe000000U 
                                           & vlTOPp->exe__DOT__exe2mem_data[4U]) 
                                          | (0x1ffffffU 
                                             & (vlTOPp->CSR_RDATA_RD 
                                                >> 7U)));
    vlTOPp->exe__DOT__exe2mem_data[4U] = ((0xfdffffffU 
                                           & vlTOPp->exe__DOT__exe2mem_data[4U]) 
                                          | (0xfe000000U 
                                             & ((IData)(vlTOPp->ENV_CALL_S_MODE_RD) 
                                                << 0x19U)));
    vlTOPp->exe__DOT__exe2mem_data[4U] = ((0xfbffffffU 
                                           & vlTOPp->exe__DOT__exe2mem_data[4U]) 
                                          | (0xfc000000U 
                                             & ((IData)(vlTOPp->ENV_CALL_WRONG_MODE_RD) 
                                                << 0x1aU)));
    vlTOPp->exe__DOT__exe2mem_data[4U] = ((0xf7ffffffU 
                                           & vlTOPp->exe__DOT__exe2mem_data[4U]) 
                                          | (0xf8000000U 
                                             & ((IData)(vlTOPp->ILLEGAL_INSTRUCTION_RD) 
                                                << 0x1bU)));
    vlTOPp->exe__DOT__exe2mem_data[4U] = ((0xefffffffU 
                                           & vlTOPp->exe__DOT__exe2mem_data[4U]) 
                                          | (0xf0000000U 
                                             & ((IData)(vlTOPp->ADRESS_MISALIGNED_RD) 
                                                << 0x1cU)));
    vlTOPp->exe__DOT__exe2mem_data[4U] = ((0xdfffffffU 
                                           & vlTOPp->exe__DOT__exe2mem_data[4U]) 
                                          | (0xe0000000U 
                                             & ((IData)(vlTOPp->ENV_CALL_U_MODE_RD) 
                                                << 0x1dU)));
    vlTOPp->exe__DOT__exe2mem_data[4U] = ((0xbfffffffU 
                                           & vlTOPp->exe__DOT__exe2mem_data[4U]) 
                                          | (0xc0000000U 
                                             & ((IData)(vlTOPp->ENV_CALL_M_MODE_RD) 
                                                << 0x1eU)));
    vlTOPp->exe__DOT__exe2mem_data[5U] = ((0xfffffffbU 
                                           & vlTOPp->exe__DOT__exe2mem_data[5U]) 
                                          | (0xfffffffcU 
                                             & ((IData)(vlTOPp->MRET_RD) 
                                                << 2U)));
    vlTOPp->exe__DOT__exe2mem_data[5U] = ((0xffffffdfU 
                                           & vlTOPp->exe__DOT__exe2mem_data[5U]) 
                                          | (0xffffffe0U 
                                             & ((IData)(vlTOPp->INSTRUCTION_ACCESS_FAULT_RD) 
                                                << 5U)));
    vlTOPp->exe__DOT__exe2mem_data[5U] = ((0xffffffbfU 
                                           & vlTOPp->exe__DOT__exe2mem_data[5U]) 
                                          | (0xffffffc0U 
                                             & ((IData)(vlTOPp->EBREAK_RD) 
                                                << 6U)));
    vlTOPp->exe__DOT__exe2mem_data[5U] = ((0x7fU & 
                                           vlTOPp->exe__DOT__exe2mem_data[5U]) 
                                          | (0xffffff80U 
                                             & (vlTOPp->PC_BRANCH_VALUE_RD 
                                                << 7U)));
    vlTOPp->exe__DOT__exe2mem_data[6U] = ((0x80U & 
                                           vlTOPp->exe__DOT__exe2mem_data[6U]) 
                                          | (0x7fU 
                                             & (vlTOPp->PC_BRANCH_VALUE_RD 
                                                >> 0x19U)));
    vlTOPp->exe__DOT__exe2mem_data[6U] = ((0x7fU & 
                                           vlTOPp->exe__DOT__exe2mem_data[6U]) 
                                          | (0xffffff80U 
                                             & ((IData)(vlTOPp->MULT_INST_RD) 
                                                << 7U)));
    vlTOPp->exe__DOT__bpc_disable2 = (((0U == (IData)(vlTOPp->RADR2_RD)) 
                                       | (IData)(vlTOPp->BLOCK_BP_RD)) 
                                      | (IData)(vlTOPp->MEM_LOAD_RD));
}

VL_INLINE_OPT void Vexe::_sequent__TOP__4(Vexe__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexe::_sequent__TOP__4\n"); );
    Vexe* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__exe__DOT__exe2mem__DOT__data_v;
    // Body
    __Vdly__exe__DOT__exe2mem__DOT__data_v = vlTOPp->exe__DOT__exe2mem__DOT__data_v;
    vlTOPp->exe__DOT__divider_i__DOT__divisor_reg = vlTOPp->exe__DOT__divider_i__DOT__divisor_se;
    vlTOPp->exe__DOT__divider_i__DOT__quotient_reg 
        = vlTOPp->exe__DOT__divider_i__DOT__quotient_se;
    if (((((IData)(vlTOPp->exe__DOT__divider_i__DOT__setup_regs) 
           | (IData)(vlTOPp->exe__DOT__divider_i__DOT__zero_div)) 
          | (IData)(vlTOPp->exe__DOT__divider_i__DOT__same)) 
         | ((IData)(vlTOPp->exe__DOT__divider_i__DOT__running) 
            & (IData)(vlTOPp->exe__DOT__divider_i__DOT__division)))) {
        vlTOPp->exe__DOT__divider_i__DOT__reminder_reg 
            = vlTOPp->exe__DOT__divider_i__DOT__reminder_se;
    }
    if ((((IData)(vlTOPp->exe__DOT__divider_i__DOT__setup_regs) 
          | (IData)(vlTOPp->exe__DOT__divider_i__DOT__same)) 
         | (IData)(vlTOPp->exe__DOT__divider_i__DOT__zero_div))) {
        vlTOPp->exe__DOT__divider_i__DOT__reminder_sign_reg 
            = ((vlTOPp->exe__DOT__divider_i__DOT__op1 
                >> 0x1fU) & (IData)(vlTOPp->exe__DOT__divider_i__DOT__signed_inst));
    }
    if ((((IData)(vlTOPp->exe__DOT__divider_i__DOT__setup_regs) 
          | (IData)(vlTOPp->exe__DOT__divider_i__DOT__same)) 
         | (IData)(vlTOPp->exe__DOT__divider_i__DOT__zero_div))) {
        vlTOPp->exe__DOT__divider_i__DOT__quotient_sign_reg 
            = (((vlTOPp->exe__DOT__divider_i__DOT__op1 
                 ^ vlTOPp->exe__DOT__divider_i__DOT__op2) 
                >> 0x1fU) & (IData)(vlTOPp->exe__DOT__divider_i__DOT__signed_inst));
    }
    if (vlTOPp->exe__02Ereset_n) {
        __Vdly__exe__DOT__exe2mem__DOT__data_v = (1U 
                                                  & ((IData)(vlTOPp->exe__DOT__exe2mem__DOT__data_v)
                                                      ? 
                                                     ((~ (IData)(vlTOPp->EXE2MEM_POP_SM)) 
                                                      | (~ (IData)(vlTOPp->exe__DOT__stall_se)))
                                                      : 
                                                     (~ (IData)(vlTOPp->exe__DOT__stall_se))));
        if (vlTOPp->exe__DOT__exe2mem__DOT__data_v) {
            if (((~ (IData)(vlTOPp->exe__DOT__stall_se)) 
                 & (IData)(vlTOPp->EXE2MEM_POP_SM))) {
                vlTOPp->exe__DOT__exe2mem__DOT__data[0U] 
                    = vlTOPp->exe__DOT__exe2mem_din[0U];
                vlTOPp->exe__DOT__exe2mem__DOT__data[1U] 
                    = vlTOPp->exe__DOT__exe2mem_din[1U];
                vlTOPp->exe__DOT__exe2mem__DOT__data[2U] 
                    = vlTOPp->exe__DOT__exe2mem_din[2U];
                vlTOPp->exe__DOT__exe2mem__DOT__data[3U] 
                    = vlTOPp->exe__DOT__exe2mem_din[3U];
                vlTOPp->exe__DOT__exe2mem__DOT__data[4U] 
                    = vlTOPp->exe__DOT__exe2mem_din[4U];
                vlTOPp->exe__DOT__exe2mem__DOT__data[5U] 
                    = vlTOPp->exe__DOT__exe2mem_din[5U];
                vlTOPp->exe__DOT__exe2mem__DOT__data[6U] 
                    = vlTOPp->exe__DOT__exe2mem_din[6U];
            }
        } else {
            if ((1U & (~ (IData)(vlTOPp->exe__DOT__stall_se)))) {
                vlTOPp->exe__DOT__exe2mem__DOT__data[0U] 
                    = vlTOPp->exe__DOT__exe2mem_din[0U];
                vlTOPp->exe__DOT__exe2mem__DOT__data[1U] 
                    = vlTOPp->exe__DOT__exe2mem_din[1U];
                vlTOPp->exe__DOT__exe2mem__DOT__data[2U] 
                    = vlTOPp->exe__DOT__exe2mem_din[2U];
                vlTOPp->exe__DOT__exe2mem__DOT__data[3U] 
                    = vlTOPp->exe__DOT__exe2mem_din[3U];
                vlTOPp->exe__DOT__exe2mem__DOT__data[4U] 
                    = vlTOPp->exe__DOT__exe2mem_din[4U];
                vlTOPp->exe__DOT__exe2mem__DOT__data[5U] 
                    = vlTOPp->exe__DOT__exe2mem_din[5U];
                vlTOPp->exe__DOT__exe2mem__DOT__data[6U] 
                    = vlTOPp->exe__DOT__exe2mem_din[6U];
            }
        }
    } else {
        __Vdly__exe__DOT__exe2mem__DOT__data_v = 0U;
    }
    vlTOPp->exe__DOT__exe2mem__DOT__data_v = __Vdly__exe__DOT__exe2mem__DOT__data_v;
    vlTOPp->exe__DOT__divider_i__DOT__division = (vlTOPp->exe__DOT__divider_i__DOT__divisor_reg 
                                                  > vlTOPp->exe__DOT__divider_i__DOT__reminder_reg);
    vlTOPp->exe__DOT__divider_i__DOT__quotient = ((IData)(vlTOPp->exe__DOT__divider_i__DOT__quotient_sign_reg)
                                                   ? 
                                                  (~ 
                                                   ((IData)(1U) 
                                                    + vlTOPp->exe__DOT__divider_i__DOT__quotient_reg))
                                                   : vlTOPp->exe__DOT__divider_i__DOT__quotient_reg);
    vlTOPp->EXE2MEM_EMPTY_SE = (1U & (~ (IData)(vlTOPp->exe__DOT__exe2mem__DOT__data_v)));
    vlTOPp->RES_RE = vlTOPp->exe__DOT__exe2mem__DOT__data[0U];
    vlTOPp->DEST_RE = (0x3fU & vlTOPp->exe__DOT__exe2mem__DOT__data[2U]);
    vlTOPp->MEM_LOAD_RE = (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[2U] 
                                 >> 9U));
    vlTOPp->MEM_STORE_RE = (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[2U] 
                                  >> 0xaU));
    vlTOPp->WB_RE = (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[2U] 
                           >> 8U));
    vlTOPp->CSR_RDATA_RE = ((vlTOPp->exe__DOT__exe2mem__DOT__data[4U] 
                             << 7U) | (vlTOPp->exe__DOT__exe2mem__DOT__data[3U] 
                                       >> 0x19U));
    vlTOPp->CSR_WENABLE_RE = (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[3U] 
                                    >> 0xcU));
    vlTOPp->MULT_INST_RE = (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[6U] 
                                  >> 7U));
    vlTOPp->MEM_DATA_RE = vlTOPp->exe__DOT__exe2mem__DOT__data[1U];
    vlTOPp->MEM_SIZE_RE = (3U & ((vlTOPp->exe__DOT__exe2mem__DOT__data[3U] 
                                  << 0x1aU) | (vlTOPp->exe__DOT__exe2mem__DOT__data[2U] 
                                               >> 6U)));
    vlTOPp->MEM_SIGN_EXTEND_RE = (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[2U] 
                                        >> 0xbU));
    vlTOPp->PC_EXE2MEM_RE = ((vlTOPp->exe__DOT__exe2mem__DOT__data[3U] 
                              << 0x14U) | (vlTOPp->exe__DOT__exe2mem__DOT__data[2U] 
                                           >> 0xcU));
    vlTOPp->CSR_WADR_RE = (0xfffU & ((vlTOPp->exe__DOT__exe2mem__DOT__data[4U] 
                                      << 0x13U) | (
                                                   vlTOPp->exe__DOT__exe2mem__DOT__data[3U] 
                                                   >> 0xdU)));
    vlTOPp->ENV_CALL_S_MODE_RE = (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[4U] 
                                        >> 0x19U));
    vlTOPp->ENV_CALL_WRONG_MODE_RE = (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[4U] 
                                            >> 0x1aU));
    vlTOPp->ILLEGAL_INSTRUCTION_RE = (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[4U] 
                                            >> 0x1bU));
    vlTOPp->ADRESS_MISALIGNED_RE = (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[4U] 
                                          >> 0x1cU));
    vlTOPp->ENV_CALL_U_MODE_RE = (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[4U] 
                                        >> 0x1dU));
    vlTOPp->ENV_CALL_M_MODE_RE = (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[4U] 
                                        >> 0x1eU));
    vlTOPp->EXCEPTION_RE = (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[4U] 
                                  >> 0x1fU));
    vlTOPp->LOAD_ADRESS_MISALIGNED_RE = (1U & vlTOPp->exe__DOT__exe2mem__DOT__data[5U]);
    vlTOPp->LOAD_ACCESS_FAULT_RE = (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[5U] 
                                          >> 1U));
    vlTOPp->MRET_RE = (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[5U] 
                             >> 2U));
    vlTOPp->STORE_ADRESS_MISALIGNED_RE = (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[5U] 
                                                >> 3U));
    vlTOPp->STORE_ACCESS_FAULT_RE = (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[5U] 
                                           >> 4U));
    vlTOPp->INSTRUCTION_ACCESS_FAULT_RE = (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[5U] 
                                                 >> 5U));
    vlTOPp->EBREAK_RE = (1U & (vlTOPp->exe__DOT__exe2mem__DOT__data[5U] 
                               >> 6U));
    vlTOPp->PC_BRANCH_VALUE_RE = ((vlTOPp->exe__DOT__exe2mem__DOT__data[6U] 
                                   << 0x19U) | (vlTOPp->exe__DOT__exe2mem__DOT__data[5U] 
                                                >> 7U));
}

VL_INLINE_OPT void Vexe::_sequent__TOP__5(Vexe__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexe::_sequent__TOP__5\n"); );
    Vexe* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__x0_multiplier__DOT__x0x1__DOT__data_v 
        = vlTOPp->x0_multiplier__DOT__x0x1__DOT__data_v;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v0 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v1 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v2 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v3 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v4 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v5 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v6 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v7 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v8 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v9 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v10 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v11 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v12 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v13 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v14 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v15 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v16 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v17 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v18 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v19 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v20 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v21 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v22 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v23 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v24 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v25 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v26 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v27 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v28 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v29 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v30 = 0U;
    vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v31 = 0U;
    if (vlTOPp->x0_multiplier__02Ereset_n) {
        vlTOPp->__Vdly__x0_multiplier__DOT__x0x1__DOT__data_v 
            = (1U & ((IData)(vlTOPp->x0_multiplier__DOT__x0x1__DOT__data_v)
                      ? ((~ (IData)(vlTOPp->X0X1_POP_SX1)) 
                         | (~ (IData)(vlTOPp->x0_multiplier__DOT__stall_sx0)))
                      : (~ (IData)(vlTOPp->x0_multiplier__DOT__stall_sx0))));
        if (vlTOPp->x0_multiplier__DOT__x0x1__DOT__data_v) {
            if (((~ (IData)(vlTOPp->x0_multiplier__DOT__stall_sx0)) 
                 & (IData)(vlTOPp->X0X1_POP_SX1))) {
                vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[0U] 
                    = vlTOPp->x0_multiplier__DOT__x0x1_din[0U];
                vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[1U] 
                    = vlTOPp->x0_multiplier__DOT__x0x1_din[1U];
                vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[2U] 
                    = vlTOPp->x0_multiplier__DOT__x0x1_din[2U];
                vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[3U] 
                    = vlTOPp->x0_multiplier__DOT__x0x1_din[3U];
                vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[4U] 
                    = vlTOPp->x0_multiplier__DOT__x0x1_din[4U];
                vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[5U] 
                    = vlTOPp->x0_multiplier__DOT__x0x1_din[5U];
                vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[6U] 
                    = vlTOPp->x0_multiplier__DOT__x0x1_din[6U];
                vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[7U] 
                    = vlTOPp->x0_multiplier__DOT__x0x1_din[7U];
                vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[8U] 
                    = vlTOPp->x0_multiplier__DOT__x0x1_din[8U];
                vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[9U] 
                    = vlTOPp->x0_multiplier__DOT__x0x1_din[9U];
                vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[0xaU] 
                    = vlTOPp->x0_multiplier__DOT__x0x1_din[0xaU];
            }
        } else {
            if ((1U & (~ (IData)(vlTOPp->x0_multiplier__DOT__stall_sx0)))) {
                vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[0U] 
                    = vlTOPp->x0_multiplier__DOT__x0x1_din[0U];
                vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[1U] 
                    = vlTOPp->x0_multiplier__DOT__x0x1_din[1U];
                vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[2U] 
                    = vlTOPp->x0_multiplier__DOT__x0x1_din[2U];
                vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[3U] 
                    = vlTOPp->x0_multiplier__DOT__x0x1_din[3U];
                vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[4U] 
                    = vlTOPp->x0_multiplier__DOT__x0x1_din[4U];
                vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[5U] 
                    = vlTOPp->x0_multiplier__DOT__x0x1_din[5U];
                vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[6U] 
                    = vlTOPp->x0_multiplier__DOT__x0x1_din[6U];
                vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[7U] 
                    = vlTOPp->x0_multiplier__DOT__x0x1_din[7U];
                vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[8U] 
                    = vlTOPp->x0_multiplier__DOT__x0x1_din[8U];
                vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[9U] 
                    = vlTOPp->x0_multiplier__DOT__x0x1_din[9U];
                vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[0xaU] 
                    = vlTOPp->x0_multiplier__DOT__x0x1_din[0xaU];
            }
        }
    } else {
        vlTOPp->__Vdly__x0_multiplier__DOT__x0x1__DOT__data_v = 0U;
    }
    if ((1U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffffeULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | (IData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                        & vlTOPp->x0_multiplier__DOT__op2)))));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffffdULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 1U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffffbULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 2U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffff7ULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 3U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffefULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 4U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffdfULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 5U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffbfULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 6U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffff7fULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 7U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffeffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 8U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffdffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 9U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffbffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 0xaU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 0xbU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 0xcU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 0xdU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 0xeU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 0xfU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 0x10U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 0x11U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 0x12U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 0x13U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 0x14U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 0x15U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & vlTOPp->x0_multiplier__DOT__op2)))) 
                  << 0x1fU));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v0 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v0 = 1U;
    }
    if ((2U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffffdULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 1U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffffbULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 1U)))) 
                  << 2U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffff7ULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 1U))))) 
                  << 3U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffefULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 1U))))) 
                  << 4U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffdfULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 1U))))) 
                  << 5U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffbfULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 1U))))) 
                  << 6U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffff7fULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 1U))))) 
                  << 7U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffeffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 1U))))) 
                  << 8U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffdffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 1U))))) 
                  << 9U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffbffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 1U))))) 
                  << 0xaU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 0xbU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 0xcU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 0xdU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 0xeU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 0xfU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 0x10U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 0x11U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 0x12U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 0x13U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 0x14U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 0x15U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 1U))))) 
                  << 0x20U));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v1 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v1 = 1U;
    }
    if ((4U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffffbULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 2U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffff7ULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 2U))))) 
                  << 3U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffefULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 2U)))) 
                  << 4U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffdfULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 2U))))) 
                  << 5U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffbfULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 2U))))) 
                  << 6U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffff7fULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 2U))))) 
                  << 7U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffeffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 2U))))) 
                  << 8U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffdffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 2U))))) 
                  << 9U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffbffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 2U))))) 
                  << 0xaU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 2U))))) 
                  << 0xbU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 0xcU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 0xdU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 0xeU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 0xfU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 0x10U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 0x11U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 0x12U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 0x13U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 0x14U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 0x15U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 2U))))) 
                  << 0x21U));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v2 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v2 = 1U;
    }
    if ((8U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffff7ULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 3U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffefULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 3U))))) 
                  << 4U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffdfULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 3U))))) 
                  << 5U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffbfULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 3U)))) 
                  << 6U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffff7fULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 3U))))) 
                  << 7U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffeffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 3U))))) 
                  << 8U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffdffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 3U))))) 
                  << 9U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffbffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 3U))))) 
                  << 0xaU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 3U))))) 
                  << 0xbU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 3U))))) 
                  << 0xcU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 0xdU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 0xeU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 0xfU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 0x10U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 0x11U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 0x12U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 0x13U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 0x14U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 0x15U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 3U))))) 
                  << 0x22U));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v3 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v3 = 1U;
    }
    if ((0x10U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffefULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 4U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffdfULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 4U))))) 
                  << 5U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffbfULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 4U))))) 
                  << 6U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffff7fULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 4U))))) 
                  << 7U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffeffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 4U)))) 
                  << 8U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffdffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 4U))))) 
                  << 9U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffbffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 4U))))) 
                  << 0xaU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 4U))))) 
                  << 0xbU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 4U))))) 
                  << 0xcU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 4U))))) 
                  << 0xdU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 0xeU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 0xfU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 0x10U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 0x11U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 0x12U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 0x13U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 0x14U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 0x15U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 4U))))) 
                  << 0x23U));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v4 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v4 = 1U;
    }
    if ((0x20U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffdfULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 5U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffbfULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 5U))))) 
                  << 6U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffff7fULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 5U))))) 
                  << 7U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffeffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 5U))))) 
                  << 8U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffdffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 5U))))) 
                  << 9U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffbffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 5U)))) 
                  << 0xaU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 5U))))) 
                  << 0xbU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 5U))))) 
                  << 0xcU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 5U))))) 
                  << 0xdU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 5U))))) 
                  << 0xeU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 0xfU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 0x10U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 0x11U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 0x12U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 0x13U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 0x14U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 0x15U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 5U))))) 
                  << 0x24U));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v5 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v5 = 1U;
    }
    if ((0x40U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffffbfULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 6U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffff7fULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 6U))))) 
                  << 7U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffeffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 6U))))) 
                  << 8U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffdffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 6U))))) 
                  << 9U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffbffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 6U))))) 
                  << 0xaU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 6U))))) 
                  << 0xbU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 6U)))) 
                  << 0xcU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 6U))))) 
                  << 0xdU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 6U))))) 
                  << 0xeU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 6U))))) 
                  << 0xfU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 0x10U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 0x11U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 0x12U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 0x13U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 0x14U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 0x15U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 6U))))) 
                  << 0x25U));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v6 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v6 = 1U;
    }
    if ((0x80U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffff7fULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 7U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffeffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 7U))))) 
                  << 8U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffdffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 7U))))) 
                  << 9U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffbffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 7U))))) 
                  << 0xaU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 7U))))) 
                  << 0xbU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 7U))))) 
                  << 0xcU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 7U))))) 
                  << 0xdU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 7U)))) 
                  << 0xeU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 7U))))) 
                  << 0xfU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 7U))))) 
                  << 0x10U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 0x11U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 0x12U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 0x13U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 0x14U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 0x15U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 7U))))) 
                  << 0x26U));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v7 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v7 = 1U;
    }
    if ((0x100U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffeffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 8U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffdffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 8U))))) 
                  << 9U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffbffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 8U))))) 
                  << 0xaU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 8U))))) 
                  << 0xbU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 8U))))) 
                  << 0xcU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 8U))))) 
                  << 0xdU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 8U))))) 
                  << 0xeU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 8U))))) 
                  << 0xfU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 8U)))) 
                  << 0x10U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 8U))))) 
                  << 0x11U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 0x12U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 0x13U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 0x14U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 0x15U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 8U))))) 
                  << 0x27U));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v8 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v8 = 1U;
    }
    if ((0x200U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffdffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 9U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffbffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 9U))))) 
                  << 0xaU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 9U))))) 
                  << 0xbU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 9U))))) 
                  << 0xcU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 9U))))) 
                  << 0xdU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 9U))))) 
                  << 0xeU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 9U))))) 
                  << 0xfU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 9U))))) 
                  << 0x10U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 9U))))) 
                  << 0x11U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 9U)))) 
                  << 0x12U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 0x13U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 0x14U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 0x15U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 9U))))) 
                  << 0x28U));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v9 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v9 = 1U;
    }
    if ((0x400U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffffbffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xaU))))) 
                  << 0xaU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xaU))))) 
                  << 0xbU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xaU))))) 
                  << 0xcU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xaU))))) 
                  << 0xdU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xaU))))) 
                  << 0xeU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xaU))))) 
                  << 0xfU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xaU))))) 
                  << 0x10U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xaU))))) 
                  << 0x11U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xaU))))) 
                  << 0x12U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xaU))))) 
                  << 0x13U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 0xaU)))) 
                  << 0x14U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x15U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x28U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xaU))))) 
                  << 0x29U));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v10 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v10 = 1U;
    }
    if ((0x800U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffff7ffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xbU))))) 
                  << 0xbU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xbU))))) 
                  << 0xcU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xbU))))) 
                  << 0xdU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xbU))))) 
                  << 0xeU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xbU))))) 
                  << 0xfU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xbU))))) 
                  << 0x10U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xbU))))) 
                  << 0x11U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xbU))))) 
                  << 0x12U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xbU))))) 
                  << 0x13U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xbU))))) 
                  << 0x14U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x15U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 0xbU)))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x28U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x29U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xbU))))) 
                  << 0x2aU));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v11 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v11 = 1U;
    }
    if ((0x1000U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffefffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xcU))))) 
                  << 0xcU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xcU))))) 
                  << 0xdU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xcU))))) 
                  << 0xeU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xcU))))) 
                  << 0xfU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xcU))))) 
                  << 0x10U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xcU))))) 
                  << 0x11U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xcU))))) 
                  << 0x12U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xcU))))) 
                  << 0x13U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xcU))))) 
                  << 0x14U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xcU))))) 
                  << 0x15U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 0xcU)))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x28U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x29U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x2aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xcU))))) 
                  << 0x2bU));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v12 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v12 = 1U;
    }
    if ((0x2000U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffdfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xdU))))) 
                  << 0xdU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xdU))))) 
                  << 0xeU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xdU))))) 
                  << 0xfU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xdU))))) 
                  << 0x10U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xdU))))) 
                  << 0x11U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xdU))))) 
                  << 0x12U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xdU))))) 
                  << 0x13U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xdU))))) 
                  << 0x14U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xdU))))) 
                  << 0x15U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xdU))))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 0xdU)))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x28U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x29U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x2aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x2bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xdU))))) 
                  << 0x2cU));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v13 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v13 = 1U;
    }
    if ((0x4000U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffffbfffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xeU))))) 
                  << 0xeU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xeU))))) 
                  << 0xfU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xeU))))) 
                  << 0x10U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xeU))))) 
                  << 0x11U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xeU))))) 
                  << 0x12U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xeU))))) 
                  << 0x13U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xeU))))) 
                  << 0x14U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xeU))))) 
                  << 0x15U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xeU))))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xeU))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 0xeU)))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x28U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x29U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x2aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x2bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x2cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xeU))))) 
                  << 0x2dU));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v14 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v14 = 1U;
    }
    if ((0x8000U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffff7fffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xfU))))) 
                  << 0xfU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xfU))))) 
                  << 0x10U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xfU))))) 
                  << 0x11U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xfU))))) 
                  << 0x12U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xfU))))) 
                  << 0x13U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xfU))))) 
                  << 0x14U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xfU))))) 
                  << 0x15U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xfU))))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xfU))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0xfU))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 0xfU)))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x28U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x29U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x2aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x2bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x2cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x2dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0xfU))))) 
                  << 0x2eU));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v15 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v15 = 1U;
    }
    if ((0x10000U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffeffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x10U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x10U))))) 
                  << 0x11U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x10U))))) 
                  << 0x12U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x10U))))) 
                  << 0x13U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x10U))))) 
                  << 0x14U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x10U))))) 
                  << 0x15U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x10U))))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x10U))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x10U))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x10U))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 0x10U)))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x28U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x29U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x2aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x2bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x2cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x2dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x2eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x10U))))) 
                  << 0x2fU));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v16 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v16 = 1U;
    }
    if ((0x20000U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffdffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x11U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x11U))))) 
                  << 0x12U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x11U))))) 
                  << 0x13U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x11U))))) 
                  << 0x14U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x11U))))) 
                  << 0x15U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x11U))))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x11U))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x11U))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x11U))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x11U))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 0x11U)))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x28U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x29U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x2aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x2bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x2cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x2dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x2eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x2fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x11U))))) 
                  << 0x30U));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v17 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v17 = 1U;
    }
    if ((0x40000U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffffbffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x12U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x12U))))) 
                  << 0x13U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x12U))))) 
                  << 0x14U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x12U))))) 
                  << 0x15U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x12U))))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x12U))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x12U))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x12U))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x12U))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x12U))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 0x12U)))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x28U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x29U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x2aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x2bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x2cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x2dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x2eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x2fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x30U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x12U))))) 
                  << 0x31U));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v18 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v18 = 1U;
    }
    if ((0x80000U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffff7ffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x13U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x13U))))) 
                  << 0x14U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x13U))))) 
                  << 0x15U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x13U))))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x13U))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x13U))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x13U))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x13U))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x13U))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x13U))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 0x13U)))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x28U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x29U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x2aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x2bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x2cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x2dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x2eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x2fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x30U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x31U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x13U))))) 
                  << 0x32U));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v19 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v19 = 1U;
    }
    if ((0x100000U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffefffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x14U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x14U))))) 
                  << 0x15U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x14U))))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x14U))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x14U))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x14U))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x14U))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x14U))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x14U))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x14U))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 0x14U)))) 
                  << 0x28U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x29U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x2aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x2bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x2cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x2dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x2eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x2fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x30U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x31U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x32U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x14U))))) 
                  << 0x33U));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x10000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v20 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v20 = 1U;
    }
    if ((0x200000U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffdfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x15U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x15U))))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x15U))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x15U))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x15U))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x15U))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x15U))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x15U))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x15U))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x15U))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x28U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x29U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 0x15U)))) 
                  << 0x2aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x2bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x2cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x2dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x2eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x2fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x30U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x31U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x32U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x33U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffefffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x15U))))) 
                  << 0x34U));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x20000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v21 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v21 = 1U;
    }
    if ((0x400000U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffffbfffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x16U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x16U))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x16U))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x16U))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x16U))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x16U))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x16U))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x16U))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x16U))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x16U))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x28U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x29U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x2aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x2bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 0x16U)))) 
                  << 0x2cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x2dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x2eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x2fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x30U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x31U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x32U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x33U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffefffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x34U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffdfffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x16U))))) 
                  << 0x35U));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x40000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v22 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v22 = 1U;
    }
    if ((0x800000U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffff7fffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x17U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x17U))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x17U))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x17U))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x17U))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x17U))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x17U))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x17U))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x17U))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x17U))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x28U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x29U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x2aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x2bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x2cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x2dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 0x17U)))) 
                  << 0x2eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x2fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x30U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x31U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x32U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x33U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffefffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x34U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffdfffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x35U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffbfffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x17U))))) 
                  << 0x36U));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x80000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v23 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v23 = 1U;
    }
    if ((0x1000000U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffeffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x18U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x18U))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x18U))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x18U))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x18U))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x18U))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x18U))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x18U))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x18U))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x18U))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x28U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x29U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x2aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x2bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x2cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x2dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x2eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x2fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 0x18U)))) 
                  << 0x30U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x31U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x32U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x33U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffefffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x34U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffdfffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x35U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffbfffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x36U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xff7fffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x18U))))) 
                  << 0x37U));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x100000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v24 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v24 = 1U;
    }
    if ((0x2000000U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffdffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x19U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x19U))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x19U))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x19U))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x19U))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x19U))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x19U))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x19U))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x19U))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x19U))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x28U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x29U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x2aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x2bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x2cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x2dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x2eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x2fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x30U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x31U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 0x19U)))) 
                  << 0x32U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x33U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffefffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x34U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffdfffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x35U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffbfffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x36U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xff7fffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x37U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfeffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x19U))))) 
                  << 0x38U));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x200000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v25 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v25 = 1U;
    }
    if ((0x4000000U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffffbffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x1aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1aU))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1aU))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1aU))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1aU))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1aU))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1aU))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1aU))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1aU))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1aU))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x28U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x29U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x2aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x2bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x2cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x2dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x2eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x2fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x30U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x31U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x32U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x33U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffefffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 0x1aU)))) 
                  << 0x34U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffdfffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x35U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffbfffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x36U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xff7fffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x37U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfeffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x38U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfdffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1aU))))) 
                  << 0x39U));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x400000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v26 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v26 = 1U;
    }
    if ((0x8000000U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffff7ffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x1bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1bU))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1bU))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1bU))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1bU))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1bU))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1bU))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1bU))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1bU))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1bU))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x28U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x29U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x2aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x2bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x2cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x2dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x2eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x2fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x30U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x31U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x32U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x33U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffefffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x34U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffdfffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x35U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffbfffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 0x1bU)))) 
                  << 0x36U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xff7fffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x37U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfeffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x38U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfdffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x39U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfbffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1bU))))) 
                  << 0x3aU));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x800000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v27 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v27 = 1U;
    }
    if ((0x10000000U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffefffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x1cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1cU))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1cU))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1cU))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1cU))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1cU))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1cU))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1cU))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1cU))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1cU))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x28U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x29U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x2aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x2bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x2cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x2dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x2eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x2fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x30U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x31U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x32U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x33U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffefffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x34U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffdfffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x35U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffbfffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x36U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xff7fffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x37U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfeffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 0x1cU)))) 
                  << 0x38U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfdffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x39U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfbffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x3aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xf7ffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1cU))))) 
                  << 0x3bU));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x1000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v28 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v28 = 1U;
    }
    if ((0x20000000U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffdfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x1dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1dU))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1dU))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1dU))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1dU))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1dU))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1dU))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1dU))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1dU))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1dU))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x28U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x29U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x2aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x2bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x2cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x2dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x2eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x2fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x30U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x31U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x32U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x33U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffefffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x34U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffdfffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x35U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffbfffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x36U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xff7fffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x37U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfeffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x38U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfdffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x39U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfbffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 0x1dU)))) 
                  << 0x3aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xf7ffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x3bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xefffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1dU))))) 
                  << 0x3cU));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x2000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v29 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v29 = 1U;
    }
    if ((0x40000000U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffffbfffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x1eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1eU))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1eU))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1eU))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1eU))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1eU))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1eU))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1eU))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1eU))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1eU))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x28U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x29U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x2aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x2bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x2cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x2dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x2eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x2fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x30U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x31U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x32U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x33U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffefffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x34U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffdfffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x35U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffbfffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x36U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xff7fffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x37U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfeffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x38U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfdffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x39U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfbffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x3aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xf7ffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x3bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xefffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 0x1eU)))) 
                  << 0x3cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xdfffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1fU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1eU))))) 
                  << 0x3dU));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x4000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v30 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v30 = 1U;
    }
    if ((0x80000000U & vlTOPp->x0_multiplier__DOT__op2)) {
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = 0ULL;
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffff7fffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & (vlTOPp->x0_multiplier__DOT__op1 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x1fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffeffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 1U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1fU))))) 
                  << 0x20U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffdffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 2U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1fU))))) 
                  << 0x21U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffffbffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 3U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1fU))))) 
                  << 0x22U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffff7ffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 4U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1fU))))) 
                  << 0x23U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffefffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 5U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1fU))))) 
                  << 0x24U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffdfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 6U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1fU))))) 
                  << 0x25U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffffbfffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 7U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1fU))))) 
                  << 0x26U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffff7fffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 8U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1fU))))) 
                  << 0x27U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffeffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 9U) & 
                                         (vlTOPp->x0_multiplier__DOT__op2 
                                          >> 0x1fU))))) 
                  << 0x28U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffdffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xaU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x29U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffffbffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xbU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x2aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffff7ffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xcU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x2bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffefffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xdU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x2cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffdfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xeU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x2dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffffbfffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0xfU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x2eU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffff7fffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x10U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x2fU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffeffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x11U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x30U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffdffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x12U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x31U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfffbffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x13U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x32U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfff7ffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x14U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x33U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffefffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x15U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x34U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffdfffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x16U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x35U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xffbfffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x17U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x36U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xff7fffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x18U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x37U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfeffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x19U) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x38U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfdffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1aU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x39U));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xfbffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1bU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x3aU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xf7ffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1cU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x3bU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xefffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1dU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x3cU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xdfffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          >> 0x1eU) 
                                         & (vlTOPp->x0_multiplier__DOT__op2 
                                            >> 0x1fU))))) 
                  << 0x3dU));
        vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
            = ((0xbfffffffffffffffULL & vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod) 
               | ((QData)((IData)((1U & ((vlTOPp->x0_multiplier__DOT__op1 
                                          & vlTOPp->x0_multiplier__DOT__op2) 
                                         >> 0x1fU)))) 
                  << 0x3eU));
        if (((IData)(vlTOPp->x0_multiplier__DOT__signed_type) 
             & (vlTOPp->x0_multiplier__DOT__op1 >> 0x1fU))) {
            vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod 
                = (0x8000000000000000ULL | vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        }
        vlTOPp->__Vdlyvval__x0_multiplier__DOT__product__v31 
            = (IData)(vlTOPp->x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod);
        vlTOPp->__Vdlyvset__x0_multiplier__DOT__product__v31 = 1U;
    }
}
