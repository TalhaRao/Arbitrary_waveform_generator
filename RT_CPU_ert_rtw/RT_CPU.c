/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: RT_CPU.c
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

#include "RT_CPU.h"
#define NumBitsPerChar                 8U

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* External output sizes (root outports fed by signals with variable sizes) */
ExtYSize rtYSize;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real32_T rt_powf_snf(real32_T u0, real32_T u1);

/* Forward declaration for local functions */
static void linspace(real32_T n1, real_T y_data[], int32_T y_size[2]);
static void sin_h(real32_T x_data[], int32_T x_size[2]);
static void factorial(real32_T *n);
extern real_T rtGetInf(void);
extern real32_T rtGetInfF(void);
extern real_T rtGetMinusInf(void);
extern real32_T rtGetMinusInfF(void);
extern real_T rtGetNaN(void);
extern real32_T rtGetNaNF(void);
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

/* Function for MATLAB Function: '<Root>/RT_CPU' */
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

/* Function for MATLAB Function: '<Root>/RT_CPU' */
static void sin_h(real32_T x_data[], int32_T x_size[2])
{
  int32_T k;
  for (k = 0; k < x_size[1]; k++) {
    x_data[k] = (real32_T)sin(x_data[k]);
  }
}

/* Function for MATLAB Function: '<Root>/RT_CPU' */
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

real32_T rt_powf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  real32_T tmp;
  real32_T tmp_0;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else {
    tmp = (real32_T)fabs(u0);
    tmp_0 = (real32_T)fabs(u1);
    if (rtIsInfF(u1)) {
      if (tmp == 1.0F) {
        y = 1.0F;
      } else if (tmp > 1.0F) {
        if (u1 > 0.0F) {
          y = (rtInfF);
        } else {
          y = 0.0F;
        }
      } else if (u1 > 0.0F) {
        y = 0.0F;
      } else {
        y = (rtInfF);
      }
    } else if (tmp_0 == 0.0F) {
      y = 1.0F;
    } else if (tmp_0 == 1.0F) {
      if (u1 > 0.0F) {
        y = u0;
      } else {
        y = 1.0F / u0;
      }
    } else if (u1 == 2.0F) {
      y = u0 * u0;
    } else if ((u1 == 0.5F) && (u0 >= 0.0F)) {
      y = (real32_T)sqrt(u0);
    } else if ((u0 < 0.0F) && (u1 > (real32_T)floor(u1))) {
      y = (rtNaNF);
    } else {
      y = (real32_T)pow(u0, u1);
    }
  }

  return y;
}

/* Model step function */
void RT_CPU_step(void)
{
  real32_T tf;
  real32_T y_data[258];
  real32_T x_data[257];
  real32_T x1_data[256];
  real32_T yy_data[261];
  real32_T b_y;
  real32_T c_y;
  static const int8_T cfd[16] = { 1, -1, 1, -1, 0, 1, -2, 3, 0, 0, 1, -3, 0, 0,
    0, 1 };

  real32_T rtb_cc[1024];
  real32_T rtb_b[255];
  real_T tmp_data[257];
  int32_T loop_ub;
  int32_T i;
  real32_T y_data_0[259];
  int32_T i_0;
  int32_T x_size[2];
  int32_T tmp_size[2];
  int32_T tmp_size_0[2];
  int32_T x1_size_idx_1;
  int32_T y_size_idx_1;
  int32_T loop_ub_tmp;

  /* MATLAB Function: '<Root>/RT_CPU' incorporates:
   *  Inport: '<Root>/A'
   *  Inport: '<Root>/breakPoints'
   *  Inport: '<Root>/ch'
   *  Inport: '<Root>/dutyCycle'
   *  Inport: '<Root>/f'
   *  Inport: '<Root>/mode'
   *  Inport: '<Root>/pOrder'
   */
  /* MATLAB Function 'RT_CPU': '<S1>:1' */
  /* '<S1>:1:65' */
  /* '<S1>:1:77' */
  if (!rtDW.cc0_not_empty) {
    /* '<S1>:1:15' */
    /* '<S1>:1:16' */
    rtDW.cc0.size[0] = 101;
    rtDW.cc0.size[1] = 3;
    memset(&rtDW.cc0.data[0], 0, 303U * sizeof(real32_T));
    rtDW.cc0_not_empty = true;

    /* '<S1>:1:17' */
    rtDW.b0.size[0] = 1;
    rtDW.b0.size[1] = 101;
    memset(&rtDW.b0.data[0], 0, 101U * sizeof(real32_T));

    /* '<S1>:1:18' */
    rtDW.i0 = 0.0F;
  }

  if (rtU.ch || (rtDW.i0 < 1.0F)) {
    /* '<S1>:1:20' */
    /* '<S1>:1:22' */
    rtDW.i0 = 1.0F;

    /* '<S1>:1:28' */
    rtDW.SFunction_DIMS2[0] = (int32_T)(rtU.Breakpoints + 1.0F);
    rtDW.SFunction_DIMS2[1] = 3;
    loop_ub = (int32_T)(rtU.Breakpoints + 1.0F) * 3;
    if (0 <= loop_ub - 1) {
      memset(&rtb_cc[0], 0, loop_ub * sizeof(real32_T));
    }

    /* '<S1>:1:29' */
    rtDW.b0.size[0] = 1;
    rtDW.b0.size[1] = (int32_T)(rtU.Breakpoints + 1.0F);
    loop_ub_tmp = (int32_T)(rtU.Breakpoints + 1.0F) - 1;
    if (0 <= loop_ub_tmp) {
      memset(&rtDW.b0.data[0], 0, (loop_ub_tmp + 1) * sizeof(real32_T));
    }

    /* '<S1>:1:30' */
    tf = 1.0F / rtU.f;

    /* '<S1>:1:32' */
    linspace(rtU.Breakpoints + 1.0F, tmp_data, tmp_size_0);
    x_size[1] = tmp_size_0[1];
    loop_ub = tmp_size_0[0] * tmp_size_0[1];
    for (i = 0; i < loop_ub; i++) {
      x_data[i] = (real32_T)tmp_data[i];
    }

    /* '<S1>:1:33' */
    linspace(rtU.Breakpoints, tmp_data, tmp_size);
    x1_size_idx_1 = tmp_size[1];
    loop_ub = tmp_size[0] * tmp_size[1];
    for (i = 0; i < loop_ub; i++) {
      x1_data[i] = (real32_T)tmp_data[i];
    }

    switch ((int32_T)rtU.mode) {
     case 0:
      /* '<S1>:1:38' */
      x_size[0] = 1;
      loop_ub = tmp_size_0[1] - 1;
      for (i = 0; i <= loop_ub; i++) {
        x_data[i] *= 6.28318548F;
      }

      sin_h(x_data, x_size);
      y_size_idx_1 = x_size[1];
      loop_ub = x_size[0] * x_size[1] - 1;
      for (i = 0; i <= loop_ub; i++) {
        y_data[i] = rtU.A * x_data[i];
      }
      break;

     case 1:
      /* '<S1>:1:42' */
      y_size_idx_1 = tmp_size_0[1];
      loop_ub = tmp_size_0[1] - 1;
      for (i = 0; i <= loop_ub; i++) {
        y_data[i] = (real32_T)(x_data[i] < rtU.DutyCycle) * rtU.A + (real32_T)
          (x_data[i] >= rtU.DutyCycle) * -rtU.A;
      }

      /* '<S1>:1:43' */
      y_data[loop_ub_tmp] = rtU.A;
      break;

     case 2:
      if ((rtU.DutyCycle == 0.0F) || (rtU.DutyCycle == 1.0F)) {
        /* '<S1>:1:47' */
        /* '<S1>:1:49' */
        loop_ub = tmp_size[1] - 1;
        i = (rtU.DutyCycle == 1.0F);
        y_size_idx_1 = (rtU.DutyCycle == 0.0F);
        for (i_0 = 0; i_0 <= loop_ub; i_0++) {
          y_data[i_0] = ((1.0F - x1_data[i_0]) * rtU.A * 2.0F + -rtU.A) *
            (real32_T)y_size_idx_1 + (x1_data[i_0] * rtU.A * 2.0F + -rtU.A) *
            (real32_T)i;
        }

        /* '<S1>:1:51' */
        y_size_idx_1 = tmp_size[1] + 1;
        if (0 <= x1_size_idx_1 - 1) {
          memcpy(&y_data_0[0], &y_data[0], x1_size_idx_1 * sizeof(real32_T));
        }

        y_data_0[tmp_size[1]] = y_data[0];
        if (0 <= y_size_idx_1 - 1) {
          memcpy(&y_data[0], &y_data_0[0], y_size_idx_1 * sizeof(real32_T));
        }
      } else {
        b_y = 2.0F / rtU.DutyCycle;
        c_y = 2.0F / (1.0F - rtU.DutyCycle);

        /* '<S1>:1:54' */
        y_size_idx_1 = tmp_size_0[1];
        loop_ub = tmp_size_0[1] - 1;
        for (i = 0; i <= loop_ub; i++) {
          y_data[i] = ((1.0F - x_data[i]) * rtU.A * c_y + -rtU.A) * (real32_T)
            (x_data[i] > rtU.DutyCycle) + (x_data[i] * rtU.A * b_y + -rtU.A) *
            (real32_T)(x_data[i] <= rtU.DutyCycle);
        }
      }
      break;

     default:
      /* '<S1>:1:60' */
      y_size_idx_1 = 1;
      y_data[0] = 0.0F;
      break;
    }

    /* '<S1>:1:65' */
    /* '<S1>:1:71' */
    if (0 <= y_size_idx_1 - 1) {
      memcpy(&yy_data[0], &y_data[0], y_size_idx_1 * sizeof(real32_T));
    }

    yy_data[y_size_idx_1] = y_data[1];
    yy_data[1 + y_size_idx_1] = y_data[2];
    yy_data[2 + y_size_idx_1] = y_data[3];

    /* '<S1>:1:73' */
    for (loop_ub = 0; loop_ub <= loop_ub_tmp; loop_ub++) {
      /* '<S1>:1:73' */
      /* '<S1>:1:74' */
      i = (int32_T)((real32_T)loop_ub + 1.0F);
      y_size_idx_1 = i - 1;
      rtDW.b0.data[rtDW.b0.size[0] * y_size_idx_1] = (real32_T)loop_ub * tf /
        rtU.Breakpoints;

      /* '<S1>:1:75' */
      /* '<S1>:1:76' */
      for (x1_size_idx_1 = 0; x1_size_idx_1 < (int32_T)(rtU.pOrder + 1.0F);
           x1_size_idx_1++) {
        /* '<S1>:1:76' */
        /* '<S1>:1:77' */
        /* '<S1>:1:78' */
        b_y = (real32_T)x1_size_idx_1;
        factorial(&b_y);
        i_0 = (int32_T)((real32_T)x1_size_idx_1 + 1.0F);
        rtb_cc[(i + rtDW.SFunction_DIMS2[0] * ((int32_T)((real32_T)x1_size_idx_1
                  + 1.0F) - 1)) - 1] = (((yy_data[y_size_idx_1] * (real32_T)
          cfd[i_0 - 1] + yy_data[(int32_T)((real32_T)loop_ub + 2.0F) - 1] *
          (real32_T)cfd[i_0 + 3]) + yy_data[(int32_T)((real32_T)loop_ub + 3.0F)
          - 1] * (real32_T)cfd[i_0 + 7]) + yy_data[(int32_T)((real32_T)loop_ub +
          4.0F) - 1] * (real32_T)cfd[i_0 + 11]) / rt_powf_snf(tf /
          rtU.Breakpoints, (real32_T)x1_size_idx_1) / b_y;
      }
    }

    /* '<S1>:1:83' */
    rtDW.cc0.size[0] = rtDW.SFunction_DIMS2[0];
    rtDW.cc0.size[1] = rtDW.SFunction_DIMS2[1];
    loop_ub = rtDW.SFunction_DIMS2[0] * rtDW.SFunction_DIMS2[1] - 1;
    if (0 <= loop_ub) {
      memcpy(&rtDW.cc0.data[0], &rtb_cc[0], (loop_ub + 1) * sizeof(real32_T));
    }

    rtDW.cc0_not_empty = !(rtDW.cc0.size[0] == 0);

    /* '<S1>:1:84' */
  } else {
    /* '<S1>:1:87' */
    rtDW.SFunction_DIMS2[0] = rtDW.cc0.size[0];
    rtDW.SFunction_DIMS2[1] = rtDW.cc0.size[1];
    loop_ub = rtDW.cc0.size[0] * rtDW.cc0.size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&rtb_cc[0], &rtDW.cc0.data[0], loop_ub * sizeof(real32_T));
    }

    /* '<S1>:1:88' */
  }

  rtDW.SFunction_DIMS3[0] = rtDW.b0.size[0];
  rtDW.SFunction_DIMS3[1] = rtDW.b0.size[1];
  loop_ub = rtDW.b0.size[0] * rtDW.b0.size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&rtb_b[0], &rtDW.b0.data[0], loop_ub * sizeof(real32_T));
  }

  /* End of MATLAB Function: '<Root>/RT_CPU' */

  /* Outport: '<Root>/cc' */
  rtYSize.cc[0] = rtDW.SFunction_DIMS2[0];
  rtYSize.cc[1] = rtDW.SFunction_DIMS2[1];
  loop_ub = rtDW.SFunction_DIMS2[0] * rtDW.SFunction_DIMS2[1];
  if (0 <= loop_ub - 1) {
    memcpy(&rtY.cc[0], &rtb_cc[0], loop_ub * sizeof(real32_T));
  }

  /* End of Outport: '<Root>/cc' */

  /* Outport: '<Root>/b' */
  rtYSize.b[0] = rtDW.SFunction_DIMS3[0];
  rtYSize.b[1] = rtDW.SFunction_DIMS3[1];
  loop_ub = rtDW.SFunction_DIMS3[0] * rtDW.SFunction_DIMS3[1];
  if (0 <= loop_ub - 1) {
    memcpy(&rtY.b[0], &rtb_b[0], loop_ub * sizeof(real32_T));
  }

  /* End of Outport: '<Root>/b' */
}

/* Model initialize function */
void RT_CPU_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
