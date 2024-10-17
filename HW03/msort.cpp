#include "msort.h"
#include <algorithm>  // For std::sort
#include <iostream>
#include <cstring> 
void merge(int* arr, int* temp, std::size_t left, std::size_t mid, std::size_t right) {
    std::size_t i = left;
    std::size_t j = mid;
    std::size_t k = left;

    while (i < mid && j < right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i < mid) {
        temp[k++] = arr[i++];
    }

    while (j < right) {
        temp[k++] = arr[j++];
    }
    std::memcpy(arr + left, temp + left, (right - left) * sizeof(int));
}

void parallel_merge_sort(int* arr, int* temp, std::size_t left, std::size_t right, std::size_t threshold) {
    if (right - left <= threshold) {
        
        // If size is below threshold, use serial sorting (std::sort)
        std::sort(arr + left, arr + right);
        return;
    }

    std::size_t mid = left + (right - left) / 2;

    #pragma omp task shared(arr, temp) if (right - left > threshold)
    parallel_merge_sort(arr, temp, left, mid, threshold);

    #pragma omp task shared(arr, temp) if (right - left > threshold)
    parallel_merge_sort(arr, temp, mid, right, threshold);

    #pragma omp taskwait 

    merge(arr, temp, left, mid, right);
}

void msort(int* arr, const std::size_t n, const std::size_t threshold) {
    int* temp = new int[n];  // Temporary array for merging

    #pragma omp parallel
    {
        #pragma omp single
        parallel_merge_sort(arr, temp, 0, n, threshold);
    }

    delete[] temp;
}
