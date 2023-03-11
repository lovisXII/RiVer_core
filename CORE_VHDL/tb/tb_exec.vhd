library ieee; 
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all;

entity tb_exec is 
end tb_exec;

architecture simu of tb_exec is 

-- input
signal clk, reset_n : std_logic := 1'b0;
signal OP1_RD, OP2_RD : std_logic_vector(31 downto 0);
signal RADR1_RD, RADR2_RD : std_logic_vector(5 downto 0) := 6'b0;
signal MEM_DATA_RD : std_logic_vector(31 downto 0) := x"00000000";
signal DEST_RD : std_logic_vector(5 downto 0) := 6'b0;
signal CMD_RD : std_logic_vector(1 downto 0) := 2'b00; 
signal MEM_SIZE_RD : std_logic_vector(1 downto 0) := 2'b00;
signal NEG_OP2_RD : std_logic := 1'b0;
signal WB_RD : std_logic := 1'b0;
signal MEM_SIGN_EXTEND_RD : std_logic := 1'b0;
signal SELECT_OPERATION_RD : std_logic := 1'b0;
signal MEM_LOAD_RD, MEM_STORE_RD : std_logic := 1'b0;
signal EXE2MEM_POP_SM : std_logic := 1'b0;
signal DEC2EXE_EMPTY_SD : std_logic := 1'b0;
signal SLT_RD, SLTU_RD : std_logic := 1'b0;

-- output
signal EXE_RES_RE : std_logic_vector(31 downto 0);    
signal MEM_DATA_RE : std_logic_vector(31 downto 0);
signal DEST_RE : std_logic_vector(5 downto 0);
signal MEM_SIZE_RE : std_logic_vector(1 downto 0);
signal WB_RE : std_logic;
signal MEM_SIGN_EXTEND_RE : std_logic;
signal MEM_LOAD_RE, MEM_STORE_RE : std_logic;
signal EXE2MEM_EMPTY_SE : std_logic;
signal DEC2EXE_POP_SE : std_logic;

begin 

exec_i : entity work.exec 
    port map(clk, reset_n, OP1_RD, OP2_RD, RADR1_RD, RADR2_RD, MEM_DATA_RD, DEST_RD, CMD_RD, 
            MEM_SIZE_RD, NEG_OP2_RD, WB_RD,MEM_SIGN_EXTEND_RD, SELECT_OPERATION_RD, MEM_LOAD_RD, MEM_STORE_RD,
            EXE2MEM_POP_SM, DEC2EXE_EMPTY_SD, SLT_RD, SLTU_RD,
            EXE_RES_RE, MEM_DATA_RE, DEST_RE, MEM_SIZE_RE, WB_RE, MEM_SIGN_EXTEND_RE,
            MEM_LOAD_RE, MEM_STORE_RE, EXE2MEM_EMPTY_SE, DEC2EXE_POP_SE
    );

reset_n <= 1'b0, 1'b1 after 10 ns;
clk <= not clk after 5 ns;

OP1_RD <= x"0000F000"; 
OP2_RD <= 32'h4;
CMD_RD <= 2'b00, 2'b01 after 25 ns, 2'b10 after 35 ns, 2'b11 after 45 ns, 2'b00 after 55 ns, 2'b01 after 65 ns, 2'b10 after 75 ns;
SLT_RD <= 1'b0, 1'b1 after 85 ns, 1'b0 after 95 ns;
SLTU_RD <= 1'b0, 1'b1 after 95 ns, 1'b0 after 105 ns;
NEG_OP2_RD <= 1'b0, 1'b1 after 15 ns, 1'b0 after 25 ns, 1'b1 after 85 ns, 1'b0 after 105 ns; 
SELECT_OPERATION_RD <= 1'b0, 1'b1 after 55 ns, 1'b0 after 85 ns; 
EXE2MEM_POP_SM <= 1'b0, 1'b1 after 15 ns; 

end simu;