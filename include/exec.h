
#include "array.h"

void exec_cmd_array(CMD_ARRAY cmd_array);
char* exec_cmd(char** cmd, char* output);
void print_cmd_file(CMD_ARRAY array,char* file);
/*if(fdf==0){ // FILHO
    //dup2(fdo, 0);
    //dup2(p[1], 1);
    //close(p[0]);
    close(0);
    dup(fdo);
    close(p[0]);
    close(p[1]);

    execvp(cmd[0],cmd);

    perror("Error execvp");
    _exit(1);
}
// PAI
else{
    close(1);
    dup(p[0]);
    close(p[1]);
    int n = read(1, output, strlen(output));
    if(n==0)puts("asneiras\n");
    else
        printf("OUTPUT: %s\n", output);
}*/
