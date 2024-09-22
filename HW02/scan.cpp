#include "scan.h"

void scan(const float *arr, float *output, std::size_t n)
{   
    if (n == 0)
    {
        return;
    }
    float temp = 0;

    // Perform the inclusive scan for the elements.
    for (int i = 0; i < n; i++)
    {
        temp += arr[i];
        output[i] = temp;
    }
}