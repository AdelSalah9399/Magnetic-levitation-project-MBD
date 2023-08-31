/*
 * File: ML.c
 *
 * Code generated for Simulink model 'ML'.
 *
 * Model version                  : 11.0
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Fri Sep  1 00:47:48 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "ML.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

/* Continuous states */
X rtX;

/* Block signals and states (default storage) */
DW rtDW;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* private model entry point functions */
extern void ML_derivatives(void);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 8;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ML_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ML_step();
  ML_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ML_step();
  ML_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void ML_step(void)
{
  real_T a;
  real_T rtb_Internal;
  int32_T i;
  if (rtmIsMajorTimeStep(rtM)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&rtM->solverInfo,((rtM->Timing.clockTick0+1)*
      rtM->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(rtM)) {
    rtM->Timing.t[0] = rtsiGetT(&rtM->solverInfo);
  }

  /* Step: '<Root>/Step1' incorporates:
   *  Step: '<Root>/Step'
   */
  a = rtM->Timing.t[0];
  if (a < 0.0) {
    rtb_Internal = 0.0;
  } else {
    rtb_Internal = 0.01;
  }

  /* End of Step: '<Root>/Step1' */

  /* Sum: '<Root>/Subtract' incorporates:
   *  Integrator: '<Root>/hight(h)1'
   *  Sum: '<Root>/Add2'
   */
  rtDW.Subtract = rtb_Internal - (rtX.highth1_CSTATE[2] + 0.01);

  /* StateSpace: '<S2>/Internal' */
  rtb_Internal = 1471.9516326287558 * rtX.Internal_CSTATE + -8825.7109543518491 *
    rtDW.Subtract;
  for (i = 0; i < 3; i++) {
    /* Sum: '<Root>/Add' incorporates:
     *  Gain: '<Root>/Gain'
     *  Gain: '<Root>/Gain2'
     *  Integrator: '<Root>/hight(h)1'
     */
    rtDW.Add[i] = ((rtConstP.Gain2_Gain[i + 3] * rtX.highth1_CSTATE[1] +
                    rtConstP.Gain2_Gain[i] * rtX.highth1_CSTATE[0]) +
                   rtConstP.Gain2_Gain[i + 6] * rtX.highth1_CSTATE[2]) +
      rtConstP.Gain_Gain[i] * rtb_Internal;
  }

  /* Step: '<Root>/Step' */
  if (a < 0.0) {
    a = 0.0;
  } else {
    a = 0.01;
  }

  /* Sum: '<Root>/Subtract1' incorporates:
   *  Integrator: '<Root>/hight'
   */
  rtDW.Subtract1 = a - rtX.hight_CSTATE;

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Integrator: '<Root>/current'
   *  Integrator: '<Root>/hight'
   *  StateSpace: '<S1>/Internal'
   *  Sum: '<Root>/Add3'
   */
  a = rtX.current_CSTATE / rtX.hight_CSTATE;
  rtDW.d2_h = (0.49 - a * a * 1.0E-6) / 0.05;
  rtDW.d_i = (((1471.9516326287558 * rtX.Internal_CSTATE_f + -8825.7109543518491
                * rtDW.Subtract1) + 7.0) - rtX.current_CSTATE) / 0.01;

  /* Integrator: '<Root>/d_h ' */
  rtDW.d_h = rtX.d_h_CSTATE;
  if (rtmIsMajorTimeStep(rtM)) {
    rt_ertODEUpdateContinuousStates(&rtM->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++rtM->Timing.clockTick0;
    rtM->Timing.t[0] = rtsiGetSolverStopTime(&rtM->solverInfo);

    {
      /* Update absolute timer for sample time: [0.2s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.2, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      rtM->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void ML_derivatives(void)
{
  XDot *_rtXdot;
  _rtXdot = ((XDot *) rtM->derivs);

  /* Derivatives for Integrator: '<Root>/hight(h)1' */
  _rtXdot->highth1_CSTATE[0] = rtDW.Add[0];
  _rtXdot->highth1_CSTATE[1] = rtDW.Add[1];
  _rtXdot->highth1_CSTATE[2] = rtDW.Add[2];

  /* Derivatives for StateSpace: '<S2>/Internal' */
  _rtXdot->Internal_CSTATE = 0.0;
  _rtXdot->Internal_CSTATE += -500.0 * rtX.Internal_CSTATE;
  _rtXdot->Internal_CSTATE += 2732.5227025589375 * rtDW.Subtract;

  /* Derivatives for Integrator: '<Root>/hight' */
  _rtXdot->hight_CSTATE = rtDW.d_h;

  /* Derivatives for StateSpace: '<S1>/Internal' */
  _rtXdot->Internal_CSTATE_f = 0.0;
  _rtXdot->Internal_CSTATE_f += -500.0 * rtX.Internal_CSTATE_f;
  _rtXdot->Internal_CSTATE_f += 2732.5227025589375 * rtDW.Subtract1;

  /* Derivatives for Integrator: '<Root>/current' */
  _rtXdot->current_CSTATE = rtDW.d_i;

  /* Derivatives for Integrator: '<Root>/d_h ' */
  _rtXdot->d_h_CSTATE = rtDW.d2_h;
}

/* Model initialize function */
void ML_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetdXPtr(&rtM->solverInfo, &rtM->derivs);
    rtsiSetContStatesPtr(&rtM->solverInfo, (real_T **) &rtM->contStates);
    rtsiSetNumContStatesPtr(&rtM->solverInfo, &rtM->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&rtM->solverInfo,
      &rtM->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&rtM->solverInfo,
      &rtM->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&rtM->solverInfo,
      &rtM->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, (&rtmGetErrorStatus(rtM)));
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtM->intgData.y = rtM->odeY;
  rtM->intgData.f[0] = rtM->odeF[0];
  rtM->intgData.f[1] = rtM->odeF[1];
  rtM->intgData.f[2] = rtM->odeF[2];
  rtM->contStates = ((X *) &rtX);
  rtsiSetSolverData(&rtM->solverInfo, (void *)&rtM->intgData);
  rtsiSetSolverName(&rtM->solverInfo,"ode3");
  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);
  rtM->Timing.stepSize0 = 0.2;

  /* InitializeConditions for Integrator: '<Root>/hight(h)1' */
  rtX.highth1_CSTATE[0] = 0.0;
  rtX.highth1_CSTATE[1] = 0.0;
  rtX.highth1_CSTATE[2] = 0.005;

  /* InitializeConditions for StateSpace: '<S2>/Internal' */
  rtX.Internal_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<Root>/hight' */
  rtX.hight_CSTATE = 0.015;

  /* InitializeConditions for StateSpace: '<S1>/Internal' */
  rtX.Internal_CSTATE_f = 0.0;

  /* InitializeConditions for Integrator: '<Root>/current' */
  rtX.current_CSTATE = 7.0;

  /* InitializeConditions for Integrator: '<Root>/d_h ' */
  rtX.d_h_CSTATE = 0.0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
