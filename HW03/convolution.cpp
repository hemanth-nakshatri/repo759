#include "convolution.h"
#include <iostream>
#include <omp.h>

float get_pixel_val(const float *image, std::size_t n, std::size_t x, std::size_t y){
    int c1 = y >= 0 && y < n;
    int c2 = x >= 0 && x < n;
    int conditions_satisfied = c1 + c2;
    if (conditions_satisfied < 2) {
        return (float)conditions_satisfied;
    }
    else {
        return image[x * n + y];
    }
}

void convolve(const float *image, float *output, std::size_t n, const float *mask, std::size_t m)
{
    if (n == 0) return;

    #pragma omp parallel for // collapse(2) 
    for (std::size_t x = 0; x < n; x++) {
        for (std::size_t y = 0; y < n; y++) {
            float g = 0.0;

            for (std::size_t i = 0; i < m; i++) {
                for (std::size_t j = 0; j < m; j++) {
                    float w = mask[i * m + j];
                    float img_val = get_pixel_val(image, n, x + i - (m - 1) / 2, y + j - (m - 1) / 2);
                    g += w * img_val;
                }
            }
            output[x * n + y] = g;
        }
    }
}
