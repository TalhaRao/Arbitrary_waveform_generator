-- -------------------------------------------------------------
-- 
-- File Name: hdlsrc\AWFG_Phase2\TimeGenerator.vhd
-- Created: 2018-08-30 01:10:44
-- 
-- Generated by MATLAB 9.4 and HDL Coder 3.12
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: TimeGenerator
-- Source Path: Dynamic_Calculations/FPGA_Calculation/TimeGenerator
-- Hierarchy Level: 2
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY TimeGenerator IS
  PORT( clk                               :   IN    std_logic;
        reset                             :   IN    std_logic;
        enb                               :   IN    std_logic;
        M                                 :   IN    std_logic_vector(26 DOWNTO 0);  -- sfix27_En19
        T                                 :   IN    std_logic_vector(26 DOWNTO 0);  -- sfix27_En19
        Time_rsvd                         :   OUT   std_logic_vector(26 DOWNTO 0);  -- sfix27_En19
        readAddr                          :   OUT   std_logic_vector(7 DOWNTO 0)  -- uint8
        );
END TimeGenerator;


ARCHITECTURE rtl OF TimeGenerator IS

  -- Signals
  SIGNAL M_signed                         : signed(26 DOWNTO 0);  -- sfix27_En19
  SIGNAL Cast_out1                        : signed(26 DOWNTO 0);  -- sfix27_En19
  SIGNAL Delay_out1                       : signed(26 DOWNTO 0);  -- sfix27_En19
  SIGNAL Add1_add_cast                    : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL Add1_add_cast_1                  : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL Add1_add_temp                    : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL Add1_out1                        : unsigned(25 DOWNTO 0);  -- ufix26_En19
  SIGNAL T_signed                         : signed(26 DOWNTO 0);  -- sfix27_En19
  SIGNAL Constant2_out1                   : signed(26 DOWNTO 0);  -- sfix27_En19
  SIGNAL Product1_mul_temp                : signed(53 DOWNTO 0);  -- sfix54_En38
  SIGNAL Product1_out1                    : signed(26 DOWNTO 0);  -- sfix27_En19
  SIGNAL Product_mul_temp                 : signed(53 DOWNTO 0);  -- sfix54_En38
  SIGNAL Time_tmp                         : signed(26 DOWNTO 0);  -- sfix27_En19
  SIGNAL Bit_Slice_out1                   : unsigned(7 DOWNTO 0);  -- uint8
  SIGNAL Bias_const_val_1                 : unsigned(7 DOWNTO 0);  -- uint8
  SIGNAL Bias_out1                        : unsigned(7 DOWNTO 0);  -- uint8

BEGIN
  -- TIME GENERATOR & ACCUMULATOR

  M_signed <= signed(M);

  Delay_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      Delay_out1 <= to_signed(16#0000000#, 27);
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb = '1' THEN
        Delay_out1 <= Cast_out1;
      END IF;
    END IF;
  END PROCESS Delay_process;


  Add1_add_cast <= resize(Delay_out1, 32);
  Add1_add_cast_1 <= resize(M_signed, 32);
  Add1_add_temp <= Add1_add_cast + Add1_add_cast_1;
  Add1_out1 <= unsigned(Add1_add_temp(25 DOWNTO 0));

  Cast_out1 <= signed(resize(Add1_out1, 27));

  T_signed <= signed(T);

  Constant2_out1 <= to_signed(16#0001000#, 27);

  Product1_mul_temp <= T_signed * Constant2_out1;
  Product1_out1 <= Product1_mul_temp(45 DOWNTO 19);

  Product_mul_temp <= Cast_out1 * Product1_out1;
  Time_tmp <= Product_mul_temp(45 DOWNTO 19);

  Time_rsvd <= std_logic_vector(Time_tmp);

  Bit_Slice_out1 <= unsigned(Cast_out1(26 DOWNTO 19));

  Bias_const_val_1 <= to_unsigned(16#01#, 8);

  Bias_out1 <= Bit_Slice_out1 + Bias_const_val_1;

  readAddr <= std_logic_vector(Bias_out1);

END rtl;

