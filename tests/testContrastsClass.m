classdef testContrastsClass < matlab.unittest.TestCase
%%
% testContrastsClass Class based unit tests for the contrastsClass
% used within the Project Class in RAT.
%
% In this class, we test:
%
% We use an example contrasts class from the example calculation
% "DPPC_standard_layers.m"
%
% Paul Sharp 21/02/23
%
%% Declare properties and parameters

    properties (TestParameter)
        contrastInput = {{}, ...
                         {'Named Contrast'}, ...
                         {'name', 'Few params', ...
                          'background', 'Background D2O', ...
                          'resolution', 'Resolution 1'}, ...
                         {'name', 'All params', ...
                          'background', 'Background H2O', ...
                          'data', 'Simulation', ...
                          'nba', 'Silicon', ...
                          'nbs', 'SLD H2O', ...
                          'resolution', 'Resolution 1', ...
                          'scalefactor', 'Scalefactor 1', ...
                          'resample', true}, ...
                          }
        invalidInput = {{'background', 'Invalid'}, ...
                        {'data', 'Invalid'}, ...
                        {'nba', 'Invalid'}, ...
                        {'nbs', 'Invalid'}, ...
                        {'resolution', 'Invalid'}, ...
                        {'scalefactor', 'Invalid'}, ...
                        {'model', 42}
                        }
        removeInput = {1, 'Bilayer / D2O'}
        changedFields = {{{'name', 'New contrast 1'}}, ...
                         {{'name', 'Named Contrast'}}, ...
                         {{'name', 'Few params'}, ...
                          {'background', 'Background D2O'}, ...
                          {'resolution', 'Resolution 1'}
                         }, ...
                         {{'name', 'All params'}, ...
                          {'background', 'Background H2O'}, ...
                          {'data', 'Simulation'}, ...
                          {'nba', 'Silicon'}, ...
                          {'nbs', 'SLD H2O'}, ...
                          {'resolution', 'Resolution 1'}, ...
                          {'scalefactor', 'Scalefactor 1'}, ...
                          {'resample', true}, ...
                         }, ...
                        }
    end

    properties
        allowedNames            % Full set of ALL parameter names in the project
        defaultContrasts        % Contrasts struct with default values
        exampleClass            % Example contrasts class for testing
        layerNames              % The names of the layers in the project
        numContrasts            % Number of Contrasts defined in exampleClass

        % Define the custom files from "orsoDPPC_cuastLay_script.m",
        % and "DPPC_customXY.m" 
        customNames = ["DSPC Model" "DPPC Model"]
    end

%% Set up test data

    methods (TestClassSetup)

        function initialiseAllowedNames(testCase)
            % The values for each parameter in the contrast class MUST
            % correspond to parameters defined in the corresponding class
            % in this project
            % This example is a reduced version of the allowed names used
            % in the example calculation "DPPC_standard_layers.m"
            testCase.layerNames = ["Oxide Layer" "Water Layer" "Bil inner head" "Bil tail" "Bil outer head"];

            testCase.allowedNames = struct( ...
                'backsNames', ["Background D2O" "Background SMW" "Background H2O"], ...
                'bulkInNames', 'Silicon', ...
                'bulkOutNames', ["SLD D2O" "SLD SMW" "SLD H2O"], ...
                'resolsNames', 'Resolution 1', ...
                'layersNames',  testCase.layerNames, ...
                'dataNames',  ["Simulation" "Bilayer / D2O" "Bilayer / SMW" "Bilayer / H2O"], ...
                'scalefacNames', 'Scalefactor 1', ...
                'customNames',  strings([0 1]) ...
                );
        end

    end

    methods (TestMethodSetup)

        function initialiseContrastsClass(testCase)
            % Set up an example contrasts class for testing
            % This example is used in the example calculation
            % "DPPC_standard_layers.m"
            testCase.exampleClass = contrastsClass();

            testCase.exampleClass.contrasts(1) = {struct( ...
                'name', 'Bilayer / D2O', ...
                'background', 'Background D2O', ...
                'data', 'Bilayer / D2O', ...
                'nba', 'Silicon', ...
                'nbs', 'SLD D2O', ...
                'resolution', 'Resolution 1', ...
                'scalefactor', 'Scalefactor 1', ...
                'resample', 0,...
                'model', {{'Oxide Layer', 'Water Layer', 'Bil inner head', 'Bil tail', 'Bil tail', 'Bil outer head'}} ...
                )};
           
            testCase.exampleClass.contrasts(2) = {struct( ...
                'name', 'Bilayer / SMW', ...
                'background', 'Background SMW', ...
                'data', 'Bilayer / SMW', ...
                'nba', 'Silicon', ...
                'nbs', 'SLD SMW', ...
                'resolution', 'Resolution 1', ...
                'scalefactor', 'Scalefactor 1', ...
                'resample', 0,...
                'model', {{'Oxide Layer', 'Water Layer', 'Bil inner head', 'Bil tail', 'Bil tail', 'Bil outer head'}} ...
                )};
            
            testCase.exampleClass.contrasts(3) = {struct( ...
                'name', 'Bilayer / H2O', ...
                'background', 'Background H2O', ...
                'data', 'Bilayer / H2O', ...
                'nba', 'Silicon', ...
                'nbs', 'SLD H2O', ...
                'resolution', 'Resolution 1', ...
                'scalefactor', 'Scalefactor 1', ...
                'resample', 0,...
                'model', {{'Oxide Layer', 'Water Layer', 'Bil inner head', 'Bil tail', 'Bil tail', 'Bil outer head'}} ...
                )};

            testCase.numContrasts = length(testCase.exampleClass.contrasts);

        end

        function initialiseDefaultContrastsStruct(testCase)
            % Create a contrasts struct with the default values for each
            % parameter
            testCase.defaultContrasts = struct( ...
                'name', '', ...
                'background', '', ...
                'data', '', ...
                'nba', '', ...
                'nbs', '', ...
                'resolution', '', ...
                'scalefactor', '', ...
                'resample', false,...
                'model', '' ...
                );
        end

    end

%% Test Contrasts Class Routines

    methods (Test, ParameterCombination="sequential")

        function testInitialiseContrastsClass(testCase)
            testClass = contrastsClass();

            testCase.verifyEqual(testClass.contrasts, {}, "contrastsClass does not initialise correctly");
            testCase.verifyEqual(testClass.contrastsTable, [], "contrastsClass does not initialise correctly");
        end

        function testAddContrast(testCase, contrastInput, changedFields)
            % Test adding a contrast to the contrasts class.
            % We can add a contrast with no parameters, just a
            % contrast name, or a set of name-value pairs

            % Set the expected contrasts struct
            addedContrast = testCase.defaultContrasts();
            
            for i=1:length(changedFields)
                addedContrast = setfield(addedContrast, changedFields{i}{:});
            end

            expectedContrasts = [testCase.exampleClass.contrasts, addedContrast];

            testCase.exampleClass.addContrast(testCase.allowedNames, contrastInput);
            testCase.verifyEqual(testCase.exampleClass.contrasts, expectedContrasts, "addContrast does not work correctly");
        end

        function testAddContrastInvalidOption(testCase, invalidInput)
            % Test adding a contrast to the contrasts class.
            % If values for each parameter are not valid options, we
            % should raise an error
            testCase.verifyError(@() testCase.exampleClass.addContrast(testCase.allowedNames, invalidInput), 'MATLAB:unrecognizedStringChoice');
        end

        function testAddContrastInvalidType(testCase)
            % Test adding a contrast to the contrasts class.
            % If values for the name an logical parameters are an invalid
            % type, we should raise an error
            testCase.verifyError(@() testCase.exampleClass.addContrast(testCase.allowedNames, {'name', 42}), 'MATLAB:InputParser:ArgumentFailedValidation');
            testCase.verifyError(@() testCase.exampleClass.addContrast(testCase.allowedNames, {'resample', datetime('today')}), 'MATLAB:InputParser:ArgumentFailedValidation');
        end

        function testRemoveContrast(testCase, removeInput)
            % Test removing a contrast from the contrasts class.
            % Contrasts can be specified either by name or by index, but
            % only one contrast can be removed at a time.
            remainingContrasts = testCase.exampleClass.contrasts(2:end);
            testCase.exampleClass.removeContrast(removeInput);

            testCase.verifyEqual(testCase.exampleClass.contrasts, remainingContrasts, "removeContrast does not work correctly");
        end

        function testRemoveContrastInvalid(testCase)
            % Test removing a contrast from the contrasts class.
            % If contrast names or indices are invalid, we should raise an
            % error
            testCase.verifyError(@() testCase.exampleClass.removeContrast(0), indexOutOfRange.errorID);
            testCase.verifyError(@() testCase.exampleClass.removeContrast(testCase.numContrasts+1), indexOutOfRange.errorID);

            testCase.verifyError(@() testCase.exampleClass.removeContrast('Unrecognised Name'), nameNotRecognised.errorID);
        end

        function testSetContrastModelStandard(testCase)
            % Test setting a model for a contrast from the contrasts class
            % when the model type is "standard layers"
            testModel = {'Oxide Layer', 'Water Layer'};

            testCase.exampleClass.setContrastModel(1, 'standard layers', testCase.layerNames, testModel);
            testCase.verifyEqual(testCase.exampleClass.contrasts{1}.model, testModel, "setContrastModel does not work correctly");
        end

        function testSetContrastModelCustom(testCase)
            % Test setting a model for a contrast from the contrasts class
            % for a "custom" model type
            testModel = {'DPPC Model'};

            testCase.exampleClass.setContrastModel(2, 'custom XY', testCase.customNames, testModel);
            testCase.verifyEqual(testCase.exampleClass.contrasts{2}.model, testModel, "setContrastModel does not work correctly");
        end

        function testSetContrastModelInvalid(testCase)
            % Test setting a model for a contrast from the contrasts class
            % If the input is invalid we should raise an error
            testModel = {'Oxide Layer', 'Carbide Layer'};

            testCase.verifyError(@() testCase.exampleClass.setContrastModel(1, 'standard layers', testCase.layerNames, testModel), nameNotRecognised.errorID);
            testCase.verifyError(@() testCase.exampleClass.setContrastModel(1, 'custom layers', testCase.layerNames, testModel), invalidValue.errorID); % More than one input not allowed

            testCase.verifyError(@() testCase.exampleClass.setContrastModel(1, 'custom layers', testCase.layerNames, {'Carbide Layer'}), nameNotRecognised.errorID);
        end

        function testSetContrast(testCase)
            setContrastInput = {
                'name', 'New Contrast', ...
                'background', 'Background SMW', ...
                'data', 'Simulation', ...
                'nbs', 'SLD SMW', ...
                'resample', true, ...
                'model', 'Water Layer'};

            testContrast = struct( ...
                'name', 'New Contrast', ...
                'background', 'Background SMW', ...
                'data', 'Simulation', ...
                'nba', 'Silicon', ...
                'nbs', 'SLD SMW', ...
                'resolution', 'Resolution 1', ...
                'scalefactor', 'Scalefactor 1', ...
                'resample', true,...
                'model', {{'Water Layer'}} ...
                );

            testCase.exampleClass.setContrast(1, testCase.allowedNames, setContrastInput);
            testCase.verifyEqual(testCase.exampleClass.contrasts{1}, testContrast, "setContrast does not work correctly");
        end

        function testGetAllContrastNames(testCase)
            testCase.verifyEqual(testCase.exampleClass.getAllContrastNames, {'Bilayer / D2O', 'Bilayer / SMW', 'Bilayer / H2O'}, "getAllContrastNames does not work correctly");
        end

        function testGetAllContrastNamesInvalid(testCase)
            % If we try to get contrast names when no contrasts are
            % defined we should raise an error
            emptyContrasts = contrastsClass();
            testCase.verifyError(@() emptyContrasts.getAllContrastNames, invalidValue.errorID);
        end

        function testUpdateContrastName(testCase)
            % Test the rouitine that updates the data entry of the
            % contrast as data names are changed.

            nameChanged = struct('oldName', 'Bilayer / H2O', 'newName', 'Test Data Name');
            testCase.exampleClass.updateContrastName(nameChanged);

            % Get the updated data names
            dataNames = cell(1, testCase.numContrasts);
            for i=1:testCase.numContrasts
                dataNames{i} = testCase.exampleClass.contrasts{i}.data;
            end

            testCase.verifyEqual(dataNames, {'Bilayer / D2O', 'Bilayer / SMW', 'Test Data Name'}, "updateContrastNames does not work correctly");
        end

        function testUpdateContrastNameNotFound(testCase)
            % Test the rouitine that updates the data entry of the
            % contrast as data names are changed. If the old name is not
            % found, nothing should happen.

            % Get the original data names
            oldDataNames = cell(1, testCase.numContrasts);
            for i=1:testCase.numContrasts
                oldDataNames{i} = testCase.exampleClass.contrasts{i}.data;
            end

            nameChanged = struct('oldName', 'Unused Data Name', 'newName', 'Test Data Name');
            testCase.exampleClass.updateContrastName(nameChanged);

            % Get the updated data names
            dataNames = cell(1, testCase.numContrasts);
            for i=1:testCase.numContrasts
                dataNames{i} = testCase.exampleClass.contrasts{i}.data;
            end

            testCase.verifyEqual(dataNames, oldDataNames, "updateContrastNames does not work correctly");
        end


    end

end
