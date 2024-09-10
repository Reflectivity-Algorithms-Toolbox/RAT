function thisContrastLayers = allocateLayersForContrast(contrastLayers,outParameterisedLayers,useImaginary)
% Decide which layers are needed for a particular contrast.
% This function takes the master array of all layers
% and extracts which parameters are required for 
% a particular contrast. 
%
% INPUTS:
%     outParameterisedLayers - List of all the available layers
%     thisContrastLayers     - Array detailing which layers are required for this contrast

if useImaginary
    thisContrastLayers = zeros(length(contrastLayers),6);
else
    thisContrastLayers = zeros(length(contrastLayers),5);
end

for i = 1:length(contrastLayers)
    thisContrastLayers(i,:) = outParameterisedLayers{contrastLayers(i)};
end

end
