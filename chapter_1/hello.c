#include <stdio.h>
#include <stdlib.h>

int main(void) {
    if (puts("puts: Hello, world!") == EOF){
        return EXIT_FAILURE;
    }
    if (printf("%s\n", "printf: Hello, world!") < 0){
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}
