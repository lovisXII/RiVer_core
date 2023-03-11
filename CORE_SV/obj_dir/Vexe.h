// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VEXE_H_
#define _VEXE_H_  // guard

#include "verilated.h"

//==========

class Vexe__Syms;

//----------

VL_MODULE(Vexe) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(exe__02Eclk,0,0);
    VL_IN8(exe__02Ereset_n,0,0);
    VL_IN8(x0_multiplier__02Eclk,0,0);
    VL_IN8(RADR1_RD,5,0);
    VL_IN8(RADR2_RD,5,0);
    VL_IN8(DEST_RD,5,0);
    VL_IN8(CMD_RD,1,0);
    VL_IN8(MEM_SIZE_RD,1,0);
    VL_IN8(NEG_OP2_RD,0,0);
    VL_IN8(WB_RD,0,0);
    VL_IN8(MEM_SIGN_EXTEND_RD,0,0);
    VL_IN8(SELECT_OPERATION_RD,3,0);
    VL_IN8(MEM_LOAD_RD,0,0);
    VL_IN8(MEM_STORE_RD,0,0);
    VL_IN8(EXE2MEM_POP_SM,0,0);
    VL_IN8(DEC2EXE_EMPTY_SD,0,0);
    VL_IN8(SLT_RD,0,0);
    VL_IN8(SLTU_RD,0,0);
    VL_OUT8(DEST_RE,5,0);
    VL_OUT8(MEM_SIZE_RE,1,0);
    VL_OUT8(WB_RE,0,0);
    VL_OUT8(MEM_SIGN_EXTEND_RE,0,0);
    VL_OUT8(MEM_LOAD_RE,0,0);
    VL_OUT8(MEM_STORE_RE,0,0);
    VL_OUT8(EXE2MEM_EMPTY_SE,0,0);
    VL_OUT8(DEC2EXE_POP_SE,0,0);
    VL_IN8(BLOCK_BP_RD,0,0);
    VL_IN8(MEM_DEST_RM,5,0);
    VL_IN8(CSR_WENABLE_RM,0,0);
    VL_IN8(BP_MEM2WBK_EMPTY_SM,0,0);
    VL_IN8(CSR_WENABLE_RD,0,0);
    VL_IN8(MULT_INST_RM,0,0);
    VL_IN8(MULT_INST_RD,0,0);
    VL_OUT8(MULT_INST_RE,0,0);
    VL_IN8(EXCEPTION_SM,0,0);
    VL_IN8(EXCEPTION_RD,0,0);
    VL_IN8(CURRENT_MODE_SM,1,0);
    VL_IN8(ILLEGAL_INSTRUCTION_RD,0,0);
    VL_IN8(ADRESS_MISALIGNED_RD,0,0);
    VL_IN8(INSTRUCTION_ACCESS_FAULT_RD,0,0);
    VL_IN8(ENV_CALL_U_MODE_RD,0,0);
    VL_IN8(ENV_CALL_S_MODE_RD,0,0);
    VL_IN8(ENV_CALL_M_MODE_RD,0,0);
    VL_IN8(ENV_CALL_WRONG_MODE_RD,0,0);
    VL_IN8(MRET_RD,0,0);
    VL_IN8(EBREAK_RD,0,0);
    VL_OUT8(EXCEPTION_RE,0,0);
    VL_OUT8(ILLEGAL_INSTRUCTION_RE,0,0);
    VL_OUT8(ADRESS_MISALIGNED_RE,0,0);
    VL_OUT8(INSTRUCTION_ACCESS_FAULT_RE,0,0);
    VL_OUT8(ENV_CALL_U_MODE_RE,0,0);
    VL_OUT8(ENV_CALL_S_MODE_RE,0,0);
    VL_OUT8(ENV_CALL_M_MODE_RE,0,0);
    VL_OUT8(ENV_CALL_WRONG_MODE_RE,0,0);
    VL_OUT8(LOAD_ADRESS_MISALIGNED_RE,0,0);
    VL_OUT8(LOAD_ACCESS_FAULT_RE,0,0);
    VL_OUT8(STORE_ADRESS_MISALIGNED_RE,0,0);
    VL_OUT8(STORE_ACCESS_FAULT_RE,0,0);
    VL_OUT8(MRET_RE,0,0);
    VL_OUT8(EBREAK_RE,0,0);
    VL_OUT8(CSR_WENABLE_RE,0,0);
    VL_IN8(x0_multiplier__02Ereset_n,0,0);
    VL_IN8(MULT_CMD_RD,1,0);
    VL_IN8(X0X1_POP_SX1,0,0);
    VL_IN8(DEC2X0_EMPTY_SD,0,0);
    VL_OUT8(SELECT_MSB_RX0,0,0);
    VL_OUT8(SIGNED_RES_RX0,0,0);
    VL_OUT8(X0X1_EMPTY_SX0,0,0);
    VL_IN16(CSR_WADR_RD,11,0);
    VL_OUT16(CSR_WADR_RE,11,0);
    VL_IN(OP1_RD,31,0);
    VL_IN(OP2_RD,31,0);
    VL_IN(MEM_DATA_RD,31,0);
    VL_OUT(RES_RE,31,0);
    VL_OUT(MEM_DATA_RE,31,0);
    VL_IN(PC_DEC2EXE_RD,31,0);
    VL_OUT(PC_EXE2MEM_RE,31,0);
    VL_IN(MEM_RES_RM,31,0);
    VL_IN(CSR_RDATA_RM,31,0);
    VL_IN(CSR_RDATA_RD,31,0);
    VL_OUT(exe__02EOP1_SE,31,0);
    VL_OUT(exe__02EOP2_SE,31,0);
    VL_IN(PC_BRANCH_VALUE_RD,31,0);
    VL_OUT(PC_BRANCH_VALUE_RE,31,0);
    VL_OUT(CSR_RDATA_RE,31,0);
    VL_IN(x0_multiplier__02EOP1_SE,31,0);
    VL_IN(x0_multiplier__02EOP2_SE,31,0);
    VL_OUTW(RES_RX0,319,0,10);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ exe__DOT__stall_se;
        CData/*0:0*/ exe__DOT__r1_valid_se;
        CData/*0:0*/ exe__DOT__r2_valid_se;
        CData/*0:0*/ exe__DOT__bpc_disable2;
        CData/*0:0*/ exe__DOT__adress_misaligned;
        CData/*0:0*/ exe__DOT__load_adress_misaligned_se;
        CData/*0:0*/ exe__DOT__store_adress_misaligned_se;
        CData/*0:0*/ exe__DOT__access_fault;
        CData/*0:0*/ exe__DOT__load_access_fault_se;
        CData/*0:0*/ exe__DOT__store_access_fault_se;
        CData/*0:0*/ exe__DOT__exception_se;
        CData/*0:0*/ exe__DOT__start_div;
        CData/*0:0*/ exe__DOT__done_div;
        CData/*0:0*/ exe__DOT__busy_div;
        CData/*0:0*/ exe__DOT__exe2mem__DOT__data_v;
        CData/*2:0*/ exe__DOT__divider_i__DOT__EP;
        CData/*2:0*/ exe__DOT__divider_i__DOT__EF;
        CData/*1:0*/ exe__DOT__divider_i__DOT__cmd_reg;
        CData/*5:0*/ exe__DOT__divider_i__DOT__shift_cpt_se;
        CData/*5:0*/ exe__DOT__divider_i__DOT__shift_cpt_reg;
        CData/*0:0*/ exe__DOT__divider_i__DOT__quotient_sign_reg;
        CData/*0:0*/ exe__DOT__divider_i__DOT__reminder_sign_reg;
        CData/*0:0*/ exe__DOT__divider_i__DOT__signed_inst;
        CData/*0:0*/ exe__DOT__divider_i__DOT__division;
        CData/*0:0*/ exe__DOT__divider_i__DOT__setup_regs;
        CData/*0:0*/ exe__DOT__divider_i__DOT__same;
        CData/*0:0*/ exe__DOT__divider_i__DOT__zero_div;
        CData/*0:0*/ exe__DOT__divider_i__DOT__running;
        CData/*0:0*/ x0_multiplier__DOT__signed_type;
        CData/*0:0*/ x0_multiplier__DOT__stall_sx0;
        CData/*0:0*/ x0_multiplier__DOT__x0x1__DOT__data_v;
        WData/*199:0*/ exe__DOT__exe2mem_data[7];
        WData/*199:0*/ exe__DOT__exe2mem_x[7];
        WData/*199:0*/ exe__DOT__exe2mem_din[7];
        IData/*31:0*/ exe__DOT__op1;
        IData/*31:0*/ exe__DOT__op2;
        IData/*31:0*/ exe__DOT__alu_op2;
        IData/*31:0*/ exe__DOT__alu_res;
        IData/*31:0*/ exe__DOT__exe_res;
        IData/*31:0*/ exe__DOT__shifter_i__DOT__lshift16;
        IData/*31:0*/ exe__DOT__shifter_i__DOT__lshift8;
        IData/*31:0*/ exe__DOT__shifter_i__DOT__lshift4;
        IData/*31:0*/ exe__DOT__shifter_i__DOT__lshift2;
        IData/*31:0*/ exe__DOT__shifter_i__DOT__rshift16;
        IData/*31:0*/ exe__DOT__shifter_i__DOT__rshift8;
        IData/*31:0*/ exe__DOT__shifter_i__DOT__rshift4;
        IData/*31:0*/ exe__DOT__shifter_i__DOT__rshift2;
        WData/*199:0*/ exe__DOT__exe2mem__DOT__data[7];
        IData/*31:0*/ exe__DOT__divider_i__DOT__op1;
        IData/*31:0*/ exe__DOT__divider_i__DOT__op2;
        IData/*31:0*/ exe__DOT__divider_i__DOT__quotient_se;
        IData/*31:0*/ exe__DOT__divider_i__DOT__quotient_reg;
        IData/*31:0*/ exe__DOT__divider_i__DOT__quotient;
        IData/*31:0*/ x0_multiplier__DOT__op1;
        IData/*31:0*/ x0_multiplier__DOT__op2;
        WData/*321:0*/ x0_multiplier__DOT__x0x1_din[11];
        WData/*321:0*/ x0_multiplier__DOT__x0x1__DOT__data[11];
        QData/*63:0*/ exe__DOT__divider_i__DOT__divisor_se;
        QData/*63:0*/ exe__DOT__divider_i__DOT__reminder_se;
        QData/*63:0*/ exe__DOT__divider_i__DOT__divisor_reg;
        QData/*63:0*/ exe__DOT__divider_i__DOT__reminder_reg;
        QData/*63:0*/ exe__DOT__divider_i__DOT__divisor_setup;
        QData/*63:0*/ x0_multiplier__DOT__unnamedblk1__DOT__unnamedblk2__DOT__prod;
        QData/*63:0*/ x0_multiplier__DOT__csa2_6__DOT__AxB;
    };
    struct {
        QData/*63:0*/ x0_multiplier__DOT__csa2_6__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__csa3_4__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__csa3_4__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__genblk1__BRA__0__KET____DOT__csa1__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__genblk1__BRA__0__KET____DOT__csa1__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__genblk1__BRA__1__KET____DOT__csa1__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__genblk1__BRA__1__KET____DOT__csa1__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__genblk1__BRA__2__KET____DOT__csa1__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__genblk1__BRA__2__KET____DOT__csa1__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__genblk1__BRA__3__KET____DOT__csa1__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__genblk1__BRA__3__KET____DOT__csa1__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__genblk1__BRA__4__KET____DOT__csa1__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__genblk1__BRA__4__KET____DOT__csa1__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__genblk1__BRA__5__KET____DOT__csa1__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__genblk1__BRA__5__KET____DOT__csa1__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__genblk1__BRA__6__KET____DOT__csa1__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__genblk1__BRA__6__KET____DOT__csa1__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__genblk1__BRA__7__KET____DOT__csa1__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__genblk1__BRA__7__KET____DOT__csa1__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__genblk1__BRA__8__KET____DOT__csa1__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__genblk1__BRA__8__KET____DOT__csa1__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__genblk1__BRA__9__KET____DOT__csa1__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__genblk1__BRA__9__KET____DOT__csa1__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__genblk2__BRA__0__KET____DOT__csa2__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__genblk2__BRA__0__KET____DOT__csa2__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__genblk2__BRA__1__KET____DOT__csa2__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__genblk2__BRA__1__KET____DOT__csa2__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__genblk2__BRA__2__KET____DOT__csa2__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__genblk2__BRA__2__KET____DOT__csa2__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__genblk2__BRA__3__KET____DOT__csa2__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__genblk2__BRA__3__KET____DOT__csa2__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__genblk2__BRA__4__KET____DOT__csa2__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__genblk2__BRA__4__KET____DOT__csa2__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__genblk2__BRA__5__KET____DOT__csa2__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__genblk2__BRA__5__KET____DOT__csa2__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__csa_instance__BRA__0__KET____DOT__csa3__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__csa_instance__BRA__0__KET____DOT__csa3__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__csa_instance__BRA__1__KET____DOT__csa3__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__csa_instance__BRA__1__KET____DOT__csa3__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__csa_instance__BRA__2__KET____DOT__csa3__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__csa_instance__BRA__2__KET____DOT__csa3__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__csa_instance__BRA__3__KET____DOT__csa3__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__csa_instance__BRA__3__KET____DOT__csa3__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__stage4__BRA__0__KET____DOT__csa4__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__stage4__BRA__0__KET____DOT__csa4__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__stage4__BRA__1__KET____DOT__csa4__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__stage4__BRA__1__KET____DOT__csa4__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__stage4__BRA__2__KET____DOT__csa4__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__stage4__BRA__2__KET____DOT__csa4__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__stage5__BRA__0__KET____DOT__csa5__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__stage5__BRA__0__KET____DOT__csa5__DOT__shf;
        QData/*63:0*/ x0_multiplier__DOT__stage5__BRA__1__KET____DOT__csa5__DOT__AxB;
        QData/*63:0*/ x0_multiplier__DOT__stage5__BRA__1__KET____DOT__csa5__DOT__shf;
        IData/*31:0*/ x0_multiplier__DOT__product[32];
        IData/*19:0*/ x0_multiplier__DOT__product_s1[20];
        SData/*13:0*/ x0_multiplier__DOT__product_s2[14];
        SData/*9:0*/ x0_multiplier__DOT__product_s3[10];
        CData/*5:0*/ x0_multiplier__DOT__product_s4[6];
        CData/*3:0*/ x0_multiplier__DOT__product_s5[4];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*2:0*/ __Vtableidx1;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v0;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v1;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v2;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v3;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v4;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v5;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v6;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v7;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v8;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v9;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v10;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v11;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v12;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v13;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v14;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v15;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v16;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v17;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v18;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v19;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v20;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v21;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v22;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v23;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v24;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v25;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v26;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v27;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v28;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v29;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v30;
        CData/*0:0*/ __Vdlyvset__x0_multiplier__DOT__product__v31;
        CData/*0:0*/ __Vdly__x0_multiplier__DOT__x0x1__DOT__data_v;
        CData/*0:0*/ __Vclklast__TOP__exe__02Eclk;
        CData/*0:0*/ __Vclklast__TOP__x0_multiplier__02Eclk;
        CData/*0:0*/ __Vclklast__TOP__exe__02Ereset_n;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v0;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v1;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v2;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v3;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v4;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v5;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v6;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v7;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v8;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v9;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v10;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v11;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v12;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v13;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v14;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v15;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v16;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v17;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v18;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v19;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v20;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v21;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v22;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v23;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v24;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v25;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v26;
    };
    struct {
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v27;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v28;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v29;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v30;
        IData/*31:0*/ __Vdlyvval__x0_multiplier__DOT__product__v31;
    };
    static CData/*0:0*/ __Vtable1_exe__DOT__divider_i__DOT__setup_regs[8];
    static CData/*0:0*/ __Vtable1_exe__DOT__divider_i__DOT__same[8];
    static CData/*0:0*/ __Vtable1_exe__DOT__divider_i__DOT__zero_div[8];
    static CData/*0:0*/ __Vtable1_exe__DOT__divider_i__DOT__running[8];
    static CData/*0:0*/ __Vtable1_exe__DOT__done_div[8];
    static CData/*0:0*/ __Vtable1_exe__DOT__busy_div[8];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vexe__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vexe);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vexe(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vexe();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vexe__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vexe__Syms* symsp, bool first);
  private:
    static QData _change_request(Vexe__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vexe__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(Vexe__Syms* __restrict vlSymsp);
    static void _combo__TOP__9(Vexe__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vexe__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vexe__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vexe__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__2(Vexe__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__10(Vexe__Syms* __restrict vlSymsp);
    static void _sequent__TOP__11(Vexe__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vexe__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vexe__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vexe__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vexe__Syms* __restrict vlSymsp);
    static void _settle__TOP__1(Vexe__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__8(Vexe__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
