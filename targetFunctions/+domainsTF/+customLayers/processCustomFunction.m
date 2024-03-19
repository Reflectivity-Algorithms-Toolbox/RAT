function [resampledLayers,subRoughs] = processCustomFunction(contrastBulkIns,contrastBulkOuts,...
    bulkIn,bulkOut,cCustFiles,numberOfContrasts,customFiles,params,useImaginary)

    % Top-level function for processing custom layers for all the
    % contrasts.

    % Do some pre-definitions to keep the compiler happy...
    %totNumCalcs = numberOfContrasts * 2;
    tempResampledLayers = cell(numberOfContrasts,2);
    resampledLayers = cell(numberOfContrasts,2);
    subRoughs = zeros(numberOfContrasts,1);

    for i = 1:numberOfContrasts
        resampledLayers{i,1} = [1, 1];    % Type def as double (size not important)
        resampledLayers{i,2} = [1, 1];
        tempResampledLayers{i,1} = [0 0 0 0 0];
        tempResampledLayers{i,2} = [0 0 0 0 0];
    end
    coder.varsize('tempResampledLayers{:}',[10000 6],[1 1]);
    coder.varsize('resampledLayers{:}',[10000 6],[1 1]);
    
    allBulkOuts = bulkOut(contrastBulkOuts);
    for i = 1:numberOfContrasts

        % Choose which custom file is associated with this contrast
        functionHandle = customFiles{cCustFiles(i)};

        % Find values of 'bulkIn' and 'bulkOut' for this
        % contrast...
        thisContrastLayers1 = [1 1 1]; % typeDef
        coder.varsize('thisContrastLayers1',[10000, 6],[1 1]);

        thisContrastLayers2 = [1 1 1]; % typeDef
        coder.varsize('thisContrastLayers2',[10000, 6],[1 1]);

        thisBulkIn = bulkIn(contrastBulkIns(i));
        thisBulkOut = allBulkOuts(i);

        if isnan(str2double(functionHandle))
            [thisContrastLayers1, subRoughs(i)] = callMatlabFunction(functionHandle, params, thisBulkIn, allBulkOuts, i, 1);
            [thisContrastLayers2, ~] = callMatlabFunction(functionHandle, params, thisBulkIn, allBulkOuts, i, 2);
        else
            [thisContrastLayers1, subRoughs(i)] = callCppFunction(functionHandle, params, thisBulkIn, allBulkOuts, i-1, 0);
            [thisContrastLayers2, ~] = callCppFunction(functionHandle, params, thisBulkIn, allBulkOuts, i-1, 1);
        end

        % If the output layers has 5 columns, then we need to do
        % the hydration correction (the user has not done it in the
        % custom function). Do that here....
        if ~useImaginary
           thisContrastLayers1 = applyHydrationReal(thisContrastLayers1,thisBulkIn,thisBulkOut);
           thisContrastLayers2 = applyHydrationReal(thisContrastLayers2,thisBulkIn,thisBulkOut);
        else
           thisContrastLayers1 = applyHydrationImag(thisContrastLayers1,thisBulkIn,thisBulkOut);
           thisContrastLayers2 = applyHydrationImag(thisContrastLayers2,thisBulkIn,thisBulkOut);
        end

        tempResampledLayers{i,1} = thisContrastLayers1;
        tempResampledLayers{i,2} = thisContrastLayers2;
    end

    resampledLayers = tempResampledLayers;

end
