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
    logic [31:0] reg0, reg1, reg2, reg3, reg4, reg5, reg6, reg7, reg8, reg9, reg10, reg11, reg12, reg13, reg14, reg15, reg16, reg17, reg18, reg19, reg20, reg21, reg22, reg23, reg24, reg25, reg26, reg27, reg28, reg29, reg30, reg31;

    always_ff @(posedge clk, negedge reset_n) begin        
        if (~reset_n) begin
            // init all registers except PC to 0
            for (int i = 0; i < 32; i++) begin 
                registers[i] <= 32'h0;
            end
            registers[32] <= PC_INIT; 
        end else begin
            if (WRITE_PC_ENABLE_SD) begin
                registers[32] <= WRITE_PC_SD; 
            end
            if ((&WADR_SW != 1'b1) || (WRITE_PC_ENABLE_SD == 1'b0)) begin
                if (WADR_SW != 6'b0) begin
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


    assign reg0     = registers[0];    
    assign reg1     = registers[1];
    assign reg2     = registers[2];
    assign reg3     = registers[3];
    assign reg4     = registers[4];
    assign reg5     = registers[5];
    assign reg6     = registers[6];    
    assign reg7     = registers[7];
    assign reg8     = registers[8];
    assign reg9     = registers[9];
    assign reg10    = registers[10];
    assign reg11    = registers[11];
    assign reg12    = registers[12];    
    assign reg13    = registers[13];
    assign reg14    = registers[14];
    assign reg15    = registers[15];
    assign reg16    = registers[16];
    assign reg17    = registers[17];
    assign reg18    = registers[18];
    assign reg19    = registers[19];
    assign reg20    = registers[20];    
    assign reg21    = registers[21];
    assign reg22    = registers[22];
    assign reg23    = registers[23];
    assign reg24    = registers[24];
    assign reg25    = registers[25];
    assign reg26    = registers[26];    
    assign reg27    = registers[27];
    assign reg28    = registers[28];
    assign reg29    = registers[29];
    assign reg30    = registers[30];
    assign reg31    = registers[31];

endmodule