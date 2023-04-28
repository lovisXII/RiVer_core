`include "riscv_pkg.sv" 
import riscv::*;

module decoder (
  input logic [XLEN-1:0]             instr_i,
  input logic [XLEN-1:0]             pc_i,

  // Registers
  output logic                       rd_v_o, 
  output logic [4:0]                 rd_o, 
  output logic                       rs1_v_o,
  output logic [4:0]                 rs1_o,
  output logic                       rs2_v_o, 
  output logic [4:0]                 rs2_o,   
  // Additionnal informations
  output logic                       rs2_is_immediat_o, 
  output logic                       is_store_o,        
  output logic                       is_load_o,          
  output logic                       is_branch_o,         
  output logic [31:0]                immediat_o,
  output logic [2:0]                 access_size_o,
  output logic [12:0]                instr_type_o,
  output logic                       unsign_extension         
);


/*
  Instr_type encoding :

  r_type   0000000000001
  i_type   0000000000010
  l_type   0000000000100
  s_type   0000000001000
  b_type   0000000010000
  u_type   0000000100000
  p_type   0000001000000
  fence    0000010000000
  auipc    0000100000000
  jalr     0001000000000
  jal      0010000000000
  r64_type 0100000000000
  i64_type 1000000000000
*/
// Registers
logic rs1_v;
logic rs2_v;
logic rd_v;
// instr id parts 
logic[6:0]  opcode;
logic[4:0]  rd;
logic[4:0]  rs1;
logic[4:0]  rs2;
logic[2:0]  funct3;
logic[6:0]  funct7;
// Instruction type 
logic r_type;
logic i_type;
logic l_type;
logic s_type;
logic b_type;
logic u_type;
logic p_type;
logic r64_type;
logic i64_type;
// Illegal instruction
logic illegal_inst;
logic unknow_opc;
// Instructions
// R-Type
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
logic mul; 
logic mulh;
logic mulhsu;
logic mulhu;
logic div;
logic divu;
logic rem;
logic remu;
// I-type
logic addi;  
logic slti;  
logic sltiu;  
logic xori;  
logic ori;  
logic andi;  
logic slli;  
logic srli;  
logic srai;   
// B-type
logic beq;
logic bne;
logic blt;
logic bge;
logic bltu;
logic bgeu;
// U-type
logic lui;
logic auipc;
// J-type
logic jal;
logic jalr;
// L-type
logic lw;
logic lh;
logic lhu;
logic lb;
logic lbu;
logic lwu;
logic ld;
// S-type
logic sw;
logic sh;
logic sb;
logic sd;
// P-type
logic ecall;
logic ebreak;
logic csrrw;
logic csrrs;
logic csrrc;
logic csrrwi;
logic csrrsi;
logic csrrci;
logic fence;

//-------------------------
// Instruction decoding
//-------------------------

assign opcode = instr_i[6:0];
assign funct3 = instr_i[14:12];
assign funct7 = instr_i[31:25];

always_comb begin
  case(opcode)
    R_TYPE   : r_type     = 1'b1;
    I_TYPE   : i_type     = 1'b1;
    L_TYPE   : l_type     = 1'b1;
    S_TYPE   : s_type     = 1'b1;
    B_TYPE   : b_type     = 1'b1;
    U_TYPE   : u_type     = 1'b1;
    P_TYPE   : p_type     = 1'b1;
    R64_TYPE : r64_type   = 1'b1;
    I64_TYPE : i64_type   = 1'b1;
    default  : 
              unknow_opc = 1'b1;
  endcase
  casez({opcode, funct3, funct7})
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
    {I_TYPE, 3'b001, 7'b0000000} : slli   = 1'b1;  
    {I_TYPE, 3'b101, 7'b0000000} : srli   = 1'b1;  
    {I_TYPE, 3'b101, 7'b0100000} : srai   = 1'b1;   
    // B-type
    {B_TYPE, 3'b000, 7'b???????} : beq    = 1'b1;
    {B_TYPE, 3'b001, 7'b???????} : bne    = 1'b1;
    {B_TYPE, 3'b100, 7'b???????} : blt    = 1'b1;
    {B_TYPE, 3'b101, 7'b???????} : bge    = 1'b1;
    {B_TYPE, 3'b110, 7'b???????} : bltu   = 1'b1;
    {B_TYPE, 3'b111, 7'b???????} : bgeu   = 1'b1;
    // U-type
    {U_TYPE, 3'b???, 7'b???????} : lui    = 1'b1;
    {AUIPC , 3'b???, 7'b???????} : auipc  = 1'b1;
    // J-type
    {JAL   , 3'b???, 7'b???????} : jal    = 1'b1;
    {JALR  , 3'b???, 7'b???????} : jalr   = 1'b1;
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
    {P_TYPE, 3'b000, 7'b0000000} : ecall  = ~instr_i[20];
    {P_TYPE, 3'b000, 7'b0000000} : ebreak =  instr_i[20];
    {P_TYPE, 3'b001, 7'b???????} : csrrw  = 1'b1;
    {P_TYPE, 3'b010, 7'b???????} : csrrs  = 1'b1;
    {P_TYPE, 3'b011, 7'b???????} : csrrc  = 1'b1;
    {P_TYPE, 3'b101, 7'b???????} : csrrwi = 1'b1;
    {P_TYPE, 3'b110, 7'b???????} : csrrsi = 1'b1;
    {P_TYPE, 3'b111, 7'b???????} : csrrci = 1'b1;
    {FENCE , 3'b000, 7'b???????} : fence  = 1'b1;
    default : illegal_inst = 1'b1;
  endcase
end

//-------------------------
// Register affectation
//-------------------------
// Destination register
assign rd_v_o = r_type | i_type | l_type | fence | p_type & ~(ecall | ebreak) | lui | auipc;
assign rd_v_o = rd_v;
assign rd_o   = {5{rd_v}} & instr_i[11:7];
// src1 register 
assign rs1_v   = r_type | i_type | jalr | b_type | s_type | l_type | fence 
               | p_type & ~(ecall | ebreak | csrrwi | csrrsi | csrrci);
assign rs1_v_o = rs1_v;
assign rs1_o   = {5{rd_v}} & instr_i[19:15];
// src2 register 
assign rs2_v   = r_type | b_type | s_type ;
assign rs2_v_o = rs2_v;
assign rs2_o   = {5{rd_v}} & instr_i[24:20];

// Additionnal informations
assign rs2_is_immediat_o = lui |auipc | jalr | jalr | l_type | i_type;
assign is_store_o        = s_type;
assign is_load_o         = lb | lh | lw | lbu | lhu;
assign is_branch_o       = b_type | jal | jalr; 
assign immediat_o        = {32{i_type | jalr}} & {20'b0, instr_i[31:20]} 
                         | {32{s_type}}        & {20'b0, instr_i[31:25],instr_i[11:7]} 
                         | {32{b_type}}        & {19'b0, instr_i[31],instr_i[7],instr_i[30:25],instr_i[11:8],1'b0} 
                         | {32{jal}}           & {11'b0, instr_i[31],instr_i[19:12],instr_i[20],instr_i[30:21],1'b0} 
                         | {32{auipc | lui}}   & {12'b0, instr_i[31:12]}; 
assign instr_type_o     = {r64_type, i64_type, jal, jalr, auipc, fence, p_type, u_type, b_type, s_type, l_type, i_type, r_type};              
assign access_size_o    = {3{lb | lbu | sb}} & 3'b001 | {3{lh | lhu | sh}} & 3'b010 | {3{lw | sw}} & 3'b100;
assign unsign_extension = bltu | bgeu | lbu | lhu | sltiu | sltu;  
endmodule