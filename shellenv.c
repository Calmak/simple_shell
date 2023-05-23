#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"
/**
 * shell_env - execute env
 * @cmd: pointer to string env
 */
void shell_env(char **cmd, int argc __attribute__((unused)), char **envp __attribute__((unused)))
{
	/**To do*/
	char **envpc= environ;
	
	if (strcmp(cmd[0],"env") == 0)
	{
  		
		while (*envpc != NULL)
		{
			printf("%s\n", *envpc);
    			envpc++;
 		 }
	}
}
