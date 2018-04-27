#include "shell.h"
#include <stdio.h>
/**
 * _strcmp - function that compares two strings
 * @s1: string to compare
 * @s2: string to compare/
 * Return: An integer
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] == s2[i])
		continue;
		else
			break;
	}
	return (s1[i] - s2[i]);
}
