#!/bin/bash

#PBS -V
#PBS -l nodes=4:ppn=16
#PBS -l walltime=8:00:00
#PBS -N SprDiffA

cd ./spatial

./temporal_run_b<parameters1.txt>$DATA/temporal-sim/Res1b & 
./temporal_run_b<parameters2.txt>$DATA/temporal-sim/Res2b & 
./temporal_run_b<parameters3.txt>$DATA/temporal-sim/Res3b & 
./temporal_run_b<parameters4.txt>$DATA/temporal-sim/Res4b & 
./temporal_run_b<parameters5.txt>$DATA/temporal-sim/Res5b & 
./temporal_run_b<parameters6.txt>$DATA/temporal-sim/Res6b & 
./temporal_run_b<parameters7.txt>$DATA/temporal-sim/Res7b & 
./temporal_run_b<parameters8.txt>$DATA/temporal-sim/Res8b & 
./temporal_run_b<parameters9.txt>$DATA/temporal-sim/Res9b & 
./temporal_run_b<parameters10.txt>$DATA/temporal-sim/Res10b & 
./temporal_run_b<parameters11.txt>$DATA/temporal-sim/Res11b & 
./temporal_run_b<parameters12.txt>$DATA/temporal-sim/Res12b & 
./temporal_run_b<parameters13.txt>$DATA/temporal-sim/Res13b & 
./temporal_run_b<parameters14.txt>$DATA/temporal-sim/Res14b & 
./temporal_run_b<parameters15.txt>$DATA/temporal-sim/Res15b & 
./temporal_run_b<parameters16.txt>$DATA/temporal-sim/Res16b & 
./temporal_run_b<parameters17.txt>$DATA/temporal-sim/Res17b & 
./temporal_run_b<parameters18.txt>$DATA/temporal-sim/Res18b & 
./temporal_run_b<parameters19.txt>$DATA/temporal-sim/Res19b & 
./temporal_run_b<parameters20.txt>$DATA/temporal-sim/Res20b & 
./temporal_run_b<parameters21.txt>$DATA/temporal-sim/Res21b & 
./temporal_run_b<parameters22.txt>$DATA/temporal-sim/Res22b &
./temporal_run_b<parameters23.txt>$DATA/temporal-sim/Res23b &
./temporal_run_b<parameters24.txt>$DATA/temporal-sim/Res24b &
./temporal_run_b<parameters25.txt>$DATA/temporal-sim/Res25b &
./temporal_run_b<parameters26.txt>$DATA/temporal-sim/Res26b &
./temporal_run_b<parameters27.txt>$DATA/temporal-sim/Res27b &
./temporal_run_b<parameters28.txt>$DATA/temporal-sim/Res28b &
./temporal_run_b<parameters29.txt>$DATA/temporal-sim/Res29b &
./temporal_run_b<parameters30.txt>$DATA/temporal-sim/Res30b &
./temporal_run_b<parameters31.txt>$DATA/temporal-sim/Res31b &
./temporal_run_b<parameters32.txt>$DATA/temporal-sim/Res32b &
./temporal_run_b<parameters33.txt>$DATA/temporal-sim/Res33b &
./temporal_run_b<parameters34.txt>$DATA/temporal-sim/Res34b &
./temporal_run_b<parameters35.txt>$DATA/temporal-sim/Res35b &
./temporal_run_b<parameters36.txt>$DATA/temporal-sim/Res36b &
./temporal_run_b<parameters37.txt>$DATA/temporal-sim/Res37b &
./temporal_run_b<parameters38.txt>$DATA/temporal-sim/Res38b &
./temporal_run_b<parameters39.txt>$DATA/temporal-sim/Res39b &
./temporal_run_b<parameters40.txt>$DATA/temporal-sim/Res40b &
./temporal_run_b<parameters41.txt>$DATA/temporal-sim/Res41b &
./temporal_run_b<parameters42.txt>$DATA/temporal-sim/Res42b &
./temporal_run_b<parameters43.txt>$DATA/temporal-sim/Res43b &
./temporal_run_b<parameters44.txt>$DATA/temporal-sim/Res44b &
./temporal_run_b<parameters45.txt>$DATA/temporal-sim/Res45b &
./temporal_run_b<parameters46.txt>$DATA/temporal-sim/Res46b &
./temporal_run_b<parameters47.txt>$DATA/temporal-sim/Res47b &
./temporal_run_b<parameters48.txt>$DATA/temporal-sim/Res48b &
./temporal_run_b<parameters49.txt>$DATA/temporal-sim/Res49b &
./temporal_run_b<parameters50.txt>$DATA/temporal-sim/Res50b &
./temporal_run_b<parameters51.txt>$DATA/temporal-sim/Res51b &
./temporal_run_b<parameters52.txt>$DATA/temporal-sim/Res52b &
./temporal_run_b<parameters53.txt>$DATA/temporal-sim/Res53b &
./temporal_run_b<parameters54.txt>$DATA/temporal-sim/Res54b &
./temporal_run_b<parameters55.txt>$DATA/temporal-sim/Res55b &
./temporal_run_b<parameters56.txt>$DATA/temporal-sim/Res56b &
./temporal_run_b<parameters57.txt>$DATA/temporal-sim/Res57b &
./temporal_run_b<parameters58.txt>$DATA/temporal-sim/Res58b &
./temporal_run_b<parameters59.txt>$DATA/temporal-sim/Res59b &
./temporal_run_b<parameters60.txt>$DATA/temporal-sim/Res60b &
./temporal_run_b<parameters61.txt>$DATA/temporal-sim/Res61b &
./temporal_run_b<parameters62.txt>$DATA/temporal-sim/Res62b &
./temporal_run_b<parameters63.txt>$DATA/temporal-sim/Res63b
./temporal_run_b<parameters64.txt>$DATA/temporal-sim/Res64b
