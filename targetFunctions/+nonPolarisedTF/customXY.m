function [qzshifts,scalefactors,bulkIns,bulkOuts,...
    resolutionParams,chis,reflectivity,simulation,shiftedData,backgrounds,layerSlds,...
    sldProfiles,resampledLayers,subRoughs] = customXY(problemStruct,problemCells,controls)

    % Extract parameters from problemStruct
    [numberOfContrasts, ~, contrastBackgroundIndices, contrastQzshiftIndices,...
     contrastScalefactorIndices, contrastBulkInIndices, contrastBulkOutIndices,...
     contrastResolutionParamIndices, ~, backgroundParamArray, qzshiftArray,...
     scalefactorArray, bulkInArray, bulkOutArray, resolutionParamArray, ~,...
     dataPresent, nParams, params, ~, ~, contrastBackgroundTypes,...
     contrastBackgroundActions, cCustFiles, useImaginary, repeatLayers,...
     data, dataLimits, simLimits, ~, ~, customFiles, ~] = extractProblemParams(problemStruct);

    parallel = controls.parallel;
    resampleMinAngle = controls.resampleMinAngle;
    resampleNPoints = controls.resampleNPoints;
                
    %Pre-Allocation...
    qzshifts = zeros(numberOfContrasts,1);
    scalefactors = zeros(numberOfContrasts,1);
    bulkIns = zeros(numberOfContrasts,1);
    bulkOuts = zeros(numberOfContrasts,1);
    resolutionParams = zeros(numberOfContrasts,1);
    chis = zeros(numberOfContrasts,1);
   
    reflectivity = cell(numberOfContrasts,1);    
    simulation = cell(numberOfContrasts,1);
    shiftedData = cell(numberOfContrasts,1);
    backgrounds = cell(numberOfContrasts,1);
    layerSlds = cell(numberOfContrasts,1);
    resampledLayers = cell(numberOfContrasts,1);

    % Process the custom models
    [sldProfiles,subRoughs] = nonPolarisedTF.customXY.processCustomFunction(contrastBulkInIndices,contrastBulkOutIndices,...
        bulkInArray,bulkOutArray,cCustFiles,numberOfContrasts,customFiles,params);
    
    if strcmpi(parallel, coderEnums.parallelOptions.Contrasts)
    
        parfor i = 1:numberOfContrasts

            [qzshifts(i),scalefactors(i),bulkIns(i),...
             bulkOuts(i),resolutionParams(i),chis(i),reflectivity{i},...
             simulation{i},shiftedData{i},backgrounds{i},layerSlds{i},sldProfiles{i},...
             resampledLayers{i}...
             ] = contrastCalculation(contrastBackgroundIndices{i},...
             contrastQzshiftIndices(i),contrastScalefactorIndices(i),...
             contrastBulkInIndices(i),contrastBulkOutIndices(i),...
             contrastResolutionParamIndices(i),backgroundParamArray,qzshiftArray,...
             scalefactorArray,bulkInArray,bulkOutArray,resolutionParamArray,...
             dataPresent(i),data{i},dataLimits{i},simLimits{i},...
             repeatLayers{i},contrastBackgroundTypes{i}, ...
             contrastBackgroundActions{i},customFiles,nParams,parallel,...
             resampleMinAngle,resampleNPoints,useImaginary,subRoughs(i),sldProfiles{i});
        end
    
    else
    
        for i = 1:numberOfContrasts

            [qzshifts(i),scalefactors(i),bulkIns(i),...
             bulkOuts(i),resolutionParams(i),chis(i),reflectivity{i},...
             simulation{i},shiftedData{i},backgrounds{i},layerSlds{i},sldProfiles{i},...
             resampledLayers{i}...
             ] = contrastCalculation(contrastBackgroundIndices{i},...
             contrastQzshiftIndices(i),contrastScalefactorIndices(i),...
             contrastBulkInIndices(i),contrastBulkOutIndices(i),...
             contrastResolutionParamIndices(i),backgroundParamArray,qzshiftArray,...
             scalefactorArray,bulkInArray,bulkOutArray,resolutionParamArray,...
             dataPresent(i),data{i},dataLimits{i},simLimits{i},...
             repeatLayers{i},contrastBackgroundTypes{i}, ...
             contrastBackgroundActions{i},customFiles,nParams,parallel,...
             resampleMinAngle,resampleNPoints,useImaginary,subRoughs(i),sldProfiles{i});

        end
    
    end

end


function [qzshiftValue,scalefactorValue,bulkInValue,...
    bulkOutValue,resolutionParamValue,chi,reflectivity,simulation,shiftedData,background,...
    layerSld,sldProfile,resampledLayer] = contrastCalculation(backgroundParamIndex,...
    qzshiftIndex,scalefactorIndex,bulkInIndex,bulkOutIndex,resolutionParamIndex,...
    backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams,...
    dataPresent,data,dataLimits,simLimits,repeatLayers,backgroundType,...
    backgroundAction,customFiles,nParams,parallel,resampleMinAngle,resampleNPoints,useImaginary,roughness,sldProfile)

    % Extract the relevant parameter values for this contrast
    % from the input arrays.
    % First need to decide which values of the backgrounds, scalefactors
    % data shifts and bulk contrasts are associated with this contrast
    [qzshiftValue,scalefactorValue,bulkInValue,bulkOutValue,...
     resolutionParamValue] = backSort(qzshiftIndex,...
     scalefactorIndex,bulkInIndex,bulkOutIndex,resolutionParamIndex,...
     qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams);
     
    % Resample the layers
    if ~useImaginary
        layerSld = resampleLayers(sldProfile,resampleMinAngle,resampleNPoints);
    else
        reSLD = sldProfile(:,1:2);
        imSLD = [sldProfile(:,1),sldProfile(:,3)];
        layerSld = resampleLayersReIm(reSLD,imSLD,resampleMinAngle,resampleNPoints);
    end
    
    resampledLayer = layerSld;

    shiftedData = shiftData(scalefactorValue,qzshiftValue,dataPresent,data,dataLimits,simLimits);
    background = constructBackground(backgroundType,backgroundParamIndex,shiftedData,customFiles,backgroundParams,simLimits);

    reflectivityType = 'standardAbeles';
    [reflect,simul] = callReflectivity(bulkInValue,bulkOutValue,simLimits,repeatLayers,shiftedData,layerSld,roughness,resolutionParamValue,parallel,reflectivityType,useImaginary);

    [reflectivity,simulation,shiftedData] = applyBackgroundCorrection(reflect,simul,shiftedData,background,backgroundAction);
    
    if dataPresent
        chi = chiSquared(shiftedData,reflectivity,nParams);
    else
        chi = 0;
    end

end
