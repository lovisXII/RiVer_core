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
logic s_type;
logic b_type;
logic u_type;
logic j_type;

logic lui;
logic auipc;
logic jal;
logic jalr;
logic beq;
logic bne;
logic blt;
logic bge;
logic bgeu; 
logic lb ;
logic lh ;
logic lw ;
logic lbu ;
logic lhu; 
logic sb;
logic sh ;
logic sw ;
logic addi ;
logic slti ;
logic sltiu ;
logic xori ;
logic ori ;
logic andi ;
logic slli ;
logic srli ;
logic srai ;
logic add ;
logic sub ;
logic sll ;
logic slt ;
logic sltu ;
logic xorr ;
logic srl ;
logic sra ;
logic orr ;
logic andd ;
logic fence ;
logic ecall;
logic ebreak;
logic lwu ;
logic ld ;
logic sd ;
logic addiw ;
logic slliw ;
logic srliw ;
logic sraiw ; 
logic addw ;
logic subw ;
logic sllw ;
logic srlw ;
logic sraw ;
logic csrrw;
logic csrrs;
logic csrrc;
logic csrrwi;
logic csrrsi;
logic csrrci;
logic mul;
logic mulh ;
logic mulhsu;
logic mulhu;
logic div ;
logic divu ;
logic rem ;
logic remu ;
logic mulw ;
logic divw ;
logic divuw ;
logic remw ;
logic remuw; 



assign opcode   = instr_i[6:0];
assign rd       = instr_i[11:7];
assign funct3   = instr_i[14:12];
assign rs1      = instr_i[19:15];
assign rs2      = instr_i[24:20];
assign funct7   = instr_i[31:25];

assign add   =  opcode == R_TYPE & funct3 == 3'b000 & funct7 == 7'b0000000;  
assign sub   =  opcode == R_TYPE & funct3 == 3'b000 & funct7 == 7'b0100000;  
assign sll   =  opcode == R_TYPE & funct3 == 3'b001 & funct7 == 7'b0000000;  
assign slt   =  opcode == R_TYPE & funct3 == 3'b010 & funct7 == 7'b0000000;  
assign sltu  =  opcode == R_TYPE & funct3 == 3'b011 & funct7 == 7'b0000000;  
assign xorr  =  opcode == R_TYPE & funct3 == 3'b100 & funct7 == 7'b0000000;  
assign srl   =  opcode == R_TYPE & funct3 == 3'b101 & funct7 == 7'b0000000;  
assign sra   =  opcode == R_TYPE & funct3 == 3'b101 & funct7 == 7'b0100000;  
assign orr   =  opcode == R_TYPE & funct3 == 3'b110 & funct7 == 7'b0000000;  
assign andd  =  opcode == R_TYPE & funct3 == 3'b111 & funct7 == 7'b0000000;  

assign addi  =  opcode == I_TYPE &  funct3 == 3'b000;  
assign slti  =  opcode == I_TYPE &  funct3 == 3'b010;  
assign sltiu =  opcode == I_TYPE &  funct3 == 3'b011;  
assign xori  =  opcode == I_TYPE &  funct3 == 3'b100;  
assign ori   =  opcode == I_TYPE &  funct3 == 3'b110;  
assign andi  =  opcode == I_TYPE &  funct3 == 3'b111;  
assign slli  =  opcode == I_TYPE &  funct3 == 3'b001;  
assign srli  =  opcode == I_TYPE &  funct3 == 3'b101;  
assign srai  =  opcode == I_TYPE &  funct3 == 3'b101;  


assign rd_v = r_type | i_type | u_type;

endmodule