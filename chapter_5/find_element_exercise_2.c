#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>

struct pos_key_in_array {
    size_t position;
    bool is_found;
};

typedef struct pos_key_in_array pos_key;

void find_element(size_t len, const int arr[len], int key, pos_key *result) {
    result->is_found = false;

    for (size_t i = 0; i < len; ++i) {
        if (arr[i] == key) {
            result->is_found = true;
            result->position = i;
            break;
        }
    }
}

pos_key *find_element_with_allocate_mem(size_t len, const int arr[len], int key) {

    pos_key *result = malloc(sizeof(pos_key));
    result->is_found = false;

    for (size_t i = 0; i < len; ++i) {
        if (arr[i] == key) {
            result->is_found = true;
            result->position = i;
            break;
        }
    }
    return result;
}

int main(void) {
    int array[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(array) / sizeof(array[0]);

    int key1 = 3;
    // you MUST free memory
    pos_key *position_key = find_element_with_allocate_mem(len, array, key1);
    if (position_key->is_found) {
        printf("Key %d found at position %zu\n", key1, position_key->position);
    } else {
        printf("Key %d not found\n", key1);
    }
    free(position_key);


    int key2 = 5;
    pos_key position_key2;
    pos_key *p_position_key2 = &position_key2;
    find_element(len, array, key2, p_position_key2);
    if (p_position_key2->is_found) {
        printf("Key %d found at position %zu\n", key2, p_position_key2->position);
    } else {
        printf("Key %d not found\n", key2);
    }

    return 0;
}