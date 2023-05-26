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
  size_t _size = *size;
  size_t s;
  

  while ((a = fgetc(buf)) != EOF)
  {
      if (a == '\n') 
        break;

      if (ptr - line == _size - 1)
      {
        _size *= 2;
        char *_fptr = _realloc(line,0, _size);
        if (_fptr == NULL) 
        {
          free(line);
          return NULL;
        }

      line = _fptr;
      ptr = line + (ptr - line);
    }

    *ptr++ = a;
  }

  *ptr = '\0';
  *size = ptr - line;

  return line;
}

