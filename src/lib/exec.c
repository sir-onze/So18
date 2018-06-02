
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

char* exec_cmd(char** cmd, char* output){

    pid_t fdf, p1[2], p2[2];
    char* o = malloc(1024);
    //char* buffer = malloc(sizeof(char)*1024);
    pipe(p1);
    pipe(p2);
    output = "sos";
    puts("---.sds");

    fdf = fork();
    if(fdf==0){ // FILHO
        dup2(p1[0], 1);
        close(p1[1]);
        dup2(p2[1], 0);
        close(p2[1]);

        /*execvp(cmd[0],cmd);

        perror("Error execvp");
        _exit(1);*/
    }
    // PAI
    else{

        close(p1[0]);
        write(p1[1], output, 1024);
        close(1);
        int n = read(p2[0], o, 1024);
        if(n==0)
            puts("asneiras\n");
        else
            printf("OUTPUT: %s\n", output);
    }
    return output;
}

void exec_cmd_array(CMD_ARRAY array){
    char* o;
    for(int i=0; i<get_arraydate_counter(array)-1; i++){
        int dep = get_dep(get_element(array, i));
        char* output = get_out(get_element(array, i-dep));
        int fdo = open("output.txt", O_RDWR|O_CREAT|O_TRUNC, 0664);
        write(fdo, output, strlen(output));
        char** pro_cmd = get_pro_cmd(get_element(array, i));
        o = exec_cmd(pro_cmd, output);
        //set_out(get_element(array, i), o);
        close(fdo);
    }
}
