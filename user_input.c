#include <stdio.h>
#include "shell.h"
/**
* get_user_input - gets user input
* Return: user input
*/

char *get_user_input(void)
{
	char *input = NULL;
	size_t buf = 0;

	/*getline handles memory allocations on its own*/
	if (getline(&input, &buf, stdin) == -1)
	{
		free(input);
		exit (1);
	}
	
	return (input);
}
