clear; close all; clc;

st_data = spatial_info('Par1T*');
num_files = length(st_data);

for i = 1:num_files
    A = st_data{i,1};
    x = A(:,1);
    y = A(:,2);
    juvX = A(:,3);
    juvW = A(:,4);
    juvY = A(:,5);
    unmated_f = A(:,6);
    maleW = A(:,7);
    maleY = A(:,8);
    mate_W_rate = A(:,9);
    mate_Y_rate = A(:,10);
    status = A(:,11);
    scatter(x,y)
    pause(1)
end