#!/bin/bash

WIDTH=1000
HEIGHT=1000
ITERATIONS=1000

for n in {1..64}; do
  sbatch --exclusive work1.sh ${n} ${WIDTH} ${HEIGHT} ${ITERATIONS}
done
