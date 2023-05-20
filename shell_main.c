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
        if (input != NULL)
            string_tokens = tokenise(input);
        if (string_tokens != NULL)
            execute_cmd(string_tokens);
    }
    free(input);
    free(string_tokens);
    return (0);
}
