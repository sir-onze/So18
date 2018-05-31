#ifndef ARRAY_H_
#define ARRAY_H_

#include "command.h"

typedef struct array_data * CMD_ARRAY;

CMD_ARRAY init_cmd_array();
int add_element(CMD_ARRAY array, Command cmd);
Command get_element(CMD_ARRAY array, int index);
int get_arraydate_counter(CMD_ARRAY arraydata);
void load_cmd_array();

#endif
