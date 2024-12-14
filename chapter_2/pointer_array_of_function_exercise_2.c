#include <stdio.h>

//
// Created by piggywiggy on 28/12/23.
//
int fun_1(void) {
    printf("func 1 was run\n");
    return 1;
}

int fun_2(void) {
    printf("func 2 was run\n");
    return 2;
}

int fun_3(void) {
    printf("func 3 was run\n");
    return 3;
}

int main(void) {
    int (*array[])()= {&fun_1, &fun_2, &fun_3};
//   ^      ^       ^
//   |      |       - mean that It will be an executable pointers
//   |      - declare an array of pointers
//   = each executable element will return void type

    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
        int result = (*array[i])();
        printf("---- result = %d \n", result);
    }

    return 0;
}