module decoder import riscv_pkg::*;(
    input logic[XLEN-1:0] instr_i;
    input logic[XLEN-1:0] pc_i;
);

logic[6:0]  opcode;
logic[4:0]  rd;
logic[4:0]  rs1;
logic[4:0]  rs2;
logic[2:0]  funct3;
logic[6:0]  funct7;
logic       rd_v;
logic       rs1_v;
logic       rs2_v;
logic       rs2_is_immediat;
logic       is_load;
logic       is_store;

logic r_type;
logic i_type;
logic s_type;
logic b_type;
logic u_type;
logic j_type;

assign opcode   = instr_i[6:0];
assign rd       = instr_i[11:7];
assign funct3   = instr_i[14:12];
assign rs1      = instr_i[19:15];
assign rs2      = instr_i[24:20];
assign funct7   = instr_i[31:25];

case(opcode)
    7'b0110011: 
        r_type          = 1'b1;
        rd_v            = 1'b1;
        rs1_v           = 1'b1;
        rs2_v           = 1'b1;
        rs2_is_immediat     = 1'b0;
    7'b0010011:
        i_type          = 1'b1;
        rd_v            = 1'b1;
        rs1_v           = 1'b1;
        rs2_v           = 1'b0;
        rs2_is_immediat     = 1'b1;
    7'b0000011:         // loads
        i_type          = 1'b1;
        rd_v            = 1'b1;
        rs1_v           = 1'b1;
        rs2_v           = 1'b0;
        rs2_is_immediat    = 1'b1;
        is_load         = 1'b1;
    7'b0100011: 
        s_type          = 1'b1;
        rd_v            = 1'b0;
        rs1_v           = 1'b1;
        rs2_v           = 1'b1;
        rs2_is_immediat    = 1'b1;
        is_store        = 1'b1;
    7'b1100011: 
        b_type          = 1'b0;
        rd_v            = 1'b1;
        rs1_v           = 1'b1;
        rs2_v           = 1'b1;
        rs2_is_immediat    = 1'b1;
    7'b0110111: 
        u_type          = 1'b1;
        rd_v            = 1'b1;
        rs1_v           = 1'b0;
        rs2_v           = 1'b0;
        rs2_is_immediat = 1'b1;
    7'b1101111: 
        j_type          = 1'b1;
        rd_v            = 1'b1;
        rs1_v           = 1'b1;
        rs2_v           = 1'b1;
        rs2_is_immediat    = 1'b1;
endcase

endmodule