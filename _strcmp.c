#include "shell.h"
/**
* _strcmp - function to compare 2 strings
* @string1: first string
* @string2: second string
*Returns: O if same 
*/

int _strcmp(const char *string1, const char *string2) 
{
  while (*string1 == *string2) 
  {
    if (*string1 == '\0') /**End of string*/
    {
      	return 0;
    }
    string1++;
    string2++;
  }
  return (*string1 - *string2);
}
