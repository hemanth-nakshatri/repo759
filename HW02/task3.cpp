#include <iostream>
#include <vector>
#include <sstream>
#include "matmul.h"
#include <random>
#include <chrono>


using std::chrono::duration;
using std::chrono::high_resolution_clock;

int main(int argc, char *argv[])
{
  // Arbitrary default value if no n is passed
  unsigned int n = 1024;

  // Read n if passed through command line
  if (argc > 1)
  {
    std::stringstream sstream(argv[1]);
    sstream >> n;
  }

  if (n < 1000)
  {
    std::cout << "n must be >= 1000 according to the PDF?" << std::endl;
  }

  std::random_device entropy_source;
  std::mt19937_64 generator(entropy_source());
  std::uniform_real_distribution<double> dist(-10., 10.);

  double *A = new double[n * n];
  double *B = new double[n * n];
  double *C = new double[n * n];
  std::vector<double> A_vector(n * n);
  std::vector<double> B_vector(n * n);

  // Generate random numbers and populate the arrays
  for (unsigned int i = 0; i < n * n; ++i)
  {
    A_vector[i] = A[i] = dist(generator);
    B_vector[i] = B[i] = dist(generator);
  }

  std::cout << n << std::endl;
  for (int mmul_func = 1; mmul_func <= 4; ++mmul_func)
  {
    for (unsigned int i = 0; i < n * n; i++)
    {
      C[i] = 0;
    }

    auto start = high_resolution_clock::now();

    switch (mmul_func)
    {
    case 1:
      mmul1(A, B, C, n);
      break;
    case 2:
      mmul2(A, B, C, n);
      break;
    case 3:
      mmul3(A, B, C, n);
      break;
    case 4:
      mmul4(A_vector, B_vector, C, n);
      break;
    default:
      std::cout << "No such mmul function. Check again" << std::endl;
      // Deallocate memory
      delete[] A;
      delete[] B;
      delete[] C;
      return 1;
    }

    auto end = high_resolution_clock::now();

    // Calculate duration in milliseconds and print tim
    auto duration_millis = std::chrono::duration_cast<duration<double, std::milli>>(end - start);
    std::cout << duration_millis.count() << std::endl;

    // Print last element of C
    std::cout << C[n * n - 1] << std::endl;

    //  Print matrix output
    // std::cout << "Output Matrix:" << std::endl;
    // for (std::size_t i = 0; i < n; ++i)
    // {
    //     for (std::size_t j = 0; j < n; ++j)
    //     {
    //         std::cout << C[i * n + j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
  }

  // Deallocate memory
  delete[] A;
  delete[] B;
  delete[] C;

  return 0;
}
