#include <stdlib.h>
#include "shell.h"

/**
 * _realloc - function that reallocs a memory block
 * @pointer: value 1
 * @old: previous size
 * @new: current size
 * Return: pointer to integer
 */

void *_realloc(void *pointer, unsigned int old, unsigned int new)
{
	unsigned int lower = 0;
	char *p;
	unsigned int i;

	if (new == old)
		return (pointer);
	if (ptr == NULL)
		return (malloc(new));
	if (new == 0 &&  pointer != NULL)
	{
		free(pointer);
		return (NULL);
	}
	if (new < old)
		lower = new;
	else
		lower = old;
	p = malloc(new);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < lower; i++)
	{

		p[i] = ((char *) pointer)[i];
	}
	free(pointer);
	return (p);
}

