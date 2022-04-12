function mainGuiShiftsTableEditedCallback(src,ev)


row = ev.getFirstRow;
col = ev.getColumn;

problem = getappdata(0,'problem');
table = getappdata(0,'mainGuiShiftsTable');

fromWhere = getappdata(table,'UserData');
if strcmp(fromWhere,'Updating From Code')
    return
end

tableModel = table.getModel();

newval = tableModel.getValueAt(row,col);

row = row + 1;
switch col
    case 2
        problem.shifts_constr(row,1) = newval;
    case 3
        problem.shifts_horisontal(row) = newval;
    case 4
        problem.shifts_constr(row,2) = newval;
end

setappdata(0,'problem',problem);

if (col==3 && (strcmpi(fromWhere,'Ok') || isempty(fromWhere)))
    reflectivity_calculation();
    rJavaUpdatePlots
    drawnow limitrate
end










%__________________________________________________________________________