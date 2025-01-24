function isFigure(figure)
  % Check if input is a figure or figure Id.   
  if ~(isnumeric(figure) || isa(figure, 'matlab.ui.Figure'))
    error("'figure' must be a figure number or a figure object.")
  end
end
