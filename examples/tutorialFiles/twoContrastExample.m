% Full Example
problem = projectClass('DSPC monolayers');% Define the parameters:
Parameters = {
    %       Name                min     val     max      fit?
    {'Tails Thickness',         10,     20,      30,     true};
    {'Heads Thickness',          3,     11,      16,     true};
    {'Tails Roughness',          2,     5,       9,      true};
    {'Heads Roughness',          2,     5,       9,      true};
    {'Deuterated Tails SLD',    4e-6,   6e-6,    2e-5,   true};
    {'Hydrogenated Tails SLD', -0.6e-6, -0.4e-6, 0,      true};
    {'Deuterated Heads SLD',    1e-6,   3e-6,    8e-6,   true};
    {'Hydrogenated Heads SLD',  0.1e-6, 1.4e-6,  3e-6,   true};
    {'Heads Hydration',         0,      0.3,     0.5,    true};
    };

problem.addParameterGroup(Parameters);H_Heads = {'Hydrogenated Heads',...
    'Heads Thickness',...
    'Hydrogenated Heads SLD',...
    'Heads Roughness',...
    'Heads Hydration',...
    'bulk out' };

D_Heads = {'Deuterated Heads',...
        'Heads Thickness',...
        'Deuterated Heads SLD',...
        'Heads Roughness',...
        'Heads Hydration',...
        'bulk out' };

D_Tails = {'Deuterated Tails',...
        'Tails Thickness',...
        'Deuterated Tails SLD',...
        'Tails Roughness'};

H_Tails = {'Hydrogenated Tails',...
        'Tails Thickness',...
        'Hydrogenated Tails SLD',...
        'Tails Roughness'};

problem.addLayerGroup({H_Heads; D_Heads; H_Tails; D_Tails});
problem.setBackgroundParamName(1, 'Backs Value ACMW'); % Use existing backsPar
problem.setBackgroundParamValue(1, 5.5e-6);
problem.addBackgroundParam('Backs Value D2O', 1e-8, 2.8e-6, 1e-5);
problem.addBackground('Background D2O', 'constant', 'Backs Value D2O');
problem.setBackground(1, 'name', 'Background ACMW', 'source', 'Backs Value ACMW');
problem.addBulkOut('SLD ACMW', -1e-6, 0.0, 1e-6, true);

root = getappdata(0, 'root');
dataPath = '/examples/miscellaneous/convertRascal1Project/';
d13ACM = readmatrix(fullfile(root, dataPath, 'd13acmw20.dat'));
d70d2O = readmatrix(fullfile(root, dataPath, 'd70d2o20.dat'));
problem.addData('H-tail / D-head / ACMW', d13ACM);
problem.addData('D-tail / H-head / D2O', d70d2O);

problem.addContrast('name', 'D-tail/H-Head/D2O',...
                'background', 'Background D2O',...
                'resolution', 'Resolution 1',...
                'scalefactor', 'Scalefactor 1',...
                'BulkOut', 'SLD D2O',...
                'BulkIn', 'SLD Air',...
                'data', 'D-tail / H-head / D2O');

problem.addContrast('name', 'H-tail/D-Head/ACMW',...
                    'background', 'Background ACMW',...
                    'resolution', 'Resolution 1',...
                    'scalefactor', 'Scalefactor 1',...
                    'BulkOut', 'SLD ACMW',...
                    'BulkIn', 'SLD Air',...
                    'data', 'H-tail / D-head / ACMW');
problem.setContrastModel(1, {'Deuterated Tails','Hydrogenated Heads'});
problem.setContrastModel(2, {'Hydrogenated Tails','Deuterated Heads'});

problem.setBackgroundParam(1,'fit', true);
problem.setBackgroundParam(2,'fit', true);
problem.setScalefactor(1,'fit', true);
problem.setBulkOut(1,'fit', true);

%% Save problem
[path, ~, ~] = fileparts(mfilename("fullpath"));
save([path filesep 'twoContrastExample.mat'], 'problem');

