module Arithm #(parameter int bitWidth = 32)
(
    input  logic[bitWidth-1:0]   rs1_i,
    input  logic[bitWidth-1:0]   rs2_i,
    input  logic[10:0]           control_i,
    output logic[bitWidth-1:0]   out_o
);

logic[5:0] operation;
logic[1:0] cmd;
logic Cin;
logic[bitWidth-1:0] rs1_op,rs2_op; //rs1 rs2 op
logic[bitWidth-1:0] shifterOut; // output of shifter
logic[bitWidth-1:0] aluOut; //output of alu
logic[bitWidth-1:0] multAluOut; // output of the multiplexer after the alu who chosse between the alu output and comparaison output
logic[1:0] aluCmd; 
logic[2:0] shiftCmd;
logic[bitWidth-1:0] zeroComparator;

ALU #(.bitWidth(bitWidth)) 
alu(
    .rs1(rs1_op),
    .rs2(rs2_op),
    .Cin(Cin),
    .cmd(aluCmd),
    .out(aluOut)
);

Shifter #(.bitWidth(bitWidth)) 
shifter(
    .shiftedSignal(rs1_op),
    .shiftSignal(rs2_op),
    .cmd(shiftCmd),
    .out(shifterOut)
);

assign rs1_op = rs1;
assign rs2_op =((operation[1] | operation[5]) & cmd[0] ) ? ~(rs2) : rs2; // If we have a sub or slt we take one complement of rs2 , else we take rs2
assign Cin    = operation[1] | operation[5]; //if we have a sub or slt signal Cin = 1 

assign operation = control[5:0];
assign cmd       = control[7:6];

always_comb begin //ALU CMD
    case(operation)
        6'b000001 : aluCmd = 2'b00; //Add
        6'b000010 : aluCmd = 2'b00; // Sub = Add C2
        6'b000100 : aluCmd = 2'b01;//And
        6'b001000 : aluCmd = 2'b10;//Or
        6'b010000 : aluCmd = 2'b11;//Xor
        6'b100000 : aluCmd = 2'b00; // Sub and compare
        default;;
    endcase
end

assign shiftCmd       = operation[2:0]; //shift cmd
assign zeroComparator = aluOut[31] ;//return 1 if output of ALU is greater than 0
assign multAluOut     = operation[5] ? zeroComparator : aluOut; // if we have slt instruction we take the comparator output else alu output

always_comb begin //output mult
    case(cmd)
    2'b01 : out = multAluOut;
    2'b10 : out = shifterOut;
    default: ;
    endcase
end


endmodule
