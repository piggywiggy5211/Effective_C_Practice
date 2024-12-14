#include <limits.h>
#include <stdio.h>

int main(void) {

    unsigned int ui = UINT_MAX;
    signed char c = -1;

    if (c == ui) {   // here, 2 typecasts will happen, "c" to (signed int) then to (unsigned int)
        puts("-1 equals UINT_MAX");
    }
    signed int si_1 = (signed int) -1;
    unsigned int usi_1= (unsigned int) si_1;     // is 4294967295

    signed int si_2 = (signed int) -2;
    unsigned int usi_2 = (unsigned int) si_2;    // is 4294967294
    return 0;
}