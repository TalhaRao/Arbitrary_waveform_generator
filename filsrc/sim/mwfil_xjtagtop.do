set SRCDIR F:/Master_Studies/Semester_2/Model_Based_Simulation/Labs/Lab_4/Practical_work/F:/Master_Studies/Semester_2/Model_Based_Simulation/Labs/Lab_4/Practical_work/filsrc
set SIMDIR F:/Master_Studies/Semester_2/Model_Based_Simulation/Labs/Lab_4/Practical_work/F:/Master_Studies/Semester_2/Model_Based_Simulation/Labs/Lab_4/Practical_work/filsrc/sim
set COMPILE vcom

set SIM vsim

vlib $SIMDIR/work
vmap work $SIMDIR/work

$COMPILE $SRCDIR/jtag_mac.v
$COMPILE $SRCDIR/jtag_mac_fifo_wrapper.vhd
$COMPILE $SRCDIR/simcycle_fifo_wrapper.vhd
$COMPILE $SRCDIR/mwfil_dpscram.vhd
$COMPILE $SRCDIR/mwfil_udfifo.vhd
$COMPILE $SRCDIR/mwfil_bus2dut.vhd
$COMPILE $SRCDIR/mwfil_chifcore.vhd
$COMPILE $SRCDIR/mwfil_controller.vhd
$COMPILE $SRCDIR/mwfil_dut2bus.vhd
$COMPILE $SRCDIR/fil_test_wrapper.vhd
$COMPILE $SRCDIR/mwfil_chiftop.vhd
$COMPILE $SRCDIR/fil_test_fil.vhd
