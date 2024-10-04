#include <iostream>
#include <random>
#include <chrono>
#include <sstream>
#include "convolution.h"

using std::chrono::duration;
using std::chrono::high_resolution_clock;

int main(int argc, char *argv[])
{
     if (argc != 3){
        std::cout << "Usage: ./task1 <n> <m>" << std::endl;
        return 1;
    }

    std::size_t n = std::atoi(argv[1]);
    std::size_t m = std::atoi(argv[2]);

    if (n <= 0 || m <= 0) {
        std::cout << "n and m must be positive integers." << std::endl;
        return 1;
    }

    std::random_device entropy_source;
    std::mt19937_64 generator(entropy_source());
    std::uniform_real_distribution<float> img_dist(-10., 10.);
    std::uniform_real_distribution<float> mask_dist(-1., 1.);

    // Allocate memory for arrays
    float *image = new float[n * n];
    float *output = new float[n * n];
    float *mask = new float[m * m];

    // Generate random numbers and populate the arrays
    for (std::size_t i = 0; i < n * n; ++i)
    {
        image[i] = img_dist(generator);
    }
    for (std::size_t i = 0; i < m * m; ++i)
    {
        mask[i] = mask_dist(generator);
    }

    // Test Input
    // float image[4*4] = {
    //     1,3,4,8,
    //     6,5,2,4,
    //     3,4,6,8,
    //     1,4,5,2
    // };

    // float mask[3*3] = {
    //     0,0,1,
    //     0,1,0,
    //     1,0,0
    // };

    // Timing the scan operation
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;
    duration<double, std::milli> duration_millis;

    start = high_resolution_clock::now();
    convolve(image, output, n, mask, m);
    end = high_resolution_clock::now();

    // Calculate duration in milliseconds and print tim
    duration_millis = std::chrono::duration_cast<duration<double, std::milli>>(end - start);
    std::cout << duration_millis.count() << std::endl;

    // Print the first and last elements of the output array
    std::cout << output[0] << std::endl;
    std::cout << output[n * n - 1] << std::endl;

    //  Print input matrix
    // std::cout << "Input Matrix:" << std::endl;
    // for (std::size_t i = 0; i < n; ++i)
    // {
    //     for (std::size_t j = 0; j < n; ++j)
    //     {
    //         std::cout << image[i * n + j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    //  Print mask
    // std::cout << "Mask:" << std::endl;
    // for (std::size_t i = 0; i < m; ++i)
    // {
    //     for (std::size_t j = 0; j < m; ++j)
    //     {
    //         std::cout << mask[i * m + j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    //  Print matrix output
    // std::cout << "Output Matrix:" << std::endl;
    // for (std::size_t i = 0; i < n; ++i)
    // {
    //     for (std::size_t j = 0; j < n; ++j)
    //     {
    //         std::cout << output[i * n + j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // Deallocate memory
    delete[] image;
    delete[] output;
    delete[] mask;

    return 0;
}