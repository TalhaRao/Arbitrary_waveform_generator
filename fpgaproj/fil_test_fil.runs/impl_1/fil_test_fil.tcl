proc start_step { step } {
  set stopFile ".stop.rst"
  if {[file isfile .stop.rst]} {
    puts ""
    puts "*** Halting run - EA reset detected ***"
    puts ""
    puts ""
    return -code error
  }
  set beginFile ".$step.begin.rst"
  set platform "$::tcl_platform(platform)"
  set user "$::tcl_platform(user)"
  set pid [pid]
  set host ""
  if { [string equal $platform unix] } {
    if { [info exist ::env(HOSTNAME)] } {
      set host $::env(HOSTNAME)
    }
  } else {
    if { [info exist ::env(COMPUTERNAME)] } {
      set host $::env(COMPUTERNAME)
    }
  }
  set ch [open $beginFile w]
  puts $ch "<?xml version=\"1.0\"?>"
  puts $ch "<ProcessHandle Version=\"1\" Minor=\"0\">"
  puts $ch "    <Process Command=\".planAhead.\" Owner=\"$user\" Host=\"$host\" Pid=\"$pid\">"
  puts $ch "    </Process>"
  puts $ch "</ProcessHandle>"
  close $ch
}

proc end_step { step } {
  set endFile ".$step.end.rst"
  set ch [open $endFile w]
  close $ch
}

proc step_failed { step } {
  set endFile ".$step.error.rst"
  set ch [open $endFile w]
  close $ch
}


start_step init_design
set ACTIVE_STEP init_design
set rc [catch {
  create_msg_db init_design.pb
  create_project -in_memory -part xc7z010clg400-1
  set_property design_mode GateLvl [current_fileset]
  set_param project.singleFileAddWarning.threshold 0
  set_property webtalk.parent_dir F:/Master_Studies/Semester_2/Model_Based_Simulation/Labs/Lab_4/Practical_work/fpgaproj/fil_test_fil.cache/wt [current_project]
  set_property parent.project_path F:/Master_Studies/Semester_2/Model_Based_Simulation/Labs/Lab_4/Practical_work/fpgaproj/fil_test_fil.xpr [current_project]
  set_property ip_output_repo F:/Master_Studies/Semester_2/Model_Based_Simulation/Labs/Lab_4/Practical_work/fpgaproj/fil_test_fil.cache/ip [current_project]
  set_property ip_cache_permissions {read write} [current_project]
  set_property XPM_LIBRARIES {XPM_CDC XPM_MEMORY} [current_project]
  add_files -quiet F:/Master_Studies/Semester_2/Model_Based_Simulation/Labs/Lab_4/Practical_work/fpgaproj/fil_test_fil.runs/synth_1/fil_test_fil.dcp
  read_ip -quiet f:/Master_Studies/Semester_2/Model_Based_Simulation/Labs/Lab_4/Practical_work/fpgaproj/fil_test_fil.srcs/sources_1/ip/clk_wiz_0/clk_wiz_0.xci
  set_property is_locked true [get_files f:/Master_Studies/Semester_2/Model_Based_Simulation/Labs/Lab_4/Practical_work/fpgaproj/fil_test_fil.srcs/sources_1/ip/clk_wiz_0/clk_wiz_0.xci]
  read_ip -quiet f:/Master_Studies/Semester_2/Model_Based_Simulation/Labs/Lab_4/Practical_work/fpgaproj/fil_test_fil.srcs/sources_1/ip/simcycle_fifo/simcycle_fifo.xci
  set_property is_locked true [get_files f:/Master_Studies/Semester_2/Model_Based_Simulation/Labs/Lab_4/Practical_work/fpgaproj/fil_test_fil.srcs/sources_1/ip/simcycle_fifo/simcycle_fifo.xci]
  read_ip -quiet f:/Master_Studies/Semester_2/Model_Based_Simulation/Labs/Lab_4/Practical_work/fpgaproj/fil_test_fil.srcs/sources_1/ip/jtag_mac_fifo/jtag_mac_fifo.xci
  set_property is_locked true [get_files f:/Master_Studies/Semester_2/Model_Based_Simulation/Labs/Lab_4/Practical_work/fpgaproj/fil_test_fil.srcs/sources_1/ip/jtag_mac_fifo/jtag_mac_fifo.xci]
  read_xdc F:/Master_Studies/Semester_2/Model_Based_Simulation/Labs/Lab_4/Practical_work/filsrc/fil_test_fil.xdc
  link_design -top fil_test_fil -part xc7z010clg400-1
  close_msg_db -file init_design.pb
} RESULT]
if {$rc} {
  step_failed init_design
  return -code error $RESULT
} else {
  end_step init_design
  unset ACTIVE_STEP 
}

start_step opt_design
set ACTIVE_STEP opt_design
set rc [catch {
  create_msg_db opt_design.pb
  opt_design 
  write_checkpoint -force fil_test_fil_opt.dcp
  catch { report_drc -file fil_test_fil_drc_opted.rpt }
  close_msg_db -file opt_design.pb
} RESULT]
if {$rc} {
  step_failed opt_design
  return -code error $RESULT
} else {
  end_step opt_design
  unset ACTIVE_STEP 
}

start_step place_design
set ACTIVE_STEP place_design
set rc [catch {
  create_msg_db place_design.pb
  implement_debug_core 
  place_design 
  write_checkpoint -force fil_test_fil_placed.dcp
  catch { report_io -file fil_test_fil_io_placed.rpt }
  catch { report_utilization -file fil_test_fil_utilization_placed.rpt -pb fil_test_fil_utilization_placed.pb }
  catch { report_control_sets -verbose -file fil_test_fil_control_sets_placed.rpt }
  close_msg_db -file place_design.pb
} RESULT]
if {$rc} {
  step_failed place_design
  return -code error $RESULT
} else {
  end_step place_design
  unset ACTIVE_STEP 
}

start_step route_design
set ACTIVE_STEP route_design
set rc [catch {
  create_msg_db route_design.pb
  route_design 
  write_checkpoint -force fil_test_fil_routed.dcp
  catch { report_drc -file fil_test_fil_drc_routed.rpt -pb fil_test_fil_drc_routed.pb -rpx fil_test_fil_drc_routed.rpx }
  catch { report_methodology -file fil_test_fil_methodology_drc_routed.rpt -rpx fil_test_fil_methodology_drc_routed.rpx }
  catch { report_power -file fil_test_fil_power_routed.rpt -pb fil_test_fil_power_summary_routed.pb -rpx fil_test_fil_power_routed.rpx }
  catch { report_route_status -file fil_test_fil_route_status.rpt -pb fil_test_fil_route_status.pb }
  catch { report_clock_utilization -file fil_test_fil_clock_utilization_routed.rpt }
  catch { report_timing_summary -warn_on_violation -max_paths 10 -file fil_test_fil_timing_summary_routed.rpt -rpx fil_test_fil_timing_summary_routed.rpx }
  close_msg_db -file route_design.pb
} RESULT]
if {$rc} {
  write_checkpoint -force fil_test_fil_routed_error.dcp
  step_failed route_design
  return -code error $RESULT
} else {
  end_step route_design
  unset ACTIVE_STEP 
}

