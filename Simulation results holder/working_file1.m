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
    % Define a colour vector to equal 1 if the number of juveniles is
    % greater than zero. Multiply it by 800 to get red.
    colour = 800*(juvY>0);
    scatter(x,y,juvX+juvW+juvY+1,colour+1,'fill')
    % This command sets the colour 'axis' scaling and allows one to keep it
    % constant (rather than renormalising) between runs
    caxis([1,1000])
    time = num2str(st_data{i,2});
    time = strcat('Time',{' '},'=',{' '},time);
    title(time)
    pause(0.1)
end