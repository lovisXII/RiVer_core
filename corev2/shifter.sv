module Shifter #(parameter int bitWidth = 32) 
(
    input logic[bitWidth-1:0]   shiftedSignal_i,
    input logic[bitWidth-1:0]   shiftSignal_i,
    input logic[2:0]            cmd_i,
    output logic[bitWidth-1:0]  out_o
);

always_comb begin
    case(cmd)
    3'b001 : out = shiftedSignal << shiftSignal;//001 Sll
    3'b010 : out = shiftedSignal >> shiftSignal;//010 Srl
    3'b100 : out = $signed(shiftedSignal) >>> shiftSignal;//100 Sra
    default:; 
    endcase
end
endmodule