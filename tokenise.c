#include <string.h>
#include "shell.h"

char **tokenise(char *input)
{
    char *delim = " \t\r\n";
    char *token;
    int len = 0;
    int size = 20;/*Initial size for input*/
    char **tokens = malloc(size * sizeof(char*));

    /*check to see if input is not null*/
    if (input != NULL)
        token = strtok(input,delim);
    while(token != NULL)
    {
        tokens[len] = token;
        len++;
        
        if (len >= size)/*not enough memory*/
        {
            /*allocate more memory*/
            tokens = realloc(tokens, len * sizeof(char*));
        }
        /*Continue to next token*/
        token = strtok(NULL, delim);
    }
    free(delim);
    free(token);
    /*set last index to NULL*/
    tokens[len] = NULL;
    return tokens;
}
