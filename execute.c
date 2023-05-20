#include <stdlib.h>
#include "shell.h"

void execute_cmd(char **cmd)
{
	int status;
        pid_t pid = fork(); /**Launch a new process*/
        
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
