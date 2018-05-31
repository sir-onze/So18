#ifndef ARRAY_H_
#define ARRAY_H_

typedef struct array_data * CMD_ARRAY;

CMD_ARRAY init_cmd_array();
void load_cmd_array();
int add_element(CMD_ARRAY array, int number);
int get_element(CMD_ARRAY array, int index);

#endif
