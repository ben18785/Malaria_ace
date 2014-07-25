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
v_breedw = a(:,10);
v_breede = a(:,11);
v_mate = a(:,12);
v_comp = a(:,13);
v_hfeed = a(:,14);
v_Oovi = a(:,15);
v_samples = a(:,16);
v_housedens = a(:,17);

plot(v_t,v_j/mean(v_j),'r',v_t,v_thetaB/mean(v_thetaB))
