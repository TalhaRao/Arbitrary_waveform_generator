/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: uc3_preparation1_2017.c
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

#include "uc3_preparation1_2017.h"
#include "uc3_preparation1_2017_private.h"

/* Named constants for Chart: '<S6>/Chart' */
#define uc3_preparation1_2017_IN_sate2 ((uint8_T)1U)
#define uc3_preparation1_2017_IN_state1 ((uint8_T)2U)

/* user code (top of source file) */
/* System '<Root>' */
int32_T *tune1 = 0x4*10;
int32_T *tune2 = 0x4*11;
int32_T *tune3 = 0x4*12;
int32_T *tune4 = 0x4*13;
int32_T *tune5 = 0x4*14;
int32_T *tune6 = 0x4*15;
int32_T *tune7 = 0x4*16;
int32_T *tune8 = 0x4*17;
int32_T *share_in1 = 0x0;
int32_T *share_in2 = 0x4*1;
int32_T *share_in3 = 0x4*2;
int32_T *share_in4 = 0x4*3;
int32_T *share_in5 = 0x4*4;
int32_T *share_in6 = 0x4*5;
int32_T *share_in7 = 0x4*6;
int32_T *share_in8 = 0x4*7;
int32_T *share_in9 = 0x4*8;
int32_T *share_in10 = 0x4*9;
int32_T *probe1 = 0x400 + 0x4*10;
int32_T *probe2 = 0x400 + 0x4*11;
int32_T *probe3 = 0x400 + 0x4*12;
int32_T *probe4 = 0x400 + 0x4*13;
int32_T *probe5 = 0x400 + 0x4*14;
int32_T *probe6 = 0x400 + 0x4*15;
int32_T *probe7 = 0x400 + 0x4*16;
int32_T *probe8 = 0x400 + 0x4*17;
int32_T *share_out1 = 0x400 + 0x4*0;
int32_T *share_out2 = 0x400 + 0x4*1;
int32_T *share_out3 = 0x400 + 0x4*2;
int32_T *share_out4 = 0x400 + 0x4*3;
int32_T *share_out5 = 0x400 + 0x4*4;
int32_T *share_out6 = 0x400 + 0x4*5;
int32_T *share_out7 = 0x400 + 0x4*6;
int32_T *share_out8 = 0x400 + 0x4*7;
int32_T *share_out9 = 0x400 + 0x4*8;
int32_T *share_out10 = 0x400 + 0x4*9;
unsigned *c_cycle_freq = 0x81200000;

/* Block signals (default storage) */
B_uc3_preparation1_2017_T uc3_preparation1_2017_B;

/* Block states (default storage) */
DW_uc3_preparation1_2017_T uc3_preparation1_2017_DW;

/* Real-time model */
RT_MODEL_uc3_preparation1_201_T uc3_preparation1_2017_M_;
RT_MODEL_uc3_preparation1_201_T *const uc3_preparation1_2017_M =
  &uc3_preparation1_2017_M_;
void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T absIn0;
  uint32_T absIn1;
  uint32_T in0Lo;
  uint32_T in0Hi;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = in0 < 0 ? ~(uint32_T)in0 + 1U : (uint32_T)in0;
  absIn1 = in1 < 0 ? ~(uint32_T)in1 + 1U : (uint32_T)in1;
  in0Hi = absIn0 >> 16U;
  in0Lo = absIn0 & 65535U;
  in1Hi = absIn1 >> 16U;
  absIn0 = absIn1 & 65535U;
  productHiLo = in0Hi * absIn0;
  productLoHi = in0Lo * in1Hi;
  absIn0 *= in0Lo;
  absIn1 = 0U;
  in0Lo = (productLoHi << /*MW:OvBitwiseOk*/ 16U) + /*MW:OvCarryOk*/ absIn0;
  if (in0Lo < absIn0) {
    absIn1 = 1U;
  }

  absIn0 = in0Lo;
  in0Lo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 16U;
  if (in0Lo < absIn0) {
    absIn1++;
  }

  absIn0 = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi) +
    absIn1;
  if (!((in0 == 0) || ((in1 == 0) || ((in0 > 0) == (in1 > 0))))) {
    absIn0 = ~absIn0;
    in0Lo = ~in0Lo;
    in0Lo++;
    if (in0Lo == 0U) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = in0Lo;
}

int32_T mul_s32_loSR(int32_T a, int32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << /*MW:OvBitwiseOk*/ (32U - aShift) | u32_clo >> aShift;
  return (int32_T)u32_clo;
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
void uc3_preparation1_2017_step(void)
{
  real32_T d_sep;
  real32_T tf;
  real_T i;
  int32_T j;
  int32_T b_k;
  static const real32_T f[34] = { 1.0F, 2.0F, 6.0F, 24.0F, 120.0F, 720.0F,
    5040.0F, 40320.0F, 362880.0F, 3.6288E+6F, 3.99168E+7F, 4.790016E+8F,
    6.2270208E+9F, 8.71782892E+10F, 1.30767428E+12F, 2.09227885E+13F,
    3.55687415E+14F, 6.40237353E+15F, 1.21645096E+17F, 2.43290202E+18F,
    5.10909408E+19F, 1.12400072E+21F, 2.58520174E+22F, 6.20448455E+23F,
    1.55112111E+25F, 4.032915E+26F, 1.08888704E+28F, 3.04888372E+29F,
    8.84176308E+30F, 2.6525289E+32F, 8.22283969E+33F, 2.6313087E+35F,
    8.68331851E+36F, 2.95232823E+38F };

  static const int8_T cfd[16] = { 1, -1, 1, -1, 0, 1, -2, 3, 0, 0, 1, -3, 0, 0,
    0, 1 };

  boolean_T rtb_Compare_e;
  real32_T rtb_Gain2;
  int32_T rtb_Add1;
  int32_T j_0;
  real32_T rtb_Switch_idx_0;

  /* Constant: '<Root>/Amplitude' */
  *tune1 = uc3_preparation1_2017_P.Amplitude_Value;

  /* DataTypeConversion: '<S13>/Data Type Conversion3' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  *share_in3 = uc3_preparation1_2017_P.Constant1_Value_n;

  /* DataTypeConversion: '<S4>/Data Type Conversion3' */
  *probe3 = *share_in3;

  /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
   *  Constant: '<S4>/Constant'
   */
  *probe4 = uc3_preparation1_2017_P.Constant_Value_p;

  /* DataTypeConversion: '<S4>/Data Type Conversion2' */
  *share_out1 = 0;

  /* Constant: '<Root>/Mode' */
  *tune3 = uc3_preparation1_2017_P.Mode_Value;

  /* Constant: '<Root>/Freq_in_Hz' */
  *tune2 = uc3_preparation1_2017_P.Freq_in_Hz_Value;

  /* Constant: '<Root>/duty' */
  *tune4 = uc3_preparation1_2017_P.duty_Value;

  /* Constant: '<Root>/Polynomial' */
  *tune5 = uc3_preparation1_2017_P.Polynomial_Value;

  /* MATLAB Function: '<S5>/RT_CPU' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion1'
   *  DataTypeConversion: '<S4>/Data Type Conversion4'
   *  DataTypeConversion: '<S4>/Data Type Conversion5'
   *  DataTypeConversion: '<S4>/Data Type Conversion6'
   *  DataTypeConversion: '<S4>/Data Type Conversion7'
   */
  rtb_Gain2 = (real32_T)*tune5;

  /* MATLAB Function 'CandHDL_c/cgenerate/Subsystem/RT_CPU': '<S7>:1' */
  /* '<S7>:1:127' */
  /* '<S7>:1:139' */
  /* '<S7>:1:17' */
  d_sep = (real32_T)*tune4 * 1.28F;
  if (!uc3_preparation1_2017_DW.cc0_not_empty) {
    /* '<S7>:1:19' */
    uc3_preparation1_2017_DW.cc0_not_empty = true;

    /* '<S7>:1:23' */
    rtb_Gain2 = 2.0F;
  }

  /* '<S7>:1:30' */
  rtb_Add1 = 0;
  if (uc3_preparation1_2017_DW.i0 < 1.0F) {
    /* '<S7>:1:35' */
    /* '<S7>:1:36' */
    uc3_preparation1_2017_DW.i0 = 1.0F;

    /* '<S7>:1:38' */
    memset(&uc3_preparation1_2017_DW.cc0[0], 0, 387U * sizeof(real32_T));

    /* '<S7>:1:39' */
    /* '<S7>:1:40' */
    /* '<S7>:1:41' */
    rtb_Switch_idx_0 = 1.0F / (real32_T)*tune2;

    /* '<S7>:1:43' */
    rtb_Add1 = 1;
    switch ((int32_T)(real32_T)*tune3) {
     case 0:
      /* '<S7>:1:54' */
      tf = 6.28318548F * (real32_T)*tune2;
      uc3_preparation1_2017_B.y[128] = rtb_Switch_idx_0;
      uc3_preparation1_2017_B.y[0] = 0.0F;
      if ((rtb_Switch_idx_0 < 0.0F) && ((real32_T)fabs(rtb_Switch_idx_0) >
           1.70141173E+38F)) {
        d_sep = rtb_Switch_idx_0 / 128.0F;
        for (b_k = 0; b_k < 127; b_k++) {
          uc3_preparation1_2017_B.y[b_k + 1] = (1.0F + (real32_T)b_k) * d_sep;
        }
      } else {
        d_sep = rtb_Switch_idx_0 / 128.0F;
        for (b_k = 0; b_k < 127; b_k++) {
          uc3_preparation1_2017_B.y[b_k + 1] = (1.0F + (real32_T)b_k) * d_sep;
        }
      }

      for (b_k = 0; b_k < 129; b_k++) {
        uc3_preparation1_2017_B.y[b_k] = (real32_T)sin(tf *
          uc3_preparation1_2017_B.y[b_k]) * (real32_T)*tune1;
      }
      break;

     case 1:
      /* '<S7>:1:60' */
      i = 1.0;

      /* '<S7>:1:61' */
      memset(&uc3_preparation1_2017_B.y[0], 0, 129U * sizeof(real32_T));
      d_sep = rtb_Switch_idx_0 / 128.0F;
      b_k = (int32_T)((rtb_Switch_idx_0 + d_sep) / d_sep);

      /* '<S7>:1:63' */
      for (j = 0; j < b_k; j++) {
        /* '<S7>:1:63' */
        if ((real32_T)j * d_sep <= rtb_Switch_idx_0 * (real32_T)*tune4) {
          /* '<S7>:1:64' */
          /* '<S7>:1:66' */
          uc3_preparation1_2017_B.y[(int32_T)i - 1] = (real32_T)*tune1;
        } else {
          /* '<S7>:1:68' */
          uc3_preparation1_2017_B.y[(int32_T)i - 1] = -(real32_T)*tune1;
        }

        /* '<S7>:1:70' */
        i++;
      }
      break;

     case 2:
      /* '<S7>:1:75' */
      i = 1.0;

      /* '<S7>:1:76' */
      memset(&uc3_preparation1_2017_B.y[0], 0, 129U * sizeof(real32_T));
      d_sep = rtb_Switch_idx_0 / 128.0F;
      b_k = (int32_T)((rtb_Switch_idx_0 + d_sep) / d_sep);

      /* '<S7>:1:77' */
      for (j = 0; j < b_k; j++) {
        /* '<S7>:1:77' */
        if (i == 1.0) {
          /* '<S7>:1:78' */
          /* '<S7>:1:79' */
          uc3_preparation1_2017_B.y[0] = (real32_T)*tune1;
        } else if ((real32_T)j * d_sep <= rtb_Switch_idx_0 * (real32_T)*tune4) {
          /* '<S7>:1:81' */
          /* '<S7>:1:82' */
          uc3_preparation1_2017_B.y[(int32_T)i - 1] = (real32_T)*tune1 / 128.0F *
            2.0F / (real32_T)*tune4 + uc3_preparation1_2017_B.y[(int32_T)(i -
            1.0) - 1];
        } else {
          /* '<S7>:1:84' */
          uc3_preparation1_2017_B.y[(int32_T)i - 1] = uc3_preparation1_2017_B.y
            [(int32_T)(i - 1.0) - 1] - (real32_T)*tune1 / 128.0F * 2.0F / (1.0F
            - (real32_T)*tune4);
        }

        /* '<S7>:1:87' */
        i++;
      }
      break;

     case 3:
      /* '<S7>:1:93' */
      /* '<S7>:1:95' */
      for (b_k = 0; b_k < 128; b_k++) {
        /* '<S7>:1:95' */
        if (1.0 + (real_T)b_k <= d_sep) {
          /* '<S7>:1:96' */
          /* '<S7>:1:98' */
          uc3_preparation1_2017_B.y[b_k] = (real32_T)*tune1;
        } else {
          /* '<S7>:1:100' */
          uc3_preparation1_2017_B.y[b_k] = -(real32_T)*tune1;
        }

        /* '<S7>:1:102' */
        uc3_preparation1_2017_B.y[b_k + 1] = (real32_T)*tune1;
      }
      break;

     case 4:
      /* '<S7>:1:107' */
      memset(&uc3_preparation1_2017_B.y[0], 0, 129U * sizeof(real32_T));
      i = 1.0;

      /* '<S7>:1:108' */
      for (b_k = 0; b_k < 128; b_k++) {
        /* '<S7>:1:108' */
        i = 1.0 + (real_T)b_k;
        if (1.0 + (real_T)b_k <= d_sep) {
          /* '<S7>:1:109' */
          /* '<S7>:1:110' */
          uc3_preparation1_2017_B.y[b_k] = (real32_T)*tune1 - (real32_T)*tune1 /
            d_sep;
        } else {
          /* '<S7>:1:112' */
          uc3_preparation1_2017_B.y[b_k] = (real32_T)*tune1 / ((128.0F - d_sep)
            - (1.0F + (real32_T)b_k)) + -(real32_T)*tune1;
        }
      }

      /* '<S7>:1:116' */
      uc3_preparation1_2017_B.y[(int32_T)i] = (real32_T)*tune1;
      break;

     default:
      /* '<S7>:1:120' */
      /* '<S7>:1:121' */
      rtb_Gain2 = 2.0F;

      /* '<S7>:1:122' */
      memset(&uc3_preparation1_2017_B.y[0], 0, 129U * sizeof(real32_T));
      break;
    }

    /* '<S7>:1:127' */
    /* '<S7>:1:133' */
    memcpy(&uc3_preparation1_2017_B.yy[0], &uc3_preparation1_2017_B.y[0], 129U *
           sizeof(real32_T));
    uc3_preparation1_2017_B.yy[129] = uc3_preparation1_2017_B.y[1];
    uc3_preparation1_2017_B.yy[130] = uc3_preparation1_2017_B.y[2];
    uc3_preparation1_2017_B.yy[131] = uc3_preparation1_2017_B.y[3];

    /* '<S7>:1:135' */
    for (b_k = 0; b_k < 129; b_k++) {
      /* '<S7>:1:135' */
      /* '<S7>:1:136' */
      /* '<S7>:1:137' */
      /* '<S7>:1:138' */
      for (j = 0; j < (int32_T)(rtb_Gain2 + 1.0F); j++) {
        /* '<S7>:1:138' */
        /* '<S7>:1:139' */
        /* '<S7>:1:140' */
        tf = (real32_T)j;
        if (!((j < 0.0F) || ((real32_T)j != j))) {
          if (j > 34.0F) {
            tf = (rtInfF);
          } else if (j < 1) {
            tf = 1.0F;
          } else {
            tf = f[j - 1];
          }
        }

        j_0 = (int32_T)((real32_T)j + 1.0F);
        uc3_preparation1_2017_DW.cc0[b_k + 129 * ((int32_T)((real32_T)j + 1.0F)
          - 1)] = ((((real32_T)cfd[j_0 - 1] * uc3_preparation1_2017_B.yy[b_k] +
                     (real32_T)cfd[j_0 + 3] * uc3_preparation1_2017_B.yy[b_k + 1])
                    + (real32_T)cfd[j_0 + 7] * uc3_preparation1_2017_B.yy[b_k +
                    2]) + (real32_T)cfd[j_0 + 11] *
                   uc3_preparation1_2017_B.yy[b_k + 3]) / rt_powf_snf((real32_T)*
          tune2 / 128.0F, (real32_T)j) / tf;
      }
    }

    /* '<S7>:1:145' */
    /* '<S7>:1:146' */
  } else {
    /* '<S7>:1:150' */
    /* '<S7>:1:151' */
  }

  /* Outputs for Atomic SubSystem: '<S5>/Counter' */
  /* Chart: '<S6>/Chart' incorporates:
   *  Constant: '<S11>/Constant'
   *  Delay: '<S6>/Delay1'
   *  MATLAB Function: '<S5>/RT_CPU'
   *  RelationalOperator: '<S11>/Compare'
   *  Sum: '<S6>/Sum2'
   *  Sum: '<S6>/Sum3'
   */
  /* Gateway: CandHDL_c/cgenerate/Subsystem/Counter/Chart */
  /* During: CandHDL_c/cgenerate/Subsystem/Counter/Chart */
  if (uc3_preparation1_2017_DW.is_c1_uc3_preparation1_2017 ==
      uc3_preparation1_2017_IN_sate2) {
    /* During 'sate2': '<S10>:43' */
    if ((real32_T)((real32_T)rtb_Add1 + uc3_preparation1_2017_B.counter !=
                   uc3_preparation1_2017_P.Constant_Value) +
        uc3_preparation1_2017_B.counter == 1.0F) {
      /* Transition: '<S10>:45' */
      uc3_preparation1_2017_DW.is_c1_uc3_preparation1_2017 =
        uc3_preparation1_2017_IN_state1;

      /* Entry 'state1': '<S10>:41' */
      uc3_preparation1_2017_B.counter = 0.0F;
    } else {
      uc3_preparation1_2017_B.counter = 0.0F;
    }
  } else {
    /* During 'state1': '<S10>:41' */
    if (uc3_preparation1_2017_B.counter > 128.0F) {
      /* Transition: '<S10>:44' */
      uc3_preparation1_2017_DW.is_c1_uc3_preparation1_2017 =
        uc3_preparation1_2017_IN_sate2;

      /* Entry 'sate2': '<S10>:43' */
    } else {
      uc3_preparation1_2017_B.counter++;
    }
  }

  /* End of Chart: '<S6>/Chart' */

  /* RelationalOperator: '<S12>/Compare' incorporates:
   *  Constant: '<S12>/Constant'
   */
  rtb_Compare_e = (uc3_preparation1_2017_B.counter !=
                   uc3_preparation1_2017_P.Constant_Value_l);

  /* End of Outputs for SubSystem: '<S5>/Counter' */

  /* DataTypeConversion: '<S5>/Data Type Conversion2' */
  *share_out5 = rtb_Compare_e;

  /* DataTypeConversion: '<S5>/Data Type Conversion4' */
  rtb_Switch_idx_0 = (real32_T)floor(uc3_preparation1_2017_B.counter);
  if (rtIsNaNF(rtb_Switch_idx_0) || rtIsInfF(rtb_Switch_idx_0)) {
    rtb_Switch_idx_0 = 0.0F;
  } else {
    rtb_Switch_idx_0 = (real32_T)fmod(rtb_Switch_idx_0, 4.294967296E+9);
  }

  *share_out8 = rtb_Switch_idx_0 < 0.0F ? -(int32_T)(uint32_T)-rtb_Switch_idx_0 :
    (int32_T)(uint32_T)rtb_Switch_idx_0;

  /* End of DataTypeConversion: '<S5>/Data Type Conversion4' */

  /* DataTypeConversion: '<S8>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion5'
   *  Gain: '<S8>/Gain'
   *  Math: '<S8>/Math Function2'
   *
   * About '<S8>/Math Function2':
   *  Operator: reciprocal
   */
  rtb_Switch_idx_0 = (real32_T)floor(1.0F / (real32_T)*tune2 *
    uc3_preparation1_2017_P.Gain_Gain_a);
  if (rtIsNaNF(rtb_Switch_idx_0) || rtIsInfF(rtb_Switch_idx_0)) {
    rtb_Switch_idx_0 = 0.0F;
  } else {
    rtb_Switch_idx_0 = (real32_T)fmod(rtb_Switch_idx_0, 4.294967296E+9);
  }

  *share_out7 = rtb_Switch_idx_0 < 0.0F ? -(int32_T)(uint32_T)-rtb_Switch_idx_0 :
    (int32_T)(uint32_T)rtb_Switch_idx_0;

  /* End of DataTypeConversion: '<S8>/Data Type Conversion1' */

  /* Math: '<S8>/Math Function1' incorporates:
   *  Constant: '<S8>/cte2'
   *  Constant: '<S8>/n'
   */
  if ((uc3_preparation1_2017_P.cte2_Value < 0.0F) &&
      (uc3_preparation1_2017_P.n_Value > (real32_T)floor
       (uc3_preparation1_2017_P.n_Value))) {
    rtb_Switch_idx_0 = -rt_powf_snf(-uc3_preparation1_2017_P.cte2_Value,
      uc3_preparation1_2017_P.n_Value);
  } else {
    rtb_Switch_idx_0 = rt_powf_snf(uc3_preparation1_2017_P.cte2_Value,
      uc3_preparation1_2017_P.n_Value);
  }

  /* End of Math: '<S8>/Math Function1' */

  /* DataTypeConversion: '<S8>/Data Type Conversion2' incorporates:
   *  Constant: '<S5>/f_clk'
   *  DataTypeConversion: '<S4>/Data Type Conversion5'
   *  Gain: '<S8>/Gain1'
   *  Product: '<S8>/f_in_fclk'
   *  Product: '<S8>/f_in_fclk1'
   */
  rtb_Switch_idx_0 = (real32_T)floor((real32_T)*tune2 / (real32_T)
    uc3_preparation1_2017_P.f_clk_Value * rtb_Switch_idx_0 *
    uc3_preparation1_2017_P.Gain1_Gain_m);
  if (rtIsNaNF(rtb_Switch_idx_0) || rtIsInfF(rtb_Switch_idx_0)) {
    rtb_Switch_idx_0 = 0.0F;
  } else {
    rtb_Switch_idx_0 = (real32_T)fmod(rtb_Switch_idx_0, 4.294967296E+9);
  }

  *share_out6 = rtb_Switch_idx_0 < 0.0F ? -(int32_T)(uint32_T)-rtb_Switch_idx_0 :
    (int32_T)(uint32_T)rtb_Switch_idx_0;

  /* End of DataTypeConversion: '<S8>/Data Type Conversion2' */

  /* Outputs for Atomic SubSystem: '<S5>/selectror' */
  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   *  MATLAB Function: '<S5>/RT_CPU'
   *  Selector: '<S9>/Selector'
   */
  if (rtb_Compare_e) {
    /* Selector: '<S9>/Selector' incorporates:
     *  Bias: '<S9>/Bias'
     */
    rtb_Add1 = (int32_T)(uc3_preparation1_2017_B.counter +
                         uc3_preparation1_2017_P.Bias_Bias);
    rtb_Switch_idx_0 = uc3_preparation1_2017_DW.cc0[129 * (int32_T)
      uc3_preparation1_2017_P.Constant_Value_k[0] + rtb_Add1];
    rtb_Gain2 = uc3_preparation1_2017_DW.cc0[129 * (int32_T)
      uc3_preparation1_2017_P.Constant_Value_k[1] + rtb_Add1];
    d_sep = uc3_preparation1_2017_DW.cc0[129 * (int32_T)
      uc3_preparation1_2017_P.Constant_Value_k[2] + rtb_Add1];
  } else {
    rtb_Switch_idx_0 = uc3_preparation1_2017_P.Constant1_Value_d;
    rtb_Gain2 = uc3_preparation1_2017_P.Constant1_Value_d;
    d_sep = uc3_preparation1_2017_P.Constant1_Value_d;
  }

  /* End of Switch: '<S9>/Switch' */

  /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
   *  Gain: '<S9>/Gain'
   */
  rtb_Switch_idx_0 = (real32_T)floor(uc3_preparation1_2017_P.Gain_Gain_b *
    rtb_Switch_idx_0);
  if (rtIsNaNF(rtb_Switch_idx_0) || rtIsInfF(rtb_Switch_idx_0)) {
    rtb_Switch_idx_0 = 0.0F;
  } else {
    rtb_Switch_idx_0 = (real32_T)fmod(rtb_Switch_idx_0, 4.294967296E+9);
  }

  *share_out2 = rtb_Switch_idx_0 < 0.0F ? -(int32_T)(uint32_T)-rtb_Switch_idx_0 :
    (int32_T)(uint32_T)rtb_Switch_idx_0;

  /* End of DataTypeConversion: '<S9>/Data Type Conversion' */

  /* DataTypeConversion: '<S9>/Data Type Conversion1' incorporates:
   *  Gain: '<S9>/Gain1'
   */
  rtb_Switch_idx_0 = (real32_T)floor(uc3_preparation1_2017_P.Gain1_Gain *
    rtb_Gain2);
  if (rtIsNaNF(rtb_Switch_idx_0) || rtIsInfF(rtb_Switch_idx_0)) {
    rtb_Switch_idx_0 = 0.0F;
  } else {
    rtb_Switch_idx_0 = (real32_T)fmod(rtb_Switch_idx_0, 4.294967296E+9);
  }

  *share_out3 = rtb_Switch_idx_0 < 0.0F ? -(int32_T)(uint32_T)-rtb_Switch_idx_0 :
    (int32_T)(uint32_T)rtb_Switch_idx_0;

  /* End of DataTypeConversion: '<S9>/Data Type Conversion1' */

  /* DataTypeConversion: '<S9>/Data Type Conversion2' incorporates:
   *  Gain: '<S9>/Gain2'
   */
  rtb_Switch_idx_0 = (real32_T)floor(uc3_preparation1_2017_P.Gain2_Gain * d_sep);
  if (rtIsNaNF(rtb_Switch_idx_0) || rtIsInfF(rtb_Switch_idx_0)) {
    rtb_Switch_idx_0 = 0.0F;
  } else {
    rtb_Switch_idx_0 = (real32_T)fmod(rtb_Switch_idx_0, 4.294967296E+9);
  }

  *share_out4 = rtb_Switch_idx_0 < 0.0F ? -(int32_T)(uint32_T)-rtb_Switch_idx_0 :
    (int32_T)(uint32_T)rtb_Switch_idx_0;

  /* End of DataTypeConversion: '<S9>/Data Type Conversion2' */
  /* End of Outputs for SubSystem: '<S5>/selectror' */

  /* Sum: '<S21>/Add1' incorporates:
   *  Gain: '<S16>/Gain'
   *  UnitDelay: '<S21>/Unit Delay1'
   */
  rtb_Add1 = mul_s32_loSR(uc3_preparation1_2017_P.Gain_Gain, *share_out6, 31U) +
    uc3_preparation1_2017_DW.UnitDelay1_DSTATE;

  /* Switch: '<S21>/Switch' incorporates:
   *  Constant: '<S21>/Constant3'
   *  RelationalOperator: '<S21>/Relational Operator'
   */
  /* MATLAB Function 'Logic and Bit Operations/Bit Slice/bit_slice': '<S29>:1' */
  /* '<S29>:1:4' */
  /* MATLAB Function 'Bit Concat2/bit_concat': '<S18>:1' */
  /* '<S18>:1:4' */
  /* MATLAB Function 'Logic and Bit Operations/Bit Slice/bit_slice': '<S19>:1' */
  /* '<S19>:1:4' */
  if (((rtb_Add1 >= uc3_preparation1_2017_P.Constant3_Value) << 19) >=
      uc3_preparation1_2017_P.Switch_Threshold) {
    /* Update for UnitDelay: '<S21>/Unit Delay1' incorporates:
     *  Constant: '<S21>/Constant1'
     */
    uc3_preparation1_2017_DW.UnitDelay1_DSTATE =
      uc3_preparation1_2017_P.Constant1_Value;
  } else {
    /* Update for UnitDelay: '<S21>/Unit Delay1' */
    uc3_preparation1_2017_DW.UnitDelay1_DSTATE = rtb_Add1;
  }

  /* End of Switch: '<S21>/Switch' */
}

/* Model initialize function */
void uc3_preparation1_2017_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(uc3_preparation1_2017_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &uc3_preparation1_2017_B), 0,
                sizeof(B_uc3_preparation1_2017_T));

  /* states (dwork) */
  (void) memset((void *)&uc3_preparation1_2017_DW, 0,
                sizeof(DW_uc3_preparation1_2017_T));

  {
    /* user code (Initialize function Header) */

    /* System '<Root>' */
    *c_cycle_freq = 1000;

    /* InitializeConditions for UnitDelay: '<S21>/Unit Delay1' */
    uc3_preparation1_2017_DW.UnitDelay1_DSTATE =
      uc3_preparation1_2017_P.UnitDelay1_InitialCondition;

    /* SystemInitialize for MATLAB Function: '<S5>/RT_CPU' */
    uc3_preparation1_2017_DW.cc0_not_empty = false;
    memset(&uc3_preparation1_2017_DW.cc0[0], 0, 387U * sizeof(real32_T));
    uc3_preparation1_2017_DW.i0 = 0.0F;

    /* SystemInitialize for Atomic SubSystem: '<S5>/Counter' */
    /* Chart: '<S6>/Chart' */
    /* Entry: CandHDL_c/cgenerate/Subsystem/Counter/Chart */
    /* Entry Internal: CandHDL_c/cgenerate/Subsystem/Counter/Chart */
    /* Transition: '<S10>:42' */
    uc3_preparation1_2017_DW.is_c1_uc3_preparation1_2017 =
      uc3_preparation1_2017_IN_state1;

    /* Entry 'state1': '<S10>:41' */
    uc3_preparation1_2017_B.counter = 0.0F;

    /* End of SystemInitialize for SubSystem: '<S5>/Counter' */
  }

  {
  }
}

/* Model terminate function */
void uc3_preparation1_2017_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
