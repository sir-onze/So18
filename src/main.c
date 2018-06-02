
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "array.h"
#include "exec.h"
#include "parser.h"

int main(int argc, char** argv){

    if(argc < 2)
        return -1;

    for(int i=1;i<argc;i++){
        CMD_ARRAY cmd_array = init_cmd_array();
        load_cmd_array(cmd_array, argv[i]);
        exec_cmd_array(cmd_array);
        print_cmd_file(cmd_array,argv[i]);
    }
    return 0;
}
