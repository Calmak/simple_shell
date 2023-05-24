#include <string.h>
#include "shell.h"
/**
 * shell_cd - executes th cd cmd
 * @cmd:pointer to string cd
 * @argc: number of argumnets
 * @envp: environment variables
 */
void shell_cd(char **cmd, int argc, char **envp __attribute__((unused)))
{
	char *current;
	
	if (_strcmp(cmd[0], "cd") == 0)
	{
		if (argc == 1)
			chdir(getenv("HOME"));
		chdir(cmd[1]);
		current = getcwd(NULL, 0);
		setenv("PWD", current, 1);
	}
}
