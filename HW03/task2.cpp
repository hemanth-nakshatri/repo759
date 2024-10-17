#include <iostream>
#include <random>
#include <chrono>
#include <cstdlib>
#include "convolution.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <matrix_size> <num_threads>" << std::endl;
        return 1;
    }

    std::size_t n = std::atoi(argv[1]);
    int num_threads = std::atoi(argv[2]);  

    std::size_t m = 3; 

    omp_set_num_threads(num_threads);

    std::random_device entropy_source;
    std::mt19937_64 generator(entropy_source());
    std::uniform_real_distribution<float> img_dist(-10.0, 10.0);
    std::uniform_real_distribution<float> mask_dist(-1.0, 1.0);

    // Allocate memory for arrays
    float *image = new float[n * n];
    float *output = new float[n * n];
    float *mask = new float[m * m];

    // Generate random numbers and populate the arrays
    for (std::size_t i = 0; i < n * n; ++i) {
        image[i] = img_dist(generator);
    }
    for (std::size_t i = 0; i < m * m; ++i) {
        mask[i] = mask_dist(generator);
    }

    auto start_time = std::chrono::high_resolution_clock::now();
    convolve(image, output, n, mask, m); 
    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end_time - start_time;

    // Output the first and last elements of the resulting output array
    std::cout << output[0] << std::endl;
    std::cout << output[n * n - 1] << std::endl;

    // Print the time taken
    std::cout << duration.count() << std::endl;

    // Free allocated memory
    delete[] image;
    delete[] output;
    delete[] mask;

    return 0;
}
