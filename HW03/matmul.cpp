// matmul.cpp

#include <cstddef>
#include <omp.h>
#include "matmul.h"

// Parallel matrix multiplication: C = A * B
void mmul(const float* A, const float* B, float* C, const std::size_t n) {
    // Initialize the output matrix C to 0
    #pragma omp parallel for
    for (std::size_t i = 0; i < n; i++) {
        for (std::size_t j = 0; j < n; j++) {
            C[i * n + j] = 0.0;
        }
    }

    // Perform matrix multiplication C = A * B using OpenMP for parallelization
    #pragma omp parallel for
    for (std::size_t i = 0; i < n; i++) {
        for (std::size_t k = 0; k < n; k++) {
            for (std::size_t j = 0; j < n; j++) {
                C[i * n + j] += A[i * n + k] * B[k * n + j];
            }
        }
    }
}
