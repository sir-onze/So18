#ifndef __EXEC_H__
#define __EXEC_H__
#include "array.h"

void exec_cmd_array(CMD_ARRAY cmd_array);
char* exec_cmd(char** cmd, char* output);
void print_cmd_file(CMD_ARRAY array,char* f);
#endif
