--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   07:27:30 10/05/2015
-- Design Name:   
-- Module Name:   D:/DIGITAL-ISE/SENSOR_HCSR04 - copia/testpot.vhd
-- Project Name:  SENSOR_HCSR04
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: DIGPOT
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY testpot IS
END testpot;
 
ARCHITECTURE behavior OF testpot IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT DIGPOT
    PORT(
         cs_in : IN  std_logic;
         wp_in : IN  std_logic_vector(6 downto 0);
         cs_o : OUT  std_logic;
         INC : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal cs_in : std_logic := '0';
   signal wp_in : std_logic_vector(6 downto 0) := (others => '0');

 	--Outputs
   signal cs_o : std_logic;
   signal INC : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
   constant <clock>_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: DIGPOT PORT MAP (
          cs_in => cs_in,
          wp_in => wp_in,
          cs_o => cs_o,
          INC => INC
        );

   -- Clock process definitions
   <clock>_process :process
   begin
		<clock> <= '0';
		wait for <clock>_period/2;
		<clock> <= '1';
		wait for <clock>_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for <clock>_period*10;

      -- insert stimulus here 

      wait;
   end process;

END;
