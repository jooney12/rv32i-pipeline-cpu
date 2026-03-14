// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VRV32I_System.h for the primary calling header

#include "VRV32I_System__pch.h"

VL_ATTR_COLD void VRV32I_System___024root___eval_static(VRV32I_System___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___eval_static\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
}

VL_ATTR_COLD void VRV32I_System___024root___eval_initial__TOP(VRV32I_System___024root* vlSelf);
VL_ATTR_COLD void VRV32I_System___024root____Vm_traceActivitySetAll(VRV32I_System___024root* vlSelf);

VL_ATTR_COLD void VRV32I_System___024root___eval_initial(VRV32I_System___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___eval_initial\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VRV32I_System___024root___eval_initial__TOP(vlSelf);
    VRV32I_System___024root____Vm_traceActivitySetAll(vlSelf);
}

VL_ATTR_COLD void VRV32I_System___024root___eval_initial__TOP(VRV32I_System___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___eval_initial__TOP\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00001000U, vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__i)) {
        vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__mem[(0x00000fffU 
                                                          & vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__i)] = 0U;
        vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__i 
            = ((IData)(1U) + vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__i);
    }
    vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__read_data0_reg = 0U;
    vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__read_data1_reg = 0U;
}

VL_ATTR_COLD void VRV32I_System___024root___eval_final(VRV32I_System___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___eval_final\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VRV32I_System___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VRV32I_System___024root___eval_phase__stl(VRV32I_System___024root* vlSelf);

VL_ATTR_COLD void VRV32I_System___024root___eval_settle(VRV32I_System___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___eval_settle\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            VRV32I_System___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("../rtl/RV32I_System.v", 1, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = VRV32I_System___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void VRV32I_System___024root___eval_triggers_vec__stl(VRV32I_System___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___eval_triggers_vec__stl\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool VRV32I_System___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VRV32I_System___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(VRV32I_System___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool VRV32I_System___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlUnpacked<CData/*0:0*/, 128> VRV32I_System__ConstPool__TABLE_h84e63adf_0;
extern const VlUnpacked<CData/*2:0*/, 128> VRV32I_System__ConstPool__TABLE_h2c554882_0;
extern const VlUnpacked<CData/*1:0*/, 128> VRV32I_System__ConstPool__TABLE_h11fb5362_0;
extern const VlUnpacked<CData/*0:0*/, 128> VRV32I_System__ConstPool__TABLE_hb0347273_0;
extern const VlUnpacked<CData/*0:0*/, 128> VRV32I_System__ConstPool__TABLE_h16aa4d84_0;
extern const VlUnpacked<CData/*1:0*/, 128> VRV32I_System__ConstPool__TABLE_h5c1acdf1_0;
extern const VlUnpacked<CData/*0:0*/, 128> VRV32I_System__ConstPool__TABLE_h95acb82f_0;
extern const VlUnpacked<CData/*1:0*/, 128> VRV32I_System__ConstPool__TABLE_hbd88711c_0;
extern const VlUnpacked<CData/*0:0*/, 256> VRV32I_System__ConstPool__TABLE_h1aa3e2e8_0;

VL_ATTR_COLD void VRV32I_System___024root___stl_sequent__TOP__0(VRV32I_System___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___stl_sequent__TOP__0\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*7:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    SData/*9:0*/ __VdfgRegularize_h6e95ff9d_0_0;
    __VdfgRegularize_h6e95ff9d_0_0 = 0;
    CData/*3:0*/ __VdfgRegularize_h6e95ff9d_0_15;
    __VdfgRegularize_h6e95ff9d_0_15 = 0;
    // Body
    vlSelfRef.pc = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcRegF;
    vlSelfRef.data_r_dbg = vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__read_data1_reg;
    vlSelfRef.inst_dbg = vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__read_data0_reg;
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT____VdfgRegularize_h3a653db9_0_0 
        = ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteW) 
           & (0U != (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW)));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__fetch_resp_valid_raw 
        = ((~ (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__killRespF_r)) 
           & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__respValidF_r));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BE_WD_M 
        = VL_SHIFTL_III(32,32,32, vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__WriteDataM, 
                        VL_SHIFTL_III(32,32,32, (3U 
                                                 & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM), 3U));
    __VdfgRegularize_h6e95ff9d_0_0 = ((0x000003f8U 
                                       & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                          >> 0x00000016U)) 
                                      | (7U & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                               >> 0x0000000cU)));
    __VdfgRegularize_h6e95ff9d_0_15 = (0x0000000fU 
                                       & ((1U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M))
                                           ? ((2U & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM)
                                               ? 0x0cU
                                               : 3U)
                                           : ((IData)(1U) 
                                              << (3U 
                                                  & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM))));
    if (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD) {
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D 
            = (0x0000001fU & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                              >> 0x0000000fU));
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D 
            = (0x0000001fU & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                              >> 0x00000014U));
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_controller__DOT__u_aludec__DOT__opcode 
            = (0x0000007fU & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD);
    } else {
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_controller__DOT__u_aludec__DOT__opcode = 0U;
    }
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemRData_bypassed 
        = (((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreValid_r) 
            & ((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreAddr_r 
                >> 2U) == (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM 
                           >> 2U))) ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreData_r
            : vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__read_data1_reg);
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardBE = 0U;
    if ((((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteM) 
          & (0U != (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdM))) 
         & ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdM) 
            == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2E)))) {
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardBE = 2U;
    } else if ((((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteW) 
                 & (0U != (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW))) 
                & ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW) 
                   == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2E)))) {
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardBE = 1U;
    }
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardAE = 0U;
    if ((((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteM) 
          & (0U != (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdM))) 
         & ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdM) 
            == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1E)))) {
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardAE = 2U;
    } else if ((((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteW) 
                 & (0U != (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW))) 
                & ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW) 
                   == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1E)))) {
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardAE = 1U;
    }
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__resultW_dbg 
        = ((1U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcW))
            ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ReadDataW
            : ((2U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcW))
                ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4W
                : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultW));
    vlSelfRef.MemWData = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BE_WD_M;
    vlSelfRef.ByteEnable = ((4U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M))
                             ? ((2U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M))
                                 ? 0U : (IData)(__VdfgRegularize_h6e95ff9d_0_15))
                             : ((2U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M))
                                 ? ((1U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M))
                                     ? 0U : 0x0fU) : (IData)(__VdfgRegularize_h6e95ff9d_0_15)));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__stallF 
        = ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validE) 
           & ((1U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcE)) 
              & ((((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdE) 
                   == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D)) 
                  & (0U != (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D))) 
                 | (((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdE) 
                     == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D)) 
                    & (0U != (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D))))));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift8 
        = VL_SHIFTR_III(32,32,32, vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemRData_bypassed, 
                        VL_SHIFTL_III(32,32,32, (3U 
                                                 & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM), 3U));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift16 
        = VL_SHIFTR_III(32,32,32, vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemRData_bypassed, 
                        VL_SHIFTL_III(32,32,32, (1U 
                                                 & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM 
                                                    >> 1U)), 4U));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_controller__DOT__u_aludec__DOT__ALUControl 
        = ((0x33U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_controller__DOT__u_aludec__DOT__opcode))
            ? ((((0U == (IData)(__VdfgRegularize_h6e95ff9d_0_0)) 
                 | (0x0100U == (IData)(__VdfgRegularize_h6e95ff9d_0_0))) 
                | (((1U == (IData)(__VdfgRegularize_h6e95ff9d_0_0)) 
                    | (2U == (IData)(__VdfgRegularize_h6e95ff9d_0_0))) 
                   | ((3U == (IData)(__VdfgRegularize_h6e95ff9d_0_0)) 
                      | ((4U == (IData)(__VdfgRegularize_h6e95ff9d_0_0)) 
                         | ((5U == (IData)(__VdfgRegularize_h6e95ff9d_0_0)) 
                            | (0x0105U == (IData)(__VdfgRegularize_h6e95ff9d_0_0)))))))
                ? ((0U == (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                    ? 0U : ((0x0100U == (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                             ? 0x10U : ((1U == (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                         ? 4U : ((2U 
                                                  == (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                  ? 0x17U
                                                  : 
                                                 ((3U 
                                                   == (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                   ? 0x18U
                                                   : 
                                                  ((4U 
                                                    == (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                    ? 3U
                                                    : 
                                                   ((5U 
                                                     == (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                     ? 5U
                                                     : 6U)))))))
                : ((6U == (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                    ? 1U : ((7U == (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                             ? 2U : 0U))) : ((0x13U 
                                              == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_controller__DOT__u_aludec__DOT__opcode))
                                              ? (((
                                                   (0U 
                                                    == 
                                                    (7U 
                                                     & (IData)(__VdfgRegularize_h6e95ff9d_0_0))) 
                                                   | (1U 
                                                      == (IData)(__VdfgRegularize_h6e95ff9d_0_0))) 
                                                  | (((2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(__VdfgRegularize_h6e95ff9d_0_0))) 
                                                      | (3U 
                                                         == 
                                                         (7U 
                                                          & (IData)(__VdfgRegularize_h6e95ff9d_0_0)))) 
                                                     | ((4U 
                                                         == 
                                                         (7U 
                                                          & (IData)(__VdfgRegularize_h6e95ff9d_0_0))) 
                                                        | ((5U 
                                                            == (IData)(__VdfgRegularize_h6e95ff9d_0_0)) 
                                                           | ((0x0105U 
                                                               == (IData)(__VdfgRegularize_h6e95ff9d_0_0)) 
                                                              | (6U 
                                                                 == 
                                                                 (7U 
                                                                  & (IData)(__VdfgRegularize_h6e95ff9d_0_0))))))))
                                                  ? 
                                                 ((0U 
                                                   == 
                                                   (7U 
                                                    & (IData)(__VdfgRegularize_h6e95ff9d_0_0)))
                                                   ? 0U
                                                   : 
                                                  ((1U 
                                                    == (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                    ? 4U
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (7U 
                                                      & (IData)(__VdfgRegularize_h6e95ff9d_0_0)))
                                                     ? 0x17U
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (7U 
                                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_0)))
                                                      ? 0x18U
                                                      : 
                                                     ((4U 
                                                       == 
                                                       (7U 
                                                        & (IData)(__VdfgRegularize_h6e95ff9d_0_0)))
                                                       ? 3U
                                                       : 
                                                      ((5U 
                                                        == (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                        ? 5U
                                                        : 
                                                       ((0x0105U 
                                                         == (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                         ? 6U
                                                         : 1U)))))))
                                                  : 
                                                 ((7U 
                                                   == 
                                                   (7U 
                                                    & (IData)(__VdfgRegularize_h6e95ff9d_0_0)))
                                                   ? 2U
                                                   : 0U))
                                              : ((0x63U 
                                                  == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_controller__DOT__u_aludec__DOT__opcode))
                                                  ? 0x10U
                                                  : 0U)));
    __Vtableidx1 = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_controller__DOT__u_aludec__DOT__opcode;
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteD_raw 
        = VRV32I_System__ConstPool__TABLE_h84e63adf_0
        [__Vtableidx1];
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmSrcD 
        = VRV32I_System__ConstPool__TABLE_h2c554882_0
        [__Vtableidx1];
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcAD_raw 
        = VRV32I_System__ConstPool__TABLE_h11fb5362_0
        [__Vtableidx1];
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcBD_raw 
        = VRV32I_System__ConstPool__TABLE_hb0347273_0
        [__Vtableidx1];
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemWriteD_raw 
        = VRV32I_System__ConstPool__TABLE_h16aa4d84_0
        [__Vtableidx1];
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcD_raw 
        = VRV32I_System__ConstPool__TABLE_h5c1acdf1_0
        [__Vtableidx1];
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BranchD_raw 
        = VRV32I_System__ConstPool__TABLE_h95acb82f_0
        [__Vtableidx1];
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__PCSrcD_raw 
        = VRV32I_System__ConstPool__TABLE_hbd88711c_0
        [__Vtableidx1];
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcB_fwd 
        = ((0U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardBE))
            ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rd2E
            : ((1U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardBE))
                ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__resultW_dbg
                : ((2U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardBE))
                    ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM
                    : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rd2E)));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcA_E 
        = ((1U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcAE))
            ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcE
            : ((2U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcAE))
                ? 0U : ((0U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardAE))
                         ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rd1E
                         : ((1U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardAE))
                             ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__resultW_dbg
                             : ((2U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardAE))
                                 ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM
                                 : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rd1E)))));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcB_E 
        = ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcBE)
            ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmExtE
            : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcB_fwd);
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT____VdfgRegularize_hd1e758aa_0_0 
        = ((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcA_E 
            ^ vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcB_E) 
           >> 0x0000001fU);
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT__sum 
        = (0x00000001ffffffffULL & ((QData)((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcA_E)) 
                                    + (((0x00000010U 
                                         & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE))
                                         ? (QData)((IData)(
                                                           (~ vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcB_E)))
                                         : (QData)((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcB_E))) 
                                       + (QData)((IData)(
                                                         (1U 
                                                          & ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE) 
                                                             >> 4U)))))));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__jalrTargetE 
        = ((8U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE))
            ? ((4U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE))
                ? 0U : ((2U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE))
                         ? 0U : ((1U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE))
                                  ? 0U : (1U & (~ (IData)(
                                                          (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT__sum 
                                                           >> 0x00000020U)))))))
            : ((4U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE))
                ? ((2U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE))
                    ? ((1U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE))
                        ? (1U & ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT____VdfgRegularize_hd1e758aa_0_0)
                                  ? (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcA_E 
                                     >> 0x0000001fU)
                                  : (IData)((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT__sum 
                                             >> 0x0000001fU))))
                        : VL_SHIFTRS_III(32,32,5, vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcA_E, 
                                         (0x0000001fU 
                                          & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcB_E)))
                    : ((1U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE))
                        ? (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcA_E 
                           >> (0x0000001fU & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcB_E))
                        : (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcA_E 
                           << (0x0000001fU & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcB_E))))
                : ((2U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE))
                    ? ((1U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE))
                        ? (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcA_E 
                           ^ vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcB_E)
                        : (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcA_E 
                           & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcB_E))
                    : ((1U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE))
                        ? (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcA_E 
                           | vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcB_E)
                        : (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT__sum)))));
    vlSelfRef.MemAddr = ((IData)(vlSelfRef.MemWrite)
                          ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM
                          : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__jalrTargetE);
    __Vtableidx2 = ((((((0U == vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__jalrTargetE) 
                        << 3U) | (4U & (((~ ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT____VdfgRegularize_hd1e758aa_0_0) 
                                             ^ ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE) 
                                                >> 4U))) 
                                         & ((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcA_E 
                                             >> 0x0000001fU) 
                                            ^ (IData)(
                                                      (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT__sum 
                                                       >> 0x0000001fU)))) 
                                        << 2U))) | 
                      ((2U & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__jalrTargetE 
                              >> 0x0000001eU)) | (1U 
                                                  & (IData)(
                                                            (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT__sum 
                                                             >> 0x00000020U))))) 
                     << 4U) | (((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3E) 
                                << 1U) | (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BranchE)));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BtakenE 
        = VRV32I_System__ConstPool__TABLE_h1aa3e2e8_0
        [__Vtableidx2];
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcSrcE_act_dbg 
        = (((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validE) 
            & (2U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__PCSrcE)))
            ? 2U : (((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validE) 
                     & (((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BranchE) 
                         & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BtakenE)) 
                        | ((~ (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BranchE)) 
                           & (1U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__PCSrcE)))))
                     ? 1U : 0U));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__flushE 
        = ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__stallF) 
           | (0U != (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcSrcE_act_dbg)));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcNextF 
        = ((1U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcSrcE_act_dbg))
            ? (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmExtE 
               + vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcE)
            : ((2U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcSrcE_act_dbg))
                ? (0xfffffffeU & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__jalrTargetE)
                : ((IData)(4U) + vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcRegF)));
}

VL_ATTR_COLD void VRV32I_System___024root___eval_stl(VRV32I_System___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___eval_stl\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        VRV32I_System___024root___stl_sequent__TOP__0(vlSelf);
        VRV32I_System___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool VRV32I_System___024root___eval_phase__stl(VRV32I_System___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___eval_phase__stl\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    VRV32I_System___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VRV32I_System___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = VRV32I_System___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        VRV32I_System___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool VRV32I_System___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VRV32I_System___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(VRV32I_System___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge reset)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VRV32I_System___024root____Vm_traceActivitySetAll(VRV32I_System___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root____Vm_traceActivitySetAll\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
}

VL_ATTR_COLD void VRV32I_System___024root___ctor_var_reset(VRV32I_System___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___ctor_var_reset\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4211327832146562899ull);
    vlSelf->MemWrite = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6222392603918024337ull);
    vlSelf->MemAddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14206314125122513421ull);
    vlSelf->MemWData = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1974828681644811998ull);
    vlSelf->ByteEnable = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4817300274068045710ull);
    vlSelf->inst_dbg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8241128537604146789ull);
    vlSelf->data_r_dbg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2954666146536015296ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__stallF = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13368308449265788638ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__flushE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15285961709829568718ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardAE = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10159653408196549228ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardBE = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6730003907269307248ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcD = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11881799474903621739ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcE = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11152766949668521033ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__resultW_dbg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 903296201341028987ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcSrcE_act_dbg = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3026135888161980129ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__tohost_csr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4426786965043163433ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2420906405844295588ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdPcF_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5192580683716026360ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdPcPlus4F_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13347428343759429929ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdInstrF_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9686801082016413007ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcRegF = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14199640142721519413ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__respPcF_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2439389503523156988ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__respPcPlus4F_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17957337398120137373ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__respValidF_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5007079933282427205ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__killRespF_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12909403248251346081ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcNextF = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8622886360087607077ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__jalrTargetE = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9504849127207715425ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__fetch_resp_valid_raw = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10273648192863807801ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4D = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13643282689576881056ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11393931158005357316ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 629130262654231639ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 37855156315516079ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9471149813823197421ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteD_raw = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4829219589013917033ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemWriteD_raw = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2993999283019044294ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__BranchD_raw = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16384438658404889108ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcBD_raw = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7781525807913557090ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmSrcD = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11135400513066549883ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcAD_raw = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11399625950973835487ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcD_raw = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17037318820155523717ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__PCSrcD_raw = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14329402727191184623ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteW = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16763397336568616552ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14997188159522504167ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcE = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2096906217752367212ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7400388677111317400ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemWriteE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12780308104428401430ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__BranchE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 639083027013642538ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcBE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1461796569505708750ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcAE = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1886342116159779765ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__PCSrcE = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14914598873451135138ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17582137017047059267ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2988147464519772218ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__rd1E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16097328200351514579ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__rd2E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1979965654209346771ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmExtE = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5736585644836777181ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1E = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7035162148350239550ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2E = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14726160450532624619ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdE = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7457046321558828515ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3E = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14951738401021338403ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__validE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13547236705238958666ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__validM = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4868037592196383174ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteM = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18052300199296145726ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcM = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8765449058664326872ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4M = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3988895847031079786ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15376923801275619282ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__WriteDataM = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14341613521655042127ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdM = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4327836789739332533ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15708168527109345430ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcB_fwd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 475603353522020519ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcA_E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11014541299546390575ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcB_E = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4612056573495273185ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__BtakenE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1915830947920188298ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreValid_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8497232148789074519ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreAddr_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10236427849300381814ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreData_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7081512612724011370ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreBE_r = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 648331952092244171ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemRData_bypassed = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7328695638967358066ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__BE_WD_M = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9259843743489541371ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__validW = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8782462068252746094ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcW = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1955814413138305424ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4W = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10213097982963237281ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultW = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17937970933740637838ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__ReadDataW = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8711161738981169986ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT____VdfgRegularize_h3a653db9_0_0 = 0;
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_controller__DOT__u_aludec__DOT__opcode = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 7040405681977165636ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_controller__DOT__u_aludec__DOT__ALUControl = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17859998082118538605ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13823197039253309819ull);
    }
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT__sum = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 12455918479617150241ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT____VdfgRegularize_hd1e758aa_0_0 = 0;
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift8 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10578208448483527991ull);
    vlSelf->RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift16 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12412926320148063220ull);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->RV32I_System__DOT__imem_dmem__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12940685487632611132ull);
    }
    vlSelf->RV32I_System__DOT__imem_dmem__DOT__read_data0_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4200434497949653824ull);
    vlSelf->RV32I_System__DOT__imem_dmem__DOT__read_data1_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3874001039512766477ull);
    vlSelf->RV32I_System__DOT__imem_dmem__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6891969799880606010ull);
    vlSelf->__VdlyVal__RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem__v0 = 0;
    vlSelf->__VdlyDim0__RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem__v0 = 0;
    vlSelf->__VdlySet__RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem__v0 = 0;
    vlSelf->__VdlyVal__RV32I_System__DOT__imem_dmem__DOT__mem__v0 = 0;
    vlSelf->__VdlyDim0__RV32I_System__DOT__imem_dmem__DOT__mem__v0 = 0;
    vlSelf->__VdlySet__RV32I_System__DOT__imem_dmem__DOT__mem__v0 = 0;
    vlSelf->__VdlyVal__RV32I_System__DOT__imem_dmem__DOT__mem__v1 = 0;
    vlSelf->__VdlyDim0__RV32I_System__DOT__imem_dmem__DOT__mem__v1 = 0;
    vlSelf->__VdlySet__RV32I_System__DOT__imem_dmem__DOT__mem__v1 = 0;
    vlSelf->__VdlyVal__RV32I_System__DOT__imem_dmem__DOT__mem__v2 = 0;
    vlSelf->__VdlyDim0__RV32I_System__DOT__imem_dmem__DOT__mem__v2 = 0;
    vlSelf->__VdlySet__RV32I_System__DOT__imem_dmem__DOT__mem__v2 = 0;
    vlSelf->__VdlyVal__RV32I_System__DOT__imem_dmem__DOT__mem__v3 = 0;
    vlSelf->__VdlyDim0__RV32I_System__DOT__imem_dmem__DOT__mem__v3 = 0;
    vlSelf->__VdlySet__RV32I_System__DOT__imem_dmem__DOT__mem__v3 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
