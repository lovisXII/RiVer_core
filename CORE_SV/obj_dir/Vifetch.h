// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VIFETCH_H_
#define _VIFETCH_H_  // guard

#include "verilated.h"

//==========

class Vifetch__Syms;

//----------

VL_MODULE(Vifetch) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset_n,0,0);
    VL_IN8(IC_STALL_SI,0,0);
    VL_OUT8(ADR_VALID_SI,0,0);
    VL_IN8(DEC2IF_EMPTY_SD,0,0);
    VL_OUT8(DEC2IF_POP_SI,0,0);
    VL_IN8(IF2DEC_FLUSH_SD,0,0);
    VL_IN8(IF2DEC_POP_SD,0,0);
    VL_OUT8(IF2DEC_EMPTY_SI,0,0);
    VL_IN8(EXCEPTION_SM,0,0);
    VL_OUT8(EXCEPTION_RI,0,0);
    VL_IN8(PRED_FAILED_RD,0,0);
    VL_IN8(PRED_SUCCESS_RD,0,0);
    VL_IN8(BRANCH_INST_RD,0,0);
    VL_IN8(PRED_TAKEN_SD,0,0);
    VL_IN8(PUSH_ADR_RAS_RD,0,0);
    VL_IN8(POP_ADR_RAS_RD,0,0);
    VL_IN8(RET_INST_RD,0,0);
    VL_OUT8(PRED_TAKEN_RI,0,0);
    VL_IN(IC_INST_SI,31,0);
    VL_OUT(ADR_SI,31,0);
    VL_IN(PC_RD,31,0);
    VL_OUT(INSTR_RI,31,0);
    VL_OUT(PC_IF2DEC_RI,31,0);
    VL_IN(BRANCH_INST_ADR_RD,31,0);
    VL_IN(ADR_TO_BRANCH_RD,31,0);
    VL_IN(PRED_ADR_SD,31,0);
    VL_IN(ADR_TO_RET_RD,31,0);
    VL_OUT(PRED_ADR_RI,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ ifetch__DOT__if2dec_push_si;
    CData/*0:0*/ ifetch__DOT__stall_si;
    CData/*1:0*/ ifetch__DOT__next_pred_state;
    CData/*3:0*/ ifetch__DOT__pred_valid_reg;
    CData/*0:0*/ ifetch__DOT__pred_branch_taken;
    CData/*0:0*/ ifetch__DOT__unnamedblk2__DOT__found;
    CData/*1:0*/ ifetch__DOT__unnamedblk2__DOT__pred_write_pointer;
    CData/*0:0*/ ifetch__DOT__unnamedblk4__DOT__found;
    CData/*0:0*/ ifetch__DOT__unnamedblk4__DOT__pred_good;
    CData/*0:0*/ ifetch__DOT__if2dec__DOT__data_v;
    WData/*96:0*/ ifetch__DOT__if2dec_din[4];
    IData/*31:0*/ ifetch__DOT__pred_branch_next_adr;
    IData/*31:0*/ ifetch__DOT__unnamedblk2__DOT__index;
    IData/*31:0*/ ifetch__DOT__unnamedblk2__DOT__unnamedblk3__DOT__i;
    WData/*96:0*/ ifetch__DOT__if2dec__DOT__data[4];
    IData/*31:0*/ ifetch__DOT__branch_adr_reg[4];
    IData/*31:0*/ ifetch__DOT__predicted_adr_reg[4];
    CData/*1:0*/ ifetch__DOT__pred_state_reg[4];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__reset_n;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vifetch__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vifetch);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vifetch(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vifetch();
    
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
    static void _eval_initial_loop(Vifetch__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vifetch__Syms* symsp, bool first);
  private:
    static QData _change_request(Vifetch__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vifetch__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__2(Vifetch__Syms* __restrict vlSymsp);
    static void _combo__TOP__6(Vifetch__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vifetch__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vifetch__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vifetch__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vifetch__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__4(Vifetch__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vifetch__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vifetch__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
