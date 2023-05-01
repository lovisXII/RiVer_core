import riscv::*;

module rename (
  input logic                           clk, 
  input logic                           reset_n,

  input logic [FRONTEND_WIDTH-1:0]      dec_rd_v_i,
  input logic [FRONTEND_WIDTH-1:0]      dec_rd_i    [4:0],
  input logic [FRONTEND_WIDTH-1:0]      dec_rs1_v_i,
  input logic [FRONTEND_WIDTH-1:0]      dec_rs1_i   [4:0],
  input logic [FRONTEND_WIDTH-1:0]      dec_rs2_v_i,
  input logic [FRONTEND_WIDTH-1:0]      dec_rs2_i   [4:0],
  input logic [FRONTEND_WIDTH-1:0]      dec_rs2_is_immediat_i,

  input logic [FRONTEND_WIDTH-1:0]      dec_is_store_i,        
  input logic [FRONTEND_WIDTH-1:0]      dec_is_load_i,          
  input logic [FRONTEND_WIDTH-1:0]      dec_is_branch_i,         
  input logic [FRONTEND_WIDTH-1:0]      dec_immediat_i    [31:0],
  input logic [FRONTEND_WIDTH-1:0]      dec_access_size_i [2:0],
  input logic [FRONTEND_WIDTH-1:0]      dec_instr_type_i  [12:0],
  input logic [FRONTEND_WIDTH-1:0]      dec_unsign_extension_i, 

  input logic [PHYS_REGS_ADDR_SIZE-1:0] freelist_preg_i [FRONTEND_WIDTH-1:0],

  output logic [FRONTEND_WIDTH-1:0]     dispatch_prd_o  [PHYS_REGS_ADDR_SIZE-1:0],
  output logic [FRONTEND_WIDTH-1:0]     dispatch_prs1_o [PHYS_REGS_ADDR_SIZE-1:0],
  output logic [FRONTEND_WIDTH-1:0]     dispatch_prs2_o [PHYS_REGS_ADDR_SIZE-1:0],

  output logic [FRONTEND_WIDTH-1:0]     regtable_rd_o   [4:0],
  output logic [FRONTEND_WIDTH-1:0]     regtable_prd_o  [PHYS_REGS_ADDR_SIZE-1:0],

  output logic [FRONTEND_WIDTH-1:0]     regtable_rs1_o  [4:0],
  output logic [FRONTEND_WIDTH-1:0]     regtable_prs1_o [PHYS_REGS_ADDR_SIZE-1:0],

  output logic [FRONTEND_WIDTH-1:0]     regtable_rs2_o  [4:0],
  output logic [FRONTEND_WIDTH-1:0]     regtable_prs2_o [PHYS_REGS_ADDR_SIZE-1:0]
);


logic [FRONTEND_WIDTH-1:0] prd  [PHYS_REGS_ADDR_SIZE-1:0];
logic [FRONTEND_WIDTH-1:0] prs1 [PHYS_REGS_ADDR_SIZE-1:0];
logic [FRONTEND_WIDTH-1:0] prs2 [PHYS_REGS_ADDR_SIZE-1:0];


logic [FRONTEND_WIDTH-1:0] prd_q  [PHYS_REGS_ADDR_SIZE-1:0];
logic [FRONTEND_WIDTH-1:0] prs1_q [PHYS_REGS_ADDR_SIZE-1:0];
logic [FRONTEND_WIDTH-1:0] prs2_q [PHYS_REGS_ADDR_SIZE-1:0];

logic [FRONTEND_WIDTH-1:0] regtable_rd  [4:0];
logic [FRONTEND_WIDTH-1:0] regtable_rs1 [4:0];
logic [FRONTEND_WIDTH-1:0] regtable_rs2 [4:0];


logic [FRONTEND_WIDTH-1:0] regtable_rd_q  [4:0];
logic [FRONTEND_WIDTH-1:0] regtable_rs1_q [4:0];
logic [FRONTEND_WIDTH-1:0] regtable_rs2_q [4:0];

genvar i;
generate
  for(i = 0; i < FRONTEND_WIDTH; i++) begin 
    assign prd [i] = freelist_preg_i[i] & {PHYS_REGS_ADDR_SIZE{dec_rd_v_i [i]}};
    assign prs1[i] = freelist_preg_i[i] & {PHYS_REGS_ADDR_SIZE{dec_rs1_v_i[i]}};
    assign prs2[i] = freelist_preg_i[i] & {PHYS_REGS_ADDR_SIZE{dec_rs2_v_i[i]}};  

    assign regtable_rd [i] = dec_rd_i [i] & {4{dec_rd_v_i [i]}};
    assign regtable_rs1[i] = dec_rs1_i[i] & {4{dec_rs1_v_i[i]}};
    assign regtable_rs2[i] = dec_rs2_i[i] & {4{dec_rs2_v_i[i]}};
  end 
endgenerate

always_ff @(posedge clk, negedge resetn) begin
  if (!resetn) begin

  prd_q   <= '0;
  prs1_q  <= '0;
  prs2_q  <= '0;

  regtable_rd_q  <= '0;
  regtable_rs1_q <= '0;
  regtable_rs2_q <= '0;
  end else begin
  prd_q   <= prd;
  prs1_q  <= prs1;
  prs2_q  <= prs2;

  regtable_rd_q  <= regtable_rd;
  regtable_rs1_q <= regtable_rs1;
  regtable_rs2_q <= regtable_rs2;
  end
end



assign regtable_rd_o  = regtable_rd;
assign regtable_rs1_o = regtable_rs1;
assign regtable_rs2_o = regtable_rs2;

assign regtable_prd_o  = prd_q;
assign regtable_prs1_o = prs1_q;
assign regtable_prs2_o = prs2_q;

assign dispatch_prd_o = prd_q;
assign dispatch_prs1_o = prs1_q;
assign dispatch_prs2_o = prs2_q;

endmodule