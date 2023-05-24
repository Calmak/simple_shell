char *my_strtok(char *str, const char *delim) {
  static char *olds;

  if (str == NULL) {
    str = olds;
  }

  // Scan leading delimiters.
  while (*str && strchr(delim, *str)) {
    *str++ = '\0';
  }

  if (*str == '\0') {
    return NULL;
  }

  // Find the end of the token.
  char *token = str;
  while (*token && !strchr(delim, *token)) {
    token++;
  }

  // Terminate the token and make OLDS point past it.
  *token = '\0';
  olds = token + 1;

  return str;
}
