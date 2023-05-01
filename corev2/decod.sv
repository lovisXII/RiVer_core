import riscv::*;

module dec (
  input logic [XLEN-1:0]             instr_i,
  input logic [XLEN-1:0]             pc_i,
  // Exception
  output logic                       illegal_inst_o,
  // Registers
  output logic                       rd_v_o, 
  output logic [4:0]                 rd_o, 
  output logic                       rs1_v_o,
  output logic [4:0]                 rs1_o,
  output logic                       rs2_v_o, 
  output logic [4:0]                 rs2_o,   
  // Additionnal informations
  output logic                       rs2_is_immediat_o, 
  output logic                       is_store_o,        
  output logic                       is_load_o,          
  output logic                       is_branch_o,         
  output logic [31:0]                immediat_o,
  output logic [2:0]                 access_size_o,
  output logic [12:0]                instr_type_o,
  output logic                       unsign_extension_o         
);

  logic                       illegal_inst;
  // Registers
  logic                       rd_v; 
  logic [4:0]                 rd; 
  logic                       rs1_v;
  logic [4:0]                 rs1;
  logic                       rs2_v; 
  logic [4:0]                 rs2;   
  // Additionnal informations
  logic                       rs2_is_immediat; 
  logic                       is_store;        
  logic                       is_load;          
  logic                       is_branch;         
  logic [31:0]                immediat;
  logic [2:0]                 access_size;
  logic [12:0]                instr_type;
  logic                       unsign_extension;     

  genvar nbr_decoders;
  generate
    for(nbr_decoders = 0; nbr_decoders < FRONTEND_WIDTH; nbr_decoders++)
        decoder dec0(
            .instr_i,
            .pc_i,
            .illegal_inst_o     (illegal_inst),
            .rd_v_o             (rd_v), 
            .rd_o               (rd), 
            .rs1_v_o            (rs1_v),
            .rs1_o              (rs1),
            .rs2_v_o            (rs2_v), 
            .rs2_o              (rs2),   
            .rs2_is_immediat_o  (rs2_is_immediat), 
            .is_store_o         (is_store),        
            .is_load_o          (is_load),          
            .is_branch_o        (is_branch),         
            .immediat_o         (immediat),
            .access_size_o      (access_size),
            .instr_type_o       (instr_type),
            .unsign_extension_o (unsign_extension) 
        );
  endgenerate
endmodule