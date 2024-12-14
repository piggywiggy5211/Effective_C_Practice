

#include <stdio.h>

unsigned int* increment(void) {
    static unsigned int counter = 0;
    counter++;
    return &counter;
}

unsigned int retrieve(unsigned int const* pi) {
    return *pi;
}

int main(void) {
    for (int i = 0; i < 5; ++i) {
        unsigned int current_value = retrieve(increment());
        printf("%d ", current_value);
    }
    return 0;
}