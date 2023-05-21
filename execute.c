#include <stdlib.h>
#include "shell.h"
#include <string.h>

void execute_cmd(char **cmd)
{
	int status;
    pid_t pid; 
	int num_cmd = 0;
	int i;
	size_t size;
	_function _functions[] = {{"cd",shell_cd},{"exit",shell_exit},{"env",shell_env}};
	
	size = array_length(_functions);
	for (i = 0; i < size;i++)
    {
        if (strcmp(_functions[i],cmd[0])==0)
        {
            _functions[i]._function(cmd);
            return;
        }
    }
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
