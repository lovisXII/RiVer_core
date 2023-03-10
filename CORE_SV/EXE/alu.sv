module alu(
    input logic [31:0] OP1_SE,
    input logic [31:0] OP2_SE,
    input logic CIN_SE,
    input logic [1:0] CMD_SE,
    output logic [31:0] RES_SE
);

    logic [31:0] carry = {32'd0, CIN_SE};

    always_comb begin
        case (CMD_SE)
            2'b00: RES_SE = $signed(OP1_SE) + $signed(OP2_SE) + $signed(carry);
            2'b01: RES_SE = OP1_SE & OP2_SE;
            2'b10: RES_SE = OP1_SE | OP2_SE;
            2'b11: RES_SE = OP1_SE ^ OP2_SE;
            default: RES_SE = '0;
        endcase
    end

endmodule