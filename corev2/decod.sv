import riscv::*;

module dec (
  input logic                                     clk,
  input logic                                     resetn,
  input logic [FRONTEND_WIDTH-1:0][XLEN-1:0]      instr_i,
  input logic [FRONTEND_WIDTH-1:0][XLEN-1:0]      pc_i,
  // Exception
  output logic [FRONTEND_WIDTH-1:0]               ren_illegal_inst_o,
  // Registers
  output logic [FRONTEND_WIDTH-1:0]               ren_rd_v_o, 
  output logic [FRONTEND_WIDTH-1:0][4:0]          ren_rd_o, 
  output logic [FRONTEND_WIDTH-1:0]               ren_rs1_v_o,
  output logic [FRONTEND_WIDTH-1:0][4:0]          ren_rs1_o,
  output logic [FRONTEND_WIDTH-1:0]               ren_rs2_v_o, 
  output logic [FRONTEND_WIDTH-1:0][4:0]          ren_rs2_o,   
  // Additionnal informations
  output logic [FRONTEND_WIDTH-1:0]               ren_rs2_is_immediat_o, 
  output logic [FRONTEND_WIDTH-1:0]               ren_is_store_o,        
  output logic [FRONTEND_WIDTH-1:0]               ren_is_load_o,          
  output logic [FRONTEND_WIDTH-1:0]               ren_is_branch_o,         
  output logic [FRONTEND_WIDTH-1:0][31:0]         ren_immediat_o,
  output logic [FRONTEND_WIDTH-1:0][2:0]          ren_access_size_o,
  output logic [FRONTEND_WIDTH-1:0][12:0]         ren_instr_type_o,
  output logic [FRONTEND_WIDTH-1:0]               ren_unsign_extension_o
);

  logic [FRONTEND_WIDTH-1:0]                      illegal_inst;
  // Registers
  logic [FRONTEND_WIDTH-1:0]                      rd_v; 
  logic [FRONTEND_WIDTH-1:0][4:0]                 rd; 
  logic [FRONTEND_WIDTH-1:0]                      rs1_v;
  logic [FRONTEND_WIDTH-1:0][4:0]                 rs1;
  logic [FRONTEND_WIDTH-1:0]                      rs2_v; 
  logic [FRONTEND_WIDTH-1:0][4:0]                 rs2;   
  // Additionnal informations
  logic [FRONTEND_WIDTH-1:0]                      rs2_is_immediat; 
  logic [FRONTEND_WIDTH-1:0]                      is_store;        
  logic [FRONTEND_WIDTH-1:0]                      is_load;          
  logic [FRONTEND_WIDTH-1:0]                      is_branch;         
  logic [FRONTEND_WIDTH-1:0][31:0]                immediat;
  logic [FRONTEND_WIDTH-1:0][2:0]                 access_size;
  logic [FRONTEND_WIDTH-1:0][12:0]                instr_type;
  logic [FRONTEND_WIDTH-1:0]                      unsign_extension;     

  // Instanciated the decoders
  generate
    for(genvar i = 0; i < FRONTEND_WIDTH; i++)
        decoder dec(
            .instr_i            (instr_i[i]),
            .pc_i               (pc_i[i]),          
            .illegal_inst_o     (illegal_inst[i]),
            .rd_v_o             (rd_v[i]), 
            .rd_o               (rd[i]), 
            .rs1_v_o            (rs1_v[i]),
            .rs1_o              (rs1[i]),
            .rs2_v_o            (rs2_v[i]), 
            .rs2_o              (rs2[i]),   
            .rs2_is_immediat_o  (rs2_is_immediat[i]), 
            .is_store_o         (is_store[i]),        
            .is_load_o          (is_load[i]),          
            .is_branch_o        (is_branch[i]),         
            .immediat_o         (immediat[i]),
            .access_size_o      (access_size[i]),
            .instr_type_o       (instr_type[i]),
            .unsign_extension_o (unsign_extension[i]) 
        );
  endgenerate
  // Flopping outputs
  generate
    for(genvar i = 0; i < FRONTEND_WIDTH; i++)
      always_ff @(posedge clk, negedge resetn)
          if (!resetn) begin
              illegal_inst_o[i]     <= '0;
              rd_v_o[i]             <= '0;
              rd_o[i]               <= '0;
              rs1_v_o[i]            <= '0;
              rs1_o[i]              <= '0;
              rs2_v_o[i]            <= '0;
              rs2_o[i]              <= '0;
              rs2_is_immediat_o[i]  <= '0;
              is_store_o[i]         <= '0;
              is_load_o[i]          <= '0;
              is_branch_o[i]        <= '0;
              immediat_o[i]         <= '0;
              access_size_o[i]      <= '0;
              instr_type_o[i]       <= '0;
              unsign_extension_o[i] <= '0;
          end else begin
              illegal_inst_o[i]     <= illegal_inst[i];
              rd_v_o[i]             <= rd_v[i];
              rd_o[i]               <= rd[i];
              rs1_v_o[i]            <= rs1_v[i];
              rs1_o[i]              <= rs1[i];
              rs2_v_o[i]            <= rs2_v[i];
              rs2_o[i]              <= rs2[i];
              rs2_is_immediat_o[i]  <= rs2_is_immediat[i];
              is_store_o[i]         <= is_store[i];
              is_load_o[i]          <= is_load[i];
              is_branch_o[i]        <= is_branch[i];
              immediat_o[i]         <= immediat[i];
              access_size_o[i]      <= access_size[i];
              instr_type_o[i]       <= instr_type[i];
              unsign_extension_o[i] <= unsign_extension[i];
          end
      endgenerate
endmodule