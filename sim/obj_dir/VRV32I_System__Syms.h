// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VRV32I_SYSTEM__SYMS_H_
#define VERILATED_VRV32I_SYSTEM__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VRV32I_System.h"

// INCLUDE MODULE CLASSES
#include "VRV32I_System___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) VRV32I_System__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VRV32I_System* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VRV32I_System___024root        TOP;

    // CONSTRUCTORS
    VRV32I_System__Syms(VerilatedContext* contextp, const char* namep, VRV32I_System* modelp);
    ~VRV32I_System__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
