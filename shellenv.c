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
  	int num = 0;

  	while (envp[num] != NULL) {
   		num++;
 	 }
	envp = malloc(sizeof(**envp * num));

 	 if (strcmp(cmd[0], "env") == 0)
 	 {
   	 	for (i = 0; i < num; i++) 
		{
      			putchar('$');
      			while (*envp[i] != '\0' && *envp[i] != '=')
			{
        			putchar(*envp[i++]);
      			}
      		putchar('\n');
    	}
  }
free(envp);
}
