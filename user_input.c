#include <stdio.h>
#include "shell.h"
/**
*get_user_input - gets user input
*Returns: user input
*/

char *get_user_input(void)
{
    char *input = NULL;
    size_t buf = 0;

    /*getline handles memory allocations on its own*/
    getline(&input,&buf,stdin);
    return input;
}
