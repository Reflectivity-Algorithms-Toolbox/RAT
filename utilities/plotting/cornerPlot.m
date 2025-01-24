function cornerPlot(results, options)
% Creates a corner plot from chain data in the result struct. 
%
% - results is a struct with the result of a RAT bayes calculation.
% - figure indicates the figure to draw in.
% - smooth indicates that the moving average smoothing is applied  
%
% cornerPlot(results);
arguments
  results
  options.figure {isFigure} = []
  options.smooth {logical} = true
end

if ~isempty(options.figure)
  hFig = figure(options.figure);
else
  hFig = figure();
end

clf(hFig);

chain = results.chain;
rows = size(chain,2);
cols = rows;

% Create/find BigAx and make it invisible
BigAx = newplot;
set(BigAx,'Visible','off','color','none')
disableDefaultInteractivity(BigAx);

BigAxUnits = get(BigAx,'units');

% Create and plot into axes
ax = gobjects(rows,cols);
pos = get(BigAx,'Position');
width = pos(3)/cols;
height = pos(4)/rows;
space = .07; % 2 percent space between axes
pos(1:2) = pos(1:2) + space*[width height];
BigAxHV = get(BigAx,'HandleVisibility');
BigAxParent = get(BigAx,'Parent');

paxes = findobj(hFig,'Type','axes','tag','PlotMatrixScatterAx');

for i=rows:-1:1
    for j=i:-1:1
        if i > j 
            axPos = [pos(1)+(j-1)*width pos(2)+(rows-i)*height width*(1-space) height*(1-space)];
            findax = findaxpos(paxes, axPos);
            if isempty(findax)
                ax(i,j) = axes('Units',BigAxUnits,'Position',axPos,'HandleVisibility',BigAxHV,'parent',BigAxParent, 'Toolbar', []);
                set(ax(i,j),'visible','on','box','on');
            else
                ax(i,j) = findax(1);
            end
            
            xx = chain(:,j);
            yy = chain(:,i);
    
            plotContours(xx, yy, ax(i,j), options.smooth);
            
            set(ax(i,j),'Visible','on','Tag','corrAxis','xlimmode','auto','ylimmode','auto','xgrid','off','ygrid','off');
            
            if j ~= 1
                set(ax(i,j),'YTick',[]);
            end
            
            if i ~= rows
                set(ax(i,j),'XTick',[]);
            end
            
            % Disable AxesToolbar
            ax(i,j).Toolbar = [];
         elseif i==j
            axPos = [pos(1)+(j-1)*width pos(2)+(rows-i)*height width*(1-space) height*(1-space)];
            findax = findaxpos(paxes, axPos);
            if isempty(findax)
                histax = axes('Units',BigAxUnits,'Position',axPos,'HandleVisibility',BigAxHV,'parent',BigAxParent, 'Toolbar', []);
                set(histax,'visible','on');
            else
                histax = findax(1);
            end
            [N,edges] = histcounts(chain(:,i), 25, 'Normalization','pdf');
            edges2 = edges(2:end) - (edges(2)-edges(1))/2;
            if (options.smooth)
                N = smoothdata(N, 'movmean');
            end
            bar(edges2(:), N(:), 1, 'w');
            
            set(histax,'tag','PlotMatrixHistAx','TitleFontSizeMultiplier',0.8);
            title(histax,split(results.fitNames{i}));         
            
            if i ~= rows
                set(histax,'XTick',[]);
            end
            if i ~= 1
                set(histax,'YTick',[]);
            end
            
            % Disable the AxesToolbar
            histax.Toolbar = [];
        end
    end
end 
drawnow;
end


function findax = findaxpos(ax, axpos)
tol = eps;
findax = [];
for i = 1:length(ax)
    axipos = get(ax(i),'Position');
    diffpos = axipos - axpos;
    if (max(max(abs(diffpos))) < tol)
        findax = ax(i);
        break;
    end
end

end


function plotContours(x, y, ax, smooth)

nbins = [50 50];

[N,Xedges,Yedges] = histcounts2(x,y,nbins,'Normalization','pdf');

if (smooth)
    N = smoothdata(N, 'movmean');
end

histogram2('XBinEdges', Xedges, 'YBinEdges', Yedges,'BinCounts',N)
C{1} = Xedges(2:end) - (Xedges(2)-Xedges(1))/2;
C{2} = Yedges(2:end) - (Yedges(2)-Yedges(1))/2;

K=(1/10)*ones(5);
N=conv2(N,K,'same');

NN = N/sum(N(:));
NS = sort(NN(:));

[c, ind, ~] = unique(cumsum(NS),'stable');
levels = interp1(c, NS(ind), [0.015 0.1 0.3 0.65 0.9],'linear','extrap');

contourf(C{1},C{2},NN',levels,'parent',ax);

colormap(flipud(gray(5)));

hold on

end
