/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AWFG_Phase2.h
 *
 * Code generated for Simulink model 'AWFG_Phase2'.
 *
 * Model version                  : 1.497
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Tue Aug 28 21:40:47 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Emulation hardware selection:
 *    Differs from embedded hardware (Custom Processor->MATLAB Host Computer)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AWFG_Phase2_h_
#define RTW_HEADER_AWFG_Phase2_h_
#include <stddef.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef AWFG_Phase2_COMMON_INCLUDES_
# define AWFG_Phase2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* AWFG_Phase2_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#define AWFG_Phase2_M                  (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef SS_INT64
#define SS_INT64                       25
#endif

#ifndef SS_UINT64
#define SS_UINT64                      26
#endif

/* Custom Type definition for MATLAB Function: '<S5>/RT_CPU' */
#ifndef struct_emxArray_real32_T_256x3
#define struct_emxArray_real32_T_256x3

struct emxArray_real32_T_256x3
{
  real32_T data[768];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real32_T_256x3*/

#ifndef typedef_emxArray_real32_T_256x3
#define typedef_emxArray_real32_T_256x3

typedef struct emxArray_real32_T_256x3 emxArray_real32_T_256x3;

#endif                                 /*typedef_emxArray_real32_T_256x3*/

#ifndef struct_emxArray_real32_T_1x255
#define struct_emxArray_real32_T_1x255

struct emxArray_real32_T_1x255
{
  real32_T data[255];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real32_T_1x255*/

#ifndef typedef_emxArray_real32_T_1x255
#define typedef_emxArray_real32_T_1x255

typedef struct emxArray_real32_T_1x255 emxArray_real32_T_1x255;

#endif                                 /*typedef_emxArray_real32_T_1x255*/

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  emxArray_real32_T_256x3 cc0;         /* '<S5>/RT_CPU' */
  emxArray_real32_T_1x255 b0;          /* '<S5>/RT_CPU' */
  real_T tmp_data[257];
  real32_T cc[1024];                   /* '<S5>/RT_CPU' */
  real32_T yy_data[261];
  real32_T y_data[258];
  real32_T x_data[257];
  real32_T DelayInput1_DSTATE;         /* '<S26>/Delay Input1' */
  real32_T DelayInput1_DSTATE_e;       /* '<S27>/Delay Input1' */
  real32_T DelayInput1_DSTATE_d;       /* '<S28>/Delay Input1' */
  real32_T DelayInput1_DSTATE_a;       /* '<S29>/Delay Input1' */
  real32_T DelayInput1_DSTATE_j;       /* '<S30>/Delay Input1' */
  real32_T DelayInput1_DSTATE_b;       /* '<S31>/Delay Input1' */
  real32_T i0;                         /* '<S5>/RT_CPU' */
  int32_T SFunction_DIMS2[2];          /* '<S5>/RT_CPU' */
  int32_T SFunction_DIMS3[2];          /* '<S5>/RT_CPU' */
  int32_T Delay_DSTATE;                /* '<S10>/Delay' */
  int32_T clockTickCounter;            /* '<S5>/Trigger' */
  boolean_T cc0_not_empty;             /* '<S5>/RT_CPU' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState CoefficientSequencer_Trig_ZCE;/* '<S5>/Coefficient Sequencer' */
} PrevZCX;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* Model entry point functions */
extern void AWFG_Phase2_initialize(void);
extern void AWFG_Phase2_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/Add' : Unused code path elimination
 * Block '<S8>/Delay' : Unused code path elimination
 * Block '<S8>/Delay1' : Unused code path elimination
 * Block '<S8>/Delay2' : Unused code path elimination
 * Block '<S8>/Delay3' : Unused code path elimination
 * Block '<S8>/Delay4' : Unused code path elimination
 * Block '<S8>/Delay5' : Unused code path elimination
 * Block '<S8>/Delay6' : Unused code path elimination
 * Block '<S8>/Delay7' : Unused code path elimination
 * Block '<S8>/Delay8' : Unused code path elimination
 * Block '<S11>/Add' : Unused code path elimination
 * Block '<S11>/Delay' : Unused code path elimination
 * Block '<S11>/Delay1' : Unused code path elimination
 * Block '<S11>/NotEqual' : Unused code path elimination
 * Block '<S11>/Switch' : Unused code path elimination
 * Block '<S8>/Multiply1' : Unused code path elimination
 * Block '<S8>/Multiply2' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<S8>/dt^2' : Unused code path elimination
 * Block '<S12>/And' : Unused code path elimination
 * Block '<S12>/Switch1' : Unused code path elimination
 * Block '<S12>/convert' : Unused code path elimination
 * Block '<S12>/din_d' : Unused code path elimination
 * Block '<S12>/dout_type' : Unused code path elimination
 * Block '<S15>/Compare' : Unused code path elimination
 * Block '<S15>/Constant' : Unused code path elimination
 * Block '<S12>/ram' : Unused code path elimination
 * Block '<S12>/ram_data' : Unused code path elimination
 * Block '<S12>/select' : Unused code path elimination
 * Block '<S12>/switch' : Unused code path elimination
 * Block '<S12>/we_d' : Unused code path elimination
 * Block '<S12>/wr_port' : Unused code path elimination
 * Block '<S13>/And' : Unused code path elimination
 * Block '<S13>/Switch1' : Unused code path elimination
 * Block '<S13>/convert' : Unused code path elimination
 * Block '<S13>/din_d' : Unused code path elimination
 * Block '<S13>/dout_type' : Unused code path elimination
 * Block '<S16>/Compare' : Unused code path elimination
 * Block '<S16>/Constant' : Unused code path elimination
 * Block '<S13>/ram' : Unused code path elimination
 * Block '<S13>/ram_data' : Unused code path elimination
 * Block '<S13>/select' : Unused code path elimination
 * Block '<S13>/switch' : Unused code path elimination
 * Block '<S13>/we_d' : Unused code path elimination
 * Block '<S13>/wr_port' : Unused code path elimination
 * Block '<S14>/And' : Unused code path elimination
 * Block '<S14>/Switch1' : Unused code path elimination
 * Block '<S14>/convert' : Unused code path elimination
 * Block '<S14>/din_d' : Unused code path elimination
 * Block '<S14>/dout_type' : Unused code path elimination
 * Block '<S17>/Compare' : Unused code path elimination
 * Block '<S17>/Constant' : Unused code path elimination
 * Block '<S14>/ram' : Unused code path elimination
 * Block '<S14>/ram_data' : Unused code path elimination
 * Block '<S14>/select' : Unused code path elimination
 * Block '<S14>/switch' : Unused code path elimination
 * Block '<S14>/we_d' : Unused code path elimination
 * Block '<S14>/wr_port' : Unused code path elimination
 * Block '<S9>/Switch' : Unused code path elimination
 * Block '<S10>/Bias' : Unused code path elimination
 * Block '<S10>/Constant2' : Unused code path elimination
 * Block '<S10>/Product' : Unused code path elimination
 * Block '<S10>/Product1' : Unused code path elimination
 * Block '<S10>/Scope' : Unused code path elimination
 * Block '<S10>/Scope1' : Unused code path elimination
 * Block '<S7>/Cast' : Unused code path elimination
 * Block '<S7>/Cast1' : Unused code path elimination
 * Block '<S7>/Cast2' : Unused code path elimination
 * Block '<S7>/Cast4' : Unused code path elimination
 * Block '<S7>/Cast5' : Unused code path elimination
 * Block '<S7>/Cast6' : Unused code path elimination
 * Block '<S7>/Gain3' : Unused code path elimination
 * Block '<S7>/Gain4' : Unused code path elimination
 * Block '<S7>/Gain6' : Unused code path elimination
 * Block '<S7>/Gain7' : Unused code path elimination
 * Block '<S7>/Gain8' : Unused code path elimination
 * Block '<S7>/Gain9' : Unused code path elimination
 * Block '<S4>/Cast' : Unused code path elimination
 * Block '<S4>/Cast1' : Unused code path elimination
 * Block '<S4>/Cast2' : Unused code path elimination
 * Block '<S4>/Cast4' : Unused code path elimination
 * Block '<S4>/Cast5' : Unused code path elimination
 * Block '<S4>/Cast6' : Unused code path elimination
 * Block '<S4>/Gain' : Unused code path elimination
 * Block '<S4>/Gain1' : Unused code path elimination
 * Block '<S4>/Gain2' : Unused code path elimination
 * Block '<S4>/Gain3' : Unused code path elimination
 * Block '<S4>/Gain4' : Unused code path elimination
 * Block '<S4>/Gain6' : Unused code path elimination
 * Block '<S4>/Scope' : Unused code path elimination
 * Block '<S24>/Constant' : Unused code path elimination
 * Block '<S24>/Scope' : Unused code path elimination
 * Block '<S24>/Selector' : Unused code path elimination
 * Block '<S24>/Switch1' : Unused code path elimination
 * Block '<S25>/Counter' : Unused code path elimination
 * Block '<S25>/Delay' : Unused code path elimination
 * Block '<S25>/GreaterThan' : Unused code path elimination
 * Block '<S23>/Display' : Unused code path elimination
 * Block '<S23>/Display1' : Unused code path elimination
 * Block '<S23>/Math Function2' : Unused code path elimination
 * Block '<Root>/AWFG OUT' : Unused code path elimination
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
 * '<Root>' : 'AWFG_Phase2'
 * '<S1>'   : 'AWFG_Phase2/AWFG'
 * '<S2>'   : 'AWFG_Phase2/Model Info'
 * '<S3>'   : 'AWFG_Phase2/AWFG/Dynamic_Calculations'
 * '<S4>'   : 'AWFG_Phase2/AWFG/Signal Scaling  & Casting'
 * '<S5>'   : 'AWFG_Phase2/AWFG/Static Calculations'
 * '<S6>'   : 'AWFG_Phase2/AWFG/Dynamic_Calculations/FPGA_Calculation'
 * '<S7>'   : 'AWFG_Phase2/AWFG/Dynamic_Calculations/Signal Scaling  & Casting'
 * '<S8>'   : 'AWFG_Phase2/AWFG/Dynamic_Calculations/FPGA_Calculation/Polynomial_Calculation'
 * '<S9>'   : 'AWFG_Phase2/AWFG/Dynamic_Calculations/FPGA_Calculation/Subsystem'
 * '<S10>'  : 'AWFG_Phase2/AWFG/Dynamic_Calculations/FPGA_Calculation/TimeGenerator'
 * '<S11>'  : 'AWFG_Phase2/AWFG/Dynamic_Calculations/FPGA_Calculation/Polynomial_Calculation/Difference_Time'
 * '<S12>'  : 'AWFG_Phase2/AWFG/Dynamic_Calculations/FPGA_Calculation/Subsystem/Single Port RAM'
 * '<S13>'  : 'AWFG_Phase2/AWFG/Dynamic_Calculations/FPGA_Calculation/Subsystem/Single Port RAM1'
 * '<S14>'  : 'AWFG_Phase2/AWFG/Dynamic_Calculations/FPGA_Calculation/Subsystem/Single Port RAM2'
 * '<S15>'  : 'AWFG_Phase2/AWFG/Dynamic_Calculations/FPGA_Calculation/Subsystem/Single Port RAM/is_new'
 * '<S16>'  : 'AWFG_Phase2/AWFG/Dynamic_Calculations/FPGA_Calculation/Subsystem/Single Port RAM1/is_new'
 * '<S17>'  : 'AWFG_Phase2/AWFG/Dynamic_Calculations/FPGA_Calculation/Subsystem/Single Port RAM2/is_new'
 * '<S18>'  : 'AWFG_Phase2/AWFG/Dynamic_Calculations/FPGA_Calculation/TimeGenerator/Bit Slice'
 * '<S19>'  : 'AWFG_Phase2/AWFG/Dynamic_Calculations/FPGA_Calculation/TimeGenerator/Bit Slice/bit_slice'
 * '<S20>'  : 'AWFG_Phase2/AWFG/Static Calculations/Coefficient Sequencer'
 * '<S21>'  : 'AWFG_Phase2/AWFG/Static Calculations/DETECT CHANGE'
 * '<S22>'  : 'AWFG_Phase2/AWFG/Static Calculations/RT_CPU'
 * '<S23>'  : 'AWFG_Phase2/AWFG/Static Calculations/precalculations'
 * '<S24>'  : 'AWFG_Phase2/AWFG/Static Calculations/Coefficient Sequencer/Coefficient Selector'
 * '<S25>'  : 'AWFG_Phase2/AWFG/Static Calculations/Coefficient Sequencer/Counter'
 * '<S26>'  : 'AWFG_Phase2/AWFG/Static Calculations/DETECT CHANGE/Detect Change'
 * '<S27>'  : 'AWFG_Phase2/AWFG/Static Calculations/DETECT CHANGE/Detect Change1'
 * '<S28>'  : 'AWFG_Phase2/AWFG/Static Calculations/DETECT CHANGE/Detect Change2'
 * '<S29>'  : 'AWFG_Phase2/AWFG/Static Calculations/DETECT CHANGE/Detect Change3'
 * '<S30>'  : 'AWFG_Phase2/AWFG/Static Calculations/DETECT CHANGE/Detect Change4'
 * '<S31>'  : 'AWFG_Phase2/AWFG/Static Calculations/DETECT CHANGE/Detect Change5'
 */
#endif                                 /* RTW_HEADER_AWFG_Phase2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
