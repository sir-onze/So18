
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "array.h"
#include "exec.h"
#include "parser.h"

int main(int argc, char** argv){

    CMD_ARRAY cmd_array = init_cmd_array();
    notebook_parser(cmd_array, argv[1]);

    Command c;
    for(int i=0; i<get_arraydate_counter(cmd_array); i++){
        c=get_element(cmd_array, i);
        print_command(c);
    }
    /*load_cmd_array();
    exec_cmd_array();*/


    return 0;
}