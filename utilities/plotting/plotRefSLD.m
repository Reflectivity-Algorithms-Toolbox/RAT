function plotRefSLD(problem, result)

    
    % Convert the problem class to a struct.
    controls = controlsClass();
    data.modelType = problem.modelType;
    [problemDef,~,~,~,~] = parseClassToStructs(problem,controls);
    
    data.reflectivity = result.reflectivity;
    data.shifted_data = result.shifted_data;
    data.sldProfiles = result.sldProfiles;
    data.allLayers = result.allLayers;
    data.dataPresent = problemDef.dataPresent;
    data.ssub = result.contrastParams.ssubs;
    data.resample = problemDef.resample;

    plotRefSLDHelper(data, false);
end