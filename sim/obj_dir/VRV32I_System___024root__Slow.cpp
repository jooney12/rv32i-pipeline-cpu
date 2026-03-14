// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VRV32I_System.h for the primary calling header

#include "VRV32I_System__pch.h"

void VRV32I_System___024root___ctor_var_reset(VRV32I_System___024root* vlSelf);

VRV32I_System___024root::VRV32I_System___024root(VRV32I_System__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    VRV32I_System___024root___ctor_var_reset(this);
}

void VRV32I_System___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VRV32I_System___024root::~VRV32I_System___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
