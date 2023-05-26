#include <stdio.h>
#include "shell.h"
/**
* _getline - returns line typed
* @line: pointer to the line
* @size: size
* @buf: stream
* Return: pointer to the line
*/

char *_getline(char *line, size_t *size, FILE *buf) 
{
  int a;
  char *ptr = line;
  size_t size = *size;
  

  while ((a = fgetc(buf)) != EOF)
  {
      if (a == '\n') 
        break;

      if (ptr - line == size - 1)
      {
        size *= 2;
        char *_fptr = _realloc(line,0, size);
      if (_fptr == NULL) 
      {
        free(line);
        return NULL;
      }

      line = _ptr;
      ptr = line + (ptr - line);
    }

    *ptr++ = a;
  }

  *ptr = '\0';
  *size = ptr - line;

  return line;
}

