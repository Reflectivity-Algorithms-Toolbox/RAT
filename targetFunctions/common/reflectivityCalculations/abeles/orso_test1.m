



layers = [0.0000	0.0000	0.0000	0.0000
30.0000	-1.9493	0.0000	0.0000
70.0000	9.4245	0.0000	0.0000
30.0000	-1.9493	0.0000	0.0000
70.0000	9.4245	0.0000	0.0000
30.0000	-1.9493	0.0000	0.0000
70.0000	9.4245	0.0000	0.0000
30.0000	-1.9493	0.0000	0.0000
70.0000	9.4245	0.0000	0.0000
30.0000	-1.9493	0.0000	0.0000
70.0000	9.4245	0.0000	0.0000
30.0000	-1.9493	0.0000	0.0000
70.0000	9.4245	0.0000	0.0000
30.0000	-1.9493	0.0000	0.0000
70.0000	9.4245	0.0000	0.0000
30.0000	-1.9493	0.0000	0.0000
70.0000	9.4245	0.0000	0.0000
30.0000	-1.9493	0.0000	0.0000
70.0000	9.4245	0.0000	0.0000
30.0000	-1.9493	0.0000	0.0000
70.0000	9.4245	0.0000	0.0000
0.0000	2.0704	0.0000	0.0000];

layers(:,2) = layers(:,2) .* 1e-6;
layers(:,3) = layers(:,3) .* 1e-6;

data = dlmread('test1.dat');

thick = layers(:,1);
sld = complex(layers(:,2),layers(:,3));
rough = layers(:,4);

q = data(:,1);
N = size(layers,1);
ref = abelesSingle(q,N,thick,sld,rough);

% Plot the comparison....
figure(1); clf
semilogy(q,ref,'k-','LineWidth',2)
hold on
plot(data(:,1),data(:,2),'r.')