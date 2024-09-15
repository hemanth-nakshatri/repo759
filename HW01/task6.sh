#!/usr/bin/env zsh
#SBATCH --partition=instruction
#SBATCH --job-name=task6
#SBATCH --output=task6.out
#SBATCH --error=task6.err

# Send JOB ID to stderr so that resulting output will be clean
echo "Running Job ID: $SLURM_JOB_ID" 1>&2
g++ task6.cpp -Wall -O3 -std=c++17 -o task6 
./task6 5