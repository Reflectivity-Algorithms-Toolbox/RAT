function [outProblemDef,problem,results,bayesResults] = RATMain(problemDef,problemDefCells,problemDefLimits,controls,priors)


result = cell(6,1);
numberOfContrasts = problemDef.numberOfContrasts;
preAlloc = zeros(numberOfContrasts,1);

problem = struct('ssubs',preAlloc,...
                 'backgrounds',preAlloc,...
                 'qshifts',preAlloc,...
                 'scalefactors',preAlloc,...
                 'nbairs',preAlloc,...
                 'nbsubs',preAlloc,...
                 'resolutions',preAlloc,...
                 'calculations',struct('all_chis',preAlloc,'sum_chi',0),...
                 'allSubRough',preAlloc);

% Make empty bayes results even though we may not fill it (for output purposes)
bayesResults.res = [];
bayesResults.chain = [];
bayesResults.s2chain = [];
bayesResults.ssChain = [];
bayesResults.bestPars = [];

outProblemDef = problemDef;

%Decide what we are doing....
action = controls.proc;
switch lower(action)
    case 'calculate' %Just a single reflectivity calculation
        [problem,results] = reflectivityCalculationWrapper(problemDef,problemDefCells,problemDefLimits,controls);
        outProblemDef = problemDef;
    case 'simplex'
        if ~strcmpi(controls.display,'off')
            sendTextOutput(sprintf('\nRunning simplex\n\n'));
        end
        [outProblemDef,problem,results] = runSimplex(problemDef,problemDefCells,problemDefLimits,controls);
    case 'de'
        if ~strcmpi(controls.display,'off')
            sendTextOutput(sprintf('\nRunning Differential Evolution\n\n'));
        end
        [outProblemDef,problem,results] = runDE(problemDef,problemDefCells,problemDefLimits,controls);
    case 'ns'
        if ~strcmpi(controls.display,'off')
            sendTextOutput(sprintf('\nRunning Nested Sampler\n\n'));
        end            
        [outProblemDef,problem,results,bayesResults] = runNestedSampler(problemDef,problemDefCells,problemDefLimits,controls);   
    case 'dream'
        if ~strcmpi(controls.display,'off')
            sendTextOutput(sprintf('\nRunning DREAM\n\n'));
        end
        [outProblemDef,problem,results,bayesResults] = runDREAM(problemDef,problemDefCells,problemDefLimits,controls,priors);
end

end