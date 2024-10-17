#!/usr/bin/env bash
#SBATCH --job-name=hw3_task2          # Job name
#SBATCH --partition=instruction        # Partition (queue) name
#SBATCH --time=00:30:00                # Run time (hh:mm:ss)
#SBATCH --cpus-per-task=20             # Request 20 threads (OpenMP will use this)
#SBATCH --nodes=1                      # Run on a single node
#SBATCH --output=task2_output.out      # Standard output log
#SBATCH --error=task2_error.err        # Standard error log

echo "Running task2 for convolution using OpenMP"

g++ task2.cpp convolution.cpp -Wall -O3 -std=c++17 -fopenmp -o task2

# Run task2 with n=1024 and t=1, 2, ..., 20
for t in {1..20}; do
    echo "Running with t=$t threads"
    ./task2 1024 $t
done
