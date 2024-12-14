#include <stdio.h>

unsigned long long tail_factorial( int depth, unsigned long long accumulator) {
    if (depth == 0) {
        return accumulator;
    }
    return tail_factorial(depth-1, depth * accumulator);
}


unsigned long long common_factorial(int depth) {
    if (depth == 0) {
        return 1;
    }
    return depth * common_factorial(depth-1);
}

int main() {
    int depth = 20; // 20 is max for 64-bit system

    unsigned long long tail_result = tail_factorial(depth, 1);
    printf("Tail-Factorial of %d result = %llu \n", depth, tail_result);

    unsigned long long common_result = common_factorial(depth);
    printf("Common-Factorial of %d result = %llu \n", depth, common_result);
}