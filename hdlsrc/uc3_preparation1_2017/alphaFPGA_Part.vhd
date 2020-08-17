-- -------------------------------------------------------------
-- 
-- File Name: hdlsrc\uc3_preparation1_2017\alphaFPGA_Part.vhd
-- Created: 2018-08-28 20:42:58
-- 
-- Generated by MATLAB 9.4 and HDL Coder 3.12
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: alphaFPGA_Part
-- Source Path: uc3_preparation1_2017/CandHDL_hdl/hdlgenerate/FPGA_simulation/ FPGA_Part
-- Hierarchy Level: 3
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
USE work.CandHDL_hdl_pkg.ALL;

ENTITY alphaFPGA_Part IS
  PORT( clk                               :   IN    std_logic;
        reset                             :   IN    std_logic;
        enb                               :   IN    std_logic;
        Cc0                               :   IN    std_logic_vector(31 DOWNTO 0);  -- int32
        Cc1                               :   IN    std_logic_vector(31 DOWNTO 0);  -- int32
        Cc2                               :   IN    std_logic_vector(31 DOWNTO 0);  -- int32
        Counter_out_write_addr            :   IN    std_logic_vector(31 DOWNTO 0);  -- int32
        We_write_enable                   :   IN    std_logic_vector(31 DOWNTO 0);  -- int32
        Time_rsvd                         :   IN    std_logic_vector(31 DOWNTO 0);  -- sfix32_En19
        read_rsvd                         :   IN    std_logic_vector(7 DOWNTO 0);  -- uint8
        output_wave_y                     :   OUT   std_logic_vector(15 DOWNTO 0)  -- uint16
        );
END alphaFPGA_Part;


ARCHITECTURE rtl OF alphaFPGA_Part IS

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
  SIGNAL Cc0_signed                       : signed(31 DOWNTO 0);  -- int32
  SIGNAL Gain_cast                        : signed(63 DOWNTO 0);  -- sfix64_En55
  SIGNAL Gain_out1                        : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL We_write_enable_signed           : signed(31 DOWNTO 0);  -- int32
  SIGNAL Data_Type_Conversion_out1        : std_logic;
  SIGNAL read_unsigned                    : unsigned(7 DOWNTO 0);  -- uint8
  SIGNAL Counter_out_write_addr_signed    : signed(31 DOWNTO 0);  -- int32
  SIGNAL Data_Type_Conversion1_out1       : unsigned(7 DOWNTO 0);  -- uint8
  SIGNAL Switch_out1                      : unsigned(7 DOWNTO 0);  -- uint8
  SIGNAL Single_Port_RAM_out1             : std_logic_vector(31 DOWNTO 0);  -- ufix32
  SIGNAL Single_Port_RAM_out1_signed      : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL Delay9_reg                       : vector_of_signed32(0 TO 1);  -- sfix32 [2]
  SIGNAL C0                               : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL Cc1_signed                       : signed(31 DOWNTO 0);  -- int32
  SIGNAL Gain1_cast                       : signed(63 DOWNTO 0);  -- sfix64_En45
  SIGNAL Gain1_out1                       : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL Single_Port_RAM1_out1            : std_logic_vector(31 DOWNTO 0);  -- ufix32
  SIGNAL Single_Port_RAM1_out1_signed     : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL Delay4_out1                      : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL Time_signed                      : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL Delay7_out1                      : unsigned(7 DOWNTO 0);  -- uint8
  SIGNAL Relational_Operator1_relop1      : std_logic;
  SIGNAL x0                               : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL Delay8_out1                      : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL alphax_x0                        : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL alphax_x0_1                      : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL Product1_mul_temp                : signed(63 DOWNTO 0);  -- sfix64_En38
  SIGNAL Product1_out1                    : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL C1_x_x0                          : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL Cc2_signed                       : signed(31 DOWNTO 0);  -- int32
  SIGNAL Gain3_cast                       : signed(63 DOWNTO 0);  -- sfix64_En50
  SIGNAL Gain3_out1                       : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL Single_Port_RAM2_out1            : std_logic_vector(31 DOWNTO 0);  -- ufix32
  SIGNAL Single_Port_RAM2_out1_signed     : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL Delay2_out1                      : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL Product2_mul_temp                : signed(63 DOWNTO 0);  -- sfix64_En38
  SIGNAL Product2_out1                    : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL Product_mul_temp                 : signed(63 DOWNTO 0);  -- sfix64_En38
  SIGNAL Product_out1                     : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL c2_x_x0_2                        : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL adding_all_the_terms_add_temp    : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL adding_all_the_terms_out1        : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL Bias1_const_val_1                : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL Bias1_out1                       : signed(31 DOWNTO 0);  -- sfix32_En19
  SIGNAL Gain4_cast                       : signed(63 DOWNTO 0);  -- sfix64_En37
  SIGNAL Gain4_out1                       : unsigned(15 DOWNTO 0);  -- uint16
  SIGNAL alphax_x0_2                      : signed(31 DOWNTO 0);  -- sfix32_En19

BEGIN
  -- Check the previous and next address
  -- 
  -- if write has been done read the address
  -- 
  -- the time is here the actual time 
  -- 
  -- read addrres is my generated time  

  u_Single_Port_RAM : SinglePortRAM_generic
    GENERIC MAP( AddrWidth => 8,
                 DataWidth => 32
                 )
    PORT MAP( clk => clk,
              enb => enb,
              din => std_logic_vector(Gain_out1),
              addr => std_logic_vector(Switch_out1),
              we => Data_Type_Conversion_out1,
              dout => Single_Port_RAM_out1
              );

  u_Single_Port_RAM1 : SinglePortRAM_generic
    GENERIC MAP( AddrWidth => 8,
                 DataWidth => 32
                 )
    PORT MAP( clk => clk,
              enb => enb,
              din => std_logic_vector(Gain1_out1),
              addr => std_logic_vector(Switch_out1),
              we => Data_Type_Conversion_out1,
              dout => Single_Port_RAM1_out1
              );

  u_Single_Port_RAM2 : SinglePortRAM_generic
    GENERIC MAP( AddrWidth => 8,
                 DataWidth => 32
                 )
    PORT MAP( clk => clk,
              enb => enb,
              din => std_logic_vector(Gain3_out1),
              addr => std_logic_vector(Switch_out1),
              we => Data_Type_Conversion_out1,
              dout => Single_Port_RAM2_out1
              );

  Cc0_signed <= signed(Cc0);

  Gain_cast <= resize(Cc0_signed & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0', 64);
  Gain_out1 <= resize(Gain_cast(63 DOWNTO 36), 32);

  We_write_enable_signed <= signed(We_write_enable);

  
  Data_Type_Conversion_out1 <= '1' WHEN We_write_enable_signed /= to_signed(0, 32) ELSE
      '0';

  read_unsigned <= unsigned(read_rsvd);

  Counter_out_write_addr_signed <= signed(Counter_out_write_addr);

  Data_Type_Conversion1_out1 <= unsigned(Counter_out_write_addr_signed(7 DOWNTO 0));

  
  Switch_out1 <= read_unsigned WHEN Data_Type_Conversion_out1 = '0' ELSE
      Data_Type_Conversion1_out1;

  Single_Port_RAM_out1_signed <= signed(Single_Port_RAM_out1);

  Delay9_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      Delay9_reg <= (OTHERS => to_signed(0, 32));
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb = '1' THEN
        Delay9_reg(0) <= Single_Port_RAM_out1_signed;
        Delay9_reg(1) <= Delay9_reg(0);
      END IF;
    END IF;
  END PROCESS Delay9_process;

  C0 <= Delay9_reg(1);

  Cc1_signed <= signed(Cc1);

  Gain1_cast <= resize(Cc1_signed & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0', 64);
  Gain1_out1 <= Gain1_cast(57 DOWNTO 26);

  Single_Port_RAM1_out1_signed <= signed(Single_Port_RAM1_out1);

  Delay4_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      Delay4_out1 <= to_signed(0, 32);
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb = '1' THEN
        Delay4_out1 <= Single_Port_RAM1_out1_signed;
      END IF;
    END IF;
  END PROCESS Delay4_process;


  Time_signed <= signed(Time_rsvd);

  Delay7_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      Delay7_out1 <= to_unsigned(16#00#, 8);
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb = '1' THEN
        Delay7_out1 <= read_unsigned;
      END IF;
    END IF;
  END PROCESS Delay7_process;


  
  Relational_Operator1_relop1 <= '1' WHEN read_unsigned /= Delay7_out1 ELSE
      '0';

  Delay8_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      Delay8_out1 <= to_signed(0, 32);
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb = '1' THEN
        Delay8_out1 <= x0;
      END IF;
    END IF;
  END PROCESS Delay8_process;


  
  x0 <= Delay8_out1 WHEN Relational_Operator1_relop1 = '0' ELSE
      Time_signed;

  alphax_x0 <= Time_signed - x0;

  reduced_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      alphax_x0_1 <= to_signed(0, 32);
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb = '1' THEN
        alphax_x0_1 <= alphax_x0;
      END IF;
    END IF;
  END PROCESS reduced_process;


  Product1_mul_temp <= Delay4_out1 * alphax_x0_1;
  Product1_out1 <= Product1_mul_temp(50 DOWNTO 19);

  Delay5_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      C1_x_x0 <= to_signed(0, 32);
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb = '1' THEN
        C1_x_x0 <= Product1_out1;
      END IF;
    END IF;
  END PROCESS Delay5_process;


  Cc2_signed <= signed(Cc2);

  Gain3_cast <= resize(Cc2_signed & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0', 64);
  Gain3_out1 <= Gain3_cast(62 DOWNTO 31);

  Single_Port_RAM2_out1_signed <= signed(Single_Port_RAM2_out1);

  Delay2_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      Delay2_out1 <= to_signed(0, 32);
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb = '1' THEN
        Delay2_out1 <= Single_Port_RAM2_out1_signed;
      END IF;
    END IF;
  END PROCESS Delay2_process;


  Product2_mul_temp <= alphax_x0_1 * alphax_x0_1;
  Product2_out1 <= Product2_mul_temp(50 DOWNTO 19);

  Product_mul_temp <= Delay2_out1 * Product2_out1;
  Product_out1 <= Product_mul_temp(50 DOWNTO 19);

  Delay3_process : PROCESS (clk, reset)
  BEGIN
    IF reset = '1' THEN
      c2_x_x0_2 <= to_signed(0, 32);
    ELSIF clk'EVENT AND clk = '1' THEN
      IF enb = '1' THEN
        c2_x_x0_2 <= Product_out1;
      END IF;
    END IF;
  END PROCESS Delay3_process;


  adding_all_the_terms_add_temp <= C0 + C1_x_x0;
  adding_all_the_terms_out1 <= adding_all_the_terms_add_temp + c2_x_x0_2;

  Bias1_const_val_1 <= to_signed(3670016, 32);

  Bias1_out1 <= adding_all_the_terms_out1 + Bias1_const_val_1;

  Gain4_cast <= resize(Bias1_out1 & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & '0', 64);
  Gain4_out1 <= unsigned(Gain4_cast(52 DOWNTO 37));

  output_wave_y <= std_logic_vector(Gain4_out1);








END rtl;
