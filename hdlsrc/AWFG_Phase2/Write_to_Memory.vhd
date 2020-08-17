-- -------------------------------------------------------------
-- 
-- File Name: hdlsrc\AWFG_Phase2\Write_to_Memory.vhd
-- Created: 2018-08-30 01:10:44
-- 
-- Generated by MATLAB 9.4 and HDL Coder 3.12
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: Write_to_Memory
-- Source Path: Dynamic_Calculations/FPGA_Calculation/Write_to_Memory
-- Hierarchy Level: 2
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY Write_to_Memory IS
  PORT( clk                               :   IN    std_logic;
        enb                               :   IN    std_logic;
        readAddr                          :   IN    std_logic_vector(7 DOWNTO 0);  -- uint8
        c0                                :   IN    std_logic_vector(26 DOWNTO 0);  -- sfix27_En19
        c1                                :   IN    std_logic_vector(26 DOWNTO 0);  -- sfix27_En19
        c2                                :   IN    std_logic_vector(26 DOWNTO 0);  -- sfix27_En19
        write                             :   IN    std_logic;
        writeAddr                         :   IN    std_logic_vector(7 DOWNTO 0);  -- uint8
        c0Ram                             :   OUT   std_logic_vector(26 DOWNTO 0);  -- sfix27_En19
        c1Ram                             :   OUT   std_logic_vector(26 DOWNTO 0);  -- sfix27_En19
        c2Ram                             :   OUT   std_logic_vector(26 DOWNTO 0)  -- sfix27_En19
        );
END Write_to_Memory;


ARCHITECTURE rtl OF Write_to_Memory IS

  -- Component Declarations
  COMPONENT SinglePortRAM_generic
    GENERIC( AddrWidth                    : integer;
             DataWidth                    : integer
             );
    PORT( clk                             :   IN    std_logic;
          enb                             :   IN    std_logic;
          din                             :   IN    std_logic_vector(DataWidth - 1 DOWNTO 0);  -- generic width
          addr                            :   IN    std_logic_vector(AddrWidth - 1 DOWNTO 0);  -- generic width
          we                              :   IN    std_logic;
          dout                            :   OUT   std_logic_vector(DataWidth - 1 DOWNTO 0)  -- generic width
          );
  END COMPONENT;

  -- Component Configuration Statements
  FOR ALL : SinglePortRAM_generic
    USE ENTITY work.SinglePortRAM_generic(rtl);

  -- Signals
  SIGNAL readAddr_unsigned                : unsigned(7 DOWNTO 0);  -- uint8
  SIGNAL writeAddr_unsigned               : unsigned(7 DOWNTO 0);  -- uint8
  SIGNAL Switch_out1                      : unsigned(7 DOWNTO 0);  -- uint8
  SIGNAL Single_Port_RAM_out1             : std_logic_vector(26 DOWNTO 0);  -- ufix27
  SIGNAL Single_Port_RAM1_out1            : std_logic_vector(26 DOWNTO 0);  -- ufix27
  SIGNAL Single_Port_RAM2_out1            : std_logic_vector(26 DOWNTO 0);  -- ufix27

BEGIN
  -- WRITE TO MEMORY BLOCK

  u_Single_Port_RAM : SinglePortRAM_generic
    GENERIC MAP( AddrWidth => 8,
                 DataWidth => 27
                 )
    PORT MAP( clk => clk,
              enb => enb,
              din => c0,
              addr => std_logic_vector(Switch_out1),
              we => write,
              dout => Single_Port_RAM_out1
              );

  u_Single_Port_RAM1 : SinglePortRAM_generic
    GENERIC MAP( AddrWidth => 8,
                 DataWidth => 27
                 )
    PORT MAP( clk => clk,
              enb => enb,
              din => c1,
              addr => std_logic_vector(Switch_out1),
              we => write,
              dout => Single_Port_RAM1_out1
              );

  u_Single_Port_RAM2 : SinglePortRAM_generic
    GENERIC MAP( AddrWidth => 8,
                 DataWidth => 27
                 )
    PORT MAP( clk => clk,
              enb => enb,
              din => c2,
              addr => std_logic_vector(Switch_out1),
              we => write,
              dout => Single_Port_RAM2_out1
              );

  readAddr_unsigned <= unsigned(readAddr);

  writeAddr_unsigned <= unsigned(writeAddr);

  
  Switch_out1 <= readAddr_unsigned WHEN write = '0' ELSE
      writeAddr_unsigned;

  c0Ram <= Single_Port_RAM_out1;

  c1Ram <= Single_Port_RAM1_out1;

  c2Ram <= Single_Port_RAM2_out1;

END rtl;

