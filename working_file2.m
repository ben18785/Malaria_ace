clear; close all; clc;

a = load('Results056177.txt');

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

v_total = v_j+v_m_norm+v_m_heg+v_U+v_H0+v_Ov;

n_cycles = round(length(a)/300);
v_survive = zeros(n_cycles,1);

for i = 1:n_cycles
    v_temptot = v_total((i-1)*300 + 1:i*300);
    v_conditions = v_thetaB((i-1)*300 + 1:i*300);
%     subplot(1,2,1),plot(1:300,v_temptot)
%     ylim([0 16000])
%     subplot(1,2,2),plot(1:300,v_conditions)
%     pause(1)
 
    if v_temptot(end)>50
        v_survive(i) = 1;
    end
end
