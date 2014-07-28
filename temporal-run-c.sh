#!/bin/bash

#PBS -V
#PBS -l nodes=4:ppn=16
#PBS -l walltime=8:00:00
#PBS -N SprDiffA

cd ./spatial

./temporal_run_c<parameters1.txt>$DATA/temporal-sim/Res1c & 
./temporal_run_c<parameters2.txt>$DATA/temporal-sim/Res2c & 
./temporal_run_c<parameters3.txt>$DATA/temporal-sim/Res3c & 
./temporal_run_c<parameters4.txt>$DATA/temporal-sim/Res4c & 
./temporal_run_c<parameters5.txt>$DATA/temporal-sim/Res5c & 
./temporal_run_c<parameters6.txt>$DATA/temporal-sim/Res6c & 
./temporal_run_c<parameters7.txt>$DATA/temporal-sim/Res7c & 
./temporal_run_c<parameters8.txt>$DATA/temporal-sim/Res8c & 
./temporal_run_c<parameters9.txt>$DATA/temporal-sim/Res9c & 
./temporal_run_c<parameters10.txt>$DATA/temporal-sim/Res10c & 
./temporal_run_c<parameters11.txt>$DATA/temporal-sim/Res11c & 
./temporal_run_c<parameters12.txt>$DATA/temporal-sim/Res12c & 
./temporal_run_c<parameters13.txt>$DATA/temporal-sim/Res13c & 
./temporal_run_c<parameters14.txt>$DATA/temporal-sim/Res14c & 
./temporal_run_c<parameters15.txt>$DATA/temporal-sim/Res15c & 
./temporal_run_c<parameters16.txt>$DATA/temporal-sim/Res16c & 
./temporal_run_c<parameters17.txt>$DATA/temporal-sim/Res17c & 
./temporal_run_c<parameters18.txt>$DATA/temporal-sim/Res18c & 
./temporal_run_c<parameters19.txt>$DATA/temporal-sim/Res19c & 
./temporal_run_c<parameters20.txt>$DATA/temporal-sim/Res20c & 
./temporal_run_c<parameters21.txt>$DATA/temporal-sim/Res21c & 
./temporal_run_c<parameters22.txt>$DATA/temporal-sim/Res22c &
./temporal_run_c<parameters23.txt>$DATA/temporal-sim/Res23c &
./temporal_run_c<parameters24.txt>$DATA/temporal-sim/Res24c &
./temporal_run_c<parameters25.txt>$DATA/temporal-sim/Res25c &
./temporal_run_c<parameters26.txt>$DATA/temporal-sim/Res26c &
./temporal_run_c<parameters27.txt>$DATA/temporal-sim/Res27c &
./temporal_run_c<parameters28.txt>$DATA/temporal-sim/Res28c &
./temporal_run_c<parameters29.txt>$DATA/temporal-sim/Res29c &
./temporal_run_c<parameters30.txt>$DATA/temporal-sim/Res30c &
./temporal_run_c<parameters31.txt>$DATA/temporal-sim/Res31c &
./temporal_run_c<parameters32.txt>$DATA/temporal-sim/Res32c &
./temporal_run_c<parameters33.txt>$DATA/temporal-sim/Res33c &
./temporal_run_c<parameters34.txt>$DATA/temporal-sim/Res34c &
./temporal_run_c<parameters35.txt>$DATA/temporal-sim/Res35c &
./temporal_run_c<parameters36.txt>$DATA/temporal-sim/Res36c &
./temporal_run_c<parameters37.txt>$DATA/temporal-sim/Res37c &
./temporal_run_c<parameters38.txt>$DATA/temporal-sim/Res38c &
./temporal_run_c<parameters39.txt>$DATA/temporal-sim/Res39c &
./temporal_run_c<parameters40.txt>$DATA/temporal-sim/Res40c &
./temporal_run_c<parameters41.txt>$DATA/temporal-sim/Res41c &
./temporal_run_c<parameters42.txt>$DATA/temporal-sim/Res42c &
./temporal_run_c<parameters43.txt>$DATA/temporal-sim/Res43c &
./temporal_run_c<parameters44.txt>$DATA/temporal-sim/Res44c &
./temporal_run_c<parameters45.txt>$DATA/temporal-sim/Res45c &
./temporal_run_c<parameters46.txt>$DATA/temporal-sim/Res46c &
./temporal_run_c<parameters47.txt>$DATA/temporal-sim/Res47c &
./temporal_run_c<parameters48.txt>$DATA/temporal-sim/Res48c &
./temporal_run_c<parameters49.txt>$DATA/temporal-sim/Res49c &
./temporal_run_c<parameters50.txt>$DATA/temporal-sim/Res50c &
./temporal_run_c<parameters51.txt>$DATA/temporal-sim/Res51c &
./temporal_run_c<parameters52.txt>$DATA/temporal-sim/Res52c &
./temporal_run_c<parameters53.txt>$DATA/temporal-sim/Res53c &
./temporal_run_c<parameters54.txt>$DATA/temporal-sim/Res54c &
./temporal_run_c<parameters55.txt>$DATA/temporal-sim/Res55c &
./temporal_run_c<parameters56.txt>$DATA/temporal-sim/Res56c &
./temporal_run_c<parameters57.txt>$DATA/temporal-sim/Res57c &
./temporal_run_c<parameters58.txt>$DATA/temporal-sim/Res58c &
./temporal_run_c<parameters59.txt>$DATA/temporal-sim/Res59c &
./temporal_run_c<parameters60.txt>$DATA/temporal-sim/Res60c &
./temporal_run_c<parameters61.txt>$DATA/temporal-sim/Res61c &
./temporal_run_c<parameters62.txt>$DATA/temporal-sim/Res62c &
./temporal_run_c<parameters63.txt>$DATA/temporal-sim/Res63c
./temporal_run_c<parameters64.txt>$DATA/temporal-sim/Res64c
