// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vexe.h for the primary calling header

#include "Vexe.h"
#include "Vexe__Syms.h"

//==========
CData/*0:0*/ Vexe::__Vtable1_exe__DOT__divider_i__DOT__setup_regs[8];
CData/*0:0*/ Vexe::__Vtable1_exe__DOT__divider_i__DOT__same[8];
CData/*0:0*/ Vexe::__Vtable1_exe__DOT__divider_i__DOT__zero_div[8];
CData/*0:0*/ Vexe::__Vtable1_exe__DOT__divider_i__DOT__running[8];
CData/*0:0*/ Vexe::__Vtable1_exe__DOT__done_div[8];
CData/*0:0*/ Vexe::__Vtable1_exe__DOT__busy_div[8];

VL_CTOR_IMP(Vexe) {
    Vexe__Syms* __restrict vlSymsp = __VlSymsp = new Vexe__Syms(this, name());
    Vexe* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vexe::__Vconfigure(Vexe__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vexe::~Vexe() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vexe::_settle__TOP__1(Vexe__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexe::_settle__TOP__1\n"); );
    Vexe* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->exe__DOT__exe2mem_x[0U] = 0U;
    vlTOPp->exe__DOT__exe2mem_x[1U] = 0U;
    vlTOPp->exe__DOT__exe2mem_x[2U] = (0xfffff000U 
                                       & vlTOPp->exe__DOT__exe2mem_x[2U]);
    vlTOPp->exe__DOT__exe2mem_x[3U] = (0xfffU & vlTOPp->exe__DOT__exe2mem_x[3U]);
    vlTOPp->exe__DOT__exe2mem_x[4U] = 0U;
    vlTOPp->exe__DOT__exe2mem_x[5U] = 0U;
    vlTOPp->exe__DOT__exe2mem_x[6U] = 0U;
    vlTOPp->exe__DOT__divider_i__DOT__divisor_setup 
        = (0x7fffffffffffffffULL & vlTOPp->exe__DOT__divider_i__DOT__divisor_setup);
    vlTOPp->exe__DOT__divider_i__DOT__divisor_setup 
        = (0xffffffff80000000ULL & vlTOPp->exe__DOT__divider_i__DOT__divisor_setup);
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
    vlTOPp->x0_multiplier__DOT__signed_type = ((~ (
                                                   ((2U 
                                                     == (IData)(vlTOPp->MULT_CMD_RD)) 
                                                    | (1U 
                                                       == (IData)(vlTOPp->MULT_CMD_RD))) 
                                                   & ((vlTOPp->x0_multiplier__02EOP1_SE 
                                                       & vlTOPp->x0_multiplier__02EOP2_SE) 
                                                      >> 0x1fU))) 
                                               & (3U 
                                                  != (IData)(vlTOPp->MULT_CMD_RD)));
    if ((((vlTOPp->x0_multiplier__02EOP1_SE & vlTOPp->x0_multiplier__02EOP2_SE) 
          >> 0x1fU) & ((2U == (IData)(vlTOPp->MULT_CMD_RD)) 
                       | (1U == (IData)(vlTOPp->MULT_CMD_RD))))) {
        vlTOPp->x0_multiplier__DOT__op1 = ((IData)(1U) 
                                           + (~ vlTOPp->x0_multiplier__02EOP1_SE));
        vlTOPp->x0_multiplier__DOT__op2 = ((IData)(1U) 
                                           + (~ vlTOPp->x0_multiplier__02EOP2_SE));
    } else {
        vlTOPp->x0_multiplier__DOT__op1 = ((((~ (vlTOPp->x0_multiplier__02EOP1_SE 
                                                 >> 0x1fU)) 
                                             & (vlTOPp->x0_multiplier__02EOP2_SE 
                                                >> 0x1fU)) 
                                            & ((2U 
                                                == (IData)(vlTOPp->MULT_CMD_RD)) 
                                               | (1U 
                                                  == (IData)(vlTOPp->MULT_CMD_RD))))
                                            ? vlTOPp->x0_multiplier__02EOP1_SE
                                            : vlTOPp->x0_multiplier__02EOP2_SE);
        vlTOPp->x0_multiplier__DOT__op2 = ((((~ (vlTOPp->x0_multiplier__02EOP1_SE 
                                                 >> 0x1fU)) 
                                             & (vlTOPp->x0_multiplier__02EOP2_SE 
                                                >> 0x1fU)) 
                                            & ((2U 
                                                == (IData)(vlTOPp->MULT_CMD_RD)) 
                                               | (1U 
                                                  == (IData)(vlTOPp->MULT_CMD_RD))))
                                            ? vlTOPp->x0_multiplier__02EOP2_SE
                                            : vlTOPp->x0_multiplier__02EOP1_SE);
    }
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
    vlTOPp->SELECT_MSB_RX0 = (1U & (vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[0xaU] 
                                    >> 1U));
    vlTOPp->SIGNED_RES_RX0 = (1U & vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[0xaU]);
    vlTOPp->RES_RX0[0U] = vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[0U];
    vlTOPp->RES_RX0[1U] = vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[1U];
    vlTOPp->RES_RX0[2U] = vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[2U];
    vlTOPp->RES_RX0[3U] = vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[3U];
    vlTOPp->RES_RX0[4U] = vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[4U];
    vlTOPp->RES_RX0[5U] = vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[5U];
    vlTOPp->RES_RX0[6U] = vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[6U];
    vlTOPp->RES_RX0[7U] = vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[7U];
    vlTOPp->RES_RX0[8U] = vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[8U];
    vlTOPp->RES_RX0[9U] = vlTOPp->x0_multiplier__DOT__x0x1__DOT__data[9U];
    vlTOPp->exe__DOT__divider_i__DOT__quotient = ((IData)(vlTOPp->exe__DOT__divider_i__DOT__quotient_sign_reg)
                                                   ? 
                                                  (~ 
                                                   ((IData)(1U) 
                                                    + vlTOPp->exe__DOT__divider_i__DOT__quotient_reg))
                                                   : vlTOPp->exe__DOT__divider_i__DOT__quotient_reg);
    vlTOPp->__Vtableidx1 = vlTOPp->exe__DOT__divider_i__DOT__EP;
    vlTOPp->exe__DOT__divider_i__DOT__setup_regs = 
        vlTOPp->__Vtable1_exe__DOT__divider_i__DOT__setup_regs
        [vlTOPp->__Vtableidx1];
    vlTOPp->exe__DOT__divider_i__DOT__same = vlTOPp->__Vtable1_exe__DOT__divider_i__DOT__same
        [vlTOPp->__Vtableidx1];
    vlTOPp->exe__DOT__divider_i__DOT__zero_div = vlTOPp->__Vtable1_exe__DOT__divider_i__DOT__zero_div
        [vlTOPp->__Vtableidx1];
    vlTOPp->exe__DOT__divider_i__DOT__running = vlTOPp->__Vtable1_exe__DOT__divider_i__DOT__running
        [vlTOPp->__Vtableidx1];
    vlTOPp->exe__DOT__done_div = vlTOPp->__Vtable1_exe__DOT__done_div
        [vlTOPp->__Vtableidx1];
    vlTOPp->exe__DOT__busy_div = vlTOPp->__Vtable1_exe__DOT__busy_div
        [vlTOPp->__Vtableidx1];
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__0__KET____DOT__csa1__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                           [0U])) ^ (QData)((IData)(
                                                    vlTOPp->x0_multiplier__DOT__product
                                                    [1U])));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__1__KET____DOT__csa1__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                           [3U])) ^ (QData)((IData)(
                                                    vlTOPp->x0_multiplier__DOT__product
                                                    [4U])));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__2__KET____DOT__csa1__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                           [6U])) ^ (QData)((IData)(
                                                    vlTOPp->x0_multiplier__DOT__product
                                                    [7U])));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__3__KET____DOT__csa1__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                           [9U])) ^ (QData)((IData)(
                                                    vlTOPp->x0_multiplier__DOT__product
                                                    [0xaU])));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__4__KET____DOT__csa1__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                           [0xcU])) ^ (QData)((IData)(
                                                      vlTOPp->x0_multiplier__DOT__product
                                                      [0xdU])));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__5__KET____DOT__csa1__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                           [0xfU])) ^ (QData)((IData)(
                                                      vlTOPp->x0_multiplier__DOT__product
                                                      [0x10U])));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__6__KET____DOT__csa1__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                           [0x12U])) ^ (QData)((IData)(
                                                       vlTOPp->x0_multiplier__DOT__product
                                                       [0x13U])));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__7__KET____DOT__csa1__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                           [0x15U])) ^ (QData)((IData)(
                                                       vlTOPp->x0_multiplier__DOT__product
                                                       [0x16U])));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__8__KET____DOT__csa1__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                           [0x18U])) ^ (QData)((IData)(
                                                       vlTOPp->x0_multiplier__DOT__product
                                                       [0x19U])));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__9__KET____DOT__csa1__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                           [0x1bU])) ^ (QData)((IData)(
                                                       vlTOPp->x0_multiplier__DOT__product
                                                       [0x1cU])));
    vlTOPp->exe__DOT__op1 = (((0U == (IData)(vlTOPp->RADR1_RD)) 
                              | (IData)(vlTOPp->BLOCK_BP_RD))
                              ? vlTOPp->OP1_RD : ((
                                                   ((0x3fU 
                                                     & vlTOPp->exe__DOT__exe2mem__DOT__data[2U]) 
                                                    == (IData)(vlTOPp->RADR1_RD)) 
                                                   & (vlTOPp->exe__DOT__exe2mem__DOT__data[3U] 
                                                      >> 0xcU))
                                                   ? 
                                                  ((vlTOPp->exe__DOT__exe2mem__DOT__data[4U] 
                                                    << 7U) 
                                                   | (vlTOPp->exe__DOT__exe2mem__DOT__data[3U] 
                                                      >> 0x19U))
                                                   : 
                                                  ((((0x3fU 
                                                      & vlTOPp->exe__DOT__exe2mem__DOT__data[2U]) 
                                                     == (IData)(vlTOPp->RADR1_RD)) 
                                                    & (~ 
                                                       (vlTOPp->exe__DOT__exe2mem__DOT__data[2U] 
                                                        >> 9U)))
                                                    ? 
                                                   vlTOPp->exe__DOT__exe2mem__DOT__data[0U]
                                                    : 
                                                   ((((0x3fU 
                                                       & vlTOPp->exe__DOT__exe2mem__DOT__data[2U]) 
                                                      == (IData)(vlTOPp->RADR1_RD)) 
                                                     & (IData)(vlTOPp->CSR_WENABLE_RM))
                                                     ? vlTOPp->CSR_RDATA_RM
                                                     : 
                                                    (((IData)(vlTOPp->MEM_DEST_RM) 
                                                      == (IData)(vlTOPp->RADR1_RD))
                                                      ? vlTOPp->MEM_RES_RM
                                                      : vlTOPp->OP1_RD)))));
    vlTOPp->exe__DOT__op2 = ((((0U == (IData)(vlTOPp->RADR2_RD)) 
                               | (IData)(vlTOPp->MEM_LOAD_RD)) 
                              | (IData)(vlTOPp->BLOCK_BP_RD))
                              ? vlTOPp->OP2_RD : ((
                                                   ((((0x3fU 
                                                       & vlTOPp->exe__DOT__exe2mem__DOT__data[2U]) 
                                                      == (IData)(vlTOPp->RADR2_RD)) 
                                                     & (~ 
                                                        (vlTOPp->exe__DOT__exe2mem__DOT__data[2U] 
                                                         >> 9U))) 
                                                    & (~ (IData)(vlTOPp->MEM_STORE_RD))) 
                                                   & (~ 
                                                      (vlTOPp->exe__DOT__exe2mem__DOT__data[6U] 
                                                       >> 7U)))
                                                   ? 
                                                  vlTOPp->exe__DOT__exe2mem__DOT__data[0U]
                                                   : 
                                                  (((((IData)(vlTOPp->MEM_DEST_RM) 
                                                      == (IData)(vlTOPp->RADR2_RD)) 
                                                     & (IData)(vlTOPp->MEM_STORE_RD)) 
                                                    & (~ (IData)(vlTOPp->MULT_INST_RM)))
                                                    ? vlTOPp->OP2_RD
                                                    : 
                                                   (((((IData)(vlTOPp->MEM_DEST_RM) 
                                                       == (IData)(vlTOPp->RADR2_RD)) 
                                                      & (~ (IData)(vlTOPp->MEM_STORE_RD))) 
                                                     & (~ (IData)(vlTOPp->MULT_INST_RM)))
                                                     ? vlTOPp->MEM_RES_RM
                                                     : vlTOPp->OP2_RD))));
    vlTOPp->exe__DOT__exe2mem_data[1U] = (((((((0x3fU 
                                                & vlTOPp->exe__DOT__exe2mem__DOT__data[2U]) 
                                               == (IData)(vlTOPp->RADR2_RD)) 
                                              & (~ 
                                                 (vlTOPp->exe__DOT__exe2mem__DOT__data[2U] 
                                                  >> 9U))) 
                                             & (~ (
                                                   vlTOPp->exe__DOT__exe2mem__DOT__data[6U] 
                                                   >> 7U))) 
                                            & (~ (IData)(vlTOPp->exe__DOT__bpc_disable2))) 
                                           & (vlTOPp->exe__DOT__exe2mem__DOT__data[3U] 
                                              >> 0xcU))
                                           ? ((vlTOPp->exe__DOT__exe2mem__DOT__data[4U] 
                                               << 7U) 
                                              | (vlTOPp->exe__DOT__exe2mem__DOT__data[3U] 
                                                 >> 0x19U))
                                           : ((((((0x3fU 
                                                   & vlTOPp->exe__DOT__exe2mem__DOT__data[2U]) 
                                                  == (IData)(vlTOPp->RADR2_RD)) 
                                                 & (~ 
                                                    (vlTOPp->exe__DOT__exe2mem__DOT__data[2U] 
                                                     >> 9U))) 
                                                & (~ 
                                                   (vlTOPp->exe__DOT__exe2mem__DOT__data[6U] 
                                                    >> 7U))) 
                                               & (~ (IData)(vlTOPp->exe__DOT__bpc_disable2)))
                                               ? vlTOPp->exe__DOT__exe2mem__DOT__data[0U]
                                               : ((
                                                   ((((IData)(vlTOPp->MEM_DEST_RM) 
                                                      == (IData)(vlTOPp->RADR2_RD)) 
                                                     & (IData)(vlTOPp->MEM_STORE_RD)) 
                                                    & (~ (IData)(vlTOPp->MULT_INST_RM))) 
                                                   & (~ (IData)(vlTOPp->exe__DOT__bpc_disable2)))
                                                   ? vlTOPp->MEM_RES_RM
                                                   : vlTOPp->MEM_DATA_RD)));
    vlTOPp->exe__DOT__start_div = ((((8U == (IData)(vlTOPp->SELECT_OPERATION_RD)) 
                                     & (~ (IData)(vlTOPp->DEC2EXE_EMPTY_SD))) 
                                    & (~ (IData)(vlTOPp->exe__DOT__busy_div))) 
                                   & (~ (IData)(vlTOPp->exe__DOT__done_div)));
    vlTOPp->exe__DOT__divider_i__DOT__signed_inst = 
        ((IData)(vlTOPp->exe__DOT__divider_i__DOT__setup_regs) 
         & ((3U == (IData)(vlTOPp->CMD_RD)) | (1U == (IData)(vlTOPp->CMD_RD))));
    vlTOPp->x0_multiplier__DOT__product_s1[0U] = (0xfffffU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__genblk1__BRA__0__KET____DOT__csa1__DOT__AxB) 
                                                     ^ (IData)((QData)((IData)(
                                                                               vlTOPp->x0_multiplier__DOT__product
                                                                               [2U])))));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__0__KET____DOT__csa1__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                            [0U])) & (QData)((IData)(
                                                     vlTOPp->x0_multiplier__DOT__product
                                                     [1U]))) 
           | (vlTOPp->x0_multiplier__DOT__genblk1__BRA__0__KET____DOT__csa1__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                                [2U]))));
    vlTOPp->x0_multiplier__DOT__product_s1[2U] = (0xfffffU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__genblk1__BRA__1__KET____DOT__csa1__DOT__AxB) 
                                                     ^ (IData)((QData)((IData)(
                                                                               vlTOPp->x0_multiplier__DOT__product
                                                                               [5U])))));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__1__KET____DOT__csa1__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                            [3U])) & (QData)((IData)(
                                                     vlTOPp->x0_multiplier__DOT__product
                                                     [4U]))) 
           | (vlTOPp->x0_multiplier__DOT__genblk1__BRA__1__KET____DOT__csa1__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                                [5U]))));
    vlTOPp->x0_multiplier__DOT__product_s1[4U] = (0xfffffU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__genblk1__BRA__2__KET____DOT__csa1__DOT__AxB) 
                                                     ^ (IData)((QData)((IData)(
                                                                               vlTOPp->x0_multiplier__DOT__product
                                                                               [8U])))));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__2__KET____DOT__csa1__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                            [6U])) & (QData)((IData)(
                                                     vlTOPp->x0_multiplier__DOT__product
                                                     [7U]))) 
           | (vlTOPp->x0_multiplier__DOT__genblk1__BRA__2__KET____DOT__csa1__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                                [8U]))));
    vlTOPp->x0_multiplier__DOT__product_s1[6U] = (0xfffffU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__genblk1__BRA__3__KET____DOT__csa1__DOT__AxB) 
                                                     ^ (IData)((QData)((IData)(
                                                                               vlTOPp->x0_multiplier__DOT__product
                                                                               [0xbU])))));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__3__KET____DOT__csa1__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                            [9U])) & (QData)((IData)(
                                                     vlTOPp->x0_multiplier__DOT__product
                                                     [0xaU]))) 
           | (vlTOPp->x0_multiplier__DOT__genblk1__BRA__3__KET____DOT__csa1__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                                [0xbU]))));
    vlTOPp->x0_multiplier__DOT__product_s1[8U] = (0xfffffU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__genblk1__BRA__4__KET____DOT__csa1__DOT__AxB) 
                                                     ^ (IData)((QData)((IData)(
                                                                               vlTOPp->x0_multiplier__DOT__product
                                                                               [0xeU])))));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__4__KET____DOT__csa1__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                            [0xcU])) & (QData)((IData)(
                                                       vlTOPp->x0_multiplier__DOT__product
                                                       [0xdU]))) 
           | (vlTOPp->x0_multiplier__DOT__genblk1__BRA__4__KET____DOT__csa1__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                                [0xeU]))));
    vlTOPp->x0_multiplier__DOT__product_s1[0xaU] = 
        (0xfffffU & ((IData)(vlTOPp->x0_multiplier__DOT__genblk1__BRA__5__KET____DOT__csa1__DOT__AxB) 
                     ^ (IData)((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                                               [0x11U])))));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__5__KET____DOT__csa1__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                            [0xfU])) & (QData)((IData)(
                                                       vlTOPp->x0_multiplier__DOT__product
                                                       [0x10U]))) 
           | (vlTOPp->x0_multiplier__DOT__genblk1__BRA__5__KET____DOT__csa1__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                                [0x11U]))));
    vlTOPp->x0_multiplier__DOT__product_s1[0xcU] = 
        (0xfffffU & ((IData)(vlTOPp->x0_multiplier__DOT__genblk1__BRA__6__KET____DOT__csa1__DOT__AxB) 
                     ^ (IData)((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                                               [0x14U])))));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__6__KET____DOT__csa1__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                            [0x12U])) & (QData)((IData)(
                                                        vlTOPp->x0_multiplier__DOT__product
                                                        [0x13U]))) 
           | (vlTOPp->x0_multiplier__DOT__genblk1__BRA__6__KET____DOT__csa1__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                                [0x14U]))));
    vlTOPp->x0_multiplier__DOT__product_s1[0xeU] = 
        (0xfffffU & ((IData)(vlTOPp->x0_multiplier__DOT__genblk1__BRA__7__KET____DOT__csa1__DOT__AxB) 
                     ^ (IData)((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                                               [0x17U])))));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__7__KET____DOT__csa1__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                            [0x15U])) & (QData)((IData)(
                                                        vlTOPp->x0_multiplier__DOT__product
                                                        [0x16U]))) 
           | (vlTOPp->x0_multiplier__DOT__genblk1__BRA__7__KET____DOT__csa1__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                                [0x17U]))));
    vlTOPp->x0_multiplier__DOT__product_s1[0x10U] = 
        (0xfffffU & ((IData)(vlTOPp->x0_multiplier__DOT__genblk1__BRA__8__KET____DOT__csa1__DOT__AxB) 
                     ^ (IData)((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                                               [0x1aU])))));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__8__KET____DOT__csa1__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                            [0x18U])) & (QData)((IData)(
                                                        vlTOPp->x0_multiplier__DOT__product
                                                        [0x19U]))) 
           | (vlTOPp->x0_multiplier__DOT__genblk1__BRA__8__KET____DOT__csa1__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                                [0x1aU]))));
    vlTOPp->x0_multiplier__DOT__product_s1[0x12U] = 
        (0xfffffU & ((IData)(vlTOPp->x0_multiplier__DOT__genblk1__BRA__9__KET____DOT__csa1__DOT__AxB) 
                     ^ (IData)((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                                               [0x1dU])))));
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__9__KET____DOT__csa1__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                            [0x1bU])) & (QData)((IData)(
                                                        vlTOPp->x0_multiplier__DOT__product
                                                        [0x1cU]))) 
           | (vlTOPp->x0_multiplier__DOT__genblk1__BRA__9__KET____DOT__csa1__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                                [0x1dU]))));
    vlTOPp->exe__02EOP1_SE = vlTOPp->exe__DOT__op1;
    vlTOPp->exe__02EOP2_SE = vlTOPp->exe__DOT__op2;
    if ((0x10U & vlTOPp->exe__DOT__op2)) {
        vlTOPp->exe__DOT__shifter_i__DOT__lshift16 
            = (0xffff0000U & (vlTOPp->exe__DOT__op1 
                              << 0x10U));
        vlTOPp->exe__DOT__shifter_i__DOT__rshift16 
            = ((((2U & (IData)(vlTOPp->CMD_RD)) ? (0xffffU 
                                                   & (- (IData)(
                                                                (1U 
                                                                 & (vlTOPp->exe__DOT__op1 
                                                                    >> 0x1fU)))))
                  : 0U) << 0x10U) | (0xffffU & (vlTOPp->exe__DOT__op1 
                                                >> 0x10U)));
    } else {
        vlTOPp->exe__DOT__shifter_i__DOT__lshift16 
            = vlTOPp->exe__DOT__op1;
        vlTOPp->exe__DOT__shifter_i__DOT__rshift16 
            = vlTOPp->exe__DOT__op1;
    }
    vlTOPp->exe__DOT__alu_op2 = ((IData)(vlTOPp->NEG_OP2_RD)
                                  ? (~ vlTOPp->exe__DOT__op2)
                                  : vlTOPp->exe__DOT__op2);
    vlTOPp->exe__DOT__divider_i__DOT__divisor_setup 
        = ((0x800000007fffffffULL & vlTOPp->exe__DOT__divider_i__DOT__divisor_setup) 
           | ((QData)((IData)(((((IData)(vlTOPp->exe__DOT__divider_i__DOT__setup_regs) 
                                 & (IData)(vlTOPp->exe__DOT__divider_i__DOT__signed_inst)) 
                                & (vlTOPp->exe__DOT__divider_i__DOT__op2 
                                   >> 0x1fU)) ? ((IData)(1U) 
                                                 + 
                                                 (~ vlTOPp->exe__DOT__divider_i__DOT__op2))
                                : vlTOPp->exe__DOT__divider_i__DOT__op2))) 
              << 0x1fU));
    if ((8U & vlTOPp->exe__DOT__op2)) {
        vlTOPp->exe__DOT__shifter_i__DOT__lshift8 = 
            (0xffffff00U & (vlTOPp->exe__DOT__shifter_i__DOT__lshift16 
                            << 8U));
        vlTOPp->exe__DOT__shifter_i__DOT__rshift8 = 
            ((((2U & (IData)(vlTOPp->CMD_RD)) ? (0xffU 
                                                 & (- (IData)(
                                                              (1U 
                                                               & (vlTOPp->exe__DOT__op1 
                                                                  >> 0x1fU)))))
                : 0U) << 0x18U) | (0xffffffU & (vlTOPp->exe__DOT__shifter_i__DOT__rshift16 
                                                >> 8U)));
    } else {
        vlTOPp->exe__DOT__shifter_i__DOT__lshift8 = vlTOPp->exe__DOT__shifter_i__DOT__lshift16;
        vlTOPp->exe__DOT__shifter_i__DOT__rshift8 = vlTOPp->exe__DOT__shifter_i__DOT__rshift16;
    }
    vlTOPp->exe__DOT__alu_res = ((2U & (IData)(vlTOPp->CMD_RD))
                                  ? ((1U & (IData)(vlTOPp->CMD_RD))
                                      ? (vlTOPp->exe__DOT__op1 
                                         ^ vlTOPp->exe__DOT__alu_op2)
                                      : (vlTOPp->exe__DOT__op1 
                                         | vlTOPp->exe__DOT__alu_op2))
                                  : ((1U & (IData)(vlTOPp->CMD_RD))
                                      ? (vlTOPp->exe__DOT__op1 
                                         & vlTOPp->exe__DOT__alu_op2)
                                      : ((vlTOPp->exe__DOT__op1 
                                          + vlTOPp->exe__DOT__alu_op2) 
                                         + (IData)(vlTOPp->NEG_OP2_RD))));
    vlTOPp->exe__DOT__divider_i__DOT__divisor_se = 
        ((IData)(vlTOPp->exe__DOT__divider_i__DOT__setup_regs)
          ? vlTOPp->exe__DOT__divider_i__DOT__divisor_setup
          : ((IData)(vlTOPp->exe__DOT__divider_i__DOT__running)
              ? (0x7fffffffffffffffULL & (vlTOPp->exe__DOT__divider_i__DOT__divisor_reg 
                                          >> 1U)) : 0ULL));
    if ((4U & vlTOPp->exe__DOT__op2)) {
        vlTOPp->exe__DOT__shifter_i__DOT__lshift4 = 
            (0xfffffff0U & (vlTOPp->exe__DOT__shifter_i__DOT__lshift8 
                            << 4U));
        vlTOPp->exe__DOT__shifter_i__DOT__rshift4 = 
            ((((2U & (IData)(vlTOPp->CMD_RD)) ? (0xfU 
                                                 & (- (IData)(
                                                              (1U 
                                                               & (vlTOPp->exe__DOT__op1 
                                                                  >> 0x1fU)))))
                : 0U) << 0x1cU) | (0xfffffffU & (vlTOPp->exe__DOT__shifter_i__DOT__rshift8 
                                                 >> 4U)));
    } else {
        vlTOPp->exe__DOT__shifter_i__DOT__lshift4 = vlTOPp->exe__DOT__shifter_i__DOT__lshift8;
        vlTOPp->exe__DOT__shifter_i__DOT__rshift4 = vlTOPp->exe__DOT__shifter_i__DOT__rshift8;
    }
    vlTOPp->exe__DOT__adress_misaligned = (((0U != 
                                             (3U & vlTOPp->exe__DOT__alu_res)) 
                                            & (0U == (IData)(vlTOPp->MEM_SIZE_RD))) 
                                           | (vlTOPp->exe__DOT__alu_res 
                                              & (1U 
                                                 == (IData)(vlTOPp->MEM_SIZE_RD))));
    vlTOPp->exe__DOT__access_fault = ((0xf0000000U 
                                       < vlTOPp->exe__DOT__alu_res) 
                                      & (0U == (IData)(vlTOPp->CURRENT_MODE_SM)));
    if ((2U & vlTOPp->exe__DOT__op2)) {
        vlTOPp->exe__DOT__shifter_i__DOT__lshift2 = 
            (0xfffffffcU & (vlTOPp->exe__DOT__shifter_i__DOT__lshift4 
                            << 2U));
        vlTOPp->exe__DOT__shifter_i__DOT__rshift2 = 
            ((((2U & (IData)(vlTOPp->CMD_RD)) ? (3U 
                                                 & (- (IData)(
                                                              (1U 
                                                               & (vlTOPp->exe__DOT__op1 
                                                                  >> 0x1fU)))))
                : 0U) << 0x1eU) | (0x3fffffffU & (vlTOPp->exe__DOT__shifter_i__DOT__rshift4 
                                                  >> 2U)));
    } else {
        vlTOPp->exe__DOT__shifter_i__DOT__lshift2 = vlTOPp->exe__DOT__shifter_i__DOT__lshift4;
        vlTOPp->exe__DOT__shifter_i__DOT__rshift2 = vlTOPp->exe__DOT__shifter_i__DOT__rshift4;
    }
}

void Vexe::_initial__TOP__2(Vexe__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexe::_initial__TOP__2\n"); );
    Vexe* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->x0_multiplier__DOT__stage5__BRA__0__KET____DOT__csa5__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__stage5__BRA__1__KET____DOT__csa5__DOT__shf = 0ULL;
    vlTOPp->exe__DOT__divider_i__DOT__cmd_reg = 0U;
    vlTOPp->exe__DOT__divider_i__DOT__quotient = 0U;
    vlTOPp->exe__DOT__divider_i__DOT__reminder_reg = 0ULL;
    vlTOPp->exe__DOT__exception_se = 0U;
    vlTOPp->exe__DOT__load_adress_misaligned_se = 0U;
    vlTOPp->exe__DOT__store_adress_misaligned_se = 0U;
    vlTOPp->exe__DOT__load_access_fault_se = 0U;
    vlTOPp->exe__DOT__store_access_fault_se = 0U;
    vlTOPp->x0_multiplier__DOT__stage4__BRA__0__KET____DOT__csa4__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__stage4__BRA__1__KET____DOT__csa4__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__stage4__BRA__2__KET____DOT__csa4__DOT__shf = 0ULL;
    vlTOPp->exe__DOT__adress_misaligned = 0U;
    vlTOPp->exe__DOT__access_fault = 0U;
    vlTOPp->x0_multiplier__DOT__csa3_4__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__csa_instance__BRA__0__KET____DOT__csa3__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__csa_instance__BRA__1__KET____DOT__csa3__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__csa_instance__BRA__2__KET____DOT__csa3__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__csa_instance__BRA__3__KET____DOT__csa3__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__csa2_6__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__0__KET____DOT__csa2__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__1__KET____DOT__csa2__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__2__KET____DOT__csa2__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__3__KET____DOT__csa2__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__4__KET____DOT__csa2__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__5__KET____DOT__csa2__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__0__KET____DOT__csa1__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__1__KET____DOT__csa1__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__2__KET____DOT__csa1__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__3__KET____DOT__csa1__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__4__KET____DOT__csa1__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__5__KET____DOT__csa1__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__6__KET____DOT__csa1__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__7__KET____DOT__csa1__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__8__KET____DOT__csa1__DOT__shf = 0ULL;
    vlTOPp->x0_multiplier__DOT__genblk1__BRA__9__KET____DOT__csa1__DOT__shf = 0ULL;
    vlTOPp->exe__DOT__divider_i__DOT__reminder_se = 0ULL;
    vlTOPp->exe__DOT__divider_i__DOT__shift_cpt_reg = 0U;
    vlTOPp->x0_multiplier__DOT__x0x1__DOT__data_v = 0U;
    vlTOPp->exe__DOT__exe2mem__DOT__data_v = 0U;
}

void Vexe::_settle__TOP__8(Vexe__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexe::_settle__TOP__8\n"); );
    Vexe* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->exe__DOT__divider_i__DOT__division = (vlTOPp->exe__DOT__divider_i__DOT__divisor_reg 
                                                  > vlTOPp->exe__DOT__divider_i__DOT__reminder_reg);
    vlTOPp->exe__DOT__exe_res = ((8U == (IData)(vlTOPp->SELECT_OPERATION_RD))
                                  ? (((3U == (IData)(vlTOPp->exe__DOT__divider_i__DOT__cmd_reg)) 
                                      | (0U == (IData)(vlTOPp->exe__DOT__divider_i__DOT__cmd_reg)))
                                      ? ((IData)(vlTOPp->exe__DOT__divider_i__DOT__reminder_sign_reg)
                                          ? (~ ((IData)(1U) 
                                                + (IData)(vlTOPp->exe__DOT__divider_i__DOT__reminder_reg)))
                                          : (IData)(vlTOPp->exe__DOT__divider_i__DOT__reminder_reg))
                                      : vlTOPp->exe__DOT__divider_i__DOT__quotient)
                                  : ((2U == (IData)(vlTOPp->SELECT_OPERATION_RD))
                                      ? ((0U == (IData)(vlTOPp->CMD_RD))
                                          ? ((1U & vlTOPp->exe__DOT__op2)
                                              ? (0xfffffffeU 
                                                 & (vlTOPp->exe__DOT__shifter_i__DOT__lshift2 
                                                    << 1U))
                                              : vlTOPp->exe__DOT__shifter_i__DOT__lshift2)
                                          : ((1U & vlTOPp->exe__DOT__op2)
                                              ? ((0x80000000U 
                                                  & (((IData)(vlTOPp->CMD_RD) 
                                                      << 0x1eU) 
                                                     & vlTOPp->exe__DOT__op1)) 
                                                 | (0x7fffffffU 
                                                    & (vlTOPp->exe__DOT__shifter_i__DOT__rshift2 
                                                       >> 1U)))
                                              : vlTOPp->exe__DOT__shifter_i__DOT__rshift2))
                                      : (((1U == (IData)(vlTOPp->SELECT_OPERATION_RD)) 
                                          & (IData)(vlTOPp->SLT_RD))
                                          ? (IData)(
                                                    ((1U 
                                                      & ((vlTOPp->exe__DOT__op1 
                                                          >> 0x1fU) 
                                                         & (~ 
                                                            (vlTOPp->exe__DOT__op2 
                                                             >> 0x1fU))))
                                                      ? 1ULL
                                                      : 
                                                     ((1U 
                                                       & ((~ 
                                                           (vlTOPp->exe__DOT__op1 
                                                            >> 0x1fU)) 
                                                          & (vlTOPp->exe__DOT__op2 
                                                             >> 0x1fU)))
                                                       ? 0ULL
                                                       : 
                                                      ((vlTOPp->exe__DOT__op1 
                                                        == vlTOPp->exe__DOT__op2)
                                                        ? 0ULL
                                                        : 
                                                       (((QData)((IData)(
                                                                         (1U 
                                                                          & (vlTOPp->exe__DOT__alu_res 
                                                                             >> 0x1fU)))) 
                                                         << 0x22U) 
                                                        | (QData)((IData)(
                                                                          (0x7fffffffU 
                                                                           & vlTOPp->exe__DOT__alu_res))))))))
                                          : (((1U == (IData)(vlTOPp->SELECT_OPERATION_RD)) 
                                              & (IData)(vlTOPp->SLTU_RD))
                                              ? ((1U 
                                                  & ((vlTOPp->exe__DOT__op1 
                                                      >> 0x1fU) 
                                                     & (~ 
                                                        (vlTOPp->exe__DOT__op2 
                                                         >> 0x1fU))))
                                                  ? 0U
                                                  : 
                                                 ((1U 
                                                   & ((~ 
                                                       (vlTOPp->exe__DOT__op1 
                                                        >> 0x1fU)) 
                                                      & (vlTOPp->exe__DOT__op2 
                                                         >> 0x1fU)))
                                                   ? 1U
                                                   : 
                                                  ((vlTOPp->exe__DOT__op1 
                                                    == vlTOPp->exe__DOT__op2)
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & (vlTOPp->exe__DOT__alu_res 
                                                       >> 0x1fU)))))
                                              : vlTOPp->exe__DOT__alu_res))));
    vlTOPp->exe__DOT__load_adress_misaligned_se = ((IData)(vlTOPp->MEM_LOAD_RD) 
                                                   & (IData)(vlTOPp->exe__DOT__adress_misaligned));
    vlTOPp->exe__DOT__store_adress_misaligned_se = 
        ((IData)(vlTOPp->MEM_STORE_RD) & (IData)(vlTOPp->exe__DOT__adress_misaligned));
    vlTOPp->exe__DOT__load_access_fault_se = ((IData)(vlTOPp->MEM_LOAD_RD) 
                                              & (IData)(vlTOPp->exe__DOT__access_fault));
    vlTOPp->exe__DOT__store_access_fault_se = ((IData)(vlTOPp->MEM_STORE_RD) 
                                               & (IData)(vlTOPp->exe__DOT__access_fault));
    vlTOPp->x0_multiplier__DOT__product_s1[1U] = (0xffffeU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__genblk1__BRA__0__KET____DOT__csa1__DOT__shf) 
                                                     << 1U));
    vlTOPp->x0_multiplier__DOT__product_s1[3U] = (0xffffeU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__genblk1__BRA__1__KET____DOT__csa1__DOT__shf) 
                                                     << 1U));
    vlTOPp->x0_multiplier__DOT__product_s1[5U] = (0xffffeU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__genblk1__BRA__2__KET____DOT__csa1__DOT__shf) 
                                                     << 1U));
    vlTOPp->x0_multiplier__DOT__product_s1[7U] = (0xffffeU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__genblk1__BRA__3__KET____DOT__csa1__DOT__shf) 
                                                     << 1U));
    vlTOPp->x0_multiplier__DOT__product_s1[9U] = (0xffffeU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__genblk1__BRA__4__KET____DOT__csa1__DOT__shf) 
                                                     << 1U));
    vlTOPp->x0_multiplier__DOT__product_s1[0xbU] = 
        (0xffffeU & ((IData)(vlTOPp->x0_multiplier__DOT__genblk1__BRA__5__KET____DOT__csa1__DOT__shf) 
                     << 1U));
    vlTOPp->x0_multiplier__DOT__product_s1[0xdU] = 
        (0xffffeU & ((IData)(vlTOPp->x0_multiplier__DOT__genblk1__BRA__6__KET____DOT__csa1__DOT__shf) 
                     << 1U));
    vlTOPp->x0_multiplier__DOT__product_s1[0xfU] = 
        (0xffffeU & ((IData)(vlTOPp->x0_multiplier__DOT__genblk1__BRA__7__KET____DOT__csa1__DOT__shf) 
                     << 1U));
    vlTOPp->x0_multiplier__DOT__product_s1[0x11U] = 
        (0xffffeU & ((IData)(vlTOPp->x0_multiplier__DOT__genblk1__BRA__8__KET____DOT__csa1__DOT__shf) 
                     << 1U));
    vlTOPp->x0_multiplier__DOT__product_s1[0x13U] = 
        (0xffffeU & ((IData)(vlTOPp->x0_multiplier__DOT__genblk1__BRA__9__KET____DOT__csa1__DOT__shf) 
                     << 1U));
    vlTOPp->exe__DOT__divider_i__DOT__shift_cpt_se 
        = ((IData)(vlTOPp->exe__DOT__divider_i__DOT__running)
            ? (0x3fU & ((IData)(1U) + (IData)(vlTOPp->exe__DOT__divider_i__DOT__shift_cpt_reg)))
            : 0U);
    vlTOPp->X0X1_EMPTY_SX0 = (1U & (~ (IData)(vlTOPp->x0_multiplier__DOT__x0x1__DOT__data_v)));
    vlTOPp->x0_multiplier__DOT__stall_sx0 = (1U & (
                                                   (((IData)(vlTOPp->x0_multiplier__DOT__x0x1__DOT__data_v) 
                                                     & (~ (IData)(vlTOPp->X0X1_POP_SX1)))
                                                     ? 1U
                                                     : 0U) 
                                                   | (IData)(vlTOPp->DEC2X0_EMPTY_SD)));
    vlTOPp->EXE2MEM_EMPTY_SE = (1U & (~ (IData)(vlTOPp->exe__DOT__exe2mem__DOT__data_v)));
    vlTOPp->exe__DOT__stall_se = (1U & ((((((((IData)(vlTOPp->exe__DOT__exe2mem__DOT__data_v) 
                                              & (~ (IData)(vlTOPp->EXE2MEM_POP_SM)))
                                              ? 1U : 0U) 
                                            | (IData)(vlTOPp->DEC2EXE_EMPTY_SD)) 
                                           | (((((0x3fU 
                                                  & vlTOPp->exe__DOT__exe2mem__DOT__data[2U]) 
                                                 == (IData)(vlTOPp->RADR1_RD)) 
                                                & (vlTOPp->exe__DOT__exe2mem__DOT__data[2U] 
                                                   >> 9U)) 
                                               | (((0x3fU 
                                                    & vlTOPp->exe__DOT__exe2mem__DOT__data[2U]) 
                                                   == (IData)(vlTOPp->RADR2_RD)) 
                                                  & (vlTOPp->exe__DOT__exe2mem__DOT__data[2U] 
                                                     >> 9U))) 
                                              & (IData)(vlTOPp->exe__DOT__exe2mem__DOT__data_v))) 
                                          | (~ (IData)(vlTOPp->exe__DOT__r1_valid_se))) 
                                         | (~ (IData)(vlTOPp->exe__DOT__r2_valid_se))) 
                                        | ((IData)(vlTOPp->exe__DOT__busy_div) 
                                           & (~ (IData)(vlTOPp->exe__DOT__done_div)))));
    vlTOPp->exe__DOT__divider_i__DOT__quotient_se = 
        ((IData)(vlTOPp->exe__DOT__divider_i__DOT__setup_regs)
          ? 0U : ((IData)(vlTOPp->exe__DOT__divider_i__DOT__same)
                   ? 1U : ((IData)(vlTOPp->exe__DOT__divider_i__DOT__zero_div)
                            ? 0xffffffffU : ((IData)(vlTOPp->exe__DOT__divider_i__DOT__running)
                                              ? ((0xfffffffeU 
                                                  & (vlTOPp->exe__DOT__divider_i__DOT__quotient_reg 
                                                     << 1U)) 
                                                 | (IData)(vlTOPp->exe__DOT__divider_i__DOT__division))
                                              : 0U))));
    vlTOPp->exe__DOT__divider_i__DOT__reminder_se = 
        (((IData)(vlTOPp->exe__DOT__divider_i__DOT__setup_regs) 
          | (IData)(vlTOPp->exe__DOT__divider_i__DOT__zero_div))
          ? (QData)((IData)(((((IData)(vlTOPp->exe__DOT__divider_i__DOT__setup_regs) 
                               & (IData)(vlTOPp->exe__DOT__divider_i__DOT__signed_inst)) 
                              & (vlTOPp->exe__DOT__divider_i__DOT__op1 
                                 >> 0x1fU)) ? ((IData)(1U) 
                                               + (~ vlTOPp->exe__DOT__divider_i__DOT__op1))
                              : vlTOPp->exe__DOT__divider_i__DOT__op1)))
          : (((IData)(vlTOPp->exe__DOT__divider_i__DOT__running) 
              & (IData)(vlTOPp->exe__DOT__divider_i__DOT__division))
              ? (vlTOPp->exe__DOT__divider_i__DOT__reminder_reg 
                 - vlTOPp->exe__DOT__divider_i__DOT__divisor_reg)
              : 0ULL));
    vlTOPp->exe__DOT__exe2mem_data[0U] = vlTOPp->exe__DOT__exe_res;
    vlTOPp->exe__DOT__exe2mem_data[5U] = ((0xfffffffeU 
                                           & vlTOPp->exe__DOT__exe2mem_data[5U]) 
                                          | (IData)(vlTOPp->exe__DOT__load_adress_misaligned_se));
    vlTOPp->exe__DOT__exe2mem_data[5U] = ((0xfffffff7U 
                                           & vlTOPp->exe__DOT__exe2mem_data[5U]) 
                                          | (0xfffffff8U 
                                             & ((IData)(vlTOPp->exe__DOT__store_adress_misaligned_se) 
                                                << 3U)));
    vlTOPp->exe__DOT__exe2mem_data[5U] = ((0xfffffffdU 
                                           & vlTOPp->exe__DOT__exe2mem_data[5U]) 
                                          | (0xfffffffeU 
                                             & ((IData)(vlTOPp->exe__DOT__load_access_fault_se) 
                                                << 1U)));
    vlTOPp->exe__DOT__exe2mem_data[5U] = ((0xffffffefU 
                                           & vlTOPp->exe__DOT__exe2mem_data[5U]) 
                                          | (0xfffffff0U 
                                             & ((IData)(vlTOPp->exe__DOT__store_access_fault_se) 
                                                << 4U)));
    vlTOPp->exe__DOT__exception_se = ((((((IData)(vlTOPp->EXCEPTION_RD) 
                                          | (IData)(vlTOPp->exe__DOT__load_adress_misaligned_se)) 
                                         | (IData)(vlTOPp->exe__DOT__load_access_fault_se)) 
                                        | (IData)(vlTOPp->exe__DOT__store_access_fault_se)) 
                                       | (IData)(vlTOPp->exe__DOT__store_adress_misaligned_se)) 
                                      & (IData)(vlTOPp->exe__02Ereset_n));
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__0__KET____DOT__csa2__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s1
                           [0U])) ^ (QData)((IData)(
                                                    vlTOPp->x0_multiplier__DOT__product_s1
                                                    [1U])));
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__1__KET____DOT__csa2__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s1
                           [3U])) ^ (QData)((IData)(
                                                    vlTOPp->x0_multiplier__DOT__product_s1
                                                    [4U])));
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__2__KET____DOT__csa2__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s1
                           [6U])) ^ (QData)((IData)(
                                                    vlTOPp->x0_multiplier__DOT__product_s1
                                                    [7U])));
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__3__KET____DOT__csa2__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s1
                           [9U])) ^ (QData)((IData)(
                                                    vlTOPp->x0_multiplier__DOT__product_s1
                                                    [0xaU])));
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__4__KET____DOT__csa2__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s1
                           [0xcU])) ^ (QData)((IData)(
                                                      vlTOPp->x0_multiplier__DOT__product_s1
                                                      [0xdU])));
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__5__KET____DOT__csa2__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s1
                           [0xfU])) ^ (QData)((IData)(
                                                      vlTOPp->x0_multiplier__DOT__product_s1
                                                      [0x10U])));
    vlTOPp->x0_multiplier__DOT__csa2_6__DOT__AxB = 
        ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s1
                         [0x12U])) ^ (QData)((IData)(
                                                     vlTOPp->x0_multiplier__DOT__product_s1
                                                     [0x13U])));
    vlTOPp->DEC2EXE_POP_SE = (1U & (~ ((IData)(vlTOPp->exe__DOT__stall_se) 
                                       | (IData)(vlTOPp->exe__DOT__start_div))));
    vlTOPp->exe__DOT__exe2mem_data[4U] = ((0x7fffffffU 
                                           & vlTOPp->exe__DOT__exe2mem_data[4U]) 
                                          | (0x80000000U 
                                             & ((IData)(vlTOPp->exe__DOT__exception_se) 
                                                << 0x1fU)));
    vlTOPp->exe__DOT__exe2mem_data[2U] = ((0xfffffeffU 
                                           & vlTOPp->exe__DOT__exe2mem_data[2U]) 
                                          | (0xffffff00U 
                                             & (((~ (IData)(vlTOPp->exe__DOT__exception_se)) 
                                                 & (IData)(vlTOPp->WB_RD)) 
                                                << 8U)));
    vlTOPp->exe__DOT__exe2mem_data[2U] = ((0xfffffdffU 
                                           & vlTOPp->exe__DOT__exe2mem_data[2U]) 
                                          | (0xfffffe00U 
                                             & (((~ (IData)(vlTOPp->exe__DOT__exception_se)) 
                                                 & (IData)(vlTOPp->MEM_LOAD_RD)) 
                                                << 9U)));
    vlTOPp->exe__DOT__exe2mem_data[2U] = ((0xfffffbffU 
                                           & vlTOPp->exe__DOT__exe2mem_data[2U]) 
                                          | (0xfffffc00U 
                                             & (((~ (IData)(vlTOPp->exe__DOT__exception_se)) 
                                                 & (IData)(vlTOPp->MEM_STORE_RD)) 
                                                << 0xaU)));
    vlTOPp->x0_multiplier__DOT__product_s2[0U] = (0x3fffU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__genblk2__BRA__0__KET____DOT__csa2__DOT__AxB) 
                                                     ^ (IData)((QData)((IData)(
                                                                               vlTOPp->x0_multiplier__DOT__product_s1
                                                                               [2U])))));
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__0__KET____DOT__csa2__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s1
                            [0U])) & (QData)((IData)(
                                                     vlTOPp->x0_multiplier__DOT__product_s1
                                                     [1U]))) 
           | (vlTOPp->x0_multiplier__DOT__genblk2__BRA__0__KET____DOT__csa2__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s1
                                [2U]))));
    vlTOPp->x0_multiplier__DOT__product_s2[2U] = (0x3fffU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__genblk2__BRA__1__KET____DOT__csa2__DOT__AxB) 
                                                     ^ (IData)((QData)((IData)(
                                                                               vlTOPp->x0_multiplier__DOT__product_s1
                                                                               [5U])))));
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__1__KET____DOT__csa2__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s1
                            [3U])) & (QData)((IData)(
                                                     vlTOPp->x0_multiplier__DOT__product_s1
                                                     [4U]))) 
           | (vlTOPp->x0_multiplier__DOT__genblk2__BRA__1__KET____DOT__csa2__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s1
                                [5U]))));
    vlTOPp->x0_multiplier__DOT__product_s2[4U] = (0x3fffU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__genblk2__BRA__2__KET____DOT__csa2__DOT__AxB) 
                                                     ^ (IData)((QData)((IData)(
                                                                               vlTOPp->x0_multiplier__DOT__product_s1
                                                                               [8U])))));
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__2__KET____DOT__csa2__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s1
                            [6U])) & (QData)((IData)(
                                                     vlTOPp->x0_multiplier__DOT__product_s1
                                                     [7U]))) 
           | (vlTOPp->x0_multiplier__DOT__genblk2__BRA__2__KET____DOT__csa2__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s1
                                [8U]))));
    vlTOPp->x0_multiplier__DOT__product_s2[6U] = (0x3fffU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__genblk2__BRA__3__KET____DOT__csa2__DOT__AxB) 
                                                     ^ (IData)((QData)((IData)(
                                                                               vlTOPp->x0_multiplier__DOT__product_s1
                                                                               [0xbU])))));
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__3__KET____DOT__csa2__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s1
                            [9U])) & (QData)((IData)(
                                                     vlTOPp->x0_multiplier__DOT__product_s1
                                                     [0xaU]))) 
           | (vlTOPp->x0_multiplier__DOT__genblk2__BRA__3__KET____DOT__csa2__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s1
                                [0xbU]))));
    vlTOPp->x0_multiplier__DOT__product_s2[8U] = (0x3fffU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__genblk2__BRA__4__KET____DOT__csa2__DOT__AxB) 
                                                     ^ (IData)((QData)((IData)(
                                                                               vlTOPp->x0_multiplier__DOT__product_s1
                                                                               [0xeU])))));
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__4__KET____DOT__csa2__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s1
                            [0xcU])) & (QData)((IData)(
                                                       vlTOPp->x0_multiplier__DOT__product_s1
                                                       [0xdU]))) 
           | (vlTOPp->x0_multiplier__DOT__genblk2__BRA__4__KET____DOT__csa2__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s1
                                [0xeU]))));
    vlTOPp->x0_multiplier__DOT__product_s2[0xaU] = 
        (0x3fffU & ((IData)(vlTOPp->x0_multiplier__DOT__genblk2__BRA__5__KET____DOT__csa2__DOT__AxB) 
                    ^ (IData)((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s1
                                              [0x11U])))));
    vlTOPp->x0_multiplier__DOT__genblk2__BRA__5__KET____DOT__csa2__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s1
                            [0xfU])) & (QData)((IData)(
                                                       vlTOPp->x0_multiplier__DOT__product_s1
                                                       [0x10U]))) 
           | (vlTOPp->x0_multiplier__DOT__genblk2__BRA__5__KET____DOT__csa2__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s1
                                [0x11U]))));
    vlTOPp->x0_multiplier__DOT__product_s2[0xcU] = 
        (0x3fffU & ((IData)(vlTOPp->x0_multiplier__DOT__csa2_6__DOT__AxB) 
                    ^ (IData)((QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                                              [0x1eU])))));
    vlTOPp->x0_multiplier__DOT__csa2_6__DOT__shf = 
        (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s1
                          [0x12U])) & (QData)((IData)(
                                                      vlTOPp->x0_multiplier__DOT__product_s1
                                                      [0x13U]))) 
         | (vlTOPp->x0_multiplier__DOT__csa2_6__DOT__AxB 
            & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                              [0x1eU]))));
    if (vlTOPp->EXCEPTION_SM) {
        vlTOPp->exe__DOT__exe2mem_din[0U] = vlTOPp->exe__DOT__exe2mem_x[0U];
        vlTOPp->exe__DOT__exe2mem_din[1U] = vlTOPp->exe__DOT__exe2mem_x[1U];
        vlTOPp->exe__DOT__exe2mem_din[2U] = vlTOPp->exe__DOT__exe2mem_x[2U];
        vlTOPp->exe__DOT__exe2mem_din[3U] = vlTOPp->exe__DOT__exe2mem_x[3U];
        vlTOPp->exe__DOT__exe2mem_din[4U] = vlTOPp->exe__DOT__exe2mem_x[4U];
        vlTOPp->exe__DOT__exe2mem_din[5U] = vlTOPp->exe__DOT__exe2mem_x[5U];
        vlTOPp->exe__DOT__exe2mem_din[6U] = vlTOPp->exe__DOT__exe2mem_x[6U];
    } else {
        vlTOPp->exe__DOT__exe2mem_din[0U] = vlTOPp->exe__DOT__exe2mem_data[0U];
        vlTOPp->exe__DOT__exe2mem_din[1U] = vlTOPp->exe__DOT__exe2mem_data[1U];
        vlTOPp->exe__DOT__exe2mem_din[2U] = vlTOPp->exe__DOT__exe2mem_data[2U];
        vlTOPp->exe__DOT__exe2mem_din[3U] = vlTOPp->exe__DOT__exe2mem_data[3U];
        vlTOPp->exe__DOT__exe2mem_din[4U] = vlTOPp->exe__DOT__exe2mem_data[4U];
        vlTOPp->exe__DOT__exe2mem_din[5U] = vlTOPp->exe__DOT__exe2mem_data[5U];
        vlTOPp->exe__DOT__exe2mem_din[6U] = vlTOPp->exe__DOT__exe2mem_data[6U];
    }
    vlTOPp->x0_multiplier__DOT__product_s2[1U] = (0x3ffeU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__genblk2__BRA__0__KET____DOT__csa2__DOT__shf) 
                                                     << 1U));
    vlTOPp->x0_multiplier__DOT__product_s2[3U] = (0x3ffeU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__genblk2__BRA__1__KET____DOT__csa2__DOT__shf) 
                                                     << 1U));
    vlTOPp->x0_multiplier__DOT__product_s2[5U] = (0x3ffeU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__genblk2__BRA__2__KET____DOT__csa2__DOT__shf) 
                                                     << 1U));
    vlTOPp->x0_multiplier__DOT__product_s2[7U] = (0x3ffeU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__genblk2__BRA__3__KET____DOT__csa2__DOT__shf) 
                                                     << 1U));
    vlTOPp->x0_multiplier__DOT__product_s2[9U] = (0x3ffeU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__genblk2__BRA__4__KET____DOT__csa2__DOT__shf) 
                                                     << 1U));
    vlTOPp->x0_multiplier__DOT__product_s2[0xbU] = 
        (0x3ffeU & ((IData)(vlTOPp->x0_multiplier__DOT__genblk2__BRA__5__KET____DOT__csa2__DOT__shf) 
                    << 1U));
    vlTOPp->x0_multiplier__DOT__product_s2[0xdU] = 
        (0x3ffeU & ((IData)(vlTOPp->x0_multiplier__DOT__csa2_6__DOT__shf) 
                    << 1U));
    vlTOPp->x0_multiplier__DOT__csa_instance__BRA__0__KET____DOT__csa3__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s2
                           [0U])) ^ (QData)((IData)(
                                                    vlTOPp->x0_multiplier__DOT__product_s2
                                                    [1U])));
    vlTOPp->x0_multiplier__DOT__csa_instance__BRA__1__KET____DOT__csa3__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s2
                           [3U])) ^ (QData)((IData)(
                                                    vlTOPp->x0_multiplier__DOT__product_s2
                                                    [4U])));
    vlTOPp->x0_multiplier__DOT__csa_instance__BRA__2__KET____DOT__csa3__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s2
                           [6U])) ^ (QData)((IData)(
                                                    vlTOPp->x0_multiplier__DOT__product_s2
                                                    [7U])));
    vlTOPp->x0_multiplier__DOT__csa_instance__BRA__3__KET____DOT__csa3__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s2
                           [9U])) ^ (QData)((IData)(
                                                    vlTOPp->x0_multiplier__DOT__product_s2
                                                    [0xaU])));
    vlTOPp->x0_multiplier__DOT__csa3_4__DOT__AxB = 
        ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s2
                         [0xcU])) ^ (QData)((IData)(
                                                    vlTOPp->x0_multiplier__DOT__product_s2
                                                    [0xdU])));
    vlTOPp->x0_multiplier__DOT__product_s3[0U] = (0x3ffU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__csa_instance__BRA__0__KET____DOT__csa3__DOT__AxB) 
                                                     ^ (IData)((QData)((IData)(
                                                                               vlTOPp->x0_multiplier__DOT__product_s2
                                                                               [2U])))));
    vlTOPp->x0_multiplier__DOT__csa_instance__BRA__0__KET____DOT__csa3__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s2
                            [0U])) & (QData)((IData)(
                                                     vlTOPp->x0_multiplier__DOT__product_s2
                                                     [1U]))) 
           | (vlTOPp->x0_multiplier__DOT__csa_instance__BRA__0__KET____DOT__csa3__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s2
                                [2U]))));
    vlTOPp->x0_multiplier__DOT__product_s3[2U] = (0x3ffU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__csa_instance__BRA__1__KET____DOT__csa3__DOT__AxB) 
                                                     ^ (IData)((QData)((IData)(
                                                                               vlTOPp->x0_multiplier__DOT__product_s2
                                                                               [5U])))));
    vlTOPp->x0_multiplier__DOT__csa_instance__BRA__1__KET____DOT__csa3__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s2
                            [3U])) & (QData)((IData)(
                                                     vlTOPp->x0_multiplier__DOT__product_s2
                                                     [4U]))) 
           | (vlTOPp->x0_multiplier__DOT__csa_instance__BRA__1__KET____DOT__csa3__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s2
                                [5U]))));
    vlTOPp->x0_multiplier__DOT__product_s3[4U] = (0x3ffU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__csa_instance__BRA__2__KET____DOT__csa3__DOT__AxB) 
                                                     ^ (IData)((QData)((IData)(
                                                                               vlTOPp->x0_multiplier__DOT__product_s2
                                                                               [8U])))));
    vlTOPp->x0_multiplier__DOT__csa_instance__BRA__2__KET____DOT__csa3__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s2
                            [6U])) & (QData)((IData)(
                                                     vlTOPp->x0_multiplier__DOT__product_s2
                                                     [7U]))) 
           | (vlTOPp->x0_multiplier__DOT__csa_instance__BRA__2__KET____DOT__csa3__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s2
                                [8U]))));
    vlTOPp->x0_multiplier__DOT__product_s3[6U] = (0x3ffU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__csa_instance__BRA__3__KET____DOT__csa3__DOT__AxB) 
                                                     ^ (IData)((QData)((IData)(
                                                                               vlTOPp->x0_multiplier__DOT__product_s2
                                                                               [0xbU])))));
    vlTOPp->x0_multiplier__DOT__csa_instance__BRA__3__KET____DOT__csa3__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s2
                            [9U])) & (QData)((IData)(
                                                     vlTOPp->x0_multiplier__DOT__product_s2
                                                     [0xaU]))) 
           | (vlTOPp->x0_multiplier__DOT__csa_instance__BRA__3__KET____DOT__csa3__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s2
                                [0xbU]))));
    vlTOPp->x0_multiplier__DOT__product_s3[8U] = (0x3ffU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__csa3_4__DOT__AxB) 
                                                     ^ (IData)((QData)((IData)(
                                                                               vlTOPp->x0_multiplier__DOT__product
                                                                               [0x1fU])))));
    vlTOPp->x0_multiplier__DOT__csa3_4__DOT__shf = 
        (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s2
                          [0xcU])) & (QData)((IData)(
                                                     vlTOPp->x0_multiplier__DOT__product_s2
                                                     [0xdU]))) 
         | (vlTOPp->x0_multiplier__DOT__csa3_4__DOT__AxB 
            & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product
                              [0x1fU]))));
    vlTOPp->x0_multiplier__DOT__product_s3[1U] = (0x3feU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__csa_instance__BRA__0__KET____DOT__csa3__DOT__shf) 
                                                     << 1U));
    vlTOPp->x0_multiplier__DOT__product_s3[3U] = (0x3feU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__csa_instance__BRA__1__KET____DOT__csa3__DOT__shf) 
                                                     << 1U));
    vlTOPp->x0_multiplier__DOT__product_s3[5U] = (0x3feU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__csa_instance__BRA__2__KET____DOT__csa3__DOT__shf) 
                                                     << 1U));
    vlTOPp->x0_multiplier__DOT__product_s3[7U] = (0x3feU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__csa_instance__BRA__3__KET____DOT__csa3__DOT__shf) 
                                                     << 1U));
    vlTOPp->x0_multiplier__DOT__product_s3[9U] = (0x3feU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__csa3_4__DOT__shf) 
                                                     << 1U));
    vlTOPp->x0_multiplier__DOT__stage4__BRA__0__KET____DOT__csa4__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s3
                           [0U])) ^ (QData)((IData)(
                                                    vlTOPp->x0_multiplier__DOT__product_s3
                                                    [1U])));
    vlTOPp->x0_multiplier__DOT__stage4__BRA__1__KET____DOT__csa4__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s3
                           [3U])) ^ (QData)((IData)(
                                                    vlTOPp->x0_multiplier__DOT__product_s3
                                                    [4U])));
    vlTOPp->x0_multiplier__DOT__stage4__BRA__2__KET____DOT__csa4__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s3
                           [6U])) ^ (QData)((IData)(
                                                    vlTOPp->x0_multiplier__DOT__product_s3
                                                    [7U])));
    vlTOPp->x0_multiplier__DOT__product_s4[0U] = (0x3fU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__stage4__BRA__0__KET____DOT__csa4__DOT__AxB) 
                                                     ^ (IData)((QData)((IData)(
                                                                               vlTOPp->x0_multiplier__DOT__product_s3
                                                                               [2U])))));
    vlTOPp->x0_multiplier__DOT__stage4__BRA__0__KET____DOT__csa4__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s3
                            [0U])) & (QData)((IData)(
                                                     vlTOPp->x0_multiplier__DOT__product_s3
                                                     [1U]))) 
           | (vlTOPp->x0_multiplier__DOT__stage4__BRA__0__KET____DOT__csa4__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s3
                                [2U]))));
    vlTOPp->x0_multiplier__DOT__product_s4[2U] = (0x3fU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__stage4__BRA__1__KET____DOT__csa4__DOT__AxB) 
                                                     ^ (IData)((QData)((IData)(
                                                                               vlTOPp->x0_multiplier__DOT__product_s3
                                                                               [5U])))));
    vlTOPp->x0_multiplier__DOT__stage4__BRA__1__KET____DOT__csa4__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s3
                            [3U])) & (QData)((IData)(
                                                     vlTOPp->x0_multiplier__DOT__product_s3
                                                     [4U]))) 
           | (vlTOPp->x0_multiplier__DOT__stage4__BRA__1__KET____DOT__csa4__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s3
                                [5U]))));
    vlTOPp->x0_multiplier__DOT__product_s4[4U] = (0x3fU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__stage4__BRA__2__KET____DOT__csa4__DOT__AxB) 
                                                     ^ (IData)((QData)((IData)(
                                                                               vlTOPp->x0_multiplier__DOT__product_s3
                                                                               [8U])))));
    vlTOPp->x0_multiplier__DOT__stage4__BRA__2__KET____DOT__csa4__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s3
                            [6U])) & (QData)((IData)(
                                                     vlTOPp->x0_multiplier__DOT__product_s3
                                                     [7U]))) 
           | (vlTOPp->x0_multiplier__DOT__stage4__BRA__2__KET____DOT__csa4__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s3
                                [8U]))));
    vlTOPp->x0_multiplier__DOT__product_s4[1U] = (0x3eU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__stage4__BRA__0__KET____DOT__csa4__DOT__shf) 
                                                     << 1U));
    vlTOPp->x0_multiplier__DOT__product_s4[3U] = (0x3eU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__stage4__BRA__1__KET____DOT__csa4__DOT__shf) 
                                                     << 1U));
    vlTOPp->x0_multiplier__DOT__product_s4[5U] = (0x3eU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__stage4__BRA__2__KET____DOT__csa4__DOT__shf) 
                                                     << 1U));
    vlTOPp->x0_multiplier__DOT__stage5__BRA__0__KET____DOT__csa5__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s4
                           [0U])) ^ (QData)((IData)(
                                                    vlTOPp->x0_multiplier__DOT__product_s4
                                                    [1U])));
    vlTOPp->x0_multiplier__DOT__stage5__BRA__1__KET____DOT__csa5__DOT__AxB 
        = ((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s4
                           [3U])) ^ (QData)((IData)(
                                                    vlTOPp->x0_multiplier__DOT__product_s4
                                                    [4U])));
    vlTOPp->x0_multiplier__DOT__product_s5[0U] = (0xfU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__stage5__BRA__0__KET____DOT__csa5__DOT__AxB) 
                                                     ^ (IData)((QData)((IData)(
                                                                               vlTOPp->x0_multiplier__DOT__product_s4
                                                                               [2U])))));
    vlTOPp->x0_multiplier__DOT__stage5__BRA__0__KET____DOT__csa5__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s4
                            [0U])) & (QData)((IData)(
                                                     vlTOPp->x0_multiplier__DOT__product_s4
                                                     [1U]))) 
           | (vlTOPp->x0_multiplier__DOT__stage5__BRA__0__KET____DOT__csa5__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s4
                                [2U]))));
    vlTOPp->x0_multiplier__DOT__product_s5[2U] = (0xfU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__stage5__BRA__1__KET____DOT__csa5__DOT__AxB) 
                                                     ^ (IData)((QData)((IData)(
                                                                               vlTOPp->x0_multiplier__DOT__product_s4
                                                                               [5U])))));
    vlTOPp->x0_multiplier__DOT__stage5__BRA__1__KET____DOT__csa5__DOT__shf 
        = (((QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s4
                            [3U])) & (QData)((IData)(
                                                     vlTOPp->x0_multiplier__DOT__product_s4
                                                     [4U]))) 
           | (vlTOPp->x0_multiplier__DOT__stage5__BRA__1__KET____DOT__csa5__DOT__AxB 
              & (QData)((IData)(vlTOPp->x0_multiplier__DOT__product_s4
                                [5U]))));
    vlTOPp->x0_multiplier__DOT__product_s5[1U] = (0xeU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__stage5__BRA__0__KET____DOT__csa5__DOT__shf) 
                                                     << 1U));
    vlTOPp->x0_multiplier__DOT__product_s5[3U] = (0xeU 
                                                  & ((IData)(vlTOPp->x0_multiplier__DOT__stage5__BRA__1__KET____DOT__csa5__DOT__shf) 
                                                     << 1U));
    vlTOPp->x0_multiplier__DOT__x0x1_din[0U] = (IData)((QData)((IData)(
                                                                       vlTOPp->x0_multiplier__DOT__product_s5
                                                                       [0U])));
    vlTOPp->x0_multiplier__DOT__x0x1_din[1U] = (IData)(
                                                       ((QData)((IData)(
                                                                        vlTOPp->x0_multiplier__DOT__product_s5
                                                                        [0U])) 
                                                        >> 0x20U));
    vlTOPp->x0_multiplier__DOT__x0x1_din[2U] = (IData)((QData)((IData)(
                                                                       vlTOPp->x0_multiplier__DOT__product_s5
                                                                       [1U])));
    vlTOPp->x0_multiplier__DOT__x0x1_din[3U] = (IData)(
                                                       ((QData)((IData)(
                                                                        vlTOPp->x0_multiplier__DOT__product_s5
                                                                        [1U])) 
                                                        >> 0x20U));
    vlTOPp->x0_multiplier__DOT__x0x1_din[4U] = (IData)((QData)((IData)(
                                                                       vlTOPp->x0_multiplier__DOT__product_s5
                                                                       [2U])));
    vlTOPp->x0_multiplier__DOT__x0x1_din[5U] = (IData)(
                                                       ((QData)((IData)(
                                                                        vlTOPp->x0_multiplier__DOT__product_s5
                                                                        [2U])) 
                                                        >> 0x20U));
    vlTOPp->x0_multiplier__DOT__x0x1_din[6U] = (IData)((QData)((IData)(
                                                                       vlTOPp->x0_multiplier__DOT__product_s5
                                                                       [3U])));
    vlTOPp->x0_multiplier__DOT__x0x1_din[7U] = (IData)(
                                                       ((QData)((IData)(
                                                                        vlTOPp->x0_multiplier__DOT__product_s5
                                                                        [3U])) 
                                                        >> 0x20U));
    vlTOPp->x0_multiplier__DOT__x0x1_din[8U] = (IData)((QData)((IData)(
                                                                       vlTOPp->x0_multiplier__DOT__product_s3
                                                                       [9U])));
    vlTOPp->x0_multiplier__DOT__x0x1_din[9U] = (IData)(
                                                       ((QData)((IData)(
                                                                        vlTOPp->x0_multiplier__DOT__product_s3
                                                                        [9U])) 
                                                        >> 0x20U));
    vlTOPp->x0_multiplier__DOT__x0x1_din[0xaU] = ((0xfffffffeU 
                                                   & ((1U 
                                                       != (IData)(vlTOPp->MULT_CMD_RD)) 
                                                      << 1U)) 
                                                  | (1U 
                                                     & (~ 
                                                        ((vlTOPp->x0_multiplier__02EOP1_SE 
                                                          & vlTOPp->x0_multiplier__02EOP2_SE) 
                                                         >> 0x1fU))));
}

void Vexe::_eval_initial(Vexe__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexe::_eval_initial\n"); );
    Vexe* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__2(vlSymsp);
    vlTOPp->__Vclklast__TOP__exe__02Eclk = vlTOPp->exe__02Eclk;
    vlTOPp->__Vclklast__TOP__x0_multiplier__02Eclk 
        = vlTOPp->x0_multiplier__02Eclk;
    vlTOPp->__Vclklast__TOP__exe__02Ereset_n = vlTOPp->exe__02Ereset_n;
}

void Vexe::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexe::final\n"); );
    // Variables
    Vexe__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vexe* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vexe::_eval_settle(Vexe__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexe::_eval_settle\n"); );
    Vexe* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__1(vlSymsp);
    vlTOPp->_settle__TOP__8(vlSymsp);
}

void Vexe::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexe::_ctor_var_reset\n"); );
    // Body
    exe__02Eclk = VL_RAND_RESET_I(1);
    exe__02Ereset_n = VL_RAND_RESET_I(1);
    OP1_RD = VL_RAND_RESET_I(32);
    OP2_RD = VL_RAND_RESET_I(32);
    RADR1_RD = VL_RAND_RESET_I(6);
    RADR2_RD = VL_RAND_RESET_I(6);
    MEM_DATA_RD = VL_RAND_RESET_I(32);
    DEST_RD = VL_RAND_RESET_I(6);
    CMD_RD = VL_RAND_RESET_I(2);
    MEM_SIZE_RD = VL_RAND_RESET_I(2);
    NEG_OP2_RD = VL_RAND_RESET_I(1);
    WB_RD = VL_RAND_RESET_I(1);
    MEM_SIGN_EXTEND_RD = VL_RAND_RESET_I(1);
    SELECT_OPERATION_RD = VL_RAND_RESET_I(4);
    MEM_LOAD_RD = VL_RAND_RESET_I(1);
    MEM_STORE_RD = VL_RAND_RESET_I(1);
    EXE2MEM_POP_SM = VL_RAND_RESET_I(1);
    DEC2EXE_EMPTY_SD = VL_RAND_RESET_I(1);
    SLT_RD = VL_RAND_RESET_I(1);
    SLTU_RD = VL_RAND_RESET_I(1);
    RES_RE = VL_RAND_RESET_I(32);
    MEM_DATA_RE = VL_RAND_RESET_I(32);
    DEST_RE = VL_RAND_RESET_I(6);
    MEM_SIZE_RE = VL_RAND_RESET_I(2);
    WB_RE = VL_RAND_RESET_I(1);
    MEM_SIGN_EXTEND_RE = VL_RAND_RESET_I(1);
    MEM_LOAD_RE = VL_RAND_RESET_I(1);
    MEM_STORE_RE = VL_RAND_RESET_I(1);
    EXE2MEM_EMPTY_SE = VL_RAND_RESET_I(1);
    DEC2EXE_POP_SE = VL_RAND_RESET_I(1);
    PC_DEC2EXE_RD = VL_RAND_RESET_I(32);
    PC_EXE2MEM_RE = VL_RAND_RESET_I(32);
    BLOCK_BP_RD = VL_RAND_RESET_I(1);
    MEM_DEST_RM = VL_RAND_RESET_I(6);
    MEM_RES_RM = VL_RAND_RESET_I(32);
    CSR_WENABLE_RM = VL_RAND_RESET_I(1);
    CSR_RDATA_RM = VL_RAND_RESET_I(32);
    BP_MEM2WBK_EMPTY_SM = VL_RAND_RESET_I(1);
    CSR_WENABLE_RD = VL_RAND_RESET_I(1);
    CSR_WADR_RD = VL_RAND_RESET_I(12);
    CSR_RDATA_RD = VL_RAND_RESET_I(32);
    MULT_INST_RM = VL_RAND_RESET_I(1);
    MULT_INST_RD = VL_RAND_RESET_I(1);
    MULT_INST_RE = VL_RAND_RESET_I(1);
    exe__02EOP1_SE = VL_RAND_RESET_I(32);
    exe__02EOP2_SE = VL_RAND_RESET_I(32);
    EXCEPTION_SM = VL_RAND_RESET_I(1);
    EXCEPTION_RD = VL_RAND_RESET_I(1);
    CURRENT_MODE_SM = VL_RAND_RESET_I(2);
    PC_BRANCH_VALUE_RD = VL_RAND_RESET_I(32);
    PC_BRANCH_VALUE_RE = VL_RAND_RESET_I(32);
    ILLEGAL_INSTRUCTION_RD = VL_RAND_RESET_I(1);
    ADRESS_MISALIGNED_RD = VL_RAND_RESET_I(1);
    INSTRUCTION_ACCESS_FAULT_RD = VL_RAND_RESET_I(1);
    ENV_CALL_U_MODE_RD = VL_RAND_RESET_I(1);
    ENV_CALL_S_MODE_RD = VL_RAND_RESET_I(1);
    ENV_CALL_M_MODE_RD = VL_RAND_RESET_I(1);
    ENV_CALL_WRONG_MODE_RD = VL_RAND_RESET_I(1);
    MRET_RD = VL_RAND_RESET_I(1);
    EBREAK_RD = VL_RAND_RESET_I(1);
    EXCEPTION_RE = VL_RAND_RESET_I(1);
    ILLEGAL_INSTRUCTION_RE = VL_RAND_RESET_I(1);
    ADRESS_MISALIGNED_RE = VL_RAND_RESET_I(1);
    INSTRUCTION_ACCESS_FAULT_RE = VL_RAND_RESET_I(1);
    ENV_CALL_U_MODE_RE = VL_RAND_RESET_I(1);
    ENV_CALL_S_MODE_RE = VL_RAND_RESET_I(1);
    ENV_CALL_M_MODE_RE = VL_RAND_RESET_I(1);
    ENV_CALL_WRONG_MODE_RE = VL_RAND_RESET_I(1);
    LOAD_ADRESS_MISALIGNED_RE = VL_RAND_RESET_I(1);
    LOAD_ACCESS_FAULT_RE = VL_RAND_RESET_I(1);
    STORE_ADRESS_MISALIGNED_RE = VL_RAND_RESET_I(1);
    STORE_ACCESS_FAULT_RE = VL_RAND_RESET_I(1);
    MRET_RE = VL_RAND_RESET_I(1);
    EBREAK_RE = VL_RAND_RESET_I(1);
    CSR_WENABLE_RE = VL_RAND_RESET_I(1);
    CSR_WADR_RE = VL_RAND_RESET_I(12);
    CSR_RDATA_RE = VL_RAND_RESET_I(32);
    x0_multiplier__02Eclk = VL_RAND_RESET_I(1);
    x0_multiplier__02Ereset_n = VL_RAND_RESET_I(1);
    x0_multiplier__02EOP1_SE = VL_RAND_RESET_I(32);
    x0_multiplier__02EOP2_SE = VL_RAND_RESET_I(32);
    MULT_CMD_RD = VL_RAND_RESET_I(2);
    X0X1_POP_SX1 = VL_RAND_RESET_I(1);
    DEC2X0_EMPTY_SD = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(320, RES_RX0);
    SELECT_MSB_RX0 = VL_RAND_RESET_I(1);
    SIGNED_RES_RX0 = VL_RAND_RESET_I(1);
    X0X1_EMPTY_SX0 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(200, exe__DOT__exe2mem_data);
    VL_RAND_RESET_W(200, exe__DOT__exe2mem_x);
    VL_RAND_RESET_W(200, exe__DOT__exe2mem_din);
    exe__DOT__op1 = VL_RAND_RESET_I(32);
    exe__DOT__op2 = VL_RAND_RESET_I(32);
    exe__DOT__alu_op2 = VL_RAND_RESET_I(32);
    exe__DOT__alu_res = VL_RAND_RESET_I(32);
    exe__DOT__exe_res = VL_RAND_RESET_I(32);
    exe__DOT__stall_se = VL_RAND_RESET_I(1);
    exe__DOT__r1_valid_se = VL_RAND_RESET_I(1);
    exe__DOT__r2_valid_se = VL_RAND_RESET_I(1);
    exe__DOT__bpc_disable2 = VL_RAND_RESET_I(1);
    exe__DOT__adress_misaligned = VL_RAND_RESET_I(1);
    exe__DOT__load_adress_misaligned_se = VL_RAND_RESET_I(1);
    exe__DOT__store_adress_misaligned_se = VL_RAND_RESET_I(1);
    exe__DOT__access_fault = VL_RAND_RESET_I(1);
    exe__DOT__load_access_fault_se = VL_RAND_RESET_I(1);
    exe__DOT__store_access_fault_se = VL_RAND_RESET_I(1);
    exe__DOT__exception_se = VL_RAND_RESET_I(1);
    exe__DOT__start_div = VL_RAND_RESET_I(1);
    exe__DOT__done_div = VL_RAND_RESET_I(1);
    exe__DOT__busy_div = VL_RAND_RESET_I(1);
    exe__DOT__shifter_i__DOT__lshift16 = VL_RAND_RESET_I(32);
    exe__DOT__shifter_i__DOT__lshift8 = VL_RAND_RESET_I(32);
    exe__DOT__shifter_i__DOT__lshift4 = VL_RAND_RESET_I(32);
    exe__DOT__shifter_i__DOT__lshift2 = VL_RAND_RESET_I(32);
    exe__DOT__shifter_i__DOT__rshift16 = VL_RAND_RESET_I(32);
    exe__DOT__shifter_i__DOT__rshift8 = VL_RAND_RESET_I(32);
    exe__DOT__shifter_i__DOT__rshift4 = VL_RAND_RESET_I(32);
    exe__DOT__shifter_i__DOT__rshift2 = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(200, exe__DOT__exe2mem__DOT__data);
    exe__DOT__exe2mem__DOT__data_v = VL_RAND_RESET_I(1);
    exe__DOT__divider_i__DOT__EP = VL_RAND_RESET_I(3);
    exe__DOT__divider_i__DOT__EF = VL_RAND_RESET_I(3);
    exe__DOT__divider_i__DOT__cmd_reg = VL_RAND_RESET_I(2);
    exe__DOT__divider_i__DOT__op1 = VL_RAND_RESET_I(32);
    exe__DOT__divider_i__DOT__op2 = VL_RAND_RESET_I(32);
    exe__DOT__divider_i__DOT__shift_cpt_se = VL_RAND_RESET_I(6);
    exe__DOT__divider_i__DOT__shift_cpt_reg = VL_RAND_RESET_I(6);
    exe__DOT__divider_i__DOT__divisor_se = VL_RAND_RESET_Q(64);
    exe__DOT__divider_i__DOT__reminder_se = VL_RAND_RESET_Q(64);
    exe__DOT__divider_i__DOT__divisor_reg = VL_RAND_RESET_Q(64);
    exe__DOT__divider_i__DOT__reminder_reg = VL_RAND_RESET_Q(64);
    exe__DOT__divider_i__DOT__divisor_setup = VL_RAND_RESET_Q(64);
    exe__DOT__divider_i__DOT__quotient_se = VL_RAND_RESET_I(32);
    exe__DOT__divider_i__DOT__quotient_reg = VL_RAND_RESET_I(32);
    exe__DOT__divider_i__DOT__quotient = VL_RAND_RESET_I(32);
    exe__DOT__divider_i__DOT__quotient_sign_reg = VL_RAND_RESET_I(1);
    exe__DOT__divider_i__DOT__reminder_sign_reg = VL_RAND_RESET_I(1);
    exe__DOT__divider_i__DOT__signed_inst = VL_RAND_RESET_I(1);
    exe__DOT__divider_i__DOT__division = VL_RAND_RESET_I(1);
    exe__DOT__divider_i__DOT__setup_regs = VL_RAND_RESET_I(1);
    exe__DOT__divider_i__DOT__same = VL_RAND_RESET_I(1);
    exe__DOT__divider_i__DOT__zero_div = VL_RAND_RESET_I(1);
    exe__DOT__divider_i__DOT__running = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            x0_multiplier__DOT__product[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<20; ++__Vi0) {
            x0_multiplier__DOT__product_s1[__Vi0] = VL_RAND_RESET_I(20);
    }}
    { int __Vi0=0; for (; __Vi0<14; ++__Vi0) {
            x0_multiplier__DOT__product_s2[__Vi0] = VL_RAND_RESET_I(14);
    }}
    { int __Vi0=0; for (; __Vi0<10; ++__Vi0) {
            x0_multiplier__DOT__product_s3[__Vi0] = VL_RAND_RESET_I(10);
    }}
    { int __Vi0=0; for (; __Vi0<6; ++__Vi0) {
            x0_multiplier__DOT__product_s4[__Vi0] = VL_RAND_RESET_I(6);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            x0_multiplier__DOT__product_s5[__Vi0] = VL_RAND_RESET_I(4);
    }}
    x0_multiplier__DOT__op1 = VL_RAND_RESET_I(32);
    x0_multiplier__DOT__op2 = VL_RAND_RESET_I(32);
    x0_multiplier__DOT__signed_type = VL_RAND_RESET_I(1);
    x0_multiplier__DOT__stall_sx0 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(322, x0_multiplier__DOT__x0x1_din);
    x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod = VL_RAND_RESET_Q(64);
    VL_RAND_RESET_W(322, x0_multiplier__DOT__x0x1__DOT__data);
    x0_multiplier__DOT__x0x1__DOT__data_v = VL_RAND_RESET_I(1);
    x0_multiplier__DOT__csa2_6__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__csa2_6__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__csa3_4__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__csa3_4__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk1__BRA__0__KET____DOT__csa1__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk1__BRA__0__KET____DOT__csa1__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk1__BRA__1__KET____DOT__csa1__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk1__BRA__1__KET____DOT__csa1__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk1__BRA__2__KET____DOT__csa1__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk1__BRA__2__KET____DOT__csa1__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk1__BRA__3__KET____DOT__csa1__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk1__BRA__3__KET____DOT__csa1__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk1__BRA__4__KET____DOT__csa1__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk1__BRA__4__KET____DOT__csa1__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk1__BRA__5__KET____DOT__csa1__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk1__BRA__5__KET____DOT__csa1__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk1__BRA__6__KET____DOT__csa1__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk1__BRA__6__KET____DOT__csa1__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk1__BRA__7__KET____DOT__csa1__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk1__BRA__7__KET____DOT__csa1__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk1__BRA__8__KET____DOT__csa1__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk1__BRA__8__KET____DOT__csa1__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk1__BRA__9__KET____DOT__csa1__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk1__BRA__9__KET____DOT__csa1__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk2__BRA__0__KET____DOT__csa2__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk2__BRA__0__KET____DOT__csa2__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk2__BRA__1__KET____DOT__csa2__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk2__BRA__1__KET____DOT__csa2__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk2__BRA__2__KET____DOT__csa2__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk2__BRA__2__KET____DOT__csa2__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk2__BRA__3__KET____DOT__csa2__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk2__BRA__3__KET____DOT__csa2__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk2__BRA__4__KET____DOT__csa2__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk2__BRA__4__KET____DOT__csa2__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk2__BRA__5__KET____DOT__csa2__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__genblk2__BRA__5__KET____DOT__csa2__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__csa_instance__BRA__0__KET____DOT__csa3__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__csa_instance__BRA__0__KET____DOT__csa3__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__csa_instance__BRA__1__KET____DOT__csa3__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__csa_instance__BRA__1__KET____DOT__csa3__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__csa_instance__BRA__2__KET____DOT__csa3__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__csa_instance__BRA__2__KET____DOT__csa3__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__csa_instance__BRA__3__KET____DOT__csa3__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__csa_instance__BRA__3__KET____DOT__csa3__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__stage4__BRA__0__KET____DOT__csa4__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__stage4__BRA__0__KET____DOT__csa4__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__stage4__BRA__1__KET____DOT__csa4__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__stage4__BRA__1__KET____DOT__csa4__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__stage4__BRA__2__KET____DOT__csa4__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__stage4__BRA__2__KET____DOT__csa4__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__stage5__BRA__0__KET____DOT__csa5__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__stage5__BRA__0__KET____DOT__csa5__DOT__shf = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__stage5__BRA__1__KET____DOT__csa5__DOT__AxB = VL_RAND_RESET_Q(64);
    x0_multiplier__DOT__stage5__BRA__1__KET____DOT__csa5__DOT__shf = VL_RAND_RESET_Q(64);
    __Vtableidx1 = 0;
    __Vtable1_exe__DOT__divider_i__DOT__setup_regs[0] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__setup_regs[1] = 1U;
    __Vtable1_exe__DOT__divider_i__DOT__setup_regs[2] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__setup_regs[3] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__setup_regs[4] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__setup_regs[5] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__setup_regs[6] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__setup_regs[7] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__same[0] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__same[1] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__same[2] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__same[3] = 1U;
    __Vtable1_exe__DOT__divider_i__DOT__same[4] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__same[5] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__same[6] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__same[7] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__zero_div[0] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__zero_div[1] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__zero_div[2] = 1U;
    __Vtable1_exe__DOT__divider_i__DOT__zero_div[3] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__zero_div[4] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__zero_div[5] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__zero_div[6] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__zero_div[7] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__running[0] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__running[1] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__running[2] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__running[3] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__running[4] = 1U;
    __Vtable1_exe__DOT__divider_i__DOT__running[5] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__running[6] = 0U;
    __Vtable1_exe__DOT__divider_i__DOT__running[7] = 0U;
    __Vtable1_exe__DOT__done_div[0] = 0U;
    __Vtable1_exe__DOT__done_div[1] = 0U;
    __Vtable1_exe__DOT__done_div[2] = 0U;
    __Vtable1_exe__DOT__done_div[3] = 0U;
    __Vtable1_exe__DOT__done_div[4] = 0U;
    __Vtable1_exe__DOT__done_div[5] = 1U;
    __Vtable1_exe__DOT__done_div[6] = 0U;
    __Vtable1_exe__DOT__done_div[7] = 0U;
    __Vtable1_exe__DOT__busy_div[0] = 0U;
    __Vtable1_exe__DOT__busy_div[1] = 1U;
    __Vtable1_exe__DOT__busy_div[2] = 1U;
    __Vtable1_exe__DOT__busy_div[3] = 1U;
    __Vtable1_exe__DOT__busy_div[4] = 1U;
    __Vtable1_exe__DOT__busy_div[5] = 1U;
    __Vtable1_exe__DOT__busy_div[6] = 0U;
    __Vtable1_exe__DOT__busy_div[7] = 0U;
    __Vdlyvval__x0_multiplier__DOT__product__v0 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v0 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v1 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v1 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v2 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v2 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v3 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v3 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v4 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v4 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v5 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v5 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v6 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v6 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v7 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v7 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v8 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v8 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v9 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v9 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v10 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v10 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v11 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v11 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v12 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v12 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v13 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v13 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v14 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v14 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v15 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v15 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v16 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v16 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v17 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v17 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v18 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v18 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v19 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v19 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v20 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v20 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v21 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v21 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v22 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v22 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v23 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v23 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v24 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v24 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v25 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v25 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v26 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v26 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v27 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v27 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v28 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v28 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v29 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v29 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v30 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v30 = 0;
    __Vdlyvval__x0_multiplier__DOT__product__v31 = VL_RAND_RESET_I(32);
    __Vdlyvset__x0_multiplier__DOT__product__v31 = 0;
    __Vdly__x0_multiplier__DOT__x0x1__DOT__data_v = VL_RAND_RESET_I(1);
}
