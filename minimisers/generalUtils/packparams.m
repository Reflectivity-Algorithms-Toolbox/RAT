function [problemDef,fitNames] = packparams(problemDef,problemDefCells,limits,checks)

%Separate out the params array into fitting
%and unfitting arrays.


%problem = getappdata(0,'problem');

% controls.checks.fitParam = ones(length(problem.params),1);
% controls.checks.fitBackgroundParam = ones(length(problem.backs),1);
% controls.checks.fitScalefactor = ones(length(problem.scalefac),1);
% controls.checks.fitBulkIn = ones(length(problem.nba),1);
% controls.checks.fitBulkOut = ones(length(problem.nbs),1);
% controls.checks.fitResolutionParam = ones(length(problem.resolution),1);

% calculation.limits.params = problem.constr;
% calculation.limits.backs = problem.backs_constr;
% calculation.limits.scalefactor = problem.scale_constr;
% calculation.limits.qzshift = problem.shifts_constr;
% calculation.limits.bulkIn = problem.nbairs_constr;
% calculation.limits.bulkOut = problem.nbsubs_constr;
% calculation.limits.res = problem.resolution_constr;



%We need to pack the parameters into seperate vectors
%of those that are being fitted, and those that are
%held constant.
numberOfFitted = sum(checks.fitParam) + ...
                 sum(checks.fitBackgroundParam) + ...
                 sum(checks.fitScalefactor) + ...
                 sum(checks.fitQzshift) + ...
                 sum(checks.fitBulkIn) + ...
                 sum(checks.fitBulkOut) + ...
                 sum(checks.fitResolutionParam) + ...
                 sum(checks.fitDomainRatio);
             
numberOfTotal = length(problemDef.params) + ...
                length(problemDef.backs) + ...
                length(problemDef.sf) + ...
                length(problemDef.shifts) + ...
                length(problemDef.nba) + ...
                length(problemDef.nbs) + ...
                length(problemDef.res) + ...
                length(problemDef.domainRatio);
   
fitpars = problemDef.fitpars;%zeros(numberOfFitted,1);
otherpars = zeros((numberOfTotal-numberOfFitted),1);
fitconstr = zeros(numberOfFitted,2);
otherconstr = zeros((numberOfTotal-numberOfFitted),2);
%limits = problemDef.limits;
fitNames = cell(numberOfFitted,1);
for i = 1:numberOfFitted
    fitNames{i} = '';
end

fitCounter = 1;
otherCounter = 1;
for n = 1:length(checks.fitParam)
    if checks.fitParam(n) == 1
        fitpars(fitCounter) = problemDef.params(n);
        fitconstr(fitCounter,1) = limits.params(n,1);
        fitconstr(fitCounter,2) = limits.params(n,2);        
        fitNames{fitCounter} = problemDefCells{7}{n};
        fitCounter = fitCounter + 1;

    else
        otherpars(otherCounter) = problemDef.params(n);
        otherconstr(otherCounter,1) = limits.params(n,1);
        otherconstr(otherCounter,2) = limits.params(n,2);
        otherCounter = otherCounter + 1;
    end
end

%Also do the same for backgrounds...
for n = 1:length(checks.fitBackgroundParam)
    if checks.fitBackgroundParam(n) == 1
        fitpars(fitCounter) = problemDef.backs(n);
        fitconstr(fitCounter,1) = limits.backs(n,1);
        fitconstr(fitCounter,2) = limits.backs(n,2);
        fitNames{fitCounter} = problemDefCells{8}{n};
        fitCounter = fitCounter + 1;
    else
        otherpars(otherCounter) = problemDef.backs(n);
        otherconstr(otherCounter,1) = limits.backs(n,1);
        otherconstr(otherCounter,2) = limits.backs(n,2);
        otherCounter = otherCounter + 1;
    end
end

%..also for the scale factors
for n = 1:length(checks.fitScalefactor)
    if checks.fitScalefactor(n) == 1
        fitpars(fitCounter) = problemDef.sf(n);
        fitconstr(fitCounter,1) = limits.scalefactor(n,1);
        fitconstr(fitCounter,2) = limits.scalefactor(n,2);
        fitNames{fitCounter} = problemDefCells{9}{n};
        fitCounter = fitCounter + 1;
    else
        otherpars(otherCounter) = problemDef.sf(n);
        otherconstr(otherCounter,1) = limits.scalefactor(n,1);
        otherconstr(otherCounter,2) = limits.scalefactor(n,2);
        otherCounter = otherCounter + 1;
    end
end    

%Need qshifts
for n = 1:length(checks.fitQzshift)
    if checks.fitQzshift(n) == 1
        fitpars(fitCounter) = problemDef.shifts(n);
        fitconstr(fitCounter,1) = limits.qzshift(n,1);
        fitconstr(fitCounter,2) = limits.qzshift(n,2);
        fitNames{fitCounter} = problemDefCells{10}{n};
        fitCounter = fitCounter + 1;
    else
        otherpars(otherCounter) = problemDef.shifts(n);
        otherconstr(otherCounter,1) = limits.qzshift(n,1);
        otherconstr(otherCounter,2) = limits.qzshift(n,2);
        otherCounter = otherCounter + 1;
    end
end 

%Nbairs
for n = 1:length(checks.fitBulkIn)
    if checks.fitBulkIn(n) == 1
        fitpars(fitCounter) = problemDef.nba(n);
        fitconstr(fitCounter,1) = limits.bulkIn(n,1);
        fitconstr(fitCounter,2) = limits.bulkIn(n,2);
        fitNames{fitCounter} = problemDefCells{11}{n};
        fitCounter = fitCounter + 1;
    else
        otherpars(otherCounter) = problemDef.nba(n);
        otherconstr(otherCounter,1) = limits.bulkIn(n,1);
        otherconstr(otherCounter,2) = limits.bulkIn(n,2);
        otherCounter = otherCounter + 1;
    end
end 

%NBsubs
for n = 1:length(checks.fitBulkOut)
    if checks.fitBulkOut(n) == 1
        fitpars(fitCounter) = problemDef.nbs(n);
        fitconstr(fitCounter,1) = limits.bulkOut(n,1);
        fitconstr(fitCounter,2) = limits.bulkOut(n,2);
        fitNames{fitCounter} = problemDefCells{12}{n};
        fitCounter = fitCounter + 1;
    else
        otherpars(otherCounter) = problemDef.nbs(n);
        otherconstr(otherCounter,1) = limits.bulkOut(n,1);
        otherconstr(otherCounter,2) = limits.bulkOut(n,2);
        otherCounter = otherCounter + 1;
    end
end 

%Resolution.....
for n = 1:length(checks.fitResolutionParam)
    if checks.fitResolutionParam(n) == 1
        fitpars(fitCounter) = problemDef.res(n);
        fitconstr(fitCounter,1) = limits.res(n,1);
        fitconstr(fitCounter,2) = limits.res(n,2);
        fitNames{fitCounter} = problemDefCells{13}{n};
        fitCounter = fitCounter + 1;
    else
        otherpars(otherCounter) = problemDef.res(n);
        otherconstr(otherCounter,1) = limits.res(n,1);
        otherconstr(otherCounter,2) = limits.res(n,2);
        otherCounter = otherCounter + 1;
    end
end 

% Domain Ratio
for n = 1:length(checks.fitDomainRatio)
    if checks.fitDomainRatio(n) == 1
        fitpars(fitCounter) = problemDef.domainRatio(n);
        fitconstr(fitCounter,1) = limits.domainRatio(n,1);
        fitconstr(fitCounter,2) = limits.domainRatio(n,2);
        fitNames{fitCounter} = problemDefCells{20}{n};
        fitCounter = fitCounter + 1;
    else
        otherpars(otherCounter) = problemDef.domainRatio(n);
        otherconstr(otherCounter,1) = limits.domainRatio(n,1);
        otherconstr(otherCounter,2) = limits.domainRatio(n,2);
        otherCounter = otherCounter + 1;
    end
end 

problemDef.fitpars = fitpars;
problemDef.otherpars = otherpars;
problemDef.fitconstr = fitconstr;
problemDef.otherconstr = otherconstr;

end