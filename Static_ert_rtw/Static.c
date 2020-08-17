/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Static.c
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

#include "Static.h"
#define NumBitsPerChar                 8U
#include "solver_zc.h"
#include "zero_crossing_types.h"
#ifndef slZcHadEvent
#define slZcHadEvent(ev, zcsDir)       (((ev) & (zcsDir)) != 0x00 )
#endif

#ifndef slZcUnAliasEvents
#define slZcUnAliasEvents(evL, evR)    ((((slZcHadEvent((evL), (SL_ZCS_EVENT_N2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2P))) || (slZcHadEvent((evL), (SL_ZCS_EVENT_P2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2N)))) ? (SL_ZCS_EVENT_NUL) : (evR)))
#endif

/* Block signals and states (default storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

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
extern ZCEventType rt_ZCFcn(ZCDirection zcDir, ZCSigState *prevZc, real_T
  currValue);
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

/* Detect zero crossings events. */
ZCEventType rt_ZCFcn(ZCDirection zcDir, ZCSigState* prevZc, real_T currValue)
{
  slZcEventType zcsDir;
  slZcEventType tempEv;
  ZCEventType zcEvent = NO_ZCEVENT;    /* assume */

  /* zcEvent matrix */
  static const slZcEventType eventMatrix[4][4] = {
    /*          ZER              POS              NEG              UNK */
    { SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_Z2P, SL_ZCS_EVENT_Z2N, SL_ZCS_EVENT_NUL },/* ZER */

    { SL_ZCS_EVENT_P2Z, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_P2N, SL_ZCS_EVENT_NUL },/* POS */

    { SL_ZCS_EVENT_N2Z, SL_ZCS_EVENT_N2P, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL },/* NEG */

    { SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL }/* UNK */
  };

  /* get prevZcEvent and prevZcSign from prevZc */
  slZcEventType prevEv = (slZcEventType)(((uint8_T)(*prevZc)) >> 2);
  slZcSignalSignType prevSign = (slZcSignalSignType)(((uint8_T)(*prevZc)) &
    (uint8_T)0x03);

  /* get current zcSignal sign from current zcSignal value */
  slZcSignalSignType currSign = (slZcSignalSignType)((currValue) > 0.0 ?
    SL_ZCS_SIGN_POS :
    ((currValue) < 0.0 ? SL_ZCS_SIGN_NEG : SL_ZCS_SIGN_ZERO));

  /* get current zcEvent based on prev and current zcSignal value */
  slZcEventType currEv = eventMatrix[prevSign][currSign];

  /* get slZcEventType from ZCDirection */
  switch (zcDir) {
   case ANY_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL;
    break;

   case FALLING_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL_DN;
    break;

   case RISING_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL_UP;
    break;

   default:
    zcsDir = SL_ZCS_EVENT_NUL;
    break;
  }

  /*had event, check if double zc happend remove double detection. */
  if (slZcHadEvent(currEv, zcsDir)) {
    currEv = (slZcEventType)(slZcUnAliasEvents(prevEv, currEv));
  } else {
    currEv = SL_ZCS_EVENT_NUL;
  }

  /* Update prevZc */
  tempEv = (slZcEventType)(currEv << 2);/* shift left by 2 bits */
  *prevZc = (ZCSigState)((currSign) | (tempEv));
  if ((currEv & SL_ZCS_EVENT_ALL_DN) != 0) {
    zcEvent = FALLING_ZCEVENT;
  } else if ((currEv & SL_ZCS_EVENT_ALL_UP) != 0) {
    zcEvent = RISING_ZCEVENT;
  } else {
    zcEvent = NO_ZCEVENT;
  }

  return zcEvent;
}                                      /* rt_ZCFcn */

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

/* Function for MATLAB Function: '<S1>/RT_CPU' */
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

/* Function for MATLAB Function: '<S1>/RT_CPU' */
static void sin_h(real32_T x_data[], int32_T x_size[2])
{
  int32_T k;
  for (k = 0; k < x_size[1]; k++) {
    x_data[k] = (real32_T)sin(x_data[k]);
  }
}

/* Function for MATLAB Function: '<S1>/RT_CPU' */
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
void Static_step(void)
{
  int32_T rst;
  real32_T tf;
  real32_T b_y;
  real32_T c_y;
  static const int8_T cfd[16] = { 1, -1, 1, -1, 0, 1, -2, 3, 0, 0, 1, -3, 0, 0,
    0, 1 };

  int32_T rtb_Trigger;
  ZCEventType zcEvent;
  int32_T loop_ub;
  int32_T i;
  int32_T i_0;
  int32_T tmp_size[2];
  int32_T x1_size_idx_1;
  int32_T y_size_idx_1;

  /* MATLAB Function: '<S1>/RT_CPU' incorporates:
   *  Inport: '<Root>/A'
   *  Inport: '<Root>/breakPoints'
   *  Inport: '<Root>/dutyCycle'
   *  Inport: '<Root>/f'
   *  Inport: '<Root>/mode'
   *  Inport: '<Root>/pOrder'
   *  Logic: '<S3>/OR'
   *  RelationalOperator: '<S10>/FixPt Relational Operator'
   *  RelationalOperator: '<S11>/FixPt Relational Operator'
   *  RelationalOperator: '<S12>/FixPt Relational Operator'
   *  RelationalOperator: '<S13>/FixPt Relational Operator'
   *  RelationalOperator: '<S8>/FixPt Relational Operator'
   *  RelationalOperator: '<S9>/FixPt Relational Operator'
   *  UnitDelay: '<S10>/Delay Input1'
   *  UnitDelay: '<S11>/Delay Input1'
   *  UnitDelay: '<S12>/Delay Input1'
   *  UnitDelay: '<S13>/Delay Input1'
   *  UnitDelay: '<S8>/Delay Input1'
   *  UnitDelay: '<S9>/Delay Input1'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S12>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S13>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S8>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S9>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rst = 0;
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

  if ((rtU.A != rtDW.DelayInput1_DSTATE) || (rtU.f != rtDW.DelayInput1_DSTATE_e)
      || (rtU.mode != rtDW.DelayInput1_DSTATE_d) || (rtU.DutyCycle !=
       rtDW.DelayInput1_DSTATE_a) || (rtU.Breakpoints !=
       rtDW.DelayInput1_DSTATE_j) || (rtU.pOrder != rtDW.DelayInput1_DSTATE_b) ||
      (rtDW.i0 < 1.0F)) {
    rst = 1;
    rtDW.i0 = 1.0F;
    rtDW.SFunction_DIMS2[0] = (int32_T)(rtU.Breakpoints + 1.0F);
    rtDW.SFunction_DIMS2[1] = 3;
    loop_ub = (int32_T)(rtU.Breakpoints + 1.0F) * 3;
    if (0 <= loop_ub - 1) {
      memset(&rtDW.cc[0], 0, loop_ub * sizeof(real32_T));
    }

    rtDW.b0.size[0] = 1;
    rtDW.b0.size[1] = (int32_T)(rtU.Breakpoints + 1.0F);
    rtb_Trigger = (int32_T)(rtU.Breakpoints + 1.0F) - 1;
    if (0 <= rtb_Trigger) {
      memset(&rtDW.b0.data[0], 0, (rtb_Trigger + 1) * sizeof(real32_T));
    }

    tf = 1.0F / rtU.f;
    linspace(rtU.Breakpoints + 1.0F, rtDW.tmp_data, tmp_size);
    rtDW.x_size[1] = tmp_size[1];
    loop_ub = tmp_size[0] * tmp_size[1];
    for (i = 0; i < loop_ub; i++) {
      rtDW.x_data[i] = (real32_T)rtDW.tmp_data[i];
    }

    linspace(rtU.Breakpoints, rtDW.tmp_data, rtDW.tmp_size);
    x1_size_idx_1 = rtDW.tmp_size[1];
    loop_ub = rtDW.tmp_size[0] * rtDW.tmp_size[1];
    for (i = 0; i < loop_ub; i++) {
      rtDW.x1_data[i] = (real32_T)rtDW.tmp_data[i];
    }

    switch ((int32_T)rtU.mode) {
     case 0:
      rtDW.x_size[0] = 1;
      loop_ub = tmp_size[1] - 1;
      for (i = 0; i <= loop_ub; i++) {
        rtDW.x_data[i] *= 6.28318548F;
      }

      sin_h(rtDW.x_data, rtDW.x_size);
      y_size_idx_1 = rtDW.x_size[1];
      loop_ub = rtDW.x_size[0] * rtDW.x_size[1] - 1;
      for (i = 0; i <= loop_ub; i++) {
        rtDW.y_data_m[i] = rtU.A * rtDW.x_data[i];
      }
      break;

     case 1:
      y_size_idx_1 = tmp_size[1];
      loop_ub = tmp_size[1] - 1;
      for (i = 0; i <= loop_ub; i++) {
        rtDW.y_data_m[i] = (real32_T)(rtDW.x_data[i] < rtU.DutyCycle) * rtU.A +
          (real32_T)(rtDW.x_data[i] >= rtU.DutyCycle) * -rtU.A;
      }

      rtDW.y_data_m[rtb_Trigger] = rtU.A;
      break;

     case 2:
      if ((rtU.DutyCycle == 0.0F) || (rtU.DutyCycle == 1.0F)) {
        loop_ub = rtDW.tmp_size[1] - 1;
        i = (rtU.DutyCycle == 1.0F);
        y_size_idx_1 = (rtU.DutyCycle == 0.0F);
        for (i_0 = 0; i_0 <= loop_ub; i_0++) {
          rtDW.y_data_m[i_0] = ((1.0F - rtDW.x1_data[i_0]) * rtU.A * 2.0F +
                                -rtU.A) * (real32_T)y_size_idx_1 +
            (rtDW.x1_data[i_0] * rtU.A * 2.0F + -rtU.A) * (real32_T)i;
        }

        y_size_idx_1 = rtDW.tmp_size[1] + 1;
        if (0 <= x1_size_idx_1 - 1) {
          memcpy(&rtDW.y_data[0], &rtDW.y_data_m[0], x1_size_idx_1 * sizeof
                 (real32_T));
        }

        rtDW.y_data[rtDW.tmp_size[1]] = rtDW.y_data_m[0];
        if (0 <= y_size_idx_1 - 1) {
          memcpy(&rtDW.y_data_m[0], &rtDW.y_data[0], y_size_idx_1 * sizeof
                 (real32_T));
        }
      } else {
        b_y = 2.0F / rtU.DutyCycle;
        c_y = 2.0F / (1.0F - rtU.DutyCycle);
        y_size_idx_1 = tmp_size[1];
        loop_ub = tmp_size[1] - 1;
        for (i = 0; i <= loop_ub; i++) {
          rtDW.y_data_m[i] = ((1.0F - rtDW.x_data[i]) * rtU.A * c_y + -rtU.A) *
            (real32_T)(rtDW.x_data[i] > rtU.DutyCycle) + (rtDW.x_data[i] * rtU.A
            * b_y + -rtU.A) * (real32_T)(rtDW.x_data[i] <= rtU.DutyCycle);
        }
      }
      break;

     default:
      y_size_idx_1 = 1;
      rtDW.y_data_m[0] = 0.0F;
      break;
    }

    if (0 <= y_size_idx_1 - 1) {
      memcpy(&rtDW.yy_data[0], &rtDW.y_data_m[0], y_size_idx_1 * sizeof(real32_T));
    }

    rtDW.yy_data[y_size_idx_1] = rtDW.y_data_m[1];
    rtDW.yy_data[1 + y_size_idx_1] = rtDW.y_data_m[2];
    rtDW.yy_data[2 + y_size_idx_1] = rtDW.y_data_m[3];
    for (loop_ub = 0; loop_ub <= rtb_Trigger; loop_ub++) {
      i = (int32_T)((real32_T)loop_ub + 1.0F);
      y_size_idx_1 = i - 1;
      rtDW.b0.data[rtDW.b0.size[0] * y_size_idx_1] = (real32_T)loop_ub * tf /
        rtU.Breakpoints;
      for (x1_size_idx_1 = 0; x1_size_idx_1 < (int32_T)(rtU.pOrder + 1.0F);
           x1_size_idx_1++) {
        b_y = (real32_T)x1_size_idx_1;
        factorial(&b_y);
        i_0 = (int32_T)((real32_T)x1_size_idx_1 + 1.0F);
        rtDW.cc[(i + rtDW.SFunction_DIMS2[0] * ((int32_T)((real32_T)
                   x1_size_idx_1 + 1.0F) - 1)) - 1] =
          (((rtDW.yy_data[y_size_idx_1] * (real32_T)cfd[i_0 - 1] + rtDW.yy_data
             [(int32_T)((real32_T)loop_ub + 2.0F) - 1] * (real32_T)cfd[i_0 + 3])
            + rtDW.yy_data[(int32_T)((real32_T)loop_ub + 3.0F) - 1] * (real32_T)
            cfd[i_0 + 7]) + rtDW.yy_data[(int32_T)((real32_T)loop_ub + 4.0F) - 1]
           * (real32_T)cfd[i_0 + 11]) / rt_powf_snf(tf / rtU.Breakpoints,
          (real32_T)x1_size_idx_1) / b_y;
      }
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
    loop_ub = rtDW.cc0.size[0] * rtDW.cc0.size[1];
    if (0 <= loop_ub - 1) {
      memcpy(&rtDW.cc[0], &rtDW.cc0.data[0], loop_ub * sizeof(real32_T));
    }
  }

  rtDW.SFunction_DIMS3[0] = rtDW.b0.size[0];
  rtDW.SFunction_DIMS3[1] = rtDW.b0.size[1];

  /* DiscretePulseGenerator: '<S1>/Trigger' */
  rtb_Trigger = ((rtDW.clockTickCounter < 1) && (rtDW.clockTickCounter >= 0));
  if (rtDW.clockTickCounter >= 1) {
    rtDW.clockTickCounter = 0;
  } else {
    rtDW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Trigger' */

  /* Outputs for Triggered SubSystem: '<S1>/Coefficient Sequencer' incorporates:
   *  TriggerPort: '<S2>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &rtPrevZCX.CoefficientSequencer_Trig_ZCE,
                     ((real_T)rtb_Trigger));
  if (zcEvent != NO_ZCEVENT) {
    /* Outport: '<Root>/write' incorporates:
     *  Delay: '<S7>/Delay'
     *  Inport: '<Root>/breakPoints'
     *  RelationalOperator: '<S7>/GreaterThan'
     */
    rtY.write = (rtU.Breakpoints > rtY.writeAddr);

    /* S-Function (sdspcount2): '<S7>/Counter' incorporates:
     *  MATLAB Function: '<S1>/RT_CPU'
     *  Outport: '<Root>/write'
     */
    if (rst != 0) {
      rtDW.Counter_Count = 0U;
    }

    if (rtY.write) {
      if (rtDW.Counter_Count < 255) {
        rtDW.Counter_Count++;
      } else {
        rtDW.Counter_Count = 0U;
      }
    }

    /* Outport: '<Root>/writeAddr' incorporates:
     *  S-Function (sdspcount2): '<S7>/Counter'
     */
    rtY.writeAddr = rtDW.Counter_Count;

    /* Switch: '<S6>/Switch1' incorporates:
     *  Constant: '<S6>/Constant'
     *  Outport: '<Root>/write'
     *  Outport: '<Root>/writeAddr'
     *  Selector: '<S6>/Selector'
     */
    if (rtY.write) {
      rtDW.Switch1[0] = rtDW.cc[(int32_T)rtY.writeAddr];
      rtDW.Switch1[1] = rtDW.cc[(int32_T)rtY.writeAddr + rtDW.SFunction_DIMS2[0]];
      rtDW.Switch1[2] = rtDW.cc[(rtDW.SFunction_DIMS2[0] << 1) + (int32_T)
        rtY.writeAddr];
    } else {
      rtDW.Switch1[0] = rtY.write;
      rtDW.Switch1[1] = rtY.write;
      rtDW.Switch1[2] = rtY.write;
    }

    /* End of Switch: '<S6>/Switch1' */
  }

  /* End of Outputs for SubSystem: '<S1>/Coefficient Sequencer' */

  /* Outport: '<Root>/c0' */
  rtY.c0 = rtDW.Switch1[0];

  /* Outport: '<Root>/c1' */
  rtY.c1 = rtDW.Switch1[1];

  /* Outport: '<Root>/c2' */
  rtY.c2 = rtDW.Switch1[2];

  /* Outport: '<Root>/M' incorporates:
   *  Constant: '<S5>/cte2'
   *  Constant: '<S5>/n'
   *  Inport: '<Root>/f'
   *  Inport: '<Root>/f-clk'
   *  Math: '<S5>/Math Function1'
   *  Product: '<S5>/f_in_fclk'
   *  Product: '<S5>/f_in_fclk1'
   */
  rtY.M = rtU.f / rtU.fclk * 128.0;

  /* Outport: '<Root>/T' incorporates:
   *  Inport: '<Root>/f'
   *  Math: '<S5>/Math Function2'
   *
   * About '<S5>/Math Function2':
   *  Operator: reciprocal
   */
  rtY.T = 1.0F / rtU.f;

  /* Update for UnitDelay: '<S8>/Delay Input1' incorporates:
   *  Inport: '<Root>/A'
   *
   * Block description for '<S8>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtDW.DelayInput1_DSTATE = rtU.A;

  /* Update for UnitDelay: '<S9>/Delay Input1' incorporates:
   *  Inport: '<Root>/f'
   *
   * Block description for '<S9>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtDW.DelayInput1_DSTATE_e = rtU.f;

  /* Update for UnitDelay: '<S10>/Delay Input1' incorporates:
   *  Inport: '<Root>/mode'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtDW.DelayInput1_DSTATE_d = rtU.mode;

  /* Update for UnitDelay: '<S11>/Delay Input1' incorporates:
   *  Inport: '<Root>/dutyCycle'
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtDW.DelayInput1_DSTATE_a = rtU.DutyCycle;

  /* Update for UnitDelay: '<S12>/Delay Input1' incorporates:
   *  Inport: '<Root>/breakPoints'
   *
   * Block description for '<S12>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtDW.DelayInput1_DSTATE_j = rtU.Breakpoints;

  /* Update for UnitDelay: '<S13>/Delay Input1' incorporates:
   *  Inport: '<Root>/pOrder'
   *
   * Block description for '<S13>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtDW.DelayInput1_DSTATE_b = rtU.pOrder;
}

/* Model initialize function */
void Static_initialize(void)
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
