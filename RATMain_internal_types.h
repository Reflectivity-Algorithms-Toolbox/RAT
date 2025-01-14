//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// RATMain_internal_types.h
//
// Code generation for function 'RATMain'
//
#ifndef RATMAIN_INTERNAL_TYPES_H
#define RATMAIN_INTERNAL_TYPES_H

// Include files
#include "RATMain_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "coder_bounded_array.h"

// Type Definitions
namespace RAT
{
  struct struct_T
  {
    real_T I_nc;
    real_T FVr_ca;
    real_T I_no;
    real_T FVr_oa;
  };

  struct b_struct_T
  {
    real_T Y;
    real_T N;
  };

  struct c_struct_T
  {
    real_T LogZ;
    real_T LogZErr;
    ::coder::bounded_array<real_T, 2U, 2U> nestSamples;
    ::coder::bounded_array<real_T, 2U, 2U> postSamples;
  };

  struct cell_wrap_53
  {
    ::coder::array<real_T, 1U> f1;
  };

  struct cell_wrap_49
  {
    ::coder::array<cell_wrap_11, 1U> f1;
  };

  struct cell_wrap_50
  {
    ::coder::array<cell_wrap_11, 2U> f1;
  };

  struct d_struct_T
  {
    ::coder::array<cell_wrap_7, 2U> params;
    ::coder::array<cell_wrap_7, 2U> backgroundParams;
    ::coder::array<cell_wrap_7, 2U> scalefactors;
    ::coder::array<cell_wrap_7, 2U> qzshifts;
    ::coder::array<cell_wrap_7, 2U> bulkIns;
    ::coder::array<cell_wrap_7, 2U> bulkOuts;
    ::coder::array<cell_wrap_7, 2U> resolutionParams;
    ::coder::array<cell_wrap_7, 2U> domainRatios;
    ::coder::array<cell_wrap_7, 2U> contrasts;
  };

  struct e_struct_T
  {
    ::coder::bounded_array<char_T, 10000U, 2U> TF;
    ::coder::array<real_T, 2U> resample;
    ::coder::array<cell_wrap_1, 2U> data;
    ::coder::array<real_T, 2U> dataPresent;
    ::coder::array<cell_wrap_2, 2U> dataLimits;
    ::coder::array<cell_wrap_2, 2U> simulationLimits;
    ::coder::array<real_T, 2U> oilChiDataPresent;
    real_T numberOfContrasts;
    ::coder::bounded_array<char_T, 10000U, 2U> geometry;
    boolean_T useImaginary;
    ::coder::array<cell_wrap_2, 2U> repeatLayers;
    ::coder::array<cell_wrap_48, 2U> contrastBackgroundParams;
    ::coder::array<cell_wrap_7, 2U> contrastBackgroundTypes;
    ::coder::array<cell_wrap_7, 2U> contrastBackgroundActions;
    ::coder::array<real_T, 2U> contrastQzshifts;
    ::coder::array<real_T, 2U> contrastScalefactors;
    ::coder::array<real_T, 2U> contrastBulkIns;
    ::coder::array<real_T, 2U> contrastBulkOuts;
    ::coder::array<real_T, 2U> contrastResolutionParams;
    ::coder::array<real_T, 2U> backgroundParams;
    ::coder::array<real_T, 2U> qzshifts;
    ::coder::array<real_T, 2U> scalefactors;
    ::coder::array<real_T, 2U> bulkIns;
    ::coder::array<real_T, 2U> bulkOuts;
    ::coder::array<real_T, 2U> resolutionParams;
    ::coder::array<real_T, 2U> params;
    real_T numberOfLayers;
    ::coder::array<cell_wrap_10, 2U> contrastLayers;
    ::coder::array<cell_wrap_10, 2U> layersDetails;
    ::coder::array<cell_wrap_7, 2U> customFiles;
    ::coder::bounded_array<char_T, 10000U, 2U> modelType;
    ::coder::array<real_T, 2U> contrastCustomFiles;
    ::coder::array<real_T, 2U> contrastDomainRatios;
    ::coder::array<real_T, 2U> domainRatios;
    real_T numberOfDomainContrasts;
    ::coder::array<cell_wrap_10, 2U> domainContrastLayers;
    ::coder::array<real_T, 2U> fitParams;
    ::coder::array<real_T, 2U> otherParams;
    ::coder::array<real_T, 2U> fitLimits;
    ::coder::array<real_T, 2U> otherLimits;
    d_struct_T names;
    struct2_T checks;
  };

  struct cell_wrap_34
  {
    ::coder::array<real_T, 2U> f1;
  };

  struct cell_wrap_64
  {
    cell_wrap_10 f1[2];
  };

  struct cell_wrap_65
  {
    cell_wrap_8 f1[2];
  };

  struct f_struct_T
  {
    ::coder::array<cell_wrap_8, 1U> reflectivity;
    ::coder::array<cell_wrap_8, 1U> simulation;
    ::coder::array<cell_wrap_9, 1U> shiftedData;
    ::coder::array<cell_wrap_9, 1U> backgrounds;
    ::coder::array<cell_wrap_10, 2U> layerSlds;
    ::coder::array<cell_wrap_10, 2U> sldProfiles;
    ::coder::array<cell_wrap_10, 2U> resampledLayers;
    struct7_T calculationResults;
    struct8_T contrastParams;
    ::coder::array<real_T, 2U> fitParams;
    ::coder::array<cell_wrap_7, 1U> fitNames;
  };

  struct g_struct_T
  {
    struct10_T predictionIntervals;
    struct11_T confidenceIntervals;
    struct12_T dreamParams;
    struct13_T dreamOutput;
    c_struct_T nestedSamplerOutput;
    ::coder::array<real_T, 2U> chain;
  };

  struct h_struct_T
  {
    ::coder::array<cell_wrap_11, 1U> reflectivity;
    ::coder::array<cell_wrap_11, 2U> sld;
    real_T sampleChi[1000];
  };

  struct i_struct_T
  {
    h_struct_T predictionIntervals;
    struct11_T confidenceIntervals;
  };

  struct j_struct_T
  {
    ::coder::bounded_array<real_T, 2000U, 2U> outlierChains;
    real_T runtime;
    struct12_T DREAMPar;
    b_struct_T Meas_info;
    real_T iteration;
    real_T iloc;
    real_T modelOutput;
    ::coder::bounded_array<real_T, 2000U, 2U> AR;
    ::coder::array<real_T, 2U> R_stat;
    ::coder::array<real_T, 2U> CR;
  };

  struct k_struct_T
  {
    real_T iterations;
    real_T funcCount;
    char_T algorithm[33];
    ::coder::array<char_T, 2U> message;
  };

  struct l_struct_T
  {
    real_T I_lentol;
    real_T FVr_x[50];
    real_T FVr_lim_up[50];
    real_T FVr_lim_lo[50];
    real_T I_NP;
    real_T fWeight;
    real_T F_CR;
    real_T I_D;
    ::coder::array<real_T, 2U> FVr_minbound;
    ::coder::array<real_T, 2U> FVr_maxbound;
    real_T I_bnd_constr;
    real_T I_itermax;
    real_T F_VTR;
    real_T I_strategy;
    real_T I_refresh;
    real_T I_plotting;
    ::coder::array<real_T, 2U> FM_pop;
    ::coder::array<real_T, 2U> FVr_bestmem;
  };

  struct cell_57
  {
    ::coder::array<real_T, 2U> f1;
  };
}

#endif

// End of code generation (RATMain_internal_types.h)
