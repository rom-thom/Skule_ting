/*
 * heli_q8_lab2.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_q8_lab2".
 *
 * Model version              : 11.5
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Sep 21 19:57:10 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "heli_q8_lab2.h"
#include "heli_q8_lab2_private.h"
#include "heli_q8_lab2_dt.h"

/* Block signals (default storage) */
B_heli_q8_lab2_T heli_q8_lab2_B;

/* Continuous states */
X_heli_q8_lab2_T heli_q8_lab2_X;

/* Block states (default storage) */
DW_heli_q8_lab2_T heli_q8_lab2_DW;

/* Real-time model */
static RT_MODEL_heli_q8_lab2_T heli_q8_lab2_M_;
RT_MODEL_heli_q8_lab2_T *const heli_q8_lab2_M = &heli_q8_lab2_M_;
static void rate_monotonic_scheduler(void);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(heli_q8_lab2_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(heli_q8_lab2_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (heli_q8_lab2_M->Timing.TaskCounters.TID[1] == 0) {
    heli_q8_lab2_M->Timing.RateInteraction.TID1_2 =
      (heli_q8_lab2_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    heli_q8_lab2_M->Timing.perTaskSampleHits[5] =
      heli_q8_lab2_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (heli_q8_lab2_M->Timing.TaskCounters.TID[2])++;
  if ((heli_q8_lab2_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    heli_q8_lab2_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  heli_q8_lab2_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void heli_q8_lab2_output0(void)        /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_TmpSignalConversionAtToFile[8];
  real_T rtb_DeadZoney;
  real_T tmp[5];
  real_T rtb_u[2];
  real_T tmp_0[2];
  real_T rtb_Backgain;
  real_T rtb_Frontgain;
  real_T tmp_1;
  real_T tmp_2;
  real_T tmp_3;
  int32_T i;
  int32_T i_0;
  if (rtmIsMajorTimeStep(heli_q8_lab2_M)) {
    /* set solver stop time */
    if (!(heli_q8_lab2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&heli_q8_lab2_M->solverInfo,
                            ((heli_q8_lab2_M->Timing.clockTickH0 + 1) *
        heli_q8_lab2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&heli_q8_lab2_M->solverInfo,
                            ((heli_q8_lab2_M->Timing.clockTick0 + 1) *
        heli_q8_lab2_M->Timing.stepSize0 + heli_q8_lab2_M->Timing.clockTickH0 *
        heli_q8_lab2_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(heli_q8_lab2_M)) {
    heli_q8_lab2_M->Timing.t[0] = rtsiGetT(&heli_q8_lab2_M->solverInfo);
  }

  /* RateTransition: '<S6>/Rate Transition: x' */
  if (rtmIsMajorTimeStep(heli_q8_lab2_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S5>/HIL Read Encoder Timebase' */

    /* S-Function Block: heli_q8_lab2/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(heli_q8_lab2_DW.HILReadEncoderTimebase_Task,
        1, &heli_q8_lab2_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_lab2_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          heli_q8_lab2_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          heli_q8_lab2_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_DeadZoney = heli_q8_lab2_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* Gain: '<S5>/Elevation: Count to rad' */
    heli_q8_lab2_B.ElevationCounttorad = heli_q8_lab2_P.ElevationCounttorad_Gain
      * rtb_DeadZoney;

    /* Sum: '<Root>/Sum1' incorporates:
     *  Constant: '<Root>/Elevation ref'
     */
    heli_q8_lab2_B.Sum1 = heli_q8_lab2_B.ElevationCounttorad -
      heli_q8_lab2_P.elev_ref;

    /* Gain: '<S5>/Pitch: Count to rad' */
    heli_q8_lab2_B.PitchCounttorad = heli_q8_lab2_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;
    if (heli_q8_lab2_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S6>/Rate Transition: x' */
      heli_q8_lab2_B.RateTransitionx = heli_q8_lab2_DW.RateTransitionx_Buffer0;
    }

    /* DeadZone: '<S6>/Dead Zone: x' */
    if (heli_q8_lab2_B.RateTransitionx > heli_q8_lab2_P.DeadZonex_End) {
      /* DeadZone: '<S6>/Dead Zone: y' */
      rtb_DeadZoney = heli_q8_lab2_B.RateTransitionx -
        heli_q8_lab2_P.DeadZonex_End;
    } else if (heli_q8_lab2_B.RateTransitionx >= heli_q8_lab2_P.DeadZonex_Start)
    {
      /* DeadZone: '<S6>/Dead Zone: y' */
      rtb_DeadZoney = 0.0;
    } else {
      /* DeadZone: '<S6>/Dead Zone: y' */
      rtb_DeadZoney = heli_q8_lab2_B.RateTransitionx -
        heli_q8_lab2_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S6>/Dead Zone: x' */

    /* Gain: '<S6>/Joystick_gain_x' incorporates:
     *  Gain: '<S6>/Gain: x'
     */
    heli_q8_lab2_B.Joystick_gain_x = heli_q8_lab2_P.Gainx_Gain * rtb_DeadZoney *
      heli_q8_lab2_P.Joystick_gain_x;
  }

  /* End of RateTransition: '<S6>/Rate Transition: x' */

  /* Step: '<S1>/30s +1' incorporates:
   *  Step: '<S1>/35s -1'
   *  Step: '<S1>/40s -1'
   *  Step: '<S1>/45s +1'
   *  Step: '<S2>/10s +1'
   *  Step: '<S2>/15s -1'
   *  Step: '<S2>/20s -1'
   *  Step: '<S2>/25s +1'
   */
  rtb_Backgain = heli_q8_lab2_M->Timing.t[0];
  if (rtb_Backgain < heli_q8_lab2_P.u0s1_Time) {
    rtb_Frontgain = heli_q8_lab2_P.u0s1_Y0;
  } else {
    rtb_Frontgain = heli_q8_lab2_P.u0s1_YFinal;
  }

  /* End of Step: '<S1>/30s +1' */

  /* Step: '<S1>/35s -1' */
  if (rtb_Backgain < heli_q8_lab2_P.u5s1_Time) {
    tmp_1 = heli_q8_lab2_P.u5s1_Y0;
  } else {
    tmp_1 = heli_q8_lab2_P.u5s1_YFinal;
  }

  /* Step: '<S1>/40s -1' */
  if (rtb_Backgain < heli_q8_lab2_P.u0s1_Time_c) {
    tmp_2 = heli_q8_lab2_P.u0s1_Y0_e;
  } else {
    tmp_2 = heli_q8_lab2_P.u0s1_YFinal_a;
  }

  /* Step: '<S1>/45s +1' */
  if (rtb_Backgain < heli_q8_lab2_P.u5s1_Time_k) {
    tmp_3 = heli_q8_lab2_P.u5s1_Y0_p;
  } else {
    tmp_3 = heli_q8_lab2_P.u5s1_YFinal_o;
  }

  /* Sum: '<Root>/Sum3' incorporates:
   *  Gain: '<S1>/Gain'
   *  Sum: '<S1>/Add'
   */
  heli_q8_lab2_B.Sum3 = (((rtb_Frontgain + tmp_1) + tmp_2) + tmp_3) *
    heli_q8_lab2_P.Gain_Gain + heli_q8_lab2_B.Joystick_gain_x;

  /* RateTransition: '<S6>/Rate Transition: y' */
  if (rtmIsMajorTimeStep(heli_q8_lab2_M)) {
    if (heli_q8_lab2_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S6>/Rate Transition: y' */
      heli_q8_lab2_B.RateTransitiony = heli_q8_lab2_DW.RateTransitiony_Buffer0;
    }

    /* DeadZone: '<S6>/Dead Zone: y' */
    if (heli_q8_lab2_B.RateTransitiony > heli_q8_lab2_P.DeadZoney_End) {
      /* DeadZone: '<S6>/Dead Zone: y' */
      rtb_DeadZoney = heli_q8_lab2_B.RateTransitiony -
        heli_q8_lab2_P.DeadZoney_End;
    } else if (heli_q8_lab2_B.RateTransitiony >= heli_q8_lab2_P.DeadZoney_Start)
    {
      /* DeadZone: '<S6>/Dead Zone: y' */
      rtb_DeadZoney = 0.0;
    } else {
      /* DeadZone: '<S6>/Dead Zone: y' */
      rtb_DeadZoney = heli_q8_lab2_B.RateTransitiony -
        heli_q8_lab2_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S6>/Dead Zone: y' */

    /* Gain: '<S6>/Joystick_gain_y' incorporates:
     *  Gain: '<S6>/Gain: y'
     */
    heli_q8_lab2_B.Joystick_gain_y = heli_q8_lab2_P.Gainy_Gain * rtb_DeadZoney *
      heli_q8_lab2_P.Joystick_gain_y;
  }

  /* End of RateTransition: '<S6>/Rate Transition: y' */

  /* Step: '<S2>/10s +1' */
  if (rtb_Backgain < heli_q8_lab2_P.u0s1_Time_a) {
    rtb_Frontgain = heli_q8_lab2_P.u0s1_Y0_f;
  } else {
    rtb_Frontgain = heli_q8_lab2_P.u0s1_YFinal_o;
  }

  /* Step: '<S2>/15s -1' */
  if (rtb_Backgain < heli_q8_lab2_P.u5s1_Time_j) {
    tmp_1 = heli_q8_lab2_P.u5s1_Y0_m;
  } else {
    tmp_1 = heli_q8_lab2_P.u5s1_YFinal_k;
  }

  /* Step: '<S2>/20s -1' */
  if (rtb_Backgain < heli_q8_lab2_P.u0s1_Time_p) {
    tmp_2 = heli_q8_lab2_P.u0s1_Y0_g;
  } else {
    tmp_2 = heli_q8_lab2_P.u0s1_YFinal_oh;
  }

  /* Step: '<S2>/25s +1' */
  if (rtb_Backgain < heli_q8_lab2_P.u5s1_Time_i) {
    rtb_Backgain = heli_q8_lab2_P.u5s1_Y0_n;
  } else {
    rtb_Backgain = heli_q8_lab2_P.u5s1_YFinal_a;
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  Gain: '<S2>/0.07'
   *  Sum: '<Root>/Sum2'
   *  Sum: '<S2>/Add'
   */
  heli_q8_lab2_B.Gain = ((((rtb_Frontgain + tmp_1) + tmp_2) + rtb_Backgain) *
    heli_q8_lab2_P.u07_Gain - heli_q8_lab2_B.Joystick_gain_y) *
    heli_q8_lab2_P.Gain_Gain_b;
  if (rtmIsMajorTimeStep(heli_q8_lab2_M)) {
    /* Gain: '<S5>/Travel: Count to rad' */
    heli_q8_lab2_B.TravelCounttorad = heli_q8_lab2_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;
  }

  /* TransferFcn: '<S5>/Travel: Transfer Fcn' */
  heli_q8_lab2_B.TravelTransferFcn = 0.0;
  heli_q8_lab2_B.TravelTransferFcn += heli_q8_lab2_P.TravelTransferFcn_C *
    heli_q8_lab2_X.TravelTransferFcn_CSTATE;
  heli_q8_lab2_B.TravelTransferFcn += heli_q8_lab2_P.TravelTransferFcn_D *
    heli_q8_lab2_B.TravelCounttorad;

  /* TransferFcn: '<S5>/Pitch: Transfer Fcn' */
  heli_q8_lab2_B.PitchTransferFcn = 0.0;
  heli_q8_lab2_B.PitchTransferFcn += heli_q8_lab2_P.PitchTransferFcn_C *
    heli_q8_lab2_X.PitchTransferFcn_CSTATE;
  heli_q8_lab2_B.PitchTransferFcn += heli_q8_lab2_P.PitchTransferFcn_D *
    heli_q8_lab2_B.PitchCounttorad;

  /* TransferFcn: '<S5>/Elevation: Transfer Fcn' */
  heli_q8_lab2_B.ElevationTransferFcn = 0.0;
  heli_q8_lab2_B.ElevationTransferFcn += heli_q8_lab2_P.ElevationTransferFcn_C *
    heli_q8_lab2_X.ElevationTransferFcn_CSTATE;
  heli_q8_lab2_B.ElevationTransferFcn += heli_q8_lab2_P.ElevationTransferFcn_D *
    heli_q8_lab2_B.ElevationCounttorad;
  if (rtmIsMajorTimeStep(heli_q8_lab2_M)) {
    /* SignalConversion generated from: '<Root>/To File' */
    rtb_TmpSignalConversionAtToFile[0] = heli_q8_lab2_B.Sum3;
    rtb_TmpSignalConversionAtToFile[1] = heli_q8_lab2_B.Gain;
    rtb_TmpSignalConversionAtToFile[2] = heli_q8_lab2_B.TravelCounttorad;
    rtb_TmpSignalConversionAtToFile[3] = heli_q8_lab2_B.TravelTransferFcn;
    rtb_TmpSignalConversionAtToFile[4] = heli_q8_lab2_B.PitchCounttorad;
    rtb_TmpSignalConversionAtToFile[5] = heli_q8_lab2_B.PitchTransferFcn;
    rtb_TmpSignalConversionAtToFile[6] = heli_q8_lab2_B.Sum1;
    rtb_TmpSignalConversionAtToFile[7] = heli_q8_lab2_B.ElevationTransferFcn;

    /* ToFile: '<Root>/To File' */
    if (rtmIsMajorTimeStep(heli_q8_lab2_M)) {
      if (rtmIsMajorTimeStep(heli_q8_lab2_M) ) {
        {
          if (!(++heli_q8_lab2_DW.ToFile_IWORK.Decimation % 1) &&
              (heli_q8_lab2_DW.ToFile_IWORK.Count * (8 + 1)) + 1 < 100000000 ) {
            FILE *fp = (FILE *) heli_q8_lab2_DW.ToFile_PWORK.FilePtr;
            if (fp != (NULL)) {
              real_T u[8 + 1];
              heli_q8_lab2_DW.ToFile_IWORK.Decimation = 0;
              u[0] = heli_q8_lab2_M->Timing.t[1];
              u[1] = rtb_TmpSignalConversionAtToFile[0];
              u[2] = rtb_TmpSignalConversionAtToFile[1];
              u[3] = rtb_TmpSignalConversionAtToFile[2];
              u[4] = rtb_TmpSignalConversionAtToFile[3];
              u[5] = rtb_TmpSignalConversionAtToFile[4];
              u[6] = rtb_TmpSignalConversionAtToFile[5];
              u[7] = rtb_TmpSignalConversionAtToFile[6];
              u[8] = rtb_TmpSignalConversionAtToFile[7];
              if (fwrite(u, sizeof(real_T), 8 + 1, fp) != 8 + 1) {
                rtmSetErrorStatus(heli_q8_lab2_M,
                                  "Error writing to MAT-file LQR_q3_10_elevation_rate_focus.mat");
                return;
              }

              if (((++heli_q8_lab2_DW.ToFile_IWORK.Count) * (8 + 1))+1 >=
                  100000000) {
                (void)fprintf(stdout,
                              "*** The ToFile block will stop logging data before\n"
                              "    the simulation has ended, because it has reached\n"
                              "    the maximum number of elements (100000000)\n"
                              "    allowed in MAT-file LQR_q3_10_elevation_rate_focus.mat.\n");
              }
            }
          }
        }
      }
    }
  }

  /* SignalConversion generated from: '<S3>/Gain' incorporates:
   *  Sum: '<S7>/Sum'
   *  Sum: '<S7>/Sum1'
   */
  tmp[0] = heli_q8_lab2_B.PitchCounttorad;
  tmp[1] = heli_q8_lab2_B.PitchTransferFcn;
  tmp[2] = heli_q8_lab2_B.ElevationTransferFcn;
  tmp[3] = heli_q8_lab2_B.Sum3 - heli_q8_lab2_B.PitchCounttorad;
  tmp[4] = heli_q8_lab2_B.Gain - heli_q8_lab2_B.ElevationTransferFcn;
  for (i = 0; i < 2; i++) {
    /* Gain: '<S3>/Gain' */
    tmp_0[i] = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      tmp_0[i] += heli_q8_lab2_P.K[(i_0 << 1) + i] * tmp[i_0];
    }

    /* End of Gain: '<S3>/Gain' */

    /* Sum: '<S3>/Sum' incorporates:
     *  Gain: '<S3>/Gain1'
     *  SignalConversion generated from: '<S3>/Gain1'
     */
    rtb_u[i] = (heli_q8_lab2_P.F[i + 2] * heli_q8_lab2_B.Gain +
                heli_q8_lab2_P.F[i] * heli_q8_lab2_B.Sum3) - tmp_0[i];
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  rtb_Backgain = rtb_u[0] + heli_q8_lab2_P.V_s0;

  /* Sum: '<S4>/Add' */
  rtb_Frontgain = rtb_Backgain - rtb_u[1];

  /* Sum: '<S4>/Subtract' */
  rtb_Backgain += rtb_u[1];

  /* Gain: '<S4>/Back gain' */
  rtb_Backgain *= heli_q8_lab2_P.Backgain_Gain;

  /* Gain: '<S4>/Front gain' */
  rtb_Frontgain *= heli_q8_lab2_P.Frontgain_Gain;
  if (rtmIsMajorTimeStep(heli_q8_lab2_M)) {
  }

  /* Saturate: '<S5>/Front motor: Saturation' */
  if (rtb_Frontgain > heli_q8_lab2_P.FrontmotorSaturation_UpperSat) {
    /* Saturate: '<S5>/Front motor: Saturation' */
    heli_q8_lab2_B.FrontmotorSaturation =
      heli_q8_lab2_P.FrontmotorSaturation_UpperSat;
  } else if (rtb_Frontgain < heli_q8_lab2_P.FrontmotorSaturation_LowerSat) {
    /* Saturate: '<S5>/Front motor: Saturation' */
    heli_q8_lab2_B.FrontmotorSaturation =
      heli_q8_lab2_P.FrontmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S5>/Front motor: Saturation' */
    heli_q8_lab2_B.FrontmotorSaturation = rtb_Frontgain;
  }

  /* End of Saturate: '<S5>/Front motor: Saturation' */

  /* Saturate: '<S5>/Back motor: Saturation' */
  if (rtb_Backgain > heli_q8_lab2_P.BackmotorSaturation_UpperSat) {
    /* Saturate: '<S5>/Back motor: Saturation' */
    heli_q8_lab2_B.BackmotorSaturation =
      heli_q8_lab2_P.BackmotorSaturation_UpperSat;
  } else if (rtb_Backgain < heli_q8_lab2_P.BackmotorSaturation_LowerSat) {
    /* Saturate: '<S5>/Back motor: Saturation' */
    heli_q8_lab2_B.BackmotorSaturation =
      heli_q8_lab2_P.BackmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S5>/Back motor: Saturation' */
    heli_q8_lab2_B.BackmotorSaturation = rtb_Backgain;
  }

  /* End of Saturate: '<S5>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(heli_q8_lab2_M)) {
    /* S-Function (hil_write_analog_block): '<S5>/HIL Write Analog' */

    /* S-Function Block: heli_q8_lab2/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      heli_q8_lab2_DW.HILWriteAnalog_Buffer[0] =
        heli_q8_lab2_B.FrontmotorSaturation;
      heli_q8_lab2_DW.HILWriteAnalog_Buffer[1] =
        heli_q8_lab2_B.BackmotorSaturation;
      result = hil_write_analog(heli_q8_lab2_DW.HILInitialize_Card,
        heli_q8_lab2_P.HILWriteAnalog_channels, 2,
        &heli_q8_lab2_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_lab2_M, _rt_error_message);
      }
    }
  }
}

/* Model update function for TID0 */
void heli_q8_lab2_update0(void)        /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(heli_q8_lab2_M)) {
    rt_ertODEUpdateContinuousStates(&heli_q8_lab2_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_lab2_M->Timing.clockTick0)) {
    ++heli_q8_lab2_M->Timing.clockTickH0;
  }

  heli_q8_lab2_M->Timing.t[0] = rtsiGetSolverStopTime
    (&heli_q8_lab2_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_lab2_M->Timing.clockTick1)) {
    ++heli_q8_lab2_M->Timing.clockTickH1;
  }

  heli_q8_lab2_M->Timing.t[1] = heli_q8_lab2_M->Timing.clockTick1 *
    heli_q8_lab2_M->Timing.stepSize1 + heli_q8_lab2_M->Timing.clockTickH1 *
    heli_q8_lab2_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void heli_q8_lab2_derivatives(void)
{
  XDot_heli_q8_lab2_T *_rtXdot;
  _rtXdot = ((XDot_heli_q8_lab2_T *) heli_q8_lab2_M->derivs);

  /* Derivatives for TransferFcn: '<S5>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_lab2_P.TravelTransferFcn_A *
    heli_q8_lab2_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_lab2_B.TravelCounttorad;

  /* Derivatives for TransferFcn: '<S5>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_lab2_P.PitchTransferFcn_A *
    heli_q8_lab2_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_lab2_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S5>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_lab2_P.ElevationTransferFcn_A *
    heli_q8_lab2_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_lab2_B.ElevationCounttorad;
}

/* Model output function for TID2 */
void heli_q8_lab2_output2(void)        /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_GameController_o4;
  real_T rtb_GameController_o5;

  /* S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: heli_q8_lab2/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_lab2_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(heli_q8_lab2_DW.GameController_Controller,
        &state, &new_data);
      if (result < 0) {
        new_data = false;
      }

      rtb_GameController_o4 = state.x;
      rtb_GameController_o5 = state.y;
    } else {
      rtb_GameController_o4 = 0;
      rtb_GameController_o5 = 0;
    }
  }

  /* RateTransition: '<S6>/Rate Transition: x' */
  heli_q8_lab2_DW.RateTransitionx_Buffer0 = rtb_GameController_o4;

  /* RateTransition: '<S6>/Rate Transition: y' */
  heli_q8_lab2_DW.RateTransitiony_Buffer0 = rtb_GameController_o5;
}

/* Model update function for TID2 */
void heli_q8_lab2_update2(void)        /* Sample time: [0.01s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_lab2_M->Timing.clockTick2)) {
    ++heli_q8_lab2_M->Timing.clockTickH2;
  }

  heli_q8_lab2_M->Timing.t[2] = heli_q8_lab2_M->Timing.clockTick2 *
    heli_q8_lab2_M->Timing.stepSize2 + heli_q8_lab2_M->Timing.clockTickH2 *
    heli_q8_lab2_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void heli_q8_lab2_output(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_lab2_output0();
    break;

   case 2 :
    heli_q8_lab2_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void heli_q8_lab2_update(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_lab2_update0();
    break;

   case 2 :
    heli_q8_lab2_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void heli_q8_lab2_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_lab2/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &heli_q8_lab2_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_lab2_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(heli_q8_lab2_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_lab2_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(heli_q8_lab2_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_lab2_M, _rt_error_message);
      return;
    }

    if ((heli_q8_lab2_P.HILInitialize_AIPStart && !is_switching) ||
        (heli_q8_lab2_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &heli_q8_lab2_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (heli_q8_lab2_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &heli_q8_lab2_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = heli_q8_lab2_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(heli_q8_lab2_DW.HILInitialize_Card,
        heli_q8_lab2_P.HILInitialize_AIChannels, 8U,
        &heli_q8_lab2_DW.HILInitialize_AIMinimums[0],
        &heli_q8_lab2_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_lab2_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_lab2_P.HILInitialize_AOPStart && !is_switching) ||
        (heli_q8_lab2_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &heli_q8_lab2_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (heli_q8_lab2_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &heli_q8_lab2_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = heli_q8_lab2_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(heli_q8_lab2_DW.HILInitialize_Card,
        heli_q8_lab2_P.HILInitialize_AOChannels, 8U,
        &heli_q8_lab2_DW.HILInitialize_AOMinimums[0],
        &heli_q8_lab2_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_lab2_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_lab2_P.HILInitialize_AOStart && !is_switching) ||
        (heli_q8_lab2_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_lab2_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_lab2_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(heli_q8_lab2_DW.HILInitialize_Card,
        heli_q8_lab2_P.HILInitialize_AOChannels, 8U,
        &heli_q8_lab2_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_lab2_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_lab2_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_lab2_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_lab2_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (heli_q8_lab2_DW.HILInitialize_Card,
         heli_q8_lab2_P.HILInitialize_AOChannels, 8U,
         &heli_q8_lab2_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_lab2_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_lab2_P.HILInitialize_EIPStart && !is_switching) ||
        (heli_q8_lab2_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &heli_q8_lab2_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = heli_q8_lab2_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (heli_q8_lab2_DW.HILInitialize_Card,
         heli_q8_lab2_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode
          *) &heli_q8_lab2_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_lab2_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_lab2_P.HILInitialize_EIStart && !is_switching) ||
        (heli_q8_lab2_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &heli_q8_lab2_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = heli_q8_lab2_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(heli_q8_lab2_DW.HILInitialize_Card,
        heli_q8_lab2_P.HILInitialize_EIChannels, 8U,
        &heli_q8_lab2_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_lab2_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_lab2_P.HILInitialize_POPStart && !is_switching) ||
        (heli_q8_lab2_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_q8_lab2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_lab2_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(heli_q8_lab2_DW.HILInitialize_Card,
        heli_q8_lab2_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &heli_q8_lab2_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_lab2_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          heli_q8_lab2_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &heli_q8_lab2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            heli_q8_lab2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            heli_q8_lab2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              heli_q8_lab2_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            heli_q8_lab2_DW.HILInitialize_POSortedChans[7U - num_frequency_modes]
              = (p_HILInitialize_POChannels[i1]);
            heli_q8_lab2_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes]
              = heli_q8_lab2_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(heli_q8_lab2_DW.HILInitialize_Card,
          &heli_q8_lab2_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &heli_q8_lab2_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_lab2_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(heli_q8_lab2_DW.HILInitialize_Card,
          &heli_q8_lab2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &heli_q8_lab2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_lab2_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_q8_lab2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_lab2_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &heli_q8_lab2_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = heli_q8_lab2_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &heli_q8_lab2_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = heli_q8_lab2_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(heli_q8_lab2_DW.HILInitialize_Card,
        heli_q8_lab2_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &heli_q8_lab2_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &heli_q8_lab2_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &heli_q8_lab2_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_lab2_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &heli_q8_lab2_DW.HILInitialize_POSortedFreqs
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = heli_q8_lab2_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_lab2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_lab2_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(heli_q8_lab2_DW.HILInitialize_Card,
        heli_q8_lab2_P.HILInitialize_POChannels, 8U,
        &heli_q8_lab2_DW.HILInitialize_POSortedFreqs[0],
        &heli_q8_lab2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_lab2_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_lab2_P.HILInitialize_POStart && !is_switching) ||
        (heli_q8_lab2_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_lab2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_lab2_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(heli_q8_lab2_DW.HILInitialize_Card,
        heli_q8_lab2_P.HILInitialize_POChannels, 8U,
        &heli_q8_lab2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_lab2_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_lab2_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_lab2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_lab2_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (heli_q8_lab2_DW.HILInitialize_Card,
         heli_q8_lab2_P.HILInitialize_POChannels, 8U,
         &heli_q8_lab2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_lab2_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S5>/HIL Read Encoder Timebase' */

  /* S-Function Block: heli_q8_lab2/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(heli_q8_lab2_DW.HILInitialize_Card,
      heli_q8_lab2_P.HILReadEncoderTimebase_SamplesI,
      heli_q8_lab2_P.HILReadEncoderTimebase_Channels, 3,
      &heli_q8_lab2_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (heli_q8_lab2_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (heli_q8_lab2_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_lab2_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S6>/Rate Transition: x' */
  heli_q8_lab2_B.RateTransitionx =
    heli_q8_lab2_P.RateTransitionx_InitialConditio;

  /* Start for RateTransition: '<S6>/Rate Transition: y' */
  heli_q8_lab2_B.RateTransitiony =
    heli_q8_lab2_P.RateTransitiony_InitialConditio;

  /* Start for ToFile: '<Root>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "LQR_q3_10_elevation_rate_focus.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(heli_q8_lab2_M,
                        "Error creating .mat file LQR_q3_10_elevation_rate_focus.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 8 + 1, 0, "ans")) {
      rtmSetErrorStatus(heli_q8_lab2_M,
                        "Error writing mat file header to file LQR_q3_10_elevation_rate_focus.mat");
      return;
    }

    heli_q8_lab2_DW.ToFile_IWORK.Count = 0;
    heli_q8_lab2_DW.ToFile_IWORK.Decimation = -1;
    heli_q8_lab2_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: heli_q8_lab2/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_lab2_P.GameController_Enabled) {
      t_double deadzone[6];
      t_double saturation[6];
      t_int index;
      t_error result;
      for (index = 0; index < 6; index++) {
        deadzone[index] = -1;
      }

      for (index = 0; index < 6; index++) {
        saturation[index] = -1;
      }

      result = game_controller_open
        (heli_q8_lab2_P.GameController_ControllerNumber,
         heli_q8_lab2_P.GameController_BufferSize, deadzone, saturation,
         heli_q8_lab2_P.GameController_AutoCenter, 0, 1.0,
         &heli_q8_lab2_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_lab2_M, _rt_error_message);
      }
    }
  }

  /* InitializeConditions for RateTransition: '<S6>/Rate Transition: x' */
  heli_q8_lab2_DW.RateTransitionx_Buffer0 =
    heli_q8_lab2_P.RateTransitionx_InitialConditio;

  /* InitializeConditions for RateTransition: '<S6>/Rate Transition: y' */
  heli_q8_lab2_DW.RateTransitiony_Buffer0 =
    heli_q8_lab2_P.RateTransitiony_InitialConditio;

  /* InitializeConditions for TransferFcn: '<S5>/Travel: Transfer Fcn' */
  heli_q8_lab2_X.TravelTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S5>/Pitch: Transfer Fcn' */
  heli_q8_lab2_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S5>/Elevation: Transfer Fcn' */
  heli_q8_lab2_X.ElevationTransferFcn_CSTATE = 0.0;
}

/* Model terminate function */
void heli_q8_lab2_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_lab2/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(heli_q8_lab2_DW.HILInitialize_Card);
    hil_monitor_stop_all(heli_q8_lab2_DW.HILInitialize_Card);
    is_switching = false;
    if ((heli_q8_lab2_P.HILInitialize_AOTerminate && !is_switching) ||
        (heli_q8_lab2_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_lab2_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_lab2_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((heli_q8_lab2_P.HILInitialize_POTerminate && !is_switching) ||
        (heli_q8_lab2_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_lab2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_lab2_P.HILInitialize_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(heli_q8_lab2_DW.HILInitialize_Card
                         , heli_q8_lab2_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , heli_q8_lab2_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &heli_q8_lab2_DW.HILInitialize_AOVoltages[0]
                         , &heli_q8_lab2_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(heli_q8_lab2_DW.HILInitialize_Card,
            heli_q8_lab2_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &heli_q8_lab2_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(heli_q8_lab2_DW.HILInitialize_Card,
            heli_q8_lab2_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &heli_q8_lab2_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_lab2_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(heli_q8_lab2_DW.HILInitialize_Card);
    hil_monitor_delete_all(heli_q8_lab2_DW.HILInitialize_Card);
    hil_close(heli_q8_lab2_DW.HILInitialize_Card);
    heli_q8_lab2_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) heli_q8_lab2_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "LQR_q3_10_elevation_rate_focus.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_lab2_M,
                          "Error closing MAT-file LQR_q3_10_elevation_rate_focus.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(heli_q8_lab2_M,
                          "Error reopening MAT-file LQR_q3_10_elevation_rate_focus.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 8 + 1, heli_q8_lab2_DW.ToFile_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(heli_q8_lab2_M,
                          "Error writing header for ans to MAT-file LQR_q3_10_elevation_rate_focus.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_lab2_M,
                          "Error closing MAT-file LQR_q3_10_elevation_rate_focus.mat");
        return;
      }

      heli_q8_lab2_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: heli_q8_lab2/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_lab2_P.GameController_Enabled) {
      game_controller_close(heli_q8_lab2_DW.GameController_Controller);
      heli_q8_lab2_DW.GameController_Controller = NULL;
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_lab2_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_lab2_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  heli_q8_lab2_initialize();
}

void MdlTerminate(void)
{
  heli_q8_lab2_terminate();
}

/* Registration function */
RT_MODEL_heli_q8_lab2_T *heli_q8_lab2(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)heli_q8_lab2_M, 0,
                sizeof(RT_MODEL_heli_q8_lab2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&heli_q8_lab2_M->solverInfo,
                          &heli_q8_lab2_M->Timing.simTimeStep);
    rtsiSetTPtr(&heli_q8_lab2_M->solverInfo, &rtmGetTPtr(heli_q8_lab2_M));
    rtsiSetStepSizePtr(&heli_q8_lab2_M->solverInfo,
                       &heli_q8_lab2_M->Timing.stepSize0);
    rtsiSetdXPtr(&heli_q8_lab2_M->solverInfo, &heli_q8_lab2_M->derivs);
    rtsiSetContStatesPtr(&heli_q8_lab2_M->solverInfo, (real_T **)
                         &heli_q8_lab2_M->contStates);
    rtsiSetNumContStatesPtr(&heli_q8_lab2_M->solverInfo,
      &heli_q8_lab2_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&heli_q8_lab2_M->solverInfo,
      &heli_q8_lab2_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&heli_q8_lab2_M->solverInfo,
      &heli_q8_lab2_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&heli_q8_lab2_M->solverInfo,
      &heli_q8_lab2_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&heli_q8_lab2_M->solverInfo, (&rtmGetErrorStatus
      (heli_q8_lab2_M)));
    rtsiSetRTModelPtr(&heli_q8_lab2_M->solverInfo, heli_q8_lab2_M);
  }

  rtsiSetSimTimeStep(&heli_q8_lab2_M->solverInfo, MAJOR_TIME_STEP);
  heli_q8_lab2_M->intgData.f[0] = heli_q8_lab2_M->odeF[0];
  heli_q8_lab2_M->contStates = ((real_T *) &heli_q8_lab2_X);
  rtsiSetSolverData(&heli_q8_lab2_M->solverInfo, (void *)
                    &heli_q8_lab2_M->intgData);
  rtsiSetSolverName(&heli_q8_lab2_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = heli_q8_lab2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    heli_q8_lab2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    heli_q8_lab2_M->Timing.sampleTimes =
      (&heli_q8_lab2_M->Timing.sampleTimesArray[0]);
    heli_q8_lab2_M->Timing.offsetTimes =
      (&heli_q8_lab2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    heli_q8_lab2_M->Timing.sampleTimes[0] = (0.0);
    heli_q8_lab2_M->Timing.sampleTimes[1] = (0.002);
    heli_q8_lab2_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    heli_q8_lab2_M->Timing.offsetTimes[0] = (0.0);
    heli_q8_lab2_M->Timing.offsetTimes[1] = (0.0);
    heli_q8_lab2_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(heli_q8_lab2_M, &heli_q8_lab2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = heli_q8_lab2_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = heli_q8_lab2_M->Timing.perTaskSampleHitsArray;
    heli_q8_lab2_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    heli_q8_lab2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(heli_q8_lab2_M, 60.0);
  heli_q8_lab2_M->Timing.stepSize0 = 0.002;
  heli_q8_lab2_M->Timing.stepSize1 = 0.002;
  heli_q8_lab2_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  heli_q8_lab2_M->Sizes.checksums[0] = (2526322252U);
  heli_q8_lab2_M->Sizes.checksums[1] = (3321140808U);
  heli_q8_lab2_M->Sizes.checksums[2] = (1650841387U);
  heli_q8_lab2_M->Sizes.checksums[3] = (4104049691U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    heli_q8_lab2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(heli_q8_lab2_M->extModeInfo,
      &heli_q8_lab2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(heli_q8_lab2_M->extModeInfo,
                        heli_q8_lab2_M->Sizes.checksums);
    rteiSetTPtr(heli_q8_lab2_M->extModeInfo, rtmGetTPtr(heli_q8_lab2_M));
  }

  heli_q8_lab2_M->solverInfoPtr = (&heli_q8_lab2_M->solverInfo);
  heli_q8_lab2_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&heli_q8_lab2_M->solverInfo, 0.002);
  rtsiSetSolverMode(&heli_q8_lab2_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  heli_q8_lab2_M->blockIO = ((void *) &heli_q8_lab2_B);

  {
    heli_q8_lab2_B.ElevationCounttorad = 0.0;
    heli_q8_lab2_B.Sum1 = 0.0;
    heli_q8_lab2_B.PitchCounttorad = 0.0;
    heli_q8_lab2_B.RateTransitionx = 0.0;
    heli_q8_lab2_B.Joystick_gain_x = 0.0;
    heli_q8_lab2_B.Sum3 = 0.0;
    heli_q8_lab2_B.RateTransitiony = 0.0;
    heli_q8_lab2_B.Joystick_gain_y = 0.0;
    heli_q8_lab2_B.Gain = 0.0;
    heli_q8_lab2_B.TravelCounttorad = 0.0;
    heli_q8_lab2_B.TravelTransferFcn = 0.0;
    heli_q8_lab2_B.PitchTransferFcn = 0.0;
    heli_q8_lab2_B.ElevationTransferFcn = 0.0;
    heli_q8_lab2_B.FrontmotorSaturation = 0.0;
    heli_q8_lab2_B.BackmotorSaturation = 0.0;
  }

  /* parameters */
  heli_q8_lab2_M->defaultParam = ((real_T *)&heli_q8_lab2_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &heli_q8_lab2_X;
    heli_q8_lab2_M->contStates = (x);
    (void) memset((void *)&heli_q8_lab2_X, 0,
                  sizeof(X_heli_q8_lab2_T));
  }

  /* states (dwork) */
  heli_q8_lab2_M->dwork = ((void *) &heli_q8_lab2_DW);
  (void) memset((void *)&heli_q8_lab2_DW, 0,
                sizeof(DW_heli_q8_lab2_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_lab2_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_lab2_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_lab2_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_lab2_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_lab2_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_lab2_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_lab2_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_lab2_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  heli_q8_lab2_DW.RateTransitionx_Buffer0 = 0.0;
  heli_q8_lab2_DW.RateTransitiony_Buffer0 = 0.0;
  heli_q8_lab2_DW.HILWriteAnalog_Buffer[0] = 0.0;
  heli_q8_lab2_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    heli_q8_lab2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  heli_q8_lab2_M->Sizes.numContStates = (3);/* Number of continuous states */
  heli_q8_lab2_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  heli_q8_lab2_M->Sizes.numY = (0);    /* Number of model outputs */
  heli_q8_lab2_M->Sizes.numU = (0);    /* Number of model inputs */
  heli_q8_lab2_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  heli_q8_lab2_M->Sizes.numSampTimes = (3);/* Number of sample times */
  heli_q8_lab2_M->Sizes.numBlocks = (64);/* Number of blocks */
  heli_q8_lab2_M->Sizes.numBlockIO = (15);/* Number of block outputs */
  heli_q8_lab2_M->Sizes.numBlockPrms = (179);/* Sum of parameter "widths" */
  return heli_q8_lab2_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
