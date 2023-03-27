`include "riscv_pkg.sv" 


module decoder(
    input logic[31:0] instr_i,
    input logic[31:0] pc_i

);
import riscv::*;
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
logic l_type;
logic s_type;
logic b_type;
logic u_type;
logic p_type;
logic fence;
logic auipc;
logic jalr;
logic jal;

logic illegal_inst;

logic lui;
logic beq;
logic bne;
logic blt;
logic bge;
logic bltu;
logic bgeu; 
logic lb;
logic lh;
logic lw;
logic lbu;
logic lhu; 
logic sb;
logic sh;
logic sw;
logic addi;
logic slti;
logic sltiu;
logic xori;
logic ori;
logic andi;
logic slli;
logic srli;
logic srai;
logic add;
logic sub;
logic sll;
logic slt;
logic sltu;
logic xorr;
logic srl;
logic sra;
logic orr;
logic andd;
logic ecall;
logic ebreak;
logic lwu;
logic ld;
logic sd;
logic addiw;
logic slliw;
logic srliw;
logic sraiw; 
logic addw;
logic subw;
logic sllw;
logic srlw;
logic sraw;
logic csrrw;
logic csrrs;
logic csrrc;
logic csrrwi;
logic csrrsi;
logic csrrci;
logic mul;
logic mulh;
logic mulhsu;
logic mulhu;
logic div;
logic divu;
logic rem;
logic remu;
logic mulw;
logic divw;
logic divuw;
logic remw;
logic remuw; 
logic mret;
logic sret;



assign opcode   = instr_i[6:0];
assign rd       = instr_i[11:7];
assign funct3   = instr_i[14:12];
assign rs1      = instr_i[19:15];
assign rs2      = instr_i[24:20];
assign funct7   = instr_i[31:25];

assign r_type        = opcode == R_TYPE;
assign i_type        = opcode == I_TYPE;
assign l_type        = opcode == L_TYPE;
assign s_type        = opcode == S_TYPE;
assign b_type        = opcode == B_TYPE;
assign u_type        = opcode == U_TYPE;
assign p_type        = opcode == P_TYPE;
assign fence         = opcode == FENCE;

assign illegal_inst = ~r_type & ~i_type & ~l_type & ~s_type & ~b_type & ~u_type & 
                      ~p_type & ~fence & opcode != AUIPC & opcode != JAL &
                      ~opcode == JALR;
//-------------------------
// Instruction decoding
//-------------------------
// R-Type
assign add    =  r_type & funct3 == 3'b000 & funct7 == 7'b0000000;  
assign sub    =  r_type & funct3 == 3'b000 & funct7 == 7'b0100000;  
assign sll    =  r_type & funct3 == 3'b001 & funct7 == 7'b0000000;  
assign slt    =  r_type & funct3 == 3'b010 & funct7 == 7'b0000000;  
assign sltu   =  r_type & funct3 == 3'b011 & funct7 == 7'b0000000;  
assign xorr   =  r_type & funct3 == 3'b100 & funct7 == 7'b0000000;  
assign srl    =  r_type & funct3 == 3'b101 & funct7 == 7'b0000000;  
assign sra    =  r_type & funct3 == 3'b101 & funct7 == 7'b0100000;  
assign orr    =  r_type & funct3 == 3'b110 & funct7 == 7'b0000000;  
assign andd   =  r_type & funct3 == 3'b111 & funct7 == 7'b0000000; 
// I-type
assign addi   =  i_type &  funct3 == 3'b000;  
assign slti   =  i_type &  funct3 == 3'b010;  
assign sltiu  =  i_type &  funct3 == 3'b011;  
assign xori   =  i_type &  funct3 == 3'b100;  
assign ori    =  i_type &  funct3 == 3'b110;  
assign andi   =  i_type &  funct3 == 3'b111;  
assign slli   =  i_type &  funct3 == 3'b001;  
assign srli   =  i_type &  funct3 == 3'b101;  
assign srai   =  i_type &  funct3 == 3'b101;  
// B-type
assign beq    =  b_type &  funct3 == 3'b000;
assign bne    =  b_type &  funct3 == 3'b001;
assign blt    =  b_type &  funct3 == 3'b100;
assign bge    =  b_type &  funct3 == 3'b101;
assign bltu   =  b_type &  funct3 == 3'b110;
assign bgeu   =  b_type &  funct3 == 3'b111;
// U-type
assign lui    = u_type;
assign auipc  = opcode == AUIPC;
// J-type
assign jal    = opcode == JAL;
assign jalr   = opcode == JALR;
// L-type
assign lw     = l_type & funct3 == 3'b010;
assign lh     = l_type & funct3 == 3'b001;
assign lhu    = l_type & funct3 == 3'b101;
assign lb     = l_type & funct3 == 3'b000;
assign lbu    = l_type & funct3 == 3'b100;
// S-type
assign sw     = s_type & funct3 == 3'b010;
assign sh     = s_type & funct3 == 3'b001;
assign sb     = s_type & funct3 == 3'b000;
// P-type
assign ecall  = p_type & funct3 == 3'h0 & ~instr_i[20];
assign ebreak = p_type & funct3 == 3'h0 &  instr_i[20];
assign csrrw  = p_type & funct3 == 3'h1;
assign csrrs  = p_type & funct3 == 3'h2;
assign csrrc  = p_type & funct3 == 3'h3;
assign csrrwi = p_type & funct3 == 3'h5;
assign csrrsi = p_type & funct3 == 3'h6;
assign csrrci = p_type & funct3 == 3'h7;
assign fence  = fence  & funct3 == 3'b001;

assign mret   = instr_i == 32'h30200073;
assign sret   = instr_i == 32'h10200073;

assign rd_v = r_type | i_type | u_type;

endmodule