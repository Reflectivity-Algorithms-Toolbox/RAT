classdef hydrationTypes < customEnum
    methods (Static)
        function s = toStruct()
            s = customEnum.toStruct(mfilename('class'));
        end
        
        function v = values()
            v = customEnum.values(mfilename('class'));
        end
        
        function e = fromValue(value)
            e = customEnum.fromValue(mfilename('class'), value);
        end
    end

    enumeration
        None ('none')
        BulkIn ('bulk in')
        BulkOut ('bulk out')
        Oil ('oil')
    end
end