#include "shell.h"
/**
 * _strlen - calculate the length of a string
 * @s: string
 * Return: Always i.
 */
int _strlen(char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
