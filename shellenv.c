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
	int i;
  	int num_env_vars = 0;

  	while (envp[num_env_vars] != NULL) {
   		num_env_vars++;
 	 }

 	 if (strcmp(cmd[0], "env") == 0)
 	 {
   	 	for (i = 0; i < num_env_vars; i++) 
		{
      			putchar('$');
      			while (*envp[i] != '\0' && *envp[i] != '=')
			{
        			putchar(*envp[i++]);
      			}
      		putchar('\n');
    	}
  }
}
