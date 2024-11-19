#include <stdio.h>
#include "dynamic_string.h"
#include "generator.h"
#include "types.h"

int main()
{

    if (!dynamic_string_init(&dyn_str, filename))
    {
        return 1;
    }

    gen_header();

    gen_main_start();
    gen_main_end();

    gen_function_start();
    gen_function_end();

    st_op = S_PLUS;

    gen_stack_operation(st_op);

    st_op = S_MINUS;

    gen_stack_operation(st_op);

    st_op = S_TIMES;

    gen_stack_operation(st_op);

    gen_label(function_id, label_depth, label_index);

    gen_if_start(function_id);

    dynamic_string_write_to_file(&dyn_str, filename);

    /*dynamic_string_print(&dyn_str);*/

    return 0;
}
