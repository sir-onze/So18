
#include "array.h"
#include "exec.h"

int main(){

    CMD_ARRAY cmd_array = init_cmd_array();
    load_cmd_array();
    exec_cmd_array();


    return 0;
}
