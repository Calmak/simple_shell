#include "shell.h"
/**
* _strcmp - function to compare 2 strings
* @string1: first string
* @string2: second string
* Return: O if same
*/

int _strcmp(const char *string1, const char *string2)
{
	while (*string1 == *string2)
	{
		if (*string1 == '\0') /**End of string*/
			return (0);
		string1++;
		string2++;
	}
	return (*string1 - *string2);
}
/**
 * _strlen - gets the length of a string
 * @s: string
 * Return: length of the string
 */
int _strlen(char *string)
{
	int a = 0;

	if (!string)
		return (0);

	while (*string++)
		a++;
	return (a);
}
/**
 * _strcat - joins two strings
 * @result: destination pointer
 * @string: source string
 * Return: pointer to destination buffer
 */
char *_strcat(char *result, char *string)
{
	while (*result)
		result++;
	while (*string)
		*result++ = *string++;
	*result = *string;
	return (result);
}
/**
 * *_strcpy - copies contents on one string to the other
 * @result: destination pointer
 * @string: source string
 * Return: pointer to destination buffer
 */
char *_strcpy(char *result, char *string) 
{
	char *res = result;

	while (*string != '\0') 
	{
		*result++ = *string++;
	}
	*result = '\0';
	return res;
}
