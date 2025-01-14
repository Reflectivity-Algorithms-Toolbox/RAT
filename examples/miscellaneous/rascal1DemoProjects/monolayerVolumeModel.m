
problem = createProject(name='monolayerVolumeModel', calcType='normal', model='custom layers', geometry='air/substrate', absorption=false);

problem.setParameter(1, 'min', 1, 'value', 2.65087499568656, 'max', 8);
problem.setParameterFit(1, true);
problem.setParameterPrior(1, 'uniform', 0, Inf);

paramGroup = {
              {'Area per molecule', 47, 50.6256672137588, 100, true, 'uniform', 0, Inf};
              {'Head Thickness', 7, 12.8478514973826, 14, true, 'uniform', 0, Inf};
              {'Theta', 0, 29.819492124601, 50, true, 'uniform', 0, Inf};
              };

problem.addParameterGroup(paramGroup);

problem.removeBulkIn(1);
problem.addBulkIn('Air', 0, 0, 0, false, 'uniform', 0, Inf);

problem.removeBulkOut(1);
problem.addBulkOut('D2O', 6.3e-06, 6.35e-06, 6.4e-06, false, 'uniform', 0, Inf);
problem.addBulkOut('ACMW', -5e-07, 0, 5e-07, false, 'uniform', 0, Inf);

problem.removeScalefactor(1);
problem.addScalefactor('Scalefactor 1', 0.1, 0.22726767868109, 0.4, false, 'uniform', 0, Inf);

problem.removeBackgroundParam(1);
problem.addBackgroundParam('Backs parameter 1', 1e-07, 2.56093353233351e-06, 7e-06, true, 'uniform', 0, Inf);
problem.addBackgroundParam('Backs parameter 2', 1e-07, 4.99560236193521e-06, 7e-06, true, 'uniform', 0, Inf);

problem.removeResolutionParam(1);
problem.addResolutionParam('Resolution par 1', 0.01, 0.03, 0.05, false, 'uniform', 0, Inf);

problem.addCustomFile('Model_IIb', 'Model_IIb.m', 'matlab', '', 'Model_IIb');

problem.removeData(1);
problem.addData('Simulation');
problem.setData(1, 'dataRange', [0.051793 0.58877]);
problem.setData(1, 'simRange', [0.051793 0.58877]);

data_2 = readmatrix('d70acmw20.dat');
problem.addData('d70acmw20', data_2);
problem.setData(2, 'dataRange', [0.051793 0.58877]);
problem.setData(2, 'simRange', [0.051793 0.58877]);

data_3 = readmatrix('d70d2o20.dat');
problem.addData('d70d2o20', data_3);
problem.setData(3, 'dataRange', [0.051793 0.58877]);
problem.setData(3, 'simRange', [0.051793 0.58877]);

data_4 = readmatrix('d13acmw20.dat');
problem.addData('d13acmw20', data_4);
problem.setData(4, 'dataRange', [0.051793 0.58877]);
problem.setData(4, 'simRange', [0.051793 0.58877]);

data_5 = readmatrix('d13d2o20.dat');
problem.addData('d13d2o20', data_5);
problem.setData(5, 'dataRange', [0.051793 0.58877]);
problem.setData(5, 'simRange', [0.051793 0.58877]);

data_6 = readmatrix('d83acmw20.dat');
problem.addData('d83acmw20', data_6);
problem.setData(6, 'dataRange', [0.051793 0.58877]);
problem.setData(6, 'simRange', [0.051793 0.58877]);

data_7 = readmatrix('d83d2o20.dat');
problem.addData('d83d2o20', data_7);
problem.setData(7, 'dataRange', [0.051793 0.58877]);
problem.setData(7, 'simRange', [0.051793 0.58877]);

data_8 = readmatrix('hd2o20.dat');
problem.addData('hd2o20', data_8);
problem.setData(8, 'dataRange', [0.051793 0.58877]);
problem.setData(8, 'simRange', [0.051793 0.58877]);

problem.removeBackground(1);
problem.removeResolution(1);

problem.addBackground('Background  D2O', 'constant', 'Backs parameter 1', '', '', '', '', '');
problem.addBackground('Background ACMW', 'constant', 'Backs parameter 2', '', '', '', '', '');

problem.addResolution('Resolution 1', 'constant', 'Resolution par 1', '', '', '', '', '');

problem.addContrast('background', 'Background ACMW', 'backgroundAction', 'add', 'bulkIn', 'Air', 'bulkOut', 'ACMW', 'data', 'd70acmw20', 'name', 'd70, acmw', 'resolution', 'Resolution 1', 'scalefactor', 'Scalefactor 1');
problem.setContrast(1, 'resample', false);
problem.setContrastModel(1, {'Model_IIb'});

problem.addContrast('background', 'Background  D2O', 'backgroundAction', 'add', 'bulkIn', 'Air', 'bulkOut', 'D2O', 'data', 'd70d2o20', 'name', 'd70 d2o', 'resolution', 'Resolution 1', 'scalefactor', 'Scalefactor 1');
problem.setContrast(2, 'resample', false);
problem.setContrastModel(2, {'Model_IIb'});

problem.addContrast('background', 'Background ACMW', 'backgroundAction', 'add', 'bulkIn', 'Air', 'bulkOut', 'ACMW', 'data', 'd13acmw20', 'name', 'd13 acmw', 'resolution', 'Resolution 1', 'scalefactor', 'Scalefactor 1');
problem.setContrast(3, 'resample', false);
problem.setContrastModel(3, {'Model_IIb'});

problem.addContrast('background', 'Background  D2O', 'backgroundAction', 'add', 'bulkIn', 'Air', 'bulkOut', 'D2O', 'data', 'd13d2o20', 'name', 'd13 d2o', 'resolution', 'Resolution 1', 'scalefactor', 'Scalefactor 1');
problem.setContrast(4, 'resample', false);
problem.setContrastModel(4, {'Model_IIb'});

problem.addContrast('background', 'Background ACMW', 'backgroundAction', 'add', 'bulkIn', 'Air', 'bulkOut', 'ACMW', 'data', 'd83acmw20', 'name', 'd83 acmw', 'resolution', 'Resolution 1', 'scalefactor', 'Scalefactor 1');
problem.setContrast(5, 'resample', false);
problem.setContrastModel(5, {'Model_IIb'});

problem.addContrast('background', 'Background  D2O', 'backgroundAction', 'add', 'bulkIn', 'Air', 'bulkOut', 'D2O', 'data', 'd83d2o20', 'name', 'd83 d2o', 'resolution', 'Resolution 1', 'scalefactor', 'Scalefactor 1');
problem.setContrast(6, 'resample', false);
problem.setContrastModel(6, {'Model_IIb'});

problem.addContrast('background', 'Background  D2O', 'backgroundAction', 'add', 'bulkIn', 'Air', 'bulkOut', 'D2O', 'data', 'hd2o20', 'name', 'fully h, D2O', 'resolution', 'Resolution 1', 'scalefactor', 'Scalefactor 1');
problem.setContrast(7, 'resample', false);
problem.setContrastModel(7, {'Model_IIb'});

controls = controlsClass();
[problem, results] = RAT(problem, controls);

plotRefSLD(problem, results);