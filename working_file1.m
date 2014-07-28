clear; close all; clc;

n_pow = 8;
v_chi = zeros(n_pow,1);
v_eta = zeros(n_pow,1);

for i = 1:n_pow
    v_chi(i) = 0.01*10^(0.25*i-0.25);
    v_eta(i) = 0.01*10^(0.25*i-0.25);
end

cell_chi = {'01','017','031','056'};
cell_eta = {'01','177'};