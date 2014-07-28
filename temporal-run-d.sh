#!/bin/bash

#PBS -V
#PBS -l nodes=4:ppn=16
#PBS -l walltime=8:00:00
#PBS -N SprDiffA

cd ./spatial

./temporal_run_d<parameters1.txt>$DATA/temporal-sim/Res1d & 
./temporal_run_d<parameters2.txt>$DATA/temporal-sim/Res2d & 
./temporal_run_d<parameters3.txt>$DATA/temporal-sim/Res3d & 
./temporal_run_d<parameters4.txt>$DATA/temporal-sim/Res4d & 
./temporal_run_d<parameters5.txt>$DATA/temporal-sim/Res5d & 
./temporal_run_d<parameters6.txt>$DATA/temporal-sim/Res6d & 
./temporal_run_d<parameters7.txt>$DATA/temporal-sim/Res7d & 
./temporal_run_d<parameters8.txt>$DATA/temporal-sim/Res8d & 
./temporal_run_d<parameters9.txt>$DATA/temporal-sim/Res9d & 
./temporal_run_d<parameters10.txt>$DATA/temporal-sim/Res10d & 
./temporal_run_d<parameters11.txt>$DATA/temporal-sim/Res11d & 
./temporal_run_d<parameters12.txt>$DATA/temporal-sim/Res12d & 
./temporal_run_d<parameters13.txt>$DATA/temporal-sim/Res13d & 
./temporal_run_d<parameters14.txt>$DATA/temporal-sim/Res14d & 
./temporal_run_d<parameters15.txt>$DATA/temporal-sim/Res15d & 
./temporal_run_d<parameters16.txt>$DATA/temporal-sim/Res16d & 
./temporal_run_d<parameters17.txt>$DATA/temporal-sim/Res17d & 
./temporal_run_d<parameters18.txt>$DATA/temporal-sim/Res18d & 
./temporal_run_d<parameters19.txt>$DATA/temporal-sim/Res19d & 
./temporal_run_d<parameters20.txt>$DATA/temporal-sim/Res20d & 
./temporal_run_d<parameters21.txt>$DATA/temporal-sim/Res21d & 
./temporal_run_d<parameters22.txt>$DATA/temporal-sim/Res22d &
./temporal_run_d<parameters23.txt>$DATA/temporal-sim/Res23d &
./temporal_run_d<parameters24.txt>$DATA/temporal-sim/Res24d &
./temporal_run_d<parameters25.txt>$DATA/temporal-sim/Res25d &
./temporal_run_d<parameters26.txt>$DATA/temporal-sim/Res26d &
./temporal_run_d<parameters27.txt>$DATA/temporal-sim/Res27d &
./temporal_run_d<parameters28.txt>$DATA/temporal-sim/Res28d &
./temporal_run_d<parameters29.txt>$DATA/temporal-sim/Res29d &
./temporal_run_d<parameters30.txt>$DATA/temporal-sim/Res30d &
./temporal_run_d<parameters31.txt>$DATA/temporal-sim/Res31d &
./temporal_run_d<parameters32.txt>$DATA/temporal-sim/Res32d &
./temporal_run_d<parameters33.txt>$DATA/temporal-sim/Res33d &
./temporal_run_d<parameters34.txt>$DATA/temporal-sim/Res34d &
./temporal_run_d<parameters35.txt>$DATA/temporal-sim/Res35d &
./temporal_run_d<parameters36.txt>$DATA/temporal-sim/Res36d &
./temporal_run_d<parameters37.txt>$DATA/temporal-sim/Res37d &
./temporal_run_d<parameters38.txt>$DATA/temporal-sim/Res38d &
./temporal_run_d<parameters39.txt>$DATA/temporal-sim/Res39d &
./temporal_run_d<parameters40.txt>$DATA/temporal-sim/Res40d &
./temporal_run_d<parameters41.txt>$DATA/temporal-sim/Res41d &
./temporal_run_d<parameters42.txt>$DATA/temporal-sim/Res42d &
./temporal_run_d<parameters43.txt>$DATA/temporal-sim/Res43d &
./temporal_run_d<parameters44.txt>$DATA/temporal-sim/Res44d &
./temporal_run_d<parameters45.txt>$DATA/temporal-sim/Res45d &
./temporal_run_d<parameters46.txt>$DATA/temporal-sim/Res46d &
./temporal_run_d<parameters47.txt>$DATA/temporal-sim/Res47d &
./temporal_run_d<parameters48.txt>$DATA/temporal-sim/Res48d &
./temporal_run_d<parameters49.txt>$DATA/temporal-sim/Res49d &
./temporal_run_d<parameters50.txt>$DATA/temporal-sim/Res50d &
./temporal_run_d<parameters51.txt>$DATA/temporal-sim/Res51d &
./temporal_run_d<parameters52.txt>$DATA/temporal-sim/Res52d &
./temporal_run_d<parameters53.txt>$DATA/temporal-sim/Res53d &
./temporal_run_d<parameters54.txt>$DATA/temporal-sim/Res54d &
./temporal_run_d<parameters55.txt>$DATA/temporal-sim/Res55d &
./temporal_run_d<parameters56.txt>$DATA/temporal-sim/Res56d &
./temporal_run_d<parameters57.txt>$DATA/temporal-sim/Res57d &
./temporal_run_d<parameters58.txt>$DATA/temporal-sim/Res58d &
./temporal_run_d<parameters59.txt>$DATA/temporal-sim/Res59d &
./temporal_run_d<parameters60.txt>$DATA/temporal-sim/Res60d &
./temporal_run_d<parameters61.txt>$DATA/temporal-sim/Res61d &
./temporal_run_d<parameters62.txt>$DATA/temporal-sim/Res62d &
./temporal_run_d<parameters63.txt>$DATA/temporal-sim/Res63d
./temporal_run_d<parameters64.txt>$DATA/temporal-sim/Res64d
