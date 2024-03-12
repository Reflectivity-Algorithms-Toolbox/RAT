//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// parallelPoints2.h
//
// Code generation for function 'parallelPoints2'
//
#ifndef PARALLELPOINTS2_H
#define PARALLELPOINTS2_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct f_struct_T;
  struct cell_11;
  struct struct2_T;
  struct cell_wrap_8;
  struct cell_wrap_10;
}

// Function Declarations
namespace RAT
{
  namespace domainsTF
  {
    namespace standardLayers
    {
      void parallelPoints(const f_struct_T *problemStruct, const cell_11
                          *problemCells, const struct2_T *controls, ::coder::
                          array<real_T, 1U> &outSsubs, ::coder::array<real_T, 1U>
                          &backgroundParams, ::coder::array<real_T, 1U>
                          &qzshifts, ::coder::array<real_T, 1U> &scalefactors, ::
                          coder::array<real_T, 1U> &bulkIns, ::coder::array<
                          real_T, 1U> &bulkOuts, ::coder::array<real_T, 1U>
                          &resolutionParams, ::coder::array<real_T, 1U> &chis, ::
                          coder::array<cell_wrap_8, 1U> &reflectivity, ::coder::
                          array<cell_wrap_8, 1U> &simulation, ::coder::array<
                          cell_wrap_10, 1U> &shiftedData, ::coder::array<
                          cell_wrap_10, 2U> &layerSlds, ::coder::array<
                          cell_wrap_10, 2U> &domainSldProfiles, ::coder::array<
                          cell_wrap_10, 2U> &allLayers, ::coder::array<real_T,
                          1U> &allRoughs);
    }
  }
}

#endif

// End of code generation (parallelPoints2.h)
