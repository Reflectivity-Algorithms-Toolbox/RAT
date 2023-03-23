% This file is used to generate the mex function that deals with CPP custom layer functionality.


function [output,subRough] = testDLL(params,nba,nbs,numberOfContrasts,libraryName,functionName)


    coder.cinclude('<functional>');
    coder.cinclude('<string>');
    coder.cinclude('<iostream>');
    coder.cinclude('<map>');
    coder.cinclude('<vector>');
    coder.cinclude('libManager.h');
    coder.cinclude('<tuple>');
    coder.updateBuildInfo('addLinkFlags','-ldl');

    % Add the include dir....
    includeDir = getappdata(0,'includeDir');
    coder.updateBuildInfo('addIncludePaths',includeDir);

    % Need to find a way to make this work with 100000,3
    tempOutput = zeros(3,1000);
    subRough = 0.0;
    nLayers = 0;
    % coder.varsize('output',[1000 1],[1 0]);

    p = coder.opaque('Library','NULL','HeaderFile','libManager.h');
    % Make an instance 
    p = coder.ceval('Library');

    % We need to add a null terminator to the library names in order for
    % them to match C/C++ format. See....
    % https://uk.mathworks.com/help/coder/ug/c-strings-for-null-terminated-matlab-strings.html
    libraryName = [libraryName,0];
    functionName = [functionName,0];

    % bulk in - 1xn
    % bulk out - 1xn
    % params - 1xn
    % call the class method in libManager.h
    coder.ceval('std::mem_fn(&Library::loadRunner)',p,coder.ref(params),coder.ref(nba),coder.ref(nbs)...
        ,numberOfContrasts,coder.wref(tempOutput),coder.wref(subRough),coder.wref(nLayers),libraryName,functionName);

    output = tempOutput(:,1:nLayers)';
    %fprintf('subRough in testDLL is %g \n', subRough);
    %fprintf('output 1  is %g \n',output(1)); 
    %fprintf('nLayers is %g \n',nLayers);
end



