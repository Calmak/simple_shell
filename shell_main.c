#include <stdlib.h>
#include <stdio.h>
#include "shell.h"
/**
* main - runs the main loop of the shell
* @argc: number of arguments passed
* @argv: arguments passed
* @envp: enviroment variables
* Return: Always 0
*/
int main(int argc, char **argv, char **envp)
{
	char *input;
	char **string_tokens;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_putchar('$');
		input = get_user_input();
		if (input == NULL)
			break;
		string_tokens = tokenise(input);
		if (string_tokens == NULL)
			break;
		execute_cmd(string_tokens, argc, argv, envp);
	}
	free(input);
	free(string_tokens);
	return (0);
}
