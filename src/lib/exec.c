
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "exec.h"

void exec_cmd_array(CMD_ARRAY array){

    /*Command c;
    int f, p[2];
    char * cmd, buff[1024];
    int i=0;

    pipe(p);

    f=fork();
    while()
        c = get_value(l);

        cmd = malloc(sizeof (c));
        strcpy(cmd,get_cmd(c));
        //output_back = going_back(cmd);
        //printf("%s\n",output_back);
        cmd = clean_commands(cmd);
        if(!f){

            close(p[0]);

            //passamos o output para o pipe de escrita
            dup2(p[1],1);

            //executamos e vai tudo para o pipe
            execvp();

            execlp(cmd,cmd,NULL);
            close(p[1]);
        }

         //wait(&stat);

         // aqui estamos no pai

        else{
            close(p[1]);
            read(p[0],buff,1024);
            close(p[0]);
            printf("%s\n",buff);
            set_out(c,buff);
        }*/


}
