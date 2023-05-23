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
 	if (strcmp(cmd[0], "env") == 0)
 	 {
   	 	for (i = 0 ; envp[i] ; i++) 
		{
			_putchar('[');
    			_putchar('0' + i);
    			_putchar(']');
    			_putchar(':');
    			_putchar(' ');
    			puts(envp[i]);
		}
    	}
}
