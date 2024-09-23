#include <iostream>
#include <random>
#include <chrono>
#include <sstream>
#include "scan.h"

using std::chrono::duration;
using std::chrono::high_resolution_clock;

int main(int argc, char *argv[])
{
    if (argc != 2){
        std::cout << "Usage: ./task1 <n>" << std::endl;
        return 1;
    }

    std::size_t n = std::atoi(argv[1]);

    if (n <= 0) {
        std::cout << "n must be a positive integer." << std::endl;
        return 1;
    }

    //  Seed random number generator
    std::random_device entropy_source;
    std::mt19937_64 generator(entropy_source());
    std::uniform_real_distribution<float> dist(-1., 1.);

    float *arr = new float[n];
    float *output = new float[n];

    // Create a random array
    for (std::size_t i = 0; i < n; i++) {
        arr[i] = dist(generator);
    }

    // Instantiate timing variables
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;
    duration<double, std::milli> duration_millis;

    start = high_resolution_clock::now();
    // Call Scan Function
    scan(arr, output, n);
    end = high_resolution_clock::now();

    duration_millis = std::chrono::duration_cast<duration<double, std::milli>>(end - start);

    //  Print out the time taken by the scan function
    std::cout << duration_millis.count() << std::endl;

    //  Print out the first and last elements of the output array
    std::cout << output[0] << std::endl;
    std::cout << output[n - 1] << std::endl;

    //  deallocate memory
    delete[] arr;
    delete[] output;

    return 0;

}