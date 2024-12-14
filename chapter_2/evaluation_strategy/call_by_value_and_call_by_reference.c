#include <stdio.h>

void add_one(int a) {
    printf(" mem reference inside function add_one  a = %p\n", &a);
    a = a + 1;
}

void add_two(int *pb) {
    printf(" mem reference inside function add_two  b = %p\n", pb);
    *pb = *pb + 2;
}

int main(void) {
    //    call by value
    int a = 17;
    printf("mem reference a= %p\n", &a);
    printf("before call add_one  a= %d\n", a);
    add_one(a);
    printf("after call add_one  a= %d\n", a);

    //    call by reference
    int b = 21;
    printf("mem reference  b = %p\n", &b);
    printf("before call add_two  b = %d\n", b);
    add_two(&b);
    printf("after call add_two  b = %d\n", b);
}