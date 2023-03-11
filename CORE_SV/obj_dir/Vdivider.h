// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VDIVIDER_H_
#define _VDIVIDER_H_  // guard

#include "verilated.h"

//==========

class Vdivider__Syms;

//----------

VL_MODULE(Vdivider) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset_n,0,0);
    VL_IN8(CMD_RD,1,0);
    VL_IN8(START_DIV,0,0);
    VL_OUT8(DONE_DIV,0,0);
    VL_OUT8(BUSY_DIV,0,0);
    VL_IN(OP1_SE,31,0);
    VL_IN(OP2_SE,31,0);
    VL_OUT(RES_DIV,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*2:0*/ divider__DOT__EP;
    CData/*2:0*/ divider__DOT__EF;
    CData/*1:0*/ divider__DOT__cmd_reg;
    CData/*5:0*/ divider__DOT__shift_cpt_se;
    CData/*5:0*/ divider__DOT__shift_cpt_reg;
    CData/*0:0*/ divider__DOT__quotient_sign_reg;
    CData/*0:0*/ divider__DOT__reminder_sign_reg;
    CData/*0:0*/ divider__DOT__signed_inst;
    CData/*0:0*/ divider__DOT__division;
    CData/*0:0*/ divider__DOT__setup_regs;
    CData/*0:0*/ divider__DOT__same;
    CData/*0:0*/ divider__DOT__zero_div;
    CData/*0:0*/ divider__DOT__running;
    IData/*31:0*/ divider__DOT__op1;
    IData/*31:0*/ divider__DOT__op2;
    IData/*31:0*/ divider__DOT__quotient_se;
    IData/*31:0*/ divider__DOT__quotient_reg;
    IData/*31:0*/ divider__DOT__quotient;
    QData/*63:0*/ divider__DOT__divisor_se;
    QData/*63:0*/ divider__DOT__reminder_se;
    QData/*63:0*/ divider__DOT__divisor_reg;
    QData/*63:0*/ divider__DOT__reminder_reg;
    QData/*63:0*/ divider__DOT__divisor_setup;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*2:0*/ __Vtableidx1;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__reset_n;
    static CData/*0:0*/ __Vtable1_divider__DOT__setup_regs[8];
    static CData/*0:0*/ __Vtable1_divider__DOT__same[8];
    static CData/*0:0*/ __Vtable1_divider__DOT__zero_div[8];
    static CData/*0:0*/ __Vtable1_divider__DOT__running[8];
    static CData/*0:0*/ __Vtable1_DONE_DIV[8];
    static CData/*0:0*/ __Vtable1_BUSY_DIV[8];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vdivider__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vdivider);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vdivider(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vdivider();
    
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
    static void _eval_initial_loop(Vdivider__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vdivider__Syms* symsp, bool first);
  private:
    static QData _change_request(Vdivider__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vdivider__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__6(Vdivider__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vdivider__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vdivider__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vdivider__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vdivider__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__3(Vdivider__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vdivider__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vdivider__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vdivider__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vdivider__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
