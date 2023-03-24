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
logic       is_immediat;

assign opcode   = instr_i[6:0];
assign rd       = instr_i[11:7];
assign funct3   = instr_i[14:12];
assign rs1      = instr_i[19:15];
assign rs2      = instr_i[24:20];
assign funct7   = instr_i[31:25];

endmodule