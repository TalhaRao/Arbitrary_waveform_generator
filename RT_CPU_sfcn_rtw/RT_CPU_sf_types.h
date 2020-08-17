/*
 * RT_CPU_sf_types.h
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

#ifndef RTW_HEADER_RT_CPU_sf_types_h_
#define RTW_HEADER_RT_CPU_sf_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Custom Type definition for MATLAB Function: '<Root>/RT_CPU' */
#ifndef struct_emxArray_real32_T_256x3
#define struct_emxArray_real32_T_256x3

struct emxArray_real32_T_256x3
{
  real32_T data[768];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real32_T_256x3*/

#ifndef typedef_emxArray_real32_T_256x3_RT_CP_T
#define typedef_emxArray_real32_T_256x3_RT_CP_T

typedef struct emxArray_real32_T_256x3 emxArray_real32_T_256x3_RT_CP_T;

#endif                                 /*typedef_emxArray_real32_T_256x3_RT_CP_T*/

#ifndef struct_emxArray_real32_T_1x255
#define struct_emxArray_real32_T_1x255

struct emxArray_real32_T_1x255
{
  real32_T data[255];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real32_T_1x255*/

#ifndef typedef_emxArray_real32_T_1x255_RT_CP_T
#define typedef_emxArray_real32_T_1x255_RT_CP_T

typedef struct emxArray_real32_T_1x255 emxArray_real32_T_1x255_RT_CP_T;

#endif                                 /*typedef_emxArray_real32_T_1x255_RT_CP_T*/
#endif                                 /* RTW_HEADER_RT_CPU_sf_types_h_ */
