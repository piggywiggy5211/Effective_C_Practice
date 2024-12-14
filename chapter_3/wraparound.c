#include <stdio.h>
#include <limits.h>
#define Abs(i) ((i) < 0 ? -(i) : (i))

int main(void) {
// unsigned
    unsigned int ui = UINT_MAX;
    ui++;
    printf("ui = %u\n", ui);
    ui--;
    printf("ui = %u\n", ui);

// signed
    signed short int si = SHRT_MIN;
    printf("SHRT_MIN = %d\n", si);

    signed short int abs_si = Abs(si);
    printf("convert INT_MIN = %d\n", abs_si);

    return 0;
}
