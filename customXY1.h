//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// customXY1.h
//
// Code generation for function 'customXY1'
//
#ifndef CUSTOMXY1_H
#define CUSTOMXY1_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct d_struct_T;
  struct cell_12;
  struct struct2_T;
  struct cell_wrap_8;
  struct cell_wrap_10;
  struct g_struct_T;
}

// Function Declarations
namespace RAT
{
  namespace domainsTF
  {
    void b_customXY(const g_struct_T *problemStruct, const cell_12 *problemCells,
                    const struct2_T *controls, ::coder::array<real_T, 1U>
                    &backgroundParams, ::coder::array<real_T, 1U> &qzshifts, ::
                    coder::array<real_T, 1U> &scalefactors, ::coder::array<
                    real_T, 1U> &bulkIns, ::coder::array<real_T, 1U> &bulkOuts, ::
                    coder::array<real_T, 1U> &resolutionParams, ::coder::array<
                    real_T, 1U> &chis, ::coder::array<cell_wrap_8, 1U>
                    &reflectivity, ::coder::array<cell_wrap_8, 1U> &simulation, ::
                    coder::array<cell_wrap_10, 1U> &shiftedData, ::coder::array<
                    cell_wrap_10, 2U> &domainLayerSlds, ::coder::array<
                    cell_wrap_10, 2U> &domainSldProfiles, ::coder::array<
                    cell_wrap_10, 2U> &domainResampledLayers, ::coder::array<
                    real_T, 1U> &subRoughs);
    void b_customXY(const d_struct_T *problemStruct, const cell_12 *problemCells,
                    const struct2_T *controls, ::coder::array<real_T, 1U>
                    &backgroundParams, ::coder::array<real_T, 1U> &qzshifts, ::
                    coder::array<real_T, 1U> &scalefactors, ::coder::array<
                    real_T, 1U> &bulkIns, ::coder::array<real_T, 1U> &bulkOuts, ::
                    coder::array<real_T, 1U> &resolutionParams, ::coder::array<
                    real_T, 1U> &chis, ::coder::array<cell_wrap_8, 1U>
                    &reflectivity, ::coder::array<cell_wrap_8, 1U> &simulation, ::
                    coder::array<cell_wrap_10, 1U> &shiftedData, ::coder::array<
                    cell_wrap_10, 2U> &domainLayerSlds, ::coder::array<
                    cell_wrap_10, 2U> &domainSldProfiles, ::coder::array<
                    cell_wrap_10, 2U> &domainResampledLayers, ::coder::array<
                    real_T, 1U> &subRoughs);
  }
}

#endif

// End of code generation (customXY1.h)
