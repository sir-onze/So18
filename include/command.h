
#ifndef __COMMAND_H__
#define __COMMAND_H__

typedef struct command* Command;

Command new_cmd(char* doc,int dep, char** cmd, char* output);

char* get_doc(Command c);
int get_dep(Command c);
char** get_cmd(Command c);
char* get_out(Command c);

void set_out(Command c, char* out);

void print_command(Command c);

void free_command(Command c);

#endif
