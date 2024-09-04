% Custom layers model including absorption


% Set up the initial project....
problem = createProject(name = 'DPPC_50_3pcBins', calcType = 'non polarised',...
    model = 'custom layers', geometry = 'substrate/liquid', absorption = true);

% Add the required parameters (substrate reference as already there by default)....
paramGroup = {
              {'Alloy Thick',      100,     135.6,      200,       true};
              {'Alloy SLD  up',    6e-06,   9.87e-06,   1.2e-05,   true};
              {'Alloy iSLD up',    1e-09,   4.87e-08,   1e-07,     true};
              {'Alloy SLD dn',     6e-06,   7.05e-06,   1.3e-05,   true};
              {'Alloy iSLD dn',    1e-09,   4.87e-08,   1e-07,     true};
              {'Alloy Rough',      2,       5.71,       10,        true};
              {'Gold Thick',       100,     154.70,     200,       true};
              {'Gold Rough',       0.1,     5.42,       10,        true};
              {'Gold SLD',         4e-06,   4.49e-06,   5e-06,     true};
              {'gold iSLD',        1e-09,   4.20e-08,   1e-07,     true};
              {'Thiol APM',        40,      56.27,      100,       true};
              {'Thiol Head %Hydr', 20,      30,         50,        true};
              {'Thiol coverage',   0.5,     0.90,       1,         true};
              {'CW thick',         1,       12.87,      25,        true};
              {'Bilayer APM',      48,      65.86,      90,        true};
              {'Bil Head %Hydr',   20,      30,         50,        true};
              {'Bilayer rough',    1,       3.87,       10,        true};
              {'Bilayer Coverage', 0.5,     0.94,       1,         true};
              };

% Add these to the problem...
problem.addParameterGroup(paramGroup);

% Change the existing Bulk In parameter to be Silicon...
problem.setBulkIn(1, 'name', 'Silicon', 'min', 2e-6,...
                  'value', 2.073e-6, 'max', 2.1e-6);

% We need 2 bulk out's - D2O and H2O...
problem.setBulkOut(1, 'name', 'D2O', 'min', 5.8e-06,...
                   'value', 6.21e-06, 'max', 6.35e-06, 'fit', true);
problem.addBulkOut('H2O', -5.6e-07, -3.15e-07, 0, true);

% Use a different scalefactor for each dataset...
problem.removeScalefactor(1);
problem.addScalefactor('Scalefactor 1', 0.5, 1, 1.5, true);
problem.addScalefactor('Scalefactor 2', 0.5, 1, 1.5, true);
problem.addScalefactor('Scalefactor 3', 0.5, 1, 1.5, true);
problem.addScalefactor('Scalefactor 4', 0.5, 1, 1.5, true);

% Similarly, use an individual background for each dataset....
problem.removeBackgroundParam(1);
problem.addBackgroundParam('Backs parameter 1', 5e-08, 7.88e-06, 9e-05, true);
problem.addBackgroundParam('Backs parameter 2', 1e-08, 5.46e-06, 9e-05, true);
problem.addBackgroundParam('Backs parameter 3', 1e-06, 9.01e-06, 9e-05, true);
problem.addBackgroundParam('Backs parameter 4', 1e-06, 5.61e-06, 9e-05, true);

problem.removeBackground(1);
problem.addBackground('Background 1', 'constant', 'Backs parameter 1', '', '', '', '');
problem.addBackground('Background 2', 'constant', 'Backs parameter 2', '', '', '', '');
problem.addBackground('Background 3', 'constant', 'Backs parameter 3', '', '', '', '');
problem.addBackground('Background 4', 'constant', 'Backs parameter 4', '', '', '', '');

% Make the resolution fittable...
problem.setResolutionParam(1,'fit',true);

% Now add the data we need....
data_1 = readmatrix('D2O_spin_down.dat');
problem.addData('D2O_dn', data_1);
problem.setData(2, 'dataRange', [0.012 0.22],'simRange', [0.012 0.22]);

data_2 = readmatrix('D2O_spin_up.dat');
problem.addData('D2O_up', data_2);
problem.setData(3, 'dataRange', [0.012 0.22],'simRange', [0.012 0.22]);

data_3 = readmatrix('H2O_spin_down.dat');
problem.addData('H2O_dn', data_3);
problem.setData(4, 'dataRange', [0.012 0.22],'simRange', [0.012 0.22]);

data_4 = readmatrix('H2O_spin_up.dat');
problem.addData('H2O_up', data_4);
problem.setData(5, 'dataRange', [0.012 0.22],'simRange', [0.012 0.22]);

% ....and the custom file...
problem.addCustomFile('DPPC absorption', 'volumeThiolBilayer.m', 'matlab');

% Finally add the contrasts...
problem.addContrast('name',       'D2O dn',...
                    'data',       'D2O_dn',...
                    'Background', 'Background 1',...
                    'BulkIn',     'Silicon',...    
                    'BulkOut',    'D2O',...
                    'scalefactor','Scalefactor 1',...
                    'resolution', 'Resolution 1',...
                    'resample',    true);

problem.addContrast('name',       'D2O up',...
                    'data',       'D2O_up',...
                    'Background', 'Background 2',...
                    'BulkIn',     'Silicon',...    
                    'BulkOut',    'D2O',...
                    'scalefactor','Scalefactor 2',...
                    'resolution', 'Resolution 1',...
                    'resample',    true);

problem.addContrast('name',       'H2O dn',...
                    'data',       'H2O_dn',...
                    'Background', 'Background 3',...
                    'BulkIn',     'Silicon',...    
                    'BulkOut',    'H2O',...
                    'scalefactor','Scalefactor 3',...
                    'resolution', 'Resolution 1',...
                    'resample',    true);

problem.addContrast('name',       'H2O up',...
                    'data',       'H2O_up',...
                    'Background', 'Background 4',...
                    'BulkIn',     'Silicon',...    
                    'BulkOut',    'H2O',...
                    'scalefactor','Scalefactor 4',...
                    'resolution', 'Resolution 1',...
                    'resample',    true);

%.... and set the model for each....
for i = 1:4
    problem.setContrastModel(i,'DPPC absorption');
end


% Now make a controls block....
controls = controlsClass();
controls.resampleNPoints = 150;
controls.parallel = 'contrasts';

[problem,results] = RAT(problem,controls);
plotRefSLD(problem,results);
