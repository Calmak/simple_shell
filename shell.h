#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
/**
* _function - Structure to represent a function pointer
*for our builtin functions
*/
typedef struct _function
{
	char *name;
	void (*_function)(char **cmd, int argc, char **envp);
} _function;

/**shell functions*/
char *get_user_input(void);
char **tokenise(char *input);
void execute_cmd(char **cmd, int argc, char **argv, char **envp);

/**own implementation of std library functions*/
int _putchar(char c);
int _strlen(char *);
int _strcmp(const char *string1, const char *string2);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
void mputs(const char *to_ouput);
int find_cmd(char *cmd, char **argv);

/**Shell builtin functions*/
void shell_exit(char **cmd, int argc, char **envp);
void shell_cd(char **cmd, int argc, char **envp);
void shell_env(char **cmd, int argc, char **envp);


#endif /* _SHELL*/
