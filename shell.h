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
void *_realloc(void *pointer, unsigned int old, unsigned int new);
char *_strtok(char *string, const char *delim);

/**own implementation of std library functions*/
int _putchar(char c);
int _strlen(char *);
int _strcmp(const char *string1, const char *string2);
char *_strcat(char *string1, char *string2);
char *_strcpy(char *string1, char *string2);
void mputs(const char *to_ouput);
int find_cmd(char *cmd, char **argv);

/**Shell builtin functions*/
void shell_exit(char **cmd, int argc, char **envp);
void shell_cd(char **cmd, int argc, char **envp);
void shell_env(char **cmd, int argc, char **envp);

int is_interactive();
size_t get_line(char **line, size_t *len, FILE *fp);

#endif /* _SHELL*/
