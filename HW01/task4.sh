#!/bin/bash

#SBATCH --job-name=FirstSlurm       # Job name
#SBATCH --ntasks=1                  # Run on a single CPU task
#SBATCH --cpus-per-task=2           # Ask for 2 CPU cores
#SBATCH --output=FirstSlurm.out      # Standard output file
#SBATCH --error=FirstSlurm.err       # Standard error file

# Print the hostname of the compute node running the job
hostname
