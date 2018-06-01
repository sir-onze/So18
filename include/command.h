
#ifndef __COMMAND_H__
#define __COMMAND_H__

typedef struct command* Command;

Command new_cmd(char* doc, int dep, char* cmd, char* output);

char* get_doc(Command c);
int get_dep(Command c);
char* get_cmd(Command c);
char* get_out(Command c);
char** get_pro_cmd(Command c);

void set_out(Command c, char* out);
void set_dep(int dep, Command c);
void set_pro_cmd(char** pro_cmd, Command c);

void print_command(Command c);
void print_procmd(Command c);

void free_command(Command c);

#endif
