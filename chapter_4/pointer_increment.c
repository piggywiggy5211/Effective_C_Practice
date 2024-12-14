#include <stdio.h>
#include <stdlib.h>


typedef struct char_array char_array;

char *convert_array_int_to_char(const int *arr, int size) {
    // (size + 1) is size of char array and "+1" needed for null terminator.
    char *char_array = (char *) malloc((size*11 + 1) * sizeof(char));

    if (char_array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int offset = 0; // Keep track of the offset in the
    for (int i = 0; i < size; i++) {
        int a = arr[i];
        int written = sprintf(char_array + offset, "%d", a);
        offset += written;
        if (i < size - 1){
            char_array[offset++] = ',';
        }
    }


    return char_array;
}

int main(void) {
    int a[] = {10, 20, 30, 40};
    char* str_a = convert_array_int_to_char(a, sizeof(a) / sizeof(a[0]));
    printf("a[] = %s\n", str_a);
    free(str_a);

    int* p_a = a;
    printf("*p_a = %d\n", *p_a);
    printf("++*p_a = %d\n", ++*p_a);
    printf("*++p_a = %d\n", *++p_a);
    printf("*(++p_a) = %d\n", *(++p_a));


    int b[] = {10, 20, 30, 40};
    char* str_b = convert_array_int_to_char(b, sizeof(b) / sizeof(b[0]));
    printf("\nb[] = %s\n", str_b);
    free(str_b);

    int *p_b = b;
    printf("*p_b = %d\n", *p_b);

    printf("*p_b++ = %d\n", *p_b++);
    printf("*p_b = %d  // after *p_b++\n", *p_b);

    printf("(*p_b)++ = %d\n", (*p_b)++);
    printf("*p_b = %d  // after (*p_b)++\n", *p_b);

    printf("*(p_b++) = %d\n", *(p_b++));
    printf("*p_b = %d // after *(p_b++)\n", *p_b);

    return 0;
}
