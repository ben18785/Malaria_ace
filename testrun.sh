#!/bin/bash

#PBS -V
#PBS -l select=1
#PBS -l walltime=0:20:00
#PBS -N SprDiffA

cd ./spatial

./run>$DATA/spatial-sim/Res1
