//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// structConstructorHelper.h
//
// Code generation for function 'structConstructorHelper'
//
#ifndef STRUCTCONSTRUCTORHELPER_H
#define STRUCTCONSTRUCTORHELPER_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace RAT
{
  struct cell_wrap_34;
  struct cell_wrap_29;
  struct cell_wrap_35;
  struct cell_wrap_10;
}

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      void structConstructorHelper(const cell_wrap_34 *varargin_2, const
        cell_wrap_29 *varargin_4, const cell_wrap_34 *varargin_6, const
        cell_wrap_29 *varargin_8, const cell_wrap_35 *varargin_10, ::coder::
        array<cell_wrap_10, 1U> &s_reflectivity, ::coder::array<cell_wrap_10, 2U>
        &s_sld, ::coder::array<cell_wrap_10, 1U> &s_reflectivityXData, ::coder::
        array<cell_wrap_10, 2U> &s_sldXData, real_T s_sampleChi_data[], int32_T *
        s_sampleChi_size);
    }
  }
}

#endif

// End of code generation (structConstructorHelper.h)
