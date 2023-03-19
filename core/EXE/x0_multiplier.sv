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


    logic [63:0] product    [32];
    logic [63:0] prod    [32]; 
    logic [63:0] product_s1 [20];
    logic [63:0] product_s2 [14];
    logic [63:0] product_s3 [10];
    logic [63:0] product_s4 [6];
    logic [63:0] product_s5 [4];

    logic [31:0] op1, op2;
    logic signed_type, signed_res_sx0, select_msb_sx0, stall_sx0;
    logic sign; 
    logic [321:0] x0x1_din, x0x1_dout;
    logic x0x1_push, x0x1_full;

    fifo #(
        .N(322)
        ) x0x1 (
        .clk(clk),
        .reset_n(reset_n),
        .DIN(x0x1_din),
        .PUSH(x0x1_push),
        .POP(X0X1_POP_SX1),
        .FULL(x0x1_full),
        .EMPTY(X0X1_EMPTY_SX0),
        .DOUT(x0x1_dout)
    );

assign signed_type = (MULT_CMD_RD == 2'b10 || MULT_CMD_RD == 2'b01) && (OP1_SE[31] && OP2_SE[31]) ? 1'b0 :
(MULT_CMD_RD != 2'b11) ? 1'b1 : 1'b0;

assign signed_res_sx0 = (OP1_SE[31] && OP2_SE[31]) ? 1'b0 : 1'b1; // else ??
assign select_msb_sx0 = (MULT_CMD_RD != 2'b01) ? 1'b1 : 1'b0;

assign op1 = (OP1_SE[31] && OP2_SE[31] && (MULT_CMD_RD == 2'b10 || MULT_CMD_RD == 2'b01)) ? 
       (~OP1_SE + 1'b1) : 
       ((OP1_SE[31] == 1'b0 && OP2_SE[31] == 1'b1) && (MULT_CMD_RD == 2'b10 || MULT_CMD_RD == 2'b01)) ? 
       OP1_SE : 
       OP2_SE;

assign op2 = (OP1_SE[31] && OP2_SE[31] && (MULT_CMD_RD == 2'b10 || MULT_CMD_RD == 2'b01)) ? 
       (~OP2_SE + 1'b1) : 
       ((OP1_SE[31] == 1'b0 && OP2_SE[31] == 1'b1) && (MULT_CMD_RD == 2'b10 || MULT_CMD_RD == 2'b01)) ? 
       OP2_SE : 
       OP1_SE;


/*
always_comb begin
    for (int i = 0; i < 32; i++) begin
        var logic [63:0] prod = 64'h0;
        if (op2[i] == 1'b1) begin
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

always_comb begin
    for (int i = 0; i < 32; i++) begin
        if (op2[i] == 1'b1) begin
            for (int j = 0; j < 32; j++) begin
                if (j <= i+31-i) begin
                    product[i][j+i] = op1[j] & op2[i];
                end else if (signed_type == 1'b1 && op1[31] == 1'b1) begin
                    product[i][j+i] = 1'b1;
                end else begin
                    product[i][j+i] = 1'b0;
                end
            end
        end
    end
end


always_comb begin
    for (int i = 0; i < 32; i++) begin
        var logic [63:0] prod = '0;
        if (op2[i] == 1'b1) begin
            for (int j = i; j <= i+31; j++) begin
                prod[j] = op1[j-i] & op2[i];
            end
            if (signed_type == 1'b1 && op1[31] == 1'b1) begin
                for (int k = i+32; k <= 63; k++) begin
                    prod[k] = 1'b1;
                end
            end
            product[i] = prod;
        end
    end
end

    always_comb begin
        for (int i = 0; i < 32; i++) begin
          if (op2[i] == 1'b1) begin
              for (int j = i; j <= i+31; j++) begin
                  prod[i][j] = (op1[j-i] & op2[i]);
              end
              for (int k = i+32; k <= 63; k++) begin
                  prod[i][k] = 1'b0;//signed_type & op1[31];
              end
          end
        end
      end
      */

/*
assign product[0] = {32{sign}, {op1        & 32{op2[0]}}};
assign product[1] = {31{sign}, {op1[30:0]  & 31{op2[1]}}, 1'b0};
assign product[2] = {30{sign}, {op1[29:0]  & 30{op2[2]}}, 2'b0};
assign product[3] = {29{sign}, {op1[28:0]  & 29{op2[3]}}, 3'b0};
assign product[4] = {28{sign}, {op1[27:0]  & 28{op2[4]}}, 4'b0};
assign product[3] = {27{sign}, {op1[26:0]  & 27{op2[5]}}, 5'b0};

assign product[2] = {30{sign}, {op1[30:0] & 30{op2[2]}}, 2'b0};
assign product[3] = {29{sign}, {op1[29:0] & 29{op2[3]}}, 3'b0};
*/
/*
integer i;
always_comb begin
  for (i = 0; i < 32; i++) begin
    product[i] = {{31-i{sign}}, {op1[(31-i):0] & (31-i){op2[i]}}, {i{1'b0}}};
  end
end
*/

assign sign = op1[31] & signed_type;

assign product[0]   = { {32{sign}}, op1 & {32{op2[0]}}};

assign product[1]   = { {31{sign}}, op1[30:0]  & {31{op2[1]}} , 1'b0};

assign product[2]   = {{30{sign}}, op1[29:0]  & { 30{op2[2]}} , 2'b0};
assign product[3]   = {{29{sign}}, op1[28:0]  & { 29{op2[3]}} , 3'b0};
assign product[4]   = {{28{sign}}, op1[27:0]  & { 28{op2[4]}} , 4'b0};
assign product[5]   = {{27{sign}}, op1[26:0]  & { 27{op2[5]}} , 5'b0};
assign product[6]   = {{26{sign}}, op1[25:0]  & { 26{op2[6]}} , 6'b0};
assign product[7]   = {{25{sign}}, op1[24:0]  & { 25{op2[7]}} , 7'b0};
assign product[8]   = {{24{sign}}, op1[23:0]  & { 24{op2[8]}} , 8'b0};
assign product[9]   = {{23{sign}}, op1[22:0]  & { 23{op2[9]}} , 9'b0};
assign product[10]  = {{22{sign}}, op1[21:0]  & { 22{op2[10]}}, 10'b0};
assign product[11]  = {{21{sign}}, op1[20:0]  & { 21{op2[11]}}, 11'b0};
assign product[12]  = {{20{sign}}, op1[19:0]  & { 20{op2[12]}}, 12'b0};
assign product[13]  = {{19{sign}}, op1[18:0]  & { 19{op2[13]}}, 13'b0};
assign product[14]  = {{18{sign}}, op1[17:0]  & { 18{op2[14]}}, 14'b0};
assign product[15]  = {{17{sign}}, op1[16:0]  & { 17{op2[15]}}, 15'b0};
assign product[16]  = {{16{sign}}, op1[15:0]  & { 16{op2[16]}}, 16'b0};
assign product[17]  = {{15{sign}}, op1[14:0]  & { 15{op2[17]}}, 17'b0};
assign product[18]  = {{14{sign}}, op1[13:0]  & { 14{op2[18]}}, 18'b0};
assign product[19]  = {{13{sign}}, op1[12:0]  & { 13{op2[19]}}, 19'b0};
assign product[20]  = {{12{sign}}, op1[11:0]  & { 12{op2[20]}}, 20'b0};
assign product[21]  = {{11{sign}}, op1[10:0]  & { 11{op2[21]}}, 21'b0};
assign product[22]  = {{10{sign}}, op1[9:0]   & { 10{op2[22]}}, 22'b0};
assign product[23]  = {{ 9{sign}}, op1[8:0]   & { 9 {op2[23]}}, 23'b0};
assign product[24]  = {{ 8{sign}}, op1[7:0]   & { 8 {op2[24]}}, 24'b0};
assign product[25]  = {{ 7{sign}}, op1[6:0]   & { 7 {op2[25]}}, 25'b0};
assign product[26]  = {{ 6{sign}}, op1[5:0]   & { 6 {op2[26]}}, 26'b0};
assign product[27]  = {{ 5{sign}}, op1[4:0]   & { 5 {op2[27]}}, 27'b0};
assign product[28]  = {{ 4{sign}}, op1[3:0]   & { 4 {op2[28]}}, 28'b0};
assign product[29]  = {{ 3{sign}}, op1[2:0]   & { 3 {op2[29]}}, 29'b0};
assign product[30]  = {{ 2{sign}}, op1[1:0]   & { 2 {op2[30]}}, 30'b0};
assign product[31]  = {{ sign,    op1[0]     & op2[31]    , 31'b0}};

//---------------------------
//-- CSA instanciation 
//---------------------------
generate
for (genvar i = 0; i <= 9; i++) begin
    csa csa1 (
        .A(product[0 + 3*i]),
        .B(product[1 + 3*i]),
        .C(product[2 + 3*i]),
        .S0(product_s1[0 + 2*i]),
        .S1(product_s1[1 + 2*i])
    );
end
endgenerate

generate
for (genvar i = 0; i <= 5; i++) begin
    csa csa2 (
        .A(product_s1[0 + 3*i]),
        .B(product_s1[1 + 3*i]),
        .C(product_s1[2 + 3*i]),
        .S0(product_s2[0 + 2*i]),
        .S1(product_s2[1 + 2*i])
    );
end
endgenerate

csa csa2_6 (
    .A(product_s1[18]),
    .B(product_s1[19]),
    .C(product[30]),
    .S0(product_s2[12]),
    .S1(product_s2[13])
);

generate
  for (genvar i = 0; i <= 3; i++) begin : csa_instance
    csa csa3 (
        .A(product_s2[0 + 3*i]),
        .B(product_s2[1 + 3*i]),
        .C(product_s2[2 + 3*i]),
        .S0(product_s3[0 + 2*i]),
        .S1(product_s3[1 + 2*i])
    );
  end
endgenerate


csa csa3_4 (
  .A(product_s2[12]),
  .B(product_s2[13]),
  .C(product[31]),
  .S0(product_s3[8]),
  .S1(product_s3[9])
);

generate
  for (genvar i = 0; i < 3; i++) begin : stage4
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
  for (genvar i = 0; i < 2; i++) begin : stage5
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

//-- fifo x0x1 input 
assign x0x1_din[321] = select_msb_sx0;
assign x0x1_din[320] = signed_res_sx0;
assign x0x1_din[319:256] = product_s3[9];
assign x0x1_din[255:192] = product_s5[3];
assign x0x1_din[191:128] = product_s5[2];
assign x0x1_din[127:64] = product_s5[1];
assign x0x1_din[63:0] = product_s5[0];

//-- fifo x0x1 ouput 
assign SELECT_MSB_RX0 = x0x1_dout[321];
assign SIGNED_RES_RX0 = x0x1_dout[320];
assign RES_RX0 = x0x1_dout[319:0];

endmodule
