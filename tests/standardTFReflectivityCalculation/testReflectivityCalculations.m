classdef testReflectivityCalculations < matlab.unittest.TestCase
%%
% testReflectivityCalculations Class based unit tests for RAT API, the
% reflectivity calculation and pre- and post-processing routines.
%
% In this class, we test:
% RAT, RATMain, singleCalculation,
% reflectivityCalculationWrapper,
% reflectivityCalculation, standardTFReflectivityCalculation,
% standardTFStandardLayersReflectivityCalculation,
% standardTFCustomLayersReflectivityCalculation,
% standardTFCustomXYReflectivityCalculation, 
% standardTFStandardLayersSingle, standardTF_custlay_single,
% standardTF_custXY_single, standardTFStandardLayersParallelContrasts,
% standardTF_custlay_paraContrasts, standardTF_custXY_paraContrasts,
% standardTFStandardLayersParallelPoints, standardTF_custlay_paraPoints,
% standardTF_custXY_paraPoints,
% RatParseClasstoStructs_new, parseCells, extractProblemParams
% parseResultToStruct, RATParseOutToProjectClass
%
% We are using the test cases for a standard TF reflectivity calculation
% to test the routines. We consider standard layers, custom layers and
% custom XY examples. For the reflectivity calculation itself, we consider
% the serial and parallel versions (both points and contrasts), using both
% the MATLAB and compiled (MEX) versions.
%
% Paul Sharp 23/01/23
%
%% Declare properties and parameters

    properties (ClassSetupParameter)
        inputsFile = {'standardLayersInputs.mat', 'customLayersInputs.mat', 'customXYInputs.mat'};     % Input test data
        outputsFile = {'standardLayersOutputs.mat', 'customLayersOutputs.mat', 'customXYOutputs.mat'}; % Output test data
        TFFile = {'standardLayersTFParams.mat', 'customLayersTFParams.mat',  'customXYTFParams.mat'};  % TF Params test data
    end

    properties (TestParameter)    
        whichParallel = {'single', 'points', 'contrasts'} % How the reflectivity calculation is parallelised
        useCompiled = {false, true}                       % Choose either the MATLAB or MEX version
    end

    properties
        inputs;                  % Test input parameters read from file
        outputs;                 % Test Output parameters read from file
        TFParams;                % Test TF Parameters read from file
        problemDefInput;         % Full set of input parameters
        problemDef;              % Input Parameters for the test problem
        problemDefCells;         % Input cell arays for the test problem
        problemDefLimits;        % Input limits for the test problem
        priors;                  % Input priors for the test problem
        controlsInput;           % Instument controls class for the input problem
        controls;                % Instument controls struct for the input problem
        expectedProblem;         % Expected output value of the problem object
        expectedProblemOut;      % Expected output value of the output problem object
        expectedProblemOutStruct % Expected output value of the output problem struct
        expectedResult;          % Expected output value of the results object
        expectedResultOut;       % Expected output value of the output results object
        expectedResultOutStruct; % Expected output value of the output results struct
        expectedBayesResults;    % Expected output value of the results object
        TFReflectivity;
        TFSimulation;
        TFShiftedData;
        TFLayerSLDs;
        TFSLDProfiles;
        TFAllLayers;
        TFOutSsubs;
        TFBackgs;
        TFQshifts;
        TFSfs;
        TFNbas;
        TFNbss;
        TFResols;
        TFChis;
        TFAllRoughs;
        tolerance = 1.0e-12;     % Relative tolerance for equality of floats
        abs_tolerance = 1.0e-5;  % Absolute tolerance for equality of floats
    end

%% Read in test data

    methods (TestClassSetup, ParameterCombination="sequential")

        function loadTestDataInputs(testCase, inputsFile)
            testCase.inputs = load(inputsFile);

            testCase.problemDefInput = testCase.inputs.inputs.problemDefInput;
            testCase.problemDef = testCase.inputs.inputs.problemDef;
            testCase.problemDefCells = testCase.inputs.inputs.problemDef_cells;
            testCase.problemDefLimits = testCase.inputs.inputs.problemDef_limits;
            testCase.priors = testCase.inputs.inputs.priors;
            testCase.controlsInput = testCase.inputs.inputs.controlsInput;
            testCase.controls = testCase.inputs.inputs.controls;
        end
        
        function loadTestDataOutputs(testCase, outputsFile)
            testCase.outputs = load(outputsFile);

            testCase.expectedProblem = testCase.outputs.outputs.problem;
            testCase.expectedProblemOut = testCase.outputs.outputs.problemOut;
            testCase.expectedProblemOutStruct = testCase.outputs.outputs.problemOutStruct;
            testCase.expectedResult = testCase.outputs.outputs.result;
            testCase.expectedResultOut = testCase.outputs.outputs.resultOut;
            testCase.expectedResultOutStruct = testCase.outputs.outputs.resultOutStruct;
            testCase.expectedBayesResults = testCase.outputs.outputs.bayesResults;
        end

        function loadTFParams(testCase, TFFile)
            testCase.TFParams = load(TFFile);

            testCase.TFReflectivity = testCase.TFParams.TFParams.reflectivity;
            testCase.TFSimulation = testCase.TFParams.TFParams.simulation;
            testCase.TFShiftedData = testCase.TFParams.TFParams.shiftedData;
            testCase.TFLayerSLDs = testCase.TFParams.TFParams.layerSlds;
            testCase.TFSLDProfiles = testCase.TFParams.TFParams.sldProfiles;
            testCase.TFAllLayers = testCase.TFParams.TFParams.allLayers;

            testCase.TFOutSsubs = testCase.TFParams.TFParams.outSsubs;
            testCase.TFBackgs = testCase.TFParams.TFParams.backgs;
            testCase.TFQshifts = testCase.TFParams.TFParams.qshifts;
            testCase.TFSfs = testCase.TFParams.TFParams.sfs;
            testCase.TFNbas = testCase.TFParams.TFParams.nbas;
            testCase.TFNbss = testCase.TFParams.TFParams.nbss;
            testCase.TFResols = testCase.TFParams.TFParams.resols;
            testCase.TFChis = testCase.TFParams.TFParams.chis;
            testCase.TFAllRoughs = testCase.TFParams.TFParams.allRoughs;
        end

        function setCurrentFolder(testCase)
            % Set the current folder to be the directory recorded in the
            % test data
            import matlab.unittest.fixtures.CurrentFolderFixture

            testDirectory = testCase.problemDefCells{14}{1}{3};

            % Check if a directory has been recorded, and apply if so
            if strlength(testDirectory) > 0
                testCase.applyFixture(CurrentFolderFixture(testDirectory));
            end
        end
        
    end

%%
    methods (Test, ParameterCombination="exhaustive")
%% Test High Level RAT Routines

        function testRAT(testCase)
            [problem, result] = RAT(testCase.problemDefInput,testCase.controlsInput);

            testCase.verifyEqual(problem, testCase.expectedProblemOut, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(result, testCase.expectedResultOut, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

        function testRATMain(testCase)
            % Test the routine that determines the calculation RAT will
            % perform
            % Note that we test only a single reflectivity calculation at
            % present

            [outProblemDef, problem, result, bayesResults] = RATMain(testCase.problemDef,testCase.problemDefCells,testCase.problemDefLimits,testCase.controls,testCase.priors);

            testCase.verifyEqual(outProblemDef, testCase.expectedProblemOutStruct, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(problem, testCase.expectedProblem, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(result, testCase.expectedResult, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(bayesResults, testCase.expectedBayesResults, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

        function testSingleCalculation(testCase)
            [problem, result] = singleCalculation(testCase.problemDef,testCase.problemDefCells,testCase.problemDefLimits,testCase.controls);

            testCase.verifyEqual(problem, testCase.expectedProblem, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(result, testCase.expectedResult, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

        function testReflectivityCalculationWrapper(testCase)
            % Test the routine that chooses how to perform the
            % reflectivity calculation
            % Note that the routine is always set to choose the "mex"
            % version of the reflectivity calculation
            [problem, result] = reflectivityCalculationWrapper(testCase.problemDef,testCase.problemDefCells,testCase.problemDefLimits,testCase.controls);

            testCase.verifyEqual(problem, testCase.expectedProblem, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(result, testCase.expectedResult, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

%% Test Reflectivity Calculation Routines

        function testReflectivityCalculation(testCase, whichParallel, useCompiled)
            % Test the reflectivity calculation.
            % We will test the serial and parallel (over both points and
            % contrasts) versions of the calculation, using both the MATLAB
            % and comiled (MEX) versions of each.
            
            [problem, result] = reflectivityCalculationTestingWrapper(testCase.problemDef, testCase.problemDefCells, testCase.problemDefLimits, testCase.controls, useCompiled, whichParallel);

            testCase.verifyEqual(problem, testCase.expectedProblem, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(result, testCase.expectedResult, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

        function testStandardTFReflectivityCalculation(testCase)
            [problem, reflectivity, simulation, shiftedData, layerSLDs, SLDProfiles, allLayers] = standardTFReflectivityCalculation(testCase.problemDef, testCase.problemDefCells, testCase.problemDefLimits, testCase.controls);

            testCase.verifyEqual(problem, testCase.expectedProblem, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(reflectivity, testCase.TFReflectivity, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(simulation, testCase.TFSimulation, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(shiftedData, testCase.TFShiftedData, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(layerSLDs, testCase.TFLayerSLDs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(SLDProfiles, testCase.TFSLDProfiles, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(allLayers, testCase.TFAllLayers, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

        function testStandardTFLayersReflectivityCalculation(testCase, TFFile)
            % Choose the appropriate routine for each test case
            switch TFFile
                case 'standardLayersTFParams.mat'
                    [problem, reflectivity, simulation, shiftedData, layerSLDs, SLDProfiles, allLayers] = standardTFStandardLayersReflectivityCalculation(testCase.problemDef, testCase.problemDefCells, testCase.problemDefLimits, testCase.controls);
                case 'customLayersTFParams.mat'
                    [problem, reflectivity, simulation, shiftedData, layerSLDs, SLDProfiles, allLayers] = standardTFCustomLayersReflectivityCalculation(testCase.problemDef, testCase.problemDefCells, testCase.problemDefLimits, testCase.controls);
                case 'customXYTFParams.mat'
                    [problem, reflectivity, simulation, shiftedData, layerSLDs, SLDProfiles, allLayers] = standardTFCustomXYReflectivityCalculation(testCase.problemDef, testCase.problemDefCells, testCase.problemDefLimits, testCase.controls);
            end

            testCase.verifyEqual(problem, testCase.expectedProblem, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(reflectivity, testCase.TFReflectivity, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(simulation, testCase.TFSimulation, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(shiftedData, testCase.TFShiftedData, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(layerSLDs, testCase.TFLayerSLDs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(SLDProfiles, testCase.TFSLDProfiles, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(allLayers, testCase.TFAllLayers, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

        function testStandardTFLayersSerialReflectivityCalculation(testCase, TFFile)
            % Choose the appropriate routine for each test case
            switch TFFile
                case 'standardLayersTFParams.mat'
                    [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = standardTFStandardLayersSingle(testCase.problemDef,testCase.problemDefCells,...
                    testCase.problemDefLimits,testCase.controls);
                case 'customLayersTFParams.mat'
                    [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = standardTF_custlay_single(testCase.problemDef,testCase.problemDefCells,...
                    testCase.problemDefLimits,testCase.controls);
                case 'customXYTFParams.mat'
                    [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = standardTF_custXY_single(testCase.problemDef,testCase.problemDefCells,...
                    testCase.problemDefLimits,testCase.controls);
            end

            testCase.verifyEqual(outSsubs, testCase.TFOutSsubs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(backgs, testCase.TFBackgs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(qshifts, testCase.TFQshifts, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(sfs, testCase.TFSfs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(nbas, testCase.TFNbas, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(nbss, testCase.TFNbss, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(resols, testCase.TFResols, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(chis, testCase.TFChis, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(reflectivity, testCase.TFReflectivity, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(simulation, testCase.TFSimulation, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(shiftedData, testCase.TFShiftedData, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(layerSLDs, testCase.TFLayerSLDs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(SLDProfiles, testCase.TFSLDProfiles, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(allLayers, testCase.TFAllLayers, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(allRoughs, testCase.TFAllRoughs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

        function testStandardTFLayersParallelContrastsReflectivityCalculation(testCase, TFFile)
            % Choose the appropriate routine for each test case
            switch TFFile
                case 'standardLayersTFParams.mat'
                    [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = standardTFStandardLayersParallelContrasts(testCase.problemDef,testCase.problemDefCells,...
                    testCase.problemDefLimits,testCase.controls);
                case 'customLayersTFParams.mat'
                    [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = standardTF_custlay_paraContrasts(testCase.problemDef,testCase.problemDefCells,...
                    testCase.problemDefLimits,testCase.controls);
                case 'customXYTFParams.mat'
                    [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = standardTF_custXY_paraContrasts(testCase.problemDef,testCase.problemDefCells,...
                    testCase.problemDefLimits,testCase.controls);
            end

            testCase.verifyEqual(outSsubs, testCase.TFOutSsubs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(backgs, testCase.TFBackgs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(qshifts, testCase.TFQshifts, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(sfs, testCase.TFSfs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(nbas, testCase.TFNbas, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(nbss, testCase.TFNbss, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(resols, testCase.TFResols, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(chis, testCase.TFChis, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(reflectivity, testCase.TFReflectivity, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(simulation, testCase.TFSimulation, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(shiftedData, testCase.TFShiftedData, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(layerSLDs, testCase.TFLayerSLDs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(SLDProfiles, testCase.TFSLDProfiles, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(allLayers, testCase.TFAllLayers, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(allRoughs, testCase.TFAllRoughs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

        function testStandardTFLayersParallelPointsReflectivityCalculation(testCase, TFFile)
            % Choose the appropriate routine for each test case
            switch TFFile
                case 'standardLayersTFParams.mat'
                    [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = standardTFStandardLayersParallelPoints(testCase.problemDef,testCase.problemDefCells,...
                    testCase.problemDefLimits,testCase.controls);
                case 'customLayersTFParams.mat'
                    [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = standardTF_custlay_paraPoints(testCase.problemDef,testCase.problemDefCells,...
                    testCase.problemDefLimits,testCase.controls);
                case 'customXYTFParams.mat'
                    [outSsubs,backgs,qshifts,sfs,nbas,nbss,resols,chis,reflectivity,...
                    simulation,shiftedData,layerSLDs,SLDProfiles,allLayers,...
                    allRoughs] = standardTF_custXY_paraPoints(testCase.problemDef,testCase.problemDefCells,...
                    testCase.problemDefLimits,testCase.controls);
            end

            testCase.verifyEqual(outSsubs, testCase.TFOutSsubs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(backgs, testCase.TFBackgs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(qshifts, testCase.TFQshifts, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(sfs, testCase.TFSfs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(nbas, testCase.TFNbas, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(nbss, testCase.TFNbss, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(resols, testCase.TFResols, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(chis, testCase.TFChis, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(reflectivity, testCase.TFReflectivity, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(simulation, testCase.TFSimulation, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(shiftedData, testCase.TFShiftedData, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(layerSLDs, testCase.TFLayerSLDs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(SLDProfiles, testCase.TFSLDProfiles, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(allLayers, testCase.TFAllLayers, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(allRoughs, testCase.TFAllRoughs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

%% Test Pre- and Post-Processing Routines

        function testRatParseClasstoStructs_new(testCase)
            [problem, problem_cells, problem_limits, problem_priors, controls_struct] = parseClassToStructs(testCase.problemDefInput, testCase.controlsInput);

            testCase.verifyEqual(problem, testCase.problemDef, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(problem_cells, testCase.problemDefCells, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(problem_limits, testCase.problemDefLimits, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(problem_priors, testCase.priors, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(controls_struct, testCase.controls, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

        function testRATParseCells(testCase)
            [repeatLayers,allData,dataLimits,simLimits,contrastLayers,layersDetails,customFiles] = parseCells(testCase.problemDefCells);

            testCase.verifyEqual(repeatLayers, testCase.problemDefCells{1}, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(allData, testCase.problemDefCells{2}, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(dataLimits, testCase.problemDefCells{3}, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(simLimits, testCase.problemDefCells{4}, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(contrastLayers, testCase.problemDefCells{5}, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(layersDetails, testCase.problemDefCells{6}, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(customFiles, testCase.problemDefCells{14}, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end        

        function testExtractProblemParams(testCase)
            [numberOfContrasts, geometry, cBacks, cShifts, cScales, cNbas, cNbss,...
            cRes, backs, shifts, sf, nba, nbs, res, dataPresent, nParams, params,...
            numberOfLayers, resample, backsType, cFiles] =  extractProblemParams(testCase.problemDef);

            testCase.verifyEqual(numberOfContrasts, testCase.problemDef.numberOfContrasts, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(geometry, testCase.problemDef.geometry, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(cBacks, testCase.problemDef.contrastBacks, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(cShifts, testCase.problemDef.contrastShifts, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(cScales, testCase.problemDef.contrastScales, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(cNbas, testCase.problemDef.contrastNbas, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(cNbss, testCase.problemDef.contrastNbss, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(cRes, testCase.problemDef.contrastRes, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(backs, testCase.problemDef.backs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(shifts, testCase.problemDef.shifts, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(sf, testCase.problemDef.sf, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(nba, testCase.problemDef.nba, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(nbs, testCase.problemDef.nbs, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(res, testCase.problemDef.res, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(dataPresent, testCase.problemDef.dataPresent, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(nParams, length(testCase.problemDef.params), "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(params, testCase.problemDef.params, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(numberOfLayers, testCase.problemDef.numberOfLayers, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(resample, testCase.problemDef.resample, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(backsType, testCase.problemDef.contrastBacksType, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(cFiles, testCase.problemDef.contrastCustomFiles, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

        function testParseResultToStruct(testCase)
            resultStruct = parseResultToStruct(testCase.expectedProblem, testCase.expectedResult);
            testCase.verifyEqual(resultStruct, testCase.expectedResultOutStruct, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);

            testCase.verifyEqual(resultStruct.reflectivity, testCase.expectedResult{1}, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(resultStruct.Simulation, testCase.expectedResult{2}, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(resultStruct.shifted_data, testCase.expectedResult{3}, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(resultStruct.layerSlds, testCase.expectedResult{4}, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(resultStruct.sldProfiles, testCase.expectedResult{5}, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(resultStruct.allLayers, testCase.expectedResult{6}, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
            testCase.verifyEqual(resultStruct.calculationResults, testCase.expectedProblem.calculations, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

        function testRATParseOutToProjectClass(testCase)
            problemOut = parseOutToProjectClass(testCase.problemDefInput, testCase.expectedProblemOutStruct, testCase.expectedProblem, testCase.expectedResult);
            testCase.verifyEqual(problemOut, testCase.expectedProblemOut, "RelTol", testCase.tolerance, "AbsTol", testCase.abs_tolerance);
        end

    end
end