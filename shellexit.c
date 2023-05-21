#include <string.h>
#include "shell.h"
/**
 * shell_exit - executes the exit cmd
 * @cmd: pointer to string exit
 */
void shell_exit(char **cmd)
{
	/**To do*/
	if (strcmp(cmd[0],"exit") == 0)
	{
		exit(0);
	}
}
