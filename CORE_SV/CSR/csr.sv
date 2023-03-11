import river_pkg::*;

module csr 
(
    input logic clk,
    input logic reset_n,
    input logic [11:0] CSR_WADR_SM,
    input logic [31:0] CSR_WDATA_SM,
    input logic CSR_ENABLE_SM,
    input logic EXCEPTION_SM,
    input logic [31:0] MSTATUS_WDATA_SM,
    input logic [31:0] MIP_WDATA_SM,
    input logic [31:0] MEPC_WDATA_SM,
    input logic [31:0] MCAUSE_WDATA_SM,
    input logic [31:0] MTVAL_WDATA_SM,
    output logic [31:0] MEPC_SC,
    output logic [31:0] MSTATUS_RC,
    output logic [31:0] MTVEC_VALUE_RC,
    output logic [31:0] MIP_VALUE_RC,
    output logic [31:0] MIE_VALUE_RC,
    output logic [31:0] MCAUSE_SC,
    input logic [11:0] CSR_RADR_SD,
    output logic [31:0] CSR_RDATA_SC
);

    // CSR registers
    logic [31:0] reg_mvendorid;
    logic [31:0] reg_marchid;
    logic [31:0] reg_mimpid;
    logic [31:0] reg_mstatus;
    logic [31:0] reg_misa;
    logic [31:0] reg_mie;
    logic [31:0] reg_mtvec;
    logic [31:0] reg_mstatush;
    logic [31:0] reg_mepc;
    logic [31:0] reg_mcause;
    logic [31:0] reg_mtval;
    logic [31:0] reg_mip;
    logic [31:0] reg_mscratch;


    // CSR address
    localparam logic [11:0] adr_mvendorid = 12'hF11;
    localparam logic [11:0] adr_marchid = 12'hF12;
    localparam logic [11:0] adr_mimpid = 12'hF13;
    localparam logic [11:0] adr_mstatus = 12'h300;
    localparam logic [11:0] adr_misa = 12'h301;
    localparam logic [11:0] adr_mie = 12'h304;
    localparam logic [11:0] adr_mtvec = 12'h305;
    localparam logic [11:0] adr_mstatush = 12'h310;
    localparam logic [11:0] adr_mepc = 12'h341;
    localparam logic [11:0] adr_mcause = 12'h342;
    localparam logic [11:0] adr_mtval = 12'h343;
    localparam logic [11:0] adr_mip = 12'h344;
    localparam logic [11:0] adr_mscratch = 12'h340;

    always_ff @(posedge clk, negedge reset_n) begin
        if (~reset_n) begin
            reg_mvendorid <= 32'h0;
            reg_marchid <= 32'h0;
            reg_mimpid <= 32'h0;
            reg_mstatus <= 32'h0;
            reg_misa <= 32'h40100100;
            reg_mie <= 32'h0;
            reg_mtvec <= 32'h0;
            reg_mstatush <= 32'h0;
            reg_mepc <= 32'h0;
            reg_mcause <= 32'h0;
            reg_mtval <= 32'h0;
            reg_mip <= 32'h0;
            reg_mscratch <= 32'h0;
            end 
        else begin
            if (EXCEPTION_SM) begin
            reg_mstatus <= MSTATUS_WDATA_SM;
            reg_mepc <= MEPC_WDATA_SM;
            reg_mcause <= MCAUSE_WDATA_SM;
            reg_mtval <= MTVAL_WDATA_SM;
            reg_mip <= MIP_WDATA_SM;
        end 
        else if (CSR_ENABLE_SM) begin
        case (CSR_WADR_SM)
            adr_mstatus: reg_mstatus <= CSR_WDATA_SM;
            adr_mie: reg_mie <= CSR_WDATA_SM;
            adr_mtvec: reg_mtvec <= CSR_WDATA_SM;
            adr_mepc: reg_mepc <= CSR_WDATA_SM;
            adr_mcause: reg_mcause <= CSR_WDATA_SM;
            adr_mtval: reg_mtval <= CSR_WDATA_SM;
            adr_mip: reg_mip <= CSR_WDATA_SM;
            adr_mscratch: reg_mscratch <= CSR_WDATA_SM;
        endcase
        end
        end
    end
// Read
assign CSR_RDATA_SC = (CSR_RADR_SD == adr_mvendorid) ? reg_mvendorid :
                      (CSR_RADR_SD == adr_marchid) ? reg_marchid :
                      (CSR_RADR_SD == adr_mimpid) ? reg_mimpid :
                      (CSR_RADR_SD == adr_mstatus) ? reg_mstatus :
                      (CSR_RADR_SD == adr_misa) ? reg_misa :
                      (CSR_RADR_SD == adr_mie) ? reg_mie :
                      (CSR_RADR_SD == adr_mtvec) ? reg_mtvec :
                      (CSR_RADR_SD == adr_mstatush) ? reg_mstatush :
                      (CSR_RADR_SD == adr_mepc) ? reg_mepc :
                      (CSR_RADR_SD == adr_mcause) ? reg_mcause :
                      (CSR_RADR_SD == adr_mtval) ? reg_mtval :
                      (CSR_RADR_SD == adr_mip) ? reg_mip :
                      (CSR_RADR_SD == adr_mscratch) ? reg_mscratch :
                      32'h0;

assign MEPC_SC = reg_mepc;
assign MSTATUS_RC = reg_mstatus;
assign MTVEC_VALUE_RC = reg_mtvec;
assign MIP_VALUE_RC = reg_mip;
assign MIE_VALUE_RC = reg_mie;
assign MCAUSE_SC = reg_mcause;
assign MEPC_SC = reg_mepc;
assign MSTATUS_RC = reg_mstatus;
assign MTVEC_VALUE_RC = reg_mtvec;
assign MIP_VALUE_RC = reg_mip;
assign MIE_VALUE_RC = reg_mie;
assign MCAUSE_SC = reg_mcause;

endmodule
