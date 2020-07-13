/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * abeles_single.c
 *
 * Code generation for function 'abeles_single'
 *
 */

/* Include files */
#include "abeles_single.h"
#include "mwmathutil.h"
#include "reflectivity_calculation.h"
#include "reflectivity_calculation_data.h"
#include "reflectivity_calculation_emxutil.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo mf_emlrtRSI = { 28, /* lineNo */
  "abeles_single",                     /* fcnName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_single.m"/* pathName */
};

static emlrtBCInfo rh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  23,                                  /* colNo */
  "sld",                               /* aName */
  "abeles_single",                     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  25,                                  /* colNo */
  "sld",                               /* aName */
  "abeles_single",                     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo ub_emlrtRTEI = { 39,/* lineNo */
  19,                                  /* colNo */
  "abeles_single",                     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_single.m"/* pName */
};

static emlrtBCInfo th_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  17,                                  /* colNo */
  "sld",                               /* aName */
  "abeles_single",                     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  27,                                  /* lineNo */
  11,                                  /* colNo */
  "x",                                 /* aName */
  "abeles_single",                     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  21,                                  /* colNo */
  "sld",                               /* aName */
  "abeles_single",                     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wh_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  5,                                   /* colNo */
  "out",                               /* aName */
  "abeles_single",                     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_single.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo lj_emlrtRTEI = { 9,/* lineNo */
  7,                                   /* colNo */
  "abeles_single",                     /* fName */
  "/home/arwel/Documents/RascalDev/RAT/targetFunctions/common/Abeles/abeles_single.m"/* pName */
};

/* Function Definitions */
void abeles_single(const emlrtStack *sp, const emxArray_real_T *x, const
                   emxArray_real_T *sld, real_T nbair, real_T nbsub, real_T
                   nrepeats, real_T rfinal, real_T layers, real_T points,
                   emxArray_real_T *out)
{
  int32_T i;
  int32_T i1;
  real_T snair;
  real_T snsub;
  int32_T i2;
  int32_T loop;
  int32_T i3;
  real_T ar_tmp;
  real_T theta;
  real_T snlay;
  real_T psub_tmp_tmp;
  creal_T psub;
  real_T pair_re;
  real_T pair_im;
  real_T blast_re;
  real_T blast_im;
  creal_T MI[4];
  int32_T reploop;
  real_T re;
  int32_T nl;
  real_T ar;
  real_T rough;
  real_T rij_re;
  real_T rij_im;
  real_T brm;
  real_T bim;
  creal_T pimag;
  real_T x_re;
  real_T x_im;
  creal_T b_MI[4];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /*  nbair = nbairs(thisCont); */
  /*  nbsub = nbsubs(thisCont); */
  /*  ssub = ssubs(thisCont); */
  /*  nrepeats = nrepeatss(thisCont); */
  /*  resol = resols(thisCont); */
  i = (int32_T)points;
  i1 = out->size[0];
  out->size[0] = i;
  emxEnsureCapacity_real_T(sp, out, i1, &lj_emlrtRTEI);

  /* pi = 3.141592653589; */
  snair = 1.0 - nbair * 0.377451863036739;
  snsub = 1.0 - nbsub * 0.377451863036739;
  if (0 <= i - 1) {
    i2 = (int32_T)nrepeats;
    if (0 <= i2 - 1) {
      i3 = (int32_T)layers;
    }

    ar_tmp = rfinal * rfinal;
  }

  for (loop = 0; loop < i; loop++) {
    i1 = loop + 1;
    if ((i1 < 1) || (i1 > x->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, x->size[1], &uh_emlrtBCI, sp);
    }

    st.site = &mf_emlrtRSI;
    theta = x->data[loop] * 1.54 / 12.566370614359172;
    if ((theta < -1.0) || (theta > 1.0)) {
      emlrtErrorWithMessageIdR2018a(&st, &tb_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        4, "asin");
    }

    theta = muDoubleScalarAsin(theta);
    snlay = muDoubleScalarCos(theta);
    psub_tmp_tmp = snair * snair * (snlay * snlay);
    snlay = snsub * snsub - psub_tmp_tmp;
    psub.re = snlay;
    psub.im = snlay * 0.0;
    b_sqrt(&psub);
    pair_re = snair * muDoubleScalarSin(theta);
    pair_im = pair_re * 0.0;
    blast_re = 0.0;
    blast_im = 0.0;
    if (1 > sld->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, sld->size[0], &th_emlrtBCI, sp);
    }

    MI[0].re = 1.0;
    MI[0].im = 0.0;
    MI[3].re = 1.0;
    MI[3].im = 0.0;
    MI[2].re = 0.0;
    MI[2].im = 0.0;
    MI[1].re = 0.0;
    MI[1].im = 0.0;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, nrepeats, mxDOUBLE_CLASS, (int32_T)
      nrepeats, &ub_emlrtRTEI, sp);
    for (reploop = 0; reploop < i2; reploop++) {
      for (nl = 0; nl < i3; nl++) {
        i1 = nl + 1;
        if ((i1 < 1) || (i1 > sld->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, sld->size[0], &sh_emlrtBCI, sp);
        }

        i1 = nl + 1;
        if ((i1 < 1) || (i1 > sld->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, sld->size[0], &rh_emlrtBCI, sp);
        }

        i1 = (int32_T)(nl + 1U);
        if ((i1 < 1) || (i1 > sld->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, sld->size[0], &vh_emlrtBCI, sp);
        }

        rough = sld->data[(i1 + sld->size[0] * 2) - 1];
        snlay = 1.0 - sld->data[nl + sld->size[0]] * 0.377451863036739;
        theta = snlay * snlay - psub_tmp_tmp;
        pimag.re = theta;
        pimag.im = theta * 0.0;
        b_sqrt(&pimag);
        re = -78.956835208714864 * pair_re;
        snlay = -78.956835208714864 * pair_im;
        theta = rough * rough;
        ar = (re * pimag.re - snlay * pimag.im) * theta;
        rough = (re * pimag.im + snlay * pimag.re) * theta;
        if (rough == 0.0) {
          rij_re = ar / 2.3716;
          rij_im = 0.0;
        } else if (ar == 0.0) {
          rij_re = 0.0;
          rij_im = rough / 2.3716;
        } else {
          rij_re = ar / 2.3716;
          rij_im = rough / 2.3716;
        }

        if (rij_im == 0.0) {
          rij_re = muDoubleScalarExp(rij_re);
          rij_im = 0.0;
        } else if (muDoubleScalarIsInf(rij_im) && muDoubleScalarIsInf(rij_re) &&
                   (rij_re < 0.0)) {
          rij_re = 0.0;
          rij_im = 0.0;
        } else {
          theta = muDoubleScalarExp(rij_re / 2.0);
          rij_re = theta * (theta * muDoubleScalarCos(rij_im));
          rij_im = theta * (theta * muDoubleScalarSin(rij_im));
        }

        ar = pair_re - pimag.re;
        rough = pair_im - pimag.im;
        theta = pair_re + pimag.re;
        snlay = pair_im + pimag.im;
        if (snlay == 0.0) {
          if (rough == 0.0) {
            pair_re = ar / theta;
            pair_im = 0.0;
          } else if (ar == 0.0) {
            pair_re = 0.0;
            pair_im = rough / theta;
          } else {
            pair_re = ar / theta;
            pair_im = rough / theta;
          }
        } else if (theta == 0.0) {
          if (ar == 0.0) {
            pair_re = rough / snlay;
            pair_im = 0.0;
          } else if (rough == 0.0) {
            pair_re = 0.0;
            pair_im = -(ar / snlay);
          } else {
            pair_re = rough / snlay;
            pair_im = -(ar / snlay);
          }
        } else {
          brm = muDoubleScalarAbs(theta);
          bim = muDoubleScalarAbs(snlay);
          if (brm > bim) {
            bim = snlay / theta;
            theta += bim * snlay;
            pair_re = (ar + bim * rough) / theta;
            pair_im = (rough - bim * ar) / theta;
          } else if (bim == brm) {
            if (theta > 0.0) {
              bim = 0.5;
            } else {
              bim = -0.5;
            }

            if (snlay > 0.0) {
              theta = 0.5;
            } else {
              theta = -0.5;
            }

            pair_re = (ar * bim + rough * theta) / brm;
            pair_im = (rough * bim - ar * theta) / brm;
          } else {
            bim = theta / snlay;
            theta = snlay + bim * theta;
            pair_re = (bim * ar + rough) / theta;
            pair_im = (bim * rough - ar) / theta;
          }
        }

        re = pair_re * rij_re - pair_im * rij_im;
        snlay = pair_re * rij_im + pair_im * rij_re;
        x_re = blast_re * 0.0 - blast_im;
        x_im = blast_re + blast_im * 0.0;
        if (x_im == 0.0) {
          x_re = muDoubleScalarExp(x_re);
          x_im = 0.0;
        } else if (muDoubleScalarIsInf(x_im) && muDoubleScalarIsInf(x_re) &&
                   (x_re < 0.0)) {
          x_re = 0.0;
          x_im = 0.0;
        } else {
          theta = muDoubleScalarExp(x_re / 2.0);
          x_re = theta * (theta * muDoubleScalarCos(x_im));
          x_im = theta * (theta * muDoubleScalarSin(x_im));
        }

        pair_re = -blast_re * 0.0 - (-blast_im);
        pair_im = -blast_re + -blast_im * 0.0;
        if (pair_im == 0.0) {
          pair_re = muDoubleScalarExp(pair_re);
          pair_im = 0.0;
        } else if (muDoubleScalarIsInf(pair_im) && muDoubleScalarIsInf(pair_re) &&
                   (pair_re < 0.0)) {
          pair_re = 0.0;
          pair_im = 0.0;
        } else {
          theta = muDoubleScalarExp(pair_re / 2.0);
          pair_re = theta * (theta * muDoubleScalarCos(pair_im));
          pair_im = theta * (theta * muDoubleScalarSin(pair_im));
        }

        rij_re = re * pair_re - snlay * pair_im;
        bim = re * pair_im + snlay * pair_re;
        brm = pair_re;
        rij_im = pair_im;
        ar = re * x_re - snlay * x_im;
        theta = re * x_im + snlay * x_re;
        pair_re = pimag.re;
        pair_im = pimag.im;
        blast_re = 4.0799904592075231 * sld->data[nl] * pimag.re;
        blast_im = 4.0799904592075231 * sld->data[nl] * pimag.im;
        for (i1 = 0; i1 < 2; i1++) {
          snlay = MI[i1 + 2].re;
          rough = MI[i1 + 2].im;
          b_MI[i1].re = (MI[i1].re * x_re - MI[i1].im * x_im) + (snlay * rij_re
            - rough * bim);
          b_MI[i1].im = (MI[i1].re * x_im + MI[i1].im * x_re) + (snlay * bim +
            rough * rij_re);
          b_MI[i1 + 2].re = (MI[i1].re * ar - MI[i1].im * theta) + (snlay * brm
            - rough * rij_im);
          b_MI[i1 + 2].im = (MI[i1].re * theta + MI[i1].im * ar) + (snlay *
            rij_im + rough * brm);
        }

        memcpy(&MI[0], &b_MI[0], 4U * sizeof(creal_T));
      }
    }

    re = -78.956835208714864 * pair_re;
    snlay = -78.956835208714864 * pair_im;
    ar = (re * psub.re - snlay * psub.im) * ar_tmp;
    rough = (re * psub.im + snlay * psub.re) * ar_tmp;
    if (rough == 0.0) {
      rij_re = ar / 2.3716;
      rij_im = 0.0;
    } else if (ar == 0.0) {
      rij_re = 0.0;
      rij_im = rough / 2.3716;
    } else {
      rij_re = ar / 2.3716;
      rij_im = rough / 2.3716;
    }

    if (rij_im == 0.0) {
      rij_re = muDoubleScalarExp(rij_re);
      rij_im = 0.0;
    } else if (muDoubleScalarIsInf(rij_im) && muDoubleScalarIsInf(rij_re) &&
               (rij_re < 0.0)) {
      rij_re = 0.0;
      rij_im = 0.0;
    } else {
      theta = muDoubleScalarExp(rij_re / 2.0);
      rij_re = theta * (theta * muDoubleScalarCos(rij_im));
      rij_im = theta * (theta * muDoubleScalarSin(rij_im));
    }

    ar = pair_re - psub.re;
    rough = pair_im - psub.im;
    theta = pair_re + psub.re;
    snlay = pair_im + psub.im;
    if (snlay == 0.0) {
      if (rough == 0.0) {
        pair_re = ar / theta;
        pair_im = 0.0;
      } else if (ar == 0.0) {
        pair_re = 0.0;
        pair_im = rough / theta;
      } else {
        pair_re = ar / theta;
        pair_im = rough / theta;
      }
    } else if (theta == 0.0) {
      if (ar == 0.0) {
        pair_re = rough / snlay;
        pair_im = 0.0;
      } else if (rough == 0.0) {
        pair_re = 0.0;
        pair_im = -(ar / snlay);
      } else {
        pair_re = rough / snlay;
        pair_im = -(ar / snlay);
      }
    } else {
      brm = muDoubleScalarAbs(theta);
      bim = muDoubleScalarAbs(snlay);
      if (brm > bim) {
        bim = snlay / theta;
        theta += bim * snlay;
        pair_re = (ar + bim * rough) / theta;
        pair_im = (rough - bim * ar) / theta;
      } else if (bim == brm) {
        if (theta > 0.0) {
          bim = 0.5;
        } else {
          bim = -0.5;
        }

        if (snlay > 0.0) {
          theta = 0.5;
        } else {
          theta = -0.5;
        }

        pair_re = (ar * bim + rough * theta) / brm;
        pair_im = (rough * bim - ar * theta) / brm;
      } else {
        bim = theta / snlay;
        theta = snlay + bim * theta;
        pair_re = (bim * ar + rough) / theta;
        pair_im = (bim * rough - ar) / theta;
      }
    }

    re = pair_re * rij_re - pair_im * rij_im;
    snlay = pair_re * rij_im + pair_im * rij_re;
    x_re = blast_re * 0.0 - blast_im;
    x_im = blast_re + blast_im * 0.0;
    if (x_im == 0.0) {
      x_re = muDoubleScalarExp(x_re);
      x_im = 0.0;
    } else if (muDoubleScalarIsInf(x_im) && muDoubleScalarIsInf(x_re) && (x_re <
                0.0)) {
      x_re = 0.0;
      x_im = 0.0;
    } else {
      theta = muDoubleScalarExp(x_re / 2.0);
      x_re = theta * (theta * muDoubleScalarCos(x_im));
      x_im = theta * (theta * muDoubleScalarSin(x_im));
    }

    pair_re = -blast_re * 0.0 - (-blast_im);
    pair_im = -blast_re + -blast_im * 0.0;
    if (pair_im == 0.0) {
      pair_re = muDoubleScalarExp(pair_re);
      pair_im = 0.0;
    } else if (muDoubleScalarIsInf(pair_im) && muDoubleScalarIsInf(pair_re) &&
               (pair_re < 0.0)) {
      pair_re = 0.0;
      pair_im = 0.0;
    } else {
      theta = muDoubleScalarExp(pair_re / 2.0);
      pair_re = theta * (theta * muDoubleScalarCos(pair_im));
      pair_im = theta * (theta * muDoubleScalarSin(pair_im));
    }

    rij_re = re * pair_re - snlay * pair_im;
    bim = re * pair_im + snlay * pair_re;
    brm = re * x_re - snlay * x_im;
    rij_im = re * x_im + snlay * x_re;
    for (i1 = 0; i1 < 2; i1++) {
      ar = MI[i1 + 2].re;
      theta = MI[i1 + 2].im;
      b_MI[i1].re = (MI[i1].re * x_re - MI[i1].im * x_im) + (ar * rij_re - theta
        * bim);
      b_MI[i1].im = (MI[i1].re * x_im + MI[i1].im * x_re) + (ar * bim + theta *
        rij_re);
      b_MI[i1 + 2].re = (MI[i1].re * brm - MI[i1].im * rij_im) + (ar * pair_re -
        theta * pair_im);
      b_MI[i1 + 2].im = (MI[i1].re * rij_im + MI[i1].im * brm) + (ar * pair_im +
        theta * pair_re);
    }

    rough = b_MI[1].re * b_MI[1].re - b_MI[1].im * -b_MI[1].im;
    rij_re = b_MI[1].re * -b_MI[1].im + b_MI[1].im * b_MI[1].re;
    theta = b_MI[0].re * b_MI[0].re - b_MI[0].im * -b_MI[0].im;
    snlay = b_MI[0].re * -b_MI[0].im + b_MI[0].im * b_MI[0].re;
    if (snlay == 0.0) {
      if (rij_re == 0.0) {
        pair_re = rough / theta;
        pair_im = 0.0;
      } else if (rough == 0.0) {
        pair_re = 0.0;
        pair_im = rij_re / theta;
      } else {
        pair_re = rough / theta;
        pair_im = rij_re / theta;
      }
    } else if (theta == 0.0) {
      if (rough == 0.0) {
        pair_re = rij_re / snlay;
        pair_im = 0.0;
      } else if (rij_re == 0.0) {
        pair_re = 0.0;
        pair_im = -(rough / snlay);
      } else {
        pair_re = rij_re / snlay;
        pair_im = -(rough / snlay);
      }
    } else {
      brm = muDoubleScalarAbs(theta);
      bim = muDoubleScalarAbs(snlay);
      if (brm > bim) {
        bim = snlay / theta;
        theta += bim * snlay;
        pair_re = (rough + bim * rij_re) / theta;
        pair_im = (rij_re - bim * rough) / theta;
      } else if (bim == brm) {
        if (theta > 0.0) {
          bim = 0.5;
        } else {
          bim = -0.5;
        }

        if (snlay > 0.0) {
          theta = 0.5;
        } else {
          theta = -0.5;
        }

        pair_re = (rough * bim + rij_re * theta) / brm;
        pair_im = (rij_re * bim - rough * theta) / brm;
      } else {
        bim = theta / snlay;
        theta = snlay + bim * theta;
        pair_re = (bim * rough + rij_re) / theta;
        pair_im = (bim * rij_re - rough) / theta;
      }
    }

    i1 = (int32_T)(loop + 1U);
    if ((i1 < 1) || (i1 > out->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, out->size[0], &wh_emlrtBCI, sp);
    }

    out->data[i1 - 1] = muDoubleScalarHypot(pair_re, pair_im);
  }
}

/* End of code generation (abeles_single.c) */
