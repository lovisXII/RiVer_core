// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VRIVER_PKG__SYMS_H_
#define _VRIVER_PKG__SYMS_H_  // guard

#include "systemc.h"
#include "verilated_sc.h"
#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vriver_pkg.h"
#include "Vriver_pkg___024unit.h"

// SYMS CLASS
class Vriver_pkg__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vriver_pkg*                    TOPp;
    
    // CREATORS
    Vriver_pkg__Syms(Vriver_pkg* topp, const char* namep);
    ~Vriver_pkg__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
