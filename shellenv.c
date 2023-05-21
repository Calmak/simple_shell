#include <string.h>
#include "shell.h"
/**
 * shell_env - execute env
 * @cmd: pointer to string env
 */
void shell_env(char **cmd)
{
	/**To do*/
	if (strcmp(cmd[0],"env") == 0)
	{
		exit(0);
	}
}
