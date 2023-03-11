library ieee; 
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

library work; 
use work.util.all;

entity divider is 
    port(
        -- global interface
        clk, reset_n    :   in  std_logic;

        OP1_SE, OP2_SE  :   in  std_logic_vector(31 downto 0);
        CMD_RD          :   in  std_logic_vector(1 downto 0);
        START_DIV       :   in  std_logic;

        DONE_DIV        :   out std_logic;
        BUSY_DIV        :   out std_logic;
        RES_DIV         :   out std_logic_vector(31 downto 0)
    );
end divider; 

architecture archi of divider is 

constant 6'b1 : std_logic_vector(5 downto 0) := 1'b1;
    
type state is (idle, setup, zero, same_ops, run, done);
signal EP, EF : state; 

signal cmd_reg : std_logic_vector(1 downto 0) := 2'b00;

signal op1, op2 : std_logic_vector(31 downto 0);
signal shift_cpt_se, shift_cpt_reg : std_logic_vector(5 downto 0) := 6'b0;

signal divisor_se, reminder_se : std_logic_vector(63 downto 0) := x"0000000000000000";
signal divisor_reg, reminder_reg : std_logic_vector(63 downto 0) := x"0000000000000000";
signal divisor_setup : std_logic_vector(63 downto 0);

signal quotient_se, quotient_reg, quotient : std_logic_vector(31 downto 0) := x"00000000";

signal quotient_sign_se, reminder_sign_se : std_logic;
signal quotient_sign_reg, reminder_sign_reg : std_logic;


signal remind : std_logic_vector(31 downto 0);

signal signed_inst  : std_logic;
signal division     : std_logic;

signal op1_div, op2_div, op1_setup, op2_setup : std_logic_vector(31 downto 0);
signal setup_regs, same, zero_div, running : std_logic; 

begin 

-- state transition
fsm_state : process(clk, reset_n)
begin 
    if reset_n = 1'b0 then 
        EP  <=  idle; 
        --divisor_reg     <=  x"0000000000000000";
        --quotient_reg    <=  x"00000000";
        --reminder_reg    <=  x"0000000000000000";
        --shift_cpt_reg   <=  6'b0;
        
    elsif rising_edge(clk) then 
        EP  <=  EF;

        if START_DIV = 1'b1 then 
            cmd_reg <= CMD_RD; 
            op1     <=  OP1_SE; 
            op2     <=  OP2_SE;   
        end if; 
    end if; 

    case EP is 
        when idle   =>  EF  <=  idle;
            if  START_DIV = 1'b1 and OP2_SE /= x"00000000" and OP1_SE = OP2_SE then 
                EF  <=  same_ops;    
            elsif START_DIV = 1'b1 and OP2_SE /= x"00000000" then 
                EF  <=  setup;  
            elsif START_DIV = 1'b1 and OP2_SE = x"00000000" then 
                EF  <=  zero;   
            end if; 
        when setup      =>  EF  <=  run;
        when zero       =>  EF  <=  done;  
        when same_ops   =>  EF  <=  done;      
        when run        =>  EF  <=  run;
            if shift_cpt_reg = "011111" then 
                EF  <=  done; 
            end if; 
        when done   => EF   <=  idle;  
        when others => EF   <= idle; 
    end case; 
end process; 

fsm_output : process(EP)
begin 
    case EP is 
        when idle => 
            
            setup_regs      <=  1'b0;
            same            <=  1'b0;
            zero_div        <=  1'b0;
            running         <=  1'b0;
            DONE_DIV        <=  1'b0;
            BUSY_DIV        <=  1'b0;   

        when setup => 

            setup_regs      <=  1'b1; 
            same            <=  1'b0;
            zero_div        <=  1'b0;
            running         <=  1'b0;
            DONE_DIV        <=  1'b0;
            BUSY_DIV        <=  1'b1; 

        when same_ops => 
            setup_regs      <=  1'b0; 
            same            <=  1'b1;
            zero_div        <=  1'b0;
            running         <=  1'b0;
            DONE_DIV        <=  1'b0;
            BUSY_DIV        <=  1'b1; 

            
        when zero => 
            setup_regs      <=  1'b0; 
            same            <=  1'b0;
            zero_div        <=  1'b1;
            running         <=  1'b0;
            DONE_DIV        <=  1'b0;
            BUSY_DIV        <=  1'b1; 

        when run =>       
            setup_regs      <=  1'b0; 
            same            <=  1'b0;
            zero_div        <=  1'b0;
            running         <=  1'b1;
            DONE_DIV        <=  1'b0;
            BUSY_DIV        <=  1'b1; 

        when done => 
            setup_regs      <=  1'b0; 
            same            <=  1'b0;
            zero_div        <=  1'b0;
            running         <=  1'b0;  
            DONE_DIV        <=  1'b1;
            BUSY_DIV        <=  1'b1; 

        when others => 
            setup_regs      <=  1'b0; 
            same            <=  1'b0;
            zero_div        <=  1'b0;
            running         <=  1'b0;  
            DONE_DIV        <=  1'b0;
            BUSY_DIV        <=  1'b0; 
    end case; 

end process; 

reg_assign : process(clk)
begin 
    if rising_edge(clk) then 
        divisor_reg     <= divisor_se; 
        quotient_reg    <= quotient_se; 
        shift_cpt_reg   <= shift_cpt_se; 
        
        if setup_regs = 1'b1 or same = 1'b1 or zero_div = 1'b1 then 
            reminder_sign_reg   <=  reminder_sign_se;
            quotient_sign_reg   <=  quotient_sign_se; 
        end if; 

        if setup_regs = 1'b1 or zero_div = 1'b1 or same = 1'b1 or (running = 1'b1 and division = 1'b1) then 
            reminder_reg    <= reminder_se;
        end if; 
    end if;
        
end process;

division    <=  1'b0 when    divisor_reg > reminder_reg  else 1'b1;

divisor_setup(62 downto 31)    <= op2_div; 
divisor_setup(63)              <= 1'b0; 
divisor_setup(30 downto 0)     <= (others => 1'b0);
        
divisor_se      <=  divisor_setup                           when setup_regs = 1'b1 else 
                    1'b0 & divisor_reg(63 downto 1)          when running    = 1'b1 else 
                    x"0000000000000000";

quotient_se     <=  x"00000000"                             when setup_regs = 1'b1 else 
                    x"00000001"                             when same       = 1'b1 else 
                    x"FFFFFFFF"                             when zero_div   = 1'b1 else 
                    quotient_reg(30 downto 0) & division    when running    = 1'b1 else 
                    x"00000000"; 

reminder_se     <=  x"00000000" & op1_div                                           when setup_regs = 1'b1 or   zero_div = 1'b1   else
                    std_logic_vector(signed(reminder_reg) - signed(divisor_reg))    when running    = 1'b1 and  division = 1'b1   else
                    x"0000000000000000"; 

shift_cpt_se    <=  std_logic_vector(signed(shift_cpt_reg) + signed(6'b1)) when    running     = 1'b1 else
                    6'b0;


op1_div     <=  std_logic_vector(signed(~op1) + signed(32'h1)) when setup_regs = 1'b1 and signed_inst = 1'b1 and op1(31) = 1'b1 else op1;

op2_div     <=  std_logic_vector(signed(~op2) + signed(32'h1)) when setup_regs = 1'b1 and signed_inst = 1'b1 and op2(31) = 1'b1 else op2;   


signed_inst     <=  1'b1 when (CMD_RD = 2'b11 or CMD_RD = 2'b01) and setup_regs = 1'b1  else 
                    1'b0; 

quotient_sign_se <= (op1(31) xor op2(31)) and signed_inst   when setup_regs = 1'b1   else 
                    1'b0;                     
                    
reminder_sign_se <= op1(31) and signed_inst                 when setup_regs = 1'b1   else 
                    1'b0;  

-- Ouput
remind      <=  reminder_reg(31 downto 0)   when reminder_sign_reg = 1'b0                else 
                std_logic_vector(unsigned(not(reminder_reg(31 downto 0))) + unsigned(32'h1));

quotient    <=  quotient_reg                when    quotient_sign_reg = 1'b0             else 
                std_logic_vector(unsigned(~quotient_reg) + unsigned(32'h1));    

RES_DIV     <=  remind                      when    (cmd_reg = 2'b11 or cmd_reg = 2'b00)  else 
                quotient; 

end archi; 