#include <stdio.h>


int main(void) {
    // char string
    char str[11];
    for (unsigned int i = 0; i < 10; ++i) {
        str[i] = '0' + i;
    }
    printf("without '\\0' str = %s", str);
    str[10] = '\0';
    printf("with '\\0' str = %s", str);

    return 0;
}
