//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// backSort.h
//
// Code generation for function 'backSort'
//
#ifndef BACKSORT_H
#define BACKSORT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  void backSort(real_T contrastQzshifts, real_T contrastScalefactors, real_T
                contrastBulkIns, real_T contrastBulkOuts, const ::coder::array<
                real_T, 2U> &qzshifts, const ::coder::array<real_T, 2U>
                &scalefactors, const ::coder::array<real_T, 2U> &bulkIn, const ::
                coder::array<real_T, 2U> &bulkOut, real_T *outQzshift, real_T
                *outScalefactor, real_T *outBulkIn, real_T *outBulkOut);
}

#endif

// End of code generation (backSort.h)
