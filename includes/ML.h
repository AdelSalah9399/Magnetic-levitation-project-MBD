/*
 * File: ML.h
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

#ifndef RTW_HEADER_ML_h_
#define RTW_HEADER_ML_h_
#include <string.h>
#ifndef ML_COMMON_INCLUDES_
#define ML_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* ML_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Add[3];                       /* '<Root>/Add' */
  real_T Subtract;                     /* '<Root>/Subtract' */
  real_T Subtract1;                    /* '<Root>/Subtract1' */
  real_T d_h;                          /* '<Root>/d_h ' */
  real_T d_i;                          /* '<Root>/MATLAB Function' */
  real_T d2_h;                         /* '<Root>/MATLAB Function' */
} DW;

/* Continuous states (default storage) */
typedef struct {
  real_T highth1_CSTATE[3];            /* '<Root>/hight(h)1' */
  real_T Internal_CSTATE;              /* '<S2>/Internal' */
  real_T hight_CSTATE;                 /* '<Root>/hight' */
  real_T Internal_CSTATE_f;            /* '<S1>/Internal' */
  real_T current_CSTATE;               /* '<Root>/current' */
  real_T d_h_CSTATE;                   /* '<Root>/d_h ' */
} X;

/* State derivatives (default storage) */
typedef struct {
  real_T highth1_CSTATE[3];            /* '<Root>/hight(h)1' */
  real_T Internal_CSTATE;              /* '<S2>/Internal' */
  real_T hight_CSTATE;                 /* '<Root>/hight' */
  real_T Internal_CSTATE_f;            /* '<S1>/Internal' */
  real_T current_CSTATE;               /* '<Root>/current' */
  real_T d_h_CSTATE;                   /* '<Root>/d_h ' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T highth1_CSTATE[3];         /* '<Root>/hight(h)1' */
  boolean_T Internal_CSTATE;           /* '<S2>/Internal' */
  boolean_T hight_CSTATE;              /* '<Root>/hight' */
  boolean_T Internal_CSTATE_f;         /* '<S1>/Internal' */
  boolean_T current_CSTATE;            /* '<Root>/current' */
  boolean_T d_h_CSTATE;                /* '<Root>/d_h ' */
} XDis;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: linsys1.a
   * Referenced by: '<Root>/Gain2'
   */
  real_T Gain2_Gain[9];

  /* Expression: linsys1.b
   * Referenced by: '<Root>/Gain'
   */
  real_T Gain_Gain[3];
} ConstP;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[8];
  real_T odeF[3][8];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Continuous states (default storage) */
extern X rtX;

/* Block signals and states (default storage) */
extern DW rtDW;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void ML_initialize(void);
extern void ML_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Add1' : Unused code path elimination
 * Block '<Root>/Constant1' : Unused code path elimination
 * Block '<Root>/Gain1' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope3' : Unused code path elimination
 * Block '<Root>/Scope4' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ML'
 * '<S1>'   : 'ML/LTI System'
 * '<S2>'   : 'ML/LTI System1'
 * '<S3>'   : 'ML/MATLAB Function'
 * '<S4>'   : 'ML/LTI System/IO Delay'
 * '<S5>'   : 'ML/LTI System/Input Delay'
 * '<S6>'   : 'ML/LTI System/Output Delay'
 * '<S7>'   : 'ML/LTI System1/IO Delay'
 * '<S8>'   : 'ML/LTI System1/Input Delay'
 * '<S9>'   : 'ML/LTI System1/Output Delay'
 */
#endif                                 /* RTW_HEADER_ML_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
