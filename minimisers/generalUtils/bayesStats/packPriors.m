function fitPriors = packPriors(priors,checks)

%We need to pack the parameters into seperate vectors
%of those that are being fitted, and those that are
%held constant.
numberOfFitted = sum(checks.fitParam) + ...
                 sum(checks.fitBackgroundParam) + ...
                 sum(checks.fitScalefactor) + ...
                 sum(checks.fitQzshift) + ...
                 sum(checks.fitBulkIn) + ...
                 sum(checks.fitBulkOut) + ...
                 sum(checks.fitResolutionParam);
             
% numberOfTotal = length(problemDefStruct.params) + ...
%                 length(problemDefStruct.backgroundParams) + ...
%                 length(problemDefStruct.scalefactors) + ...
%                 length(problemDefStruct.qzshifts) + ...
%                 length(problemDefStruct.bulkIn) + ...
%                 length(problemDefStruct.bulkOut) + ...
%                 length(problemDefStruct.resolutionParams);
   
% fitParams = problemDefStruct.fitParams;%zeros(numberOfFitted,1);
% otherParams = zeros((numberOfTotal-numberOfFitted),1);
% fitLimits = zeros(numberOfFitted,2);
% otherLimits = zeros((numberOfTotal-numberOfFitted),2);
% %limits = problemDefStruct.limits;
% fitNames = cell(numberOfFitted,1);
fitCounter = 1;
% otherCounter = 1;
thesePriors = priors.param;
for n = 1:length(checks.fitParam)
    if checks.fitParam(n) == 1
        fitPriors{fitCounter} = thesePriors(n,:);
        fitCounter = fitCounter + 1;
        
%         fitParams(fitCounter) = problemDefStruct.params(n);
%         fitLimits(fitCounter,1) = limits.param(n,1);
%         fitLimits(fitCounter,2) = limits.param(n,2);        
%         fitNames{fitCounter} = problemDefCells{7}{n};
%         fitCounter = fitCounter + 1;
% 
%     else
%         otherParams(otherCounter) = problemDefStruct.params(n);
%         otherLimits(otherCounter,1) = limits.param(n,1);
%         otherLimits(otherCounter,2) = limits.param(n,2);
%         otherCounter = otherCounter + 1;
    end
end

% backs

% scales

% shifts

% nba

% nbs

% resol














end