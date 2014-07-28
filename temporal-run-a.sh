#!/bin/bash

#PBS -V
#PBS -l nodes=4:ppn=16
#PBS -l walltime=8:00:00
#PBS -N SprDiffA

cd ./spatial

./temporal_run_a<parameters1.txt>$DATA/temporal-sim/Res1a & 
./temporal_run_a<parameters2.txt>$DATA/temporal-sim/Res2a & 
./temporal_run_a<parameters3.txt>$DATA/temporal-sim/Res3a & 
./temporal_run_a<parameters4.txt>$DATA/temporal-sim/Res4a & 
./temporal_run_a<parameters5.txt>$DATA/temporal-sim/Res5a & 
./temporal_run_a<parameters6.txt>$DATA/temporal-sim/Res6a & 
./temporal_run_a<parameters7.txt>$DATA/temporal-sim/Res7a & 
./temporal_run_a<parameters8.txt>$DATA/temporal-sim/Res8a & 
./temporal_run_a<parameters9.txt>$DATA/temporal-sim/Res9a & 
./temporal_run_a<parameters10.txt>$DATA/temporal-sim/Res10a & 
./temporal_run_a<parameters11.txt>$DATA/temporal-sim/Res11a & 
./temporal_run_a<parameters12.txt>$DATA/temporal-sim/Res12a & 
./temporal_run_a<parameters13.txt>$DATA/temporal-sim/Res13a & 
./temporal_run_a<parameters14.txt>$DATA/temporal-sim/Res14a & 
./temporal_run_a<parameters15.txt>$DATA/temporal-sim/Res15a & 
./temporal_run_a<parameters16.txt>$DATA/temporal-sim/Res16a & 
./temporal_run_a<parameters17.txt>$DATA/temporal-sim/Res17a & 
./temporal_run_a<parameters18.txt>$DATA/temporal-sim/Res18a & 
./temporal_run_a<parameters19.txt>$DATA/temporal-sim/Res19a & 
./temporal_run_a<parameters20.txt>$DATA/temporal-sim/Res20a & 
./temporal_run_a<parameters21.txt>$DATA/temporal-sim/Res21a & 
./temporal_run_a<parameters22.txt>$DATA/temporal-sim/Res22a &
./temporal_run_a<parameters23.txt>$DATA/temporal-sim/Res23a &
./temporal_run_a<parameters24.txt>$DATA/temporal-sim/Res24a &
./temporal_run_a<parameters25.txt>$DATA/temporal-sim/Res25a &
./temporal_run_a<parameters26.txt>$DATA/temporal-sim/Res26a &
./temporal_run_a<parameters27.txt>$DATA/temporal-sim/Res27a &
./temporal_run_a<parameters28.txt>$DATA/temporal-sim/Res28a &
./temporal_run_a<parameters29.txt>$DATA/temporal-sim/Res29a &
./temporal_run_a<parameters30.txt>$DATA/temporal-sim/Res30a &
./temporal_run_a<parameters31.txt>$DATA/temporal-sim/Res31a &
./temporal_run_a<parameters32.txt>$DATA/temporal-sim/Res32a &
./temporal_run_a<parameters33.txt>$DATA/temporal-sim/Res33a &
./temporal_run_a<parameters34.txt>$DATA/temporal-sim/Res34a &
./temporal_run_a<parameters35.txt>$DATA/temporal-sim/Res35a &
./temporal_run_a<parameters36.txt>$DATA/temporal-sim/Res36a &
./temporal_run_a<parameters37.txt>$DATA/temporal-sim/Res37a &
./temporal_run_a<parameters38.txt>$DATA/temporal-sim/Res38a &
./temporal_run_a<parameters39.txt>$DATA/temporal-sim/Res39a &
./temporal_run_a<parameters40.txt>$DATA/temporal-sim/Res40a &
./temporal_run_a<parameters41.txt>$DATA/temporal-sim/Res41a &
./temporal_run_a<parameters42.txt>$DATA/temporal-sim/Res42a &
./temporal_run_a<parameters43.txt>$DATA/temporal-sim/Res43a &
./temporal_run_a<parameters44.txt>$DATA/temporal-sim/Res44a &
./temporal_run_a<parameters45.txt>$DATA/temporal-sim/Res45a &
./temporal_run_a<parameters46.txt>$DATA/temporal-sim/Res46a &
./temporal_run_a<parameters47.txt>$DATA/temporal-sim/Res47a &
./temporal_run_a<parameters48.txt>$DATA/temporal-sim/Res48a &
./temporal_run_a<parameters49.txt>$DATA/temporal-sim/Res49a &
./temporal_run_a<parameters50.txt>$DATA/temporal-sim/Res50a &
./temporal_run_a<parameters51.txt>$DATA/temporal-sim/Res51a &
./temporal_run_a<parameters52.txt>$DATA/temporal-sim/Res52a &
./temporal_run_a<parameters53.txt>$DATA/temporal-sim/Res53a &
./temporal_run_a<parameters54.txt>$DATA/temporal-sim/Res54a &
./temporal_run_a<parameters55.txt>$DATA/temporal-sim/Res55a &
./temporal_run_a<parameters56.txt>$DATA/temporal-sim/Res56a &
./temporal_run_a<parameters57.txt>$DATA/temporal-sim/Res57a &
./temporal_run_a<parameters58.txt>$DATA/temporal-sim/Res58a &
./temporal_run_a<parameters59.txt>$DATA/temporal-sim/Res59a &
./temporal_run_a<parameters60.txt>$DATA/temporal-sim/Res60a &
./temporal_run_a<parameters61.txt>$DATA/temporal-sim/Res61a &
./temporal_run_a<parameters62.txt>$DATA/temporal-sim/Res62a &
./temporal_run_a<parameters63.txt>$DATA/temporal-sim/Res63a
./temporal_run_a<parameters64.txt>$DATA/temporal-sim/Res64a
