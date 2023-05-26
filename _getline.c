#include <stdio.h>

char *getline(char *lineptr, size_t *n, FILE *stream) {
  char *bufptr = lineptr;
  size_t size = *n;
  int c;

  while ((c = fgetc(stream)) != EOF) {
    if (c == '\n') {
      break;
    }

    if (bufptr - lineptr == size - 1) {
      size *= 2;
      char *new_bufptr = realloc(lineptr, size);
      if (new_bufptr == NULL) {
        free(lineptr);
        return NULL;
      }

      lineptr = new_bufptr;
      bufptr = lineptr + (bufptr - lineptr);
    }

    *bufptr++ = c;
  }

  *bufptr = '\0';
  *n = bufptr - lineptr;

  return lineptr;
}

