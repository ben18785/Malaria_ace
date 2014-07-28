clear; close all; clc;

x = {'a','b','c','d'};

cell_survival = cell(4,63);
for i = 1:4
    cell_names = f_name_generator(x{i});
    for j = 1:63
        filename = cell_names{j};
        cell_survival{i,j} = f_survival_analysis(filename);
    end
end