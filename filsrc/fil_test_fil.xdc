create_clock -period 8.000 -name sysclk -waveform {0.000 4.000} [get_ports sysclk]
set_property PACKAGE_PIN L16 [get_ports sysclk]
set_property IOSTANDARD LVCMOS33 [get_ports sysclk]
set_property PACKAGE_PIN R18 [get_ports sysrst]
set_property IOSTANDARD LVCMOS33 [get_ports sysrst]
create_clock -period 15.151515 -name TCK -waveform {0.000 7.575758} [get_pins u_BSCANE2/TCK]
set_false_path -from [get_clocks clk_out1_clk_wiz_0] -to [get_clocks TCK]
set_false_path -from [get_clocks TCK] -to [get_clocks clk_out1_clk_wiz_0]