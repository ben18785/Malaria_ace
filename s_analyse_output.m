clear; close all; clc;

a = importdata('Results1.txt');

v_t = a(:,1);
v_j = a(:,2);
v_m_norm = a(:,3);
v_m_heg = a(:,4);
v_U = a(:,5);
v_H0 = a(:,6);
v_Ov = a(:,7);
v_feed = a(:,8);
v_thetaB = a(:,9);
