function cell_names = f_name_generator(x)
% A function which generates a list of file names appropriate to the case
% specified in its argument.

% Generate file names
cell_names = cell(63,1);
for i = 1:63
    cell_names{i} = strcat('Results',num2str(i),x,'.txt');
end