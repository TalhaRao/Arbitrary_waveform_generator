/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: RT_CPU.h
 *
 * Code generated for Simulink model 'RT_CPU'.
 *
 * Model version                  : 1.454
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Mon Aug 27 22:08:45 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_RT_CPU_h_
#define RTW_HEADER_RT_CPU_h_
#include <stddef.h>
#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#ifndef RT_CPU_COMMON_INCLUDES_
# define RT_CPU_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* RT_CPU_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Custom Type definition for MATLAB Function: '<Root>/RT_CPU' */
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
  emxArray_real32_T_256x3 cc0;         /* '<Root>/RT_CPU' */
  emxArray_real32_T_1x255 b0;          /* '<Root>/RT_CPU' */
  real32_T i0;                         /* '<Root>/RT_CPU' */
  int32_T SFunction_DIMS2[2];          /* '<Root>/RT_CPU' */
  int32_T SFunction_DIMS3[2];          /* '<Root>/RT_CPU' */
  boolean_T cc0_not_empty;             /* '<Root>/RT_CPU' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  boolean_T ch;                        /* '<Root>/ch' */
  real32_T A;                          /* '<Root>/A' */
  real32_T mode;                       /* '<Root>/mode' */
  real32_T DutyCycle;                  /* '<Root>/dutyCycle' */
  real32_T Breakpoints;                /* '<Root>/breakPoints' */
  real32_T pOrder;                     /* '<Root>/pOrder' */
  real32_T f;                          /* '<Root>/f' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T cc[1024];                   /* '<Root>/cc' */
  real32_T b[255];                     /* '<Root>/b' */
} ExtY;

/* External output sizes (for root outports fed by signals with variable sizes) */
typedef struct {
  int32_T cc[2];                       /* '<Root>/cc' */
  int32_T b[2];                        /* '<Root>/b' */
} ExtYSize;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* External outputs size (variable-sizing root outport signals with default storage) */
extern ExtYSize rtYSize;

/* Model entry point functions */
extern void RT_CPU_initialize(void);
extern void RT_CPU_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

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
 * hilite_system('AWFG_Phase2_SIL/AWFG/Static Calculations/RT_CPU')    - opens subsystem AWFG_Phase2_SIL/AWFG/Static Calculations/RT_CPU
 * hilite_system('AWFG_Phase2_SIL/AWFG/Static Calculations/RT_CPU/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'AWFG_Phase2_SIL/AWFG/Static Calculations'
 * '<S1>'   : 'AWFG_Phase2_SIL/AWFG/Static Calculations/RT_CPU'
 */
#endif                                 /* RTW_HEADER_RT_CPU_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
