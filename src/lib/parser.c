#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "parser.h"
#include "array.h"
#include "command.h"

static int prefix(const char *pre, const char *str){
    return strncmp(pre, str, strlen(pre)) == 0;
}

static void clean_spaces (char* x){
	int i, j=0;
    for(i=0; x[i]!='\0'; i++){
        if(x[i] == ' ' && x[i+1] == ' ') x[j] = x[i];
		else{
            x[j] = x[i];
			j++;
		}
    }
	x[j] = '\0';
}

void notebook_parser(CMD_ARRAY array, char* name){

    //Open notebook.
    int fd = open(name,O_RDONLY | O_CREAT,0774);
    char* strfile = NULL;

    //Ler do ficheiro e inserir numa string.
    char buffer[1024];

    while( read(fd, buffer, 1024) > 0){
         strfile = (char*)realloc(strfile,1024);
         strcat(strfile,buffer);
    }
    /* ESTA A FAZER O PRINT DIREITO printf("%s",strfile); */
    /* OK!!! */

    //Guardar informacao de cada comando.
    char* doc = NULL;
    int dep = 0;
    char* cmd = NULL;
    char* output = "";

    char** cmd_aux;
    char *p;
    char* tok[5] = {"$","\n","$",">>>","<<<"};
    int i = 0;

    //Retirar doc.
    p = strtok (strfile,tok[i]);
    while (p){
        switch (i){
            case 0:
                doc = realloc(doc,sizeof(char)*strlen(p));
                strcpy(doc,p);
                i++;

                //Retirar cmd.
                p = strtok (NULL,tok[i]);
                break;

            case 1:
                cmd = realloc(cmd,sizeof(char)*strlen(p));
                strcpy(cmd,p);
                i++;

                clean_spaces(cmd);
                //Inserir novo commando na double linked list.
                Command c = new_cmd(doc,dep,cmd_aux,output);
                
                //print_command(c);
                add_element(array,c);

                //Caso tenha ou nao outputs.
                p = strtok (NULL,tok[i]);
                break;

            case 2:
                i++;
                if(prefix(tok[i],p)){
                    i++;
                    strsep(&p,tok[i]);
                    p = p + 3;
                    i=0;
                }else i=0;
                break;

            default:
                printf("Nao devia estar aqui!!!");
        }
    }

    free(doc);
    free(cmd);

    close(fd);
}
