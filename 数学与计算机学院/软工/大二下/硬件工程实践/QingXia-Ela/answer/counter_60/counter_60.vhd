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
-- CREATED		"Sun Jun 16 11:09:11 2024"

LIBRARY ieee;
USE ieee.std_logic_1164.all; 

LIBRARY work;

ENTITY counter_60 IS 
	PORT
	(
		up_down_switch :  IN  STD_LOGIC;
		clk :  IN  STD_LOGIC;
		enable :  IN  STD_LOGIC;
		count_60 :  OUT  STD_LOGIC;
		high_output :  OUT  STD_LOGIC_VECTOR(3 DOWNTO 0);
		low_output :  OUT  STD_LOGIC_VECTOR(3 DOWNTO 0)
	);
END counter_60;

ARCHITECTURE bdf_type OF counter_60 IS 

ATTRIBUTE black_box : BOOLEAN;
ATTRIBUTE noopt : BOOLEAN;

COMPONENT \74191_0\
	PORT(LDN : IN STD_LOGIC;
		 CLK : IN STD_LOGIC;
		 DNUP : IN STD_LOGIC;
		 QA : OUT STD_LOGIC;
		 QB : OUT STD_LOGIC;
		 QD : OUT STD_LOGIC;
		 QC : OUT STD_LOGIC);
END COMPONENT;
ATTRIBUTE black_box OF \74191_0\: COMPONENT IS true;
ATTRIBUTE noopt OF \74191_0\: COMPONENT IS true;

COMPONENT \74191_1\
	PORT(LDN : IN STD_LOGIC;
		 CLK : IN STD_LOGIC;
		 DNUP : IN STD_LOGIC;
		 QA : OUT STD_LOGIC;
		 QB : OUT STD_LOGIC;
		 QD : OUT STD_LOGIC;
		 QC : OUT STD_LOGIC);
END COMPONENT;
ATTRIBUTE black_box OF \74191_1\: COMPONENT IS true;
ATTRIBUTE noopt OF \74191_1\: COMPONENT IS true;

SIGNAL	high_output_ALTERA_SYNTHESIZED :  STD_LOGIC_VECTOR(3 DOWNTO 0);
SIGNAL	low_output_ALTERA_SYNTHESIZED :  STD_LOGIC_VECTOR(3 DOWNTO 0);
SIGNAL	reset :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_0 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_1 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_10 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_3 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_4 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_5 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_7 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_8 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_9 :  STD_LOGIC;


BEGIN 



b2v_inst : 74191_0
PORT MAP(LDN => SYNTHESIZED_WIRE_0,
		 CLK => SYNTHESIZED_WIRE_1,
		 DNUP => up_down_switch,
		 QA => low_output_ALTERA_SYNTHESIZED(0),
		 QB => low_output_ALTERA_SYNTHESIZED(1),
		 QD => low_output_ALTERA_SYNTHESIZED(3),
		 QC => low_output_ALTERA_SYNTHESIZED(2));


SYNTHESIZED_WIRE_0 <= NOT(reset OR SYNTHESIZED_WIRE_10);


count_60 <= high_output_ALTERA_SYNTHESIZED(2) AND SYNTHESIZED_WIRE_3 AND high_output_ALTERA_SYNTHESIZED(0);


SYNTHESIZED_WIRE_9 <= NOT(high_output_ALTERA_SYNTHESIZED(0));



SYNTHESIZED_WIRE_3 <= NOT(high_output_ALTERA_SYNTHESIZED(1));



SYNTHESIZED_WIRE_1 <= clk AND enable;


SYNTHESIZED_WIRE_4 <= NOT(reset);



b2v_inst4 : 74191_1
PORT MAP(LDN => SYNTHESIZED_WIRE_4,
		 CLK => SYNTHESIZED_WIRE_5,
		 DNUP => up_down_switch,
		 QA => high_output_ALTERA_SYNTHESIZED(0),
		 QB => high_output_ALTERA_SYNTHESIZED(1),
		 QD => high_output_ALTERA_SYNTHESIZED(3),
		 QC => high_output_ALTERA_SYNTHESIZED(2));


SYNTHESIZED_WIRE_5 <= NOT(SYNTHESIZED_WIRE_10);



SYNTHESIZED_WIRE_8 <= NOT(low_output_ALTERA_SYNTHESIZED(0));



SYNTHESIZED_WIRE_10 <= low_output_ALTERA_SYNTHESIZED(3) AND SYNTHESIZED_WIRE_7 AND low_output_ALTERA_SYNTHESIZED(1) AND SYNTHESIZED_WIRE_8;


SYNTHESIZED_WIRE_7 <= NOT(low_output_ALTERA_SYNTHESIZED(2));



reset <= high_output_ALTERA_SYNTHESIZED(2) AND high_output_ALTERA_SYNTHESIZED(1) AND SYNTHESIZED_WIRE_9;

high_output <= high_output_ALTERA_SYNTHESIZED;
low_output <= low_output_ALTERA_SYNTHESIZED;

END bdf_type;