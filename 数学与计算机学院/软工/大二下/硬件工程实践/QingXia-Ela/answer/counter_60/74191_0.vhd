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

LIBRARY altera;
USE altera.maxplus2.all; 

LIBRARY work;

ENTITY 74191_0 IS 
PORT 
( 
	LDN	:	IN	 STD_LOGIC;
	CLK	:	IN	 STD_LOGIC;
	DNUP	:	IN	 STD_LOGIC;
	QA	:	OUT	 STD_LOGIC;
	QB	:	OUT	 STD_LOGIC;
	QD	:	OUT	 STD_LOGIC;
	QC	:	OUT	 STD_LOGIC
); 
END 74191_0;

ARCHITECTURE bdf_type OF 74191_0 IS 
BEGIN 

-- instantiate macrofunction 

b2v_inst : 74191
PORT MAP(LDN => LDN,
		 CLK => CLK,
		 DNUP => DNUP,
		 QA => QA,
		 QB => QB,
		 QD => QD,
		 QC => QC);

END bdf_type; 