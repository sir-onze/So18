
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

char* exec_cmd(char** cmd, int fdo){
    for(int i=0; cmd[i]!=NULL; i++){
        printf("%s ", cmd[i]);
    }
    printf("\n");

    /*int fdf, p[2];
    char* output = malloc(1024);
    //char* buffer = malloc(sizeof(char)*1024);
    pipe(p);

    //read(fdo, buffer, 1024);
    //write(1, buffer, strlen(buffer));

    fdf = fork();
    if(!fdf){
        //passamos o output para o pipe de escrita
        dup2(fdo, 0);
        dup2(p[1], 1);
        close(p[0]);

        //executamos e vai tudo para o pipe
        execvp(cmd[0],cmd);

        perror("Error execvp");
        _exit(1);
    }
    // aqui estamos no pai
    else{
        close(p[1]);
        read(p[0], output, strlen(output));
        close(p[0]);
    }
    printf("NO FIIIIIM: %s\n",output);*/
    return NULL;
}

void exec_cmd_array(CMD_ARRAY array){
    char* o;
    for(int i=0; i<get_arraydate_counter(array); i++){
        int dep = get_dep(get_element(array, i));

        char* output = get_out(get_element(array, i-dep));

        int fdo = open("output.txt", O_RDWR|O_CREAT|O_TRUNC, 0664);
        write(fdo, output, strlen(output));

        char** pro_cmd = get_pro_cmd(get_element(array, i));
        o = exec_cmd(pro_cmd, fdo);
        //set_out(get_element(array, i), o);
        close(fdo);
    }
}
