// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VX2_MULTIPLIER__SYMS_H_
#define _VX2_MULTIPLIER__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vx2_multiplier.h"

// SYMS CLASS
class Vx2_multiplier__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vx2_multiplier*                TOPp;
    
    // CREATORS
    Vx2_multiplier__Syms(Vx2_multiplier* topp, const char* namep);
    ~Vx2_multiplier__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
