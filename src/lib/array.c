
#include "array.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

struct array_data {
    int *pointer;
    int counter;
    int size;
};

CMD_ARRAY init_cmd_array() {
	CMD_ARRAY new_array = malloc(sizeof(CMD_ARRAY));
	new_array->pointer = calloc(1000, sizeof(int));
	new_array->size = 1000;
	new_array->counter = 0;
	return new_array;
}

void resize_array(CMD_ARRAY array) {
	int new_size = (array->size * sizeof(int)) * 2;
	array->pointer = realloc(array->pointer, new_size);
	fflush (stdout);
	array->size *= 2;  // This is the number of elements, don't multiply by sizeof
}

int add_element(CMD_ARRAY array, int number) {
	if (array->counter >= array->size) {
		resize_array(array);
	}
    *(array->pointer + array->counter) = number;  // Pointer arithmetic
	array->counter += 1;

	return 0;
}

int get_element(CMD_ARRAY array, int index) {
	if (array->counter >= array->size) {
		return -1;
	}
    int *data = array->pointer + index;

    return *data;
}

void load_cmd_array(){

}
