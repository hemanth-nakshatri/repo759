#!/usr/bin/env zsh
#SBATCH --job-name=hw2
#SBATCH --partition=instruction
#SBATCH --time=00-00:30:00
# SBATCH --ntasks=1
#SBATCH --cpus-per-task=2
#SBATCH --output=scan_scaling.out
#SBATCH --error=scan_scaling.err

# Compile the C++ program (optional, if it's already compiled you can skip this step)
g++ scan.cpp task1.cpp -Wall -O3 -std=c++17 -o task1

# Loop through values of n from 2^10 to 2^30
for exp in {10..30}; do
    n=$((2**exp)) # Calculate n as 2^exp
    echo "Running task1 with n=$n"
    
    # Run the program with n and append the results to a file
    ./task1 $n >> scaling_results.txt >> ","
done
