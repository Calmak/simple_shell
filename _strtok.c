#include "shell.h"

/*char *_strchr(const char *area, int num) {
  char *a = NULL;

  while (*area) {
    if (*area == num) {
      a = area;
      break;
    }

    area++;
  }*/

char *_strtok(char *string, const char *delim)
{
  static char *olds;
  char *token;

  if (string == NULL)
  {
      string = olds;
  }

  
  while (*string && strchr(delim, *string))
  {
      *string++ = '\0';
  }

  if (*string == '\0')
  {
    return NULL;
  }

  token = string;
  while (*token && !strchr(delim, *token))
  {
      token++;
  }
  *token = '\0';
  olds = token + 1;

  return str;
}


