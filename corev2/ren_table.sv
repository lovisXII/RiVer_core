/*
    ##### Renaming Table #####

    This module hold the mapping of every architectural register <-> physical register.
    * It allow the write of 2 physical register per cycle from the rename.
    * It means that when rename is renaming a destination register, the physical register choosed must
      be written here
    * It has 4 read ports, one for each source send by the rename engine
    * THe rename send the architectural register and the register table answer with the right 
      physical register
*/
import riscv::*;
module ren_table(
    input logic clk,
    input logic resetn,
    // Write port instr 0
    input logic                             instr0_v_rd,
    input logic [PHYS_REGS_ADDR_SIZE-1:0]   instr0_phys_rd,
    input logic [4:0]                       instr0_rd,
    // Write port instr 1
    input logic                             instr1_v_rd,
    input logic [PHYS_REGS_ADDR_SIZE-1:0]   instr1_phys_rd,
    input logic [4:0]                       instr1_rd,
    // Read port instr 0
    input logic                             instr0_v_src0,
    input logic                             instr0_v_src1,
    input logic [4:0]                       instr0_src0,
    input logic [4:0]                       instr0_src1,

    output logic [PHYS_REGS_ADDR_SIZE-1:0]  instr0_phys_src0,
    output logic [PHYS_REGS_ADDR_SIZE-1:0]  instr0_phys_src1,
    // Read port instr 1
    input logic                             instr1_v_src0,
    input logic                             instr1_v_src1,
    input logic [4:0]                       instr1_src0,
    input logic [4:0]                       instr1_src1,

    output logic [PHYS_REGS_ADDR_SIZE-1:0]  instr1_phys_src0,
    output logic [PHYS_REGS_ADDR_SIZE-1:0]  instr1_phys_src1
);
// The array is indexed by the architectural register
// It holds the value of the physical register mapped to the architectural
logic [XLEN_SIZE-1:0][PHYS_REGS_ADDR_SIZE-1:0] archi_reg_q;
logic [PHYS_REGS_ADDR_SIZE-1:0]                next_archi_reg0;
logic [PHYS_REGS_ADDR_SIZE-1:0]                next_archi_reg1;


// Writing the new physical register
assign next_archi_reg0 = ({PHYS_REGS_ADDR_SIZE{instr0_v_rd}} & instr0_phys_rd);
assign next_archi_reg1 = ({PHYS_REGS_ADDR_SIZE{instr1_v_rd}} & instr1_phys_rd);

generate
    for(genvar i = 0; i < XLEN; i++)
        always_ff @(posedge clk, negedge resetn)
            if (!resetn) begin
                archi_reg_q[i]     <= '0;
            end else if(i == instr0_rd && instr0_v_rd) begin
                archi_reg_q[i]     <= next_archi_reg0;
            end else if(i == instr1_rd && instr1_v_rd) begin
                archi_reg_q[i]     <= next_archi_reg1;
            end
endgenerate
endmodule