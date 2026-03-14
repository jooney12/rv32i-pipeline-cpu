module rv32i_pipeline_cpu #(parameter RESET_PC=32'h1000_0000)(
  input clk,
  input reset,
  input  [31:0] MemRData,
  input  [31:0] inst,

  output [31:0] pc,
  output MemWrite,
  output [31:0] MemAddr,
  output [31:0] MemWData,
  output [3:0]  ByteEnable
);

  datapath #(.RESET_PC(RESET_PC)) i_datapath(
    .clk(clk),
    .reset(reset),
    .instrF(inst),
    .MemRData(MemRData),
    .pcF(pc),
    .MemWriteM(MemWrite),
    .MemAddrM(MemAddr),
    .MemWDataM(MemWData),
    .ByteEnableM(ByteEnable),
    .if_id_inst(),
    .id_ex_rd(),
    .ex_mem_rd(),
    .mem_wb_rd(),
    .stallF(),
    .stallD(),
    .flushD(),
    .flushE(),
    .ForwardAE(),
    .ForwardBE(),
    .pcD(),
    .pcE(),
    .resultW_dbg(),
    .pcSrcE_act_dbg(),
    .tohost_csr()
  );
endmodule