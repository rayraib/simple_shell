#include "shell.h"
/**
 * _strdup - copy string to a new mememory location
 * @s: pointer to string that is to be copied
 * Return: pointer to newly allocated memory location
 */
char *_strdup(char *s)
{
	int len;
	char *new_location;

	len = _strlen(s);
	new_location = malloc(len + 1);
	if (new_location == NULL)
		return (NULL);
	_strcpy(new_location, s);
	return (new_location);
}
