#!/bin/bash

#PBS -V
#PBS -l nodes=1:ppn=32
#PBS -l walltime=0:20:00
#PBS -N SprDiffA

cd ./spatial

./run<parameters1.txt>$DATA/temporal-sim/Res1 & 
./run<parameters2.txt>$DATA/temporal-sim/Res2 & 
./run<parameters3.txt>$DATA/temporal-sim/Res3 & 
./run<parameters4.txt>$DATA/temporal-sim/Res4 & 
./run<parameters5.txt>$DATA/temporal-sim/Res5 & 
./run<parameters6.txt>$DATA/temporal-sim/Res6 & 
./run<parameters7.txt>$DATA/temporal-sim/Res7 & 
./run<parameters8.txt>$DATA/temporal-sim/Res8 & 
./run<parameters9.txt>$DATA/temporal-sim/Res9 & 
./run<parameters10.txt>$DATA/temporal-sim/Res10 & 
./run<parameters11.txt>$DATA/temporal-sim/Res11 & 
./run<parameters12.txt>$DATA/temporal-sim/Res12 & 
./run<parameters13.txt>$DATA/temporal-sim/Res13 & 
./run<parameters14.txt>$DATA/temporal-sim/Res14 & 
./run<parameters15.txt>$DATA/temporal-sim/Res15 & 
./run<parameters16.txt>$DATA/temporal-sim/Res16 & 
./run<parameters17.txt>$DATA/temporal-sim/Res17 & 
./run<parameters18.txt>$DATA/temporal-sim/Res18 & 
./run<parameters19.txt>$DATA/temporal-sim/Res19 & 
./run<parameters20.txt>$DATA/temporal-sim/Res20 & 
./run<parameters21.txt>$DATA/temporal-sim/Res21 & 
./run<parameters22.txt>$DATA/temporal-sim/Res22 &
./run<parameters23.txt>$DATA/temporal-sim/Res23 &
./run<parameters24.txt>$DATA/temporal-sim/Res24 &
./run<parameters25.txt>$DATA/temporal-sim/Res25 &
./run<parameters26.txt>$DATA/temporal-sim/Res26 &
./run<parameters27.txt>$DATA/temporal-sim/Res27 &
./run<parameters28.txt>$DATA/temporal-sim/Res28 &
./run<parameters29.txt>$DATA/temporal-sim/Res29 &
./run<parameters30.txt>$DATA/temporal-sim/Res30 &
./run<parameters31.txt>$DATA/temporal-sim/Res31
./run<parameters32.txt>$DATA/temporal-sim/Res32
