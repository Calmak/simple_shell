#include "shell.h"
#include <stdlib.h>
#include <string.h>

int find_cmd(char *cmd, char **argv)
{
  char *path = getenv("PATH");
  int is_found = 0;
  char *dir

  if (path == NULL) 
  {
    perror(argv[0]);
    return -1;
  }
  for (*dir in path)
  {
    char *full_path = malloc(strlen(dir) + strlen(cmd) + 2);
    strcpy(full_path, dir);
    strcat(full_path, "/");
    strcat(full_path, cmd);

    if (access(full_path, X_OK) == 0) 
    {
      is_found = 1;
      break;
    }

    free(full_path);
  }

  return is_found;
}

