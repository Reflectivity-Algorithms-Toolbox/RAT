function [outSsubs,backgroundParams,qzshifts,scalefactors,bulkIns,bulkOuts,...
    resolutionParams,chis,reflectivity,simulation,shiftedData,layerSlds,...
    sldProfiles,allLayers,allRoughs] = customXY(problemStruct,problemCells,controls)

% Extract individual cell arrays
[repeatLayers,...
 allData,...
 dataLimits,...
 simLimits,...
 ~,~,...        % Layers details N/A
 customFiles] = parseCells(problemCells);

% Extract individual parameters from problemStruct
[numberOfContrasts, ~, contrastBackgrounds, contrastQzshifts, contrastScalefactors, contrastBulkIns, contrastBulkOuts,...
contrastResolutions, backgroundParam, qzshift, scalefactor, bulkIn, bulkOut, resolutionParam, dataPresent, nParams, params,...
~, ~, contrastBackgroundsType, cCustFiles] =  extractProblemParams(problemStruct);      
            
%Pre-Allocation...
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

sldProfiles = cell(numberOfContrasts,1);
for i = 1:numberOfContrasts
    sldProfiles{i} = [1 ; 1];
end

% Resampling parameters
resamPars = controls.resamPars;
parallel = controls.parallel;
useImaginary = problemStruct.useImaginary;

[sldProfiles,allRoughs] = nonPolarisedTF.customXY.processCustomFunction(contrastBackgrounds,contrastQzshifts,contrastScalefactors,contrastBulkIns,contrastBulkOuts,contrastResolutions,backgroundParam, ...
    qzshift,scalefactor,bulkIn,bulkOut,resolutionParam,cCustFiles,numberOfContrasts,customFiles,params);

if strcmpi(parallel, coderEnums.parallelOptions.Contrasts)

    parfor i = 1:numberOfContrasts
        [backgroundParams(i),qzshifts(i),scalefactors(i),bulkIns(i),bulkOuts(i),resolutionParams(i)] = backSort(contrastBackgrounds(i),contrastQzshifts(i),contrastScalefactors(i),contrastBulkIns(i),contrastBulkOuts(i),contrastResolutions(i),backgroundParam,qzshift,scalefactor,bulkIn,bulkOut,resolutionParam);
    
        % Resample the layers
        sld = sldProfiles{i};
        if ~useImaginary
            layerSld = resampleLayers(sld,resamPars);
        else
            reSLD = sld(:,1:2);
            imSLD = [sld(:,1),sld(:,3)];
            layerSld = resampleLayersReIm(reSLD,imSLD,resamPars);
        end
        
        layerSlds{i} = layerSld;
        allLayers{i} = layerSld;
    
        shiftedDat =  shiftData(scalefactors(i),qzshifts(i),dataPresent(i),allData{i},dataLimits{i},simLimits{i});
        shiftedData{i} = shiftedDat;

        reflectivityType = 'standardAbeles';
        [reflect,simul] = callReflectivity(bulkIns(i),bulkOuts(i),simLimits{i},repeatLayers{i},shiftedDat,layerSld,outSsubs(i),resolutionParams(i),parallel,reflectivityType,useImaginary);
        
        [reflectivity{i},simulation{i},shiftedDat] = applyBackgroundCorrection(reflect,simul,shiftedDat,backgroundParams(i),contrastBackgroundsType(i));
        
        if dataPresent(i)
            chis(i) = chiSquared(shiftedDat,reflect,nParams);
        else
            chis(i) = 0;
        end
    end

else

    for i = 1:numberOfContrasts
        [backgroundParams(i),qzshifts(i),scalefactors(i),bulkIns(i),bulkOuts(i),resolutionParams(i)] = backSort(contrastBackgrounds(i),contrastQzshifts(i),contrastScalefactors(i),contrastBulkIns(i),contrastBulkOuts(i),contrastResolutions(i),backgroundParam,qzshift,scalefactor,bulkIn,bulkOut,resolutionParam);
    
        % Resample the layers
        sld = sldProfiles{i};
        if ~useImaginary
            layerSld = resampleLayers(sld,resamPars);
        else
            reSLD = sld(:,1:2);
            imSLD = [sld(:,1),sld(:,3)];
            layerSld = resampleLayersReIm(reSLD,imSLD,resamPars);
        end
        
        layerSlds{i} = layerSld;
        allLayers{i} = layerSld;
    
        shiftedDat =  shiftData(scalefactors(i),qzshifts(i),dataPresent(i),allData{i},dataLimits{i},simLimits{i});
        shiftedData{i} = shiftedDat;

        reflectivityType = 'standardAbeles';
        [reflect,simul] = callReflectivity(bulkIns(i),bulkOuts(i),simLimits{i},repeatLayers{i},shiftedDat,layerSld,outSsubs(i),resolutionParams(i),parallel,reflectivityType,useImaginary);
        
        [reflectivity{i},simulation{i},shiftedDat] = applyBackgroundCorrection(reflect,simul,shiftedDat,backgroundParams(i),contrastBackgroundsType(i));
        
        if dataPresent(i)
            chis(i) = chiSquared(shiftedDat,reflect,nParams);
        else
            chis(i) = 0;
        end
    end

end
