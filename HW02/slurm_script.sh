#!/usr/bin/env zsh
#SBATCH --job-name=hw2_nakshatri
#SBATCH --partition=instruction
#SBATCH --time=00-00:30:00
# SBATCH --ntasks=2
#SBATCH --cpus-per-task=2
# SBATCH --nodes=3
# SBATCH --array=0-3
#SBATCH -o hw2.out -e hw2.err

echo "Running task1"
g++ scan.cpp task1.cpp -Wall -O3 -std=c++17 -o task1
./task1 0
./task1 100

echo "Running task2"
g++ convolution.cpp task2.cpp -Wall -O3 -std=c++17 -o task2
./task2 100 5

echo "Running task3"
g++ task3.cpp matmul.cpp -Wall -O3 -std=c++17 -o task3
./task3
./task3 1000
