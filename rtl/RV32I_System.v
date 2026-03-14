module RV32I_System #(
  parameter RESET_PC = 32'h1000_0000,
  parameter MEM_AWIDTH = 12,
  parameter MEM_DEPTH  = (1 << MEM_AWIDTH),
  parameter IMEM_HEX   = "",
  parameter IMEM_BIN   = ""
)(
  input  clk,
  input  reset,
  output [31:0] pc,
  output        MemWrite,
  output [31:0] MemAddr,
  output [31:0] MemWData,
  output [3:0]  ByteEnable,
  output [31:0] inst_dbg,
  output [31:0] data_r_dbg
);

  localparam [31:0] RESET_WORD_ADDR = RESET_PC >> 2;

  wire [31:0] inst;
  wire [31:0] MemRData;
  wire [MEM_AWIDTH-1:0] imem_addr;
  wire [MEM_AWIDTH-1:0] dmem_addr;

  assign imem_addr = pc[MEM_AWIDTH+1:2] - RESET_WORD_ADDR[MEM_AWIDTH-1:0];
  assign dmem_addr = MemAddr[MEM_AWIDTH+1:2] - RESET_WORD_ADDR[MEM_AWIDTH-1:0];

  assign inst_dbg   = inst;
  assign data_r_dbg = MemRData;

  rv32i_pipeline_cpu #(
    .RESET_PC(RESET_PC)
  ) dut (
    .clk(clk),
    .reset(reset),
    .MemRData(MemRData),
    .inst(inst),
    .pc(pc),
    .MemWrite(MemWrite),
    .MemAddr(MemAddr),
    .MemWData(MemWData),
    .ByteEnable(ByteEnable)
  );

  SYNC_RAM_DP_WBE #(
    .DWIDTH(32),
    .AWIDTH(MEM_AWIDTH),
    .DEPTH(MEM_DEPTH),
    .MIF_HEX(IMEM_HEX),
    .MIF_BIN(IMEM_BIN)
  ) imem_dmem (
    .clk(clk),

    .d0(32'b0),
    .addr0(imem_addr),
    .wbe0(4'b0000),
    .wen0(1'b0),
    .q0(inst),

    .d1(MemWData),
    .addr1(dmem_addr),
    .wbe1(ByteEnable),
    .wen1(MemWrite),
    .q1(MemRData)
  );

endmodule
