#include <iostream>
#include <random>
#include <chrono>
#include <cstdlib>
#include "msort.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <array_size> <num_threads> <threshold>" << std::endl;
        return 1;
    }

    std::size_t n = std::atoi(argv[1]);  
    int num_threads = std::atoi(argv[2]);  
    std::size_t threshold = std::atoi(argv[3]); 

    omp_set_num_threads(num_threads);

    std::random_device entropy_source;
    std::mt19937_64 generator(entropy_source());
    std::uniform_int_distribution<int> dist(-1000, 1000);

    int *arr = new int[n];

    for (std::size_t i = 0; i < n; ++i) {
        arr[i] = dist(generator);
    }

    auto start_time = std::chrono::high_resolution_clock::now();
    msort(arr, n, threshold); 
    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end_time - start_time;

    // Outputs
    std::cout << arr[0] << std::endl;
    std::cout << arr[n - 1] << std::endl;

    std::cout << duration.count() << std::endl;

    delete[] arr;

    return 0;
}
