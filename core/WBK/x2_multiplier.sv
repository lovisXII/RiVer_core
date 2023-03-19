module x2_multiplier (
    input logic clk,
    input logic reset_n,
    input logic [127:0] RES_RX1,
    input logic SELECT_MSB_RX1,
    input logic SIGNED_RES_RX1,
    input logic X1X2_EMPTY_SX1,
    output logic [31:0] RES_RX2,
    output logic X1X2_POP_SX2
);

    logic [63:0] res;


    assign res = RES_RX1[63:0] + RES_RX1[128:64];
    
    assign RES_RX2 = (SELECT_MSB_RX1) ? res[63:32] : res[31:0];
    assign X1X2_POP_SX2 = !X1X2_EMPTY_SX1;

endmodule
