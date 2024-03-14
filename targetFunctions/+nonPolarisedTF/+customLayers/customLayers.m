function [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,...
    resolutionParams,chis,reflectivity,simulation,shiftedData,layerSlds,...
    sldProfiles,allLayers,allRoughs] = customLayers(problemStruct,problemCells,controls)
    % The custom layers, nonPolarisedTF reflectivity calculation.
    % The function extracts the relevant parameters from the input arrays,
    % allocates these on a pre-contrast basis, then calls the 'core' 
    % calculation (the core layers nonPolarisedTF calc is shared between
    % multiple calculation types).
    
    % Extract individual cell arrays
    [repeatLayers,...
     allData,...
     dataLimits,...
     simLimits,...
     ~,~,customFiles] = parseCells(problemCells);
    
    % Extract individual parameters from problemStruct
    [numberOfContrasts, geometry, contrastBackgroundIndices, contrastQzshiftIndices, contrastScalefactorIndices, contrastBulkInIndices, contrastBulkOutIndices,...
    contrastResolutionIndices, backgroundParamArray, qzshiftArray, scalefactorArray, bulkInArray, bulkOutArray, resolutionParamArray, dataPresent, nParams, params,...
    ~, resample, contrastBackgroundsType, cCustFiles] =  extractProblemParams(problemStruct);
    
    calcSld = controls.calcSldDuringFit;
    parallel = controls.parallel;
    resamPars = controls.resamPars;
    useImaginary = problemStruct.useImaginary;
                         
    % Pre-Allocation of output arrays...
    backgroundParams = zeros(numberOfContrasts,1);
    qzshifts = zeros(numberOfContrasts,1);
    scalefactors = zeros(numberOfContrasts,1);
    bulkIns = zeros(numberOfContrasts,1);
    bulkOuts = zeros(numberOfContrasts,1);
    resolutionParams = zeros(numberOfContrasts,1);
    allRoughs = zeros(numberOfContrasts,1);
    outSsubs = zeros(numberOfContrasts,1);
    chis = zeros(numberOfContrasts,1);
    layerSlds = cell(numberOfContrasts,1);
    sldProfiles = cell(numberOfContrasts,1);
    shiftedData = cell(numberOfContrasts,1);
    
    reflectivity = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        reflectivity{i} = [1 1 ; 1 1];
    end
    
    simulation = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        simulation{i} = [1 1 ; 1 1];
    end
    
    allLayers = cell(numberOfContrasts,1);
    for i = 1:numberOfContrasts
        allLayers{i} = [1 ; 1];
    end
    
    %   --- End Memory Allocation ---
    
    % Process the custom models
    [allLayers,allRoughs] = nonPolarisedTF.customLayers.processCustomFunction(contrastBulkInIndices,contrastBulkOutIndices,...
        bulkInArray,bulkOutArray,cCustFiles,numberOfContrasts,customFiles,params,useImaginary);
    
    if strcmpi(parallel, coderEnums.parallelOptions.Contrasts)
    
        % Multi cored over all contrasts
        parfor i = 1:numberOfContrasts
            
            [backgroundParams(i),qzshifts(i),scalefactors(i),bulkIns(i),...
             bulkOuts(i),resolutionParams(i),reflectivity{i},simulation{i},...
             shiftedData{i},layerSlds{i},sldProfiles{i},allLayers{i},chis(i),...
             outSsubs(i)] = contrastCalculation(contrastBackgroundIndices(i),...
            contrastQzshiftIndices(i),contrastScalefactorIndices(i),contrastBulkInIndices(i),...
            contrastBulkOutIndices(i),contrastResolutionIndices(i),...
            backgroundParamArray,qzshiftArray,scalefactorArray,bulkInArray,...
            bulkOutArray,resolutionParamArray,dataPresent(i),allData{i},...
            dataLimits{i},simLimits{i},repeatLayers{i},contrastBackgroundsType(i),...
            nParams,parallel,resamPars,useImaginary,resample(i),geometry,...
            allRoughs(i),calcSld,allLayers{i});
        
        end
    
    else
    
        % Single cored over all contrasts
        for i = 1:numberOfContrasts

            [backgroundParams(i),qzshifts(i),scalefactors(i),bulkIns(i),...
             bulkOuts(i),resolutionParams(i),reflectivity{i},simulation{i},...
             shiftedData{i},layerSlds{i},sldProfiles{i},allLayers{i},chis(i),...
             outSsubs(i)] = contrastCalculation(contrastBackgroundIndices(i),...
            contrastQzshiftIndices(i),contrastScalefactorIndices(i),contrastBulkInIndices(i),...
            contrastBulkOutIndices(i),contrastResolutionIndices(i),...
            backgroundParamArray,qzshiftArray,scalefactorArray,bulkInArray,...
            bulkOutArray,resolutionParamArray,dataPresent(i),allData{i},...
            dataLimits{i},simLimits{i},repeatLayers{i},contrastBackgroundsType(i),...
            nParams,parallel,resamPars,useImaginary,resample(i),geometry,...
            allRoughs(i),calcSld,allLayers{i});

        end
    
    end

end

function [backgroundParamValue,qzshiftValue,scalefactorValue,bulkInValue,...
    bulkOutValue,resolutionParamValue,reflectivity,simulation,shiftedData,...
    layerSld,sldProfile,allLayer,chi,ssub] = contrastCalculation(backgroundParamIndex,...
    qzshiftIndex,scalefactorIndex,bulkInIndex,bulkOutIndex,resolutionParamIndex,...
    backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams,...
    dataPresent,allData,dataLimits,simLimits,repeatLayers,contrastBackgroundsType,...
    nParams,parallel,resamPars,useImaginary,resample,geometry,roughness,...
    calcSld,layer)

    % Extract the relevant parameter values for this contrast
    % from the input arrays.
    % First need to decide which values of the backgrounds, scalefactors
    % data shifts and bulk contrasts are associated with this contrast
    [backgroundParamValue,qzshiftValue,scalefactorValue,bulkInValue,bulkOutValue,...
     resolutionParamValue] = backSort(backgroundParamIndex,qzshiftIndex,...
     scalefactorIndex,bulkInIndex,bulkOutIndex,resolutionParamIndex,...
     backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,resolutionParams);
        
    % Call the core layers calculation
    [sldProfile,reflectivity,simulation,shiftedData,layerSld,allLayer,...
     chi,ssub] = nonPolarisedTF.coreLayersCalculation(layer,roughness,...
     geometry,bulkInValue,bulkOutValue,resample,calcSld,scalefactorValue,qzshiftValue,...
     dataPresent,allData,dataLimits,simLimits,repeatLayers,backgroundParamValue,...
     resolutionParamValue,contrastBackgroundsType,nParams,parallel,resamPars,useImaginary);

end
