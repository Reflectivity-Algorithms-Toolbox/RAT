classdef (Abstract) tableUtilities < handle

    % This class holds the common routines for handling table entries

    properties
        paramTable = table
    end

    properties %(GetAccess = protected, SetAccess = private)
        autoNameCounter = 1
    end

    properties (Dependent, SetAccess = private)
        paramCount
    end

    methods

        function count = get.paramCount(obj)
           count = height(obj.paramTable);
        end

        function displayTable(obj)
            % Displays the param table with numbered rows
            %
            % layers.displayTable()
            array = obj.paramTable;

            if obj.paramCount == 0
                % Creat blank line for empty table,
                array(1, :) = repmat({''}, 1, width(obj.paramTable));
            else
                % Add indices for table entries
                p = 1:obj.paramCount;
                p = p(:);
                p = table(p);
                array = [p array];
            end

            disp(array);
        end

        function names = getNames(obj)
            % Get a string array of the names of each of the objects
            % defined in the class.
            %
            % customFiles.getNames()
            names = obj.paramTable{:,1};  
        end

        function removeRow(obj, row)
            % Removes a row from the table. The expected input is an
            % integer or integer array.
            % NOTE that an input such as [1 3] leads to multiple rows
            % being removed from the table
            %
            % paramTable.removeRow(2);
            arguments
                obj
                row {mustBePositive, mustBeInteger}
            end

            if row > obj.paramCount
                throw(indexOutOfRange(sprintf('Row index %d out of range 1 - %d', row, obj.paramCount)));
            end
            
            tab = obj.paramTable;
            tab(row, :) = [];
            obj.paramTable = tab;
        end

    end

    methods%(Access = protected)

        function appendNewRow(obj, row)
            % Appends a new row to the table. Expects a cell array  
            % with the row to append
            % 
            % obj.appendNewRow({'Tails', 10, 20, 30, true, 'uniform', 0, Inf})
            tab = obj.paramTable;
            
            % Ensure no duplicate names
            if any(strcmp(row{1}, tab{:,1}))
                throw(duplicateName('Duplicate row names not allowed'));
            end

            tab = [tab; row];
            obj.paramTable = tab;
            obj.autoNameCounter = obj.autoNameCounter + 1;
        end

    end

    methods(Static)
        
        function row = findRowIndex(name, rowNames, errorMessage)
            % Find the index of a row in the table given its name.
            % The expected inputs are the name of the row, the
            % full list of row names, and, optionally, an error message.
            %
            % obj.findRowIndex('param')
            arguments
                name {mustBeTextScalar}
                rowNames {mustBeText}
                errorMessage {mustBeTextScalar} = 'The given name is not recognised'
            end

            % Strip leading or trailing whitespaces from names
            rowNames = strip(rowNames);
            name = strip(name);

            % Compare 'name' to list ignoring case
            index = strcmpi(name, rowNames);
            if any(index)
                % Non-zero value in array is the row index
                row = find(index);
            else
                throw(nameNotRecognised(errorMessage));
            end
        end

    end
end
