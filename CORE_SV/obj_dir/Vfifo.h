// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VFIFO_H_
#define _VFIFO_H_  // guard

#include "verilated.h"

//==========

class Vfifo__Syms;

//----------

VL_MODULE(Vfifo) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset_n,0,0);
    VL_IN8(DIN,0,0);
    VL_IN8(PUSH,0,0);
    VL_IN8(POP,0,0);
    VL_OUT8(FULL,0,0);
    VL_OUT8(EMPTY,0,0);
    VL_OUT8(DOUT,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ fifo__DOT__data;
    CData/*0:0*/ fifo__DOT__data_v;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vfifo__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vfifo);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vfifo(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vfifo();
    
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
    static void _eval_initial_loop(Vfifo__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vfifo__Syms* symsp, bool first);
  private:
    static QData _change_request(Vfifo__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vfifo__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__4(Vfifo__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vfifo__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vfifo__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vfifo__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__2(Vfifo__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vfifo__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vfifo__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
