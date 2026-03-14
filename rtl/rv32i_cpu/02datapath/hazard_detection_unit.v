module hazard_detection_unit(
  input [4:0] rs1D,
  input [4:0] rs2D,
  input [4:0] rdE,
  input ResultSrcE_isLoad,
  input validE,

  output stallF,
  output stallD,
  output flushE
);

  wire dep_rs1;
  wire dep_rs2;
  wire lwStall;

  assign dep_rs1 = (rs1D == rdE) && (rs1D != 5'd0);
  assign dep_rs2 = (rs2D == rdE) && (rs2D != 5'd0);

  assign lwStall = validE && ResultSrcE_isLoad && (dep_rs1 || dep_rs2);

  assign stallF = lwStall;
  assign stallD = lwStall;
  assign flushE = lwStall;

endmodule