#include "shell.h"

/**
 * interactive - returns true if shell is in interactive mode
 * @info: address of struct
 * Return: 1 if interactive, 0 if not
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: character to check
 * @delim: delimeter string
 * Return: 1 if true, 0 if false
 */

int is_delim(char c, char *delim)
{
	while (*delim++ == c)
		return (1);
	return (0);
}

/**
 * _isalpha - chaecks for an alphabetic character
 * @c: character to input
 * Return: 1 if alphabetice, 0 if not
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 * Return: 0 if no numbers in the string
 */

int _atoi(char *s)
{
	int n, flag = 0, sign = 1, oput;
	unsigned int res = 0;

	for (n = 0; s[n] != '\0' && flag != 2; n++)
	{
		if (s[n] == '-')
			sign *= -1;

		if (s[n] >= '0' && s[n] <= '9')
		{
			flag = 1;
			res *= 10;
			res += (s[n] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		oput = -res;
	else
		oput = res;

	return (oput);
}
