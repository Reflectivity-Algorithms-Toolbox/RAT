classdef testExamples < matlab.unittest.TestCase

    properties (TestParameter)
        exampleFolder = {'standardLayers',...
            'customXY',...
            ['manual' filesep 'DSPCCustomLayers'],...
            ['manual' filesep 'DSPCStandardLayers'],...
            'customLayers',...
            '.'};
        exampleFile = {'orsoDSPCStandardLayers',...
            'DPPCCustomXYScript',...
            'DSPCMonolayerStandardLayers',...
            'DSPCMonolayerTwoContrasts',...
            'orsoDSPCCustomLayers',...
            'projectConversion',...
            'DSPCMonolayerCustomLayers',...
            'controlAlgorithms'};
        exampleName = {'Orso lipid example',...
            'Custom DPPC',...
            'DSPC monolayers',...
            'DSPC monolayers',...
            'Orso lipid example - custom layers',...
            'original_dspc_bilayer',...
            'DSPC custom layers',...
            'original_dspc_bilayer'};
        exampleModel = {modelTypes.StandardLayers.value,...
            modelTypes.CustomXY.value,...
            modelTypes.StandardLayers.value,...
            modelTypes.StandardLayers.value,...
            modelTypes.CustomLayers.value,...
            modelTypes.StandardLayers.value,...
            modelTypes.CustomLayers.value,...
            modelTypes.StandardLayers.value};
        exampleContrastCount = {3,...
            3,...
            4,...
            2,...
            3,...
            2,...
            2,...
            2};
        exampleLayerCount = {5,...
            0,...
            4,...
            4,...
            0,...
            6,...
            0,...
            6};
        exampleGeometry = {geometryOptions.AirSubstrate.value,...
            geometryOptions.SubstrateLiquid.value,...
            geometryOptions.AirSubstrate.value,...
            geometryOptions.AirSubstrate.value,...
            geometryOptions.SubstrateLiquid.value,...
            geometryOptions.SubstrateLiquid.value,...
            geometryOptions.AirSubstrate.value,...
            geometryOptions.SubstrateLiquid.value};
        exampleParameterParamCount = {15,...
            6,...
            10,...
            10,...
            8,...
            21,...
            6,...
            21};
        exampleBulkOutParamCount = {3,...
            3,...
            2,...
            2,...
            3,...
            2,...
            2,...
            2};
        exampleBackgroundsTypesCount = {3,...
            3,...
            2,...
            2,...
            3,...
            2,...
            2,...
            2};
        exampleDataCount = {4,...
            1,...
            6,...
            3,...
            4,...
            3,...
            3,...
            3};
        exampleScalefactorParamCount = {1,...
            1,...
            1,...
            1,...
            1,...
            2,...
            1,...
            2};

    end

    methods(TestClassSetup)
        function addExamplePaths(testCase)
            root = getappdata(0,'root');
            for i = 1:length(testCase.exampleFolder)
                addpath(fullfile(root, 'examples', testCase.exampleFolder{1,i}));
            end
        end

        function setWorkingFolder(testCase)
            % Makes a temporary folder the current working directory so
            % file written by the example are deleted
            import matlab.unittest.fixtures.WorkingFolderFixture;
            testCase.applyFixture(WorkingFolderFixture);
        end
    end

    methods(TestClassTeardown)
        function testCleanUp(testCase)
            root = getappdata(0,'root');
            for i = 1:length(testCase.exampleFolder)
                rmpath(fullfile(root, 'examples', testCase.exampleFolder{1,i}));
            end
        end
    end

    methods (Test,ParameterCombination="sequential")
        % Runs the different examples sequentially
        function testExample(testCase, ...
                exampleFile, ...
                exampleName, ...
                exampleModel, ...
                exampleContrastCount, ...
                exampleLayerCount, ...
                exampleGeometry, ...
                exampleParameterParamCount, ...
                exampleBulkOutParamCount, ...
                exampleBackgroundsTypesCount, ...
                exampleDataCount, ...
                exampleScalefactorParamCount)

            % verifies example exists with .m extension
            testCase.verifyEqual(exist(exampleFile,'file'), 2);

            % runs the example file
            evalc(exampleFile);

            % verifies the problem name, model type and geometry
            testCase.verifyEqual(problem.experimentName, exampleName);
            testCase.verifyEqual(problem.modelType, exampleModel);
            testCase.verifyEqual(problem.geometry, exampleGeometry);

            % verifies the count of problem properties
            testCase.verifyEqual(problem.contrasts.numberOfContrasts, exampleContrastCount);
            testCase.verifyEqual(problem.layers.layersCount, exampleLayerCount);
            testCase.verifyEqual(problem.parameters.paramCount, exampleParameterParamCount);
            testCase.verifyEqual(problem.bulkOut.paramCount, exampleBulkOutParamCount);
            testCase.verifyEqual(problem.background.backgrounds.typesCount, exampleBackgroundsTypesCount);
            testCase.verifyEqual(problem.data.dataCount, exampleDataCount);
            testCase.verifyEqual(problem.scalefactors.paramCount, exampleScalefactorParamCount);

            % Problem properties that are consistent across examples
            testCase.verifyEqual(problem.bulkIn.paramCount, 1);
            testCase.verifyEqual(problem.qzshifts.paramCount, 1);
            testCase.verifyEqual(problem.resolution.resolutions.typesCount, 1);

            % closes all the figures generated by the examples
            close all;
        end
    end
end




