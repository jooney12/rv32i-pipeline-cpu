module mem_wb_reg(
  input clk,
  input reset,
  input RegWriteM,
  input [1:0] ResultSrcM,
  input [31:0] pcPlus4M,
  input [31:0] ALUResultM,
  input [31:0] ReadDataM,
  input [4:0] rdM,

  output reg RegWriteW,
  output reg [1:0] ResultSrcW,
  output reg [31:0] pcPlus4W,
  output reg [31:0] ALUResultW,
  output reg [31:0] ReadDataW,
  output reg [4:0] rdW
);

  always @(posedge clk or posedge reset) begin
    if (reset) begin
      RegWriteW  <= 1'b0;
      ResultSrcW <= 2'b00;
      pcPlus4W   <= 32'b0;
      ALUResultW <= 32'b0;
      ReadDataW  <= 32'b0;
      rdW        <= 5'b0;
    end else begin
      RegWriteW  <= RegWriteM;
      ResultSrcW <= ResultSrcM;
      pcPlus4W   <= pcPlus4M;
      ALUResultW <= ALUResultM;
      ReadDataW  <= ReadDataM;
      rdW        <= rdM;
    end
  end

endmodule