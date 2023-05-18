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
int main(int argc, char *argv[], char *envp[])
{
    while (1)
    {
        _putchar('$');
        char *input = get_user_input();
        char **string_tokens = tokenise(input);
        /**char *cmd = getcommand(string_tokens);*/
        excecute_cmd(string_tokens);
        
        free(input);
        free(stringtokens);
        free(cmd);
    }
    return (0);
}
