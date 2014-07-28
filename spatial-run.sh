#!/bin/bash

#PBS -V
#PBS -l nodes=2:ppn=16
#PBS -l walltime=0:20:00
#PBS -N SprDiffA

cd ./spatial

./spatial-run<spatial-parameters1.txt>$DATA/spatial-sim/Res1 & 
./spatial-run<spatial-parameters2.txt>$DATA/spatial-sim/Res2 & 
./spatial-run<spatial-parameters3.txt>$DATA/spatial-sim/Res3 & 
./spatial-run<spatial-parameters4.txt>$DATA/spatial-sim/Res4 & 
./spatial-run<spatial-parameters5.txt>$DATA/spatial-sim/Res5 & 
./spatial-run<spatial-parameters6.txt>$DATA/spatial-sim/Res6 & 
./spatial-run<spatial-parameters7.txt>$DATA/spatial-sim/Res7 & 
./spatial-run<spatial-parameters8.txt>$DATA/spatial-sim/Res8 & 
./spatial-run<spatial-parameters9.txt>$DATA/spatial-sim/Res9 & 
./spatial-run<spatial-parameters10.txt>$DATA/spatial-sim/Res10 & 
./spatial-run<spatial-parameters11.txt>$DATA/spatial-sim/Res11 & 
./spatial-run<spatial-parameters12.txt>$DATA/spatial-sim/Res12 & 
./spatial-run<spatial-parameters13.txt>$DATA/spatial-sim/Res13 & 
./spatial-run<spatial-parameters14.txt>$DATA/spatial-sim/Res14 & 
./spatial-run<spatial-parameters15.txt>$DATA/spatial-sim/Res15 & 
./spatial-run<spatial-parameters16.txt>$DATA/spatial-sim/Res16 & 
./spatial-run<spatial-parameters17.txt>$DATA/spatial-sim/Res17 & 
./spatial-run<spatial-parameters18.txt>$DATA/spatial-sim/Res18 & 
./spatial-run<spatial-parameters19.txt>$DATA/spatial-sim/Res19 & 
./spatial-run<spatial-parameters20.txt>$DATA/spatial-sim/Res20 & 
./spatial-run<spatial-parameters21.txt>$DATA/spatial-sim/Res21 & 
./spatial-run<spatial-parameters22.txt>$DATA/spatial-sim/Res22 &
./spatial-run<spatial-parameters23.txt>$DATA/spatial-sim/Res23 &
./spatial-run<spatial-parameters24.txt>$DATA/spatial-sim/Res24 &
./spatial-run<spatial-parameters25.txt>$DATA/spatial-sim/Res25 &
./spatial-run<spatial-parameters26.txt>$DATA/spatial-sim/Res26 &
./spatial-run<spatial-parameters27.txt>$DATA/spatial-sim/Res27 &
./spatial-run<spatial-parameters28.txt>$DATA/spatial-sim/Res28 &
./spatial-run<spatial-parameters29.txt>$DATA/spatial-sim/Res29 &
./spatial-run<spatial-parameters30.txt>$DATA/spatial-sim/Res30 &
./spatial-run<spatial-parameters31.txt>$DATA/spatial-sim/Res31
./spatial-run<spatial-parameters32.txt>$DATA/spatial-sim/Res32
