--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   11:56:37 09/18/2015
-- Design Name:   
-- Module Name:   D:/DIGITAL-ISE/SENSOR_HCSR04/decbin.vhd
-- Project Name:  SENSOR_HCSR04
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: DECtoBIN
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
 
ENTITY decbin IS
END decbin;
 
ARCHITECTURE behavior OF decbin IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT DECtoBIN
    PORT(
         x : IN  std_logic_vector(13 downto 0);
         uni : OUT  std_logic_vector(3 downto 0);
         dec : OUT  std_logic_vector(3 downto 0);
         cen : OUT  std_logic_vector(3 downto 0);
         mil : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal x : std_logic_vector(13 downto 0) := (others => '0');

 	--Outputs
   signal uni : std_logic_vector(3 downto 0);
   signal dec : std_logic_vector(3 downto 0);
   signal cen : std_logic_vector(3 downto 0);
   signal mil : std_logic_vector(3 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
   constant <clock>_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: DECtoBIN PORT MAP (
          x => x,
          uni => uni,
          dec => dec,
          cen => cen,
          mil => mil
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
