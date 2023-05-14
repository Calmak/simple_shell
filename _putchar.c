#include <unistd.h>
/**
 * _putchar - writes the charc to standard output
 * @c: The char to print
 * Return: On success 1, -1 on failure
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

