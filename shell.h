#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**shell functions*/
char *get_user_input(void);
char **tokenise(char *input);
void execute_cmd(char **cmd);

/**own implementation of std library functions*/
int _putchar(char c);
int _strlen(char *);
int _strcmp(char *, char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);

/**Shell builtin functions*/
void shell_exit(char **cmd);
void shell_cd(char **cmd);
void shell_env(char **cmd);
void shell_cd(char **cmd);

#endif /* _SHELL*/
