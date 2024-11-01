//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// runNestedSampler.cpp
//
// Code generation for function 'runNestedSampler'
//

// Include files
#include "runNestedSampler.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "blockedSummation.h"
#include "getFittedPriors.h"
#include "makeEmptyBayesResultsStruct.h"
#include "nestedSampler.h"
#include "packParams.h"
#include "processBayes.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>

// Function Definitions
namespace RAT
{
  void runNestedSampler(const d_struct_T *problemStruct, const cell_12
                        *problemCells, const struct1_T *problemLimits, const
                        struct2_T *controls, const struct4_T *inPriors,
                        g_struct_T *b_problemStruct, struct5_T *result,
                        struct8_T *bayesResults)
  {
    static struct2_T b_controls;
    ::coder::array<cell_wrap_1, 1U> fitNames;
    ::coder::array<cell_wrap_11, 2U> expl_temp_sld;
    ::coder::array<cell_wrap_11, 1U> expl_temp_reflectivity;
    ::coder::array<real_T, 2U> b_bayesResults;
    ::coder::array<real_T, 2U> b_expl_temp;
    ::coder::array<real_T, 2U> bayesOutputs_bestParams;
    ::coder::array<real_T, 2U> bayesOutputs_chain;
    ::coder::array<real_T, 2U> expl_temp_mean;
    ::coder::array<real_T, 2U> expl_temp_percentile65;
    ::coder::array<real_T, 2U> expl_temp_percentile95;
    ::coder::array<real_T, 2U> r;
    ::coder::array<real_T, 2U> r1;
    ::coder::bounded_array<real_T, 1000U, 1U> expl_temp_sampleChi;
    c_struct_T expl_temp;
    d_struct_T c_problemStruct;
    j_struct_T nestResults;
    real_T H;
    int32_T b_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T loop_ub;
    c_problemStruct = *problemStruct;
    packParams(&c_problemStruct, problemCells->f7, problemCells->f8,
               problemCells->f9, problemCells->f10, problemCells->f11,
               problemCells->f12, problemCells->f13, problemCells->f20,
               problemLimits, &controls->checks, fitNames);

    //  Make an empty struct for bayesResults to hold the outputs of the
    //  calculation
    b_makeEmptyBayesResultsStruct(c_problemStruct.numberOfContrasts, coder::
      internal::b_strcmp(c_problemStruct.TF.data, c_problemStruct.TF.size),
      expl_temp_reflectivity, expl_temp_sld, expl_temp_sampleChi.data,
      &expl_temp_sampleChi.size[0], expl_temp_percentile95,
      expl_temp_percentile65, expl_temp_mean, &bayesResults->dreamParams,
      &bayesResults->dreamOutput, &expl_temp, b_expl_temp);

    // Deal with priors.
    // Tuning Parameters
    getFittedPriors(fitNames, inPriors->priorNames, inPriors->priorValues,
                    c_problemStruct.fitLimits, r);
    nestedSampler(&c_problemStruct, controls, problemLimits, problemCells,
                  controls->nLive, controls->nMCMC, controls->nsTolerance, r,
                  &bayesResults->nestedSamplerOutput.LogZ,
                  bayesResults->nestedSamplerOutput.nestSamples,
                  bayesResults->nestedSamplerOutput.postSamples, &H);

    //  Process the results...
    //  chain = nest_samples(:,1:end-1);
    if (1 > fitNames.size(0)) {
      loop_ub = 0;
    } else {
      loop_ub = fitNames.size(0);
    }

    b_loop_ub = bayesResults->nestedSamplerOutput.postSamples.size(0);
    b_bayesResults.set_size(bayesResults->nestedSamplerOutput.postSamples.size(0),
      loop_ub);
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b_bayesResults[i1 + b_bayesResults.size(0) * i] =
          bayesResults->nestedSamplerOutput.postSamples[i1 +
          bayesResults->nestedSamplerOutput.postSamples.size(0) * i];
      }
    }

    coder::blockedSummation(b_bayesResults,
      bayesResults->nestedSamplerOutput.postSamples.size(0), r1);
    bayesOutputs_bestParams.set_size(1, r1.size(1));
    b_loop_ub = r1.size(1);
    for (i = 0; i < b_loop_ub; i++) {
      bayesOutputs_bestParams[i] = r1[i] / static_cast<real_T>
        (bayesResults->nestedSamplerOutput.postSamples.size(0));
    }

    b_loop_ub = bayesResults->nestedSamplerOutput.postSamples.size(0);
    bayesOutputs_chain.set_size
      (bayesResults->nestedSamplerOutput.postSamples.size(0), loop_ub);
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        bayesOutputs_chain[i1 + bayesOutputs_chain.size(0) * i] =
          bayesResults->nestedSamplerOutput.postSamples[i1 +
          bayesResults->nestedSamplerOutput.postSamples.size(0) * i];
      }
    }

    b_controls = *controls;
    processBayes(bayesOutputs_bestParams, bayesOutputs_chain, &c_problemStruct,
                 problemCells, problemLimits, &b_controls, b_problemStruct,
                 result, &nestResults);
    bayesResults->predictionIntervals.reflectivity.set_size
      (nestResults.predictionIntervals.reflectivity.size(0));
    b_loop_ub = nestResults.predictionIntervals.reflectivity.size(0);
    for (i = 0; i < b_loop_ub; i++) {
      bayesResults->predictionIntervals.reflectivity[i] =
        nestResults.predictionIntervals.reflectivity[i];
    }

    bayesResults->predictionIntervals.sld.set_size
      (nestResults.predictionIntervals.sld.size(0),
       nestResults.predictionIntervals.sld.size(1));
    b_loop_ub = nestResults.predictionIntervals.sld.size(1);
    for (i = 0; i < b_loop_ub; i++) {
      int32_T c_loop_ub;
      c_loop_ub = nestResults.predictionIntervals.sld.size(0);
      for (i1 = 0; i1 < c_loop_ub; i1++) {
        bayesResults->predictionIntervals.sld[i1 +
          bayesResults->predictionIntervals.sld.size(0) * i] =
          nestResults.predictionIntervals.sld[i1 +
          nestResults.predictionIntervals.sld.size(0) * i];
      }
    }

    bayesResults->predictionIntervals.sampleChi.size[0] = 1000;
    std::copy(&nestResults.predictionIntervals.sampleChi[0],
              &nestResults.predictionIntervals.sampleChi[1000],
              &bayesResults->predictionIntervals.sampleChi.data[0]);
    bayesResults->confidenceIntervals = nestResults.confidenceIntervals;
    b_loop_ub = bayesResults->nestedSamplerOutput.postSamples.size(0);
    bayesResults->chain.set_size
      (bayesResults->nestedSamplerOutput.postSamples.size(0), loop_ub);
    for (i = 0; i < loop_ub; i++) {
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        bayesResults->chain[i1 + bayesResults->chain.size(0) * i] =
          bayesResults->nestedSamplerOutput.postSamples[i1 +
          bayesResults->nestedSamplerOutput.postSamples.size(0) * i];
      }
    }
  }
}

// End of code generation (runNestedSampler.cpp)
