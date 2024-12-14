#include <stdio.h>

// declaring function
int add(int a, int b);

// body declaring function
int add(int a, int b){
    return a + b;
}


int main() {
    // Assigning function address
    int (*add_p1)(int, int) = &add;
    // or
    // take function address without &
    int (*add_p2)(int, int) = add;


    // The function name "add" points to the starting address of the code being executed, like the name of an array pointing to its first element.
    // However, there are coding conventions that say that a call through a function pointer should use the dereference operator *, i.e. (*add_p1)(1, 2),
    //  and likewise that the assignment be written as *add_p1 = &sum;.
    int result_1_1 = add_p1(1, 2);
    int result_1_2 = (*add_p1)(1, 2);
    int result_2 = add_p2(2, 3);

    printf("result 1 1 = %d\n", result_1_1);
    printf("result 1 2 = %d\n", result_1_2);
    printf("result 2 = %d\n", result_2);



}