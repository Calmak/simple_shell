#include "shell.h"

int _strcmp(const char *string1, const char *string2) 
{
  while (*string1 == *string2) 
  {
    if (*string1 == '\0') 
    {
      	return 0;
    }
    string1++;
    string2++;
  }
  return (*string1 - *string2);
}
