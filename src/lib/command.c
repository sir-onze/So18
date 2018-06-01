#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "command.h"

struct command{
    char* doc;
    int dep;
    char* cmd;
    char** pro_cmd;
    char* output;
};

Command new_cmd(char* doc, int dep, char* cmd, char* output){

    Command new = malloc(sizeof(struct command));
    new->doc = malloc (sizeof(char)*strlen(doc));
    new->cmd = malloc (sizeof(char)*strlen(cmd));
    new->output = malloc(sizeof(output));

    strcpy( new->doc, doc);
    new->dep = dep;
    strcpy( new->cmd, cmd);
    new->pro_cmd = NULL;
    strcpy( new->output, output);

    return new;
}

//Getters.
char* get_doc(Command c){
    if(c)
        return c->doc;
    return NULL;
}
int get_dep(Command c){
    if(c)
        return c->dep;
    return 0;
}
char* get_cmd(Command c){
    if(c)
        return c->cmd;
    return NULL;
}
char* get_out(Command c){
    if(c)
        return c->output;
    return NULL;
}


//Setters.
void set_out(Command c,char* out){
    strcpy(c->output, out);
}
void set_dep(int dep, Command c){
    c->dep = dep;
}
void set_pro_cmd(char** pro_cmd, Command c){
    c->pro_cmd = pro_cmd;
}

void print_command(Command c){
    if(c)
        printf("Command:\n\tdoc: %s\tcmd: %s\n\tdep: %d\n\toutput: %s\n\n",get_doc(c),get_cmd(c),get_dep(c),get_out(c));
}

void print_procmd(Command c){
    if(c){
        printf("---- CMD ----\n");
        char** aux = c->pro_cmd;
        for(int i = 0; aux[i]!=NULL; i++) {
            printf("%s\n", aux[i]);
        }
    }

}

void free_command(Command c){
    if(c){
        free(c->doc);
        free(c->cmd);
        free(c->output);
        free(c);
    }
}
