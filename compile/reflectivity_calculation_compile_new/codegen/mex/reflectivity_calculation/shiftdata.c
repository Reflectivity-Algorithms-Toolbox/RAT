/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * shiftdata.c
 *
 * Code generation for function 'shiftdata'
 *
 */

/* Include files */
#include "shiftdata.h"
#include "find.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "reflectivity_calculation_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo tf_emlrtRSI = { 26, /* lineNo */
  "shiftdata",                         /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pathName */
};

static emlrtRSInfo uf_emlrtRSI = { 33, /* lineNo */
  "shiftdata",                         /* fcnName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pathName */
};

static emlrtDCInfo lb_emlrtDCI = { 14, /* lineNo */
  8,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo kg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  28,                                  /* colNo */
  "data",                              /* aName */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  16,                                  /* colNo */
  "data",                              /* aName */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo u_emlrtECI = { -1,  /* nDims */
  19,                                  /* lineNo */
  9,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtBCInfo mg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  28,                                  /* colNo */
  "data",                              /* aName */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ng_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  16,                                  /* colNo */
  "data",                              /* aName */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo v_emlrtECI = { -1,  /* nDims */
  20,                                  /* lineNo */
  9,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtBCInfo og_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  28,                                  /* colNo */
  "data",                              /* aName */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  16,                                  /* colNo */
  "data",                              /* aName */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo w_emlrtECI = { -1,  /* nDims */
  21,                                  /* lineNo */
  9,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtBCInfo qg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  32,                                  /* colNo */
  "data",                              /* aName */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  33,                                  /* lineNo */
  31,                                  /* colNo */
  "data",                              /* aName */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  37,                                  /* lineNo */
  37,                                  /* colNo */
  "data",                              /* aName */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  29,                                  /* colNo */
  "data",                              /* aName */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ug_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  38,                                  /* colNo */
  "data",                              /* aName */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  27,                                  /* colNo */
  "simLimits",                         /* aName */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  27,                                  /* colNo */
  "simLimits",                         /* aName */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xg_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  28,                                  /* lineNo */
  24,                                  /* colNo */
  "lowIndex",                          /* aName */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo vk_emlrtRTEI = { 19,/* lineNo */
  21,                                  /* colNo */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtRTEInfo wk_emlrtRTEI = { 47,/* lineNo */
  9,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtRTEInfo xk_emlrtRTEI = { 20,/* lineNo */
  21,                                  /* colNo */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtRTEInfo yk_emlrtRTEI = { 21,/* lineNo */
  21,                                  /* colNo */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtRTEInfo al_emlrtRTEI = { 26,/* lineNo */
  25,                                  /* colNo */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtRTEInfo bl_emlrtRTEI = { 26,/* lineNo */
  9,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtRTEInfo cl_emlrtRTEI = { 33,/* lineNo */
  24,                                  /* colNo */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtRTEInfo dl_emlrtRTEI = { 33,/* lineNo */
  9,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

static emlrtRTEInfo el_emlrtRTEI = { 40,/* lineNo */
  9,                                   /* colNo */
  "shiftdata",                         /* fName */
  "/home/sp1115144/Desktop/RAT/targetFunctions/common/shiftData/shiftdata.m"/* pName */
};

/* Function Definitions */
void shiftdata(const emlrtStack *sp, real_T scalefac, real_T horshift, real_T
               dataPresent, emxArray_real_T *data, const real_T dataLimits[2],
               const real_T simLimits_data[], const int32_T simLimits_size[2],
               emxArray_real_T *shifted_data)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_boolean_T *b_data;
  emxArray_int32_T *ii;
  emxArray_real_T *lowIndex;
  real_T b_simXData[300];
  real_T simXData[100];
  real_T d1;
  real_T delta1;
  real_T delta2;
  int32_T b_lowIndex;
  int32_T hiIndex;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  Shifts the data according to scale factor. If there is no data, makes  */
  /*  x-data over the simulation range. */
  /*  scalefac = problem.scalefactors; */
  /*  horshift = problem.qshifts; */
  /*  numberOfContrasts = problem.numberOfContrasts; */
  /*  dataPresent = problem.dataPresent; */
  /*  allData = problem.data; */
  /*  dataLimits = problem.dataLimits; */
  /* shifted_data = cell(1,numberOfContrasts); */
  if (dataPresent != (int32_T)muDoubleScalarFloor(dataPresent)) {
    emlrtIntegerCheckR2012b(dataPresent, &lb_emlrtDCI, sp);
  }

  switch ((int32_T)dataPresent) {
   case 1:
    if (scalefac == 0.0) {
      scalefac = 1.0E-30;
    }

    if (1 > data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, data->size[1], &lg_emlrtBCI, sp);
    }

    if (1 > data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, data->size[1], &kg_emlrtBCI, sp);
    }

    emxInit_real_T(sp, &lowIndex, 1, &bl_emlrtRTEI, true);
    emlrtSubAssignSizeCheckR2012b(&data->size[0], 1, &data->size[0], 1,
      &u_emlrtECI, sp);
    b_lowIndex = data->size[0] - 1;
    i = lowIndex->size[0];
    lowIndex->size[0] = data->size[0];
    emxEnsureCapacity_real_T(sp, lowIndex, i, &vk_emlrtRTEI);
    for (i = 0; i <= b_lowIndex; i++) {
      lowIndex->data[i] = data->data[i] + horshift;
    }

    loop_ub = lowIndex->size[0];
    for (i = 0; i < loop_ub; i++) {
      data->data[i] = lowIndex->data[i];
    }

    if (2 > data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, data->size[1], &ng_emlrtBCI, sp);
    }

    if (2 > data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, data->size[1], &mg_emlrtBCI, sp);
    }

    loop_ub = data->size[0];
    i = lowIndex->size[0];
    lowIndex->size[0] = data->size[0];
    emxEnsureCapacity_real_T(sp, lowIndex, i, &xk_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      lowIndex->data[i] = data->data[i + data->size[0]] / scalefac;
    }

    emlrtSubAssignSizeCheckR2012b(&data->size[0], 1, &lowIndex->size[0], 1,
      &v_emlrtECI, sp);
    loop_ub = lowIndex->size[0];
    for (i = 0; i < loop_ub; i++) {
      data->data[i + data->size[0]] = lowIndex->data[i];
    }

    if (3 > data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(3, 1, data->size[1], &pg_emlrtBCI, sp);
    }

    if (3 > data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(3, 1, data->size[1], &og_emlrtBCI, sp);
    }

    loop_ub = data->size[0];
    i = lowIndex->size[0];
    lowIndex->size[0] = data->size[0];
    emxEnsureCapacity_real_T(sp, lowIndex, i, &yk_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      lowIndex->data[i] = data->data[i + data->size[0] * 2] / scalefac;
    }

    emlrtSubAssignSizeCheckR2012b(&data->size[0], 1, &lowIndex->size[0], 1,
      &w_emlrtECI, sp);
    loop_ub = lowIndex->size[0];
    for (i = 0; i < loop_ub; i++) {
      data->data[i + data->size[0] * 2] = lowIndex->data[i];
    }

    if (1 > data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, data->size[1], &qg_emlrtBCI, sp);
    }

    emxInit_boolean_T(sp, &b_data, 1, &al_emlrtRTEI, true);
    st.site = &tf_emlrtRSI;
    loop_ub = data->size[0];
    i = b_data->size[0];
    b_data->size[0] = data->size[0];
    emxEnsureCapacity_boolean_T(&st, b_data, i, &al_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      b_data->data[i] = (data->data[i] < dataLimits[0]);
    }

    emxInit_int32_T(&st, &ii, 1, &xj_emlrtRTEI, true);
    b_st.site = &xd_emlrtRSI;
    eml_find(&b_st, b_data, ii);
    i = lowIndex->size[0];
    lowIndex->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(&st, lowIndex, i, &bl_emlrtRTEI);
    loop_ub = ii->size[0];
    for (i = 0; i < loop_ub; i++) {
      lowIndex->data[i] = ii->data[i];
    }

    if (lowIndex->size[0] != 0) {
      if (lowIndex->size[0] < 1) {
        emlrtDynamicBoundsCheckR2012b(lowIndex->size[0], 1, lowIndex->size[0],
          &xg_emlrtBCI, sp);
      }

      b_lowIndex = (int32_T)lowIndex->data[lowIndex->size[0] - 1];
    } else {
      b_lowIndex = 1;
    }

    if (1 > data->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, data->size[1], &rg_emlrtBCI, sp);
    }

    st.site = &uf_emlrtRSI;
    loop_ub = data->size[0];
    i = b_data->size[0];
    b_data->size[0] = data->size[0];
    emxEnsureCapacity_boolean_T(&st, b_data, i, &cl_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      b_data->data[i] = (data->data[i] > dataLimits[1]);
    }

    b_st.site = &xd_emlrtRSI;
    eml_find(&b_st, b_data, ii);
    i = lowIndex->size[0];
    lowIndex->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(&st, lowIndex, i, &dl_emlrtRTEI);
    loop_ub = ii->size[0];
    emxFree_boolean_T(&b_data);
    for (i = 0; i < loop_ub; i++) {
      lowIndex->data[i] = ii->data[i];
    }

    emxFree_int32_T(&ii);
    if (lowIndex->size[0] != 0) {
      hiIndex = (int32_T)lowIndex->data[0];
    } else {
      if (1 > data->size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, data->size[1], &sg_emlrtBCI, sp);
      }

      hiIndex = data->size[0];
    }

    emxFree_real_T(&lowIndex);
    if (b_lowIndex > hiIndex) {
      i = 0;
      hiIndex = 0;
    } else {
      if ((b_lowIndex < 1) || (b_lowIndex > data->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_lowIndex, 1, data->size[0], &tg_emlrtBCI,
          sp);
      }

      i = b_lowIndex - 1;
      if ((hiIndex < 1) || (hiIndex > data->size[0])) {
        emlrtDynamicBoundsCheckR2012b(hiIndex, 1, data->size[0], &ug_emlrtBCI,
          sp);
      }
    }

    loop_ub = data->size[1];
    b_lowIndex = hiIndex - i;
    hiIndex = shifted_data->size[0] * shifted_data->size[1];
    shifted_data->size[0] = b_lowIndex;
    shifted_data->size[1] = data->size[1];
    emxEnsureCapacity_real_T(sp, shifted_data, hiIndex, &el_emlrtRTEI);
    for (hiIndex = 0; hiIndex < loop_ub; hiIndex++) {
      for (i1 = 0; i1 < b_lowIndex; i1++) {
        shifted_data->data[i1 + shifted_data->size[0] * hiIndex] = data->data[(i
          + i1) + data->size[0] * hiIndex];
      }
    }
    break;

   default:
    i = simLimits_size[0] * simLimits_size[1];
    if (1 > i) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i, &vg_emlrtBCI, sp);
    }

    d1 = simLimits_data[0];
    if (2 > i) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i, &wg_emlrtBCI, sp);
    }

    simXData[99] = simLimits_data[1];
    simXData[0] = simLimits_data[0];
    if (simLimits_data[0] == -simLimits_data[1]) {
      for (b_lowIndex = 0; b_lowIndex < 98; b_lowIndex++) {
        simXData[b_lowIndex + 1] = simLimits_data[1] * ((2.0 * ((real_T)
          b_lowIndex + 2.0) - 101.0) / 99.0);
      }
    } else if (((simLimits_data[0] < 0.0) != (simLimits_data[1] < 0.0)) &&
               ((muDoubleScalarAbs(simLimits_data[0]) > 8.9884656743115785E+307)
                || (muDoubleScalarAbs(simLimits_data[1]) >
                    8.9884656743115785E+307))) {
      delta1 = simLimits_data[0] / 99.0;
      delta2 = simLimits_data[1] / 99.0;
      for (b_lowIndex = 0; b_lowIndex < 98; b_lowIndex++) {
        simXData[b_lowIndex + 1] = (d1 + delta2 * ((real_T)b_lowIndex + 1.0)) -
          delta1 * ((real_T)b_lowIndex + 1.0);
      }
    } else {
      delta1 = (simLimits_data[1] - simLimits_data[0]) / 99.0;
      for (b_lowIndex = 0; b_lowIndex < 98; b_lowIndex++) {
        simXData[b_lowIndex + 1] = d1 + ((real_T)b_lowIndex + 1.0) * delta1;
      }
    }

    for (i = 0; i < 100; i++) {
      b_simXData[i] = simXData[i];
      b_simXData[i + 100] = 0.0;
      b_simXData[i + 200] = 0.0;
    }

    i = shifted_data->size[0] * shifted_data->size[1];
    shifted_data->size[0] = 100;
    shifted_data->size[1] = 3;
    emxEnsureCapacity_real_T(sp, shifted_data, i, &wk_emlrtRTEI);
    for (i = 0; i < 300; i++) {
      shifted_data->data[i] = b_simXData[i];
    }
    break;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (shiftdata.c) */
