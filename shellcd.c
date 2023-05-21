#include "shell.h"
/**
 * shell_cd - executes th cd cmd
 * @cmd:pointer to string cd
 * */
void shell_cd(char **cmd)
{
	/**to do*/
	if (strcmp(cmd[0],"cd") == 0)
	{
		exit(0);
	}
}
