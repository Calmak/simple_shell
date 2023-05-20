#include <stdlib.h>
#include "shell.h"

void execute_cmd(char **cmd)
{
	int status;
        pid_t pid; 
	int num_cmd = 0;
	
	if (strcmp(cmd[0], "cd") == 0) 
	{
		/**change directory*/
    		chdir(cmd[1]);
  	}
	else if (strcmp(cmd[0], "exit") == 0)
	{
    		/** Exit the shell.*/
    		exit(0);
  	}
	else if (strcmp(cmd[0], "env") == 0) 
	{
    		/**Print the environment variables.*/
    		for (int i = 0; i < num_cmd; i++)
		{
      			printf("%s=%s\n", cmd[i], getenv(cmd[i]));
    		}
	}
	else
	{
	
		pid = fork(); /**Launch a child process*/
		if (pid == 0)/**child process*/
        	{
          		execvp(cmd[0],cmd);/**run command*/
            		perror("shell error");
            		exit(1);
        	}
        	else if (pid > 0) /**parent process*/
        	{
         	do
            	{
               		/**wait for child process to exit*/
               		waitpid(pid,&status,WUNTRACED);
            	}
            	while(!WIFEXITED(status) && !WIFSIGNALED(status));
        	}
       		else
        	{
            		perror("shell error");
        	}
	}
}
