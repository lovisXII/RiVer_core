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
logic r64_type;
logic i64_type;

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

always_comb begin
      // update
  case(opcode)
    R_TYPE   : r_type   = 1'b1;
    I_TYPE   : i_type   = 1'b1;
    L_TYPE   : l_type   = 1'b1;
    S_TYPE   : s_type   = 1'b1;
    B_TYPE   : b_type   = 1'b1;
    U_TYPE   : u_type   = 1'b1;
    P_TYPE   : p_type   = 1'b1;
    FENCE    : fence    = 1'b1;
    R64_TYPE : r64_type = 1'b1;
    I64_TYPE : i64_type = 1'b1;
  endcase
  casez({opcode, funct3, funct7})

    //-------------------------
// Instruction decoding
//-------------------------
// R-Type
{R_TYPE, 3'b000, 7'b0000000} : add    = 1'b1;  
{R_TYPE, 3'b000, 7'b0100000} : sub    = 1'b1;  
{R_TYPE, 3'b001, 7'b0000000} : sll    = 1'b1;  
{R_TYPE, 3'b010, 7'b0000000} : slt    = 1'b1;  
{R_TYPE, 3'b011, 7'b0000000} : sltu   = 1'b1;  
{R_TYPE, 3'b100, 7'b0000000} : xorr   = 1'b1;  
{R_TYPE, 3'b101, 7'b0000000} : srl    = 1'b1;  
{R_TYPE, 3'b101, 7'b0100000} : sra    = 1'b1;  
{R_TYPE, 3'b110, 7'b0000000} : orr    = 1'b1;  
{R_TYPE, 3'b111, 7'b0000000} : andd   = 1'b1; 
{R_TYPE, 3'b000, 7'b0000001} : mul    = 1'b1; 
{R_TYPE, 3'b001, 7'b0000001} : mulh   = 1'b1;
{R_TYPE, 3'b010, 7'b0000001} : mulhsu = 1'b1;
{R_TYPE, 3'b011, 7'b0000001} : mulhu  = 1'b1;
{R_TYPE, 3'b100, 7'b0000001} : div    = 1'b1;
{R_TYPE, 3'b101, 7'b0000001} : divu   = 1'b1;
{R_TYPE, 3'b110, 7'b0000001} : rem    = 1'b1;
{R_TYPE, 3'b111, 7'b0000001} : remu   = 1'b1;
// I-type
{I_TYPE, 3'b000, 7'b???????} : addi   = 1'b1;  
{I_TYPE, 3'b010, 7'b???????} : slti   = 1'b1;  
{I_TYPE, 3'b011, 7'b???????} : sltiu  = 1'b1;  
{I_TYPE, 3'b100, 7'b???????} : xori   = 1'b1;  
{I_TYPE, 3'b110, 7'b???????} : ori    = 1'b1;  
{I_TYPE, 3'b111, 7'b???????} : andi   = 1'b1;  
{I_TYPE, 3'b001, 7'b???????} : slli   = 1'b1;  
{I_TYPE, 3'b101, 7'b?0?????} : srli   = 1'b1;  
{I_TYPE, 3'b101, 7'b?1?????} : srai   = 1'b1;   
// B-type
{B_TYPE, 3'b000, 7'b???????} : beq    = 1'b1;
{B_TYPE, 3'b001, 7'b???????} : bne    = 1'b1;
{B_TYPE, 3'b100, 7'b???????} : blt    = 1'b1;
{B_TYPE, 3'b101, 7'b???????} : bge    = 1'b1;
{B_TYPE, 3'b110, 7'b???????} : bltu   = 1'b1;
{B_TYPE, 3'b111, 7'b???????} : bgeu   = 1'b1;
// U-type
{U_TYPE, 3'b???, 7'b???????} : lui    = 1'b1;
{U_TYPE, 3'b???, 7'b???????} : auipc  = 1'b1;
// J-type
{B_TYPE, 3'b???, 7'b???????} : jal    = 1'b1;
{B_TYPE, 3'b???, 7'b???????} : jalr   = 1'b1;
// L-type
{L_TYPE, 3'b010, 7'b???????} : lw     = 1'b1;
{L_TYPE, 3'b001, 7'b???????} : lh     = 1'b1;
{L_TYPE, 3'b101, 7'b???????} : lhu    = 1'b1;
{L_TYPE, 3'b000, 7'b???????} : lb     = 1'b1;
{L_TYPE, 3'b100, 7'b???????} : lbu    = 1'b1;
{L_TYPE, 3'b110, 7'b???????} : lwu    = 1'b1;
{L_TYPE, 3'b011, 7'b???????} : ld     = 1'b1;
// S-type
{S_TYPE, 3'b010, 7'b???????} : sw     = 1'b1;
{S_TYPE, 3'b001, 7'b???????} : sh     = 1'b1;
{S_TYPE, 3'b000, 7'b???????} : sb     = 1'b1;
{S_TYPE, 3'b011, 7'b???????} : sd     = 1'b1;
// P-type
{P_TYPE, 3'h0   , 7'b0000001} : ecall  =  ~instr_i[20];
{P_TYPE, 3'h0   , 7'b0000001} : ebreak =  instr_i[20];
{P_TYPE, 3'h1   , 7'b0000001} : csrrw  = 1'b1;
{P_TYPE, 3'h2   , 7'b0000001} : csrrs  = 1'b1;
{P_TYPE, 3'h3   , 7'b0000001} : csrrc  = 1'b1;
{P_TYPE, 3'h5   , 7'b0000001} : csrrwi = 1'b1;
{P_TYPE, 3'h6   , 7'b0000001} : csrrsi = 1'b1;
{P_TYPE, 3'h7   , 7'b0000001} : csrrci = 1'b1;
{FENCE, 3'b001, 7'b0000001}   : fence  = 1'b1;
  endcase
//  sret   = instr_i == 32'h10200073;
//  mret   = instr_i == 32'h30200073;
end


endmodule