#!/usr/bin/env zsh

#SBATCH --job-name=FirstSlurm       # Job name
#SBATCH --cpus-per-task=2           # Ask for 2 CPU cores
#SBATCH --output=FirstSlurm.out      # Standard output file
#SBATCH --error=FirstSlurm.err       # Standard error file
#SBATCH --partition=instruction

echo $SLURMD_NODENAME
