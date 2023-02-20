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
% Paul Sharp 16/02/23
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
        numContrasts            % Number of Contrasts defined in exampleClass
    end

%% Set up test data

    methods (TestClassSetup)

        function initialiseAllowedNames(testCase)
            % The values for each parameter in the contrast class MUST
            % correspond to parameters defined in the corresponding class
            % in this project
            % This example is a reduced version of the allowed names used
            % in the example calculation "DPPC_standard_layers.m"
            testCase.allowedNames = struct( ...
                'backsNames', ["Background D2O" "Background SMW" "Background H2O"], ...
                'bulkInNames', 'Silicon', ...
                'bulkOutNames', ["SLD D2O" "SLD SMW" "SLD H2O"], ...
                'resolsNames', 'Resolution 1', ...
                'layersNames',  ["Oxide Layer" "Water Layer" "Bil inner head" "Bil tail" "Bil outer head"], ...
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



    end

end
