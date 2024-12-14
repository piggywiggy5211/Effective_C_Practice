#include <stdio.h>
#include <stdlib.h>

int do_something(void) {
    FILE *file1, *file2;
//    object_t *obj;
    char* obj;
    int ret_val = 0;

    file1 = fopen("a_file", "w");
    if (file1 == NULL) {
        ret_val = -1;
        goto FAIL_FILE1;
    }
    file2 = fopen("another_file", "w");
    if (file2 == NULL) {
        ret_val = -2;
        goto FAIL_FILE2;
    }

    obj = malloc(sizeof(char));
    if (obj == NULL) {
        ret_val = -3;
        goto FAIL_OBJ;
    }

    free(obj);
FAIL_OBJ:
    fclose(file2);
FAIL_FILE2:
    fclose(file1);
FAIL_FILE1:
    return ret_val;
}

const char* get_error_message(int error_code) {
    switch (error_code) {
        case -1: return "Failed to open file1";
        case -2: return "Failed to open file2";
        case -3: return "Failed to allocate memory for object char";
        default: return "Unknown error";
    }
}

int main(void) {
    int result = do_something();
    if (result < 0) {
        printf("Error: %s\n", get_error_message(result));
    }
    return 0;
}