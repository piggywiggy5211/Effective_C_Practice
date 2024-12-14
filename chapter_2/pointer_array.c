#include <stdio.h>


void just_print_array(int (*arr)[], int n) {
    printf("array's elements:    ");
    for (int i = 0; i < n - 1; ++i) {
        printf("%d ", (*arr)[i]);
    }
    printf("%d\n", (*arr)[n - 1]);
}


void print_array_and_change_element_position_1_variant_1(int arr[], int n) {

    printf("---------print && change array variant 1---------\n"
           "array reference to memory with \"&\":    %p\n"
           "array reference to memory without \"&\":    %p\n"
           "array 1 element reference to memory with \"&\":    %p\n"
           "array 1 element reference to memory without \"&\":    %p\n"
           "array's elements:    ",
           &arr, arr, &arr[1], (arr + 1)
    );
    arr[1] = 1;
    for (int i = 0; i < n - 1; ++i) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[n - 1]);
}

void print_array_and_change_element_position_2_variant_2(int (*arr)[], int n) {
    printf("---------print && change array variant 2---------\n"
           "array reference to memory:    %p\n"
           "array 1 element reference to memory:    %p\n"
           "array's elements:    ",
           arr,  ((*arr) + 1)
    );
    (*arr)[2] = 2;
    for (int i = 0; i < n - 1; ++i) {
        printf("%d ", (*arr)[i]);
    }
    printf("%d\n", (*arr)[n - 1]);
}

void print_array_and_change_element_position_3_variant_3(int *start_seq, int n) {
    printf("---------print && change array variant 3---------\n"
           "array reference to memory:    %p\n"
           "array 1 element reference to memory:    %p\n"
           "array's elements:    ",
           start_seq, (start_seq + 1)
    );
    *(start_seq + 2) = 3;
    for (int i = 0; i < n - 1; ++i) {
        printf("%d ", *(start_seq + i));
    }
    printf("%d\n", start_seq[n - 1]);
}


int main(void) {

    printf("------\nchange array elements in different way \n------\n");

    char str[] = "test_string";
    printf("str = %s\n", str);

    // change first element [0]
    str[0] = '1';
    printf("str = %s\n", str);

    // change first element [0]
    *str = '2';
    printf("str = %s\n", str);

    // change second element [1]
    *(str + 1) = '3';
    printf("str = %s\n", str);

    // get address of element
    char *first_element_pointer_type0 = str;
    char *first_element_pointer_type1 = str + 0;
    char *first_element_pointer_type2 = &str[0];
    printf(
            "first_element_pointer_type0 (str) = %p\n"
            "first_element_pointer_type1 (str + 0) = %p\n"
            "first_element_pointer_type2 (&str[0]) = %p\n",
            first_element_pointer_type0, first_element_pointer_type1, first_element_pointer_type2
    );


    printf("\n\n------\npass array to function \n------\n");

    int array[] = {99, 99 ,99, 99, 99, 99};
    int number_elements = sizeof(array) / sizeof(int);

    printf("---------main  array---------\n");
    printf("array reference to memory:    %p\n", &array);
    just_print_array(&array, number_elements);
    printf("\n");


    print_array_and_change_element_position_1_variant_1(array, number_elements);
    print_array_and_change_element_position_2_variant_2(&array, number_elements);
    print_array_and_change_element_position_3_variant_3(array, number_elements);


    printf("\n---------main  array---------\n");
    printf("array reference to memory:    %p\n", &array);
    just_print_array(&array, number_elements);
}
