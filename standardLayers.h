//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// standardLayers.h
//
// Code generation for function 'standardLayers'
//
#ifndef STANDARDLAYERS_H
#define STANDARDLAYERS_H

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
  struct cell_wrap_8;
  struct cell_wrap_9;
  struct cell_wrap_10;
  struct struct0_T;
}

// Function Declarations
namespace RAT
{
  namespace normalTF
  {
    void b_standardLayers(const e_struct_T *problemStruct, const struct4_T
                          *controls, ::coder::array<real_T, 1U> &qzshifts, ::
                          coder::array<real_T, 1U> &scalefactors, ::coder::array<
                          real_T, 1U> &bulkIns, ::coder::array<real_T, 1U>
                          &bulkOuts, ::coder::array<real_T, 1U>
                          &resolutionParams, ::coder::array<real_T, 1U> &chis, ::
                          coder::array<cell_wrap_8, 1U> &reflectivity, ::coder::
                          array<cell_wrap_8, 1U> &simulation, ::coder::array<
                          cell_wrap_9, 1U> &shiftedData, ::coder::array<
                          cell_wrap_9, 1U> &backgrounds, ::coder::array<
                          cell_wrap_10, 2U> &layerSlds, ::coder::array<
                          cell_wrap_10, 2U> &sldProfiles, ::coder::array<
                          cell_wrap_10, 2U> &resampledLayers, ::coder::array<
                          real_T, 1U> &subRoughs);
    void standardLayers(const e_struct_T *problemStruct, const struct4_T
                        *controls, ::coder::array<real_T, 1U> &qzshifts, ::coder::
                        array<real_T, 1U> &scalefactors, ::coder::array<real_T,
                        1U> &bulkIns, ::coder::array<real_T, 1U> &bulkOuts, ::
                        coder::array<real_T, 1U> &resolutionParams, ::coder::
                        array<real_T, 1U> &chis, ::coder::array<cell_wrap_8, 1U>
                        &reflectivity, ::coder::array<cell_wrap_8, 1U>
                        &simulation, ::coder::array<cell_wrap_9, 1U>
                        &shiftedData, ::coder::array<cell_wrap_9, 1U>
                        &backgrounds, ::coder::array<cell_wrap_10, 2U>
                        &layerSlds, ::coder::array<cell_wrap_10, 2U>
                        &sldProfiles, ::coder::array<cell_wrap_10, 2U>
                        &resampledLayers, ::coder::array<real_T, 1U> &subRoughs);
    void standardLayers(const struct0_T *problemStruct, const struct4_T
                        *controls, ::coder::array<real_T, 1U> &qzshifts, ::coder::
                        array<real_T, 1U> &scalefactors, ::coder::array<real_T,
                        1U> &bulkIns, ::coder::array<real_T, 1U> &bulkOuts, ::
                        coder::array<real_T, 1U> &resolutionParams, ::coder::
                        array<real_T, 1U> &chis, ::coder::array<cell_wrap_8, 1U>
                        &reflectivity, ::coder::array<cell_wrap_8, 1U>
                        &simulation, ::coder::array<cell_wrap_9, 1U>
                        &shiftedData, ::coder::array<cell_wrap_9, 1U>
                        &backgrounds, ::coder::array<cell_wrap_10, 2U>
                        &layerSlds, ::coder::array<cell_wrap_10, 2U>
                        &sldProfiles, ::coder::array<cell_wrap_10, 2U>
                        &resampledLayers, ::coder::array<real_T, 1U> &subRoughs);
  }
}

#endif

// End of code generation (standardLayers.h)