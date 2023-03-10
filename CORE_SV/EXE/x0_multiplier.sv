module x0_multiplier (
    input logic clk, reset_n,
    input logic [31:0] OP1_SE, OP2_SE,
    input logic [1:0] MULT_CMD_RD,
    input logic X0X1_POP_SX1,
    input logic DEC2X0_EMPTY_SD,
    output logic [319:0] RES_RX0,
    output logic SELECT_MSB_RX0,
    output logic SIGNED_RES_RX0,
    output logic X0X1_EMPTY_SX0
);

    typedef logic [31:0] tab_32_t [0:31];
    typedef logic [19:0] tab_20_t [0:19];
    typedef logic [13:0] tab_14_t [0:13];
    typedef logic [9:0] tab_10_t [0:9];
    typedef logic [5:0] tab_6_t [0:5];
    typedef logic [3:0] tab_4_t [0:3];

    logic [31:0] op1, op2;
    logic [63:0] prod;
    logic signed_type, signed_res_sx0, select_msb_sx0, stall_sx0;
    logic [321:0] x0x1_din, x0x1_dout;
    logic x0x1_push, x0x1_full;

    fifo #(322) x0x1 (
        .clk(clk),
        .reset_n(reset_n),
        .DIN(x0x1_din),
        .PUSH(x0x1_push),
        .POP(X0X1_POP_SX1),
        .FULL(x0x1_full),
        .EMPTY(X0X1_EMPTY_SX0),
        .DOUT(x0x1_dout)
    );

    component csa;
        input logic [63:0] A, B, C;
        output logic [63:0] S0, S1;
    endcomponent

    function unsigned one_ext_32;
        input logic [31:0] in_val;
        begin
            one_ext_32 = {in_val[31], {28{in_val[31]}}, in_val};
        end
    endfunction

    initial prod = 64'b0;

    // need clarification
    always_comb begin
        if ((MULT_CMD_RD == 2'b10 || MULT_CMD_RD == 2'b01) && OP1_SE[31] && OP2_SE[31])
            signed_type = 1'b0;
        else if (MULT_CMD_RD != 2'b11)
            signed_type = 1'b1;
        else
            signed_type = 1'b0;
    end

    always_comb begin
        if (OP1_SE[31] && OP2_SE[31])
            signed_res_sx0 = 1'b0;
        else
            signed_res_sx0 = 1'b1;
    end

    always_comb begin
        if (MULT_CMD_RD != 2'b01)
            select_msb_sx0 = 1'b1;
        else
            select_msb_sx0 = 1'b0;
    end

op1 = (OP1_SE[31] && OP2_SE[31] && (MULT_CMD_RD == "10" || MULT_CMD_RD == 2'b01)) ? 
       (not(OP1_SE) + 1'b1) : 
       ((OP1_SE[31] == 1'b0 && OP2_SE[31] == 1'b1) && (MULT_CMD_RD == "10" || MULT_CMD_RD == 2'b01)) ? 
       OP1_SE : 
       OP2_SE;
op2 = (OP1_SE[31] && OP2_SE[31] && (MULT_CMD_RD == "10" || MULT_CMD_RD == 2'b01)) ? 
       (not(OP2_SE) + 1'b1) : 
       ((OP1_SE[31] == 1'b0 && OP2_SE[31] == 1'b1) && (MULT_CMD_RD == "10" || MULT_CMD_RD == 2'b01)) ? 
       OP2_SE : 
       OP1_SE;

always_ff @(posedge clk) begin
    for (int i = 0; i < 32; i++) begin
        if (op2[i] == 1'b1) begin
            logic [63:0] prod = 64'h0;
            for (int j = i; j <= i+31; j++) begin
                prod[j] = op1[j-i] & op2[i];
            end
            if (signed_type == 1'b1 && op1[31] == 1'b1) begin
                for (int k = i+32; k <= 63; k++) begin
                    prod[k] = 1'b1;
                end
            end
            product[i] <= prod;
        end
    end
end

for (int i = 0; i <= 9; i++) begin
    csa csa1 (
        .A(product[0 + 3*i]),
        .B(product[1 + 3*i]),
        .C(product[2 + 3*i]),
        .S0(product_s1[0 + 2*i]),
        .S1(product_s1[1 + 2*i])
    );
end

for (int i = 0; i <= 5; i++) begin
    csa csa2 (
        .A(product_s1[0 + 3*i]),
        .B(product_s1[1 + 3*i]),
        .C(product_s1[2 + 3*i]),
        .S0(product_s2[0 + 2*i]),
        .S1(product_s2[1 + 2*i])
    );
end

csa csa2_6 (
    .A(product_s1[18]),
    .B(product_s1[19]),
    .C(product[30]),
    .S0(product_s2[12]),
    .S1(product_s2[13])
);

for (int i = 0; i <= 3; i++) begin
    csa csa3 (
        .A(product_s2[0 + 3*i]),
        .B(product_s2[1 + 3*i]),
        .C(product_s2[2 + 3*i]),
        .S0(product_s3[0 + 2*i]),
        .S1(product_s3[1 + 2*i])
    );
end

csa csa3_4 (
  .A(product_s2[12]),
  .B(product_s2[13]),
  .C(product[31]),
  .S0(product_s3[8]),
  .S1(product_s3[9])
);

genvar i;
generate
  for (i = 0; i < 3; i++) begin : stage4
    csa csa4 (
      .A(product_s3[0 + 3*i]),
      .B(product_s3[1 + 3*i]),
      .C(product_s3[2 + 3*i]),
      .S0(product_s4[0 + 2*i]),
      .S1(product_s4[1 + 2*i])
    );
  end
endgenerate

generate
  for (i = 0; i < 2; i++) begin : stage5
    csa csa5 (
      .A(product_s4[0 + 3*i]),
      .B(product_s4[1 + 3*i]),
      .C(product_s4[2 + 3*i]),
      .S0(product_s5[0 + 2*i]),
      .S1(product_s5[1 + 2*i])
    );
  end
endgenerate

assign stall_sx0 = x0x1_full || DEC2X0_EMPTY_SD;
assign x0x1_push = !stall_sx0;

assign x0x1_din[321] = select_msb_sx0;
assign x0x1_din[320] = signed_res_sx0;
assign x0x1_din[319:256] = product_s3[9];
assign x0x1_din[255:192] = product_s5[3];
assign x0x1_din[191:128] = product_s5[2];
assign x0x1_din[127:64] = product_s5[1];
assign x0x1_din[63:0] = product_s5[0];

assign SELECT_MSB_RX0 = x0x1_dout[321];
assign SIGNED_RES_RX0 = x0x1_dout[320];
assign RES_RX0 = x0x1_dout[319:0];

endmodule
