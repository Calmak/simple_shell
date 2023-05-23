#include "shell.h"
/**
* _puts - outputs the contents of a string
* @to_output: string to output 
*/
void _puts(const char *to_output)
{
  	int i = 0;
  	while (to_output[i] != '\0') 
  	{
		_putchar(to_output[i]);
		i++;
  	}
  	_putchar('\n');
} 
