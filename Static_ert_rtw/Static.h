/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Static.h
 *
 * Code generated for Simulink model 'Static'.
 *
 * Model version                  : 1.497
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Tue Aug 28 21:39:41 2018
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

#ifndef RTW_HEADER_Static_h_
#define RTW_HEADER_Static_h_
#include <stddef.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Static_COMMON_INCLUDES_
# define Static_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* Static_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#define Static_M                       (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Custom Type definition for MATLAB Function: '<S1>/RT_CPU' */
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
  emxArray_real32_T_256x3 cc0;         /* '<S1>/RT_CPU' */
  emxArray_real32_T_1x255 b0;          /* '<S1>/RT_CPU' */
  real_T tmp_data[257];
  real32_T Switch1[3];                 /* '<S6>/Switch1' */
  real32_T cc[1024];                   /* '<S1>/RT_CPU' */
  real32_T yy_data[261];
  real32_T y_data[259];
  real32_T y_data_m[258];
  real32_T x_data[257];
  real32_T x1_data[256];
  real32_T DelayInput1_DSTATE;         /* '<S8>/Delay Input1' */
  real32_T DelayInput1_DSTATE_e;       /* '<S9>/Delay Input1' */
  real32_T DelayInput1_DSTATE_d;       /* '<S10>/Delay Input1' */
  real32_T DelayInput1_DSTATE_a;       /* '<S11>/Delay Input1' */
  real32_T DelayInput1_DSTATE_j;       /* '<S12>/Delay Input1' */
  real32_T DelayInput1_DSTATE_b;       /* '<S13>/Delay Input1' */
  real32_T i0;                         /* '<S1>/RT_CPU' */
  int32_T SFunction_DIMS2[2];          /* '<S1>/RT_CPU' */
  int32_T SFunction_DIMS3[2];          /* '<S1>/RT_CPU' */
  int32_T x_size[2];
  int32_T tmp_size[2];
  int32_T clockTickCounter;            /* '<S1>/Trigger' */
  uint8_T Counter_Count;               /* '<S7>/Counter' */
  boolean_T cc0_not_empty;             /* '<S1>/RT_CPU' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState CoefficientSequencer_Trig_ZCE;/* '<S1>/Coefficient Sequencer' */
} PrevZCX;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T A;                          /* '<Root>/A' */
  real32_T mode;                       /* '<Root>/mode' */
  real32_T DutyCycle;                  /* '<Root>/dutyCycle' */
  real32_T Breakpoints;                /* '<Root>/breakPoints' */
  real32_T pOrder;                     /* '<Root>/pOrder' */
  real32_T f;                          /* '<Root>/f' */
  real_T fclk;                         /* '<Root>/f-clk' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T c0;                         /* '<Root>/c0' */
  real32_T c1;                         /* '<Root>/c1' */
  real32_T c2;                         /* '<Root>/c2' */
  boolean_T write;                     /* '<Root>/write' */
  real32_T writeAddr;                  /* '<Root>/writeAddr' */
  real_T M;                            /* '<Root>/M' */
  real32_T T;                          /* '<Root>/T' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void Static_initialize(void);
extern void Static_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Scope' : Unused code path elimination
 * Block '<S5>/Display' : Unused code path elimination
 * Block '<S5>/Display1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('AWFG_Phase2/AWFG/Static Calculations')    - opens subsystem AWFG_Phase2/AWFG/Static Calculations
 * hilite_system('AWFG_Phase2/AWFG/Static Calculations/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'AWFG_Phase2/AWFG'
 * '<S1>'   : 'AWFG_Phase2/AWFG/Static Calculations'
 * '<S2>'   : 'AWFG_Phase2/AWFG/Static Calculations/Coefficient Sequencer'
 * '<S3>'   : 'AWFG_Phase2/AWFG/Static Calculations/DETECT CHANGE'
 * '<S4>'   : 'AWFG_Phase2/AWFG/Static Calculations/RT_CPU'
 * '<S5>'   : 'AWFG_Phase2/AWFG/Static Calculations/precalculations'
 * '<S6>'   : 'AWFG_Phase2/AWFG/Static Calculations/Coefficient Sequencer/Coefficient Selector'
 * '<S7>'   : 'AWFG_Phase2/AWFG/Static Calculations/Coefficient Sequencer/Counter'
 * '<S8>'   : 'AWFG_Phase2/AWFG/Static Calculations/DETECT CHANGE/Detect Change'
 * '<S9>'   : 'AWFG_Phase2/AWFG/Static Calculations/DETECT CHANGE/Detect Change1'
 * '<S10>'  : 'AWFG_Phase2/AWFG/Static Calculations/DETECT CHANGE/Detect Change2'
 * '<S11>'  : 'AWFG_Phase2/AWFG/Static Calculations/DETECT CHANGE/Detect Change3'
 * '<S12>'  : 'AWFG_Phase2/AWFG/Static Calculations/DETECT CHANGE/Detect Change4'
 * '<S13>'  : 'AWFG_Phase2/AWFG/Static Calculations/DETECT CHANGE/Detect Change5'
 */
#endif                                 /* RTW_HEADER_Static_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
