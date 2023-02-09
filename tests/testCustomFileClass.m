classdef testCustomFileClass < matlab.unittest.TestCase
%%
% testCustomFileClass Class based unit tests for the customFileClass
% used within the Project Class in RAT.
%
% In this class, we test:
%
% We use an example custom file class from example calculation
% "DPPC_customXY.m"
%
% Paul Sharp 09/02/23
%
%% Declare properties and parameters

    properties (TestParameter)
    end

    properties
        exampleClass;           % Example layers class for testing
        initialFileTable        % Empty table to compare to initialisation
        numRows                 % Number of rows in exampleClass.fileTable
        numCols                 % Number of columns in exampleClass.fileTable
    end

%% Set up test data

    methods (TestClassSetup)

        function initialiseFileTable(testCase)
            % Set up an empty file table 
            sz = [0 4];
            tableTypes = {'string','string','string','string'};
            tableNames = {'Name','Filename','Language','path'};

            testCase.initialFileTable = table('Size',sz,'VariableTypes',tableTypes,'VariableNames',tableNames);
        end

    end

    methods (TestMethodSetup)

        function initialiseCustomFileClass(testCase)
            % Set up an example custom file class for testing
            % This example is used in the example calculation
            % "DPPC_customXY.m"
            testCase.exampleClass = customFileClass();

            testCase.exampleClass.fileTable(1,:) = {'DPPC Model', 'DPPC_customXY.m', 'matlab', '../../'};

            testCase.numRows = height(testCase.exampleClass.fileTable);
            testCase.numCols = width(testCase.exampleClass.fileTable);
        end

    end

%% Test Layers Real SLD Class Routines

    methods (Test, ParameterCombination="sequential")

        function testInitialiseCustomFileClassEmpty(testCase)
            % On initialisation we set up a custom file class with an
            % either an empty file table, or a table with a single row
            testClass = customFileClass();

            testCase.verifySize(testClass.fileTable, [0 4], "customFileClass does not initialise correctly");
            testCase.verifyEqual(testClass.fileTable, testCase.initialFileTable, "customFileClass does not initialise correctly");
        end

        function testInitialiseCustomFileClassOneRow(testCase)
            % On initialisation we set up a custom file class with an
            % either an empty file table, or a table with a single row
            testClass = customFileClass({'DPPC Model', 'DPPC_customXY.m', 'matlab', '../../'});

            testCase.verifySize(testClass.fileTable, [1 4], "customFileClass does not initialise correctly");
            testCase.verifyEqual(testClass.fileTable, testCase.exampleClass.fileTable, "customFileClass does not initialise correctly");
        end


    end

end