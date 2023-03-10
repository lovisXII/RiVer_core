module x1_multiplier (
  input logic clk,
  input logic reset_n,
  input logic [319:0] RES_RX0,
  input logic SELECT_MSB_RX0,
  input logic SIGNED_RES_RX0,
  input logic X0X1_EMPTY_SX0,
  input logic X1X2_POP_SX2,
  output logic [127:0] RES_RX1,
  output logic SELECT_MSB_RX1,
  output logic SIGNED_RES_RX1,
  output logic X1X2_EMPTY_SX1,
  output logic X0X1_POP_SX1
);

  typedef logic [63:0] tab_2_t;
  typedef logic [4][63:0] tab_5_t;

  tab_5_t x0_data;
  tab_2_t product_s6, product_s7, product_s8;
  logic stall_sx1;
  logic [129:0] x1x2_din, x1x2_dout;
  logic x1x2_push, x1x2_full;

  fifo #(.N(130)) x1x2 (
    .clk(clk),
    .reset_n(reset_n),
    .DIN(x1x2_din),
    .PUSH(x1x2_push),
    .POP(X1X2_POP_SX2),
    .FULL(x1x2_full),
    .EMPTY(X1X2_EMPTY_SX1),
    .DOUT(x1x2_dout)
  );

  csa csa6 (
    .A(x0_data[0]),
    .B(x0_data[1]),
    .C(x0_data[2]),
    .S0(product_s6[0]),
    .S1(product_s6[1])
  );

  csa csa7 (
    .A(product_s6[0]),
    .B(product_s6[1]),
    .C(x0_data[3]),
    .S0(product_s7[0]),
    .S1(product_s7[1])
  );

  csa csa8 (
    .A(product_s7[0]),
    .B(product_s7[1]),
    .C(x0_data[4]),
    .S0(product_s8[0]),
    .S1(product_s8[1])
  );

  assign stall_sx1 = x1x2_full || X0X1_EMPTY_SX0;
  assign x1x2_push = ~stall_sx1;
  assign X0X1_POP_SX1 = ~stall_sx1;

  // fifo x1x2 input
  assign x1x2_din[129] = SIGNED_RES_RX0;
  assign x1x2_din[128] = SELECT_MSB_RX0;
  assign x1x2_din[127:64] = product_s8[1];
  assign x1x2_din[63:0] = product_s8[0];

  // fifo x1x2 ouput
  assign SIGNED_RES_RX1 = x1x2_dout[129];
  assign SELECT_MSB_RX1 = x1x2_dout[128];
  assign RES_RX1 = x1x2_dout[127:0];

  // generate x0_data from RES_RX0
 assign x0_data[4] = RES_RX0[319:256];
assign x0_data[3] = RES_RX0[255:192];
assign x0_data[2] = RES_RX0[191:128];
assign x0_data[1] = RES_RX0[127:64];
assign x0_data[0] = RES_RX0[63:0];

csa csa6 (
    .A(x0_data[0]),
    .B(x0_data[1]),
    .C(x0_data[2]),
    .S0(product_s6[0]),
    .S1(product_s6[1])
);

csa csa7 (
    .A(product_s6[0]),
    .B(product_s6[1]),
    .C(x0_data[3]),
    .S0(product_s7[0]),
    .S1(product_s7[1])
);

csa csa8 (
    .A(product_s7[0]),
    .B(product_s7[1]),
    .C(x0_data[4]),
    .S0(product_s8[0]),
    .S1(product_s8[1])
);

assign stall_sx1 = x1x2_full || X0X1_EMPTY_SX0;
assign x1x2_push = ~stall_sx1;
assign x0x1_POP_SX1 = ~stall_sx1;

// fifo x1x2 input
assign x1x2_din[129] = SIGNED_RES_RX0;
assign x1x2_din[128] = SELECT_MSB_RX0;
assign x1x2_din[127:64] = {product_s8[1],{64{1'b0}}};
assign x1x2_din[63:0] = product_s8[0];

// fifo x1x2 output
assign SIGNED_RES_RX1 = x1x2_dout[129];
assign SELECT_MSB_RX1 = x1x2_dout[128];
assign RES_RX1 = x1x2_dout[127:0];

endmodule;
