// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vriver_pkg__Syms.h"
#include "Vriver_pkg.h"
#include "Vriver_pkg___024unit.h"



// FUNCTIONS
Vriver_pkg__Syms::Vriver_pkg__Syms(Vriver_pkg* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
}
