//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// reflectivityCalculation2.cpp
//
// Code generation for function 'reflectivityCalculation2'
//

// Include files
#include "reflectivityCalculation2.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "blockedSummation.h"
#include "customLayers1.h"
#include "customXY1.h"
#include "lower.h"
#include "rt_nonfinite.h"
#include "standardLayers1.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Definitions
namespace RAT
{
  namespace domainsTF
  {
    void b_reflectivityCalculation(const f_struct_T *problemStruct, const
      cell_11 *problemCells, const struct2_T *controls, c_struct_T
      *contrastParams, struct6_T *calculationResults, ::coder::array<cell_wrap_8,
      1U> &reflectivity, ::coder::array<cell_wrap_8, 1U> &simulation, ::coder::
      array<cell_wrap_10, 1U> &shiftedData, ::coder::array<cell_wrap_10, 2U>
      &layerSlds, ::coder::array<cell_wrap_10, 2U> &sldProfiles, ::coder::array<
      cell_wrap_10, 2U> &resampledLayers)
    {
      real_T y;
      int32_T switch_expression_size[2];
      int32_T i;
      int32_T loop_ub_tmp;
      char_T switch_expression_data[10000];

      //  Main function for the domainsTF reflectivity calculation.
      //  This function decides what type of model is being analysed and branches
      //  to the correct one. The main options are:
      //
      //  Standard Layers   - This is the equivalent of Standard Layers in RasCAL.
      //  Custom Layers     - This is also a layers calculation, but the
      //                      specification of the layers is done using a user
      //                      defined function.
      //  Custom XY         - This also has a model described by a user supplied
      //                      function, but in this case the function generates an
      //                      SLD profile (i.e. XY function) rather than a list of
      //                      layers.
      //
      //  We then decide on parallelisation options before calling the relevant
      //  version of the main custom layers calculation. It is more efficient to
      //  have multiple versions of the core calculation, each dealing with a
      //  different scheme for parallelisation. These are:
      //
      //  single            - single threaded reflectivity calculation.
      //  points            - parallelise over points.
      //  contrasts         - parallelise over contrasts.
      //
      //  Find out the model type from the input structs
      //  Pre-allocation - It's necessary to pre-define the types for all the
      //  arrays for compilation, so do this in this block.
      loop_ub_tmp = static_cast<int32_T>(problemStruct->numberOfContrasts);
      contrastParams->backgroundParams.set_size(loop_ub_tmp);
      contrastParams->qzshifts.set_size(loop_ub_tmp);
      contrastParams->scalefactors.set_size(loop_ub_tmp);
      contrastParams->bulkIn.set_size(loop_ub_tmp);
      contrastParams->bulkOut.set_size(loop_ub_tmp);
      for (i = 0; i < loop_ub_tmp; i++) {
        contrastParams->backgroundParams[i] = 0.0;
        contrastParams->qzshifts[i] = 0.0;
        contrastParams->scalefactors[i] = 0.0;
        contrastParams->bulkIn[i] = 0.0;
        contrastParams->bulkOut[i] = 0.0;
      }

      calculationResults->chiValues.set_size(loop_ub_tmp);
      for (i = 0; i < loop_ub_tmp; i++) {
        calculationResults->chiValues[i] = 0.0;
      }

      contrastParams->resolutionParams.set_size(loop_ub_tmp);
      contrastParams->subRoughs.set_size(loop_ub_tmp);

      //  Pre-allocate the output arrays.. this is necessary because otherwise the
      //  compiler complains with 'Output argument <....> is not assigned on some
      //  execution paths' error.
      reflectivity.set_size(loop_ub_tmp);
      simulation.set_size(loop_ub_tmp);
      shiftedData.set_size(loop_ub_tmp);
      layerSlds.set_size(loop_ub_tmp, 2);
      sldProfiles.set_size(loop_ub_tmp, 2);
      resampledLayers.set_size(loop_ub_tmp, 2);
      for (int32_T b_i{0}; b_i < loop_ub_tmp; b_i++) {
        contrastParams->resolutionParams[b_i] = 0.0;
        contrastParams->subRoughs[b_i] = 0.0;
        reflectivity[b_i].f1.set_size(2, 2);
        reflectivity[b_i].f1[0] = 1.0;
        reflectivity[b_i].f1[1] = 1.0;
        reflectivity[b_i].f1[reflectivity[b_i].f1.size(0)] = 1.0;
        reflectivity[b_i].f1[reflectivity[b_i].f1.size(0) + 1] = 1.0;
        simulation[b_i].f1.set_size(2, 2);
        simulation[b_i].f1[0] = 1.0;
        simulation[b_i].f1[1] = 1.0;
        simulation[b_i].f1[simulation[b_i].f1.size(0)] = 1.0;
        simulation[b_i].f1[simulation[b_i].f1.size(0) + 1] = 1.0;
        shiftedData[b_i].f1.set_size(2, 3);
        layerSlds[b_i].f1.set_size(2, 3);
        layerSlds[b_i + layerSlds.size(0)].f1.set_size(2, 3);
        sldProfiles[b_i].f1.set_size(2, 2);
        sldProfiles[b_i + sldProfiles.size(0)].f1.set_size(2, 2);
        sldProfiles[b_i].f1[0] = 1.0;
        sldProfiles[b_i + sldProfiles.size(0)].f1[0] = 1.0;
        sldProfiles[b_i].f1[1] = 1.0;
        sldProfiles[b_i + sldProfiles.size(0)].f1[1] = 1.0;
        sldProfiles[b_i].f1[sldProfiles[b_i].f1.size(0)] = 1.0;
        sldProfiles[b_i + sldProfiles.size(0)].f1[sldProfiles[b_i +
          sldProfiles.size(0)].f1.size(0)] = 1.0;
        sldProfiles[b_i].f1[sldProfiles[b_i].f1.size(0) + 1] = 1.0;
        sldProfiles[b_i + sldProfiles.size(0)].f1[sldProfiles[b_i +
          sldProfiles.size(0)].f1.size(0) + 1] = 1.0;
        resampledLayers[b_i].f1.set_size(2, 3);
        resampledLayers[b_i + resampledLayers.size(0)].f1.set_size(2, 3);
        for (i = 0; i < 3; i++) {
          shiftedData[b_i].f1[shiftedData[b_i].f1.size(0) * i] = 1.0;
          shiftedData[b_i].f1[shiftedData[b_i].f1.size(0) * i + 1] = 1.0;
          layerSlds[b_i].f1[layerSlds[b_i].f1.size(0) * i] = 1.0;
          layerSlds[b_i + layerSlds.size(0)].f1[layerSlds[b_i + layerSlds.size(0)]
            .f1.size(0) * i] = 1.0;
          layerSlds[b_i].f1[layerSlds[b_i].f1.size(0) * i + 1] = 1.0;
          layerSlds[b_i + layerSlds.size(0)].f1[layerSlds[b_i + layerSlds.size(0)]
            .f1.size(0) * i + 1] = 1.0;
          resampledLayers[b_i].f1[resampledLayers[b_i].f1.size(0) * i] = 1.0;
          resampledLayers[b_i + resampledLayers.size(0)].f1[resampledLayers[b_i
            + resampledLayers.size(0)].f1.size(0) * i] = 1.0;
          resampledLayers[b_i].f1[resampledLayers[b_i].f1.size(0) * i + 1] = 1.0;
          resampledLayers[b_i + resampledLayers.size(0)].f1[resampledLayers[b_i
            + resampledLayers.size(0)].f1.size(0) * i + 1] = 1.0;
        }
      }

      coder::lower(problemStruct->modelType.data, problemStruct->modelType.size,
                   switch_expression_data, switch_expression_size);
      if (coder::internal::j_strcmp(switch_expression_data,
           switch_expression_size)) {
        loop_ub_tmp = 0;
      } else if (coder::internal::k_strcmp(switch_expression_data,
                  switch_expression_size)) {
        loop_ub_tmp = 1;
      } else if (coder::internal::l_strcmp(switch_expression_data,
                  switch_expression_size)) {
        loop_ub_tmp = 2;
      } else {
        loop_ub_tmp = -1;
      }

      switch (loop_ub_tmp) {
       case 0:
        standardLayers(problemStruct, problemCells, controls,
                       contrastParams->backgroundParams,
                       contrastParams->qzshifts, contrastParams->scalefactors,
                       contrastParams->bulkIn, contrastParams->bulkOut,
                       contrastParams->resolutionParams,
                       calculationResults->chiValues, reflectivity, simulation,
                       shiftedData, layerSlds, sldProfiles, resampledLayers,
                       contrastParams->subRoughs);
        break;

       case 1:
        b_customLayers(problemStruct, problemCells, controls,
                       contrastParams->backgroundParams,
                       contrastParams->qzshifts, contrastParams->scalefactors,
                       contrastParams->bulkIn, contrastParams->bulkOut,
                       contrastParams->resolutionParams,
                       calculationResults->chiValues, reflectivity, simulation,
                       shiftedData, layerSlds, sldProfiles, resampledLayers,
                       contrastParams->subRoughs);
        break;

       case 2:
        b_customXY(problemStruct, problemCells, controls,
                   contrastParams->backgroundParams, contrastParams->qzshifts,
                   contrastParams->scalefactors, contrastParams->bulkIn,
                   contrastParams->bulkOut, contrastParams->resolutionParams,
                   calculationResults->chiValues, reflectivity, simulation,
                   shiftedData, layerSlds, sldProfiles, resampledLayers,
                   contrastParams->subRoughs);
        break;
      }

      //  Package everything into one array for tidy output
      contrastParams->resample.set_size(1, problemStruct->resample.size(1));
      loop_ub_tmp = problemStruct->resample.size(1);
      for (i = 0; i < loop_ub_tmp; i++) {
        contrastParams->resample[i] = problemStruct->resample[i];
      }

      if (calculationResults->chiValues.size(0) == 0) {
        y = 0.0;
      } else {
        y = coder::nestedIter(calculationResults->chiValues,
                              calculationResults->chiValues.size(0));
      }

      calculationResults->sumChi = y;
    }
  }
}

// End of code generation (reflectivityCalculation2.cpp)
