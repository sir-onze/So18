
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "parser.h"
#include "array.h"
#include "exec.h"

int main(int argc, char** argv){

    if(argc < 2){
        return -1;
    }

    CMD_ARRAY cmd_array = init_cmd_array();

    load_cmd_array(cmd_array, argv[1]);

    /*Command c;
    for(int i=0; i<get_arraydate_counter(cmd_array); i++){
    c=get_element(cmd_array, i);
    print_command(c);
    }
    printf("---------\n");
    for(int i=0; i<get_arraydate_counter(cmd_array); i++){
    c=get_element(cmd_array, i);
    print_procmd(c);
    }*/

    exec_cmd_array(cmd_array);


    return 0;
}
