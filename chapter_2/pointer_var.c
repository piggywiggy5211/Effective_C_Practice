#include <stdio.h>
#include <stdlib.h>

void swap(int *pa, int *pb) {
    int t = *pa;
    *pa = *pb;
    *pb = t;
}

void print_array(int (*arr)[], int n) {
    printf(
           "array reference to memory:    %p\n"
           "array's elements:    ",
           arr
    );
    for (int i = 0; i < n - 1; ++i) {
        printf("%d ", (*arr)[i]);
    }
    printf("%d\n", (*arr)[n - 1]);
}


int comparator(const void *vpa, const void *vpb) {
    return ( *(int *)vpa - *(int *)vpb);
    //       ^   ^   ^
    //       |   |   void point on var "a"
    //       |   type casting to int pointer
    //       dereference int pointer that to get value
    // OR
    // It is equivalent to that code:
//    // type casting
//    int *ipa = (int *) vpa;
//    int *ipb = (int *) vpb;
//    // get value
//    int value_a = *ipa;
//    int value_b = *ipb;
//    return value_a - value_b;
}

int main(void) {
    printf("\n\n------\nswap value of two variables\n------\n");

    int a = 21;
    int b = 17;

    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);


    printf("\n\n------\nqsort implementation comparator\n------\n");

    int array[] = {99, 11, 444, 0, 5, 2, 7, 1};
//    int number_elements_diff = sizeof(array) / sizeof(int);
// OR
    int number_elements = sizeof(array) / sizeof(array[0]);


    printf("main array reference to memory:    %p\n", &array);
    printf("---------main  array---------\n");
    print_array(&array, number_elements);

//    qsort((void *) &array, number_elements, sizeof(array[0]), comparator);
// OR
    qsort(array, number_elements, sizeof(array[0]), comparator);

    printf("---------sort  array---------\n");
    print_array(&array, number_elements);

    return 0;
}
