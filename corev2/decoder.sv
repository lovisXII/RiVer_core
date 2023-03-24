

module decoder #(
    localparam  XLEN = 64
)(
    input logic[XLEN-1:0] instr_i,
    input logic[XLEN-1:0] pc_i

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

case(opcode)
    7'b0110011: assign r_type          = 1'b1;
    7'b0010011: assign i_type          = 1'b1;
    7'b0000011: assign i_type          = 1'b1;
    7'b0100011: assign s_type          = 1'b1;
    7'b1100011: assign b_type          = 1'b0;
    7'b0110111: assign u_type          = 1'b1;
    7'b1101111: assign j_type          = 1'b1;
endcase

casex({opcode, funct3, funct7})
    // r-type
    {r_type, 3'b000, 7'b0000000} : assign add   = 1'b1;
    {r_type, 3'b000, 7'b0100000} : assign sub   = 1'b1;
    {r_type, 3'b001, 7'b0000000} : assign sll   = 1'b1;
    {r_type, 3'b010, 7'b0000000} : assign slt   = 1'b1;
    {r_type, 3'b011, 7'b0000000} : assign sltu  = 1'b1;
    {r_type, 3'b100, 7'b0000000} : assign xorr  = 1'b1;
    {r_type, 3'b101, 7'b0000000} : assign srl   = 1'b1;
    {r_type, 3'b101, 7'b0100000} : assign sra   = 1'b1;
    {r_type, 3'b110, 7'b0000000} : assign orr   = 1'b1;
    {r_type, 3'b111, 7'b0000000} : assign andd  = 1'b1;
    // i-type
    {i_type, 3'b000, 7'b???????} : assign addi  = 1'b1;
    {i_type, 3'b010, 7'b???????} : assign slti  = 1'b1;
    {i_type, 3'b011, 7'b???????} : assign sltiu = 1'b1;
    {i_type, 3'b100, 7'b???????} : assign xori  = 1'b1;
    {i_type, 3'b110, 7'b???????} : assign ori   = 1'b1;
    {i_type, 3'b111, 7'b???????} : assign andi  = 1'b1;
    {i_type, 3'b001, 7'b???????} : assign slli  = 1'b1;
    {i_type, 3'b101, 7'b???????} : assign srli  = 1'b1;
    {i_type, 3'b101, 7'b???????} : assign srai  = 1'b1;
endcase


assign rd_v = r_type | i_type | u_type;

endmodule