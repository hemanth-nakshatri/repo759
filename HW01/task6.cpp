#include <iostream>
#include <cstdio>
#include <cstdlib>

int main(int argc, char* argv[]){
    // Check if user provided the required command line arguments
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " Missing input N" << std::endl;
        return 1;
    }

    // Convert command line argument to a integer
    int N = std::atoi(argv[1]);

    // Print integers from 0 to N using printf
    for (int i =0; i <= N; i++){
        printf("%d ", i);
    }
    printf("\n");

    //  Print integers from N to 0 using std::cout
    for (int i = N; i >= 0; i--){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}