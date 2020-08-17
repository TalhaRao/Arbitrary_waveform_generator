/*
 * RT_CPU_sf.c
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

#include <math.h>
#include "RT_CPU_sf.h"
#include "RT_CPU_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *RT_CPU_malloc(SimStruct *S);

#endif

#ifndef __RTW_UTFREE__
#if defined (MATLAB_MEX_FILE)

extern void * utMalloc(size_t);
extern void utFree(void *);

#endif
#endif                                 /* #ifndef __RTW_UTFREE__ */

/* Forward declaration for local functions */
static void RT_CPU_linspace(real32_T n1, real_T y_data[], int32_T y_size[2]);
static void RT_CPU_sin(real32_T x_data[], int32_T x_size[2]);
static void RT_CPU_factorial(real32_T *n);
static real32_T RT_CPU_rt_powf_snf(real32_T u0, real32_T u1);

#if defined(MATLAB_MEX_FILE)
#include "rt_nonfinite.c"
#endif

static const char_T *RT_MEMORY_ALLOCATION_ERROR =
  "memory allocation error in generated S-Function";

/* Function for MATLAB Function: '<Root>/RT_CPU' */
static void RT_CPU_linspace(real32_T n1, real_T y_data[], int32_T y_size[2])
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
static void RT_CPU_sin(real32_T x_data[], int32_T x_size[2])
{
  int32_T k;
  for (k = 0; k < x_size[1]; k++) {
    x_data[k] = (real32_T)sin(x_data[k]);
  }
}

/* Function for MATLAB Function: '<Root>/RT_CPU' */
static void RT_CPU_factorial(real32_T *n)
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

static real32_T RT_CPU_rt_powf_snf(real32_T u0, real32_T u1)
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

/* System initialize for root system: '<Root>' */
#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  if (ssIsFirstInitCond(S)) {
    /* SystemInitialize for MATLAB Function: '<Root>/RT_CPU' */
    ((boolean_T *)ssGetDWork(S, 5))[0] = false;
  } else {                             /* SystemReset for MATLAB Function: '<Root>/RT_CPU' */
    ((boolean_T *)ssGetDWork(S, 5))[0] = false;
  }
}

/* Start for root system: '<Root>' */
#define MDL_START

static void mdlStart(SimStruct *S)
{
  /* instance underlying S-Function data */
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  if defined(MATLAB_MEX_FILE)

  /* non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

#  endif

  RT_CPU_malloc(S);
  if (ssGetErrorStatus(S) != (NULL) ) {
    return;
  }

#endif

  {
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
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
  int32_T i;
  int32_T loop_ub;
  real32_T y_data_0[259];
  int32_T i_0;
  int32_T x_size[2];
  int32_T tmp_size[2];
  int32_T tmp_size_0[2];
  int32_T x1_size_idx_1;
  int32_T y_size_idx_1;
  int32_T loop_ub_tmp;

  /* MATLAB Function: '<Root>/RT_CPU' */
  /* MATLAB Function 'RT_CPU': '<S1>:1' */
  /* '<S1>:1:65' */
  /* '<S1>:1:77' */
  if (!((boolean_T *)ssGetDWork(S, 5))[0]) {
    /* '<S1>:1:15' */
    /* '<S1>:1:16' */
    (*(emxArray_real32_T_256x3_RT_CP_T *)ssGetDWork(S, 0)).size[0] = 101;
    (*(emxArray_real32_T_256x3_RT_CP_T *)ssGetDWork(S, 0)).size[1] = 3;
    memset(&(*(emxArray_real32_T_256x3_RT_CP_T *)ssGetDWork(S, 0)).data[0], 0,
           303U * sizeof(real32_T));
    ((boolean_T *)ssGetDWork(S, 5))[0] = true;

    /* '<S1>:1:17' */
    (*(emxArray_real32_T_1x255_RT_CP_T *)ssGetDWork(S, 1)).size[0] = 1;
    (*(emxArray_real32_T_1x255_RT_CP_T *)ssGetDWork(S, 1)).size[1] = 101;
    memset(&(*(emxArray_real32_T_1x255_RT_CP_T *)ssGetDWork(S, 1)).data[0], 0,
           101U * sizeof(real32_T));

    /* '<S1>:1:18' */
    ((real32_T *)ssGetDWork(S, 2))[0] = 0.0F;
  }

  if ((*((const boolean_T **)ssGetInputPortSignalPtrs(S, 0))[0]) || (((real32_T *)
        ssGetDWork(S, 2))[0] < 1.0F)) {
    /* '<S1>:1:20' */
    /* '<S1>:1:22' */
    ((real32_T *)ssGetDWork(S, 2))[0] = 1.0F;

    /* '<S1>:1:28' */
    ((int32_T *)ssGetDWork(S, 3))[0] = (int32_T)(real32_T)(*((const real32_T **)
      ssGetInputPortSignalPtrs(S, 4))[0] + 1.0F);
    ((int32_T *)ssGetDWork(S, 3))[1] = 3;
    loop_ub = (int32_T)(real32_T)(*((const real32_T **)ssGetInputPortSignalPtrs
      (S, 4))[0] + 1.0F) * 3;
    if (0 <= loop_ub - 1) {
      memset(&rtb_cc[0], 0, loop_ub * sizeof(real32_T));
    }

    /* '<S1>:1:29' */
    (*(emxArray_real32_T_1x255_RT_CP_T *)ssGetDWork(S, 1)).size[0] = 1;
    (*(emxArray_real32_T_1x255_RT_CP_T *)ssGetDWork(S, 1)).size[1] = (int32_T)
      (real32_T)(*((const real32_T **)ssGetInputPortSignalPtrs(S, 4))[0] + 1.0F);
    loop_ub_tmp = (int32_T)(real32_T)(*((const real32_T **)
      ssGetInputPortSignalPtrs(S, 4))[0] + 1.0F) - 1;
    if (0 <= loop_ub_tmp) {
      memset(&(*(emxArray_real32_T_1x255_RT_CP_T *)ssGetDWork(S, 1)).data[0], 0,
             (loop_ub_tmp + 1) * sizeof(real32_T));
    }

    /* '<S1>:1:30' */
    tf = 1.0F / *((const real32_T **)ssGetInputPortSignalPtrs(S, 6))[0];

    /* '<S1>:1:32' */
    RT_CPU_linspace((real32_T)(*((const real32_T **)ssGetInputPortSignalPtrs(S,
      4))[0] + 1.0F), tmp_data, tmp_size_0);
    x_size[1] = tmp_size_0[1];
    loop_ub = tmp_size_0[0] * tmp_size_0[1];
    for (i = 0; i < loop_ub; i++) {
      x_data[i] = (real32_T)tmp_data[i];
    }

    /* '<S1>:1:33' */
    RT_CPU_linspace(*((const real32_T **)ssGetInputPortSignalPtrs(S, 4))[0],
                    tmp_data, tmp_size);
    x1_size_idx_1 = tmp_size[1];
    loop_ub = tmp_size[0] * tmp_size[1];
    for (i = 0; i < loop_ub; i++) {
      x1_data[i] = (real32_T)tmp_data[i];
    }

    switch ((int32_T)*((const real32_T **)ssGetInputPortSignalPtrs(S, 2))[0]) {
     case 0:
      /* '<S1>:1:38' */
      x_size[0] = 1;
      loop_ub = tmp_size_0[1] - 1;
      for (i = 0; i <= loop_ub; i++) {
        x_data[i] *= 6.28318548F;
      }

      RT_CPU_sin(x_data, x_size);
      y_size_idx_1 = x_size[1];
      loop_ub = x_size[0] * x_size[1] - 1;
      for (i = 0; i <= loop_ub; i++) {
        y_data[i] = *((const real32_T **)ssGetInputPortSignalPtrs(S, 1))[0] *
          x_data[i];
      }
      break;

     case 1:
      /* '<S1>:1:42' */
      y_size_idx_1 = tmp_size_0[1];
      loop_ub = tmp_size_0[1] - 1;
      for (i = 0; i <= loop_ub; i++) {
        y_data[i] = (real32_T)(x_data[i] < *((const real32_T **)
          ssGetInputPortSignalPtrs(S, 3))[0]) * *((const real32_T **)
          ssGetInputPortSignalPtrs(S, 1))[0] + (real32_T)(x_data[i] >= *((const
          real32_T **)ssGetInputPortSignalPtrs(S, 3))[0]) * -*((const real32_T **)
          ssGetInputPortSignalPtrs(S, 1))[0];
      }

      /* '<S1>:1:43' */
      y_data[loop_ub_tmp] = *((const real32_T **)ssGetInputPortSignalPtrs(S, 1))
        [0];
      break;

     case 2:
      if ((*((const real32_T **)ssGetInputPortSignalPtrs(S, 3))[0] == 0.0F) || (*
           ((const real32_T **)ssGetInputPortSignalPtrs(S, 3))[0] == 1.0F)) {
        /* '<S1>:1:47' */
        /* '<S1>:1:49' */
        loop_ub = tmp_size[1] - 1;
        i = (*((const real32_T **)ssGetInputPortSignalPtrs(S, 3))[0] == 1.0F);
        y_size_idx_1 = (*((const real32_T **)ssGetInputPortSignalPtrs(S, 3))[0] ==
                        0.0F);
        for (i_0 = 0; i_0 <= loop_ub; i_0++) {
          y_data[i_0] = ((1.0F - x1_data[i_0]) * *((const real32_T **)
            ssGetInputPortSignalPtrs(S, 1))[0] * 2.0F + -*((const real32_T **)
            ssGetInputPortSignalPtrs(S, 1))[0]) * (real32_T)y_size_idx_1 +
            (x1_data[i_0] * *((const real32_T **)ssGetInputPortSignalPtrs(S, 1))
             [0] * 2.0F + -*((const real32_T **)ssGetInputPortSignalPtrs(S, 1))
             [0]) * (real32_T)i;
        }

        /* '<S1>:1:51' */
        y_size_idx_1 = tmp_size[1] + 1;
        for (i = 0; i < x1_size_idx_1; i++) {
          y_data_0[i] = y_data[i];
        }

        y_data_0[tmp_size[1]] = y_data[0];
        for (i = 0; i < y_size_idx_1; i++) {
          y_data[i] = y_data_0[i];
        }
      } else {
        b_y = 2.0F / *((const real32_T **)ssGetInputPortSignalPtrs(S, 3))[0];
        c_y = 2.0F / (1.0F - *((const real32_T **)ssGetInputPortSignalPtrs(S, 3))
                      [0]);

        /* '<S1>:1:54' */
        y_size_idx_1 = tmp_size_0[1];
        loop_ub = tmp_size_0[1] - 1;
        for (i = 0; i <= loop_ub; i++) {
          y_data[i] = ((1.0F - x_data[i]) * *((const real32_T **)
            ssGetInputPortSignalPtrs(S, 1))[0] * c_y + -*((const real32_T **)
            ssGetInputPortSignalPtrs(S, 1))[0]) * (real32_T)(x_data[i] > *((
            const real32_T **)ssGetInputPortSignalPtrs(S, 3))[0]) + (x_data[i] *
            *((const real32_T **)ssGetInputPortSignalPtrs(S, 1))[0] * b_y + -*((
            const real32_T **)ssGetInputPortSignalPtrs(S, 1))[0]) * (real32_T)
            (x_data[i] <= *((const real32_T **)ssGetInputPortSignalPtrs(S, 3))[0]);
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
    for (i = 0; i < y_size_idx_1; i++) {
      yy_data[i] = y_data[i];
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
      (*(emxArray_real32_T_1x255_RT_CP_T *)ssGetDWork(S, 1)).data
        [(*(emxArray_real32_T_1x255_RT_CP_T *)ssGetDWork(S, 1)).size[0] *
        y_size_idx_1] = (real32_T)loop_ub * tf / *((const real32_T **)
        ssGetInputPortSignalPtrs(S, 4))[0];

      /* '<S1>:1:75' */
      /* '<S1>:1:76' */
      for (x1_size_idx_1 = 0; x1_size_idx_1 < (int32_T)(real32_T)(*((const
              real32_T **)ssGetInputPortSignalPtrs(S, 5))[0] + 1.0F);
           x1_size_idx_1++) {
        /* '<S1>:1:76' */
        /* '<S1>:1:77' */
        /* '<S1>:1:78' */
        b_y = (real32_T)x1_size_idx_1;
        RT_CPU_factorial(&b_y);
        i_0 = (int32_T)((real32_T)x1_size_idx_1 + 1.0F);
        rtb_cc[(i + ((int32_T *)ssGetDWork(S, 3))[0] * ((int32_T)((real32_T)
                  x1_size_idx_1 + 1.0F) - 1)) - 1] = (((yy_data[y_size_idx_1] *
          (real32_T)cfd[i_0 - 1] + yy_data[(int32_T)((real32_T)loop_ub + 2.0F) -
          1] * (real32_T)cfd[i_0 + 3]) + yy_data[(int32_T)((real32_T)loop_ub +
          3.0F) - 1] * (real32_T)cfd[i_0 + 7]) + yy_data[(int32_T)((real32_T)
          loop_ub + 4.0F) - 1] * (real32_T)cfd[i_0 + 11]) / RT_CPU_rt_powf_snf
          (tf / *((const real32_T **)ssGetInputPortSignalPtrs(S, 4))[0],
           (real32_T)x1_size_idx_1) / b_y;
      }
    }

    /* '<S1>:1:83' */
    (*(emxArray_real32_T_256x3_RT_CP_T *)ssGetDWork(S, 0)).size[0] = ((int32_T *)
      ssGetDWork(S, 3))[0];
    (*(emxArray_real32_T_256x3_RT_CP_T *)ssGetDWork(S, 0)).size[1] = ((int32_T *)
      ssGetDWork(S, 3))[1];
    loop_ub = ((int32_T *)ssGetDWork(S, 3))[0] * ((int32_T *)ssGetDWork(S, 3))[1]
      - 1;
    for (i = 0; i <= loop_ub; i++) {
      (*(emxArray_real32_T_256x3_RT_CP_T *)ssGetDWork(S, 0)).data[i] = rtb_cc[i];
    }

    ((boolean_T *)ssGetDWork(S, 5))[0] = !((*(emxArray_real32_T_256x3_RT_CP_T *)
      ssGetDWork(S, 0)).size[0] == 0);

    /* '<S1>:1:84' */
  } else {
    /* '<S1>:1:87' */
    ((int32_T *)ssGetDWork(S, 3))[0] = (*(emxArray_real32_T_256x3_RT_CP_T *)
      ssGetDWork(S, 0)).size[0];
    ((int32_T *)ssGetDWork(S, 3))[1] = (*(emxArray_real32_T_256x3_RT_CP_T *)
      ssGetDWork(S, 0)).size[1];
    loop_ub = (*(emxArray_real32_T_256x3_RT_CP_T *)ssGetDWork(S, 0)).size[0] * (*
      (emxArray_real32_T_256x3_RT_CP_T *)ssGetDWork(S, 0)).size[1];
    for (i = 0; i < loop_ub; i++) {
      rtb_cc[i] = (*(emxArray_real32_T_256x3_RT_CP_T *)ssGetDWork(S, 0)).data[i];
    }

    /* '<S1>:1:88' */
  }

  ((int32_T *)ssGetDWork(S, 4))[0] = (*(emxArray_real32_T_1x255_RT_CP_T *)
    ssGetDWork(S, 1)).size[0];
  ((int32_T *)ssGetDWork(S, 4))[1] = (*(emxArray_real32_T_1x255_RT_CP_T *)
    ssGetDWork(S, 1)).size[1];
  loop_ub = (*(emxArray_real32_T_1x255_RT_CP_T *)ssGetDWork(S, 1)).size[0] *
    (*(emxArray_real32_T_1x255_RT_CP_T *)ssGetDWork(S, 1)).size[1];
  for (i = 0; i < loop_ub; i++) {
    rtb_b[i] = (*(emxArray_real32_T_1x255_RT_CP_T *)ssGetDWork(S, 1)).data[i];
  }

  /* End of MATLAB Function: '<Root>/RT_CPU' */

  /* Outport: '<Root>/cc' */
  ((int32_T *)&ssGetCurrentOutputPortDimensions(S, 0, 0))[0] = ((int32_T *)
    ssGetDWork(S, 3))[0];
  ((int32_T *)&ssGetCurrentOutputPortDimensions(S, 0, 0))[1] = ((int32_T *)
    ssGetDWork(S, 3))[1];
  loop_ub = ((int32_T *)ssGetDWork(S, 3))[0] * ((int32_T *)ssGetDWork(S, 3))[1];
  for (i = 0; i < loop_ub; i++) {
    ((real32_T *)ssGetOutputPortSignal(S, 0))[i] = rtb_cc[i];
  }

  /* End of Outport: '<Root>/cc' */

  /* Outport: '<Root>/b' */
  ((int32_T *)&ssGetCurrentOutputPortDimensions(S, 1, 0))[0] = ((int32_T *)
    ssGetDWork(S, 4))[0];
  ((int32_T *)&ssGetCurrentOutputPortDimensions(S, 1, 0))[1] = ((int32_T *)
    ssGetDWork(S, 4))[1];
  loop_ub = ((int32_T *)ssGetDWork(S, 4))[0] * ((int32_T *)ssGetDWork(S, 4))[1];
  for (i = 0; i < loop_ub; i++) {
    ((real32_T *)ssGetOutputPortSignal(S, 1))[i] = rtb_b[i];
  }

  /* End of Outport: '<Root>/b' */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  UNUSED_PARAMETER(tid);
}

/* Termination for root system: '<Root>' */
static void mdlTerminate(SimStruct *S)
{

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

  if (ssGetUserData(S) != (NULL) ) {
    rt_FREE(ssGetLocalBlockIO(S));
  }

  rt_FREE(ssGetUserData(S));

#endif

}

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "RT_CPU_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 1);           /* Number of sample times */
  ssSetNumContStates(S, 0);            /* Number of continuous states */
  ssSetNumNonsampledZCs(S, 0);         /* Number of nonsampled ZCs */

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 2))
    return;

  /* outport number: 0 */
  ssSetOutputPortDimensionsMode(S, 0, VARIABLE_DIMS_MODE);
  if (!ssSetOutputPortMatrixDimensions(S, 0, 256, 4))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 0, SS_SINGLE);
  }

  ssSetOutputPortSampleTime(S, 0, 0.0001);
  ssSetOutputPortOffsetTime(S, 0, 0.0);
  ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

  /* outport number: 1 */
  ssSetOutputPortDimensionsMode(S, 1, VARIABLE_DIMS_MODE);
  if (!ssSetOutputPortMatrixDimensions(S, 1, 1, 255))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 1, SS_SINGLE);
  }

  ssSetOutputPortSampleTime(S, 1, 0.0001);
  ssSetOutputPortOffsetTime(S, 1, 0.0);
  ssSetOutputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 7))
    return;

  /* inport number: 0 */
  {
    if (!ssSetInputPortVectorDimension(S, 0, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 0, SS_BOOLEAN);
    }

    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortSampleTime(S, 0, 0.0001);
    ssSetInputPortOffsetTime(S, 0, 0.0);
    ssSetInputPortOverWritable(S, 0, 0);
    ssSetInputPortOptimOpts(S, 0, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 1 */
  {
    if (!ssSetInputPortVectorDimension(S, 1, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 1, SS_SINGLE);
    }

    ssSetInputPortDirectFeedThrough(S, 1, 1);
    ssSetInputPortSampleTime(S, 1, 0.0001);
    ssSetInputPortOffsetTime(S, 1, 0.0);
    ssSetInputPortOverWritable(S, 1, 0);
    ssSetInputPortOptimOpts(S, 1, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 2 */
  {
    if (!ssSetInputPortVectorDimension(S, 2, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 2, SS_SINGLE);
    }

    ssSetInputPortDirectFeedThrough(S, 2, 1);
    ssSetInputPortSampleTime(S, 2, 0.0001);
    ssSetInputPortOffsetTime(S, 2, 0.0);
    ssSetInputPortOverWritable(S, 2, 0);
    ssSetInputPortOptimOpts(S, 2, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 3 */
  {
    if (!ssSetInputPortVectorDimension(S, 3, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 3, SS_SINGLE);
    }

    ssSetInputPortDirectFeedThrough(S, 3, 1);
    ssSetInputPortSampleTime(S, 3, 0.0001);
    ssSetInputPortOffsetTime(S, 3, 0.0);
    ssSetInputPortOverWritable(S, 3, 0);
    ssSetInputPortOptimOpts(S, 3, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 4 */
  {
    if (!ssSetInputPortVectorDimension(S, 4, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 4, SS_SINGLE);
    }

    ssSetInputPortDirectFeedThrough(S, 4, 1);
    ssSetInputPortSampleTime(S, 4, 0.0001);
    ssSetInputPortOffsetTime(S, 4, 0.0);
    ssSetInputPortOverWritable(S, 4, 0);
    ssSetInputPortOptimOpts(S, 4, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 5 */
  {
    if (!ssSetInputPortVectorDimension(S, 5, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 5, SS_SINGLE);
    }

    ssSetInputPortDirectFeedThrough(S, 5, 1);
    ssSetInputPortSampleTime(S, 5, 0.0001);
    ssSetInputPortOffsetTime(S, 5, 0.0);
    ssSetInputPortOverWritable(S, 5, 0);
    ssSetInputPortOptimOpts(S, 5, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 6 */
  {
    if (!ssSetInputPortVectorDimension(S, 6, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 6, SS_SINGLE);
    }

    ssSetInputPortDirectFeedThrough(S, 6, 1);
    ssSetInputPortSampleTime(S, 6, 0.0001);
    ssSetInputPortOffsetTime(S, 6, 0.0);
    ssSetInputPortOverWritable(S, 6, 0);
    ssSetInputPortOptimOpts(S, 6, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* DWork */
  if (!ssSetNumDWork(S, 6)) {
    return;
  }

  /* '<Root>/RT_CPU': DWORK1 */
  ssSetDWorkName(S, 0, "DWORK0");
  ssSetDWorkWidth(S, 0, 1);

#if SS_SFCN_FOR_SIM

  {
    int id = ssRegisterDataType(S, "emxArray_real32_T_256x3_RT_CP_T");
    if (id == INVALID_DTYPE_ID )
      return;
    if (!ssSetDataTypeSize(S, id, sizeof(emxArray_real32_T_256x3_RT_CP_T)))
      return;
    ssSetDWorkDataType(S, 0, id);
  }

#endif

  /* '<Root>/RT_CPU': DWORK3 */
  ssSetDWorkName(S, 1, "DWORK1");
  ssSetDWorkWidth(S, 1, 1);

#if SS_SFCN_FOR_SIM

  {
    int id = ssRegisterDataType(S, "emxArray_real32_T_1x255_RT_CP_T");
    if (id == INVALID_DTYPE_ID )
      return;
    if (!ssSetDataTypeSize(S, id, sizeof(emxArray_real32_T_1x255_RT_CP_T)))
      return;
    ssSetDWorkDataType(S, 1, id);
  }

#endif

  /* '<Root>/RT_CPU': DWORK4 */
  ssSetDWorkName(S, 2, "DWORK2");
  ssSetDWorkWidth(S, 2, 1);
  ssSetDWorkDataType(S, 2, SS_SINGLE);

  /* '<Root>/RT_CPU': DWORK5 */
  ssSetDWorkName(S, 3, "DWORK3");
  ssSetDWorkWidth(S, 3, 2);
  ssSetDWorkDataType(S, 3, SS_INT32);

  /* '<Root>/RT_CPU': DWORK6 */
  ssSetDWorkName(S, 4, "DWORK4");
  ssSetDWorkWidth(S, 4, 2);
  ssSetDWorkDataType(S, 4, SS_INT32);

  /* '<Root>/RT_CPU': DWORK2 */
  ssSetDWorkName(S, 5, "DWORK5");
  ssSetDWorkWidth(S, 5, 1);
  ssSetDWorkDataType(S, 5, SS_BOOLEAN);

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 0);

  /* Number of expected parameters */
#if defined(MATLAB_MEX_FILE)

  if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {

#if defined(MDL_CHECK_PARAMETERS)

    mdlCheckParameters(S);

#endif                                 /* MDL_CHECK_PARAMETERS */

    if (ssGetErrorStatus(S) != (NULL) ) {
      return;
    }
  } else {
    return;                            /* Parameter mismatch will be reported by Simulink */
  }

#endif                                 /* MATLAB_MEX_FILE */

  /* Options */
  ssSetOptions(S, (SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE |
                   SS_OPTION_PORT_SAMPLE_TIMES_ASSIGNED ));

#if SS_SFCN_FOR_SIM

  {
    ssSupportsMultipleExecInstances(S, false);
    ssRegisterMsgForNotSupportingMultiExecInst(S,
      "<diag_root><diag id=\"Simulink:blocks:ImplicitIterSS_VariableDimsSigNotSupportedInside\" pr=\"d\"><arguments><arg type=\"encoded\">PABfAF8AaQBpAFMAUwBfAF8APgA8AC8AXwBfAGkAaQBTAFMAXwBfAD4AAAA=</arg><arg type=\"encoded\">PABfAF8AaQB0AGUAcgBCAGwAawBfAF8APgA8AC8AXwBfAGkAdABlAHIAQgBsAGsAXwBfAD4AAAA=</arg><arg type=\"numeric\">1</arg><arg type=\"encoded\">UgBUAF8AQwBQAFUALwBSAFQAXwBDAFAAVQAAAA==</arg></arguments><hs><h>AAAAgABAhED+</h></hs></diag></diag_root>");
    ssHasStateInsideForEachSS(S, false);
  }

#endif

}

/* Function to initialize sample times. */
static void mdlInitializeSampleTimes(SimStruct *S)
{
  /* task periods */
  ssSetSampleTime(S, 0, 0.0001);

  /* task offsets */
  ssSetOffsetTime(S, 0, 0.0);
}

#if defined(MATLAB_MEX_FILE)
# include "fixedpoint.c"
# include "simulink.c"
#else
# undef S_FUNCTION_NAME
# define S_FUNCTION_NAME               RT_CPU_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
