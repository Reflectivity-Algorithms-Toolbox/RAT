function output = runBayes(loop,nsimu,burnin,adaptint,params,problem)

% Version of runBayes that uses scaled parameters

problemDef = problem{1};
controls = problem{2};
problemDef_limits = problem{3};
problemDef_cells = problem{4};

%data = problem.data;
% Arrange the data into the format mcmcstat requires 
% We have the same number of 'batches' as contrasts.
% Also need to pass problem in order to access this
% from the subfunctions.
numberOfContrasts = problemDef.numberOfContrasts;

% Pre-allocate data to keep the compiler happy
% data = cell(1,numberOfContrasts);
% structDefineType = struct('ydata',[],'problem',problem);
% for i = 1:numberOfContrasts
%     data{i} =  structDefineType;
% end
data = cell(1,numberOfContrasts);
for i = 1:numberOfContrasts
    thisData = problemDef_cells{2}{i};
    data{i} = [thisData(:,1:2)];
    %data{i}.problem = problem;
end

% fitPars = problemDef.fitPars;
% fitConstr = problemDef.fitconstr;


% Now scale tall the parameters ('params') to a range between 0 and 1.
% To do thiswe work through the 'params' array, change the limits and
% do the scaling, and also modify they if they are set. A prior is
% considered to be unset if sigma = Inf, and in that case is left alone..
nPars = length(params);
for i = 1:nPars
    thisParam = params{i};
    thisName = thisParam{1};
    thisMin = thisParam{3};
    thisVal = thisParam{2};
    thisMax = thisParam{4};
    thisMu = thisParam{5};
    thisSig = thisParam{6};
    
    scaledVal = (thisVal - thisMin)./(thisMax-thisMin);
    
    % In sig is not inf, scale mu and sigma...
    if ~isinf(thisSig)
        newMu = (thisMu - thisMin)./(thisMax-thisMin);
        
        % Need to do some more work with sigma. Work out the
        % scaling between the old and new mu, and then scale sigma by the
        % same amount
        muScaling = abs(thisMu) / abs(newMu);
        newSig = thisSig / muScaling;
        
        thisMu = newMu;
        thisSig = newSig;
    end
    
    % Make the new cell array and put it in params...
    newParam = {thisName scaledVal 0 1 thisMu thisSig};
    params{i} = newParam;
end

% Because the parameters are now on a scale between 0 an 1, the covariance
% matrix now can just be the identity matric times a scale factor...
% qcov = [];
% for i = 1:nPars
%     thisConstr = fitConstr(i,:);
%     qcov(i) = (abs(thisConstr(2) - thisConstr(1))*0.01)^2;
% end
% qcov = diag(qcov);
qcov = eye(nPars) * 0.001;


% Define model and method options.
model.modelfun      = 'refModel_scaled';     % will return a reflectivity curve
model.ssfun         = 'reflectivity_fitModel_scaled';     % will return chi squared
model.nbatch        = numberOfContrasts;

options.method      = 'dram';          % adaptation method (mh, am, dr, dram)
options.nsimu       = nsimu;           % no of simulation%
options.qcov        = qcov;            % proposal covariance (not sure why 11....)

options.adaptint    = adaptint;        % adaptation interval
options.printint    = 200;             % how often to show info of acceptance ratios
options.verbosity   = 1;               % how much to show output
options.waitbar     = 1;               % show graphical waitbar
options.updatesigma = 0;               % update error variance
options.stats       = 1;               % save extra statistics in result
options.burnintime  = burnin;          % burn in time..
options.ntry = 2;
options.drscale = [3 2 1];
%options.adascale = 2.4 / sqrt(nPars) * 0.01;

results = [];
loop = int32(loop);
for i = 1:loop
    fprintf('Running loop %d of %d ',i,loop);

    [results,chain,s2chain,sschain] = mcmcrun_compile_scaled(model, data, problem, params, options, results);
    fprintf('\n');
end

% Need to unscale the chain..
fitConstr = problemDef.fitconstr;
for i = 1:size(chain,1)
    thesePars = chain(i,:);
    unscaled = unscalePars(thesePars,fitConstr);
    chain(i,:) = unscaled;
end

% Also unscale best for downstream
mean = results.mean;
unscaledMean = unscalePars(mean,fitConstr);
results.mean = unscaledMean;

theta = results.theta;
unscaledTheta = unscalePars(theta,fitConstr);
results.theta = unscaledTheta;

output.results = results;
output.chain = chain;
output.s2chain = s2chain;
output.sschain = sschain;
output.bestPars = results.mean;
output.data = data;

% out = mcmcpred_compile(results,chain,[],data,problem,500);
% outSld = mcmcpred_compile_sld(results,chain,[],data,problem,500);
% 
% problemDef.fitpars = output.bestPars;
% problemDef = unpackparams(problemDef,controls);
% [problem,result] = reflectivity_calculation_wrapper(problemDef,problemDef_cells,problemDef_limits,controls);
% 
% output.bestFits = result{1};
% output.shiftedData = problemDef_cells{2};
% output.predlims = out;

end


%-------------------------------------------------------------------------

function makePredPlot(out,data,problem,bestFit,scalefac)


% figure(refFig);
% clf;
% hold on;

%data = problem.data;

thisData = data;

%figure(refFig); clf; hold on
errorbar(thisData(:,1),thisData(:,2),thisData(:,3),'.');
set(gca,'YScale','log','XScale','log');
hold on
plot(bestFit(:,1),bestFit(:,2).*scalefac,'k-');

numRanges = 1;
for i = 1:numRanges
    thisMin = out(2,:);
    thisMax = out(8,:);
    
    numPoints = size(thisData,1);
    
    plot(thisData(:,1),thisMin(1:numPoints),'-')
    plot(thisData(:,1),thisMax(1:numPoints),'-')
end

end




