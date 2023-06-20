classdef customModelClass < handle

    % A general class containing methods for running user defined custom
    % models. This version contains direct calls to the base Matlab

    properties

    end

    methods (Static)

        function [allLayers,allRoughs] = processCustomLayers(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
                shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params,useImaginary)

            % Top-level function for processing custom layers for all the
            % contrasts.

            % Do some pre-definitions to keep the compiler happy...
            tempAllLayers = cell(numberOfContrasts,1);
            allLayers = cell(numberOfContrasts,1);
            allRoughs = zeros(numberOfContrasts,1);

            for i = 1:numberOfContrasts
                allLayers{i} = [1 , 1];    % Type def as double (size not important)
                tempAllLayers{i} = [0 0 0 0 0];
            end
            coder.varsize('tempAllLayers{:}',[10000 6],[1 1]);


            for i = 1:numberOfContrasts     % TODO - the ambition is for parfor here, but would fail for Matlab and Python CM's..

                % Choose which custom file is associated with this contrast
                thisCustomModel = customFiles{cCustFiles(i)};

                % Check what language it is....
                thisLanguage = thisCustomModel{2};

                % ... and path
                thisPath = thisCustomModel{3};

                % ....also file.
                thisFile = thisCustomModel{1};

                % Find values of 'bulkIn' and 'bulkOut' for this
                % contrast...
                [~,~,~,bulkIn,bulkOut,~] = backSort(cBacks(i),cShifts(i),cScales(i),cNbas(i),cNbss(i),cRes(i),backs,shifts,sf,nba,nbs,res);

                thisContrastLayers = [1 1 1]; % typeDef
                coder.varsize('thisContrastLayers',[10000, 6],[1 1]);

                switch thisLanguage
                    case 'matlab'
                        [thisContrastLayers,allRoughs(i)] = callMatlabCustomFunction(params,i,thisFile,thisPath,bulkIn,bulkOut,numberOfContrasts);
                    case 'cpp'
                        [thisContrastLayers,allRoughs(i)] = callCppFunc(params,bulkIn,bulkOut,i,thisFile,thisFile);
                    case 'python'
                        [thisContrastLayers,allRoughs(i)] = pythonCustomFunctionWrapper(thisFile,params,bulkIn,bulkOut,i,numberOfContrasts);
                end

                % If the output layers has 5 columns, then we need to do
                % the hydration correction (the user has not done it in the
                % custom function). Do that here....
                if ~useImaginary
                   thisContrastLayers = applyHydrationReal(thisContrastLayers,bulkIn,bulkOut);
                else
                   thisContrastLayers = applyHydrationImag(thisContrastLayers,bulkIn,bulkOut);
                end

                tempAllLayers{i} = thisContrastLayers;
            end

            allLayers = tempAllLayers;

        end


        function [allSLDs,allRoughs] = processCustomXY(cBacks,cShifts,cScales,cNbas,cNbss,cRes,backs,...
                shifts,sf,nba,nbs,res,cCustFiles,numberOfContrasts,customFiles,params,useImaginary)

            % Top-level function for processing custom XY profiles for all the
            % contrasts.

            % Do some pre-definitions to keep the compiler happy...
            tempAllSLDs = cell(numberOfContrasts,1);
            allSLDs = cell(numberOfContrasts,1);
            allRoughs = zeros(numberOfContrasts,1);

            for i = 1:numberOfContrasts
                allSLDs{i} = [1,1];    % Type def as double (size not important)
                tempAllSLDs{i} = [0 0];
            end
            coder.varsize('tempAllSLDs{:}',[10000 3],[1 1]);    % 3 columns to allow for potential imaginary curve

            for i = 1:numberOfContrasts     % TODO - the ambition is for parfor here, but would fail for Matlab and Python CM's..

                % Choose which custom file is associated with this contrast
                thisCustomModel = customFiles{cCustFiles(i)};

                % Check what language it is....
                thisLanguage = thisCustomModel{2};

                % ... and path
                thisPath = thisCustomModel{3};

                % ....also file.
                thisFile = thisCustomModel{1};

                % Find values of 'bulkIn' and 'bulkOut' for thid
                % contrast...
                [~,~,~,bulkIn,bulkOut,~] = backSort(cBacks(i),cShifts(i),cScales(i),cNbas(i),cNbss(i),cRes(i),backs,shifts,sf,nba,nbs,res);

                switch thisLanguage
                    case 'matlab'
                        [tempAllSLDs{i},allRoughs(i)] = callMatlabCustomFunction(params,i,thisFile,thisPath,bulkIn,bulkOut,numberOfContrasts);
                    case 'cpp'
                        [tempAllSLDs{i},allRoughs(i)] = callCppFunc(params,bulkIn,bulkOut,i,thisFile,thisFile);
                    case 'python'
                        [tempAllSLDs{i},allRoughs(i)] = pythonCustomFunctionWrapper(thisFile,params,bulkIn,bulkOut,i,numberOfContrasts);
                end
            end

            allSLDs = tempAllSLDs;
        end
    end
end