function [slds,subRoughs] = processCustomFunction(contrastBulkIns,contrastBulkOuts,...
    bulkInArray,bulkOutArray,cCustFiles,numberOfContrasts,customFiles,params)

    % Top-level function for processing custom XY profiles for all the
    % contrasts.

    % Do some pre-definitions to keep the compiler happy...
    slds = cell(numberOfContrasts,1);
    subRoughs = zeros(numberOfContrasts,1);

    for i = 1:numberOfContrasts
        slds{i} = [0 0];
    end
    coder.varsize('slds{:}',[10000 3],[1 1]);    % 3 columns to allow for potential imaginary curve
    
    bulkOuts = bulkOutArray(contrastBulkOuts);
    for i = 1:numberOfContrasts     % TODO - the ambition is for parfor here, but would fail for Matlab and Python CM's..

        % Choose which custom file is associated with this contrast
        functionHandle = customFiles{cCustFiles(i)};

        % Find values of 'bulkIn' and 'bulkOut' for this
        % contrast...
        thisBulkIn = bulkInArray(contrastBulkIns(i));
        
        if isnan(str2double(functionHandle))
            [slds{i}, subRoughs(i)] = callMatlabFunction(functionHandle, params, thisBulkIn, bulkOuts, i, 0);
        else
            [slds{i}, subRoughs(i)] = callCppFunction(functionHandle, params, thisBulkIn, bulkOuts, i-1, -1);
        end
    end
end
