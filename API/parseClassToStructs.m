function [problemDef,problemDefCells,problemDefLimits,priors,controls] = parseClassToStructs(inputProblemDef,inputControls)

% Breaks up the classes into the relevant structures for inputting into C

% Put the extracted fields into a cell array...
% Structure of problemDefCells array.
%
% {1} - inputProblemDef.contrastRepeatSLDs
%       {1 x nContrasts} array of cells
%       Each cell is {1 x 2 double}.
%
% {2} - inputProblemDef.allData
%       {1 x nContrasts} array of cells
%       Each cell is {Inf x 3 double}
%
% {3} - inputProblemDef.dataLimits
%       {1 x nContrasts} array of cells
%       Each cell is {1 x 2 double}
%
% {4} - inputProblemDef.simLimits
%       {1 x nContrasts} array of cells
%       Each cell is {1 x 2 double}
%
% {5} - inputProblemDef.contrastLayers
%       {1 x nContrasts} array of cells
%       Each cell is {1 x Inf double}
%
% {6} - inputProblemDef.layersDetails
%       {n x 1} array of cells
%       Each cell is (1 x 5 double}
%
% {7} - inputProblemDef.paramNames
%       {1 x nParams} array of cells
%       Each cell is {1 x Inf char}
%
% {8} - inputProblemDef.backgroundsNames
%       {1 x nBackgrounds} array of cells
%       Each cell is {1 x Inf char}
% 
% {9} - inputProblemDef.scalefactorNames
%       {1 x nScales} array of cells
%       Each cell is {1 x Inf char}
% 
% {10}- inputProblemDef.qzshiftNames
%       {1 x nShifts} array of cells
%       Each cell is {1 x Inf char}
% 
% {11}- inputProblemDef.nbairNames
%       {1 x nNba} array of cells
%       Each cell is {1 x Inf char}
% 
% {12}- inputProblemDef.nbsrNames
%       {1 x nNba} array of cells
%       Each cell is {1 x Inf char}
% 
% {13}- inputProblemDef.resolNames
%       {1 x nNba} array of cells
%       Each cell is {1 x Inf char}
%
% {14} - inputProblemDef.customFiles
%        {1 x nCustomFiles}  array of cells
%        Each cell is {1 x Inf char}
%
% {15} - inputProblemDef.backgroundTypes
%        {1 x nBackgrounds} array of cells
%        Each cell is {1 x Inf char}
%
% {16} - inputProblemDef.resolutionTypes
%        {1 x nResolutions} array of cells
%        Each cell is {1 x Inf char}
%
% {17} - inputProblemDef.allOilChiData
%        {1 x nContrasts} array of cells
%        Each cell is {Inf x 3 double}
%
% {18} - inputProblemDef.domainContrastRepeatSLDs
%        {1 x nDomainContrasts} array of cells
%        Each cell is {1 x 2 double}.
%
% {19} - inputProblemDef.domainContrastLayers
%        {1 x nDomainContrasts} array of cells
%        Each cell is {1 x Inf double}
% 
% {20} - inputProblemDef.domainRatioNames
%        {1 x nDomainRatios} array of cells
%        Each cell is {1 x Inf char}

 
% First parse the class to a structure variable.
inputStruct = inputProblemDef.toStruct();

%% Start by removing the cell arrays
contrastLayers = inputStruct.contrastLayers;
layersDetails = inputStruct.layersDetails;

% If any of the contrastLayers are empty, replace the empty cells by zero
% thickness layers
for i = 1:length(contrastLayers)
    thisLayer = contrastLayers{i};
    if isempty(thisLayer)
        contrastLayers{i} = 0;
    end
end

% Do the same for layersDetails
if isempty(layersDetails)
    layersDetails = {0};
end

% Pull out all the cell arrays (except priors) into one array
problemDefCells{1} = inputStruct.contrastRepeatSLDs;
problemDefCells{2} = inputStruct.allData;
problemDefCells{3} = inputStruct.dataLimits;
problemDefCells{4} = inputStruct.simLimits;
problemDefCells{5} = contrastLayers;
problemDefCells{6} = layersDetails;
problemDefCells{7} = inputStruct.paramNames;
problemDefCells{8} = inputStruct.backParNames;
problemDefCells{9} = inputStruct.scalefactorNames;
problemDefCells{10} = inputStruct.qzshiftNames;
problemDefCells{11} = inputStruct.nbairNames;
problemDefCells{12} = inputStruct.nbsubNames;
problemDefCells{13} = inputStruct.resolParNames;
problemDefCells{14} = inputStruct.files;
problemDefCells{15} = cellstr(inputStruct.backgroundTypes');
problemDefCells{16} = cellstr(inputStruct.resolutionTypes');
problemDefCells{17} = inputStruct.allOilChiData;

% Now deal with domains cell arrays
if isa(inputProblemDef, 'domainsClass') && isa(inputProblemDef.domainContrasts, 'domainContrastsClass')

    domainContrastLayers = inputStruct.domainContrastLayers;

    % If any of the domainContrastLayers are empty, replace the empty
    % cells by zero thickness layers
    for i = 1:length(domainContrastLayers)
        thisLayer = domainContrastLayers{i};
        if isempty(thisLayer)
            domainContrastLayers{i} = 0;
        end
    end
    
    problemDefCells{18} = inputStruct.domainContrastRepeatSLDs;
    problemDefCells{19} = domainContrastLayers;
    
else

    problemDefCells{18} = cell(1,0);
    problemDefCells{19} = cell(1,0);

end

if isa(inputProblemDef, 'domainsClass')
    problemDefCells{20} = inputStruct.domainRatioNames;
else
    problemDefCells{20} = cell(1,0);
end

% Fix for cell array bug with custom layers - is this needed still??
if strcmpi(inputStruct.modelType,'custom layers') || strcmpi(inputStruct.modelType,'custom xy')
    for i = 1:length(problemDefCells{5})
        problemDefCells{5}{i} = 0;
    end
    for i = 1:length(problemDefCells{19})
        problemDefCells{19}{i} = 0;
    end
    
    problemDefCells{6} = {0};
    
end

% Also the custom files array..
if isempty(problemDefCells{14})
    problemDefCells{14} = {''};
end


%% Put the priors into their own array
priors.paramPriors = inputStruct.paramPriors;
priors.backsPriors = inputStruct.backsPriors;
priors.resolPriors = inputStruct.resolParPriors;
priors.nbaPriors = inputStruct.nbaPriors;
priors.nbsPriors = inputStruct.nbsPriors;
priors.shiftPriors = inputStruct.qzshiftPriors;
priors.scalesPriors = inputStruct.scalefactorPriors;
if isa(inputProblemDef, 'domainsClass')
    priors.domainRatioPriors = inputStruct.domainRatioPriors;
else
    priors.domainRatioPriors = cell(0,1);
end

priorFields = fieldnames(priors);
totalNumber = 0;
for i=1:length(priorFields)
    totalNumber = totalNumber + size(priors.(priorFields{i}), 1);
end

allPriors = cell(totalNumber,4);
cellCount = 1;

for i=1:length(priorFields)
    currentPrior = priorFields{i};
    for j = 1:size(priors.(currentPrior), 1)
        allPriors{cellCount,1} = priors.(currentPrior){j}{1};
       
        % Check prior type.....
        thisType = priors.(currentPrior){j}{2};

        if strcmpi(thisType,'uniform')
            priorType = 1;
        elseif strcmpi(thisType,'gaussian')
            priorType = 2;
        else
            priorType = 3;
        end
        allPriors{cellCount,2} = priorType;

        allPriors{cellCount,3} = priors.(currentPrior){j}{3};
        allPriors{cellCount,4} = priors.(currentPrior){j}{4};
        cellCount = cellCount + 1;
    end
end

priors.priorNames = allPriors(:, 1);
priors.priorVals = cell2mat(allPriors(:, 2:end));


%% Split up the contrastBacks array
contrastBacks = inputStruct.contrastBacks;
for i = 1:length(contrastBacks)
    problemDef.contrastBacks(i) = contrastBacks{i}(1);
    problemDef.contrastBacksType(i) = contrastBacks{i}(2);
end
    
% Here we need to do the same with the contrastResolutions array
contrastResols = inputStruct.contrastRes;
resolNames = inputStruct.resolParNames;
resolTypes = inputStruct.resolutionTypes;
contrastRes = zeros(1, length(contrastResols));
for i = 1:length(contrastResols)
    % Check the type of the resolution that each contrast is pointing to.
    % If it is a constant, point to the number of the corresponding
    % resolution par. If it's data, then set it to zero
    thisResol = contrastResols(i);      % Which reolution
    thisType = resolTypes{thisResol};   % What type is it?
    
    if strcmpi(thisType,'data')
        % Resolution is in the datafile. Set contrastRes to zero
        contrastRes(i) = -1;
    else
        % Resolution is a resolParam, the nname of which should
        % be in the first column of resolutionValues
        whichResolParName = inputStruct.resolutionValues{thisResol,1};
        
        % Find which resolPar this is, and set contrastRes to this number
        resolParNumber = find(strcmpi(whichResolParName,resolNames));
        contrastRes(i) = resolParNumber;
    end
end
        

%% Now make the limits array
for i = 1:length(inputStruct.paramLimits)
    problemDefLimits.params(i,:) = inputStruct.paramLimits{i};
end

for i = 1:length(inputStruct.backParLimits)
    problemDefLimits.backs(i,:) = inputStruct.backParLimits{i};
end

for i = 1:length(inputStruct.scalefactorLimits)
    problemDefLimits.scales(i,:) = inputStruct.scalefactorLimits{i};
end

for i = 1:length(inputStruct.qzshiftLimits)
    problemDefLimits.shifts(i,:) = inputStruct.qzshiftLimits{i};
end

for i = 1:length(inputStruct.nbairLimits)
    problemDefLimits.nba(i,:) = inputStruct.nbairLimits{i};
end

for i = 1:length(inputStruct.nbsubLimits)
    problemDefLimits.nbs(i,:) = inputStruct.nbsubLimits{i};
end

for i = 1:length(inputStruct.resolParLimits)
    problemDefLimits.res(i,:) = inputStruct.resolParLimits{i};
end

if isa(inputProblemDef, 'domainsClass')
    for i = 1:length(inputStruct.domainRatioLimits)
        problemDefLimits.domainRatio(i,:) = inputStruct.domainRatioLimits{i};
    end
else
    problemDefLimits.domainRatio = ones(0,2);
end


%% Make the problemDef structure from the remaining inputs

% *************************************************************************
% NOTE - not using the more complicated background and resolution
% definitions for now - instead use the background names and backsPar
% values.... fix this next
% **********************************************************************8


problemDef.TF = inputStruct.TF;
problemDef.resample = inputStruct.resample;
problemDef.dataPresent = inputStruct.dataPresent;
problemDef.oilChiDataPresent = inputStruct.oilChiDataPresent;
problemDef.numberOfContrasts = inputStruct.numberOfContrasts;
problemDef.geometry = inputStruct.geometry;
problemDef.useImaginary = inputStruct.useImaginary;
%problemDef.contrastBacks = contrastBacks;
problemDef.contrastShifts = inputStruct.contrastShifts;
problemDef.contrastScales = inputStruct.contrastScales;
problemDef.contrastNbas = inputStruct.contrastNbas;
problemDef.contrastNbss = inputStruct.contrastNbss;
problemDef.contrastRes = contrastRes;
problemDef.backs = inputStruct.backParValues; %inputStruct.backgrounds;       % **** note backPar workaround (todo) ****
problemDef.shifts = inputStruct.qzshiftValues;
problemDef.sf = inputStruct.scalefactorValues;
problemDef.nba = inputStruct.nbairValues;
problemDef.nbs = inputStruct.nbsubValues;
problemDef.res = inputStruct.resolParValues; %inputStruct.resolutions;           % **** note resolPar workaround (todo) ****          
problemDef.params = inputStruct.paramValues;
problemDef.numberOfLayers = inputStruct.numberOfLayers;
problemDef.modelType = inputStruct.modelType;
problemDef.contrastCustomFiles = inputStruct.contrastCustomFile;

% Add the domains parameters, using dummy values if this is not a domains
% calculation
problemDef.contrastDomainRatios = inputStruct.contrastDomainRatios;

if isa(inputProblemDef, 'domainsClass')
    problemDef.domainRatio = inputStruct.domainRatioValues;
else
    problemDef.domainRatio = ones(1,0);
end

if isa(inputProblemDef, 'domainsClass') && isa(inputProblemDef.domainContrasts, 'domainContrastsClass')
    problemDef.numberOfDomainContrasts = inputStruct.numberOfDomainContrasts;
else
    problemDef.numberOfDomainContrasts = 0;
end    

% Initialise the lists of fitting parameters    
problemDef.fitpars = [];
problemDef.otherpars = [];
problemDef.fitconstr = [];
problemDef.otherconstr = [];


%% Now deal with the controls class
controls.procedure = inputControls.procedure;
controls.parallel = inputControls.parallel;
controls.resamPars = inputControls.resamPars;
controls.calcSldDuringFit = inputControls.calcSldDuringFit;
controls.display = inputControls.display;
controls.tolX = inputControls.tolX;
controls.tolFun = inputControls.tolFun;
controls.maxFunEvals = inputControls.maxFunEvals;
controls.maxIter = inputControls.maxIter;
controls.updateFreq = inputControls.updateFreq;
controls.updatePlotFreq = inputControls.updatePlotFreq;
controls.populationSize = inputControls.populationSize;
controls.fWeight = inputControls.fWeight;
controls.crossoverProbability = inputControls.crossoverProbability;
controls.strategy = inputControls.strategy;
controls.targetValue = inputControls.targetValue;
controls.numGenerations = inputControls.numGenerations;
controls.Nlive = inputControls.Nlive;
controls.Nmcmc = inputControls.Nmcmc;
controls.propScale = inputControls.propScale;
controls.nsTolerance = inputControls.nsTolerance;
controls.nSamples = inputControls.nSamples;
controls.nChains = inputControls.nChains;   
controls.jumpProbability = inputControls.jumpProbability;      
controls.pUnitGamma = inputControls.pUnitGamma;
controls.boundHandling = inputControls.boundHandling;
controls.adaptPCR = inputControls.adaptPCR;

% Also need to deal with the checks...
checks.fitParams = inputStruct.fitParams;
checks.fitBacks = inputStruct.fitBackPar;
checks.fitShifts = inputStruct.fitQzshift;
checks.fitScales = inputStruct.fitScalefactor;
checks.fitNbairs = inputStruct.fitNba;
checks.fitNbsubs = inputStruct.fitNbs;
checks.fitResol = inputStruct.fitResol;
if isa(inputProblemDef, 'domainsClass')
    checks.fitDomainRatio = inputStruct.fitDomainRatio;
else
    checks.fitDomainRatio = ones(1,0);
end

controls.checks = checks;

end