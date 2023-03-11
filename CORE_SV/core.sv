module core (
        // global interface
        input logic clk, reset_n,

        // Mcache interface
        input logic [31:0] MCACHE_RESULT_SM,
        input logic MCACHE_STALL_SM,

        output logic MCACHE_ADR_VALID_SM, MCACHE_STORE_SM, MCACHE_LOAD_SM,
        output logic[31:0] MCACHE_DATA_SM,
        output logic[31:0] MCACHE_ADR_SM, 
        output logic[3:0]  byt_sel, 

        // Icache interface
        input logic[31:0]   IC_INST_SI,
        input logic         IC_STALL_SI, 

        output logic[31:0] ADR_SI,
        output logic ADR_VALID_SI, 

        // Debug 
        input logic[31:0] PC_INIT,
        output logic[31:0] DEBUG_PC_READ 
);
endmodule