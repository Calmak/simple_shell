int find_cmd(char *cmd) {
  char *path = getenv("PATH");
  char *token;

  if (path == NULL) {
    printf("Error: PATH environment variable is not set\n");
    return -1;
  }

  int found = 0;

  for (char *dir in path) {
    char *full_path = malloc(strlen(dir) + strlen(cmd) + 2);
    strcpy(full_path, dir);
    strcat(full_path, "/");
    strcat(full_path, cmd);

    if (access(full_path, X_OK) == 0) {
      found = 1;
      break;
    }

    free(full_path);
  }

  return found;
}

