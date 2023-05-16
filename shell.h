#ifndef SHELL_H
#define SHELL_H

int _putchar(char c);
char *get_user_input(void);
char **tokenise(char *input);
char *getcommand(char **command);
void execute_cmd(char *cmd);
#endif /* _SHELL*/
