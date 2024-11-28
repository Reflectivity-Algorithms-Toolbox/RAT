//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// processBayes.h
//
// Code generation for function 'processBayes'
//
#ifndef PROCESSBAYES_H
#define PROCESSBAYES_H

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
  struct struct2_T;
  struct struct3_T;
  struct g_struct_T;
  struct struct6_T;
  struct j_struct_T;
}

// Function Declarations
namespace RAT
{
  void processBayes(const ::coder::array<real_T, 2U> &bayesOutputs_bestParams,
                    const ::coder::array<real_T, 2U> &bayesOutputs_chain, const
                    e_struct_T *problemStruct, const struct2_T *problemLimits,
                    struct3_T *controls, g_struct_T *b_problemStruct, struct6_T *
                    result, j_struct_T *bayesResults);
}

#endif

// End of code generation (processBayes.h)
