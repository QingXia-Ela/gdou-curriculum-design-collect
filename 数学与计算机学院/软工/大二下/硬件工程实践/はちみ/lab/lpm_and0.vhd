-- megafunction wizard: %LPM_AND%
-- GENERATION: STANDARD
-- VERSION: WM1.0
-- MODULE: lpm_and 

-- ============================================================
-- File Name: lpm_and0.vhd
-- Megafunction Name(s):
-- 			lpm_and
--
-- Simulation Library Files(s):
-- 			lpm
-- ============================================================
-- ************************************************************
-- THIS IS A WIZARD-GENERATED FILE. DO NOT EDIT THIS FILE!
--
-- 9.1 Build 222 10/21/2009 SJ Web Edition
-- ************************************************************


--Copyright (C) 1991-2009 Altera Corporation
--Your use of Altera Corporation's design tools, logic functions 
--and other software and tools, and its AMPP partner logic 
--functions, and any output files from any of the foregoing 
--(including device programming or simulation files), and any 
--associated documentation or information are expressly subject 
--to the terms and conditions of the Altera Program License 
--Subscription Agreement, Altera MegaCore Function License 
--Agreement, or other applicable license agreement, including, 
--without limitation, that your use is for the sole purpose of 
--programming logic devices manufactured by Altera and sold by 
--Altera or its authorized distributors.  Please refer to the 
--applicable agreement for further details.


LIBRARY ieee;
USE ieee.std_logic_1164.all;

LIBRARY lpm;
USE lpm.lpm_components.all;

ENTITY lpm_and0 IS
	PORT
	(
		data		: IN STD_LOGIC_2D (3 DOWNTO 0, 0 DOWNTO 0);
		result		: OUT STD_LOGIC 
	);
END lpm_and0;


ARCHITECTURE SYN OF lpm_and0 IS

	SIGNAL sub_wire0	: STD_LOGIC_VECTOR (0 DOWNTO 0);
	SIGNAL sub_wire1	: STD_LOGIC ;

BEGIN
	sub_wire1    <= sub_wire0(0);
	result    <= sub_wire1;

	lpm_and_component : lpm_and
	GENERIC MAP (
		lpm_size => 4,
		lpm_type => "LPM_AND",
		lpm_width => 1
	)
	PORT MAP (
		data => data,
		result => sub_wire0
	);



END SYN;

-- ============================================================
-- CNX file retrieval info
-- ============================================================
-- Retrieval info: PRIVATE: CompactSymbol NUMERIC "0"
-- Retrieval info: PRIVATE: GateFunction NUMERIC "0"
-- Retrieval info: PRIVATE: INTENDED_DEVICE_FAMILY STRING "Stratix II"
-- Retrieval info: PRIVATE: InputAsBus NUMERIC "1"
-- Retrieval info: PRIVATE: SYNTH_WRAPPER_GEN_POSTFIX STRING "1"
-- Retrieval info: PRIVATE: WidthInput NUMERIC "1"
-- Retrieval info: PRIVATE: nInput NUMERIC "4"
-- Retrieval info: CONSTANT: LPM_SIZE NUMERIC "4"
-- Retrieval info: CONSTANT: LPM_TYPE STRING "LPM_AND"
-- Retrieval info: CONSTANT: LPM_WIDTH NUMERIC "1"
-- Retrieval info: USED_PORT: data 4 0 1 0 INPUT NODEFVAL data[3..0][0..0]
-- Retrieval info: USED_PORT: result 0 0 0 0 OUTPUT NODEFVAL result
-- Retrieval info: CONNECT: @data 4 0 1 0 data 4 0 1 0
-- Retrieval info: CONNECT: result 0 0 0 0 @result 0 0 1 0
-- Retrieval info: LIBRARY: lpm lpm.lpm_components.all
-- Retrieval info: GEN_FILE: TYPE_NORMAL lpm_and0.vhd TRUE
-- Retrieval info: GEN_FILE: TYPE_NORMAL lpm_and0.inc TRUE
-- Retrieval info: GEN_FILE: TYPE_NORMAL lpm_and0.cmp TRUE
-- Retrieval info: GEN_FILE: TYPE_NORMAL lpm_and0.bsf TRUE FALSE
-- Retrieval info: GEN_FILE: TYPE_NORMAL lpm_and0_inst.vhd TRUE
-- Retrieval info: GEN_FILE: TYPE_NORMAL lpm_and0_syn.v TRUE
-- Retrieval info: LIB_FILE: lpm
