#!/usr/bin/env bash
#SBATCH --job-name=hw3_task1          # Job name
#SBATCH --partition=instruction        # Partition (queue) name
#SBATCH --time=00:30:00                # Run time (hh:mm:ss)
#SBATCH --cpus-per-task=20             # Request 20 threads (OpenMP will use this)
#SBATCH --nodes=1                      # Run on a single node
#SBATCH --output=task1_output.out      # Standard output log
#SBATCH --error=task1_error.err        # Standard error log

# Print task details
echo "Running task1 for matrix multiplication using OpenMP"

# Compile the program with OpenMP flag enabled
g++ task1.cpp matmul.cpp -Wall -O3 -std=c++17 -fopenmp -o task1

# Run task1 with n=1024 and t=1, 2, ..., 20
for t in {1..20}; do
    echo "Running with t=$t threads"
    ./task1 1024 $t
done
