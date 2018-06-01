
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "parser.h"
#include "array.h"

struct array_data {
    Command* pointer;
    int counter;
    int size;
};

int get_arraydate_counter(CMD_ARRAY arraydata){
    return arraydata->counter;
}

CMD_ARRAY init_cmd_array() {
	CMD_ARRAY new_array = malloc(sizeof(CMD_ARRAY));
	new_array->pointer = calloc(20, sizeof(Command));
	new_array->size = 20;
	new_array->counter = 0;
	return new_array;
}

void resize_array(CMD_ARRAY array) {
	int new_size = (array->size * sizeof(Command)) * 2;
	array->pointer = realloc(array->pointer, new_size);
	fflush (stdout);
	array->size *= 2;
}

int add_element(CMD_ARRAY array, Command cmd) {
	if (array->counter >= array->size) {
		resize_array(array);
	}
    *(array->pointer + array->counter) = cmd;
	array->counter += 1;

	return 0;
}

Command get_element(CMD_ARRAY array, int index) {
	if (array->counter >= array->size) {
		return NULL;
	}
    Command *data = array->pointer + index;

    return *data;
}

void load_cmd_array(CMD_ARRAY array, char* argv){
    notebook_parser(array, argv);
}
