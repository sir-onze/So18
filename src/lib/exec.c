
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "exec.h"
#include "array.h"
#include "command.h"

char* exec_cmd(char** cmd, char* input){
    int i, fdf, in[2], out[2];
    char* output = malloc(sizeof(char)*1024);


    pipe(in);
    pipe(out);
    fdf = fork();

    if(!fdf){ // FILHO
        close(in[1]);
        close(out[0]);
        dup2(in[0],0);
        close(in[0]);
        dup2(out[1],1);
        close(out[1]);

        execvp(cmd[0],cmd);

        perror("Error execvp");
        _exit(-1);
    }
    // PAI
    else{

        close(in[0]);
        close(out[1]);
        write(in[1], input, strlen(input));
        close(in[1]);
        wait(&i);
        read(out[0], output, 1024);
    }
    return output;
}

void exec_cmd_array(CMD_ARRAY array){

    int dep;
    char* o = NULL, *output = NULL;
    Command c;
    for(int i=0; i<get_arraydate_counter(array); i++){
        c = get_element(array, i);
        dep = get_dep(c);
        output = get_out(get_element(array, i-dep));

        char** pro_cmd = get_pro_cmd(get_element(array, i));
        o = exec_cmd(pro_cmd, output);

        set_out(get_element(array, i), o);
        print_command(c);
    }
}
