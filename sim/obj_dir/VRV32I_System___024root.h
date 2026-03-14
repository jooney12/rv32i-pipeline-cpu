// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VRV32I_System.h for the primary calling header

#ifndef VERILATED_VRV32I_SYSTEM___024ROOT_H_
#define VERILATED_VRV32I_SYSTEM___024ROOT_H_  // guard

#include "verilated.h"


class VRV32I_System__Syms;

class alignas(VL_CACHE_LINE_BYTES) VRV32I_System___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(reset,0,0);
        VL_OUT8(MemWrite,0,0);
        VL_OUT8(ByteEnable,3,0);
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__stallF;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__flushE;
        CData/*1:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardAE;
        CData/*1:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardBE;
        CData/*1:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcSrcE_act_dbg;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__respValidF_r;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__killRespF_r;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__fetch_resp_valid_raw;
        CData/*4:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D;
        CData/*4:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteD_raw;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemWriteD_raw;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__BranchD_raw;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcBD_raw;
        CData/*2:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmSrcD;
        CData/*1:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcAD_raw;
        CData/*1:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcD_raw;
        CData/*1:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__PCSrcD_raw;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteW;
        CData/*4:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW;
        CData/*1:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcE;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteE;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemWriteE;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__BranchE;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcBE;
        CData/*1:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcAE;
        CData/*1:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__PCSrcE;
        CData/*4:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE;
        CData/*4:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1E;
        CData/*4:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2E;
        CData/*4:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdE;
        CData/*2:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3E;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__validE;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__validM;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteM;
        CData/*1:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcM;
        CData/*4:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdM;
        CData/*2:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__BtakenE;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreValid_r;
        CData/*3:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreBE_r;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__validW;
        CData/*1:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcW;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT____VdfgRegularize_h3a653db9_0_0;
        CData/*6:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_controller__DOT__u_aludec__DOT__opcode;
        CData/*4:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_controller__DOT__u_aludec__DOT__ALUControl;
        CData/*0:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT____VdfgRegularize_hd1e758aa_0_0;
        CData/*4:0*/ __VdlyDim0__RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem__v0;
        CData/*0:0*/ __VdlySet__RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem__v0;
        CData/*7:0*/ __VdlyVal__RV32I_System__DOT__imem_dmem__DOT__mem__v0;
        CData/*0:0*/ __VdlySet__RV32I_System__DOT__imem_dmem__DOT__mem__v0;
        CData/*7:0*/ __VdlyVal__RV32I_System__DOT__imem_dmem__DOT__mem__v1;
        CData/*0:0*/ __VdlySet__RV32I_System__DOT__imem_dmem__DOT__mem__v1;
        CData/*7:0*/ __VdlyVal__RV32I_System__DOT__imem_dmem__DOT__mem__v2;
        CData/*0:0*/ __VdlySet__RV32I_System__DOT__imem_dmem__DOT__mem__v2;
        CData/*7:0*/ __VdlyVal__RV32I_System__DOT__imem_dmem__DOT__mem__v3;
        CData/*0:0*/ __VdlySet__RV32I_System__DOT__imem_dmem__DOT__mem__v3;
        CData/*0:0*/ __VstlFirstIteration;
    };
    struct {
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        SData/*11:0*/ __VdlyDim0__RV32I_System__DOT__imem_dmem__DOT__mem__v0;
        SData/*11:0*/ __VdlyDim0__RV32I_System__DOT__imem_dmem__DOT__mem__v1;
        SData/*11:0*/ __VdlyDim0__RV32I_System__DOT__imem_dmem__DOT__mem__v2;
        SData/*11:0*/ __VdlyDim0__RV32I_System__DOT__imem_dmem__DOT__mem__v3;
        VL_OUT(pc,31,0);
        VL_OUT(MemAddr,31,0);
        VL_OUT(MemWData,31,0);
        VL_OUT(inst_dbg,31,0);
        VL_OUT(data_r_dbg,31,0);
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcD;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcE;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__resultW_dbg;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__tohost_csr;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdPcF_r;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdPcPlus4F_r;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdInstrF_r;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcRegF;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__respPcF_r;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__respPcPlus4F_r;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcNextF;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__jalrTargetE;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4D;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4E;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__rd1E;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__rd2E;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmExtE;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4M;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__WriteDataM;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcB_fwd;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcA_E;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcB_E;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreAddr_r;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreData_r;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemRData_bypassed;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__BE_WD_M;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4W;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultW;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__ReadDataW;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift8;
        IData/*31:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift16;
        IData/*31:0*/ RV32I_System__DOT__imem_dmem__DOT__read_data0_reg;
        IData/*31:0*/ RV32I_System__DOT__imem_dmem__DOT__read_data1_reg;
        IData/*31:0*/ RV32I_System__DOT__imem_dmem__DOT__i;
        IData/*31:0*/ __VdlyVal__RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem__v0;
        IData/*31:0*/ __VactIterCount;
        QData/*32:0*/ RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT__sum;
        VlUnpacked<IData/*31:0*/, 32> RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem;
        VlUnpacked<IData/*31:0*/, 4096> RV32I_System__DOT__imem_dmem__DOT__mem;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
        VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    };

    // INTERNAL VARIABLES
    VRV32I_System__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VRV32I_System___024root(VRV32I_System__Syms* symsp, const char* namep);
    ~VRV32I_System___024root();
    VL_UNCOPYABLE(VRV32I_System___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
