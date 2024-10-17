#!/usr/bin/env bash
#SBATCH --job-name=hw3_task3          # Job name
#SBATCH --partition=instruction        # Partition (queue) name
#SBATCH --time=01:00:00                # Run time (hh:mm:ss)
#SBATCH --cpus-per-task=20             # Request 20 threads (OpenMP will use this)
#SBATCH --nodes=1                      # Run on a single node
#SBATCH --output=task3_output.out      # Standard output log
#SBATCH --error=task3_error.err        # Standard error log

# Print task details
echo "Running task3 for parallel merge sort using OpenMP"

g++ task3.cpp msort.cpp -Wall -O3 -std=c++17 -fopenmp -o task3

for ts_exp in {1..10}; do
    ts=$((2 ** ts_exp))  # Compute 2^ts_exp
    for t in {1..20}; do
        echo "Running with t=$t threads and threshold=2^$ts_exp ($ts)"
        ./task3 1000000 $t $ts  # Sorting array of size 1,000,000
    done
done
