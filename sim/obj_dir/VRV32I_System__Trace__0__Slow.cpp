// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "VRV32I_System__Syms.h"


VL_ATTR_COLD void VRV32I_System___024root__trace_init_sub__TOP__0(VRV32I_System___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root__trace_init_sub__TOP__0\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+154,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+155,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+156,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+157,0,"MemWrite",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+158,0,"MemAddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+159,0,"MemWData",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+160,0,"ByteEnable",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+161,0,"inst_dbg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+162,0,"data_r_dbg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("RV32I_System", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+168,0,"RESET_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"MEM_AWIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+170,0,"MEM_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"IMEM_HEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+171,0,"IMEM_BIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+154,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+155,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+156,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+157,0,"MemWrite",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+158,0,"MemAddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+159,0,"MemWData",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+160,0,"ByteEnable",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+161,0,"inst_dbg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+162,0,"data_r_dbg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+172,0,"RESET_WORD_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+118,0,"inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+163,0,"MemRData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+164,0,"imem_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+165,0,"dmem_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+168,0,"RESET_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+154,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+155,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+163,0,"MemRData",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+118,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+156,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+157,0,"MemWrite",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+158,0,"MemAddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+159,0,"MemWData",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+160,0,"ByteEnable",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("i_datapath", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+168,0,"RESET_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+154,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+155,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+118,0,"instrF",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+163,0,"MemRData",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+156,0,"pcF",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+157,0,"MemWriteM",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+158,0,"MemAddrM",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+159,0,"MemWDataM",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+160,0,"ByteEnableM",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+0,0,"if_id_inst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"id_ex_rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+2,0,"ex_mem_rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+3,0,"mem_wb_rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+4,0,"stallF",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"stallD",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"flushD",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"flushE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"ForwardAE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+8,0,"ForwardBE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+9,0,"pcD",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"pcE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"resultW_dbg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"pcSrcE_act_dbg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+13,0,"tohost_csr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+14,0,"holdValidF_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"holdPcF_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"holdPcPlus4F_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"holdInstrF_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"pcRegF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"respPcF_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+20,0,"respPcPlus4F_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+21,0,"respValidF_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"killRespF_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+23,0,"pcPlus4F",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"pcNextF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+25,0,"pcTargetE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"jalrTargetE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"PCSrcE_act",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+5,0,"redirectF_kill",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"fetch_resp_valid_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"fetch_resp_pc_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+20,0,"fetch_resp_pcplus4_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+118,0,"fetch_resp_instr_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+28,0,"fetch_valid_respF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+29,0,"fetch_pc_respF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+30,0,"fetch_pcplus4_respF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+113,0,"fetch_instr_respF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+31,0,"pcPlus4D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+0,0,"instrD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+32,0,"rs1D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+33,0,"rs2D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+34,0,"rdD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+35,0,"funct3D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+114,0,"rd1D_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+115,0,"rd2D_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"rd1D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+117,0,"rd2D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"ImmExtD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+28,0,"ifid_valid_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+29,0,"ifid_pc_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+30,0,"ifid_pcplus4_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+113,0,"ifid_instr_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+37,0,"validD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"RegWriteD_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"MemWriteD_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"BranchD_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"ALUSrcBD_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+42,0,"ImmSrcD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+43,0,"ALUSrcAD_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+44,0,"ResultSrcD_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+45,0,"PCSrcD_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+46,0,"ALUControlD_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+47,0,"RegWriteD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"MemWriteD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"BranchD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"ALUSrcBD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+51,0,"ALUSrcAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+52,0,"ResultSrcD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+53,0,"PCSrcD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+54,0,"ALUControlD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+55,0,"RegWriteW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"rdW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+11,0,"ResultW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+56,0,"wbBypassRs1D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"wbBypassRs2D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"flushE_hz",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"flushE_redirect",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+58,0,"ResultSrcE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+59,0,"ResultSrcE_isLoad",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"RegWriteE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"MemWriteE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"BranchE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"ALUSrcBE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"ALUSrcAE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+65,0,"PCSrcE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+66,0,"ALUControlE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+67,0,"pcPlus4E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+68,0,"rd1E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"rd2E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+70,0,"ImmExtE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+71,0,"rs1E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+72,0,"rs2E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1,0,"rdE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+73,0,"funct3E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+74,0,"validE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+173,0,"validM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+75,0,"RegWriteM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+76,0,"ResultSrcM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+77,0,"pcPlus4M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+78,0,"ALUResultM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+79,0,"WriteDataM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"rdM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+80,0,"funct3M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+81,0,"SrcA_fwd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+82,0,"SrcB_fwd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+83,0,"SrcA_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+84,0,"SrcB_E",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"ALUResultE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+85,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"Z",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"C",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"V",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"BtakenE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"redirectBranchE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"redirectJalE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+92,0,"redirectJalrE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,0,"prevStoreValid_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+94,0,"prevStoreAddr_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+95,0,"prevStoreData_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+96,0,"prevStoreBE_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+97,0,"sameAddrStoreLoadM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+151,0,"MemRData_bypassed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+98,0,"BE_WD_M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"BE_RD_M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+99,0,"addrLast2M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+174,0,"validW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+100,0,"ResultSrcW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+101,0,"pcPlus4W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+102,0,"ALUResultW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+103,0,"ReadDataW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("i_alu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+83,0,"SrcA",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+84,0,"SrcB",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+66,0,"ALUControl",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+26,0,"ALUResult",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+85,0,"N",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"Z",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"C",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"V",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+104,0,"sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBit(c+106,0,"slt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+107,0,"sltu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("i_be", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+80,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+99,0,"Addr_Last2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+79,0,"WD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+151,0,"RD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+98,0,"BE_WD",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"BE_RD",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+160,0,"Byte_Enable",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+152,0,"rd_shift8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+153,0,"rd_shift16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("i_br", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+62,0,"Branch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+73,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+85,0,"N",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"Z",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"C",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"V",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"Btaken",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("i_controller", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+108,0,"opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+109,0,"funct7",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+35,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+38,0,"RegWrite",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+42,0,"ImmSrc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+43,0,"ALUSrcA",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+41,0,"ALUSrcB",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+46,0,"ALUControl",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+39,0,"MemWrite",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+44,0,"ResultSrc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+40,0,"Branch",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+45,0,"PCSrc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("u_aludec", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+108,0,"opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+109,0,"funct7",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+35,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+46,0,"ALUControl",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_maindec", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+108,0,"opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+38,0,"RegWrite",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+42,0,"ImmSrc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+43,0,"ALUSrcA",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+41,0,"ALUSrcB",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"MemWrite",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+44,0,"ResultSrc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+40,0,"Branch",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+45,0,"PCSrc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("i_exmem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+154,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+155,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"RegWriteE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"MemWriteE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+58,0,"ResultSrcE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+67,0,"pcPlus4E",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"ALUResultE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+82,0,"WriteDataE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"rdE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+73,0,"funct3E",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+75,0,"RegWriteM",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+157,0,"MemWriteM",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+76,0,"ResultSrcM",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+77,0,"pcPlus4M",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+78,0,"ALUResultM",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+79,0,"WriteDataM",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"rdM",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+80,0,"funct3M",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("i_ext", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+0,0,"instr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"ImmSrc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+36,0,"ImmExt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("i_fctrl", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+12,0,"PCSrcE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+5,0,"flushD",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"flushE_redirect",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"redirect",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("i_fwd", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+75,0,"RegWriteM",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"RegWriteW",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+71,0,"rs1E",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+72,0,"rs2E",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+2,0,"rdM",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+3,0,"rdW",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+7,0,"ForwardAE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+8,0,"ForwardBE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("i_hdu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+32,0,"rs1D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+33,0,"rs2D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1,0,"rdE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+59,0,"ResultSrcE_isLoad",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"validE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"stallF",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"stallD",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"flushE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+110,0,"dep_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+111,0,"dep_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"lwStall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("i_idex", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+154,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+155,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"flushE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"validD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"RegWriteD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"MemWriteD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"BranchD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"ALUSrcBD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+51,0,"ALUSrcAD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+52,0,"ResultSrcD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+53,0,"PCSrcD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+54,0,"ALUControlD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+9,0,"pcD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+31,0,"pcPlus4D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"rd1D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+117,0,"rd2D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"ImmExtD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+32,0,"rs1D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+33,0,"rs2D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+34,0,"rdD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+35,0,"funct3D",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+74,0,"validE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"RegWriteE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"MemWriteE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"BranchE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"ALUSrcBE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"ALUSrcAE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+58,0,"ResultSrcE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+65,0,"PCSrcE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+66,0,"ALUControlE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+10,0,"pcE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+67,0,"pcPlus4E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+68,0,"rd1E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"rd2E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+70,0,"ImmExtE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+71,0,"rs1E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+72,0,"rs2E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1,0,"rdE",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+73,0,"funct3E",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("i_ifid", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+154,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+155,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+112,0,"enD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"clearD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"validF",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+29,0,"pcF",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+30,0,"pcPlus4F",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+113,0,"instrF",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+37,0,"validD",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+9,0,"pcD",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+31,0,"pcPlus4D",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+0,0,"instrD",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("i_memwb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+154,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+155,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+75,0,"RegWriteM",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+76,0,"ResultSrcM",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+77,0,"pcPlus4M",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+78,0,"ALUResultM",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"ReadDataM",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"rdM",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+55,0,"RegWriteW",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+100,0,"ResultSrcW",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+101,0,"pcPlus4W",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+102,0,"ALUResultW",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+103,0,"ReadDataW",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"rdW",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("i_nextpc", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+18,0,"pcF",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+25,0,"pcTargetE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"jalrTargetE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"PCSrcE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+23,0,"pcPlus4F",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"pcNextF",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("i_wbsel", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+100,0,"ResultSrc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+102,0,"ALUResult",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+103,0,"BE_RD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+101,0,"PCPlus4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"WD",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("muxA", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+175,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+68,0,"d0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"d1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+78,0,"d2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"s",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+81,0,"y",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("muxB", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+175,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"d0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"d1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+78,0,"d2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+8,0,"s",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+82,0,"y",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("rf", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+154,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+32,0,"ra1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+33,0,"ra2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+3,0,"wa",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+11,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+114,0,"rd1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+115,0,"rd2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+175,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("mem", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+119+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("imem_dmem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+175,0,"DWIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"AWIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+170,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"MIF_HEX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+171,0,"MIF_BIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+154,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+176,0,"d0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+164,0,"addr0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+177,0,"wbe0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+178,0,"wen0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+118,0,"q0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+159,0,"d1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+165,0,"addr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+160,0,"wbe1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+157,0,"wen1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+163,0,"q1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+118,0,"read_data0_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+163,0,"read_data1_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+167,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void VRV32I_System___024root__trace_init_top(VRV32I_System___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root__trace_init_top\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VRV32I_System___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VRV32I_System___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void VRV32I_System___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void VRV32I_System___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void VRV32I_System___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void VRV32I_System___024root__trace_register(VRV32I_System___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root__trace_register\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VRV32I_System___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&VRV32I_System___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&VRV32I_System___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&VRV32I_System___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VRV32I_System___024root__trace_const_0_sub_0(VRV32I_System___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void VRV32I_System___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root__trace_const_0\n"); );
    // Body
    VRV32I_System___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VRV32I_System___024root*>(voidSelf);
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VRV32I_System___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VRV32I_System___024root__trace_const_0_sub_0(VRV32I_System___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root__trace_const_0_sub_0\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+168,(0x10000000U),32);
    bufp->fullIData(oldp+169,(0x0000000cU),32);
    bufp->fullIData(oldp+170,(0x00001000U),32);
    bufp->fullCData(oldp+171,(0U),8);
    bufp->fullIData(oldp+172,(0x04000000U),32);
    bufp->fullBit(oldp+173,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validM));
    bufp->fullBit(oldp+174,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validW));
    bufp->fullIData(oldp+175,(0x00000020U),32);
    bufp->fullIData(oldp+176,(0U),32);
    bufp->fullCData(oldp+177,(0U),4);
    bufp->fullBit(oldp+178,(0U));
}

VL_ATTR_COLD void VRV32I_System___024root__trace_full_0_sub_0(VRV32I_System___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void VRV32I_System___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root__trace_full_0\n"); );
    // Body
    VRV32I_System___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VRV32I_System___024root*>(voidSelf);
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VRV32I_System___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VRV32I_System___024root__trace_full_0_sub_0(VRV32I_System___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRV32I_System___024root__trace_full_0_sub_0\n"); );
    VRV32I_System__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+0,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD),32);
    bufp->fullCData(oldp+1,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdE),5);
    bufp->fullCData(oldp+2,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdM),5);
    bufp->fullCData(oldp+3,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW),5);
    bufp->fullBit(oldp+4,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__stallF));
    bufp->fullBit(oldp+5,((0U != (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcSrcE_act_dbg))));
    bufp->fullBit(oldp+6,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__flushE));
    bufp->fullCData(oldp+7,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardAE),2);
    bufp->fullCData(oldp+8,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardBE),2);
    bufp->fullIData(oldp+9,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcD),32);
    bufp->fullIData(oldp+10,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcE),32);
    bufp->fullIData(oldp+11,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__resultW_dbg),32);
    bufp->fullCData(oldp+12,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcSrcE_act_dbg),2);
    bufp->fullIData(oldp+13,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__tohost_csr),32);
    bufp->fullBit(oldp+14,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r));
    bufp->fullIData(oldp+15,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdPcF_r),32);
    bufp->fullIData(oldp+16,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdPcPlus4F_r),32);
    bufp->fullIData(oldp+17,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdInstrF_r),32);
    bufp->fullIData(oldp+18,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcRegF),32);
    bufp->fullIData(oldp+19,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__respPcF_r),32);
    bufp->fullIData(oldp+20,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__respPcPlus4F_r),32);
    bufp->fullBit(oldp+21,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__respValidF_r));
    bufp->fullBit(oldp+22,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__killRespF_r));
    bufp->fullIData(oldp+23,(((IData)(4U) + vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcRegF)),32);
    bufp->fullIData(oldp+24,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcNextF),32);
    bufp->fullIData(oldp+25,((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmExtE 
                              + vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcE)),32);
    bufp->fullIData(oldp+26,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__jalrTargetE),32);
    bufp->fullBit(oldp+27,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__fetch_resp_valid_raw));
    bufp->fullBit(oldp+28,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r) 
                            | (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__fetch_resp_valid_raw))));
    bufp->fullIData(oldp+29,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r)
                               ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdPcF_r
                               : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__respPcF_r)),32);
    bufp->fullIData(oldp+30,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r)
                               ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdPcPlus4F_r
                               : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__respPcPlus4F_r)),32);
    bufp->fullIData(oldp+31,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4D),32);
    bufp->fullCData(oldp+32,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D),5);
    bufp->fullCData(oldp+33,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D),5);
    bufp->fullCData(oldp+34,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD)
                               ? (0x0000001fU & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                                 >> 7U))
                               : 0U)),5);
    bufp->fullCData(oldp+35,((7U & (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                                    >> 0x0000000cU))),3);
    bufp->fullIData(oldp+36,(((4U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmSrcD))
                               ? ((2U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmSrcD))
                                   ? 0U : ((1U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmSrcD))
                                            ? 0U : 
                                           (0xfffff000U 
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
    bufp->fullBit(oldp+37,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD));
    bufp->fullBit(oldp+38,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteD_raw));
    bufp->fullBit(oldp+39,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemWriteD_raw));
    bufp->fullBit(oldp+40,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BranchD_raw));
    bufp->fullBit(oldp+41,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcBD_raw));
    bufp->fullCData(oldp+42,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmSrcD),3);
    bufp->fullCData(oldp+43,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcAD_raw),2);
    bufp->fullCData(oldp+44,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcD_raw),2);
    bufp->fullCData(oldp+45,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__PCSrcD_raw),2);
    bufp->fullCData(oldp+46,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_controller__DOT__u_aludec__DOT__ALUControl),5);
    bufp->fullBit(oldp+47,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteD_raw) 
                            & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD))));
    bufp->fullBit(oldp+48,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemWriteD_raw) 
                            & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD))));
    bufp->fullBit(oldp+49,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BranchD_raw) 
                            & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD))));
    bufp->fullBit(oldp+50,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcBD_raw) 
                            & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD))));
    bufp->fullCData(oldp+51,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD)
                               ? (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcAD_raw)
                               : 0U)),2);
    bufp->fullCData(oldp+52,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD)
                               ? (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcD_raw)
                               : 0U)),2);
    bufp->fullCData(oldp+53,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD)
                               ? (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__PCSrcD_raw)
                               : 0U)),2);
    bufp->fullCData(oldp+54,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validD)
                               ? (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_controller__DOT__u_aludec__DOT__ALUControl)
                               : 0U)),5);
    bufp->fullBit(oldp+55,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteW));
    bufp->fullBit(oldp+56,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT____VdfgRegularize_h3a653db9_0_0) 
                            & ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW) 
                               == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D)))));
    bufp->fullBit(oldp+57,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT____VdfgRegularize_h3a653db9_0_0) 
                            & ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW) 
                               == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D)))));
    bufp->fullCData(oldp+58,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcE),2);
    bufp->fullBit(oldp+59,((1U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcE))));
    bufp->fullBit(oldp+60,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteE));
    bufp->fullBit(oldp+61,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemWriteE));
    bufp->fullBit(oldp+62,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BranchE));
    bufp->fullBit(oldp+63,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcBE));
    bufp->fullCData(oldp+64,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUSrcAE),2);
    bufp->fullCData(oldp+65,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__PCSrcE),2);
    bufp->fullCData(oldp+66,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE),5);
    bufp->fullIData(oldp+67,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4E),32);
    bufp->fullIData(oldp+68,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rd1E),32);
    bufp->fullIData(oldp+69,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rd2E),32);
    bufp->fullIData(oldp+70,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ImmExtE),32);
    bufp->fullCData(oldp+71,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1E),5);
    bufp->fullCData(oldp+72,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2E),5);
    bufp->fullCData(oldp+73,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3E),3);
    bufp->fullBit(oldp+74,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validE));
    bufp->fullBit(oldp+75,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__RegWriteM));
    bufp->fullCData(oldp+76,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcM),2);
    bufp->fullIData(oldp+77,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4M),32);
    bufp->fullIData(oldp+78,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM),32);
    bufp->fullIData(oldp+79,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__WriteDataM),32);
    bufp->fullCData(oldp+80,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M),3);
    bufp->fullIData(oldp+81,(((0U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardAE))
                               ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rd1E
                               : ((1U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardAE))
                                   ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__resultW_dbg
                                   : ((2U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ForwardAE))
                                       ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM
                                       : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rd1E)))),32);
    bufp->fullIData(oldp+82,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcB_fwd),32);
    bufp->fullIData(oldp+83,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcA_E),32);
    bufp->fullIData(oldp+84,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcB_E),32);
    bufp->fullBit(oldp+85,((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__jalrTargetE 
                            >> 0x0000001fU)));
    bufp->fullBit(oldp+86,((0U == vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__jalrTargetE)));
    bufp->fullBit(oldp+87,((1U & (IData)((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT__sum 
                                          >> 0x00000020U)))));
    bufp->fullBit(oldp+88,((1U & ((~ ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT____VdfgRegularize_hd1e758aa_0_0) 
                                      ^ ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUControlE) 
                                         >> 4U))) & 
                                  ((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcA_E 
                                    >> 0x0000001fU) 
                                   ^ (IData)((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT__sum 
                                              >> 0x0000001fU)))))));
    bufp->fullBit(oldp+89,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BtakenE));
    bufp->fullBit(oldp+90,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validE) 
                            & ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BranchE) 
                               & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BtakenE)))));
    bufp->fullBit(oldp+91,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validE) 
                            & ((~ (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BranchE)) 
                               & (1U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__PCSrcE))))));
    bufp->fullBit(oldp+92,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__validE) 
                            & (2U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__PCSrcE)))));
    bufp->fullBit(oldp+93,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreValid_r));
    bufp->fullIData(oldp+94,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreAddr_r),32);
    bufp->fullIData(oldp+95,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreData_r),32);
    bufp->fullCData(oldp+96,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreBE_r),4);
    bufp->fullBit(oldp+97,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreValid_r) 
                            & ((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__prevStoreAddr_r 
                                >> 2U) == (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM 
                                           >> 2U)))));
    bufp->fullIData(oldp+98,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__BE_WD_M),32);
    bufp->fullCData(oldp+99,((3U & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultM)),2);
    bufp->fullCData(oldp+100,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ResultSrcW),2);
    bufp->fullIData(oldp+101,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__pcPlus4W),32);
    bufp->fullIData(oldp+102,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ALUResultW),32);
    bufp->fullIData(oldp+103,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__ReadDataW),32);
    bufp->fullQData(oldp+104,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT__sum),33);
    bufp->fullBit(oldp+106,((1U & ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT____VdfgRegularize_hd1e758aa_0_0)
                                    ? (vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__SrcA_E 
                                       >> 0x0000001fU)
                                    : (IData)((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT__sum 
                                               >> 0x0000001fU))))));
    bufp->fullBit(oldp+107,((1U & (~ (IData)((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_alu__DOT__sum 
                                              >> 0x00000020U))))));
    bufp->fullCData(oldp+108,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_controller__DOT__u_aludec__DOT__opcode),7);
    bufp->fullCData(oldp+109,((vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__instrD 
                               >> 0x00000019U)),7);
    bufp->fullBit(oldp+110,((((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdE) 
                              == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D)) 
                             & (0U != (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D)))));
    bufp->fullBit(oldp+111,((((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdE) 
                              == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D)) 
                             & (0U != (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D)))));
    bufp->fullBit(oldp+112,((1U & (~ (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__stallF)))));
    bufp->fullIData(oldp+113,(((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdValidF_r)
                                ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__holdInstrF_r
                                : vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__read_data0_reg)),32);
    bufp->fullIData(oldp+114,(((0U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D))
                                ? 0U : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem
                               [vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D])),32);
    bufp->fullIData(oldp+115,(((0U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D))
                                ? 0U : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem
                               [vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D])),32);
    bufp->fullIData(oldp+116,((((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT____VdfgRegularize_h3a653db9_0_0) 
                                & ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW) 
                                   == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D)))
                                ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__resultW_dbg
                                : ((0U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D))
                                    ? 0U : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem
                                   [vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs1D]))),32);
    bufp->fullIData(oldp+117,((((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT____VdfgRegularize_h3a653db9_0_0) 
                                & ((IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rdW) 
                                   == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D)))
                                ? vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__resultW_dbg
                                : ((0U == (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D))
                                    ? 0U : vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem
                                   [vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rs2D]))),32);
    bufp->fullIData(oldp+118,(vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__read_data0_reg),32);
    bufp->fullIData(oldp+119,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[0]),32);
    bufp->fullIData(oldp+120,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[1]),32);
    bufp->fullIData(oldp+121,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[2]),32);
    bufp->fullIData(oldp+122,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[3]),32);
    bufp->fullIData(oldp+123,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[4]),32);
    bufp->fullIData(oldp+124,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[5]),32);
    bufp->fullIData(oldp+125,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[6]),32);
    bufp->fullIData(oldp+126,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[7]),32);
    bufp->fullIData(oldp+127,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[8]),32);
    bufp->fullIData(oldp+128,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[9]),32);
    bufp->fullIData(oldp+129,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[10]),32);
    bufp->fullIData(oldp+130,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[11]),32);
    bufp->fullIData(oldp+131,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[12]),32);
    bufp->fullIData(oldp+132,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[13]),32);
    bufp->fullIData(oldp+133,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[14]),32);
    bufp->fullIData(oldp+134,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[15]),32);
    bufp->fullIData(oldp+135,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[16]),32);
    bufp->fullIData(oldp+136,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[17]),32);
    bufp->fullIData(oldp+137,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[18]),32);
    bufp->fullIData(oldp+138,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[19]),32);
    bufp->fullIData(oldp+139,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[20]),32);
    bufp->fullIData(oldp+140,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[21]),32);
    bufp->fullIData(oldp+141,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[22]),32);
    bufp->fullIData(oldp+142,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[23]),32);
    bufp->fullIData(oldp+143,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[24]),32);
    bufp->fullIData(oldp+144,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[25]),32);
    bufp->fullIData(oldp+145,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[26]),32);
    bufp->fullIData(oldp+146,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[27]),32);
    bufp->fullIData(oldp+147,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[28]),32);
    bufp->fullIData(oldp+148,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[29]),32);
    bufp->fullIData(oldp+149,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[30]),32);
    bufp->fullIData(oldp+150,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__rf__DOT__mem[31]),32);
    bufp->fullIData(oldp+151,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__MemRData_bypassed),32);
    bufp->fullIData(oldp+152,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift8),32);
    bufp->fullIData(oldp+153,(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift16),32);
    bufp->fullBit(oldp+154,(vlSelfRef.clk));
    bufp->fullBit(oldp+155,(vlSelfRef.reset));
    bufp->fullIData(oldp+156,(vlSelfRef.pc),32);
    bufp->fullBit(oldp+157,(vlSelfRef.MemWrite));
    bufp->fullIData(oldp+158,(vlSelfRef.MemAddr),32);
    bufp->fullIData(oldp+159,(vlSelfRef.MemWData),32);
    bufp->fullCData(oldp+160,(vlSelfRef.ByteEnable),4);
    bufp->fullIData(oldp+161,(vlSelfRef.inst_dbg),32);
    bufp->fullIData(oldp+162,(vlSelfRef.data_r_dbg),32);
    bufp->fullIData(oldp+163,(vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__read_data1_reg),32);
    bufp->fullSData(oldp+164,((0x00000fffU & (vlSelfRef.pc 
                                              >> 2U))),12);
    bufp->fullSData(oldp+165,((0x00000fffU & (vlSelfRef.MemAddr 
                                              >> 2U))),12);
    bufp->fullIData(oldp+166,(((4U & (IData)(vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__funct3M))
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
                                            << 8U) 
                                           | (0x000000ffU 
                                              & vlSelfRef.RV32I_System__DOT__dut__DOT__i_datapath__DOT__i_be__DOT__rd_shift8)))))),32);
    bufp->fullIData(oldp+167,(vlSelfRef.RV32I_System__DOT__imem_dmem__DOT__i),32);
}
