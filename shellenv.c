#include <string.h>
#include "shell.h"
/**
 * shell_env - execute env
 * @cmd: pointer to string env
 */
void shell_env(char **cmd, int argc, char **envp)
{
	envp = environ;
	argc = 0;
	/**To do*/
	if (strcmp(cmd[0],"env") == 0)
	{
  		while (*envp != NULL)
		{
    			_putchar('$');
    			_putchar(' ');
    			puts(*envp);
    			_putchar('\n');
    			envp += 2;
  		}
	}
}
