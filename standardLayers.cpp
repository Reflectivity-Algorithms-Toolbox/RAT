//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// standardLayers.cpp
//
// Code generation for function 'standardLayers'
//

// Include files
#include "standardLayers.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "allocateLayersForContrast.h"
#include "allocateParamsToLayers.h"
#include "backSort.h"
#include "constructBackground.h"
#include "coreLayersCalculation.h"
#include "extractProblemParams.h"
#include "rt_nonfinite.h"
#include "shiftData.h"
#include "strcmp.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Function Declarations
namespace RAT
{
  namespace nonPolarisedTF
  {
    static void contrastCalculation(const real_T backgroundParamIndex_data[],
      const int32_T backgroundParamIndex_size[2], real_T qzshiftIndex, real_T
      scalefactorIndex, real_T bulkInIndex, real_T bulkOutIndex, real_T
      resolutionParamIndex, const ::coder::array<real_T, 2U> &backgroundParams,
      const ::coder::array<real_T, 2U> &qzshifts, const ::coder::array<real_T,
      2U> &scalefactors, const ::coder::array<real_T, 2U> &bulkIns, const ::
      coder::array<real_T, 2U> &bulkOuts, const ::coder::array<real_T, 2U>
      &resolutionParams, real_T dataPresent, const ::coder::array<real_T, 2U>
      &data, const real_T dataLimits[2], const real_T simLimits[2], const real_T
      repeatLayers[2], const char_T backgroundType_data[], const int32_T
      backgroundType_size[2], const char_T backgroundAction_data[], const
      int32_T backgroundAction_size[2], const ::coder::array<cell_wrap_7, 2U>
      &customFiles, real_T nParams, const char_T parallel_data[], const int32_T
      parallel_size[2], real_T resampleMinAngle, real_T resampleNPoints,
      boolean_T useImaginary, real_T resample, const char_T geometry_data[],
      const int32_T geometry_size[2], real_T roughness, boolean_T calcSld, const
      ::coder::array<real_T, 2U> &contrastLayers, const ::coder::array<
      cell_wrap_13, 2U> &outParameterisedLayers, real_T *qzshiftValue, real_T
      *scalefactorValue, real_T *bulkInValue, real_T *bulkOutValue, real_T
      *resolutionParamValue, real_T *chi, ::coder::array<real_T, 2U>
      &reflectivity, ::coder::array<real_T, 2U> &simulation, ::coder::array<
      real_T, 2U> &shiftedData, ::coder::array<real_T, 2U> &background, ::coder::
      array<real_T, 2U> &layerSld, ::coder::array<real_T, 2U> &sldProfile, ::
      coder::array<real_T, 2U> &resampledLayer);
  }
}

// Function Definitions
namespace RAT
{
  namespace nonPolarisedTF
  {
    static void contrastCalculation(const real_T backgroundParamIndex_data[],
      const int32_T backgroundParamIndex_size[2], real_T qzshiftIndex, real_T
      scalefactorIndex, real_T bulkInIndex, real_T bulkOutIndex, real_T
      resolutionParamIndex, const ::coder::array<real_T, 2U> &backgroundParams,
      const ::coder::array<real_T, 2U> &qzshifts, const ::coder::array<real_T,
      2U> &scalefactors, const ::coder::array<real_T, 2U> &bulkIns, const ::
      coder::array<real_T, 2U> &bulkOuts, const ::coder::array<real_T, 2U>
      &resolutionParams, real_T dataPresent, const ::coder::array<real_T, 2U>
      &data, const real_T dataLimits[2], const real_T simLimits[2], const real_T
      repeatLayers[2], const char_T backgroundType_data[], const int32_T
      backgroundType_size[2], const char_T backgroundAction_data[], const
      int32_T backgroundAction_size[2], const ::coder::array<cell_wrap_7, 2U>
      &customFiles, real_T nParams, const char_T parallel_data[], const int32_T
      parallel_size[2], real_T resampleMinAngle, real_T resampleNPoints,
      boolean_T useImaginary, real_T resample, const char_T geometry_data[],
      const int32_T geometry_size[2], real_T roughness, boolean_T calcSld, const
      ::coder::array<real_T, 2U> &contrastLayers, const ::coder::array<
      cell_wrap_13, 2U> &outParameterisedLayers, real_T *qzshiftValue, real_T
      *scalefactorValue, real_T *bulkInValue, real_T *bulkOutValue, real_T
      *resolutionParamValue, real_T *chi, ::coder::array<real_T, 2U>
      &reflectivity, ::coder::array<real_T, 2U> &simulation, ::coder::array<
      real_T, 2U> &shiftedData, ::coder::array<real_T, 2U> &background, ::coder::
      array<real_T, 2U> &layerSld, ::coder::array<real_T, 2U> &sldProfile, ::
      coder::array<real_T, 2U> &resampledLayer)
    {
      ::coder::array<real_T, 2U> b_data;
      ::coder::array<real_T, 2U> b_layerSld;
      ::coder::array<real_T, 2U> b_shiftedData;
      ::coder::array<real_T, 2U> r;
      int32_T i;
      int32_T i1;
      int32_T loop_ub;

      //  Extract the relevant parameter values for this contrast
      //  from the input arrays.
      //  First need to decide which values of the backgrounds, scalefactors
      //  data shifts and bulk contrasts are associated with this contrast
      backSort(qzshiftIndex, scalefactorIndex, bulkInIndex, bulkOutIndex,
               resolutionParamIndex, qzshifts, scalefactors, bulkIns, bulkOuts,
               resolutionParams, qzshiftValue, scalefactorValue, bulkInValue,
               bulkOutValue, resolutionParamValue);

      //  Also need to determine which layers from the overall layers list
      //  are required for this contrast, and put them in the correct order
      //  according to geometry
      //  Apply scale factors and q shifts to the data
      b_data.set_size(data.size(0), 6);
      loop_ub = data.size(0) - 1;
      for (i = 0; i < 6; i++) {
        for (i1 = 0; i1 <= loop_ub; i1++) {
          b_data[i1 + b_data.size(0) * i] = data[i1 + data.size(0) * i];
        }
      }

      shiftData(*scalefactorValue, *qzshiftValue, dataPresent, b_data,
                dataLimits, simLimits, b_shiftedData);
      constructBackground(backgroundType_data, backgroundType_size,
                          backgroundParamIndex_data, backgroundParamIndex_size,
                          b_shiftedData, customFiles, backgroundParams,
                          simLimits, background);

      //  Call the core layers calculation
      allocateLayersForContrast(contrastLayers, outParameterisedLayers,
        useImaginary, r);
      coreLayersCalculation(r, roughness, geometry_data, geometry_size,
                            *bulkInValue, *bulkOutValue, resample, calcSld,
                            b_shiftedData, simLimits, repeatLayers,
                            *resolutionParamValue, background,
                            backgroundAction_data, backgroundAction_size,
                            nParams, parallel_data, parallel_size,
                            resampleMinAngle, resampleNPoints, useImaginary,
                            sldProfile, reflectivity, simulation, shiftedData,
                            b_layerSld, resampledLayer, chi);
      layerSld.set_size(b_layerSld.size(0), b_layerSld.size(1));
      loop_ub = b_layerSld.size(1);
      for (i = 0; i < loop_ub; i++) {
        int32_T b_loop_ub;
        b_loop_ub = b_layerSld.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          layerSld[i1 + layerSld.size(0) * i] = b_layerSld[i1 + b_layerSld.size
            (0) * i];
        }
      }
    }

    void standardLayers(const e_struct_T *problemStruct, const struct3_T
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
                        &resampledLayers, ::coder::array<real_T, 1U> &subRoughs)
    {
      ::coder::array<cell_wrap_13, 2U> outParameterisedLayers;
      ::coder::array<real_T, 2U> r;
      ::coder::array<real_T, 2U> r1;
      ::coder::array<real_T, 2U> r2;
      ::coder::array<real_T, 2U> r3;
      ::coder::array<real_T, 2U> r4;
      ::coder::array<real_T, 2U> r5;
      ::coder::array<real_T, 2U> r6;
      ::coder::array<real_T, 2U> r7;
      real_T d;
      real_T d1;
      real_T d2;
      real_T d3;
      real_T d4;
      real_T d5;
      real_T resampleMinAngle;
      real_T resampleNPoints;
      int32_T iv[2];
      int32_T iv1[2];
      int32_T iv2[2];
      int32_T iv3[2];
      int32_T b_i;
      int32_T c_i;
      int32_T c_loop_ub;
      int32_T d_loop_ub;
      int32_T i;
      int32_T i3;
      int32_T i4;
      int32_T nParams;
      boolean_T calcSld;
      boolean_T useImaginary;

      //  This is the main reflectivity calculation of the standard layers
      //  calculation type. It extracts the required parameters for the contrasts
      //  from the input arrays, then passes the main calculation to
      //  'coreLayersCalculation', which carries out the calculation itself.
      //  The core calculation is common for both standard and custom layers.
      //  Extract parameters from problemStruct
      nParams = problemStruct->params.size(1);
      useImaginary = problemStruct->useImaginary;
      calcSld = controls->calcSldDuringFit;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Allocate the memory for the output arrays before the main loop
      //  First we need to allocate the absolute values of the input
      //  parameters to all the layers in the layers list. This only needs
      //  to be done once, and so is done outside the contrasts loop
      allocateParamsToLayers(problemStruct->params, problemStruct->layersDetails,
        outParameterisedLayers);

      //  Substrate roughness is always first parameter for standard layers
      i = static_cast<int32_T>(problemStruct->numberOfContrasts);
      subRoughs.set_size(i);
      for (b_i = 0; b_i < i; b_i++) {
        subRoughs[b_i] = problemStruct->params[0];
      }

      if (coder::internal::m_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        int32_T loop_ub;

        //  Loop over all the contrasts
        resampledLayers.set_size(i, 1);
        sldProfiles.set_size(i, 1);
        layerSlds.set_size(i, 1);
        backgrounds.set_size(i);
        shiftedData.set_size(i);
        simulation.set_size(i);
        reflectivity.set_size(i);
        qzshifts.set_size(i);
        scalefactors.set_size(i);
        bulkIns.set_size(i);
        bulkOuts.set_size(i);
        resolutionParams.set_size(i);
        chis.set_size(i);
        loop_ub = i - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r,r1,r2,r7,d,d1,d2,d3,d4,d5,iv2,c_i,iv3,c_loop_ub,i3,i4,d_loop_ub)

        for (c_i = 0; c_i <= loop_ub; c_i++) {
          iv2[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundTypes[c_i].f1)->size())[0];
          iv2[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundTypes[c_i].f1)->size())[1];
          iv3[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[c_i].f1)->size())
            [0];
          iv3[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[c_i].f1)->size())
            [1];
          contrastCalculation(problemStruct->contrastBackgroundParams[c_i].
                              f1.data, problemStruct->
                              contrastBackgroundParams[c_i].f1.size,
                              problemStruct->contrastQzshifts[c_i],
                              problemStruct->contrastScalefactors[c_i],
                              problemStruct->contrastBulkIns[c_i],
                              problemStruct->contrastBulkOuts[c_i],
                              problemStruct->contrastResolutionParams[c_i],
                              problemStruct->backgroundParams,
                              problemStruct->qzshifts,
                              problemStruct->scalefactors, problemStruct->bulkIn,
                              problemStruct->bulkOut,
                              problemStruct->resolutionParams,
                              problemStruct->dataPresent[c_i],
                              problemStruct->data[c_i].f1,
                              problemStruct->dataLimits[c_i].f1,
                              problemStruct->simulationLimits[c_i].f1,
                              problemStruct->repeatLayers[c_i].f1, (const char_T
            *)((::coder::array<char_T, 2U> *)
               &problemStruct->contrastBackgroundTypes[c_i].f1)->data(), iv2, (
            const char_T *)((::coder::array<char_T, 2U> *)
                            &problemStruct->contrastBackgroundActions[c_i].f1)
                              ->data(), iv3, problemStruct->customFiles,
                              static_cast<real_T>(nParams),
                              controls->parallel.data, controls->parallel.size,
                              resampleMinAngle, resampleNPoints, useImaginary,
                              problemStruct->resample[c_i],
                              problemStruct->geometry.data,
                              problemStruct->geometry.size, subRoughs[c_i],
                              calcSld, problemStruct->contrastLayers[c_i].f1,
                              outParameterisedLayers, &d5, &d4, &d3, &d2, &d1,
                              &d, reflectivity[c_i].f1, simulation[c_i].f1, r7,
                              backgrounds[c_i].f1, r2, r1, r);
          c_loop_ub = r7.size(0);
          shiftedData[c_i].f1.set_size(r7.size(0), 3);
          for (i3 = 0; i3 < 3; i3++) {
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              shiftedData[c_i].f1[i4 + shiftedData[c_i].f1.size(0) * i3] = r7[i4
                + r7.size(0) * i3];
            }
          }

          c_loop_ub = r2.size(1);
          layerSlds[c_i].f1.set_size(r2.size(0), r2.size(1));
          for (i3 = 0; i3 < c_loop_ub; i3++) {
            d_loop_ub = r2.size(0);
            for (i4 = 0; i4 < d_loop_ub; i4++) {
              layerSlds[c_i].f1[i4 + layerSlds[c_i].f1.size(0) * i3] = r2[i4 +
                r2.size(0) * i3];
            }
          }

          c_loop_ub = r1.size(0);
          sldProfiles[c_i].f1.set_size(r1.size(0), 2);
          for (i3 = 0; i3 < 2; i3++) {
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              sldProfiles[c_i].f1[i4 + sldProfiles[c_i].f1.size(0) * i3] = r1[i4
                + r1.size(0) * i3];
            }
          }

          c_loop_ub = r.size(1);
          resampledLayers[c_i].f1.set_size(r.size(0), r.size(1));
          for (i3 = 0; i3 < c_loop_ub; i3++) {
            d_loop_ub = r.size(0);
            for (i4 = 0; i4 < d_loop_ub; i4++) {
              resampledLayers[c_i].f1[i4 + resampledLayers[c_i].f1.size(0) * i3]
                = r[i4 + r.size(0) * i3];
            }
          }

          qzshifts[c_i] = d5;
          scalefactors[c_i] = d4;
          bulkIns[c_i] = d3;
          bulkOuts[c_i] = d2;
          resolutionParams[c_i] = d1;
          chis[c_i] = d;
        }
      } else {
        //  Loop over all the contrasts
        resampledLayers.set_size(i, 1);
        sldProfiles.set_size(i, 1);
        layerSlds.set_size(i, 1);
        backgrounds.set_size(i);
        shiftedData.set_size(i);
        simulation.set_size(i);
        reflectivity.set_size(i);
        qzshifts.set_size(i);
        scalefactors.set_size(i);
        bulkIns.set_size(i);
        bulkOuts.set_size(i);
        resolutionParams.set_size(i);
        chis.set_size(i);
        for (b_i = 0; b_i < i; b_i++) {
          int32_T b_loop_ub;
          int32_T i1;
          int32_T i2;
          int32_T loop_ub;
          iv[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                    &problemStruct->contrastBackgroundTypes[b_i].f1)->size())[0];
          iv[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                    &problemStruct->contrastBackgroundTypes[b_i].f1)->size())[1];
          iv1[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[b_i].f1)->size())
            [0];
          iv1[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[b_i].f1)->size())
            [1];
          contrastCalculation(problemStruct->contrastBackgroundParams[b_i].
                              f1.data, problemStruct->
                              contrastBackgroundParams[b_i].f1.size,
                              problemStruct->contrastQzshifts[b_i],
                              problemStruct->contrastScalefactors[b_i],
                              problemStruct->contrastBulkIns[b_i],
                              problemStruct->contrastBulkOuts[b_i],
                              problemStruct->contrastResolutionParams[b_i],
                              problemStruct->backgroundParams,
                              problemStruct->qzshifts,
                              problemStruct->scalefactors, problemStruct->bulkIn,
                              problemStruct->bulkOut,
                              problemStruct->resolutionParams,
                              problemStruct->dataPresent[b_i],
                              problemStruct->data[b_i].f1,
                              problemStruct->dataLimits[b_i].f1,
                              problemStruct->simulationLimits[b_i].f1,
                              problemStruct->repeatLayers[b_i].f1, (const char_T
            *)((::coder::array<char_T, 2U> *)
               &problemStruct->contrastBackgroundTypes[b_i].f1)->data(), iv, (
            const char_T *)((::coder::array<char_T, 2U> *)
                            &problemStruct->contrastBackgroundActions[b_i].f1)
                              ->data(), iv1, problemStruct->customFiles,
                              static_cast<real_T>(problemStruct->params.size(1)),
                              controls->parallel.data, controls->parallel.size,
                              resampleMinAngle, resampleNPoints,
                              problemStruct->useImaginary,
                              problemStruct->resample[b_i],
                              problemStruct->geometry.data,
                              problemStruct->geometry.size, subRoughs[b_i],
                              calcSld, problemStruct->contrastLayers[b_i].f1,
                              outParameterisedLayers, &qzshifts[b_i],
                              &scalefactors[b_i], &bulkIns[b_i], &bulkOuts[b_i],
                              &resolutionParams[b_i], &chis[b_i],
                              reflectivity[b_i].f1, simulation[b_i].f1, r3,
                              backgrounds[b_i].f1, r4, r5, r6);
          loop_ub = r3.size(0);
          shiftedData[b_i].f1.set_size(r3.size(0), 3);
          for (i1 = 0; i1 < 3; i1++) {
            for (i2 = 0; i2 < loop_ub; i2++) {
              shiftedData[b_i].f1[i2 + shiftedData[b_i].f1.size(0) * i1] = r3[i2
                + r3.size(0) * i1];
            }
          }

          loop_ub = r4.size(1);
          layerSlds[b_i].f1.set_size(r4.size(0), r4.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = r4.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              layerSlds[b_i].f1[i2 + layerSlds[b_i].f1.size(0) * i1] = r4[i2 +
                r4.size(0) * i1];
            }
          }

          loop_ub = r5.size(0);
          sldProfiles[b_i].f1.set_size(r5.size(0), 2);
          for (i1 = 0; i1 < 2; i1++) {
            for (i2 = 0; i2 < loop_ub; i2++) {
              sldProfiles[b_i].f1[i2 + sldProfiles[b_i].f1.size(0) * i1] = r5[i2
                + r5.size(0) * i1];
            }
          }

          loop_ub = r6.size(1);
          resampledLayers[b_i].f1.set_size(r6.size(0), r6.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = r6.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              resampledLayers[b_i].f1[i2 + resampledLayers[b_i].f1.size(0) * i1]
                = r6[i2 + r6.size(0) * i1];
            }
          }
        }
      }
    }

    void standardLayers(const g_struct_T *problemStruct, const struct3_T
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
                        &resampledLayers, ::coder::array<real_T, 1U> &subRoughs)
    {
      ::coder::array<cell_wrap_13, 2U> outParameterisedLayers;
      ::coder::array<real_T, 2U> r;
      ::coder::array<real_T, 2U> r1;
      ::coder::array<real_T, 2U> r2;
      ::coder::array<real_T, 2U> r3;
      ::coder::array<real_T, 2U> r4;
      ::coder::array<real_T, 2U> r5;
      ::coder::array<real_T, 2U> r6;
      ::coder::array<real_T, 2U> r7;
      real_T d;
      real_T d1;
      real_T d2;
      real_T d3;
      real_T d4;
      real_T d5;
      real_T resampleMinAngle;
      real_T resampleNPoints;
      int32_T iv[2];
      int32_T iv1[2];
      int32_T iv2[2];
      int32_T iv3[2];
      int32_T b_i;
      int32_T c_i;
      int32_T c_loop_ub;
      int32_T d_loop_ub;
      int32_T i;
      int32_T i3;
      int32_T i4;
      int32_T nParams;
      boolean_T calcSld;
      boolean_T useImaginary;

      //  This is the main reflectivity calculation of the standard layers
      //  calculation type. It extracts the required parameters for the contrasts
      //  from the input arrays, then passes the main calculation to
      //  'coreLayersCalculation', which carries out the calculation itself.
      //  The core calculation is common for both standard and custom layers.
      //  Extract parameters from problemStruct
      nParams = problemStruct->params.size(1);
      useImaginary = problemStruct->useImaginary;
      calcSld = controls->calcSldDuringFit;
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Allocate the memory for the output arrays before the main loop
      //  First we need to allocate the absolute values of the input
      //  parameters to all the layers in the layers list. This only needs
      //  to be done once, and so is done outside the contrasts loop
      allocateParamsToLayers(problemStruct->params, problemStruct->layersDetails,
        outParameterisedLayers);

      //  Substrate roughness is always first parameter for standard layers
      i = static_cast<int32_T>(problemStruct->numberOfContrasts);
      subRoughs.set_size(i);
      for (b_i = 0; b_i < i; b_i++) {
        subRoughs[b_i] = problemStruct->params[0];
      }

      if (coder::internal::m_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        int32_T loop_ub;

        //  Loop over all the contrasts
        resampledLayers.set_size(i, 1);
        sldProfiles.set_size(i, 1);
        layerSlds.set_size(i, 1);
        backgrounds.set_size(i);
        shiftedData.set_size(i);
        simulation.set_size(i);
        reflectivity.set_size(i);
        qzshifts.set_size(i);
        scalefactors.set_size(i);
        bulkIns.set_size(i);
        bulkOuts.set_size(i);
        resolutionParams.set_size(i);
        chis.set_size(i);
        loop_ub = i - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r,r1,r2,r7,d,d1,d2,d3,d4,d5,iv2,c_i,iv3,c_loop_ub,i3,i4,d_loop_ub)

        for (c_i = 0; c_i <= loop_ub; c_i++) {
          iv2[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundTypes[c_i].f1)->size())[0];
          iv2[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundTypes[c_i].f1)->size())[1];
          iv3[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[c_i].f1)->size())
            [0];
          iv3[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[c_i].f1)->size())
            [1];
          contrastCalculation(problemStruct->contrastBackgroundParams[c_i].
                              f1.data, problemStruct->
                              contrastBackgroundParams[c_i].f1.size,
                              problemStruct->contrastQzshifts[c_i],
                              problemStruct->contrastScalefactors[c_i],
                              problemStruct->contrastBulkIns[c_i],
                              problemStruct->contrastBulkOuts[c_i],
                              problemStruct->contrastResolutionParams[c_i],
                              problemStruct->backgroundParams,
                              problemStruct->qzshifts,
                              problemStruct->scalefactors, problemStruct->bulkIn,
                              problemStruct->bulkOut,
                              problemStruct->resolutionParams,
                              problemStruct->dataPresent[c_i],
                              problemStruct->data[c_i].f1,
                              problemStruct->dataLimits[c_i].f1,
                              problemStruct->simulationLimits[c_i].f1,
                              problemStruct->repeatLayers[c_i].f1, (const char_T
            *)((::coder::array<char_T, 2U> *)
               &problemStruct->contrastBackgroundTypes[c_i].f1)->data(), iv2, (
            const char_T *)((::coder::array<char_T, 2U> *)
                            &problemStruct->contrastBackgroundActions[c_i].f1)
                              ->data(), iv3, problemStruct->customFiles,
                              static_cast<real_T>(nParams),
                              controls->parallel.data, controls->parallel.size,
                              resampleMinAngle, resampleNPoints, useImaginary,
                              problemStruct->resample[c_i],
                              problemStruct->geometry.data,
                              problemStruct->geometry.size, subRoughs[c_i],
                              calcSld, problemStruct->contrastLayers[c_i].f1,
                              outParameterisedLayers, &d5, &d4, &d3, &d2, &d1,
                              &d, reflectivity[c_i].f1, simulation[c_i].f1, r7,
                              backgrounds[c_i].f1, r2, r1, r);
          c_loop_ub = r7.size(0);
          shiftedData[c_i].f1.set_size(r7.size(0), 3);
          for (i3 = 0; i3 < 3; i3++) {
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              shiftedData[c_i].f1[i4 + shiftedData[c_i].f1.size(0) * i3] = r7[i4
                + r7.size(0) * i3];
            }
          }

          c_loop_ub = r2.size(1);
          layerSlds[c_i].f1.set_size(r2.size(0), r2.size(1));
          for (i3 = 0; i3 < c_loop_ub; i3++) {
            d_loop_ub = r2.size(0);
            for (i4 = 0; i4 < d_loop_ub; i4++) {
              layerSlds[c_i].f1[i4 + layerSlds[c_i].f1.size(0) * i3] = r2[i4 +
                r2.size(0) * i3];
            }
          }

          c_loop_ub = r1.size(0);
          sldProfiles[c_i].f1.set_size(r1.size(0), 2);
          for (i3 = 0; i3 < 2; i3++) {
            for (i4 = 0; i4 < c_loop_ub; i4++) {
              sldProfiles[c_i].f1[i4 + sldProfiles[c_i].f1.size(0) * i3] = r1[i4
                + r1.size(0) * i3];
            }
          }

          c_loop_ub = r.size(1);
          resampledLayers[c_i].f1.set_size(r.size(0), r.size(1));
          for (i3 = 0; i3 < c_loop_ub; i3++) {
            d_loop_ub = r.size(0);
            for (i4 = 0; i4 < d_loop_ub; i4++) {
              resampledLayers[c_i].f1[i4 + resampledLayers[c_i].f1.size(0) * i3]
                = r[i4 + r.size(0) * i3];
            }
          }

          qzshifts[c_i] = d5;
          scalefactors[c_i] = d4;
          bulkIns[c_i] = d3;
          bulkOuts[c_i] = d2;
          resolutionParams[c_i] = d1;
          chis[c_i] = d;
        }
      } else {
        //  Loop over all the contrasts
        resampledLayers.set_size(i, 1);
        sldProfiles.set_size(i, 1);
        layerSlds.set_size(i, 1);
        backgrounds.set_size(i);
        shiftedData.set_size(i);
        simulation.set_size(i);
        reflectivity.set_size(i);
        qzshifts.set_size(i);
        scalefactors.set_size(i);
        bulkIns.set_size(i);
        bulkOuts.set_size(i);
        resolutionParams.set_size(i);
        chis.set_size(i);
        for (b_i = 0; b_i < i; b_i++) {
          int32_T b_loop_ub;
          int32_T i1;
          int32_T i2;
          int32_T loop_ub;
          iv[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                    &problemStruct->contrastBackgroundTypes[b_i].f1)->size())[0];
          iv[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                    &problemStruct->contrastBackgroundTypes[b_i].f1)->size())[1];
          iv1[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[b_i].f1)->size())
            [0];
          iv1[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                     &problemStruct->contrastBackgroundActions[b_i].f1)->size())
            [1];
          contrastCalculation(problemStruct->contrastBackgroundParams[b_i].
                              f1.data, problemStruct->
                              contrastBackgroundParams[b_i].f1.size,
                              problemStruct->contrastQzshifts[b_i],
                              problemStruct->contrastScalefactors[b_i],
                              problemStruct->contrastBulkIns[b_i],
                              problemStruct->contrastBulkOuts[b_i],
                              problemStruct->contrastResolutionParams[b_i],
                              problemStruct->backgroundParams,
                              problemStruct->qzshifts,
                              problemStruct->scalefactors, problemStruct->bulkIn,
                              problemStruct->bulkOut,
                              problemStruct->resolutionParams,
                              problemStruct->dataPresent[b_i],
                              problemStruct->data[b_i].f1,
                              problemStruct->dataLimits[b_i].f1,
                              problemStruct->simulationLimits[b_i].f1,
                              problemStruct->repeatLayers[b_i].f1, (const char_T
            *)((::coder::array<char_T, 2U> *)
               &problemStruct->contrastBackgroundTypes[b_i].f1)->data(), iv, (
            const char_T *)((::coder::array<char_T, 2U> *)
                            &problemStruct->contrastBackgroundActions[b_i].f1)
                              ->data(), iv1, problemStruct->customFiles,
                              static_cast<real_T>(problemStruct->params.size(1)),
                              controls->parallel.data, controls->parallel.size,
                              resampleMinAngle, resampleNPoints,
                              problemStruct->useImaginary,
                              problemStruct->resample[b_i],
                              problemStruct->geometry.data,
                              problemStruct->geometry.size, subRoughs[b_i],
                              calcSld, problemStruct->contrastLayers[b_i].f1,
                              outParameterisedLayers, &qzshifts[b_i],
                              &scalefactors[b_i], &bulkIns[b_i], &bulkOuts[b_i],
                              &resolutionParams[b_i], &chis[b_i],
                              reflectivity[b_i].f1, simulation[b_i].f1, r3,
                              backgrounds[b_i].f1, r4, r5, r6);
          loop_ub = r3.size(0);
          shiftedData[b_i].f1.set_size(r3.size(0), 3);
          for (i1 = 0; i1 < 3; i1++) {
            for (i2 = 0; i2 < loop_ub; i2++) {
              shiftedData[b_i].f1[i2 + shiftedData[b_i].f1.size(0) * i1] = r3[i2
                + r3.size(0) * i1];
            }
          }

          loop_ub = r4.size(1);
          layerSlds[b_i].f1.set_size(r4.size(0), r4.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = r4.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              layerSlds[b_i].f1[i2 + layerSlds[b_i].f1.size(0) * i1] = r4[i2 +
                r4.size(0) * i1];
            }
          }

          loop_ub = r5.size(0);
          sldProfiles[b_i].f1.set_size(r5.size(0), 2);
          for (i1 = 0; i1 < 2; i1++) {
            for (i2 = 0; i2 < loop_ub; i2++) {
              sldProfiles[b_i].f1[i2 + sldProfiles[b_i].f1.size(0) * i1] = r5[i2
                + r5.size(0) * i1];
            }
          }

          loop_ub = r6.size(1);
          resampledLayers[b_i].f1.set_size(r6.size(0), r6.size(1));
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = r6.size(0);
            for (i2 = 0; i2 < b_loop_ub; i2++) {
              resampledLayers[b_i].f1[i2 + resampledLayers[b_i].f1.size(0) * i1]
                = r6[i2 + r6.size(0) * i1];
            }
          }
        }
      }
    }

    void standardLayers(const struct0_T *problemStruct, const struct3_T
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
                        &resampledLayers, ::coder::array<real_T, 1U> &subRoughs)
    {
      ::coder::array<cell_wrap_1, 2U> data;
      ::coder::array<cell_wrap_10, 2U> a__5;
      ::coder::array<cell_wrap_10, 2U> contrastLayers;
      ::coder::array<cell_wrap_10, 2U> layersDetails;
      ::coder::array<cell_wrap_13, 2U> contrastBackgroundIndices;
      ::coder::array<cell_wrap_13, 2U> outParameterisedLayers;
      ::coder::array<cell_wrap_2, 2U> dataLimits;
      ::coder::array<cell_wrap_2, 2U> repeatLayers;
      ::coder::array<cell_wrap_2, 2U> simLimits;
      ::coder::array<cell_wrap_7, 2U> contrastBackgroundActions;
      ::coder::array<cell_wrap_7, 2U> contrastBackgroundTypes;
      ::coder::array<cell_wrap_7, 2U> customFiles;
      ::coder::array<real_T, 2U> a__1;
      ::coder::array<real_T, 2U> a__2;
      ::coder::array<real_T, 2U> a__4;
      ::coder::array<real_T, 2U> backgroundParamArray;
      ::coder::array<real_T, 2U> bulkInArray;
      ::coder::array<real_T, 2U> bulkOutArray;
      ::coder::array<real_T, 2U> contrastBulkInIndices;
      ::coder::array<real_T, 2U> contrastBulkOutIndices;
      ::coder::array<real_T, 2U> contrastQzshiftIndices;
      ::coder::array<real_T, 2U> contrastResolutionParamIndices;
      ::coder::array<real_T, 2U> contrastScalefactorIndices;
      ::coder::array<real_T, 2U> dataPresent;
      ::coder::array<real_T, 2U> params;
      ::coder::array<real_T, 2U> qzshiftArray;
      ::coder::array<real_T, 2U> r;
      ::coder::array<real_T, 2U> r1;
      ::coder::array<real_T, 2U> r2;
      ::coder::array<real_T, 2U> r3;
      ::coder::array<real_T, 2U> r4;
      ::coder::array<real_T, 2U> r5;
      ::coder::array<real_T, 2U> r6;
      ::coder::array<real_T, 2U> r7;
      ::coder::array<real_T, 2U> resample;
      ::coder::array<real_T, 2U> resolutionParamArray;
      ::coder::array<real_T, 2U> scalefactorArray;
      real_T a__3;
      real_T d;
      real_T d1;
      real_T d2;
      real_T d3;
      real_T d4;
      real_T d5;
      real_T nParams;
      real_T numberOfContrasts;
      real_T resampleMinAngle;
      real_T resampleNPoints;
      int32_T geometry_size[2];
      int32_T iv[2];
      int32_T iv1[2];
      int32_T iv2[2];
      int32_T iv3[2];
      int32_T b_i;
      int32_T c_loop_ub;
      int32_T d_loop_ub;
      int32_T i;
      int32_T i2;
      int32_T i3;
      int32_T ub_loop;
      char_T geometry_data[10000];
      boolean_T useImaginary;

      //  This is the main reflectivity calculation of the standard layers
      //  calculation type. It extracts the required parameters for the contrasts
      //  from the input arrays, then passes the main calculation to
      //  'coreLayersCalculation', which carries out the calculation itself.
      //  The core calculation is common for both standard and custom layers.
      //  Extract parameters from problemStruct
      extractProblemParams(problemStruct, &numberOfContrasts, geometry_data,
                           geometry_size, contrastBackgroundIndices,
                           contrastQzshiftIndices, contrastScalefactorIndices,
                           contrastBulkInIndices, contrastBulkOutIndices,
                           contrastResolutionParamIndices, a__1,
                           backgroundParamArray, qzshiftArray, scalefactorArray,
                           bulkInArray, bulkOutArray, resolutionParamArray, a__2,
                           dataPresent, &nParams, params, &a__3, resample,
                           contrastBackgroundTypes, contrastBackgroundActions,
                           a__4, &useImaginary, repeatLayers, data, dataLimits,
                           simLimits, contrastLayers, layersDetails, customFiles,
                           a__5);
      resampleMinAngle = controls->resampleMinAngle;
      resampleNPoints = controls->resampleNPoints;

      //  Allocate the memory for the output arrays before the main loop
      //  First we need to allocate the absolute values of the input
      //  parameters to all the layers in the layers list. This only needs
      //  to be done once, and so is done outside the contrasts loop
      allocateParamsToLayers(params, layersDetails, outParameterisedLayers);

      //  Substrate roughness is always first parameter for standard layers
      ub_loop = static_cast<int32_T>(numberOfContrasts);
      subRoughs.set_size(ub_loop);
      for (i = 0; i < ub_loop; i++) {
        subRoughs[i] = params[0];
      }

      if (coder::internal::m_strcmp(controls->parallel.data,
           controls->parallel.size)) {
        //  Loop over all the contrasts
        resampledLayers.set_size(ub_loop, 1);
        sldProfiles.set_size(ub_loop, 1);
        layerSlds.set_size(ub_loop, 1);
        backgrounds.set_size(ub_loop);
        shiftedData.set_size(ub_loop);
        simulation.set_size(ub_loop);
        reflectivity.set_size(ub_loop);
        qzshifts.set_size(ub_loop);
        scalefactors.set_size(ub_loop);
        bulkIns.set_size(ub_loop);
        bulkOuts.set_size(ub_loop);
        resolutionParams.set_size(ub_loop);
        chis.set_size(ub_loop);
        ub_loop = static_cast<int32_T>(numberOfContrasts) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r,r1,r2,r7,d,d1,d2,d3,d4,d5,iv2,b_i,iv3,c_loop_ub,i2,i3,d_loop_ub)

        for (b_i = 0; b_i <= ub_loop; b_i++) {
          iv2[0] = (*(int32_T (*)[2])contrastBackgroundTypes[b_i].f1.size())[0];
          iv2[1] = (*(int32_T (*)[2])contrastBackgroundTypes[b_i].f1.size())[1];
          iv3[0] = (*(int32_T (*)[2])contrastBackgroundActions[b_i].f1.size())[0];
          iv3[1] = (*(int32_T (*)[2])contrastBackgroundActions[b_i].f1.size())[1];
          contrastCalculation(contrastBackgroundIndices[b_i].f1.data,
                              contrastBackgroundIndices[b_i].f1.size,
                              contrastQzshiftIndices[b_i],
                              contrastScalefactorIndices[b_i],
                              contrastBulkInIndices[b_i],
                              contrastBulkOutIndices[b_i],
                              contrastResolutionParamIndices[b_i],
                              backgroundParamArray, qzshiftArray,
                              scalefactorArray, bulkInArray, bulkOutArray,
                              resolutionParamArray, dataPresent[b_i], data[b_i].
                              f1, dataLimits[b_i].f1, simLimits[b_i].f1,
                              repeatLayers[b_i].f1, (const char_T *)
                              contrastBackgroundTypes[b_i].f1.data(), iv2, (
            const char_T *)contrastBackgroundActions[b_i].f1.data(), iv3,
                              customFiles, nParams, controls->parallel.data,
                              controls->parallel.size, resampleMinAngle,
                              resampleNPoints, useImaginary, resample[b_i],
                              geometry_data, geometry_size, subRoughs[b_i], true,
                              contrastLayers[b_i].f1, outParameterisedLayers,
                              &d5, &d4, &d3, &d2, &d1, &d, reflectivity[b_i].f1,
                              simulation[b_i].f1, r7, backgrounds[b_i].f1, r2,
                              r1, r);
          c_loop_ub = r7.size(0);
          shiftedData[b_i].f1.set_size(r7.size(0), 3);
          for (i2 = 0; i2 < 3; i2++) {
            for (i3 = 0; i3 < c_loop_ub; i3++) {
              shiftedData[b_i].f1[i3 + shiftedData[b_i].f1.size(0) * i2] = r7[i3
                + r7.size(0) * i2];
            }
          }

          c_loop_ub = r2.size(1);
          layerSlds[b_i].f1.set_size(r2.size(0), r2.size(1));
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            d_loop_ub = r2.size(0);
            for (i3 = 0; i3 < d_loop_ub; i3++) {
              layerSlds[b_i].f1[i3 + layerSlds[b_i].f1.size(0) * i2] = r2[i3 +
                r2.size(0) * i2];
            }
          }

          c_loop_ub = r1.size(0);
          sldProfiles[b_i].f1.set_size(r1.size(0), 2);
          for (i2 = 0; i2 < 2; i2++) {
            for (i3 = 0; i3 < c_loop_ub; i3++) {
              sldProfiles[b_i].f1[i3 + sldProfiles[b_i].f1.size(0) * i2] = r1[i3
                + r1.size(0) * i2];
            }
          }

          c_loop_ub = r.size(1);
          resampledLayers[b_i].f1.set_size(r.size(0), r.size(1));
          for (i2 = 0; i2 < c_loop_ub; i2++) {
            d_loop_ub = r.size(0);
            for (i3 = 0; i3 < d_loop_ub; i3++) {
              resampledLayers[b_i].f1[i3 + resampledLayers[b_i].f1.size(0) * i2]
                = r[i3 + r.size(0) * i2];
            }
          }

          qzshifts[b_i] = d5;
          scalefactors[b_i] = d4;
          bulkIns[b_i] = d3;
          bulkOuts[b_i] = d2;
          resolutionParams[b_i] = d1;
          chis[b_i] = d;
        }
      } else {
        //  Loop over all the contrasts
        resampledLayers.set_size(ub_loop, 1);
        sldProfiles.set_size(ub_loop, 1);
        layerSlds.set_size(ub_loop, 1);
        backgrounds.set_size(ub_loop);
        shiftedData.set_size(ub_loop);
        simulation.set_size(ub_loop);
        reflectivity.set_size(ub_loop);
        qzshifts.set_size(ub_loop);
        scalefactors.set_size(ub_loop);
        bulkIns.set_size(ub_loop);
        bulkOuts.set_size(ub_loop);
        resolutionParams.set_size(ub_loop);
        chis.set_size(ub_loop);
        for (i = 0; i < ub_loop; i++) {
          int32_T b_loop_ub;
          int32_T c_i;
          int32_T i1;
          int32_T loop_ub;
          iv[0] = (*(int32_T (*)[2])contrastBackgroundTypes[i].f1.size())[0];
          iv[1] = (*(int32_T (*)[2])contrastBackgroundTypes[i].f1.size())[1];
          iv1[0] = (*(int32_T (*)[2])contrastBackgroundActions[i].f1.size())[0];
          iv1[1] = (*(int32_T (*)[2])contrastBackgroundActions[i].f1.size())[1];
          contrastCalculation(contrastBackgroundIndices[i].f1.data,
                              contrastBackgroundIndices[i].f1.size,
                              contrastQzshiftIndices[i],
                              contrastScalefactorIndices[i],
                              contrastBulkInIndices[i], contrastBulkOutIndices[i],
                              contrastResolutionParamIndices[i],
                              backgroundParamArray, qzshiftArray,
                              scalefactorArray, bulkInArray, bulkOutArray,
                              resolutionParamArray, dataPresent[i], data[i].f1,
                              dataLimits[i].f1, simLimits[i].f1, repeatLayers[i]
                              .f1, (const char_T *)contrastBackgroundTypes[i].
                              f1.data(), iv, (const char_T *)
                              contrastBackgroundActions[i].f1.data(), iv1,
                              customFiles, nParams, controls->parallel.data,
                              controls->parallel.size, resampleMinAngle,
                              resampleNPoints, useImaginary, resample[i],
                              geometry_data, geometry_size, subRoughs[i], true,
                              contrastLayers[i].f1, outParameterisedLayers,
                              &qzshifts[i], &scalefactors[i], &bulkIns[i],
                              &bulkOuts[i], &resolutionParams[i], &chis[i],
                              reflectivity[i].f1, simulation[i].f1, r3,
                              backgrounds[i].f1, r4, r5, r6);
          loop_ub = r3.size(0);
          shiftedData[i].f1.set_size(r3.size(0), 3);
          for (c_i = 0; c_i < 3; c_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              shiftedData[i].f1[i1 + shiftedData[i].f1.size(0) * c_i] = r3[i1 +
                r3.size(0) * c_i];
            }
          }

          loop_ub = r4.size(1);
          layerSlds[i].f1.set_size(r4.size(0), r4.size(1));
          for (c_i = 0; c_i < loop_ub; c_i++) {
            b_loop_ub = r4.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              layerSlds[i].f1[i1 + layerSlds[i].f1.size(0) * c_i] = r4[i1 +
                r4.size(0) * c_i];
            }
          }

          loop_ub = r5.size(0);
          sldProfiles[i].f1.set_size(r5.size(0), 2);
          for (c_i = 0; c_i < 2; c_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              sldProfiles[i].f1[i1 + sldProfiles[i].f1.size(0) * c_i] = r5[i1 +
                r5.size(0) * c_i];
            }
          }

          loop_ub = r6.size(1);
          resampledLayers[i].f1.set_size(r6.size(0), r6.size(1));
          for (c_i = 0; c_i < loop_ub; c_i++) {
            b_loop_ub = r6.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              resampledLayers[i].f1[i1 + resampledLayers[i].f1.size(0) * c_i] =
                r6[i1 + r6.size(0) * c_i];
            }
          }
        }
      }
    }
  }
}

// End of code generation (standardLayers.cpp)
