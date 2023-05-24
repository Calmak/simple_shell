#include <string.h>
#include "shell.h"
/**
 * shell_exit - executes the exit cmd
 * @cmd: pointer to string exit
 * @argc: number of argumnets
 * @envp: environment variables
 */
void shell_exit(char **cmd, int argc __attribute__((unused)),
		char **envp __attribute__((unused)))
{
	/**To do*/
	if (_strcmp(cmd[0], "exit") == 0)
	{
		exit(0);
	}
}
