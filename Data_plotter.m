clear; close all; clc;

A = importdata('ov_results1.txt');

t = A(:,1);
ov = A(:,2);

plot(t,ov)