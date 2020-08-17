/*
 * RT_CPU_sf.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "RT_CPU_sf".
 *
 * Model version              : 1.454
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Mon Aug 27 22:14:09 2018
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_RT_CPU_sf_h_
#define RTW_HEADER_RT_CPU_sf_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef RT_CPU_sf_COMMON_INCLUDES_
# define RT_CPU_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                RT_CPU_sf
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if !defined(MATLAB_MEX_FILE)
#include "rt_matrx.h"
#endif

#if !defined(RTW_SFUNCTION_DEFINES)
#define RTW_SFUNCTION_DEFINES

typedef struct {
  void *blockIO;
  void *defaultParam;
  void *nonContDerivSig;
} LocalS;

#define ssSetLocalBlockIO(S, io)       ((LocalS *)ssGetUserData(S))->blockIO = ((void *)(io))
#define ssGetLocalBlockIO(S)           ((LocalS *)ssGetUserData(S))->blockIO
#define ssSetLocalDefaultParam(S, paramVector) ((LocalS *)ssGetUserData(S))->defaultParam = (paramVector)
#define ssGetLocalDefaultParam(S)      ((LocalS *)ssGetUserData(S))->defaultParam
#define ssSetLocalNonContDerivSig(S, pSig) ((LocalS *)ssGetUserData(S))->nonContDerivSig = (pSig)
#define ssGetLocalNonContDerivSig(S)   ((LocalS *)ssGetUserData(S))->nonContDerivSig
#endif
#endif                                 /* RT_CPU_sf_COMMON_INCLUDES_ */

#include "RT_CPU_sf_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rt_defines.h"

/* External inputs (root inport signals with default storage) */
typedef struct {
  boolean_T *ch;                       /* '<Root>/ch' */
  real32_T *A;                         /* '<Root>/A' */
  real32_T *mode;                      /* '<Root>/mode' */
  real32_T *DutyCycle;                 /* '<Root>/dutyCycle' */
  real32_T *Breakpoints;               /* '<Root>/breakPoints' */
  real32_T *pOrder;                    /* '<Root>/pOrder' */
  real32_T *f;                         /* '<Root>/f' */
} ExternalUPtrs_RT_CPU_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T *cc[1024];                  /* '<Root>/cc' */
  real32_T *b[255];                    /* '<Root>/b' */
} ExtY_RT_CPU_T;

/* External output sizes (for root outports fed by signals with variable sizes) */
typedef struct {
  int32_T cc[2];                       /* '<Root>/cc' */
  int32_T b[2];                        /* '<Root>/b' */
} ExtYSize_RT_CPU_T;

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
#endif                                 /* RTW_HEADER_RT_CPU_sf_h_ */
