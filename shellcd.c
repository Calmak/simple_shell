#include <string.h>
#include "shell.h"
/**
 * shell_cd - executes th cd cmd
 * @cmd:pointer to string cd
 * */
void shell_cd(char **cmd, int argc, char **envp)
{
	envp = NULL;
	/**to do*/
	if (strcmp(cmd[0],"cd") == 0)
	{
		 if (argc == 1)
			 chdir(getenv("HOME"));
		chdir(cmd[1]);
	}
}
