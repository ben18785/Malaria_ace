function A = spatial_info(s_user)
% A function which takes a file root name e.g. 'Par1T' and returns all
% files which have a similar root which are the same in date and time. It
% then accesses these files to get the spatial data which has been
% generated from Ace's program, returning these as a cell array

str_all_files_info = dir(s_user);
num_files = length(str_all_files_info);
all_files_namesdate = cell(num_files,4);

% Get all the file names
for i = 1:num_files
    all_files_namesdate{i,1} = str_all_files_info(i).name;
    all_files_namesdate{i,2} = str_all_files_info(i).date;
end

% Now extract the date and time
format long g

for i = 1:num_files
    temp_date = all_files_namesdate{i,2};
    temp_date = datenum(temp_date);
    temp_fdate = num2str(temp_date);
    temp_sdate = str2num(temp_fdate(1:6));
    all_files_namesdate{i,3} = temp_sdate;
    temp_time = temp_date - temp_sdate;
    all_files_namesdate{i,4} = temp_time;
end
format short

% Now only keep those files which have the same date as the first one, and
% are less than 0.02 away from the first in terms of time

short_files = cell(num_files,1);
first_date = all_files_namesdate{1,3};
first_time = all_files_namesdate{1,4};
short_files{1,1} = all_files_namesdate{1,1};

for i = 2:num_files
    if (all_files_namesdate{i,3} - first_date == 0) &&  (abs(all_files_namesdate{i,4} - first_time)<0.02)
        short_files{i,1} = all_files_namesdate{i,1};
    end
end

% Now remove the empty contents of the cell array
short_files = short_files(~cellfun('isempty',short_files));

len_finalfiles = length(short_files);

% Store the spatial results in a cell array
A = cell(len_finalfiles,2);

for i = 1:len_finalfiles
    A{i,1} = csvread(short_files{i,1});
    A{i,2} = str2num(short_files{i,1}(end-6:end-4));
end




