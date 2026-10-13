/*
 * heli_q8_lab2_data.c
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

/* Block parameters (default storage) */
P_heli_q8_lab2_T heli_q8_lab2_P = {
  /* Variable: F
   * Referenced by: '<S3>/Gain1'
   */
  { -6.51197873396555E-16, 2.4657473217107229, 3.7230764154450173,
    2.4461096459546278E-16 },

  /* Variable: Joystick_gain_x
   * Referenced by: '<S6>/Joystick_gain_x'
   */
  1.0,

  /* Variable: Joystick_gain_y
   * Referenced by: '<S6>/Joystick_gain_y'
   */
  -1.0,

  /* Variable: K
   * Referenced by: '<S3>/Gain'
   */
  { -6.51197873396555E-16, 2.4657473217107229, -3.8308586569700662E-16,
    2.5399549272618041, 3.7230764154450173, 2.4461096459546278E-16,
    6.8479428259261892E-16, -1.0000000000000002, -1.0, -9.3335792761803629E-16 },

  /* Variable: V_s0
   * Referenced by: '<Root>/Constant1'
   */
  6.5,

  /* Variable: elev_ref
   * Referenced by: '<Root>/Elevation ref'
   */
  0.48,

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<S5>/HIL Write Analog'
   */
  { 0U, 1U },

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  -10.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  -10.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_frequency
   * Referenced by: '<Root>/HIL Initialize'
   */
  24305.934065934067,

  /* Expression: pwm_leading_deadband
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_trailing_deadband
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: -2 * pi /4096
   * Referenced by: '<S5>/Elevation: Count to rad'
   */
  -0.0015339807878856412,

  /* Expression: -2*pi /4096
   * Referenced by: '<S5>/Pitch: Count to rad'
   */
  -0.0015339807878856412,

  /* Expression: 30
   * Referenced by: '<S1>/30s +1'
   */
  30.0,

  /* Expression: 0
   * Referenced by: '<S1>/30s +1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/30s +1'
   */
  1.0,

  /* Expression: 35
   * Referenced by: '<S1>/35s -1'
   */
  35.0,

  /* Expression: 0
   * Referenced by: '<S1>/35s -1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S1>/35s -1'
   */
  -1.0,

  /* Expression: 40
   * Referenced by: '<S1>/40s -1'
   */
  40.0,

  /* Expression: 0
   * Referenced by: '<S1>/40s -1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S1>/40s -1'
   */
  -1.0,

  /* Expression: 45
   * Referenced by: '<S1>/45s +1'
   */
  45.0,

  /* Expression: 0
   * Referenced by: '<S1>/45s +1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/45s +1'
   */
  1.0,

  /* Expression: 0.4
   * Referenced by: '<S1>/Gain'
   */
  0.4,

  /* Expression: 0
   * Referenced by: '<S6>/Rate Transition: x'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S6>/Dead Zone: x'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S6>/Dead Zone: x'
   */
  0.1,

  /* Expression: 10/9
   * Referenced by: '<S6>/Gain: x'
   */
  1.1111111111111112,

  /* Expression: 0
   * Referenced by: '<S6>/Rate Transition: y'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S6>/Dead Zone: y'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S6>/Dead Zone: y'
   */
  0.1,

  /* Expression: 10/9
   * Referenced by: '<S6>/Gain: y'
   */
  1.1111111111111112,

  /* Expression: 10
   * Referenced by: '<S2>/10s +1'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S2>/10s +1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/10s +1'
   */
  1.0,

  /* Expression: 15
   * Referenced by: '<S2>/15s -1'
   */
  15.0,

  /* Expression: 0
   * Referenced by: '<S2>/15s -1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S2>/15s -1'
   */
  -1.0,

  /* Expression: 20
   * Referenced by: '<S2>/20s -1'
   */
  20.0,

  /* Expression: 0
   * Referenced by: '<S2>/20s -1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S2>/20s -1'
   */
  -1.0,

  /* Expression: 25
   * Referenced by: '<S2>/25s +1'
   */
  25.0,

  /* Expression: 0
   * Referenced by: '<S2>/25s +1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/25s +1'
   */
  1.0,

  /* Expression: 0.9
   * Referenced by: '<S2>/0.07'
   */
  0.9,

  /* Expression: 1
   * Referenced by: '<Root>/Gain'
   */
  1.0,

  /* Expression: 2*pi/8192
   * Referenced by: '<S5>/Travel: Count to rad'
   */
  0.00076699039394282058,

  /* Computed Parameter: TravelTransferFcn_A
   * Referenced by: '<S5>/Travel: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: TravelTransferFcn_C
   * Referenced by: '<S5>/Travel: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: TravelTransferFcn_D
   * Referenced by: '<S5>/Travel: Transfer Fcn'
   */
  50.0,

  /* Computed Parameter: PitchTransferFcn_A
   * Referenced by: '<S5>/Pitch: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: PitchTransferFcn_C
   * Referenced by: '<S5>/Pitch: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: PitchTransferFcn_D
   * Referenced by: '<S5>/Pitch: Transfer Fcn'
   */
  50.0,

  /* Computed Parameter: ElevationTransferFcn_A
   * Referenced by: '<S5>/Elevation: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: ElevationTransferFcn_C
   * Referenced by: '<S5>/Elevation: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: ElevationTransferFcn_D
   * Referenced by: '<S5>/Elevation: Transfer Fcn'
   */
  50.0,

  /* Expression: 0.5
   * Referenced by: '<S4>/Back gain'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S4>/Front gain'
   */
  0.5,

  /* Expression: 5
   * Referenced by: '<S5>/Front motor: Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S5>/Front motor: Saturation'
   */
  -5.0,

  /* Expression: 5
   * Referenced by: '<S5>/Back motor: Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S5>/Back motor: Saturation'
   */
  -5.0,

  /* Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0, 1, 2 },

  /* Computed Parameter: HILInitialize_DOWatchdog
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POConfiguration
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POAlignment
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPolarity
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Clock
   * Referenced by: '<S5>/HIL Read Encoder Timebase'
   */
  0,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<Root>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_POChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILReadEncoderTimebase_Channels
   * Referenced by: '<S5>/HIL Read Encoder Timebase'
   */
  { 0U, 1U, 2U },

  /* Computed Parameter: HILReadEncoderTimebase_SamplesI
   * Referenced by: '<S5>/HIL Read Encoder Timebase'
   */
  500U,

  /* Computed Parameter: GameController_BufferSize
   * Referenced by: '<S6>/Game Controller'
   */
  12U,

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Active
   * Referenced by: '<S5>/HIL Read Encoder Timebase'
   */
  1,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<S5>/HIL Write Analog'
   */
  0,

  /* Computed Parameter: GameController_AutoCenter
   * Referenced by: '<S6>/Game Controller'
   */
  0,

  /* Computed Parameter: GameController_Enabled
   * Referenced by: '<S6>/Game Controller'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Overflow
   * Referenced by: '<S5>/HIL Read Encoder Timebase'
   */
  1U,

  /* Computed Parameter: GameController_ControllerNumber
   * Referenced by: '<S6>/Game Controller'
   */
  1U
};
