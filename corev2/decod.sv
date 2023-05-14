import riscv::*;

module dec (
  input logic                 clk,
  input logic                 resetn,
// -----------------------
//      LINE 0
// -----------------------
  input logic [XLEN-1:0]      line0_instr_i,
  input logic [XLEN-1:0]      line0_pc_i,
  // Exception
  output logic                line0_ren_illegal_inst_o,
  // Registers
  output logic                ren_line0_rd_v_o, 
  output logic [4:0]          ren_line0_rd_o, 
  output logic                ren_line0_rs1_v_o,
  output logic [4:0]          ren_line0_rs1_o,
  output logic                ren_line0_rs2_v_o, 
  output logic [4:0]          ren_line0_rs2_o,   
  // Additionnal informations
  output logic                ren_line0_rs2_is_immediat_o, 
  output logic                ren_line0_is_store_o,        
  output logic                ren_line0_is_load_o,          
  output logic                ren_line0_is_branch_o,         
  output logic [31:0]         ren_line0_immediat_o,
  output logic [2:0]          ren_line0_access_size_o,
  output logic [12:0]         ren_line0_instr_type_o,
  output logic                ren_line0_unsign_extension_o,
// -----------------------
//      LINE 1
// -----------------------
  input logic [XLEN-1:0]      line1_instr_i,
  input logic [XLEN-1:0]      line1_pc_i,
  // Exception
  output logic                ren_line1_illegal_inst_o,
  // Registers
  output logic                ren_line1_rd_v_o, 
  output logic [4:0]          ren_line1_rd_o, 
  output logic                ren_line1_rs1_v_o,
  output logic [4:0]          ren_line1_rs1_o,
  output logic                ren_line1_rs2_v_o, 
  output logic [4:0]          ren_line1_rs2_o,   
  // Additionnal informations
  output logic                ren_line1_rs2_is_immediat_o, 
  output logic                ren_line1_is_store_o,        
  output logic                ren_line1_is_load_o,          
  output logic                ren_line1_is_branch_o,         
  output logic [31:0]         ren_line1_immediat_o,
  output logic [2:0]          ren_line1_access_size_o,
  output logic [12:0]         ren_line1_instr_type_o,
  output logic                ren_line1_unsign_extension_o

);
// -----------------------
//      LINE 0
// -----------------------
  logic                       line0_illegal_inst;
  // Registers
  logic                       line0_rd_v; 
  logic [4:0]                 line0_rd; 
  logic                       line0_rs1_v;
  logic [4:0]                 line0_rs1;
  logic                       line0_rs2_v; 
  logic [4:0]                 line0_rs2;   
  // Additionnal informations
  logic                       line0_rs2_is_immediat; 
  logic                       line0_is_store;        
  logic                       line0_is_load;          
  logic                       line0_is_branch;         
  logic [31:0]                line0_immediat;
  logic [2:0]                 line0_access_size;
  logic [12:0]                line0_instr_type;
  logic                       line0_unsign_extension;     
// -----------------------
//      LINE 1
// -----------------------
  logic                       line1_illegal_inst;
  // Registers
  logic                       line1_rd_v; 
  logic [4:0]                 line1_rd; 
  logic                       line1_rs1_v;
  logic [4:0]                 line1_rs1;
  logic                       line1_rs2_v; 
  logic [4:0]                 line1_rs2;   
  // Additionnal informations
  logic                       line1_rs2_is_immediat; 
  logic                       line1_is_store;        
  logic                       line1_is_load;          
  logic                       line1_is_branch;         
  logic [31:0]                line1_immediat;
  logic [2:0]                 line1_access_size;
  logic [12:0]                line1_instr_type;
  logic                       line1_unsign_extension; 

  // Instanciated the decoders
  decoder dec0(
      .instr_i            (line0_instr_i[i]),
      .pc_i               (line0_pc_i[i]),          
      .illegal_inst_o     (line0_illegal_inst[i]),
      .rd_v_o             (line0_rd_v[i]), 
      .rd_o               (line0_rd[i]), 
      .rs1_v_o            (line0_rs1_v[i]),
      .rs1_o              (line0_rs1[i]),
      .rs2_v_o            (line0_rs2_v[i]), 
      .rs2_o              (line0_rs2[i]),   
      .rs2_is_immediat_o  (line0_rs2_is_immediat[i]), 
      .is_store_o         (line0_is_store[i]),        
      .is_load_o          (line0_is_load[i]),          
      .is_branch_o        (line0_is_branch[i]),         
      .immediat_o         (line0_immediat[i]),
      .access_size_o      (line0_access_size[i]),
      .instr_type_o       (line0_instr_type[i]),
      .unsign_extension_o (line0_unsign_extension[i]) 
  );
decoder dec1(
      .instr_i            (line1_instr_i[i]),
      .pc_i               (line1_pc_i[i]),          
      .illegal_inst_o     (line1_illegal_inst[i]),
      .rd_v_o             (line1_rd_v[i]), 
      .rd_o               (line1_rd[i]), 
      .rs1_v_o            (line1_rs1_v[i]),
      .rs1_o              (line1_rs1[i]),
      .rs2_v_o            (line1_rs2_v[i]), 
      .rs2_o              (line1_rs2[i]),   
      .rs2_is_immediat_o  (line1_rs2_is_immediat[i]), 
      .is_store_o         (line1_is_store[i]),        
      .is_load_o          (line1_is_load[i]),          
      .is_branch_o        (line1_is_branch[i]),         
      .immediat_o         (line1_immediat[i]),
      .access_size_o      (line1_access_size[i]),
      .instr_type_o       (line1_instr_type[i]),
      .unsign_extension_o (line1_unsign_extension[i]) 
  );
  // Flopping outputs
  generate
    for(genvar i = 0; i < FRONTEND_WIDTH; i++)
      always_ff @(posedge clk, negedge resetn)
          if (!resetn) begin
            // -----------------------
            //      LINE 0
            // -----------------------
              line0_illegal_inst_o     <= '0;
              line0_rd_v_o             <= '0;
              line0_rd_o               <= '0;
              line0_rs1_v_o            <= '0;
              line0_rs1_o              <= '0;
              line0_rs2_v_o            <= '0;
              line0_rs2_o              <= '0;
              line0_rs2_is_immediat_o  <= '0;
              line0_is_store_o         <= '0;
              line0_is_load_o          <= '0;
              line0_is_branch_o        <= '0;
              line0_immediat_o         <= '0;
              line0_access_size_o      <= '0;
              line0_instr_type_o       <= '0;
              line0_unsign_extension_o <= '0;
            // -----------------------
            //      LINE 1
            // -----------------------
              line1_illegal_inst_o     <= '0;
              line1_rd_v_o             <= '0;
              line1_rd_o               <= '0;
              line1_rs1_v_o            <= '0;
              line1_rs1_o              <= '0;
              line1_rs2_v_o            <= '0;
              line1_rs2_o              <= '0;
              line1_rs2_is_immediat_o  <= '0;
              line1_is_store_o         <= '0;
              line1_is_load_o          <= '0;
              line1_is_branch_o        <= '0;
              line1_immediat_o         <= '0;
              line1_access_size_o      <= '0;
              line1_instr_type_o       <= '0;
              line1_unsign_extension_o <= '0;
          end else begin
            // -----------------------
            //      LINE 0
            // -----------------------
              line0_illegal_inst_o     <= illegal_inst;
              line0_rd_v_o             <= rd_v;
              line0_rd_o               <= rd;
              line0_rs1_v_o            <= rs1_v;
              line0_rs1_o              <= rs1;
              line0_rs2_v_o            <= rs2_v;
              line0_rs2_o              <= rs2;
              line0_rs2_is_immediat_o  <= rs2_is_immediat;
              line0_is_store_o         <= is_store;
              line0_is_load_o          <= is_load;
              line0_is_branch_o        <= is_branch;
              line0_immediat_o         <= immediat;
              line0_access_size_o      <= access_size;
              line0_instr_type_o       <= instr_type;
              line0_unsign_extension_o <= unsign_extension;
            // -----------------------
            //      LINE 1
            // -----------------------
              line1_illegal_inst_o     <= illegal_inst;
              line1_rd_v_o             <= rd_v;
              line1_rd_o               <= rd;
              line1_rs1_v_o            <= rs1_v;
              line1_rs1_o              <= rs1;
              line1_rs2_v_o            <= rs2_v;
              line1_rs2_o              <= rs2;
              line1_rs2_is_immediat_o  <= rs2_is_immediat;
              line1_is_store_o         <= is_store;
              line1_is_load_o          <= is_load;
              line1_is_branch_o        <= is_branch;
              line1_immediat_o         <= immediat;
              line1_access_size_o      <= access_size;
              line1_instr_type_o       <= instr_type;
              line1_unsign_extension_o <= unsign_extension;
          end
      endgenerate
endmodule