#include "shell.h"
/**
 * _strcpy - copies one string into another array
 * @dest: pointer to an array
 * @src: pointer to a string
 * Return: Always 0.
 */
char  *_strcpy(char *dest, char *src)
{

	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
