// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "VRV32I_System__Syms.h"


void VRV32I_System___024root__trace_chg_0_sub_0(VRV32I_System___024root* vlSelf, VerilatedFst::Buffer* bufp);

void VRV32I_System___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root__trace_chg_0\n"); );
    // Body
    VRV32I_System___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VRV32I_System___024root*>(voidSelf);
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    VRV32I_System___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VRV32I_System___024root__trace_chg_0_sub_0(VRV32I_System___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root__trace_chg_0_sub_0\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD),32);
        bufp->chgCData(oldp+1,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdE),5);
        bufp->chgCData(oldp+2,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdM),5);
        bufp->chgCData(oldp+3,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW),5);
        bufp->chgBit(oldp+4,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__stallF));
        bufp->chgBit(oldp+5,((0U != (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcSrcE_act_dbg))));
        bufp->chgBit(oldp+6,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__flushE));
        bufp->chgCData(oldp+7,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardAE),2);
        bufp->chgCData(oldp+8,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardBE),2);
        bufp->chgIData(oldp+9,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcD),32);
        bufp->chgIData(oldp+10,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcE),32);
        bufp->chgIData(oldp+11,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__resultW_dbg),32);
        bufp->chgCData(oldp+12,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcSrcE_act_dbg),2);
        bufp->chgIData(oldp+13,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__tohost_csr),32);
        bufp->chgBit(oldp+14,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r));
        bufp->chgIData(oldp+15,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdPcF_r),32);
        bufp->chgIData(oldp+16,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdPcPlus4F_r),32);
        bufp->chgIData(oldp+17,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdInstrF_r),32);
        bufp->chgIData(oldp+18,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcRegF),32);
        bufp->chgIData(oldp+19,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__respPcF_r),32);
        bufp->chgIData(oldp+20,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__respPcPlus4F_r),32);
        bufp->chgBit(oldp+21,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__respValidF_r));
        bufp->chgBit(oldp+22,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__killRespF_r));
        bufp->chgIData(oldp+23,(((IData)(4U) + vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcRegF)),32);
        bufp->chgIData(oldp+24,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcNextF),32);
        bufp->chgIData(oldp+25,((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmExtE 
                                 + vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcE)),32);
        bufp->chgIData(oldp+26,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__jalrTargetE),32);
        bufp->chgBit(oldp+27,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__fetch_resp_valid_raw));
        bufp->chgBit(oldp+28,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r) 
                               | (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__fetch_resp_valid_raw))));
        bufp->chgIData(oldp+29,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r)
                                  ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdPcF_r
                                  : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__respPcF_r)),32);
        bufp->chgIData(oldp+30,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r)
                                  ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdPcPlus4F_r
                                  : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__respPcPlus4F_r)),32);
        bufp->chgIData(oldp+31,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4D),32);
        bufp->chgCData(oldp+32,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D),5);
        bufp->chgCData(oldp+33,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D),5);
        bufp->chgCData(oldp+34,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD)
                                  ? (0x0000001fU & 
                                     (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                      >> 7U)) : 0U)),5);
        bufp->chgCData(oldp+35,((7U & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                       >> 0x0000000cU))),3);
        bufp->chgIData(oldp+36,(((4U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmSrcD))
                                  ? ((2U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmSrcD))
                                      ? 0U : ((1U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmSrcD))
                                               ? 0U
                                               : (0xfffff000U 
                                                  & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD)))
                                  : ((2U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmSrcD))
                                      ? ((1U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmSrcD))
                                          ? ((((0x00000ffeU 
                                                & ((- (IData)(
                                                              (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                                               >> 0x0000001fU))) 
                                                   << 1U)) 
                                               | (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                                  >> 0x0000001fU)) 
                                              << 0x00000014U) 
                                             | ((((0x000001feU 
                                                   & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                                      >> 0x0000000bU)) 
                                                  | (1U 
                                                     & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                                        >> 0x00000014U))) 
                                                 << 0x0000000bU) 
                                                | (0x000007feU 
                                                   & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                                      >> 0x00000014U))))
                                          : (((- (IData)(
                                                         (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                                          >> 0x0000001fU))) 
                                              << 0x0000000dU) 
                                             | ((((2U 
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
                                          ? (((- (IData)(
                                                         (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                                          >> 0x0000001fU))) 
                                              << 0x0000000cU) 
                                             | ((0x00000fe0U 
                                                 & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                                    >> 0x00000014U)) 
                                                | (0x0000001fU 
                                                   & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                                      >> 7U))))
                                          : (((- (IData)(
                                                         (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                                          >> 0x0000001fU))) 
                                              << 0x0000000cU) 
                                             | (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                                >> 0x00000014U)))))),32);
        bufp->chgBit(oldp+37,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD));
        bufp->chgBit(oldp+38,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteD_raw));
        bufp->chgBit(oldp+39,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemWriteD_raw));
        bufp->chgBit(oldp+40,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BranchD_raw));
        bufp->chgBit(oldp+41,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcBD_raw));
        bufp->chgCData(oldp+42,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmSrcD),3);
        bufp->chgCData(oldp+43,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcAD_raw),2);
        bufp->chgCData(oldp+44,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcD_raw),2);
        bufp->chgCData(oldp+45,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__PCSrcD_raw),2);
        bufp->chgCData(oldp+46,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_controller__DOT__u_aludec__DOT__ALUControl),5);
        bufp->chgBit(oldp+47,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteD_raw) 
                               & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD))));
        bufp->chgBit(oldp+48,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemWriteD_raw) 
                               & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD))));
        bufp->chgBit(oldp+49,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BranchD_raw) 
                               & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD))));
        bufp->chgBit(oldp+50,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcBD_raw) 
                               & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD))));
        bufp->chgCData(oldp+51,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD)
                                  ? (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcAD_raw)
                                  : 0U)),2);
        bufp->chgCData(oldp+52,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD)
                                  ? (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcD_raw)
                                  : 0U)),2);
        bufp->chgCData(oldp+53,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD)
                                  ? (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__PCSrcD_raw)
                                  : 0U)),2);
        bufp->chgCData(oldp+54,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD)
                                  ? (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_controller__DOT__u_aludec__DOT__ALUControl)
                                  : 0U)),5);
        bufp->chgBit(oldp+55,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteW));
        bufp->chgBit(oldp+56,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT____VdfgRegularize_h3a653db9_0_0) 
                               & ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW) 
                                  == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D)))));
        bufp->chgBit(oldp+57,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT____VdfgRegularize_h3a653db9_0_0) 
                               & ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW) 
                                  == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D)))));
        bufp->chgCData(oldp+58,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcE),2);
        bufp->chgBit(oldp+59,((1U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcE))));
        bufp->chgBit(oldp+60,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteE));
        bufp->chgBit(oldp+61,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemWriteE));
        bufp->chgBit(oldp+62,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BranchE));
        bufp->chgBit(oldp+63,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcBE));
        bufp->chgCData(oldp+64,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcAE),2);
        bufp->chgCData(oldp+65,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__PCSrcE),2);
        bufp->chgCData(oldp+66,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE),5);
        bufp->chgIData(oldp+67,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4E),32);
        bufp->chgIData(oldp+68,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rd1E),32);
        bufp->chgIData(oldp+69,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rd2E),32);
        bufp->chgIData(oldp+70,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmExtE),32);
        bufp->chgCData(oldp+71,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1E),5);
        bufp->chgCData(oldp+72,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2E),5);
        bufp->chgCData(oldp+73,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3E),3);
        bufp->chgBit(oldp+74,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validE));
        bufp->chgBit(oldp+75,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteM));
        bufp->chgCData(oldp+76,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcM),2);
        bufp->chgIData(oldp+77,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4M),32);
        bufp->chgIData(oldp+78,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM),32);
        bufp->chgIData(oldp+79,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__WriteDataM),32);
        bufp->chgCData(oldp+80,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M),3);
        bufp->chgIData(oldp+81,(((0U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardAE))
                                  ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rd1E
                                  : ((1U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardAE))
                                      ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__resultW_dbg
                                      : ((2U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardAE))
                                          ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM
                                          : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rd1E)))),32);
        bufp->chgIData(oldp+82,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcB_fwd),32);
        bufp->chgIData(oldp+83,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcA_E),32);
        bufp->chgIData(oldp+84,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcB_E),32);
        bufp->chgBit(oldp+85,((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__jalrTargetE 
                               >> 0x0000001fU)));
        bufp->chgBit(oldp+86,((0U == vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__jalrTargetE)));
        bufp->chgBit(oldp+87,((1U & (IData)((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT__sum 
                                             >> 0x00000020U)))));
        bufp->chgBit(oldp+88,((1U & ((~ ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT____VdfgRegularize_hd1e758aa_0_0) 
                                         ^ ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE) 
                                            >> 4U))) 
                                     & ((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcA_E 
                                         >> 0x0000001fU) 
                                        ^ (IData)((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT__sum 
                                                   >> 0x0000001fU)))))));
        bufp->chgBit(oldp+89,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BtakenE));
        bufp->chgBit(oldp+90,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validE) 
                               & ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BranchE) 
                                  & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BtakenE)))));
        bufp->chgBit(oldp+91,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validE) 
                               & ((~ (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BranchE)) 
                                  & (1U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__PCSrcE))))));
        bufp->chgBit(oldp+92,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validE) 
                               & (2U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__PCSrcE)))));
        bufp->chgBit(oldp+93,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreValid_r));
        bufp->chgIData(oldp+94,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreAddr_r),32);
        bufp->chgIData(oldp+95,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreData_r),32);
        bufp->chgCData(oldp+96,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreBE_r),4);
        bufp->chgBit(oldp+97,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreValid_r) 
                               & ((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreAddr_r 
                                   >> 2U) == (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM 
                                              >> 2U)))));
        bufp->chgIData(oldp+98,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BE_WD_M),32);
        bufp->chgCData(oldp+99,((3U & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM)),2);
        bufp->chgCData(oldp+100,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcW),2);
        bufp->chgIData(oldp+101,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4W),32);
        bufp->chgIData(oldp+102,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultW),32);
        bufp->chgIData(oldp+103,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ReadDataW),32);
        bufp->chgQData(oldp+104,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT__sum),33);
        bufp->chgBit(oldp+106,((1U & ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT____VdfgRegularize_hd1e758aa_0_0)
                                       ? (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcA_E 
                                          >> 0x0000001fU)
                                       : (IData)((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT__sum 
                                                  >> 0x0000001fU))))));
        bufp->chgBit(oldp+107,((1U & (~ (IData)((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT__sum 
                                                 >> 0x00000020U))))));
        bufp->chgCData(oldp+108,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_controller__DOT__u_aludec__DOT__opcode),7);
        bufp->chgCData(oldp+109,((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                  >> 0x00000019U)),7);
        bufp->chgBit(oldp+110,((((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdE) 
                                 == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D)) 
                                & (0U != (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D)))));
        bufp->chgBit(oldp+111,((((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdE) 
                                 == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D)) 
                                & (0U != (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D)))));
        bufp->chgBit(oldp+112,((1U & (~ (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__stallF)))));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity[2U])))) {
        bufp->chgIData(oldp+113,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r)
                                   ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdInstrF_r
                                   : vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__read_data0_reg)),32);
        bufp->chgIData(oldp+114,(((0U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D))
                                   ? 0U : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem
                                  [vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D])),32);
        bufp->chgIData(oldp+115,(((0U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D))
                                   ? 0U : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem
                                  [vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D])),32);
        bufp->chgIData(oldp+116,((((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT____VdfgRegularize_h3a653db9_0_0) 
                                   & ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW) 
                                      == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D)))
                                   ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__resultW_dbg
                                   : ((0U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D))
                                       ? 0U : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem
                                      [vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D]))),32);
        bufp->chgIData(oldp+117,((((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT____VdfgRegularize_h3a653db9_0_0) 
                                   & ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW) 
                                      == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D)))
                                   ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__resultW_dbg
                                   : ((0U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D))
                                       ? 0U : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem
                                      [vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D]))),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+118,(vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__read_data0_reg),32);
        bufp->chgIData(oldp+119,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[0]),32);
        bufp->chgIData(oldp+120,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[1]),32);
        bufp->chgIData(oldp+121,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[2]),32);
        bufp->chgIData(oldp+122,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[3]),32);
        bufp->chgIData(oldp+123,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[4]),32);
        bufp->chgIData(oldp+124,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[5]),32);
        bufp->chgIData(oldp+125,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[6]),32);
        bufp->chgIData(oldp+126,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[7]),32);
        bufp->chgIData(oldp+127,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[8]),32);
        bufp->chgIData(oldp+128,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[9]),32);
        bufp->chgIData(oldp+129,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[10]),32);
        bufp->chgIData(oldp+130,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[11]),32);
        bufp->chgIData(oldp+131,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[12]),32);
        bufp->chgIData(oldp+132,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[13]),32);
        bufp->chgIData(oldp+133,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[14]),32);
        bufp->chgIData(oldp+134,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[15]),32);
        bufp->chgIData(oldp+135,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[16]),32);
        bufp->chgIData(oldp+136,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[17]),32);
        bufp->chgIData(oldp+137,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[18]),32);
        bufp->chgIData(oldp+138,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[19]),32);
        bufp->chgIData(oldp+139,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[20]),32);
        bufp->chgIData(oldp+140,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[21]),32);
        bufp->chgIData(oldp+141,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[22]),32);
        bufp->chgIData(oldp+142,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[23]),32);
        bufp->chgIData(oldp+143,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[24]),32);
        bufp->chgIData(oldp+144,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[25]),32);
        bufp->chgIData(oldp+145,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[26]),32);
        bufp->chgIData(oldp+146,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[27]),32);
        bufp->chgIData(oldp+147,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[28]),32);
        bufp->chgIData(oldp+148,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[29]),32);
        bufp->chgIData(oldp+149,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[30]),32);
        bufp->chgIData(oldp+150,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[31]),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgIData(oldp+151,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemRData_bypassed),32);
        bufp->chgIData(oldp+152,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift8),32);
        bufp->chgIData(oldp+153,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift16),32);
    }
    bufp->chgBit(oldp+154,(vlSelfRef.clk));
    bufp->chgBit(oldp+155,(vlSelfRef.reset));
    bufp->chgIData(oldp+156,(vlSelfRef.pc),32);
    bufp->chgBit(oldp+157,(vlSelfRef.MemWrite));
    bufp->chgIData(oldp+158,(vlSelfRef.MemAddr),32);
    bufp->chgIData(oldp+159,(vlSelfRef.MemWData),32);
    bufp->chgCData(oldp+160,(vlSelfRef.ByteEnable),4);
    bufp->chgIData(oldp+161,(vlSelfRef.inst_dbg),32);
    bufp->chgIData(oldp+162,(vlSelfRef.data_r_dbg),32);
    bufp->chgIData(oldp+163,(vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__read_data1_reg),32);
    bufp->chgSData(oldp+164,((0x00000fffU & (vlSelfRef.pc 
                                             >> 2U))),12);
    bufp->chgSData(oldp+165,((0x00000fffU & (vlSelfRef.MemAddr 
                                             >> 2U))),12);
    bufp->chgIData(oldp+166,(((4U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M))
                               ? ((2U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M))
                                   ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemRData_bypassed
                                   : ((1U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M))
                                       ? (0x0000ffffU 
                                          & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift16)
                                       : (0x000000ffU 
                                          & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift8)))
                               : ((2U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M))
                                   ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemRData_bypassed
                                   : ((1U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M))
                                       ? (((- (IData)(
                                                      (1U 
                                                       & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift16 
                                                          >> 0x0000000fU)))) 
                                           << 0x00000010U) 
                                          | (0x0000ffffU 
                                             & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift16))
                                       : (((- (IData)(
                                                      (1U 
                                                       & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift8 
                                                          >> 7U)))) 
                                           << 8U) | 
                                          (0x000000ffU 
                                           & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift8)))))),32);
    bufp->chgIData(oldp+167,(vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__i),32);
}

void VRV32I_System___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root__trace_cleanup\n"); );
    // Body
    VRV32I_System___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VRV32I_System___024root*>(voidSelf);
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
