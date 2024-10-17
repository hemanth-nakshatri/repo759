#!/usr/bin/env bash
#SBATCH --job-name=hw3_task3_final     # Job name
#SBATCH --partition=instruction        # Partition (queue) name
#SBATCH --time=01:00:00                # Run time (hh:mm:ss)
#SBATCH --cpus-per-task=20             # Request 20 threads
#SBATCH --nodes=1                      # Run on a single node
#SBATCH --output=task3_final_output.out  # Standard output log
#SBATCH --error=task3_final_error.err  # Standard error log

echo "Running task3 for parallel merge sort with ts=32 using OpenMP"

g++ task3.cpp msort.cpp -Wall -O3 -std=c++17 -fopenmp -o task3

# Run task3 with ts=32 (2^5) for t=1 to t=20 threads
for t in {1..20}; do
    echo "Running with t=$t threads and ts=32"
    ./task3 1000000 $t 128  # Sorting array of size 1,000,000 with ts=32
done
