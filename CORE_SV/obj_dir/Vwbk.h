// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VWBK_H_
#define _VWBK_H_  // guard

#include "verilated.h"

//==========

class Vwbk__Syms;

//----------

VL_MODULE(Vwbk) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset_n,0,0);
    VL_IN8(MEM_DEST_RM,5,0);
    VL_IN8(WB_RM,0,0);
    VL_IN8(CSR_WENABLE_RM,0,0);
    VL_IN8(CURRENT_MODE_SM,1,0);
    VL_IN8(MEM2WBK_EMPTY_SM,0,0);
    VL_OUT8(MEM2WBK_POP_SW,0,0);
    VL_IN8(MULT_INST_RM,0,0);
    VL_OUT8(DEST_SW,5,0);
    VL_OUT8(WB_SW,0,0);
    VL_IN(MEM_RES_RM,31,0);
    VL_IN(PC_MEM2WBK_RM,31,0);
    VL_IN(CSR_RDATA_RM,31,0);
    VL_IN(RES_RX2,31,0);
    VL_OUT(DATA_SW,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vwbk__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vwbk);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vwbk(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vwbk();
    
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
    static void _eval_initial_loop(Vwbk__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vwbk__Syms* symsp, bool first);
  private:
    static QData _change_request(Vwbk__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vwbk__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vwbk__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vwbk__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vwbk__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vwbk__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
