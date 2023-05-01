import riscv::*;

module rename (
    // Need to send information from the queues
    input logic arithm_rd_v_i,
    input logic arithm_rd_i,
    input logic arithm_rd_data_i,

    input logic arithm_rs1_v_i,
    input logic arithm_rs1_i,
    input logic arithm_rs1_data_i,
    
    input logic arithm_rs2_v_i,
    input logic arithm_rs2_i,
    input logic arithm_rs2_data_i,

    
    input logic branch_instr,
    input logic lsu_instr
)
// Each queue can issue one instr per cycle, need to send it to the right unit
// Total of 3 queues :
// * arithm queue for arith operations
// * branch queue for branch operation
// * load/store queue for memory access
logic cmd;
logic unit;
endmodule