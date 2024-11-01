//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// reflectivityCalculation2.h
//
// Code generation for function 'reflectivityCalculation2'
//
#ifndef REFLECTIVITYCALCULATION2_H
#define REFLECTIVITYCALCULATION2_H

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
  struct f_struct_T;
  struct struct6_T;
  struct cell_wrap_8;
  struct cell_wrap_10;
  struct g_struct_T;
}

// Function Declarations
namespace RAT
{
  namespace domainsTF
  {
    void b_reflectivityCalculation(const g_struct_T *problemStruct, const
      cell_12 *problemCells, const struct2_T *controls, f_struct_T
      *contrastParams, struct6_T *calculationResults, ::coder::array<cell_wrap_8,
      1U> &reflectivity, ::coder::array<cell_wrap_8, 1U> &simulation, ::coder::
      array<cell_wrap_10, 1U> &shiftedData, ::coder::array<cell_wrap_10, 2U>
      &layerSlds, ::coder::array<cell_wrap_10, 2U> &sldProfiles, ::coder::array<
      cell_wrap_10, 2U> &resampledLayers);
    void b_reflectivityCalculation(const d_struct_T *problemStruct, const
      cell_12 *problemCells, const struct2_T *controls, f_struct_T
      *contrastParams, struct6_T *calculationResults, ::coder::array<cell_wrap_8,
      1U> &reflectivity, ::coder::array<cell_wrap_8, 1U> &simulation, ::coder::
      array<cell_wrap_10, 1U> &shiftedData, ::coder::array<cell_wrap_10, 2U>
      &layerSlds, ::coder::array<cell_wrap_10, 2U> &sldProfiles, ::coder::array<
      cell_wrap_10, 2U> &resampledLayers);
  }
}

#endif

// End of code generation (reflectivityCalculation2.h)
