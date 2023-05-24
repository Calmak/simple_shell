#include "shell.h"
#include <string.h>

size_t get_line(char **line, size_t *len, FILE *fp)
{
	if (line == NULL || len == NULL)
	{
		fputs("Error\n", stderr);
		return -1;
	}


	if (fp == NULL)
	{
		fputs("Error!\n", stderr);
		return -1;
	}

	char c[120];

	if (*line == NULL)
	{
		*len = sizeof(c);
		if ((*line = malloc(*len)) == NULL)
		{
			perror("Error\n");
			return -1;
		}
	}
	(*line)[0] = '\0';
	
	while (fgets(c, sizeof(c), fp) != NULL)
	{
		if (*len - strlen(*line) < sizeof(c))
		{
			*len *= 2;
			if((*line = realloc(*line, *len)) == NULL)
			{
				perror("Error");
				free(line);
				return -1;
			}
		}

		strcat(*line, c);
		if ((*line)[strlen(*line) - 1] == '\n')
		{
			return strlen(*line);
		}
	}
	return -1;
}

int main(void)
{
	FILE *fp = fopen(*line.txt, "r");
	if (fp == NULL)
	{
		perror("ERROR");
		exit(1);
	}

	char *line = NULL;
	size_t len = 0;

	while(get_line(&line, &len, fp) != -1)
	{
		printf("line length: %zd\n", strlen(line));
	}

	printf("line size: %zd\n", len);

	fclose(fp);
	free(line);
}
