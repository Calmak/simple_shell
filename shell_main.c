#include <stdlib.h>
#include <stdio.h>
#include "shell.h"
/**
*main - runs the main loop of the shell
*@argc: number of arguments passed
*@argv: arguments passed to main
*@envp: environment variables
*Returns: Always 0
*/
int main(void)
{
    char *input;
    char **string_tokens;
    while (1)
    {
        _putchar('$');
        input = get_user_input();
        string_tokens = tokenise(input);
        execute_cmd(string_tokens);
        
        free(input);
        free(string_tokens);
        free(cmd);
    }
    return (0);
}
