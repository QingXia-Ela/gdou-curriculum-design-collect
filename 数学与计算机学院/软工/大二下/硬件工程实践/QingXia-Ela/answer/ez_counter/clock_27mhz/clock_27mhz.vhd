-- Copyright (C) 1991-2010 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- PROGRAM		"Quartus II"
-- VERSION		"Version 9.1 Build 350 03/24/2010 Service Pack 2 SJ Web Edition"
-- CREATED		"Sun Jun 16 15:31:27 2024"

LIBRARY ieee;
USE ieee.std_logic_1164.all; 

LIBRARY work;

ENTITY clock_27mhz IS 
	PORT
	(
		27Mhz_input :  IN  STD_LOGIC;
		1hz_output :  OUT  STD_LOGIC
	);
END clock_27mhz;

ARCHITECTURE bdf_type OF clock_27mhz IS 

COMPONENT lpm_counter0
	PORT(clock : IN STD_LOGIC;
		 q : OUT STD_LOGIC_VECTOR(24 DOWNTO 0)
	);
END COMPONENT;

COMPONENT lpm_compare0
	PORT(dataa : IN STD_LOGIC_VECTOR(24 DOWNTO 0);
		 aeb : OUT STD_LOGIC
	);
END COMPONENT;

SIGNAL	SYNTHESIZED_WIRE_0 :  STD_LOGIC_VECTOR(24 DOWNTO 0);


BEGIN 



b2v_inst : lpm_counter0
PORT MAP(clock => 27Mhz_input,
		 q => SYNTHESIZED_WIRE_0);


b2v_inst1 : lpm_compare0
PORT MAP(dataa => SYNTHESIZED_WIRE_0,
		 aeb => 1hz_output);


END bdf_type;