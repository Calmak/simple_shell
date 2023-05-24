#include "shell.h"
/**
* mputs - outputs the contents of a string
* @to_output: string to output
*/
void mputs(const char *to_output)
{
	int i = 0;

	while (to_output[i] != '\0')
	{
		_putchar(to_output[i]);
		i++;
	}
	_putchar('\n');
}
