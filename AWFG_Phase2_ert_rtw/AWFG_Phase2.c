/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AWFG_Phase2.c
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

#include "AWFG_Phase2.h"
#define NumBitsPerChar                 8U
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

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */

/* Block signals and states (default storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Forward declaration for local functions */
static void linspace(real32_T n1, real_T y_data[], int32_T y_size[2]);
static void sin_h(real32_T x_data[], int32_T x_size[2]);
static void factorial(real32_T *n);
extern real_T rtGetInf(void);
extern real32_T rtGetInfF(void);
extern real_T rtGetMinusInf(void);
extern real32_T rtGetMinusInfF(void);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
extern void rt_InitInfAndNaN(size_t realSize);
extern boolean_T rtIsInf(real_T value);
extern boolean_T rtIsInfF(real32_T value);
extern boolean_T rtIsNaN(real_T value);
extern boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
extern real_T rtGetNaN(void);
extern real32_T rtGetNaNF(void);

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
boolean_T rtIsNaN(real_T value)
{
  return (boolean_T)((value!=value) ? 1U : 0U);
}

/* Test if single-precision value is not a number */
boolean_T rtIsNaNF(real32_T value)
{
  return (boolean_T)(((value!=value) ? 1U : 0U));
}

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0 } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/* Function for MATLAB Function: '<S5>/RT_CPU' */
static void linspace(real32_T n1, real_T y_data[], int32_T y_size[2])
{
  real_T delta1;
  int32_T k;
  if (n1 < 0.0F) {
    n1 = 0.0F;
  }

  y_size[0] = 1;
  y_size[1] = (int32_T)(real32_T)floor(n1);
  if (y_size[1] >= 1) {
    y_data[y_size[1] - 1] = 1.0;
    if (y_size[1] >= 2) {
      y_data[0] = 0.0;
      if (y_size[1] >= 3) {
        delta1 = 1.0 / ((real_T)y_size[1] - 1.0);
        for (k = 0; k <= y_size[1] - 3; k++) {
          y_data[k + 1] = (1.0 + (real_T)k) * delta1;
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S5>/RT_CPU' */
static void sin_h(real32_T x_data[], int32_T x_size[2])
{
  int32_T k;
  for (k = 0; k < x_size[1]; k++) {
    x_data[k] = (real32_T)sin(x_data[k]);
  }
}

/* Function for MATLAB Function: '<S5>/RT_CPU' */
static void factorial(real32_T *n)
{
  static const real32_T b[34] = { 1.0F, 2.0F, 6.0F, 24.0F, 120.0F, 720.0F,
    5040.0F, 40320.0F, 362880.0F, 3.6288E+6F, 3.99168E+7F, 4.790016E+8F,
    6.2270208E+9F, 8.71782892E+10F, 1.30767428E+12F, 2.09227885E+13F,
    3.55687415E+14F, 6.40237353E+15F, 1.21645096E+17F, 2.43290202E+18F,
    5.10909408E+19F, 1.12400072E+21F, 2.58520174E+22F, 6.20448455E+23F,
    1.55112111E+25F, 4.032915E+26F, 1.08888704E+28F, 3.04888372E+29F,
    8.84176308E+30F, 2.6525289E+32F, 8.22283969E+33F, 2.6313087E+35F,
    8.68331851E+36F, 2.95232823E+38F };

  if (!((real32_T)floor(*n) != *n)) {
    if (*n > 34.0F) {
      *n = (rtInfF);
    } else if (*n < 1.0F) {
      *n = 1.0F;
    } else {
      *n = b[(int32_T)*n - 1];
    }
  }
}

/* Model step function */
void AWFG_Phase2_step(void)
{
  real32_T b_y;
  int32_T loop_ub;
  int32_T x_size[2];
  int32_T tmp_size[2];
  int32_T y_size_idx_1;

  /* MATLAB Function: '<S5>/RT_CPU' incorporates:
   *  Constant: '<Root>/Amplitude'
   *  Constant: '<Root>/Breakpoints'
   *  Constant: '<Root>/Duty Cycle'
   *  Constant: '<Root>/Freq_in_Hz'
   *  Constant: '<Root>/Mode'
   *  Constant: '<Root>/pOrder'
   *  Logic: '<S21>/OR'
   *  RelationalOperator: '<S26>/FixPt Relational Operator'
   *  RelationalOperator: '<S27>/FixPt Relational Operator'
   *  RelationalOperator: '<S28>/FixPt Relational Operator'
   *  RelationalOperator: '<S29>/FixPt Relational Operator'
   *  RelationalOperator: '<S30>/FixPt Relational Operator'
   *  RelationalOperator: '<S31>/FixPt Relational Operator'
   *  UnitDelay: '<S26>/Delay Input1'
   *  UnitDelay: '<S27>/Delay Input1'
   *  UnitDelay: '<S28>/Delay Input1'
   *  UnitDelay: '<S29>/Delay Input1'
   *  UnitDelay: '<S30>/Delay Input1'
   *  UnitDelay: '<S31>/Delay Input1'
   *
   * Block description for '<S26>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S27>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S28>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S29>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S30>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S31>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (!rtDW.cc0_not_empty) {
    rtDW.cc0.size[0] = 101;
    rtDW.cc0.size[1] = 3;
    memset(&rtDW.cc0.data[0], 0, 303U * sizeof(real32_T));
    rtDW.cc0_not_empty = true;
    rtDW.b0.size[0] = 1;
    rtDW.b0.size[1] = 101;
    memset(&rtDW.b0.data[0], 0, 101U * sizeof(real32_T));
    rtDW.i0 = 0.0F;
  }

  if ((1.0F != rtDW.DelayInput1_DSTATE) || (1000.0F != rtDW.DelayInput1_DSTATE_e)
      || (0.0F != rtDW.DelayInput1_DSTATE_d) || (0.5F !=
       rtDW.DelayInput1_DSTATE_a) || (128.0F != rtDW.DelayInput1_DSTATE_j) ||
      (0.0F != rtDW.DelayInput1_DSTATE_b) || (rtDW.i0 < 1.0F)) {
    rtDW.i0 = 1.0F;
    rtDW.SFunction_DIMS2[0] = 129;
    rtDW.SFunction_DIMS2[1] = 3;
    memset(&rtDW.cc[0], 0, 387U * sizeof(real32_T));
    rtDW.b0.size[0] = 1;
    rtDW.b0.size[1] = 129;
    memset(&rtDW.b0.data[0], 0, 129U * sizeof(real32_T));
    linspace(129.0F, rtDW.tmp_data, tmp_size);
    x_size[1] = tmp_size[1];
    loop_ub = tmp_size[0] * tmp_size[1];
    for (y_size_idx_1 = 0; y_size_idx_1 < loop_ub; y_size_idx_1++) {
      rtDW.x_data[y_size_idx_1] = (real32_T)rtDW.tmp_data[y_size_idx_1];
    }

    x_size[0] = 1;
    loop_ub = tmp_size[1] - 1;
    for (y_size_idx_1 = 0; y_size_idx_1 <= loop_ub; y_size_idx_1++) {
      rtDW.x_data[y_size_idx_1] *= 6.28318548F;
    }

    sin_h(rtDW.x_data, x_size);
    y_size_idx_1 = x_size[1];
    loop_ub = x_size[0] * x_size[1] - 1;
    if (0 <= loop_ub) {
      memcpy(&rtDW.y_data[0], &rtDW.x_data[0], (loop_ub + 1) * sizeof(real32_T));
    }

    if (0 <= y_size_idx_1 - 1) {
      memcpy(&rtDW.yy_data[0], &rtDW.y_data[0], y_size_idx_1 * sizeof(real32_T));
    }

    rtDW.yy_data[x_size[1]] = rtDW.y_data[1];
    rtDW.yy_data[1 + x_size[1]] = rtDW.y_data[2];
    rtDW.yy_data[2 + x_size[1]] = rtDW.y_data[3];
    for (loop_ub = 0; loop_ub < 129; loop_ub++) {
      rtDW.b0.data[rtDW.b0.size[0] * loop_ub] = (real32_T)loop_ub * 0.001F /
        128.0F;
      b_y = 0.0F;
      factorial(&b_y);
      rtDW.cc[loop_ub] = (((rtDW.yy_data[loop_ub + 1] * 0.0F +
                            rtDW.yy_data[loop_ub]) + rtDW.yy_data[loop_ub + 2] *
                           0.0F) + rtDW.yy_data[loop_ub + 3] * 0.0F) / b_y;
    }

    rtDW.cc0.size[0] = rtDW.SFunction_DIMS2[0];
    rtDW.cc0.size[1] = rtDW.SFunction_DIMS2[1];
    loop_ub = rtDW.SFunction_DIMS2[0] * rtDW.SFunction_DIMS2[1] - 1;
    if (0 <= loop_ub) {
      memcpy(&rtDW.cc0.data[0], &rtDW.cc[0], (loop_ub + 1) * sizeof(real32_T));
    }

    rtDW.cc0_not_empty = !(rtDW.cc0.size[0] == 0);
  } else {
    rtDW.SFunction_DIMS2[0] = rtDW.cc0.size[0];
    rtDW.SFunction_DIMS2[1] = rtDW.cc0.size[1];
  }

  rtDW.SFunction_DIMS3[0] = rtDW.b0.size[0];
  rtDW.SFunction_DIMS3[1] = rtDW.b0.size[1];

  /* End of MATLAB Function: '<S5>/RT_CPU' */

  /* DiscretePulseGenerator: '<S5>/Trigger' */
  if (rtDW.clockTickCounter >= 1) {
    rtDW.clockTickCounter = 0;
  } else {
    rtDW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S5>/Trigger' */

  /* DataTypeConversion: '<S10>/Cast' incorporates:
   *  DataTypeConversion: '<S4>/Cast3'
   *  DataTypeConversion: '<S7>/Cast3'
   *  Delay: '<S10>/Delay'
   *  Gain: '<S4>/Gain5'
   *  Gain: '<S7>/Gain5'
   *  Product: '<S23>/f_in_fclk1'
   *  Sum: '<S10>/Add1'
   */
  y_size_idx_1 = (int32_T)((rtDW.Delay_DSTATE + 1336) & 67108863U);

  /* Update for Delay: '<S10>/Delay' incorporates:
   *  DataTypeConversion: '<S10>/Cast'
   */
  rtDW.Delay_DSTATE = (y_size_idx_1 & 67108864U) != 0U ? y_size_idx_1 |
    -67108864 : y_size_idx_1;

  /* Update for UnitDelay: '<S26>/Delay Input1' incorporates:
   *  Constant: '<Root>/Amplitude'
   *
   * Block description for '<S26>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtDW.DelayInput1_DSTATE = 1.0F;

  /* Update for UnitDelay: '<S27>/Delay Input1' incorporates:
   *  Constant: '<Root>/Freq_in_Hz'
   *
   * Block description for '<S27>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtDW.DelayInput1_DSTATE_e = 1000.0F;

  /* Update for UnitDelay: '<S28>/Delay Input1' incorporates:
   *  Constant: '<Root>/Mode'
   *
   * Block description for '<S28>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtDW.DelayInput1_DSTATE_d = 0.0F;

  /* Update for UnitDelay: '<S29>/Delay Input1' incorporates:
   *  Constant: '<Root>/Duty Cycle'
   *
   * Block description for '<S29>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtDW.DelayInput1_DSTATE_a = 0.5F;

  /* Update for UnitDelay: '<S30>/Delay Input1' incorporates:
   *  Constant: '<Root>/Breakpoints'
   *
   * Block description for '<S30>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtDW.DelayInput1_DSTATE_j = 128.0F;

  /* Update for UnitDelay: '<S31>/Delay Input1' incorporates:
   *  Constant: '<Root>/pOrder'
   *
   * Block description for '<S31>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtDW.DelayInput1_DSTATE_b = 0.0F;
}

/* Model initialize function */
void AWFG_Phase2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtPrevZCX.CoefficientSequencer_Trig_ZCE = UNINITIALIZED_ZCSIG;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
