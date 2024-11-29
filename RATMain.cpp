//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// RATMain.cpp
//
// Code generation for function 'RATMain'
//

// Include files
#include "RATMain.h"
#include "RATMain_data.h"
#include "RATMain_internal_types.h"
#include "RATMain_rtwutil.h"
#include "RATMain_types.h"
#include "makeEmptyBayesResultsStruct.h"
#include "reflectivityCalculation.h"
#include "rt_nonfinite.h"
#include "runDE.h"
#include "runDREAM.h"
#include "runNestedSampler.h"
#include "runSimplex.h"
#include "strcmp.h"
#include "triggerEvent.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>

// Function Declarations
namespace RAT
{
  static void cast(const e_struct_T *b, struct0_T *c);
  static void cast(const struct0_T *b, e_struct_T *c);
  static void cast(const ::coder::array<cell_wrap_0, 2U> &t1_params, const ::
                   coder::array<cell_wrap_0, 2U> &t1_backgroundParams, const ::
                   coder::array<cell_wrap_0, 2U> &t1_scalefactors, const ::coder::
                   array<cell_wrap_0, 2U> &t1_qzshifts, const ::coder::array<
                   cell_wrap_0, 2U> &t1_bulkIns, const ::coder::array<
                   cell_wrap_0, 2U> &t1_bulkOuts, const ::coder::array<
                   cell_wrap_0, 2U> &t1_resolutionParams, const ::coder::array<
                   cell_wrap_0, 2U> &t1_domainRatios, ::coder::array<cell_wrap_7,
                   2U> &t2_params, ::coder::array<cell_wrap_7, 2U>
                   &t2_backgroundParams, ::coder::array<cell_wrap_7, 2U>
                   &t2_scalefactors, ::coder::array<cell_wrap_7, 2U>
                   &t2_qzshifts, ::coder::array<cell_wrap_7, 2U> &t2_bulkIns, ::
                   coder::array<cell_wrap_7, 2U> &t2_bulkOuts, ::coder::array<
                   cell_wrap_7, 2U> &t2_resolutionParams, ::coder::array<
                   cell_wrap_7, 2U> &t2_domainRatios);
  static void cast(const g_struct_T *b, struct0_T *c);
  static void cast(const ::coder::array<cell_wrap_13, 2U> &b, ::coder::array<
                   cell_wrap_3, 2U> &c);
  static void cast(const ::coder::array<cell_wrap_10, 2U> &b, ::coder::array<
                   cell_wrap_5, 2U> &c);
  static void cast(const ::coder::array<cell_wrap_10, 2U> &b, ::coder::array<
                   cell_wrap_4, 2U> &c);
  static void cast(const ::coder::array<cell_wrap_7, 2U> &t3_params, const ::
                   coder::array<cell_wrap_7, 2U> &t3_backgroundParams, const ::
                   coder::array<cell_wrap_7, 2U> &t3_scalefactors, const ::coder::
                   array<cell_wrap_7, 2U> &t3_qzshifts, const ::coder::array<
                   cell_wrap_7, 2U> &t3_bulkIns, const ::coder::array<
                   cell_wrap_7, 2U> &t3_bulkOuts, const ::coder::array<
                   cell_wrap_7, 2U> &t3_resolutionParams, const ::coder::array<
                   cell_wrap_7, 2U> &t3_domainRatios, ::coder::array<cell_wrap_0,
                   2U> &t4_params, ::coder::array<cell_wrap_0, 2U>
                   &t4_backgroundParams, ::coder::array<cell_wrap_0, 2U>
                   &t4_scalefactors, ::coder::array<cell_wrap_0, 2U>
                   &t4_qzshifts, ::coder::array<cell_wrap_0, 2U> &t4_bulkIns, ::
                   coder::array<cell_wrap_0, 2U> &t4_bulkOuts, ::coder::array<
                   cell_wrap_0, 2U> &t4_resolutionParams, ::coder::array<
                   cell_wrap_0, 2U> &t4_domainRatios);
  static void cast(const ::coder::array<cell_wrap_7, 2U> &b, ::coder::array<
                   cell_wrap_0, 2U> &c);
}

// Function Definitions
namespace RAT
{
  static void cast(const e_struct_T *b, struct0_T *c)
  {
    int32_T b_loop_ub;
    int32_T i;
    int32_T loop_ub;
    c->TF.size[0] = 1;
    c->TF.size[1] = b->TF.size[1];
    loop_ub = b->TF.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&b->TF.data[0], &b->TF.data[loop_ub], &c->TF.data[0]);
    }

    c->resample.set_size(1, b->resample.size(1));
    loop_ub = b->resample.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->resample[i] = b->resample[i];
    }

    c->data.set_size(1, b->data.size(1));
    loop_ub = b->data.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->data[i] = b->data[i];
    }

    c->dataPresent.set_size(1, b->dataPresent.size(1));
    loop_ub = b->dataPresent.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->dataPresent[i] = b->dataPresent[i];
    }

    c->dataLimits.set_size(1, b->dataLimits.size(1));
    loop_ub = b->dataLimits.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->dataLimits[i] = b->dataLimits[i];
    }

    c->simulationLimits.set_size(1, b->simulationLimits.size(1));
    loop_ub = b->simulationLimits.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->simulationLimits[i] = b->simulationLimits[i];
    }

    c->oilChiDataPresent.set_size(1, b->oilChiDataPresent.size(1));
    loop_ub = b->oilChiDataPresent.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->oilChiDataPresent[i] = b->oilChiDataPresent[i];
    }

    c->numberOfContrasts = b->numberOfContrasts;
    c->geometry.size[0] = 1;
    c->geometry.size[1] = b->geometry.size[1];
    loop_ub = b->geometry.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&b->geometry.data[0], &b->geometry.data[loop_ub],
                &c->geometry.data[0]);
    }

    c->useImaginary = b->useImaginary;
    c->repeatLayers.set_size(1, b->repeatLayers.size(1));
    loop_ub = b->repeatLayers.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->repeatLayers[i] = b->repeatLayers[i];
    }

    cast(b->contrastNames, c->contrastNames);
    cast(b->contrastBackgroundParams, c->contrastBackgroundParams);
    cast(b->contrastBackgroundTypes, c->contrastBackgroundTypes);
    cast(b->contrastBackgroundActions, c->contrastBackgroundActions);
    c->contrastQzshifts.set_size(1, b->contrastQzshifts.size(1));
    loop_ub = b->contrastQzshifts.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastQzshifts[i] = b->contrastQzshifts[i];
    }

    c->contrastScalefactors.set_size(1, b->contrastScalefactors.size(1));
    loop_ub = b->contrastScalefactors.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastScalefactors[i] = b->contrastScalefactors[i];
    }

    c->contrastBulkIns.set_size(1, b->contrastBulkIns.size(1));
    loop_ub = b->contrastBulkIns.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastBulkIns[i] = b->contrastBulkIns[i];
    }

    c->contrastBulkOuts.set_size(1, b->contrastBulkOuts.size(1));
    loop_ub = b->contrastBulkOuts.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastBulkOuts[i] = b->contrastBulkOuts[i];
    }

    c->contrastResolutionParams.set_size(1, b->contrastResolutionParams.size(1));
    loop_ub = b->contrastResolutionParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastResolutionParams[i] = b->contrastResolutionParams[i];
    }

    c->backgroundParams.set_size(1, b->backgroundParams.size(1));
    loop_ub = b->backgroundParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->backgroundParams[i] = b->backgroundParams[i];
    }

    c->qzshifts.set_size(1, b->qzshifts.size(1));
    loop_ub = b->qzshifts.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->qzshifts[i] = b->qzshifts[i];
    }

    c->scalefactors.set_size(1, b->scalefactors.size(1));
    loop_ub = b->scalefactors.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->scalefactors[i] = b->scalefactors[i];
    }

    c->bulkIn.set_size(1, b->bulkIn.size(1));
    loop_ub = b->bulkIn.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->bulkIn[i] = b->bulkIn[i];
    }

    c->bulkOut.set_size(1, b->bulkOut.size(1));
    loop_ub = b->bulkOut.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->bulkOut[i] = b->bulkOut[i];
    }

    c->resolutionParams.set_size(1, b->resolutionParams.size(1));
    loop_ub = b->resolutionParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->resolutionParams[i] = b->resolutionParams[i];
    }

    c->params.set_size(1, b->params.size(1));
    loop_ub = b->params.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->params[i] = b->params[i];
    }

    c->numberOfLayers = b->numberOfLayers;
    cast(b->contrastLayers, c->contrastLayers);
    cast(b->layersDetails, c->layersDetails);
    cast(b->customFiles, c->customFiles);
    c->modelType.size[0] = 1;
    c->modelType.size[1] = b->modelType.size[1];
    loop_ub = b->modelType.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&b->modelType.data[0], &b->modelType.data[loop_ub],
                &c->modelType.data[0]);
    }

    c->contrastCustomFiles.set_size(1, b->contrastCustomFiles.size(1));
    loop_ub = b->contrastCustomFiles.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastCustomFiles[i] = b->contrastCustomFiles[i];
    }

    c->contrastDomainRatios.set_size(1, b->contrastDomainRatios.size(1));
    loop_ub = b->contrastDomainRatios.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastDomainRatios[i] = b->contrastDomainRatios[i];
    }

    c->domainRatio.set_size(1, b->domainRatio.size(1));
    loop_ub = b->domainRatio.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->domainRatio[i] = b->domainRatio[i];
    }

    c->numberOfDomainContrasts = b->numberOfDomainContrasts;
    cast(b->domainContrastLayers, c->domainContrastLayers);
    c->fitParams.set_size(b->fitParams.size(0));
    loop_ub = b->fitParams.size(0);
    for (i = 0; i < loop_ub; i++) {
      c->fitParams[i] = b->fitParams[i];
    }

    c->otherParams.set_size(b->otherParams.size(0));
    loop_ub = b->otherParams.size(0);
    for (i = 0; i < loop_ub; i++) {
      c->otherParams[i] = b->otherParams[i];
    }

    c->fitLimits.set_size(b->fitLimits.size(0), 2);
    c->otherLimits.set_size(b->otherLimits.size(0), 2);
    loop_ub = b->fitLimits.size(0);
    b_loop_ub = b->otherLimits.size(0);
    for (i = 0; i < 2; i++) {
      int32_T i1;
      for (i1 = 0; i1 < loop_ub; i1++) {
        c->fitLimits[i1 + c->fitLimits.size(0) * i] = b->fitLimits[i1 +
          b->fitLimits.size(0) * i];
      }

      for (i1 = 0; i1 < b_loop_ub; i1++) {
        c->otherLimits[i1 + c->otherLimits.size(0) * i] = b->otherLimits[i1 +
          b->otherLimits.size(0) * i];
      }
    }

    cast(b->names.params, b->names.backgroundParams, b->names.scalefactors,
         b->names.qzshifts, b->names.bulkIns, b->names.bulkOuts,
         b->names.resolutionParams, b->names.domainRatios, c->names.params,
         c->names.backgroundParams, c->names.scalefactors, c->names.qzshifts,
         c->names.bulkIns, c->names.bulkOuts, c->names.resolutionParams,
         c->names.domainRatios);
  }

  static void cast(const struct0_T *b, e_struct_T *c)
  {
    int32_T b_loop_ub;
    int32_T i;
    int32_T loop_ub;
    c->TF.size[0] = 1;
    c->TF.size[1] = b->TF.size[1];
    loop_ub = b->TF.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&b->TF.data[0], &b->TF.data[loop_ub], &c->TF.data[0]);
    }

    c->resample.set_size(1, b->resample.size(1));
    loop_ub = b->resample.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->resample[i] = b->resample[i];
    }

    c->data.set_size(1, b->data.size(1));
    loop_ub = b->data.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->data[i] = b->data[i];
    }

    c->dataPresent.set_size(1, b->dataPresent.size(1));
    loop_ub = b->dataPresent.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->dataPresent[i] = b->dataPresent[i];
    }

    c->dataLimits.set_size(1, b->dataLimits.size(1));
    loop_ub = b->dataLimits.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->dataLimits[i] = b->dataLimits[i];
    }

    c->simulationLimits.set_size(1, b->simulationLimits.size(1));
    loop_ub = b->simulationLimits.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->simulationLimits[i] = b->simulationLimits[i];
    }

    c->oilChiDataPresent.set_size(1, b->oilChiDataPresent.size(1));
    loop_ub = b->oilChiDataPresent.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->oilChiDataPresent[i] = b->oilChiDataPresent[i];
    }

    c->numberOfContrasts = b->numberOfContrasts;
    c->geometry.size[0] = 1;
    c->geometry.size[1] = b->geometry.size[1];
    loop_ub = b->geometry.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&b->geometry.data[0], &b->geometry.data[loop_ub],
                &c->geometry.data[0]);
    }

    c->useImaginary = b->useImaginary;
    c->repeatLayers.set_size(1, b->repeatLayers.size(1));
    loop_ub = b->repeatLayers.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->repeatLayers[i] = b->repeatLayers[i];
    }

    cast(b->contrastNames, c->contrastNames);
    cast(b->contrastBackgroundParams, c->contrastBackgroundParams);
    cast(b->contrastBackgroundTypes, c->contrastBackgroundTypes);
    cast(b->contrastBackgroundActions, c->contrastBackgroundActions);
    c->contrastQzshifts.set_size(1, b->contrastQzshifts.size(1));
    loop_ub = b->contrastQzshifts.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastQzshifts[i] = b->contrastQzshifts[i];
    }

    c->contrastScalefactors.set_size(1, b->contrastScalefactors.size(1));
    loop_ub = b->contrastScalefactors.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastScalefactors[i] = b->contrastScalefactors[i];
    }

    c->contrastBulkIns.set_size(1, b->contrastBulkIns.size(1));
    loop_ub = b->contrastBulkIns.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastBulkIns[i] = b->contrastBulkIns[i];
    }

    c->contrastBulkOuts.set_size(1, b->contrastBulkOuts.size(1));
    loop_ub = b->contrastBulkOuts.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastBulkOuts[i] = b->contrastBulkOuts[i];
    }

    c->contrastResolutionParams.set_size(1, b->contrastResolutionParams.size(1));
    loop_ub = b->contrastResolutionParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastResolutionParams[i] = b->contrastResolutionParams[i];
    }

    c->backgroundParams.set_size(1, b->backgroundParams.size(1));
    loop_ub = b->backgroundParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->backgroundParams[i] = b->backgroundParams[i];
    }

    c->qzshifts.set_size(1, b->qzshifts.size(1));
    loop_ub = b->qzshifts.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->qzshifts[i] = b->qzshifts[i];
    }

    c->scalefactors.set_size(1, b->scalefactors.size(1));
    loop_ub = b->scalefactors.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->scalefactors[i] = b->scalefactors[i];
    }

    c->bulkIn.set_size(1, b->bulkIn.size(1));
    loop_ub = b->bulkIn.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->bulkIn[i] = b->bulkIn[i];
    }

    c->bulkOut.set_size(1, b->bulkOut.size(1));
    loop_ub = b->bulkOut.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->bulkOut[i] = b->bulkOut[i];
    }

    c->resolutionParams.set_size(1, b->resolutionParams.size(1));
    loop_ub = b->resolutionParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->resolutionParams[i] = b->resolutionParams[i];
    }

    c->params.set_size(1, b->params.size(1));
    loop_ub = b->params.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->params[i] = b->params[i];
    }

    c->numberOfLayers = b->numberOfLayers;
    cast(b->contrastLayers, c->contrastLayers);
    cast(b->layersDetails, c->layersDetails);
    cast(b->customFiles, c->customFiles);
    c->modelType.size[0] = 1;
    c->modelType.size[1] = b->modelType.size[1];
    loop_ub = b->modelType.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&b->modelType.data[0], &b->modelType.data[loop_ub],
                &c->modelType.data[0]);
    }

    c->contrastCustomFiles.set_size(1, b->contrastCustomFiles.size(1));
    loop_ub = b->contrastCustomFiles.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastCustomFiles[i] = b->contrastCustomFiles[i];
    }

    c->contrastDomainRatios.set_size(1, b->contrastDomainRatios.size(1));
    loop_ub = b->contrastDomainRatios.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastDomainRatios[i] = b->contrastDomainRatios[i];
    }

    c->domainRatio.set_size(1, b->domainRatio.size(1));
    loop_ub = b->domainRatio.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->domainRatio[i] = b->domainRatio[i];
    }

    c->numberOfDomainContrasts = b->numberOfDomainContrasts;
    cast(b->domainContrastLayers, c->domainContrastLayers);
    c->fitParams.set_size(b->fitParams.size(0));
    loop_ub = b->fitParams.size(0);
    for (i = 0; i < loop_ub; i++) {
      c->fitParams[i] = b->fitParams[i];
    }

    c->otherParams.set_size(b->otherParams.size(0));
    loop_ub = b->otherParams.size(0);
    for (i = 0; i < loop_ub; i++) {
      c->otherParams[i] = b->otherParams[i];
    }

    c->fitLimits.set_size(b->fitLimits.size(0), 2);
    c->otherLimits.set_size(b->otherLimits.size(0), 2);
    loop_ub = b->fitLimits.size(0);
    b_loop_ub = b->otherLimits.size(0);
    for (i = 0; i < 2; i++) {
      int32_T i1;
      for (i1 = 0; i1 < loop_ub; i1++) {
        c->fitLimits[i1 + c->fitLimits.size(0) * i] = b->fitLimits[i1 +
          b->fitLimits.size(0) * i];
      }

      for (i1 = 0; i1 < b_loop_ub; i1++) {
        c->otherLimits[i1 + c->otherLimits.size(0) * i] = b->otherLimits[i1 +
          b->otherLimits.size(0) * i];
      }
    }

    cast(b->names.params, b->names.backgroundParams, b->names.scalefactors,
         b->names.qzshifts, b->names.bulkIns, b->names.bulkOuts,
         b->names.resolutionParams, b->names.domainRatios, c->names.params,
         c->names.backgroundParams, c->names.scalefactors, c->names.qzshifts,
         c->names.bulkIns, c->names.bulkOuts, c->names.resolutionParams,
         c->names.domainRatios);
  }

  static void cast(const ::coder::array<cell_wrap_0, 2U> &t1_params, const ::
                   coder::array<cell_wrap_0, 2U> &t1_backgroundParams, const ::
                   coder::array<cell_wrap_0, 2U> &t1_scalefactors, const ::coder::
                   array<cell_wrap_0, 2U> &t1_qzshifts, const ::coder::array<
                   cell_wrap_0, 2U> &t1_bulkIns, const ::coder::array<
                   cell_wrap_0, 2U> &t1_bulkOuts, const ::coder::array<
                   cell_wrap_0, 2U> &t1_resolutionParams, const ::coder::array<
                   cell_wrap_0, 2U> &t1_domainRatios, ::coder::array<cell_wrap_7,
                   2U> &t2_params, ::coder::array<cell_wrap_7, 2U>
                   &t2_backgroundParams, ::coder::array<cell_wrap_7, 2U>
                   &t2_scalefactors, ::coder::array<cell_wrap_7, 2U>
                   &t2_qzshifts, ::coder::array<cell_wrap_7, 2U> &t2_bulkIns, ::
                   coder::array<cell_wrap_7, 2U> &t2_bulkOuts, ::coder::array<
                   cell_wrap_7, 2U> &t2_resolutionParams, ::coder::array<
                   cell_wrap_7, 2U> &t2_domainRatios)
  {
    cast(t1_params, t2_params);
    cast(t1_backgroundParams, t2_backgroundParams);
    cast(t1_scalefactors, t2_scalefactors);
    cast(t1_qzshifts, t2_qzshifts);
    cast(t1_bulkIns, t2_bulkIns);
    cast(t1_bulkOuts, t2_bulkOuts);
    cast(t1_resolutionParams, t2_resolutionParams);
    cast(t1_domainRatios, t2_domainRatios);
  }

  static void cast(const g_struct_T *b, struct0_T *c)
  {
    int32_T b_loop_ub;
    int32_T i;
    int32_T loop_ub;
    c->TF.size[0] = 1;
    c->TF.size[1] = b->TF.size[1];
    loop_ub = b->TF.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&b->TF.data[0], &b->TF.data[loop_ub], &c->TF.data[0]);
    }

    c->resample.set_size(1, b->resample.size(1));
    loop_ub = b->resample.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->resample[i] = b->resample[i];
    }

    c->data.set_size(1, b->data.size(1));
    loop_ub = b->data.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->data[i] = b->data[i];
    }

    c->dataPresent.set_size(1, b->dataPresent.size(1));
    loop_ub = b->dataPresent.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->dataPresent[i] = b->dataPresent[i];
    }

    c->dataLimits.set_size(1, b->dataLimits.size(1));
    loop_ub = b->dataLimits.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->dataLimits[i] = b->dataLimits[i];
    }

    c->simulationLimits.set_size(1, b->simulationLimits.size(1));
    loop_ub = b->simulationLimits.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->simulationLimits[i] = b->simulationLimits[i];
    }

    c->oilChiDataPresent.set_size(1, b->oilChiDataPresent.size(1));
    loop_ub = b->oilChiDataPresent.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->oilChiDataPresent[i] = b->oilChiDataPresent[i];
    }

    c->numberOfContrasts = b->numberOfContrasts;
    c->geometry.size[0] = 1;
    c->geometry.size[1] = b->geometry.size[1];
    loop_ub = b->geometry.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&b->geometry.data[0], &b->geometry.data[loop_ub],
                &c->geometry.data[0]);
    }

    c->useImaginary = b->useImaginary;
    c->repeatLayers.set_size(1, b->repeatLayers.size(1));
    loop_ub = b->repeatLayers.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->repeatLayers[i] = b->repeatLayers[i];
    }

    cast(b->contrastNames, c->contrastNames);
    cast(b->contrastBackgroundParams, c->contrastBackgroundParams);
    cast(b->contrastBackgroundTypes, c->contrastBackgroundTypes);
    cast(b->contrastBackgroundActions, c->contrastBackgroundActions);
    c->contrastQzshifts.set_size(1, b->contrastQzshifts.size(1));
    loop_ub = b->contrastQzshifts.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastQzshifts[i] = b->contrastQzshifts[i];
    }

    c->contrastScalefactors.set_size(1, b->contrastScalefactors.size(1));
    loop_ub = b->contrastScalefactors.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastScalefactors[i] = b->contrastScalefactors[i];
    }

    c->contrastBulkIns.set_size(1, b->contrastBulkIns.size(1));
    loop_ub = b->contrastBulkIns.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastBulkIns[i] = b->contrastBulkIns[i];
    }

    c->contrastBulkOuts.set_size(1, b->contrastBulkOuts.size(1));
    loop_ub = b->contrastBulkOuts.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastBulkOuts[i] = b->contrastBulkOuts[i];
    }

    c->contrastResolutionParams.set_size(1, b->contrastResolutionParams.size(1));
    loop_ub = b->contrastResolutionParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastResolutionParams[i] = b->contrastResolutionParams[i];
    }

    c->backgroundParams.set_size(1, b->backgroundParams.size(1));
    loop_ub = b->backgroundParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->backgroundParams[i] = b->backgroundParams[i];
    }

    c->qzshifts.set_size(1, b->qzshifts.size(1));
    loop_ub = b->qzshifts.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->qzshifts[i] = b->qzshifts[i];
    }

    c->scalefactors.set_size(1, b->scalefactors.size(1));
    loop_ub = b->scalefactors.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->scalefactors[i] = b->scalefactors[i];
    }

    c->bulkIn.set_size(1, b->bulkIn.size(1));
    loop_ub = b->bulkIn.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->bulkIn[i] = b->bulkIn[i];
    }

    c->bulkOut.set_size(1, b->bulkOut.size(1));
    loop_ub = b->bulkOut.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->bulkOut[i] = b->bulkOut[i];
    }

    c->resolutionParams.set_size(1, b->resolutionParams.size(1));
    loop_ub = b->resolutionParams.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->resolutionParams[i] = b->resolutionParams[i];
    }

    c->params.set_size(1, b->params.size(1));
    loop_ub = b->params.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->params[i] = b->params[i];
    }

    c->numberOfLayers = b->numberOfLayers;
    cast(b->contrastLayers, c->contrastLayers);
    cast(b->layersDetails, c->layersDetails);
    cast(b->customFiles, c->customFiles);
    c->modelType.size[0] = 1;
    c->modelType.size[1] = b->modelType.size[1];
    loop_ub = b->modelType.size[1];
    if (0 <= loop_ub - 1) {
      std::copy(&b->modelType.data[0], &b->modelType.data[loop_ub],
                &c->modelType.data[0]);
    }

    c->contrastCustomFiles.set_size(1, b->contrastCustomFiles.size(1));
    loop_ub = b->contrastCustomFiles.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastCustomFiles[i] = b->contrastCustomFiles[i];
    }

    c->contrastDomainRatios.set_size(1, b->contrastDomainRatios.size(1));
    loop_ub = b->contrastDomainRatios.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->contrastDomainRatios[i] = b->contrastDomainRatios[i];
    }

    c->domainRatio.set_size(1, b->domainRatio.size(1));
    loop_ub = b->domainRatio.size(1);
    for (i = 0; i < loop_ub; i++) {
      c->domainRatio[i] = b->domainRatio[i];
    }

    c->numberOfDomainContrasts = b->numberOfDomainContrasts;
    cast(b->domainContrastLayers, c->domainContrastLayers);
    c->fitParams.set_size(b->fitParams.size(0));
    loop_ub = b->fitParams.size(0);
    for (i = 0; i < loop_ub; i++) {
      c->fitParams[i] = b->fitParams[i];
    }

    c->otherParams.set_size(b->otherParams.size(0));
    loop_ub = b->otherParams.size(0);
    for (i = 0; i < loop_ub; i++) {
      c->otherParams[i] = b->otherParams[i];
    }

    c->fitLimits.set_size(b->fitLimits.size(0), 2);
    c->otherLimits.set_size(b->otherLimits.size(0), 2);
    loop_ub = b->fitLimits.size(0);
    b_loop_ub = b->otherLimits.size(0);
    for (i = 0; i < 2; i++) {
      int32_T i1;
      for (i1 = 0; i1 < loop_ub; i1++) {
        c->fitLimits[i1 + c->fitLimits.size(0) * i] = b->fitLimits[i1 +
          b->fitLimits.size(0) * i];
      }

      for (i1 = 0; i1 < b_loop_ub; i1++) {
        c->otherLimits[i1 + c->otherLimits.size(0) * i] = b->otherLimits[i1 +
          b->otherLimits.size(0) * i];
      }
    }

    cast(b->names.params, b->names.backgroundParams, b->names.scalefactors,
         b->names.qzshifts, b->names.bulkIns, b->names.bulkOuts,
         b->names.resolutionParams, b->names.domainRatios, c->names.params,
         c->names.backgroundParams, c->names.scalefactors, c->names.qzshifts,
         c->names.bulkIns, c->names.bulkOuts, c->names.resolutionParams,
         c->names.domainRatios);
  }

  static void cast(const ::coder::array<cell_wrap_13, 2U> &b, ::coder::array<
                   cell_wrap_3, 2U> &c)
  {
    int32_T i;
    c.set_size(1, b.size(1));
    i = b.size(1) - 1;
    for (int32_T i1{0}; i1 <= i; i1++) {
      int32_T loop_ub;
      c[i1].f1.size[0] = 1;
      loop_ub = b[i1].f1.size[1];
      c[i1].f1.size[1] = b[i1].f1.size[1];
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        c[i1].f1.data[i2] = b[i1].f1.data[i2];
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_10, 2U> &b, ::coder::array<
                   cell_wrap_5, 2U> &c)
  {
    int32_T i;
    c.set_size(b.size(0), b.size(1));
    i = b.size(0) * b.size(1);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      c[i1].f1.size[0] = b[i1].f1.size(0);
      loop_ub = b[i1].f1.size(1);
      c[i1].f1.size[1] = b[i1].f1.size(1);
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = b[i1].f1.size(0);
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          c[i1].f1.data[i3 + c[i1].f1.size[0] * i2] = b[i1].f1[i3 + b[i1].
            f1.size(0) * i2];
        }
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_10, 2U> &b, ::coder::array<
                   cell_wrap_4, 2U> &c)
  {
    int32_T i;
    c.set_size(1, b.size(1));
    i = b.size(1) - 1;
    for (int32_T i1{0}; i1 <= i; i1++) {
      int32_T loop_ub;
      loop_ub = b[i1].f1.size(1);
      c[c.size(0) * i1].f1.set_size(b[b.size(0) * i1].f1.size(0), b[b.size(0) *
        i1].f1.size(1));
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = b[i1].f1.size(0);
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          c[i1].f1[i3 + c[i1].f1.size(0) * i2] = b[i1].f1[i3 + b[i1].f1.size(0) *
            i2];
        }
      }
    }
  }

  static void cast(const ::coder::array<cell_wrap_7, 2U> &t3_params, const ::
                   coder::array<cell_wrap_7, 2U> &t3_backgroundParams, const ::
                   coder::array<cell_wrap_7, 2U> &t3_scalefactors, const ::coder::
                   array<cell_wrap_7, 2U> &t3_qzshifts, const ::coder::array<
                   cell_wrap_7, 2U> &t3_bulkIns, const ::coder::array<
                   cell_wrap_7, 2U> &t3_bulkOuts, const ::coder::array<
                   cell_wrap_7, 2U> &t3_resolutionParams, const ::coder::array<
                   cell_wrap_7, 2U> &t3_domainRatios, ::coder::array<cell_wrap_0,
                   2U> &t4_params, ::coder::array<cell_wrap_0, 2U>
                   &t4_backgroundParams, ::coder::array<cell_wrap_0, 2U>
                   &t4_scalefactors, ::coder::array<cell_wrap_0, 2U>
                   &t4_qzshifts, ::coder::array<cell_wrap_0, 2U> &t4_bulkIns, ::
                   coder::array<cell_wrap_0, 2U> &t4_bulkOuts, ::coder::array<
                   cell_wrap_0, 2U> &t4_resolutionParams, ::coder::array<
                   cell_wrap_0, 2U> &t4_domainRatios)
  {
    cast(t3_params, t4_params);
    cast(t3_backgroundParams, t4_backgroundParams);
    cast(t3_scalefactors, t4_scalefactors);
    cast(t3_qzshifts, t4_qzshifts);
    cast(t3_bulkIns, t4_bulkIns);
    cast(t3_bulkOuts, t4_bulkOuts);
    cast(t3_resolutionParams, t4_resolutionParams);
    cast(t3_domainRatios, t4_domainRatios);
  }

  static void cast(const ::coder::array<cell_wrap_7, 2U> &b, ::coder::array<
                   cell_wrap_0, 2U> &c)
  {
    int32_T i;
    c.set_size(1, b.size(1));
    i = b.size(1) - 1;
    for (int32_T i1{0}; i1 <= i; i1++) {
      int32_T loop_ub;
      c[i1].f1.size[0] = 1;
      loop_ub = b[i1].f1.size(1);
      c[i1].f1.size[1] = b[i1].f1.size(1);
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        c[i1].f1.data[i2] = b[i1].f1[i2];
      }
    }
  }

  void RATMain(struct0_T *problemStruct, const struct2_T *problemLimits,
               struct3_T *controls, const struct5_T *priors, struct6_T *result,
               struct9_T *bayesResults)
  {
    static e_struct_T b_problemStruct;
    static g_struct_T c_problemStruct;
    c_struct_T bayesResults_nestedSamplerOutput;
    f_struct_T b_expl_temp;
    f_struct_T expl_temp;
    makeEmptyBayesResultsStruct(problemStruct->numberOfContrasts, coder::
      internal::b_strcmp(problemStruct->TF.data, problemStruct->TF.size),
      controls->nChains, bayesResults->predictionIntervals.reflectivity,
      bayesResults->predictionIntervals.sld,
      bayesResults->predictionIntervals.sampleChi.data,
      &bayesResults->predictionIntervals.sampleChi.size[0],
      bayesResults->confidenceIntervals.percentile95,
      bayesResults->confidenceIntervals.percentile65,
      bayesResults->confidenceIntervals.mean, &bayesResults->dreamParams,
      &bayesResults->dreamOutput, &bayesResults_nestedSamplerOutput,
      bayesResults->chain);
    bayesResults->nestedSamplerOutput.LogZ =
      bayesResults_nestedSamplerOutput.LogZ;
    bayesResults->nestedSamplerOutput.nestSamples.set_size(1, 2);
    bayesResults->nestedSamplerOutput.postSamples.set_size(1, 2);
    bayesResults->nestedSamplerOutput.nestSamples[0] =
      bayesResults_nestedSamplerOutput.nestSamples.data[0];
    bayesResults->nestedSamplerOutput.postSamples[0] =
      bayesResults_nestedSamplerOutput.postSamples.data[0];
    bayesResults->nestedSamplerOutput.nestSamples
      [bayesResults->nestedSamplerOutput.nestSamples.size(0)] =
      bayesResults_nestedSamplerOutput.nestSamples.data[1];
    bayesResults->nestedSamplerOutput.postSamples
      [bayesResults->nestedSamplerOutput.postSamples.size(0)] =
      bayesResults_nestedSamplerOutput.postSamples.data[1];
    if (problemStruct->numberOfContrasts > 0.0) {
      int32_T b_index;
      int32_T i;
      int32_T i1;
      int32_T loop_ub;
      if (coder::internal::c_strcmp(controls->procedure.data,
           controls->procedure.size)) {
        b_index = 0;
      } else if (coder::internal::d_strcmp(controls->procedure.data,
                  controls->procedure.size)) {
        b_index = 1;
      } else if (coder::internal::e_strcmp(controls->procedure.data,
                  controls->procedure.size)) {
        b_index = 2;
      } else if (coder::internal::f_strcmp(controls->procedure.data,
                  controls->procedure.size)) {
        b_index = 3;
      } else if (coder::internal::g_strcmp(controls->procedure.data,
                  controls->procedure.size)) {
        b_index = 4;
      } else {
        b_index = -1;
      }

      switch (b_index) {
       case 0:
        //  Just a single reflectivity calculation
        controls->calcSldDuringFit = true;
        reflectivityCalculation(problemStruct, problemLimits->param,
          problemLimits->backgroundParam, problemLimits->scalefactor,
          problemLimits->qzshift, problemLimits->bulkIn, problemLimits->bulkOut,
          problemLimits->resolutionParam, problemLimits->domainRatio, controls,
          &expl_temp);
        result->reflectivity.set_size(expl_temp.reflectivity.size(0));
        b_index = expl_temp.reflectivity.size(0);
        for (i = 0; i < b_index; i++) {
          result->reflectivity[i] = expl_temp.reflectivity[i];
        }

        result->simulation.set_size(expl_temp.simulation.size(0));
        b_index = expl_temp.simulation.size(0);
        for (i = 0; i < b_index; i++) {
          result->simulation[i] = expl_temp.simulation[i];
        }

        result->shiftedData.set_size(expl_temp.shiftedData.size(0));
        b_index = expl_temp.shiftedData.size(0);
        for (i = 0; i < b_index; i++) {
          result->shiftedData[i] = expl_temp.shiftedData[i];
        }

        result->backgrounds.set_size(expl_temp.backgrounds.size(0));
        b_index = expl_temp.backgrounds.size(0);
        for (i = 0; i < b_index; i++) {
          result->backgrounds[i] = expl_temp.backgrounds[i];
        }

        result->layerSlds.set_size(expl_temp.layerSlds.size(0),
          expl_temp.layerSlds.size(1));
        b_index = expl_temp.layerSlds.size(1);
        for (i = 0; i < b_index; i++) {
          loop_ub = expl_temp.layerSlds.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            result->layerSlds[i1 + result->layerSlds.size(0) * i] =
              expl_temp.layerSlds[i1 + expl_temp.layerSlds.size(0) * i];
          }
        }

        result->sldProfiles.set_size(expl_temp.sldProfiles.size(0),
          expl_temp.sldProfiles.size(1));
        b_index = expl_temp.sldProfiles.size(1);
        for (i = 0; i < b_index; i++) {
          loop_ub = expl_temp.sldProfiles.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            result->sldProfiles[i1 + result->sldProfiles.size(0) * i] =
              expl_temp.sldProfiles[i1 + expl_temp.sldProfiles.size(0) * i];
          }
        }

        result->resampledLayers.set_size(expl_temp.resampledLayers.size(0),
          expl_temp.resampledLayers.size(1));
        b_index = expl_temp.resampledLayers.size(1);
        for (i = 0; i < b_index; i++) {
          loop_ub = expl_temp.resampledLayers.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            result->resampledLayers[i1 + result->resampledLayers.size(0) * i] =
              expl_temp.resampledLayers[i1 + expl_temp.resampledLayers.size(0) *
              i];
          }
        }

        result->calculationResults = expl_temp.calculationResults;
        result->contrastParams = expl_temp.contrastParams;
        b_index = expl_temp.fitParams.size(0);
        result->fitParams.set_size(expl_temp.fitParams.size(0), 1);
        for (i = 0; i < 1; i++) {
          for (i1 = 0; i1 < b_index; i1++) {
            result->fitParams[i1] = expl_temp.fitParams[i1];
          }
        }

        result->fitNames.set_size(expl_temp.fitNames.size(0));
        b_index = expl_temp.fitNames.size(0);
        for (i = 0; i < b_index; i++) {
          result->fitNames[i] = expl_temp.fitNames[i];
        }
        break;

       case 1:
        if (!coder::internal::t_strcmp(controls->display.data,
             controls->display.size)) {
          triggerEvent();
        }

        cast(problemStruct, &b_problemStruct);
        runSimplex(&b_problemStruct, problemLimits->param,
                   problemLimits->backgroundParam, problemLimits->scalefactor,
                   problemLimits->qzshift, problemLimits->bulkIn,
                   problemLimits->bulkOut, problemLimits->resolutionParam,
                   problemLimits->domainRatio, controls, &b_expl_temp);
        expl_temp.reflectivity.set_size(b_expl_temp.reflectivity.size(0));
        b_index = b_expl_temp.reflectivity.size(0);
        for (i = 0; i < b_index; i++) {
          expl_temp.reflectivity[i] = b_expl_temp.reflectivity[i];
        }

        expl_temp.simulation.set_size(b_expl_temp.simulation.size(0));
        b_index = b_expl_temp.simulation.size(0);
        for (i = 0; i < b_index; i++) {
          expl_temp.simulation[i] = b_expl_temp.simulation[i];
        }

        expl_temp.shiftedData.set_size(b_expl_temp.shiftedData.size(0));
        b_index = b_expl_temp.shiftedData.size(0);
        for (i = 0; i < b_index; i++) {
          expl_temp.shiftedData[i] = b_expl_temp.shiftedData[i];
        }

        expl_temp.backgrounds.set_size(b_expl_temp.backgrounds.size(0));
        b_index = b_expl_temp.backgrounds.size(0);
        for (i = 0; i < b_index; i++) {
          expl_temp.backgrounds[i] = b_expl_temp.backgrounds[i];
        }

        expl_temp.layerSlds.set_size(b_expl_temp.layerSlds.size(0),
          b_expl_temp.layerSlds.size(1));
        b_index = b_expl_temp.layerSlds.size(1);
        for (i = 0; i < b_index; i++) {
          loop_ub = b_expl_temp.layerSlds.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            expl_temp.layerSlds[i1 + expl_temp.layerSlds.size(0) * i] =
              b_expl_temp.layerSlds[i1 + b_expl_temp.layerSlds.size(0) * i];
          }
        }

        expl_temp.sldProfiles.set_size(b_expl_temp.sldProfiles.size(0),
          b_expl_temp.sldProfiles.size(1));
        b_index = b_expl_temp.sldProfiles.size(1);
        for (i = 0; i < b_index; i++) {
          loop_ub = b_expl_temp.sldProfiles.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            expl_temp.sldProfiles[i1 + expl_temp.sldProfiles.size(0) * i] =
              b_expl_temp.sldProfiles[i1 + b_expl_temp.sldProfiles.size(0) * i];
          }
        }

        expl_temp.resampledLayers.set_size(b_expl_temp.resampledLayers.size(0),
          b_expl_temp.resampledLayers.size(1));
        b_index = b_expl_temp.resampledLayers.size(1);
        for (i = 0; i < b_index; i++) {
          loop_ub = b_expl_temp.resampledLayers.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            expl_temp.resampledLayers[i1 + expl_temp.resampledLayers.size(0) * i]
              = b_expl_temp.resampledLayers[i1 +
              b_expl_temp.resampledLayers.size(0) * i];
          }
        }

        expl_temp.fitParams.set_size(b_expl_temp.fitParams.size(0));
        b_index = b_expl_temp.fitParams.size(0);
        for (i = 0; i < b_index; i++) {
          expl_temp.fitParams[i] = b_expl_temp.fitParams[i];
        }

        expl_temp.fitNames.set_size(b_expl_temp.fitNames.size(0));
        b_index = b_expl_temp.fitNames.size(0);
        for (i = 0; i < b_index; i++) {
          expl_temp.fitNames[i] = b_expl_temp.fitNames[i];
        }

        cast(&b_problemStruct, problemStruct);
        result->reflectivity.set_size(expl_temp.reflectivity.size(0));
        b_index = expl_temp.reflectivity.size(0);
        for (i = 0; i < b_index; i++) {
          result->reflectivity[i] = expl_temp.reflectivity[i];
        }

        result->simulation.set_size(expl_temp.simulation.size(0));
        b_index = expl_temp.simulation.size(0);
        for (i = 0; i < b_index; i++) {
          result->simulation[i] = expl_temp.simulation[i];
        }

        result->shiftedData.set_size(expl_temp.shiftedData.size(0));
        b_index = expl_temp.shiftedData.size(0);
        for (i = 0; i < b_index; i++) {
          result->shiftedData[i] = expl_temp.shiftedData[i];
        }

        result->backgrounds.set_size(expl_temp.backgrounds.size(0));
        b_index = expl_temp.backgrounds.size(0);
        for (i = 0; i < b_index; i++) {
          result->backgrounds[i] = expl_temp.backgrounds[i];
        }

        result->layerSlds.set_size(expl_temp.layerSlds.size(0),
          expl_temp.layerSlds.size(1));
        b_index = expl_temp.layerSlds.size(1);
        for (i = 0; i < b_index; i++) {
          loop_ub = expl_temp.layerSlds.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            result->layerSlds[i1 + result->layerSlds.size(0) * i] =
              expl_temp.layerSlds[i1 + expl_temp.layerSlds.size(0) * i];
          }
        }

        result->sldProfiles.set_size(expl_temp.sldProfiles.size(0),
          expl_temp.sldProfiles.size(1));
        b_index = expl_temp.sldProfiles.size(1);
        for (i = 0; i < b_index; i++) {
          loop_ub = expl_temp.sldProfiles.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            result->sldProfiles[i1 + result->sldProfiles.size(0) * i] =
              expl_temp.sldProfiles[i1 + expl_temp.sldProfiles.size(0) * i];
          }
        }

        result->resampledLayers.set_size(expl_temp.resampledLayers.size(0),
          expl_temp.resampledLayers.size(1));
        b_index = expl_temp.resampledLayers.size(1);
        for (i = 0; i < b_index; i++) {
          loop_ub = expl_temp.resampledLayers.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            result->resampledLayers[i1 + result->resampledLayers.size(0) * i] =
              expl_temp.resampledLayers[i1 + expl_temp.resampledLayers.size(0) *
              i];
          }
        }

        result->calculationResults = b_expl_temp.calculationResults;
        result->contrastParams = b_expl_temp.contrastParams;
        b_index = expl_temp.fitParams.size(0);
        result->fitParams.set_size(expl_temp.fitParams.size(0), 1);
        for (i = 0; i < 1; i++) {
          for (i1 = 0; i1 < b_index; i1++) {
            result->fitParams[i1] = expl_temp.fitParams[i1];
          }
        }

        result->fitNames.set_size(expl_temp.fitNames.size(0));
        b_index = expl_temp.fitNames.size(0);
        for (i = 0; i < b_index; i++) {
          result->fitNames[i] = expl_temp.fitNames[i];
        }
        break;

       case 2:
        if (!coder::internal::t_strcmp(controls->display.data,
             controls->display.size)) {
          d_triggerEvent();
        }

        cast(problemStruct, &b_problemStruct);
        runDE(&b_problemStruct, problemLimits->param,
              problemLimits->backgroundParam, problemLimits->scalefactor,
              problemLimits->qzshift, problemLimits->bulkIn,
              problemLimits->bulkOut, problemLimits->resolutionParam,
              problemLimits->domainRatio, controls, &c_problemStruct, result);
        cast(&c_problemStruct, problemStruct);
        break;

       case 3:
        if (!coder::internal::t_strcmp(controls->display.data,
             controls->display.size)) {
          i_triggerEvent();
        }

        cast(problemStruct, &b_problemStruct);
        runNestedSampler(&b_problemStruct, problemLimits, controls,
                         priors->priorNames, priors->priorValues,
                         &c_problemStruct, result,
                         &bayesResults->predictionIntervals,
                         &bayesResults->confidenceIntervals,
                         &bayesResults->dreamParams, &bayesResults->dreamOutput,
                         &bayesResults->nestedSamplerOutput, bayesResults->chain);
        cast(&c_problemStruct, problemStruct);
        break;

       case 4:
        if (!coder::internal::t_strcmp(controls->display.data,
             controls->display.size)) {
          j_triggerEvent();
        }

        cast(problemStruct, &b_problemStruct);
        runDREAM(&b_problemStruct, problemLimits, controls, priors->priorNames,
                 priors->priorValues, &c_problemStruct, result,
                 &bayesResults->predictionIntervals,
                 &bayesResults->confidenceIntervals, &bayesResults->dreamParams,
                 &bayesResults->dreamOutput, &bayesResults_nestedSamplerOutput,
                 bayesResults->chain);
        cast(&c_problemStruct, problemStruct);
        bayesResults->nestedSamplerOutput.LogZ =
          bayesResults_nestedSamplerOutput.LogZ;
        bayesResults->nestedSamplerOutput.nestSamples.set_size(1, 2);
        bayesResults->nestedSamplerOutput.postSamples.set_size(1, 2);
        bayesResults->nestedSamplerOutput.nestSamples[0] =
          bayesResults_nestedSamplerOutput.nestSamples.data[0];
        bayesResults->nestedSamplerOutput.postSamples[0] =
          bayesResults_nestedSamplerOutput.postSamples.data[0];
        bayesResults->nestedSamplerOutput.nestSamples
          [bayesResults->nestedSamplerOutput.nestSamples.size(0)] =
          bayesResults_nestedSamplerOutput.nestSamples.data[1];
        bayesResults->nestedSamplerOutput.postSamples
          [bayesResults->nestedSamplerOutput.postSamples.size(0)] =
          bayesResults_nestedSamplerOutput.postSamples.data[1];
        break;
      }

      //  Then just do a final calculation to fill in SLD if necessary
      //  (i.e. if calcSLD is no for fit)
      if (!controls->calcSldDuringFit) {
        controls->calcSldDuringFit = true;
        controls->procedure.size[0] = 1;
        controls->procedure.size[1] = 9;
        for (i = 0; i < 9; i++) {
          controls->procedure.data[i] = cv1[i];
        }

        reflectivityCalculation(problemStruct, problemLimits->param,
          problemLimits->backgroundParam, problemLimits->scalefactor,
          problemLimits->qzshift, problemLimits->bulkIn, problemLimits->bulkOut,
          problemLimits->resolutionParam, problemLimits->domainRatio, controls,
          &b_expl_temp);
        expl_temp.reflectivity.set_size(b_expl_temp.reflectivity.size(0));
        b_index = b_expl_temp.reflectivity.size(0);
        for (i = 0; i < b_index; i++) {
          expl_temp.reflectivity[i] = b_expl_temp.reflectivity[i];
        }

        expl_temp.simulation.set_size(b_expl_temp.simulation.size(0));
        b_index = b_expl_temp.simulation.size(0);
        for (i = 0; i < b_index; i++) {
          expl_temp.simulation[i] = b_expl_temp.simulation[i];
        }

        expl_temp.shiftedData.set_size(b_expl_temp.shiftedData.size(0));
        b_index = b_expl_temp.shiftedData.size(0);
        for (i = 0; i < b_index; i++) {
          expl_temp.shiftedData[i] = b_expl_temp.shiftedData[i];
        }

        expl_temp.backgrounds.set_size(b_expl_temp.backgrounds.size(0));
        b_index = b_expl_temp.backgrounds.size(0);
        for (i = 0; i < b_index; i++) {
          expl_temp.backgrounds[i] = b_expl_temp.backgrounds[i];
        }

        expl_temp.layerSlds.set_size(b_expl_temp.layerSlds.size(0),
          b_expl_temp.layerSlds.size(1));
        b_index = b_expl_temp.layerSlds.size(1);
        for (i = 0; i < b_index; i++) {
          loop_ub = b_expl_temp.layerSlds.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            expl_temp.layerSlds[i1 + expl_temp.layerSlds.size(0) * i] =
              b_expl_temp.layerSlds[i1 + b_expl_temp.layerSlds.size(0) * i];
          }
        }

        expl_temp.sldProfiles.set_size(b_expl_temp.sldProfiles.size(0),
          b_expl_temp.sldProfiles.size(1));
        b_index = b_expl_temp.sldProfiles.size(1);
        for (i = 0; i < b_index; i++) {
          loop_ub = b_expl_temp.sldProfiles.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            expl_temp.sldProfiles[i1 + expl_temp.sldProfiles.size(0) * i] =
              b_expl_temp.sldProfiles[i1 + b_expl_temp.sldProfiles.size(0) * i];
          }
        }

        expl_temp.resampledLayers.set_size(b_expl_temp.resampledLayers.size(0),
          b_expl_temp.resampledLayers.size(1));
        b_index = b_expl_temp.resampledLayers.size(1);
        for (i = 0; i < b_index; i++) {
          loop_ub = b_expl_temp.resampledLayers.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            expl_temp.resampledLayers[i1 + expl_temp.resampledLayers.size(0) * i]
              = b_expl_temp.resampledLayers[i1 +
              b_expl_temp.resampledLayers.size(0) * i];
          }
        }

        expl_temp.fitParams.set_size(b_expl_temp.fitParams.size(0));
        b_index = b_expl_temp.fitParams.size(0);
        for (i = 0; i < b_index; i++) {
          expl_temp.fitParams[i] = b_expl_temp.fitParams[i];
        }

        expl_temp.fitNames.set_size(b_expl_temp.fitNames.size(0));
        b_index = b_expl_temp.fitNames.size(0);
        for (i = 0; i < b_index; i++) {
          expl_temp.fitNames[i] = b_expl_temp.fitNames[i];
        }

        result->reflectivity.set_size(expl_temp.reflectivity.size(0));
        b_index = expl_temp.reflectivity.size(0);
        for (i = 0; i < b_index; i++) {
          result->reflectivity[i] = expl_temp.reflectivity[i];
        }

        result->simulation.set_size(expl_temp.simulation.size(0));
        b_index = expl_temp.simulation.size(0);
        for (i = 0; i < b_index; i++) {
          result->simulation[i] = expl_temp.simulation[i];
        }

        result->shiftedData.set_size(expl_temp.shiftedData.size(0));
        b_index = expl_temp.shiftedData.size(0);
        for (i = 0; i < b_index; i++) {
          result->shiftedData[i] = expl_temp.shiftedData[i];
        }

        result->backgrounds.set_size(expl_temp.backgrounds.size(0));
        b_index = expl_temp.backgrounds.size(0);
        for (i = 0; i < b_index; i++) {
          result->backgrounds[i] = expl_temp.backgrounds[i];
        }

        result->layerSlds.set_size(expl_temp.layerSlds.size(0),
          expl_temp.layerSlds.size(1));
        b_index = expl_temp.layerSlds.size(1);
        for (i = 0; i < b_index; i++) {
          loop_ub = expl_temp.layerSlds.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            result->layerSlds[i1 + result->layerSlds.size(0) * i] =
              expl_temp.layerSlds[i1 + expl_temp.layerSlds.size(0) * i];
          }
        }

        result->sldProfiles.set_size(expl_temp.sldProfiles.size(0),
          expl_temp.sldProfiles.size(1));
        b_index = expl_temp.sldProfiles.size(1);
        for (i = 0; i < b_index; i++) {
          loop_ub = expl_temp.sldProfiles.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            result->sldProfiles[i1 + result->sldProfiles.size(0) * i] =
              expl_temp.sldProfiles[i1 + expl_temp.sldProfiles.size(0) * i];
          }
        }

        result->resampledLayers.set_size(expl_temp.resampledLayers.size(0),
          expl_temp.resampledLayers.size(1));
        b_index = expl_temp.resampledLayers.size(1);
        for (i = 0; i < b_index; i++) {
          loop_ub = expl_temp.resampledLayers.size(0);
          for (i1 = 0; i1 < loop_ub; i1++) {
            result->resampledLayers[i1 + result->resampledLayers.size(0) * i] =
              expl_temp.resampledLayers[i1 + expl_temp.resampledLayers.size(0) *
              i];
          }
        }

        result->calculationResults = b_expl_temp.calculationResults;
        result->contrastParams = b_expl_temp.contrastParams;
        b_index = expl_temp.fitParams.size(0);
        result->fitParams.set_size(expl_temp.fitParams.size(0), 1);
        for (i = 0; i < 1; i++) {
          for (i1 = 0; i1 < b_index; i1++) {
            result->fitParams[i1] = expl_temp.fitParams[i1];
          }
        }

        result->fitNames.set_size(expl_temp.fitNames.size(0));
        b_index = expl_temp.fitNames.size(0);
        for (i = 0; i < b_index; i++) {
          result->fitNames[i] = expl_temp.fitNames[i];
        }
      }
    }
  }
}

// End of code generation (RATMain.cpp)
