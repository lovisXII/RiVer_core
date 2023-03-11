// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VX2_MULTIPLIER_H_
#define _VX2_MULTIPLIER_H_  // guard

#include "verilated.h"

//==========

class Vx2_multiplier__Syms;

//----------

VL_MODULE(Vx2_multiplier) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset_n,0,0);
    VL_IN8(SELECT_MSB_RX1,0,0);
    VL_IN8(SIGNED_RES_RX1,0,0);
    VL_IN8(X1X2_EMPTY_SX1,0,0);
    VL_OUT8(X1X2_POP_SX2,0,0);
    VL_INW(RES_RX1,127,0,4);
    VL_OUT(RES_RX2,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    QData/*63:0*/ x2_multiplier__DOT__res;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__reset_n;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vx2_multiplier__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vx2_multiplier);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vx2_multiplier(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vx2_multiplier();
    
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
    static void _eval_initial_loop(Vx2_multiplier__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vx2_multiplier__Syms* symsp, bool first);
  private:
    static QData _change_request(Vx2_multiplier__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vx2_multiplier__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vx2_multiplier__Syms* __restrict vlSymsp);
    static void _combo__TOP__4(Vx2_multiplier__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vx2_multiplier__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vx2_multiplier__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vx2_multiplier__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__3(Vx2_multiplier__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vx2_multiplier__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
