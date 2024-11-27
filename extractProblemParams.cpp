//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// extractProblemParams.cpp
//
// Code generation for function 'extractProblemParams'
//

// Include files
#include "extractProblemParams.h"
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>

// Function Definitions
namespace RAT
{
  void extractProblemParams(const struct0_T *problemStruct, real_T
    *numberOfContrasts, char_T geometry_data[], int32_T geometry_size[2], ::
    coder::array<cell_wrap_14, 2U> &contrastBackgroundParams, ::coder::array<
    real_T, 2U> &contrastQzshifts, ::coder::array<real_T, 2U>
    &contrastScalefactors, ::coder::array<real_T, 2U> &contrastBulkIns, ::coder::
    array<real_T, 2U> &contrastBulkOuts, ::coder::array<real_T, 2U>
    &contrastResolutionParams, ::coder::array<real_T, 2U> &contrastDomainRatios,
    ::coder::array<real_T, 2U> &backgroundParams, ::coder::array<real_T, 2U>
    &qzshifts, ::coder::array<real_T, 2U> &scalefactors, ::coder::array<real_T,
    2U> &bulkIn, ::coder::array<real_T, 2U> &bulkOut, ::coder::array<real_T, 2U>
    &resolutionParams, ::coder::array<real_T, 2U> &domainRatio, ::coder::array<
    real_T, 2U> &dataPresent, real_T *nParams, ::coder::array<real_T, 2U>
    &params, real_T *numberOfLayers, ::coder::array<real_T, 2U> &resample, ::
    coder::array<cell_wrap_3, 2U> &contrastBackgroundTypes, ::coder::array<
    cell_wrap_3, 2U> &contrastBackgroundActions, ::coder::array<real_T, 2U>
    &contrastCustomFiles, boolean_T *useImaginary)
  {
    int32_T b_nParams;
    int32_T i;
    int32_T loop_ub;

    // Extract individual parameters from problem
    geometry_size[0] = 1;
    geometry_size[1] = problemStruct->geometry.size[1];
    loop_ub = problemStruct->geometry.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&problemStruct->geometry.data[0], &problemStruct->
                geometry.data[loop_ub], &geometry_data[0]);
    }

    cast(problemStruct->contrastBackgroundParams, contrastBackgroundParams);
    cast(problemStruct->contrastBackgroundTypes, contrastBackgroundTypes);
    cast(problemStruct->contrastBackgroundActions, contrastBackgroundActions);
    contrastQzshifts.set_size(1, problemStruct->contrastQzshifts.size(1));
    loop_ub = problemStruct->contrastQzshifts.size(1);
    for (i = 0; i < loop_ub; i++) {
      contrastQzshifts[i] = problemStruct->contrastQzshifts[i];
    }

    contrastScalefactors.set_size(1, problemStruct->contrastScalefactors.size(1));
    loop_ub = problemStruct->contrastScalefactors.size(1);
    for (i = 0; i < loop_ub; i++) {
      contrastScalefactors[i] = problemStruct->contrastScalefactors[i];
    }

    contrastBulkIns.set_size(1, problemStruct->contrastBulkIns.size(1));
    loop_ub = problemStruct->contrastBulkIns.size(1);
    for (i = 0; i < loop_ub; i++) {
      contrastBulkIns[i] = problemStruct->contrastBulkIns[i];
    }

    contrastBulkOuts.set_size(1, problemStruct->contrastBulkOuts.size(1));
    loop_ub = problemStruct->contrastBulkOuts.size(1);
    for (i = 0; i < loop_ub; i++) {
      contrastBulkOuts[i] = problemStruct->contrastBulkOuts[i];
    }

    contrastResolutionParams.set_size(1,
      problemStruct->contrastResolutionParams.size(1));
    loop_ub = problemStruct->contrastResolutionParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      contrastResolutionParams[i] = problemStruct->contrastResolutionParams[i];
    }

    contrastDomainRatios.set_size(1, problemStruct->contrastDomainRatios.size(1));
    loop_ub = problemStruct->contrastDomainRatios.size(1);
    for (i = 0; i < loop_ub; i++) {
      contrastDomainRatios[i] = problemStruct->contrastDomainRatios[i];
    }

    contrastCustomFiles.set_size(1, problemStruct->contrastCustomFiles.size(1));
    loop_ub = problemStruct->contrastCustomFiles.size(1);
    for (i = 0; i < loop_ub; i++) {
      contrastCustomFiles[i] = problemStruct->contrastCustomFiles[i];
    }

    backgroundParams.set_size(1, problemStruct->backgroundParams.size(1));
    loop_ub = problemStruct->backgroundParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      backgroundParams[i] = problemStruct->backgroundParams[i];
    }

    qzshifts.set_size(1, problemStruct->qzshifts.size(1));
    loop_ub = problemStruct->qzshifts.size(1);
    for (i = 0; i < loop_ub; i++) {
      qzshifts[i] = problemStruct->qzshifts[i];
    }

    scalefactors.set_size(1, problemStruct->scalefactors.size(1));
    loop_ub = problemStruct->scalefactors.size(1);
    for (i = 0; i < loop_ub; i++) {
      scalefactors[i] = problemStruct->scalefactors[i];
    }

    bulkIn.set_size(1, problemStruct->bulkIn.size(1));
    loop_ub = problemStruct->bulkIn.size(1);
    for (i = 0; i < loop_ub; i++) {
      bulkIn[i] = problemStruct->bulkIn[i];
    }

    bulkOut.set_size(1, problemStruct->bulkOut.size(1));
    loop_ub = problemStruct->bulkOut.size(1);
    for (i = 0; i < loop_ub; i++) {
      bulkOut[i] = problemStruct->bulkOut[i];
    }

    resolutionParams.set_size(1, problemStruct->resolutionParams.size(1));
    loop_ub = problemStruct->resolutionParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      resolutionParams[i] = problemStruct->resolutionParams[i];
    }

    domainRatio.set_size(1, problemStruct->domainRatio.size(1));
    loop_ub = problemStruct->domainRatio.size(1);
    for (i = 0; i < loop_ub; i++) {
      domainRatio[i] = problemStruct->domainRatio[i];
    }

    dataPresent.set_size(1, problemStruct->dataPresent.size(1));
    loop_ub = problemStruct->dataPresent.size(1);
    for (i = 0; i < loop_ub; i++) {
      dataPresent[i] = problemStruct->dataPresent[i];
    }

    b_nParams = problemStruct->params.size(1);
    params.set_size(1, problemStruct->params.size(1));
    loop_ub = problemStruct->params.size(1);
    for (i = 0; i < loop_ub; i++) {
      params[i] = problemStruct->params[i];
    }

    resample.set_size(1, problemStruct->resample.size(1));
    loop_ub = problemStruct->resample.size(1);
    for (i = 0; i < loop_ub; i++) {
      resample[i] = problemStruct->resample[i];
    }

    *numberOfContrasts = problemStruct->numberOfContrasts;
    *nParams = b_nParams;
    *numberOfLayers = problemStruct->numberOfLayers;
    *useImaginary = problemStruct->useImaginary;
  }
}

// End of code generation (extractProblemParams.cpp)
