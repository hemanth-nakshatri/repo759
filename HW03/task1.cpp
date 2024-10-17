
#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <random>
#include "matmul.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <matrix_size> <num_threads>" << std::endl;
        return 1;
    }

    std::size_t n = std::atoi(argv[1]);
    int num_threads = std::atoi(argv[2]);

    // Set the number of threads for OpenMP
    omp_set_num_threads(num_threads);

    // Allocate memory for matrices A, B, and C
    float* A = new float[n * n];
    float* B = new float[n * n];
    float* C = new float[n * n];

    // Initialize random number generator
    std::random_device entropy_source;
    std::mt19937_64 generator(entropy_source());
    std::uniform_real_distribution<float> dist(-10.0, 10.0);

    // Initialize matrices A and B with random values using the new generator
    for (std::size_t i = 0; i < n * n; i++) {
        A[i] = dist(generator);
        B[i] = dist(generator);
    }

    // Measure the time taken by mmul
    double start_time = omp_get_wtime();
    mmul(A, B, C, n);  // Call the parallel matrix multiplication function
    double end_time = omp_get_wtime();

    // Output the first and last elements of the resulting matrix C
    std::cout << C[0] << std::endl;
    std::cout <<  C[n * n - 1] << std::endl;

    // Print the time taken in milliseconds
    std::cout << (end_time - start_time) * 1000.0 << std::endl;

    // Free allocated memory
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
