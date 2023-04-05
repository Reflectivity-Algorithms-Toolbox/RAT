classdef nonPolarised < projectClass
    
    methods

        function obj = nonPolarised(experimentName)
            % Creates a project object for non polarised neutrons.
            % The only argument is the experiment name which is a char
            % array, which is optional
            %
            % problem = nonPolarised('New experiment');
            arguments
                experimentName {mustBeTextScalar} = ''
            end

            % Call projectClass constructor
            obj@projectClass(experimentName);
            obj.calculationType = calculationTypes.Standard.value;
        end
        
    end

end