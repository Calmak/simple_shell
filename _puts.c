#include "shell.h"

void _puts(const char *to_ouput)
{
  int i = 0;
  while (to_output[i] != '\0') 
  {
	putchar(to_output[i]);
	i++;
  }
  putchar('\n');
} 
