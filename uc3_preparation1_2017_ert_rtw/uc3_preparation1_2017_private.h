/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: uc3_preparation1_2017_private.h
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

#ifndef RTW_HEADER_uc3_preparation1_2017_private_h_
#define RTW_HEADER_uc3_preparation1_2017_private_h_
#include "rtwtypes.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Imported (extern) pointer block signals */
extern int32_T *tune1;                 /* '<Root>/Amplitude' */
extern int32_T *share_in3;             /* '<S13>/Data Type Conversion3' */
extern int32_T *probe3;                /* '<S4>/Data Type Conversion3' */
extern int32_T *probe4;                /* '<S4>/Data Type Conversion' */
extern int32_T *share_out1;            /* '<S4>/Data Type Conversion2' */
extern int32_T *tune3;                 /* '<Root>/Mode' */
extern int32_T *tune2;                 /* '<Root>/Freq_in_Hz' */
extern int32_T *tune4;                 /* '<Root>/duty' */
extern int32_T *tune5;                 /* '<Root>/Polynomial' */
extern int32_T *share_out5;            /* '<S5>/Data Type Conversion2' */
extern int32_T *share_out8;            /* '<S5>/Data Type Conversion4' */
extern int32_T *share_out7;            /* '<S8>/Data Type Conversion1' */
extern int32_T *share_out6;            /* '<S8>/Data Type Conversion2' */
extern int32_T *share_out2;            /* '<S9>/Data Type Conversion' */
extern int32_T *share_out3;            /* '<S9>/Data Type Conversion1' */
extern int32_T *share_out4;            /* '<S9>/Data Type Conversion2' */
extern real32_T rt_powf_snf(real32_T u0, real32_T u1);
extern void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
extern int32_T mul_s32_loSR(int32_T a, int32_T b, uint32_T aShift);

#endif                                 /* RTW_HEADER_uc3_preparation1_2017_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
