#include <stdlib.h>
#include "shell.h"
#include <string.h>

/**
 * execute_cmd - runs builtin and external shell cmds
 * @cmd:pointer to array of commands
 * @argc: number of arguments
 * @argv: arguments passed
 * @envp; environment variables
 */
void execute_cmd(char **cmd, int argc, char **argv, char **envp)
{
	int status;
	pid_t pid;
	unsigned long int i;
	size_t size;
	_function _functions[] = {{"cd", shell_cd},
		{"exit", shell_exit}, {"env", shell_env}};
	size = sizeof(_functions) / sizeof(_function);
	for (i = 0; i < size; i++)
	{
		if (_strcmp(_functions[i].name, cmd[0]) ==)
		{
			_functions[i]._function(cmd, argc, envp);
			return;
		}
	}
	pid = fork();/**Launch a child process*/
	if (pid == 0)/**child process*/
	{
		execvp(cmd[0], cmd);/**run command*/
		perror(argv[0]);
		exit(1);
	}
	else if (pid > 0)/**parent process*/
	{
		do{
			/**wait for child process to exit*/
			waitpid(pid, &status, WUNTRACED);
		}
		while(!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		perror(argv[0]);
	}
}
