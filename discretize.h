//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// discretize.h
//
// Code generation for function 'discretize'
//
#ifndef DISCRETIZE_H
#define DISCRETIZE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    void b_discretize(const ::coder::array<real_T, 2U> &x, const real_T
                      edgesInput[3], ::coder::array<real_T, 2U> &bins);
    void discretize(const ::coder::array<real_T, 2U> &x, const real_T
                    edgesInput_data[], ::coder::array<real_T, 2U> &bins);
  }
}

#endif

// End of code generation (discretize.h)
