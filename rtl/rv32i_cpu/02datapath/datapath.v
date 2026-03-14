// 5-stage RV32I pipelined datapath (IF/ID/EX/MEM/WB connectivity 중심).
// Function priority: preserve existing behavior, expose debug anchors for GTKWave.
module datapath #(parameter RESET_PC=32'h1000_0000)(
  input clk,
  input reset,
  input [31:0] instrF,
  input [31:0] MemRData,

  output [31:0] pcF,
  output MemWriteM,
  output [31:0] MemAddrM,
  output [31:0] MemWDataM,
  output [3:0] ByteEnableM,
  output [31:0] if_id_inst,
  output [4:0] id_ex_rd,
  output [4:0] ex_mem_rd,
  output [4:0] mem_wb_rd,

  output stallF,
  output stallD,
  output flushD,
  output flushE,
  output [1:0] ForwardAE,
  output [1:0] ForwardBE,
  
  output [31:0] pcD,
  output [31:0] pcE,

  output [31:0] resultW_dbg,
  output [1:0] pcSrcE_act_dbg,
  output reg [31:0] tohost_csr
);
  // ---------------- IF ----------------

  // stall 동안 도착한 fetch response를 1개 보관
  reg        holdValidF_r;
  reg [31:0] holdPcF_r;
  reg [31:0] holdPcPlus4F_r;
  reg [31:0] holdInstrF_r;

  reg  [31:0] pcRegF;

  // sync IMEM response metadata (1-cycle delayed fetch response)
  reg  [31:0] respPcF_r;
  reg  [31:0] respPcPlus4F_r;
  reg         respValidF_r;

  // redirect happened after this request was issued -> kill returned response
  reg         killRespF_r;

  wire [31:0] pcPlus4F,pcNextF;
  wire [31:0] pcTargetE,jalrTargetE;
  wire [1:0]  PCSrcE_act;
  assign pcF = pcRegF;

  next_pc_logic i_nextpc(
    .pcF(pcRegF),
    .pcTargetE(pcTargetE),
    .jalrTargetE(jalrTargetE),
    .PCSrcE(PCSrcE_act),
    .pcPlus4F(pcPlus4F),
    .pcNextF(pcNextF)
    );

  wire redirectF_kill = (PCSrcE_act != 2'b00);

  wire        fetch_resp_valid_raw   = respValidF_r & ~killRespF_r;
  wire [31:0] fetch_resp_pc_raw      = respPcF_r;
  wire [31:0] fetch_resp_pcplus4_raw = respPcPlus4F_r;
  wire [31:0] fetch_resp_instr_raw   = instrF;

  wire        fetch_valid_respF   = holdValidF_r ? 1'b1          : fetch_resp_valid_raw;
  wire [31:0] fetch_pc_respF      = holdValidF_r ? holdPcF_r     : fetch_resp_pc_raw;
  wire [31:0] fetch_pcplus4_respF = holdValidF_r ? holdPcPlus4F_r: fetch_resp_pcplus4_raw;
  wire [31:0] fetch_instr_respF   = holdValidF_r ? holdInstrF_r  : fetch_resp_instr_raw;

  always @(posedge clk or posedge reset) begin
    if (reset) begin
      pcRegF         <= RESET_PC;

      respPcF_r      <= 32'b0;
      respPcPlus4F_r <= 32'b0;
      respValidF_r   <= 1'b0;
      killRespF_r    <= 1'b0;

      holdValidF_r    <= 1'b0;
      holdPcF_r       <= 32'b0;
      holdPcPlus4F_r  <= 32'b0;
      holdInstrF_r    <= 32'b0;

    end
    else begin
      // 현재 사이클에 IMEM으로 나간 request의 다음 사이클 응답 metadata 저장
      if (!stallF) begin
        respPcF_r      <= pcRegF;
        respPcPlus4F_r <= pcPlus4F;
        respValidF_r   <= 1'b1;
        killRespF_r    <= 1'b0;
      end

      // stall 중 새 fetch response가 도착하면 1개 보관
      if (stallD && fetch_resp_valid_raw && !holdValidF_r) begin
        holdValidF_r   <= 1'b1;
        holdPcF_r      <= fetch_resp_pc_raw;
        holdPcPlus4F_r <= fetch_resp_pcplus4_raw;
        holdInstrF_r   <= fetch_resp_instr_raw;
      end

      // stall이 풀리고 IF/ID가 받을 수 있으면 hold 소비
      if (!stallD && holdValidF_r) begin
        holdValidF_r <= 1'b0;
      end

      // redirect 우선
      if (redirectF_kill) begin
        killRespF_r  <= 1'b1;
        holdValidF_r <= 1'b0;
        pcRegF       <= pcNextF;
      end
      else if (!stallF) begin
        pcRegF <= pcNextF;
      end
    end
  end

  // ---------------- ID ----------------
  wire [31:0] pcPlus4D,instrD;
  wire [4:0] rs1D = validD ? instrD[19:15] : 5'd0;
  wire [4:0] rs2D = validD ? instrD[24:20] : 5'd0;
  wire [4:0] rdD  = validD ? instrD[11:7]  : 5'd0;
  wire [2:0] funct3D = instrD[14:12];
  wire [31:0] rd1D_raw, rd2D_raw;
  wire [31:0] rd1D, rd2D, ImmExtD;

  assign if_id_inst = instrD;

  wire        ifid_valid_in;
  wire [31:0] ifid_pc_in;
  wire [31:0] ifid_pcplus4_in;
  wire [31:0] ifid_instr_in;

  assign ifid_valid_in   = fetch_valid_respF;
  assign ifid_pc_in      = fetch_pc_respF;
  assign ifid_pcplus4_in = fetch_pcplus4_respF;
  assign ifid_instr_in   = fetch_instr_respF;

  wire validD;

  if_id_reg i_ifid(
    .clk(clk),
    .reset(reset),
    .enD(!stallD),
    .clearD(flushD),
    .validF(ifid_valid_in),
    .pcF(ifid_pc_in),
    .pcPlus4F(ifid_pcplus4_in),
    .instrF(ifid_instr_in),
    .validD(validD),
    .pcD(pcD),
    .pcPlus4D(pcPlus4D),
    .instrD(instrD)
  );

  wire RegWriteD_raw, MemWriteD_raw, BranchD_raw, ALUSrcBD_raw;
  wire [2:0] ImmSrcD;
  wire [1:0] ALUSrcAD_raw, ResultSrcD_raw, PCSrcD_raw;
  wire [4:0] ALUControlD_raw;

  wire RegWriteD, MemWriteD, BranchD, ALUSrcBD;
  wire [1:0] ALUSrcAD, ResultSrcD, PCSrcD;
  wire [4:0] ALUControlD;

  controller i_controller(
    .opcode(validD ? instrD[6:0] : 7'b0),
    .funct7(instrD[31:25]),
    .funct3(instrD[14:12]),
    .RegWrite(RegWriteD_raw),
    .ImmSrc(ImmSrcD),
    .ALUSrcA(ALUSrcAD_raw),
    .ALUSrcB(ALUSrcBD_raw),
    .ALUControl(ALUControlD_raw),
    .MemWrite(MemWriteD_raw),
    .ResultSrc(ResultSrcD_raw),
    .Branch(BranchD_raw),
    .PCSrc(PCSrcD_raw)
  );

  assign RegWriteD   = validD ? RegWriteD_raw   : 1'b0;
  assign MemWriteD   = validD ? MemWriteD_raw   : 1'b0;
  assign BranchD     = validD ? BranchD_raw     : 1'b0;
  assign ALUSrcBD    = validD ? ALUSrcBD_raw    : 1'b0;
  assign ALUSrcAD    = validD ? ALUSrcAD_raw    : 2'b00;
  assign ResultSrcD  = validD ? ResultSrcD_raw  : 2'b00;
  assign PCSrcD      = validD ? PCSrcD_raw      : 2'b00;
  assign ALUControlD = validD ? ALUControlD_raw : 5'b00000;

  wire RegWriteW;
  wire [4:0] rdW;
  wire [31:0] ResultW;
  
  reg_file_async rf(
    .clk(clk),
    .we(RegWriteW),
    .ra1(rs1D),
    .ra2(rs2D),
    .wa(rdW),
    .wd(ResultW),
    .rd1(rd1D_raw),
    .rd2(rd2D_raw)
    );

  wire wbBypassRs1D = RegWriteW && (rdW != 5'd0) && (rdW == rs1D);
  wire wbBypassRs2D = RegWriteW && (rdW != 5'd0) && (rdW == rs2D);

  assign rd1D = wbBypassRs1D ? ResultW : rd1D_raw;
  assign rd2D = wbBypassRs2D ? ResultW : rd2D_raw;

  extend i_ext(
    .instr(instrD),
    .ImmSrc(ImmSrcD),
    .ImmExt(ImmExtD)
    );

  // Hazard / flush controls
  wire flushE_hz,flushE_redirect;
  wire [1:0] ResultSrcE;
  wire ResultSrcE_isLoad = (ResultSrcE == 2'b01); // explicit decode for load-use condition

  hazard_detection_unit i_hdu(
    .rs1D(rs1D),
    .rs2D(rs2D),
    .rdE(id_ex_rd),
    .ResultSrcE_isLoad(ResultSrcE_isLoad),
    .validE(validE),
    .stallF(stallF),
    .stallD(stallD),
    .flushE(flushE_hz)
  );
  flush_control i_fctrl(
    .PCSrcE(PCSrcE_act),
    .flushD(flushD),
    .flushE_redirect(flushE_redirect)
  );

  assign flushE = flushE_hz | flushE_redirect;

  // ---------------- ID/EX pipeline register ----------------
  wire RegWriteE, MemWriteE, BranchE, ALUSrcBE;
  wire [1:0] ALUSrcAE, PCSrcE;
  wire [4:0] ALUControlE;
  wire [31:0] pcPlus4E, rd1E, rd2E, ImmExtE;
  wire [4:0] rs1E, rs2E, rdE;
  wire [2:0] funct3E;

  wire validE;

  assign id_ex_rd = rdE;

  id_ex_reg i_idex(
    .clk(clk),
    .reset(reset),
    .flushE(flushE),

    .validD(validD),

    .RegWriteD(RegWriteD),
    .MemWriteD(MemWriteD),
    .BranchD(BranchD),
    .ALUSrcBD(ALUSrcBD),
    .ALUSrcAD(ALUSrcAD),
    .ResultSrcD(ResultSrcD),
    .PCSrcD(PCSrcD),
    .ALUControlD(ALUControlD),

    .pcD(pcD),
    .pcPlus4D(pcPlus4D),
    .rd1D(rd1D),
    .rd2D(rd2D),
    .ImmExtD(ImmExtD),
    .rs1D(rs1D),
    .rs2D(rs2D),
    .rdD(rdD),
    .funct3D(funct3D),

    .validE(validE),

    .RegWriteE(RegWriteE),
    .MemWriteE(MemWriteE),
    .BranchE(BranchE),
    .ALUSrcBE(ALUSrcBE),
    .ALUSrcAE(ALUSrcAE),
    .ResultSrcE(ResultSrcE),
    .PCSrcE(PCSrcE),
    .ALUControlE(ALUControlE),

    .pcE(pcE),
    .pcPlus4E(pcPlus4E),
    .rd1E(rd1E),
    .rd2E(rd2E),
    .ImmExtE(ImmExtE),
    .rs1E(rs1E),
    .rs2E(rs2E),
    .rdE(rdE),
    .funct3E(funct3E)
  );

  // ---------------- EX ----------------
  wire validM;
  wire RegWriteM;
  wire [1:0] ResultSrcM;
  wire [31:0] pcPlus4M,ALUResultM,WriteDataM;
  wire [4:0] rdM;
  wire [2:0] funct3M;

  wire [31:0] SrcA_fwd, SrcB_fwd;
  wire [31:0] SrcA_E, SrcB_E;
  wire [31:0] ALUResultE;
  wire N, Z, C, V;
  wire BtakenE;

  assign ex_mem_rd = rdM;

  forwarding_unit i_fwd(
    .RegWriteM(RegWriteM),
    .RegWriteW(RegWriteW),
    .rs1E(rs1E),
    .rs2E(rs2E),
    .rdM(rdM),
    .rdW(rdW),
    .ForwardAE(ForwardAE),
    .ForwardBE(ForwardBE)
    );

  mux3 #(32) muxA(
    .d0(rd1E),
    .d1(ResultW),
    .d2(ALUResultM),
    .s(ForwardAE),
    .y(SrcA_fwd)
    );

  mux3 #(32) muxB(
    .d0(rd2E),
    .d1(ResultW),
    .d2(ALUResultM),
    .s(ForwardBE),
    .y(SrcB_fwd)
    );

  assign SrcA_E = (ALUSrcAE==2'b01) ? pcE :
                  (ALUSrcAE==2'b10) ? 32'd0 :
                  SrcA_fwd;

  assign SrcB_E = ALUSrcBE ? ImmExtE : SrcB_fwd;

  alu i_alu(
    .SrcA(SrcA_E),
    .SrcB(SrcB_E),
    .ALUControl(ALUControlE),
    .ALUResult(ALUResultE),
    .N(N),
    .Z(Z),
    .C(C),
    .V(V)
    );

  branch_logic i_br(
    .Branch(BranchE),
    .funct3(funct3E),
    .N(N),
    .Z(Z),
    .C(C),
    .V(V),
    .Btaken(BtakenE)
    );

  assign pcTargetE   = pcE + ImmExtE;
  assign jalrTargetE = ALUResultE;

  wire redirectBranchE = validE && BranchE && BtakenE;
  wire redirectJalE    = validE && (PCSrcE==2'b01) && !BranchE;
  wire redirectJalrE   = validE && (PCSrcE==2'b10);

  assign PCSrcE_act = redirectJalrE ? 2'b10 :
                      (redirectBranchE || redirectJalE) ? 2'b01 :
                      2'b00;

  // ---------------- MEM ----------------

  // same-address store -> load bypass support
  reg        prevStoreValid_r;
  reg [31:0] prevStoreAddr_r;
  reg [31:0] prevStoreData_r;
  reg [3:0]  prevStoreBE_r;

  wire sameAddrStoreLoadM;
  wire [31:0] MemRData_bypassed;

  ex_mem_reg i_exmem(
    .clk(clk),
    .reset(reset),
    .RegWriteE(RegWriteE),
    .MemWriteE(MemWriteE),
    .ResultSrcE(ResultSrcE),
    .pcPlus4E(pcPlus4E),
    .ALUResultE(ALUResultE),
    .WriteDataE(SrcB_fwd),
    .rdE(rdE),
    .funct3E(funct3E),

    .RegWriteM(RegWriteM),
    .MemWriteM(MemWriteM),
    .ResultSrcM(ResultSrcM),
    .pcPlus4M(pcPlus4M),
    .ALUResultM(ALUResultM),
    .WriteDataM(WriteDataM),
    .rdM(rdM),
    .funct3M(funct3M)
    );

  wire [31:0] BE_WD_M, BE_RD_M;
  wire [1:0]  addrLast2M;

  assign addrLast2M = ALUResultM[1:0];

  assign sameAddrStoreLoadM =
      prevStoreValid_r &&
      (prevStoreAddr_r[31:2] == ALUResultM[31:2]);

  assign MemRData_bypassed =
      sameAddrStoreLoadM ? prevStoreData_r : MemRData;  

  // synchronous RAM timing alignment
  // store : use M-stage address
  // load  : present E-stage address one cycle earlier
  assign MemAddrM = MemWriteM ? ALUResultM : ALUResultE;

  BE_logic i_be(
    .funct3(funct3M),
    .Addr_Last2(addrLast2M),
    .WD(WriteDataM),
    .RD(MemRData_bypassed),
    .BE_WD(BE_WD_M),
    .BE_RD(BE_RD_M),
    .Byte_Enable(ByteEnableM)
    );

  assign MemWDataM = BE_WD_M;

  always @(posedge clk or posedge reset) begin
    if (reset) begin
      prevStoreValid_r <= 1'b0;
      prevStoreAddr_r  <= 32'b0;
      prevStoreData_r  <= 32'b0;
      prevStoreBE_r    <= 4'b0000;
    end
    else begin
      prevStoreValid_r <= MemWriteM;
      prevStoreAddr_r  <= ALUResultM;
      prevStoreData_r  <= BE_WD_M;
      prevStoreBE_r    <= ByteEnableM;
    end
  end  

  // ---------------- WB ----------------
  wire validW;
  wire [1:0] ResultSrcW;
  wire [31:0] pcPlus4W, ALUResultW, ReadDataW;

  assign mem_wb_rd = rdW;

  mem_wb_reg i_memwb(
    .clk(clk),
    .reset(reset),
    .RegWriteM(RegWriteM),
    .ResultSrcM(ResultSrcM),
    .pcPlus4M(pcPlus4M),
    .ALUResultM(ALUResultM),
    .ReadDataM(BE_RD_M),
    .rdM(rdM),

    .RegWriteW(RegWriteW),
    .ResultSrcW(ResultSrcW),
    .pcPlus4W(pcPlus4W),
    .ALUResultW(ALUResultW),
    .ReadDataW(ReadDataW),
    .rdW(rdW)
    );

  register_write_data_logic i_wbsel(
    .ResultSrc(ResultSrcW),
    .ALUResult(ALUResultW),
    .BE_RD(ReadDataW),
    .PCPlus4(pcPlus4W),
    .WD(ResultW)
    );

  // Debug anchors
  assign resultW_dbg = ResultW;
  assign pcSrcE_act_dbg = PCSrcE_act;

  always @(posedge clk or posedge reset) begin
    if (reset) tohost_csr <= 32'd0;
    else if (RegWriteW && rdW==5'd31) tohost_csr <= ResultW;
  end
endmodule