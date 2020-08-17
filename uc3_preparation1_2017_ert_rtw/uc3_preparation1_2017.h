/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: uc3_preparation1_2017.h
 *
 * Code generated for Simulink model 'uc3_preparation1_2017'.
 *
 * Model version                  : 1.357
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Tue Aug 28 20:40:17 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_uc3_preparation1_2017_h_
#define RTW_HEADER_uc3_preparation1_2017_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef uc3_preparation1_2017_COMMON_INCLUDES_
# define uc3_preparation1_2017_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* uc3_preparation1_2017_COMMON_INCLUDES_ */

#include "uc3_preparation1_2017_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T yy[132];
  real32_T y[129];
  real32_T counter;                    /* '<S6>/Chart' */
} B_uc3_preparation1_2017_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int32_T UnitDelay1_DSTATE;           /* '<S21>/Unit Delay1' */
  real32_T cc0[387];                   /* '<S5>/RT_CPU' */
  real32_T i0;                         /* '<S5>/RT_CPU' */
  uint8_T is_c1_uc3_preparation1_2017; /* '<S6>/Chart' */
  boolean_T cc0_not_empty;             /* '<S5>/RT_CPU' */
} DW_uc3_preparation1_2017_T;

/* Parameters (default storage) */
struct P_uc3_preparation1_2017_T_ {
  int32_T Amplitude_Value;             /* Computed Parameter: Amplitude_Value
                                        * Referenced by: '<Root>/Amplitude'
                                        */
  int32_T Mode_Value;                  /* Computed Parameter: Mode_Value
                                        * Referenced by: '<Root>/Mode'
                                        */
  int32_T Freq_in_Hz_Value;            /* Computed Parameter: Freq_in_Hz_Value
                                        * Referenced by: '<Root>/Freq_in_Hz'
                                        */
  int32_T duty_Value;                  /* Computed Parameter: duty_Value
                                        * Referenced by: '<Root>/duty'
                                        */
  int32_T Polynomial_Value;            /* Computed Parameter: Polynomial_Value
                                        * Referenced by: '<Root>/Polynomial'
                                        */
  int32_T f_clk_Value;                 /* Computed Parameter: f_clk_Value
                                        * Referenced by: '<S5>/f_clk'
                                        */
  int32_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S21>/Constant1'
                                        */
  int32_T UnitDelay1_InitialCondition; /* Computed Parameter: UnitDelay1_InitialCondition
                                        * Referenced by: '<S21>/Unit Delay1'
                                        */
  int32_T Constant3_Value;             /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S21>/Constant3'
                                        */
  int32_T Switch_Threshold;            /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S21>/Switch'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S16>/Gain'
                                        */
  real32_T Delay1_InitialCondition;    /* Computed Parameter: Delay1_InitialCondition
                                        * Referenced by: '<S6>/Delay1'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S11>/Constant'
                                        */
  real32_T Constant_Value_l;           /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S12>/Constant'
                                        */
  real32_T Constant1_Value_d;          /* Computed Parameter: Constant1_Value_d
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real32_T Constant_Value_k[3];        /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S9>/Constant'
                                        */
  real32_T Bias_Bias;                  /* Computed Parameter: Bias_Bias
                                        * Referenced by: '<S9>/Bias'
                                        */
  real32_T Gain_Gain_b;                /* Computed Parameter: Gain_Gain_b
                                        * Referenced by: '<S9>/Gain'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S9>/Gain2'
                                        */
  real32_T Gain_Gain_a;                /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S8>/Gain'
                                        */
  real32_T cte2_Value;                 /* Computed Parameter: cte2_Value
                                        * Referenced by: '<S8>/cte2'
                                        */
  real32_T n_Value;                    /* Computed Parameter: n_Value
                                        * Referenced by: '<S8>/n'
                                        */
  real32_T Gain1_Gain_m;               /* Computed Parameter: Gain1_Gain_m
                                        * Referenced by: '<S8>/Gain1'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S6>/Delay1'
                                        */
  int16_T Constant1_Value_n;           /* Computed Parameter: Constant1_Value_n
                                        * Referenced by: '<S13>/Constant1'
                                        */
  int16_T Constant_Value_p;            /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S4>/Constant'
                                        */
  uint8_T u_bit_data_Value;            /* Computed Parameter: u_bit_data_Value
                                        * Referenced by: '<S13>/8_bit_data'
                                        */
  uint8_T Constant36_Value;            /* Computed Parameter: Constant36_Value
                                        * Referenced by: '<S13>/Constant36'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_uc3_preparation1_2017_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_uc3_preparation1_2017_T uc3_preparation1_2017_P;

/* Block signals (default storage) */
extern B_uc3_preparation1_2017_T uc3_preparation1_2017_B;

/* Block states (default storage) */
extern DW_uc3_preparation1_2017_T uc3_preparation1_2017_DW;

/* Model entry point functions */
extern void uc3_preparation1_2017_initialize(void);
extern void uc3_preparation1_2017_step(void);
extern void uc3_preparation1_2017_terminate(void);

/* Real-time Model object */
extern RT_MODEL_uc3_preparation1_201_T *const uc3_preparation1_2017_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Breaks' : Unused code path elimination
 * Block '<S5>/Coefficients' : Unused code path elimination
 * Block '<S6>/Scope7' : Unused code path elimination
 * Block '<S5>/Signal1' : Unused code path elimination
 * Block '<S5>/Signal3' : Unused code path elimination
 * Block '<S8>/Display' : Unused code path elimination
 * Block '<S8>/Display1' : Unused code path elimination
 * Block '<S8>/Display2' : Unused code path elimination
 * Block '<S8>/Display3' : Unused code path elimination
 * Block '<S8>/Display4' : Unused code path elimination
 * Block '<S8>/Display5' : Unused code path elimination
 * Block '<S8>/Display6' : Unused code path elimination
 * Block '<S9>/C0' : Unused code path elimination
 * Block '<S9>/C1' : Unused code path elimination
 * Block '<S9>/C2' : Unused code path elimination
 * Block '<S9>/Scope' : Unused code path elimination
 * Block '<S13>/Constant' : Unused code path elimination
 * Block '<S13>/Data Type Conversion' : Unused code path elimination
 * Block '<S13>/Data Type Conversion1' : Unused code path elimination
 * Block '<S13>/Data Type Conversion2' : Unused code path elimination
 * Block '<S13>/Delay' : Unused code path elimination
 * Block '<S20>/Bias1' : Unused code path elimination
 * Block '<S20>/Data Type Conversion' : Unused code path elimination
 * Block '<S20>/Data Type Conversion1' : Unused code path elimination
 * Block '<S20>/Delay1' : Unused code path elimination
 * Block '<S20>/Delay2' : Unused code path elimination
 * Block '<S20>/Delay3' : Unused code path elimination
 * Block '<S20>/Delay4' : Unused code path elimination
 * Block '<S20>/Delay5' : Unused code path elimination
 * Block '<S20>/Delay6' : Unused code path elimination
 * Block '<S20>/Delay7' : Unused code path elimination
 * Block '<S20>/Delay8' : Unused code path elimination
 * Block '<S20>/Delay9' : Unused code path elimination
 * Block '<S20>/Display' : Unused code path elimination
 * Block '<S20>/Display1' : Unused code path elimination
 * Block '<S20>/Display2' : Unused code path elimination
 * Block '<S20>/Gain' : Unused code path elimination
 * Block '<S20>/Gain1' : Unused code path elimination
 * Block '<S20>/Gain3' : Unused code path elimination
 * Block '<S20>/Gain4' : Unused code path elimination
 * Block '<S20>/Product' : Unused code path elimination
 * Block '<S20>/Product1' : Unused code path elimination
 * Block '<S20>/Product2' : Unused code path elimination
 * Block '<S20>/Relational Operator1' : Unused code path elimination
 * Block '<S20>/Scope' : Unused code path elimination
 * Block '<S20>/Scope1' : Unused code path elimination
 * Block '<S20>/Scope2' : Unused code path elimination
 * Block '<S22>/And' : Unused code path elimination
 * Block '<S22>/Switch1' : Unused code path elimination
 * Block '<S22>/convert' : Unused code path elimination
 * Block '<S22>/din_d' : Unused code path elimination
 * Block '<S22>/dout_type' : Unused code path elimination
 * Block '<S25>/Compare' : Unused code path elimination
 * Block '<S25>/Constant' : Unused code path elimination
 * Block '<S22>/ram' : Unused code path elimination
 * Block '<S22>/ram_data' : Unused code path elimination
 * Block '<S22>/select' : Unused code path elimination
 * Block '<S22>/switch' : Unused code path elimination
 * Block '<S22>/we_d' : Unused code path elimination
 * Block '<S22>/wr_port' : Unused code path elimination
 * Block '<S23>/And' : Unused code path elimination
 * Block '<S23>/Switch1' : Unused code path elimination
 * Block '<S23>/convert' : Unused code path elimination
 * Block '<S23>/din_d' : Unused code path elimination
 * Block '<S23>/dout_type' : Unused code path elimination
 * Block '<S26>/Compare' : Unused code path elimination
 * Block '<S26>/Constant' : Unused code path elimination
 * Block '<S23>/ram' : Unused code path elimination
 * Block '<S23>/ram_data' : Unused code path elimination
 * Block '<S23>/select' : Unused code path elimination
 * Block '<S23>/switch' : Unused code path elimination
 * Block '<S23>/we_d' : Unused code path elimination
 * Block '<S23>/wr_port' : Unused code path elimination
 * Block '<S24>/And' : Unused code path elimination
 * Block '<S24>/Switch1' : Unused code path elimination
 * Block '<S24>/convert' : Unused code path elimination
 * Block '<S24>/din_d' : Unused code path elimination
 * Block '<S24>/dout_type' : Unused code path elimination
 * Block '<S27>/Compare' : Unused code path elimination
 * Block '<S27>/Constant' : Unused code path elimination
 * Block '<S24>/ram' : Unused code path elimination
 * Block '<S24>/ram_data' : Unused code path elimination
 * Block '<S24>/select' : Unused code path elimination
 * Block '<S24>/switch' : Unused code path elimination
 * Block '<S24>/we_d' : Unused code path elimination
 * Block '<S24>/wr_port' : Unused code path elimination
 * Block '<S20>/Subtract' : Unused code path elimination
 * Block '<S20>/Switch' : Unused code path elimination
 * Block '<S20>/Switch1' : Unused code path elimination
 * Block '<S20>/TimeGen' : Unused code path elimination
 * Block '<S20>/adding_all the terms' : Unused code path elimination
 * Block '<S16>/Gain1' : Unused code path elimination
 * Block '<S21>/Bias' : Unused code path elimination
 * Block '<S21>/Constant2' : Unused code path elimination
 * Block '<S21>/Display1' : Unused code path elimination
 * Block '<S21>/Display2' : Unused code path elimination
 * Block '<S21>/Display4' : Unused code path elimination
 * Block '<S21>/Display5' : Unused code path elimination
 * Block '<S21>/Display6' : Unused code path elimination
 * Block '<S21>/Product' : Unused code path elimination
 * Block '<S21>/Product1' : Unused code path elimination
 * Block '<Root>/Output_wave' : Unused code path elimination
 * Block '<Root>/Output_wave1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'uc3_preparation1_2017'
 * '<S1>'   : 'uc3_preparation1_2017/CandHDL_c'
 * '<S2>'   : 'uc3_preparation1_2017/CandHDL_hdl'
 * '<S3>'   : 'uc3_preparation1_2017/Model Info'
 * '<S4>'   : 'uc3_preparation1_2017/CandHDL_c/cgenerate'
 * '<S5>'   : 'uc3_preparation1_2017/CandHDL_c/cgenerate/Subsystem'
 * '<S6>'   : 'uc3_preparation1_2017/CandHDL_c/cgenerate/Subsystem/Counter'
 * '<S7>'   : 'uc3_preparation1_2017/CandHDL_c/cgenerate/Subsystem/RT_CPU'
 * '<S8>'   : 'uc3_preparation1_2017/CandHDL_c/cgenerate/Subsystem/precalculations'
 * '<S9>'   : 'uc3_preparation1_2017/CandHDL_c/cgenerate/Subsystem/selectror'
 * '<S10>'  : 'uc3_preparation1_2017/CandHDL_c/cgenerate/Subsystem/Counter/Chart'
 * '<S11>'  : 'uc3_preparation1_2017/CandHDL_c/cgenerate/Subsystem/Counter/Compare To Zero2'
 * '<S12>'  : 'uc3_preparation1_2017/CandHDL_c/cgenerate/Subsystem/Counter/Compare To Zero3'
 * '<S13>'  : 'uc3_preparation1_2017/CandHDL_hdl/hdlgenerate'
 * '<S14>'  : 'uc3_preparation1_2017/CandHDL_hdl/hdlgenerate/Bit Concat'
 * '<S15>'  : 'uc3_preparation1_2017/CandHDL_hdl/hdlgenerate/Bit Slice'
 * '<S16>'  : 'uc3_preparation1_2017/CandHDL_hdl/hdlgenerate/FPGA_simulation'
 * '<S17>'  : 'uc3_preparation1_2017/CandHDL_hdl/hdlgenerate/Bit Concat/Bit Concat2'
 * '<S18>'  : 'uc3_preparation1_2017/CandHDL_hdl/hdlgenerate/Bit Concat/Bit Concat2/bit_concat'
 * '<S19>'  : 'uc3_preparation1_2017/CandHDL_hdl/hdlgenerate/Bit Slice/bit_slice'
 * '<S20>'  : 'uc3_preparation1_2017/CandHDL_hdl/hdlgenerate/FPGA_simulation/ FPGA_Part'
 * '<S21>'  : 'uc3_preparation1_2017/CandHDL_hdl/hdlgenerate/FPGA_simulation/TimeGenerator'
 * '<S22>'  : 'uc3_preparation1_2017/CandHDL_hdl/hdlgenerate/FPGA_simulation/ FPGA_Part/Single Port RAM'
 * '<S23>'  : 'uc3_preparation1_2017/CandHDL_hdl/hdlgenerate/FPGA_simulation/ FPGA_Part/Single Port RAM1'
 * '<S24>'  : 'uc3_preparation1_2017/CandHDL_hdl/hdlgenerate/FPGA_simulation/ FPGA_Part/Single Port RAM2'
 * '<S25>'  : 'uc3_preparation1_2017/CandHDL_hdl/hdlgenerate/FPGA_simulation/ FPGA_Part/Single Port RAM/is_new'
 * '<S26>'  : 'uc3_preparation1_2017/CandHDL_hdl/hdlgenerate/FPGA_simulation/ FPGA_Part/Single Port RAM1/is_new'
 * '<S27>'  : 'uc3_preparation1_2017/CandHDL_hdl/hdlgenerate/FPGA_simulation/ FPGA_Part/Single Port RAM2/is_new'
 * '<S28>'  : 'uc3_preparation1_2017/CandHDL_hdl/hdlgenerate/FPGA_simulation/TimeGenerator/Bit Slice'
 * '<S29>'  : 'uc3_preparation1_2017/CandHDL_hdl/hdlgenerate/FPGA_simulation/TimeGenerator/Bit Slice/bit_slice'
 */
#endif                                 /* RTW_HEADER_uc3_preparation1_2017_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
