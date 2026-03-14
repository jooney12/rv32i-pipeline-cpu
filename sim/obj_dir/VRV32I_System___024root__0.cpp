// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VRV32I_System.h for the primary calling header

#include "VRV32I_System__pch.h"

void VRV32I_System___024root___eval_triggers_vec__act(VRV32I_System___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___eval_triggers_vec__act\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((IData)(vlSelfRef.reset) 
                                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__reset__0))) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.clk) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
}

bool VRV32I_System___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___trigger_anySet__act\n"); );
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

void VRV32I_System___024root___nba_sequent__TOP__0(VRV32I_System___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___nba_sequent__TOP__0\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__RV32I_System__DOT__imem_dmem__DOT__mem__v0 = 0U;
    vlSelfRef.__VdlySet__RV32I_System__DOT__imem_dmem__DOT__mem__v1 = 0U;
    vlSelfRef.__VdlySet__RV32I_System__DOT__imem_dmem__DOT__mem__v2 = 0U;
    vlSelfRef.__VdlySet__RV32I_System__DOT__imem_dmem__DOT__mem__v3 = 0U;
    vlSelfRef.__VdlySet__RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem__v0 = 0U;
    if (vlSelfRef.MemWrite) {
        vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__i = 4U;
        if ((1U & (IData)(vlSelfRef.ByteEnable))) {
            vlSelfRef.__VdlyVal__RV32I_System__DOT__imem_dmem__DOT__mem__v0 
                = (0x000000ffU & vlSelfRef.MemWData);
            vlSelfRef.__VdlyDim0__RV32I_System__DOT__imem_dmem__DOT__mem__v0 
                = (0x00000fffU & (vlSelfRef.MemAddr 
                                  >> 2U));
            vlSelfRef.__VdlySet__RV32I_System__DOT__imem_dmem__DOT__mem__v0 = 1U;
        }
        if ((2U & (IData)(vlSelfRef.ByteEnable))) {
            vlSelfRef.__VdlyVal__RV32I_System__DOT__imem_dmem__DOT__mem__v1 
                = (0x000000ffU & (vlSelfRef.MemWData 
                                  >> 8U));
            vlSelfRef.__VdlyDim0__RV32I_System__DOT__imem_dmem__DOT__mem__v1 
                = (0x00000fffU & (vlSelfRef.MemAddr 
                                  >> 2U));
            vlSelfRef.__VdlySet__RV32I_System__DOT__imem_dmem__DOT__mem__v1 = 1U;
        }
        if ((4U & (IData)(vlSelfRef.ByteEnable))) {
            vlSelfRef.__VdlyVal__RV32I_System__DOT__imem_dmem__DOT__mem__v2 
                = (0x000000ffU & (vlSelfRef.MemWData 
                                  >> 0x10U));
            vlSelfRef.__VdlyDim0__RV32I_System__DOT__imem_dmem__DOT__mem__v2 
                = (0x00000fffU & (vlSelfRef.MemAddr 
                                  >> 2U));
            vlSelfRef.__VdlySet__RV32I_System__DOT__imem_dmem__DOT__mem__v2 = 1U;
        }
        if ((8U & (IData)(vlSelfRef.ByteEnable))) {
            vlSelfRef.__VdlyVal__RV32I_System__DOT__imem_dmem__DOT__mem__v3 
                = (vlSelfRef.MemWData >> 0x18U);
            vlSelfRef.__VdlyDim0__RV32I_System__DOT__imem_dmem__DOT__mem__v3 
                = (0x00000fffU & (vlSelfRef.MemAddr 
                                  >> 2U));
            vlSelfRef.__VdlySet__RV32I_System__DOT__imem_dmem__DOT__mem__v3 = 1U;
        }
    }
    if (((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteW) 
         & (0U != (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW)))) {
        vlSelfRef.__VdlyVal__RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem__v0 
            = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__resultW_dbg;
        vlSelfRef.__VdlyDim0__RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem__v0 
            = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW;
        vlSelfRef.__VdlySet__RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem__v0 = 1U;
    }
    vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__read_data1_reg 
        = vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__mem
        [(0x00000fffU & (vlSelfRef.MemAddr >> 2U))];
    vlSelfRef.data_r_dbg = vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__read_data1_reg;
}

extern const VlUnpacked<CData/*0:0*/, 256> VRV32I_System__ConstPool__TABLE_h1aa3e2e8_0;
extern const VlUnpacked<CData/*0:0*/, 128> VRV32I_System__ConstPool__TABLE_h84e63adf_0;
extern const VlUnpacked<CData/*2:0*/, 128> VRV32I_System__ConstPool__TABLE_h2c554882_0;
extern const VlUnpacked<CData/*1:0*/, 128> VRV32I_System__ConstPool__TABLE_h11fb5362_0;
extern const VlUnpacked<CData/*0:0*/, 128> VRV32I_System__ConstPool__TABLE_hb0347273_0;
extern const VlUnpacked<CData/*0:0*/, 128> VRV32I_System__ConstPool__TABLE_h16aa4d84_0;
extern const VlUnpacked<CData/*1:0*/, 128> VRV32I_System__ConstPool__TABLE_h5c1acdf1_0;
extern const VlUnpacked<CData/*0:0*/, 128> VRV32I_System__ConstPool__TABLE_h95acb82f_0;
extern const VlUnpacked<CData/*1:0*/, 128> VRV32I_System__ConstPool__TABLE_hbd88711c_0;

void VRV32I_System___024root___nba_sequent__TOP__1(VRV32I_System___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___nba_sequent__TOP__1\n"); );
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
    CData/*0:0*/ __Vdly__RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r;
    __Vdly__RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r = 0;
    // Body
    __Vdly__RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r 
        = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r;
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validE 
        = ((1U & (~ ((IData)(vlSelfRef.reset) | (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__flushE)))) 
           && (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD));
    if (((IData)(vlSelfRef.reset) | (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__flushE))) {
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__PCSrcE = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2E = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1E = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcAE = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmExtE = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcE = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rd2E = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rd1E = 0U;
    } else {
        if (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD) {
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__PCSrcE 
                = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__PCSrcD_raw;
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE 
                = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_controller__DOT__u_aludec__DOT__ALUControl;
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcAE 
                = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcAD_raw;
        } else {
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__PCSrcE = 0U;
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE = 0U;
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcAE = 0U;
        }
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2E 
            = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1E 
            = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmExtE 
            = ((4U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmSrcD))
                ? ((2U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmSrcD))
                    ? 0U : ((1U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmSrcD))
                             ? 0U : (0xfffff000U & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD)))
                : ((2U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmSrcD))
                    ? ((1U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmSrcD))
                        ? ((((0x00000ffeU & ((- (IData)(
                                                        (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                                         >> 0x0000001fU))) 
                                             << 1U)) 
                             | (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                >> 0x0000001fU)) << 0x00000014U) 
                           | ((((0x000001feU & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                                >> 0x0000000bU)) 
                                | (1U & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                         >> 0x00000014U))) 
                               << 0x0000000bU) | (0x000007feU 
                                                  & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                                     >> 0x00000014U))))
                        : (((- (IData)((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                        >> 0x0000001fU))) 
                            << 0x0000000dU) | ((((2U 
                                                  & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                                     >> 0x0000001eU)) 
                                                 | (1U 
                                                    & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                                       >> 7U))) 
                                                << 0x0000000bU) 
                                               | ((0x000007e0U 
                                                   & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                                      >> 0x00000014U)) 
                                                  | (0x0000001eU 
                                                     & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                                        >> 7U))))))
                    : ((1U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmSrcD))
                        ? (((- (IData)((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                        >> 0x0000001fU))) 
                            << 0x0000000cU) | ((0x00000fe0U 
                                                & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                                   >> 0x00000014U)) 
                                               | (0x0000001fU 
                                                  & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                                     >> 7U))))
                        : (((- (IData)((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                        >> 0x0000001fU))) 
                            << 0x0000000cU) | (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                               >> 0x00000014U)))));
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcE 
            = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcD;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rd2E 
            = (((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT____VdfgRegularize_h3a653db9_0_0) 
                & ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW) 
                   == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D)))
                ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__resultW_dbg
                : ((0U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D))
                    ? 0U : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem
                   [vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D]));
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rd1E 
            = (((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT____VdfgRegularize_h3a653db9_0_0) 
                & ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW) 
                   == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D)))
                ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__resultW_dbg
                : ((0U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D))
                    ? 0U : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem
                   [vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D]));
    }
    if (vlSelfRef.reset) {
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreBE_r = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__respValidF_r = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreData_r = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__killRespF_r = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__WriteDataM = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcW = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreAddr_r = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultW = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4W = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ReadDataW = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__tohost_csr = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcM = 0U;
    } else {
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreBE_r 
            = vlSelfRef.ByteEnable;
        if ((1U & (~ (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__stallF)))) {
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__respValidF_r = 1U;
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__killRespF_r = 0U;
        }
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreData_r 
            = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BE_WD_M;
        if ((0U != (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcSrcE_act_dbg))) {
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__killRespF_r = 1U;
        }
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__WriteDataM 
            = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcB_fwd;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcW 
            = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcM;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreAddr_r 
            = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultW 
            = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4W 
            = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4M;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ReadDataW 
            = ((4U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M))
                ? ((2U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M))
                    ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemRData_bypassed
                    : ((1U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M))
                        ? (0x0000ffffU & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift16)
                        : (0x000000ffU & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift8)))
                : ((2U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M))
                    ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemRData_bypassed
                    : ((1U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M))
                        ? (((- (IData)((1U & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift16 
                                              >> 0x0000000fU)))) 
                            << 0x00000010U) | (0x0000ffffU 
                                               & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift16))
                        : (((- (IData)((1U & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift8 
                                              >> 7U)))) 
                            << 8U) | (0x000000ffU & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift8)))));
        if (((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteW) 
             & (0x1fU == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW)))) {
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__tohost_csr 
                = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__resultW_dbg;
        }
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcM 
            = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcE;
    }
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcE 
        = (((IData)(vlSelfRef.reset) | (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__flushE))
            ? 0U : ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD)
                     ? (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcD_raw)
                     : 0U));
    if (vlSelfRef.reset) {
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcD = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4M = 0U;
    } else {
        if ((0U != (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcSrcE_act_dbg))) {
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcD = 0U;
        } else if ((1U & (~ (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__stallF)))) {
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcD 
                = ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r)
                    ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdPcF_r
                    : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__respPcF_r);
        }
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM 
            = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__jalrTargetE;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4M 
            = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4E;
    }
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4E 
        = (((IData)(vlSelfRef.reset) | (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__flushE))
            ? 0U : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4D);
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M 
        = ((IData)(vlSelfRef.reset) ? 0U : (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3E));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3E 
        = (((IData)(vlSelfRef.reset) | (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__flushE))
            ? 0U : (7U & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                          >> 0x0000000cU)));
    if (vlSelfRef.reset) {
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdM = 0U;
    } else {
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW 
            = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdM;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdM 
            = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdE;
    }
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdE 
        = (((IData)(vlSelfRef.reset) | (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__flushE))
            ? 0U : ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD)
                     ? (0x0000001fU & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                       >> 7U)) : 0U));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BranchE 
        = ((1U & (~ ((IData)(vlSelfRef.reset) | (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__flushE)))) 
           && ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BranchD_raw) 
               & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD)));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreValid_r 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.MemWrite));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcBE 
        = ((1U & (~ ((IData)(vlSelfRef.reset) | (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__flushE)))) 
           && ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcBD_raw) 
               & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD)));
    vlSelfRef.MemWrite = ((1U & (~ (IData)(vlSelfRef.reset))) 
                          && (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemWriteE));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__resultW_dbg 
        = ((1U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcW))
            ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ReadDataW
            : ((2U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcW))
                ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4W
                : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultW));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteW 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteM));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemWriteE 
        = ((1U & (~ ((IData)(vlSelfRef.reset) | (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__flushE)))) 
           && ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemWriteD_raw) 
               & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD)));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BE_WD_M 
        = VL_SHIFTL_III(32,32,32, vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__WriteDataM, 
                        VL_SHIFTL_III(32,32,32, (3U 
                                                 & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM), 3U));
    __VdfgRegularize_h6e95ff9d_0_15 = (0x0000000fU 
                                       & ((1U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M))
                                           ? ((2U & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM)
                                               ? 0x0cU
                                               : 3U)
                                           : ((IData)(1U) 
                                              << (3U 
                                                  & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM))));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteM 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteE));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT____VdfgRegularize_h3a653db9_0_0 
        = ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteW) 
           & (0U != (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW)));
    vlSelfRef.MemWData = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BE_WD_M;
    vlSelfRef.ByteEnable = ((4U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M))
                             ? ((2U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M))
                                 ? 0U : (IData)(__VdfgRegularize_h6e95ff9d_0_15))
                             : ((2U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M))
                                 ? ((1U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M))
                                     ? 0U : 0x0fU) : (IData)(__VdfgRegularize_h6e95ff9d_0_15)));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteE 
        = ((1U & (~ ((IData)(vlSelfRef.reset) | (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__flushE)))) 
           && ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteD_raw) 
               & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD)));
    if (vlSelfRef.reset) {
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4D = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD = 0U;
        __Vdly__RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdPcF_r = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdPcPlus4F_r = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdInstrF_r = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__respPcF_r = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__respPcPlus4F_r = 0U;
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcRegF = 0x10000000U;
    } else {
        if ((0U != (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcSrcE_act_dbg))) {
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4D = 0U;
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD = 0U;
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD = 0U;
        } else if ((1U & (~ (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__stallF)))) {
            if (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r) {
                vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4D 
                    = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdPcPlus4F_r;
                vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                    = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdInstrF_r;
            } else {
                vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4D 
                    = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__respPcPlus4F_r;
                vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                    = vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__read_data0_reg;
            }
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD 
                = ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r) 
                   | (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__fetch_resp_valid_raw));
        }
        if ((((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__stallF) 
              & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__fetch_resp_valid_raw)) 
             & (~ (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r)))) {
            __Vdly__RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r = 1U;
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdPcF_r 
                = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__respPcF_r;
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdPcPlus4F_r 
                = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__respPcPlus4F_r;
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdInstrF_r 
                = vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__read_data0_reg;
        }
        if (((~ (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__stallF)) 
             & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r))) {
            __Vdly__RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r = 0U;
        }
        if ((1U & (~ (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__stallF)))) {
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__respPcF_r 
                = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcRegF;
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__respPcPlus4F_r 
                = ((IData)(4U) + vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcRegF);
        }
        if ((0U != (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcSrcE_act_dbg))) {
            __Vdly__RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r = 0U;
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcRegF 
                = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcNextF;
        } else if ((1U & (~ (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__stallF)))) {
            vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcRegF 
                = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcNextF;
        }
    }
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
    __VdfgRegularize_h6e95ff9d_0_0 = ((0x000003f8U 
                                       & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                          >> 0x00000016U)) 
                                      | (7U & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                               >> 0x0000000cU)));
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
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__fetch_resp_valid_raw 
        = ((~ (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__killRespF_r)) 
           & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__respValidF_r));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r 
        = __Vdly__RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r;
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__stallF 
        = ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validE) 
           & ((1U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcE)) 
              & ((((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdE) 
                   == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D)) 
                  & (0U != (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D))) 
                 | (((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdE) 
                     == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D)) 
                    & (0U != (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D))))));
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

void VRV32I_System___024root___nba_sequent__TOP__2(VRV32I_System___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___nba_sequent__TOP__2\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem__v0) {
        vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[vlSelfRef.__VdlyDim0__RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem__v0] 
            = vlSelfRef.__VdlyVal__RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem__v0;
    }
    vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__read_data0_reg 
        = vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__mem
        [(0x00000fffU & (vlSelfRef.pc >> 2U))];
    if (vlSelfRef.__VdlySet__RV32I_System__DOT__imem_dmem__DOT__mem__v0) {
        vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__mem[vlSelfRef.__VdlyDim0__RV32I_System__DOT__imem_dmem__DOT__mem__v0] 
            = ((0xffffff00U & vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__mem
                [vlSelfRef.__VdlyDim0__RV32I_System__DOT__imem_dmem__DOT__mem__v0]) 
               | (IData)(vlSelfRef.__VdlyVal__RV32I_System__DOT__imem_dmem__DOT__mem__v0));
    }
    if (vlSelfRef.__VdlySet__RV32I_System__DOT__imem_dmem__DOT__mem__v1) {
        vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__mem[vlSelfRef.__VdlyDim0__RV32I_System__DOT__imem_dmem__DOT__mem__v1] 
            = ((0xffff00ffU & vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__mem
                [vlSelfRef.__VdlyDim0__RV32I_System__DOT__imem_dmem__DOT__mem__v1]) 
               | ((IData)(vlSelfRef.__VdlyVal__RV32I_System__DOT__imem_dmem__DOT__mem__v1) 
                  << 8U));
    }
    if (vlSelfRef.__VdlySet__RV32I_System__DOT__imem_dmem__DOT__mem__v2) {
        vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__mem[vlSelfRef.__VdlyDim0__RV32I_System__DOT__imem_dmem__DOT__mem__v2] 
            = ((0xff00ffffU & vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__mem
                [vlSelfRef.__VdlyDim0__RV32I_System__DOT__imem_dmem__DOT__mem__v2]) 
               | ((IData)(vlSelfRef.__VdlyVal__RV32I_System__DOT__imem_dmem__DOT__mem__v2) 
                  << 0x00000010U));
    }
    if (vlSelfRef.__VdlySet__RV32I_System__DOT__imem_dmem__DOT__mem__v3) {
        vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__mem[vlSelfRef.__VdlyDim0__RV32I_System__DOT__imem_dmem__DOT__mem__v3] 
            = ((0x00ffffffU & vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__mem
                [vlSelfRef.__VdlyDim0__RV32I_System__DOT__imem_dmem__DOT__mem__v3]) 
               | ((IData)(vlSelfRef.__VdlyVal__RV32I_System__DOT__imem_dmem__DOT__mem__v3) 
                  << 0x00000018U));
    }
    vlSelfRef.inst_dbg = vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__read_data0_reg;
}

void VRV32I_System___024root___nba_comb__TOP__0(VRV32I_System___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___nba_comb__TOP__0\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemRData_bypassed 
        = (((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreValid_r) 
            & ((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreAddr_r 
                >> 2U) == (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM 
                           >> 2U))) ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreData_r
            : vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__read_data1_reg);
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift8 
        = VL_SHIFTR_III(32,32,32, vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemRData_bypassed, 
                        VL_SHIFTL_III(32,32,32, (3U 
                                                 & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM), 3U));
    vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift16 
        = VL_SHIFTR_III(32,32,32, vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemRData_bypassed, 
                        VL_SHIFTL_III(32,32,32, (1U 
                                                 & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM 
                                                    >> 1U)), 4U));
}

void VRV32I_System___024root___nba_sequent__TOP__3(VRV32I_System___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___nba_sequent__TOP__3\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pc = vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcRegF;
}

void VRV32I_System___024root___eval_nba(VRV32I_System___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___eval_nba\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        VRV32I_System___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        VRV32I_System___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        VRV32I_System___024root___nba_sequent__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        VRV32I_System___024root___nba_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        VRV32I_System___024root___nba_sequent__TOP__3(vlSelf);
    }
}

void VRV32I_System___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VRV32I_System___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool VRV32I_System___024root___eval_phase__act(VRV32I_System___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___eval_phase__act\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VRV32I_System___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VRV32I_System___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    VRV32I_System___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void VRV32I_System___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool VRV32I_System___024root___eval_phase__nba(VRV32I_System___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___eval_phase__nba\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = VRV32I_System___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        VRV32I_System___024root___eval_nba(vlSelf);
        VRV32I_System___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void VRV32I_System___024root___eval(VRV32I_System___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___eval\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VRV32I_System___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("../rtl/RV32I_System.v", 1, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VRV32I_System___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("../rtl/RV32I_System.v", 1, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = VRV32I_System___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = VRV32I_System___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void VRV32I_System___024root___eval_debug_assertions(VRV32I_System___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root___eval_debug_assertions\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");
    }
}
#endif  // VL_DEBUG
