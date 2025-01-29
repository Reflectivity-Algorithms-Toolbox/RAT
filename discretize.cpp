//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// discretize.cpp
//
// Code generation for function 'discretize'
//

// Include files
#include "discretize.h"
#include "bsearch.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    void b_discretize(const ::coder::array<real_T, 2U> &x, const real_T
                      edgesInput[3], ::coder::array<real_T, 2U> &bins)
    {
      int32_T i;
      int32_T nx;
      bins.set_size(1, x.size(1));
      nx = x.size(1);
      for (i = 0; i < nx; i++) {
        bins[i] = rtNaN;
      }

      nx = x.size(1);
      for (int32_T k{0}; k < nx; k++) {
        real_T bGuess;
        real_T d;
        d = x[k];
        bGuess = std::ceil(d / edgesInput[1]);
        if ((bGuess >= 1.0) && (bGuess < 3.0)) {
          i = static_cast<int32_T>(bGuess);
          if ((d >= edgesInput[i - 1]) && (d < edgesInput[i])) {
            bins[k] = bGuess;
          } else {
            bins[k] = internal::c_bsearch(edgesInput, d);
          }
        } else {
          bins[k] = internal::c_bsearch(edgesInput, d);
        }
      }
    }

    void discretize(const ::coder::array<real_T, 2U> &x, const real_T
                    edgesInput_data[], ::coder::array<real_T, 2U> &bins)
    {
      real_T delta;
      real_T leftEdge;
      int32_T i;
      int32_T nx;
      bins.set_size(1, x.size(1));
      nx = x.size(1);
      for (i = 0; i < nx; i++) {
        bins[i] = rtNaN;
      }

      nx = x.size(1);
      leftEdge = edgesInput_data[0];
      delta = edgesInput_data[1] - edgesInput_data[0];
      for (int32_T k{0}; k < nx; k++) {
        real_T d;
        d = x[k];
        if ((d >= leftEdge) && (d <= edgesInput_data[3])) {
          real_T bGuess;
          bGuess = std::ceil((d - leftEdge) / delta);
          if ((bGuess >= 1.0) && (bGuess < 4.0)) {
            i = static_cast<int32_T>(bGuess);
            if ((d >= edgesInput_data[i - 1]) && (d < edgesInput_data[i])) {
              bins[k] = bGuess;
            } else {
              bins[k] = internal::b_bsearch(edgesInput_data, d);
            }
          } else {
            bins[k] = internal::b_bsearch(edgesInput_data, d);
          }
        }
      }
    }
  }
}

// End of code generation (discretize.cpp)
