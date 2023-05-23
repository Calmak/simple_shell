#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"
/**
 * shell_env - execute env
 * @cmd: pointer to string env
 */
void shell_env(char **cmd, int argc __attribute__((unused)), char **envp)
{
	
	if (strcmp(cmd[0],"env") == 0)
	{
		while (*env != NULL)
		{
    			putchar('$');
    			while (*env != '\0' && *env != '=')
      				putchar(*env++);
   			 putchar('\n');
  		}
	}
}
