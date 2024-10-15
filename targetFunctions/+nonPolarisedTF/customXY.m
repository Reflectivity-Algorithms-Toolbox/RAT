function [qzshifts,scalefactors,bulkIns,bulkOuts,...
    resolutionParams,chis,reflectivity,simulation,shiftedData,backgrounds,layerSlds,...
    sldProfiles,resampledLayers,subRoughs] = customXY(problemStruct,problemCells,controls)

    % Extract individual cell arrays
    [repeatLayers,...
     data,...
     dataLimits,...
     simLimits,...
     ~,~,...        % Layers details N/A
     customFiles] = parseCells(problemCells);
    
    % Extract individual parameters from problemStruct
    [numberOfContrasts, ~, contrastBackgroundIndices, contrastQzshiftIndices,...
     contrastScalefactorIndices, contrastBulkInIndices, contrastBulkOutIndices,...
     contrastResolutionParamIndices, ~, backgroundParamArray, qzshiftArray,...
     scalefactorArray, bulkInArray, bulkOutArray, resolutionParamArray, ~,...
     dataPresent, nParams, params, ~, ~, contrastBackgroundActions, cCustFiles,...
     useImaginary] = extractProblemParams(problemStruct);

    parallel = controls.parallel;
    resampleMinAngle = controls.resampleMinAngle;
    resampleNPoints = controls.resampleNPoints;
                
    %Pre-Allocation...
    qzshifts = zeros(numberOfContrasts,1);
    scalefactors = zeros(numberOfContrasts,1);
    bulkIns = zeros(numberOfContrasts,1);
    bulkOuts = zeros(numberOfContrasts,1);
    resolutionParams = zeros(numberOfContrasts,1);
    subRoughs = zeros(numberOfContrasts,1);
    chis = zeros(numberOfContrasts,1);
    layerSlds = cell(numberOfContrasts,1);
    shiftedData = cell(numberOfContrasts,1);
    backgrounds = cell(numberOfContrasts,1);
    
    reflectivity = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        reflectivity{i} = [1 1; 1 1];
    end
    
    simulation = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        simulation{i} = [1 1; 1 1];
    end
    
    resampledLayers = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        resampledLayers{i} = [1; 1];
    end
    
    sldProfiles = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        sldProfiles{i} = [1; 1];
    end

    % Process the custom models
    [sldProfiles,subRoughs] = nonPolarisedTF.customXY.processCustomFunction(contrastBulkInIndices,contrastBulkOutIndices,...
        bulkInArray,bulkOutArray,cCustFiles,numberOfContrasts,customFiles,params);
    
    if strcmpi(parallel, coderEnums.parallelOptions.Contrasts)
    
        parfor i = 1:numberOfContrasts

            [qzshifts(i),scalefactors(i),bulkIns(i),...
             bulkOuts(i),resolutionParams(i),chis(i),reflectivity{i},...
             simulation{i},shiftedData{i},backgrounds{i},layerSlds{i},sldProfiles{i},...
             resampledLayers{i}...
             ] = contrastCalculation(contrastBackgroundIndices(i,:),...
             contrastQzshiftIndices(i),contrastScalefactorIndices(i),...
             contrastBulkInIndices(i),contrastBulkOutIndices(i),...
             contrastResolutionParamIndices(i),backgroundParamArray,qzshiftArray,...
             scalefactorArray,bulkInArray,bulkOutArray,resolutionParamArray,...
             dataPresent(i),data{i},dataLimits{i},simLimits{i},...
             repeatLayers{i},contrastBackgroundActions(i),customFiles,nParams,parallel,...
             resampleMinAngle,resampleNPoints,useImaginary,subRoughs(i),sldProfiles{i});
        end
    
    else
    
        for i = 1:numberOfContrasts

            [qzshifts(i),scalefactors(i),bulkIns(i),...
             bulkOuts(i),resolutionParams(i),chis(i),reflectivity{i},...
             simulation{i},shiftedData{i},backgrounds{i},layerSlds{i},sldProfiles{i},...
             resampledLayers{i}...
             ] = contrastCalculation(contrastBackgroundIndices(i,:),...
             contrastQzshiftIndices(i),contrastScalefactorIndices(i),...
             contrastBulkInIndices(i),contrastBulkOutIndices(i),...
             contrastResolutionParamIndices(i),backgroundParamArray,qzshiftArray,...
             scalefactorArray,bulkInArray,bulkOutArray,resolutionParamArray,...
             dataPresent(i),data{i},dataLimits{i},simLimits{i},...
             repeatLayers{i},contrastBackgroundActions(i),customFiles,nParams,parallel,...
             resampleMinAngle,resampleNPoints,useImaginary,subRoughs(i),sldProfiles{i});

        end
    
    end

end


function [qzshiftValue,scalefactorValue,bulkInValue,...
    bulkOutValue,resolutionParamValue,chi,reflectivity,simulation,shiftedData,background,...
    layerSld,sldProfile,resampledLayer] = contrastCalculation(backgroundParamIndex,...
    qzshiftIndex,scalefactorIndex,bulkInIndex,bulkOutIndex,resolutionParamIndex,...
    backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams,...
    dataPresent,data,dataLimits,simLimits,repeatLayers,contrastBackgroundActions,...
    customFiles,nParams,parallel,resampleMinAngle,resampleNPoints,useImaginary,roughness,sldProfile)

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

    shiftedDat = shiftData(scalefactorValue,qzshiftValue,dataPresent,data,dataLimits,simLimits);
    background = constructBackground(backgroundParamIndex,shiftedDat,customFiles,backgroundParams,simLimits);
    shiftedData = shiftedDat;

    reflectivityType = 'standardAbeles';
    [reflect,simul] = callReflectivity(bulkInValue,bulkOutValue,simLimits,repeatLayers,shiftedDat,layerSld,roughness,resolutionParamValue,parallel,reflectivityType,useImaginary);

    [reflectivity,simulation,shiftedDat] = applyBackgroundCorrection(reflect,simul,shiftedDat,background,contrastBackgroundActions);
    
    if dataPresent
        chi = chiSquared(shiftedDat,reflectivity,nParams);
    else
        chi = 0;
    end

end
