function plotRefSLDHelper(data, noDelay, linearX, q4, showErrorBar, showGrid, showLegend)
    % Helper function to make it easier to plot from event. 
    %
    % - Data is a struct with the plot data.
    % - noDelay indicates if draw should be delayed.
    % - linearX indicates that the X axis should be linear scale instead of log.
    % - q4 indicates that the Y axis should plot Q^4.
    % - showErrorBars indicates that the error bar should be shown in the plot
    % - showGrid indicates that the grid should be shown in the plot
    % - showLegend indicates that the legend should be shown in the plot
    %
    % plotRefSLDHelper(data, false);
    arguments
        data
        noDelay {logical} = true
        linearX {logical} = false
        q4 {logical} = false
        showErrorBar {logical} = true
        showGrid {logical} = false
        showLegend {logical} = true
    end

    defaultState = 'on';
    s = warning();
    if any(strcmp({s.identifier}, 'MATLAB:Axes:NegativeDataInLogAxis'))
        defaultState = 'off';
    end
    warning('off','MATLAB:Axes:NegativeDataInLogAxis');

    numberOfContrasts = length(data.reflectivity);
    
    % Plot the data.reflectivity
    subplot(1,2,1);
    if linearX
       set(gca,'YScale','log','XScale','linear');
    else
       set(gca,'YScale','log','XScale','log');
    end

    if showGrid
       set(gca,'YGrid','on','XGrid','on');
    end   
    hold on
    xlabel('$\textrm{Q}_{z} (\AA^{-1})$', 'Interpreter', 'Latex') 
    ylabel('Reflectivity', 'Interpreter', 'Latex') 
    lines = cell(numberOfContrasts, 1);
    mult = 1;
    q4Data = 1;
    for i = 1:numberOfContrasts
        thisRef = data.reflectivity{i};
        thisData = data.shiftedData{i};
        if i > 1 || q4
            mult = 2^(4*i);
        end
        
        if q4 && data.dataPresent(i)
            q4Data = thisData(:,1).^4;
        end
        mult = q4Data/mult;
        refY = thisRef(:,2) .* mult;
        % If there is data present
        % plot it - size of data.shiftedData
        % will be [n x 3] if so
        if data.dataPresent(i) && showErrorBar    
            dataX = thisData(:, 1); 
            dataY = thisData(:,2) .* mult;
            dataErr = thisData(:,3) .* mult;
            errorbar(dataX, dataY, dataErr, '.', 'MarkerSize', 2.5);
        end
    
        % Plot the fit
        lines{i} = plot(thisRef(:,1), refY, '-', 'LineWidth', 2);
        
    end
    if showLegend
        legend([lines{:}], data.contrastNames{:});
    end

    % Plot the SLDs
    subplot(1,2,2);
    if showGrid
         set(gca,'YGrid','on','XGrid','on');
    end
    hold on
    xlabel('$\textrm{Z} (\AA)$','Interpreter','Latex') 
    ylabel('$\textrm{SLD} (\AA^{-2})$','Interpreter','Latex') 
    nColumns = size(data.sldProfiles, 2);
    lines = cell(numberOfContrasts * nColumns, 1);
    names = cell(numberOfContrasts * nColumns, 1);
    for i = 1:numberOfContrasts
        for j=1:nColumns
           index = nColumns*(i-1)+j ;
           sld = data.sldProfiles{i, j};
           lines{index} = plot(sld(:, 1), sld(:, 2), '-');
           if nColumns == 2
               names{index} = sprintf("%s Domain %d", data.contrastNames{i}, j); 
           else
               names{index} = data.contrastNames{i};
           end
        end
    
        % If there is resampling, plot the resampled layers also
        % TODO for domains...
        if (data.resample(i) == 1) || (strcmpi(data.modelType, 'custom xy'))
            roughness = data.subRoughs(i); 
            layers = data.resampledLayers{i, 1};
            bulkIn = layers(1, 2);
            bulkOut = layers(end, 2);

            for j=1:size(data.resampledLayers, 2)
                layer = data.resampledLayers{i, j};                                               

                % Because we plot only real SLD, if we have imaginary in
                % layers then take it out...
                if size(layers,2) == 4
                    layer = [layer(:,1:2),layer(:,4)];
                end
                numberOfLayers = size(layer, 1);
                nrepeats = 1;
                newProf = makeSLDProfileXY(bulkIn,bulkOut,roughness,layer,numberOfLayers,nrepeats);
                plot(newProf(:,1)-49,newProf(:,2));
            end
        end
    end
    if showLegend
        legend([lines{:}], names{:});
    end
    if noDelay
        drawnow limitrate;
    end
    warning(defaultState, 'MATLAB:Axes:NegativeDataInLogAxis');
end