module register_file(
    input logic clk,
    input logic reset_n,
    input logic [31:0] PC_INIT,

    // read ports
    output logic [31:0] RDATA1_SR,
    output logic [31:0] RDATA2_SR,
    input logic [5:0] RADR1_SD,
    input logic [5:0] RADR2_SD,

    // write ports
    input logic [31:0] WDATA_SW,
    input logic [5:0] WADR_SW,
    input logic WENABLE_SW,

    input logic [31:0] WRITE_PC_SD,
    input logic WRITE_PC_ENABLE_SD,

    // PC
    output logic [31:0] READ_PC_SR
);

    logic [31:0] registers [0:32];

    always_ff @(posedge clk, negedge reset_n) begin        
        if (~reset_n) begin
            // init all registers except PC to 0
            for (int i = 0; i < 32; i++) begin 
                registers[i] <= 32'h00000000;
            end
            registers[32] <= PC_INIT; 
        end else begin
            if (WRITE_PC_ENABLE_SD) begin
                registers[32] <= WRITE_PC_SD; 
            end
            if ((WADR_SW != 6'd63) || (WRITE_PC_ENABLE_SD == 0)) begin
                if (WADR_SW != 6'd0) begin
                    if (WENABLE_SW) begin
                        registers[WADR_SW] <= WDATA_SW; 
                    end
                end
            end
        end
    end

    assign RDATA1_SR = registers[RADR1_SD];
    assign RDATA2_SR = registers[RADR2_SD];
    assign READ_PC_SR = registers[32];

endmodule