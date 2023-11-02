function CR = drawCR(DREAMPar,pCR)
% Generates CR values based on current crossover probabilities

CR = [1,1];
coder.varsize('CR',[1e2,1e6],[1,1]);

switch DREAMPar.adapt_pCR
    
    % If crossover probabilities are updated
    case 'yes'
        
        % How many candidate points for each crossover value?
        [L] = multrnd(DREAMPar.N * DREAMPar.steps,pCR); L2 = [0 cumsum(L)];
        
        % Then select which candidate points are selected with what CR
        r = randperm(DREAMPar.N * DREAMPar.steps);
        
        % Then generate CR values for each chain
        cCR = zeros(1e6,1);
        coder.varsize('cCR',[1e6 1],[1 0]);

        for zz = 1:DREAMPar.nCR
            
            % Define start and end
            i_start = L2(1,zz) + 1; i_end = L2(1,zz+1);
            
            % Take the appropriate elements of r
            idx = r(i_start:i_end);
            
            % Assign these indices DREAMPar.CR(zz)
            cCR(idx,1) = zz/DREAMPar.nCR;
            
        end
        
        % Now reshape CR
        % CR = reshape(cCR,DREAMPar.N,DREAMPar.steps);
        CR = reshape(cCR,DREAMPar.N,[]);
    
    % If crossover probabilities are not updated
    case 'no'
        
        CR = reshape(randsample([1:DREAMPar.nCR]/DREAMPar.nCR,DREAMPar.steps*DREAMPar.N,true,pCR),DREAMPar.N,DREAMPar.steps);
        
    otherwise
        
        error('unknown crossover sampling method');
        
end