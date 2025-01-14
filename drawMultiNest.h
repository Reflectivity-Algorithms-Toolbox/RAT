//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// drawMultiNest.h
//
// Code generation for function 'drawMultiNest'
//
#ifndef DRAWMULTINEST_H
#define DRAWMULTINEST_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct e_struct_T;
  struct struct4_T;
}

// Function Declarations
namespace RAT
{
  void drawMultiNest(const ::coder::array<real_T, 1U> &fracvol, const ::coder::
                     array<real_T, 2U> &Bs, const ::coder::array<real_T, 2U>
                     &mus, real_T logLmin, const ::coder::array<real_T, 2U>
                     &prior, const e_struct_T *data_f1, const struct4_T *data_f2,
                     ::coder::array<real_T, 2U> &sample, real_T *logL);
}

#endif

// End of code generation (drawMultiNest.h)