#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int absolute_value(int a, bool *is_error) {
    if (a == INT_MIN) {
        *is_error = true;
        return 0;
    }

    if (a < 0) {
        return -a;
    }
    return a;
}

void pprint( int  *val,  int *val_abs,   bool *is_error) {
    if (!*is_error) {
        printf("val = %d    val_abs = %d\n", *val, *val_abs);
    } else {
        printf("val = %d    error INT OVERFLOW\n", *val);
    }
}

int main(void) {

    bool is_error = false;
    int val_negative = -5;
    int val_abs = absolute_value(val_negative, &is_error);
    pprint(&val_negative, &val_abs, &is_error);


    bool is_error2 = false;
    int val_negative2 = INT_MIN;
    int val_abs2 = absolute_value(val_negative2, &is_error2);
    pprint(&val_negative2, &val_abs2, &is_error2);

    return 0;
}