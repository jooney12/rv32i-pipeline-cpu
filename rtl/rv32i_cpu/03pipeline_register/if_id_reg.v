// IF/ID register with valid bit.
// Priority: clearD > enD update > hold
module if_id_reg(
  input clk,
  input reset,

  input enD,
  input clearD,

  input validF,
  input [31:0] pcF,
  input [31:0] pcPlus4F,
  input [31:0] instrF,

  output reg validD,
  output reg [31:0] pcD,
  output reg [31:0] pcPlus4D,
  output reg [31:0] instrD
);
  always @(posedge clk or posedge reset) begin
    if (reset) begin
      validD   <= 1'b0;
      pcD      <= 32'b0;
      pcPlus4D <= 32'b0;
      instrD   <= 32'b0;
    end
    else if (clearD) begin
      validD   <= 1'b0;
      pcD      <= 32'b0;
      pcPlus4D <= 32'b0;
      instrD   <= 32'b0;
    end
    else if (enD) begin
      validD   <= validF;
      pcD      <= pcF;
      pcPlus4D <= pcPlus4F;
      instrD   <= instrF;
    end
  end
endmodule