module wbk (
    input logic clk,
    input logic reset_n,
    input logic [31:0] MEM_RES_RM,
    input logic [5:0] MEM_DEST_RM,
    input logic WB_RM,
    input logic [31:0] PC_MEM2WBK_RM,
    input logic [31:0] CSR_RDATA_RM,
    input logic CSR_WENABLE_RM,
    input logic [1:0] CURRENT_MODE_SM,
    input logic MEM2WBK_EMPTY_SM,
    output logic MEM2WBK_POP_SW,
    input logic MULT_INST_RM,
    input logic [31:0] RES_RX2,
    output logic [31:0] DATA_SW,
    output logic [5:0] DEST_SW,
    output logic WB_SW
);

assign DEST_SW = MEM_DEST_RM;

assign WB_SW = (WB_RM && !MEM2WBK_EMPTY_SM) ? 1'b1 : 1'b0;

assign MEM2WBK_POP_SW = !MEM2WBK_EMPTY_SM;

assign DATA_SW = CSR_WENABLE_RM ? CSR_RDATA_RM :
                 MULT_INST_RM ? RES_RX2 :
                 MEM_RES_RM;

endmodule