function ARGS = makeCompileArgsFull()

% Define the arguments for compiling reflectivityCalculation
% using codegen.

%% Define argument types for entry-point 'reflectivityCalculation'.
maxArraySize = 10000;

ARGS = cell(1,1);
ARGS{1} = cell(5,1);
ARGS_1_1 = struct;
ARGS_1_1.contrastBacks = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_1.contrastBacksType = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_1.TF = coder.typeof('X',[1 maxArraySize],[0 1]);
ARGS_1_1.resample = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_1.dataPresent = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_1.oilChiDataPresent = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_1.numberOfContrasts = coder.typeof(0);
ARGS_1_1.geometry = coder.typeof('X',[1 maxArraySize],[0 1]);
ARGS_1_1.useImaginary = coder.typeof(true,[1 1],[0 0]);
ARGS_1_1.contrastShifts = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_1.contrastScales = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_1.contrastNbas = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_1.contrastNbss = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_1.contrastRes = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_1.backs = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_1.shifts = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_1.sf = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_1.nba = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_1.nbs = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_1.res = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_1.params = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_1.numberOfLayers = coder.typeof(0);
ARGS_1_1.modelType = coder.typeof('X',[1 maxArraySize],[0 1]);
ARGS_1_1.contrastCustomFiles = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_1.contrastDomainRatios = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_1.domainRatio = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_1.numberOfDomainContrasts = coder.typeof(0);
ARGS_1_1.fitpars = coder.typeof(0,[maxArraySize maxArraySize],[1 1]);
ARGS_1_1.otherpars = coder.typeof(0,[maxArraySize maxArraySize],[1 1]);
ARGS_1_1.fitconstr = coder.typeof(0,[maxArraySize maxArraySize],[1 1]);
ARGS_1_1.otherconstr = coder.typeof(0,[maxArraySize maxArraySize],[1 1]);
ARGS{1}{1} = coder.typeof(ARGS_1_1);
ARGS_1_2 = cell([1 20]);
ARG = coder.typeof(0,[1 2]);
ARGS_1_2{1} = coder.typeof({ARG}, [1 maxArraySize],[0 1]);
ARG = coder.typeof(0,[maxArraySize  5],[1 1]);
ARGS_1_2{2} = coder.typeof({ARG}, [1 maxArraySize],[0 1]);
ARG = coder.typeof(0,[1 2]);
ARGS_1_2{3} = coder.typeof({ARG}, [1 maxArraySize],[0 1]);
ARG = coder.typeof(0,[1 2],[1 1]);
ARGS_1_2{4} = coder.typeof({ARG}, [1 maxArraySize],[0 1]);
ARG = coder.typeof(0,[1 maxArraySize],[1 1]);
ARGS_1_2{5} = coder.typeof({ARG}, [1 maxArraySize],[0 1]);
ARG = coder.typeof(0,[1 10],[1 1]);
ARGS_1_2{6} = coder.typeof({ARG}, [maxArraySize  1],[1 0]);
ARG = coder.typeof('X',[1 maxArraySize],[1 1]);
ARGS_1_2{7} = coder.typeof({ARG}, [1 maxArraySize],[0 1]);
ARG = coder.typeof('X',[1 maxArraySize],[0 1]);
ARGS_1_2{8} = coder.typeof({ARG}, [1 maxArraySize],[0 1]);
ARG = coder.typeof('X',[1 maxArraySize],[0 1]);
ARGS_1_2{9} = coder.typeof({ARG}, [1 maxArraySize],[0 1]);
ARG = coder.typeof('X',[1 maxArraySize],[0 1]);
ARGS_1_2{10} = coder.typeof({ARG}, [1 maxArraySize],[0 1]);
ARG = coder.typeof('X',[1 maxArraySize],[0 1]);
ARGS_1_2{11} = coder.typeof({ARG}, [1 maxArraySize],[0 1]);
ARG = coder.typeof('X',[1 maxArraySize],[0 1]);
ARGS_1_2{12} = coder.typeof({ARG}, [1 maxArraySize],[0 1]);
ARG = coder.typeof('X',[1 maxArraySize],[0 1]);
ARGS_1_2{13} = coder.typeof({ARG}, [1 maxArraySize],[0 1]);
ARG = coder.typeof('X',[1 maxArraySize],[0 1]);
ARGS_1_2{14} = coder.typeof({ARG}, [1 maxArraySize], [0 1]);
ARG = coder.typeof('X',[1 maxArraySize],[1 1]);
ARGS_1_2{15} = coder.typeof({ARG}, [1 maxArraySize],[0 1]);
ARG = coder.typeof('X',[1 maxArraySize],[1 1]);
ARGS_1_2{16} = coder.typeof({ARG}, [1 maxArraySize],[0 1]);
ARG = coder.typeof(0,[maxArraySize  5],[1 1]);
ARGS_1_2{17} = coder.typeof({ARG}, [1 maxArraySize],[0 1]);
ARG = coder.typeof(0,[1 2]);
ARGS_1_2{18} = coder.typeof({ARG}, [1 maxArraySize],[0 1]);
ARG = coder.typeof(0,[1 maxArraySize],[1 1]);
ARGS_1_2{19} = coder.typeof({ARG}, [1 maxArraySize],[0 1]);
ARG = coder.typeof('X',[1 maxArraySize],[0 1]);
ARGS_1_2{20} = coder.typeof({ARG}, [1 maxArraySize],[0 1]);
ARGS{1}{2} = coder.typeof(ARGS_1_2,[1 20]);
ARGS{1}{2} = ARGS{1}{2}.makeHeterogeneous();
ARGS_1_3 = struct;
ARGS_1_3.params = coder.typeof(0,[maxArraySize  2],[1 0]);
ARGS_1_3.backs = coder.typeof(0,[maxArraySize  2],[1 0]);
ARGS_1_3.scales = coder.typeof(0,[maxArraySize  2],[1 0]);
ARGS_1_3.shifts = coder.typeof(0,[maxArraySize  2],[1 0]);
ARGS_1_3.nba = coder.typeof(0,[maxArraySize  2],[1 0]);
ARGS_1_3.nbs = coder.typeof(0,[maxArraySize  2],[1 0]);
ARGS_1_3.res = coder.typeof(0,[maxArraySize  2],[1 0]);
ARGS_1_3.domainRatio = coder.typeof(0,[maxArraySize  2],[1 0]);
ARGS{1}{3} = coder.typeof(ARGS_1_3);
ARGS_1_4 = struct;
ARGS_1_4.para = coder.typeof('X',[1 maxArraySize],[0 1]);
ARGS_1_4.proc = coder.typeof('X',[1 maxArraySize],[0 1]);
ARGS_1_4.display = coder.typeof('X',[1 maxArraySize],[0 1]);
ARGS_1_4.tolX = coder.typeof(0);
ARGS_1_4.tolFun = coder.typeof(0);
ARGS_1_4.maxFunEvals = coder.typeof(0);
ARGS_1_4.maxIter = coder.typeof(0);
ARGS_1_4.populationSize = coder.typeof(0);
ARGS_1_4.fWeight = coder.typeof(0);
ARGS_1_4.F_CR = coder.typeof(0);
ARGS_1_4.VTR = coder.typeof(0);
ARGS_1_4.numGen = coder.typeof(0);
ARGS_1_4.strategy = coder.typeof(0);
ARGS_1_4.Nlive = coder.typeof(0);
ARGS_1_4.nmcmc = coder.typeof(0);
ARGS_1_4.propScale = coder.typeof(0);
ARGS_1_4.nsTolerance = coder.typeof(0);
ARGS_1_4.calcSld = coder.typeof(0);
% ARGS_1_4.repeats = coder.typeof(0);
% ARGS_1_4.nsimu = coder.typeof(0);
% ARGS_1_4.burnin = coder.typeof(0);
ARGS_1_4.resamPars = coder.typeof(0,[1 2]);
ARGS_1_4.updateFreq = coder.typeof(0,[1 1]);
ARGS_1_4.updatePlotFreq = coder.typeof(0,[1 1]);
ARGS_1_4.nSamples = coder.typeof(0,[1 1]);
ARGS_1_4.nChains = coder.typeof(0,[1 1]);
ARGS_1_4.lambda = coder.typeof(0,[1 1]);
ARGS_1_4.pUnitGamma = coder.typeof(0,[1 1]);
ARGS_1_4.boundHandling = coder.typeof('X',[1 8],[0 1]);
ARGS_1_4_checks = struct;
ARGS_1_4_checks.params_fitYesNo = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_4_checks.backs_fitYesNo = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_4_checks.shifts_fitYesNo = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_4_checks.scales_fitYesNo = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_4_checks.nbairs_fitYesNo = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_4_checks.nbsubs_fitYesNo = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_4_checks.resol_fitYesNo = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_4_checks.domainRatio_fitYesNo = coder.typeof(0,[1 maxArraySize],[0 1]);
ARGS_1_4.checks = coder.typeof(ARGS_1_4_checks);
ARGS{1}{4} = coder.typeof(ARGS_1_4);
ARGS_1_5 = struct;
ARG_20 = cell([1 4]);
ARG_20{1} = coder.typeof('X',[1 Inf],[0 1]);
ARG_20{2} = coder.typeof('X',[1 Inf],[0 1]);
ARG_20{3} = coder.typeof(0);
ARG_20{4} = coder.typeof(0);
ARG_20 = coder.typeof(ARG_20,[1 4]);
ARG_20 = ARG_20.makeHeterogeneous();
ARGS_1_5.paramPriors = coder.typeof({ARG_20}, [Inf  1],[1 0]);
ARG_21 = cell([1 4]);
ARG_21{1} = coder.typeof('X',[1 Inf],[0 1]);
ARG_21{2} = coder.typeof('X',[1 Inf],[0 1]);
ARG_21{3} = coder.typeof(0);
ARG_21{4} = coder.typeof(0);
ARG_21 = coder.typeof(ARG_21,[1 4]);
ARG_21 = ARG_21.makeHeterogeneous();
ARGS_1_5.backsPriors = coder.typeof({ARG_21}, [Inf  1],[1 0]);
ARG_22 = cell([1 4]);
ARG_22{1} = coder.typeof('X',[1 Inf],[0 1]);
ARG_22{2} = coder.typeof('X',[1 Inf],[0 1]);
ARG_22{3} = coder.typeof(0);
ARG_22{4} = coder.typeof(0);
ARG_22 = coder.typeof(ARG_22,[1 4]);
ARG_22 = ARG_22.makeHeterogeneous();
ARGS_1_5.resolPriors = coder.typeof({ARG_22}, [1 Inf],[0 1]);
ARG_23 = cell([1 4]);
ARG_23{1} = coder.typeof('X',[1 Inf],[0 1]);
ARG_23{2} = coder.typeof('X',[1 Inf],[0 1]);
ARG_23{3} = coder.typeof(0);
ARG_23{4} = coder.typeof(0);
ARG_23 = coder.typeof(ARG_23,[1 4]);
ARG_23 = ARG_23.makeHeterogeneous();
ARGS_1_5.nbaPriors = coder.typeof({ARG_23}, [1 Inf],[0 1]);
ARG_24 = cell([1 4]);
ARG_24{1} = coder.typeof('X',[1 Inf],[0 1]);
ARG_24{2} = coder.typeof('X',[1 Inf],[0 1]);
ARG_24{3} = coder.typeof(0);
ARG_24{4} = coder.typeof(0);
ARG_24 = coder.typeof(ARG_24,[1 4]);
ARG_24 = ARG_24.makeHeterogeneous();
ARGS_1_5.nbsPriors = coder.typeof({ARG_24}, [Inf 1],[1 0]);
ARG_25 = cell([1 4]);
ARG_25{1} = coder.typeof('X',[1 Inf],[0 1]);
ARG_25{2} = coder.typeof('X',[1 Inf],[0 1]);
ARG_25{3} = coder.typeof(0);
ARG_25{4} = coder.typeof(0);
ARG_25 = coder.typeof(ARG_25,[1 4]);
ARG_25 = ARG_25.makeHeterogeneous();
ARGS_1_5.shiftPriors = coder.typeof({ARG_25}, [1 Inf],[0 1]);
ARG_26 = cell([1 4]);
ARG_26{1} = coder.typeof('X',[1 Inf],[0 1]);
ARG_26{2} = coder.typeof('X',[1 Inf],[0 1]);
ARG_26{3} = coder.typeof(0);
ARG_26{4} = coder.typeof(0);
ARG_26 = coder.typeof(ARG_26,[1 4]);
ARG_26 = ARG_26.makeHeterogeneous();
ARGS_1_5.scalesPriors = coder.typeof({ARG_26}, [1 Inf],[0 1]);
ARG_27 = coder.typeof(0);
ARGS_1_5.domainRatioPriors = coder.typeof({ARG_27}, [Inf  1],[1 0]);
ARG_28 = coder.typeof('X',[1 Inf],[0 1]);
ARGS_1_5.priorNames = coder.typeof({ARG_28}, [Inf  1],[1 0]);
ARGS_1_5.priorVals = coder.typeof(0,[Inf  3],[1 0]);
ARGS{1}{5} = coder.typeof(ARGS_1_5);

end