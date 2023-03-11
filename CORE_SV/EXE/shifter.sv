module shifter(
    input logic [31:0] DIN_SE,
    input logic [4:0] SHIFT_VAL_SE,
    input logic [1:0] CMD_SE,
    output logic [31:0] DOUT_SE
);

    logic [31:0] lshift16, lshift8, lshift4, lshift2, lshift1;
    logic [31:0] rshift16, rshift8, rshift4, rshift2, rshift1;

    logic [15:0] bits16;
    logic [7:0] bits8;
    logic [3:0] bits4;
    logic [1:0] bits2;
    logic bit1;

    // select right shifting bits in case of arithmetic shift
    assign bits16   = (CMD_SE[1])       ? {16{DIN_SE[31]}}          : 16'h0000;
    assign bits8    = (CMD_SE[1])       ? {8{DIN_SE[31]}}           : 8'h00;
    assign bits4    = (CMD_SE[1])       ? {4{DIN_SE[31]}}           : 4'h0;
    assign bits2    = (CMD_SE[1])       ? {2{DIN_SE[31]}}           : 2'h0;
    assign bit1     = (CMD_SE[1])       ? DIN_SE[31]                : 1'b0;

    // Shift Right
    assign rshift16 = (SHIFT_VAL_SE[4]) ? {bits16, DIN_SE[31:16]}   : DIN_SE;
    assign rshift8  = (SHIFT_VAL_SE[3]) ? {bits8, rshift16[31:8]}   : rshift16;
    assign rshift4  = (SHIFT_VAL_SE[2]) ? {bits4, rshift8[31:4]}    : rshift8;
    assign rshift2  = (SHIFT_VAL_SE[1]) ? {bits2, rshift4[31:2]}    : rshift4;
    assign rshift1  = (SHIFT_VAL_SE[0]) ? {bit1, rshift2[31:1]}     : rshift2;

    // Shift Left
    assign lshift16 = (SHIFT_VAL_SE[4]) ? {DIN_SE[15:0], 16'h0000}  : DIN_SE;
    assign lshift8  = (SHIFT_VAL_SE[3]) ? {lshift16[23:0], 8'h00}   : lshift16;
    assign lshift4  = (SHIFT_VAL_SE[2]) ? {lshift8[27:0], 4'h0}     : lshift8;
    assign lshift2  = (SHIFT_VAL_SE[1]) ? {lshift4[29:0], 2'h0}     : lshift4;
    assign lshift1  = (SHIFT_VAL_SE[0]) ? {lshift2[30:0], 1'b0}     : lshift2;

    // Output selection
    assign DOUT_SE = (CMD_SE == 2'b00) ? lshift1 : rshift1;

endmodule
