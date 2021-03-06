#include "shell.h"
/**
* get_command - get the first argument from string of arguments
* @buffer: pointer to string of arguments
* Return: pointer to string of first argument, or NULL
*/
char *get_command(char *buffer)
{
	char *first_command = NULL;
	char *copy_string = NULL;
	char *token = NULL;
	char *delim = "\n ";

	copy_string = _strdup(buffer);
	if (copy_string == NULL)
	{
		free(buffer);
		free(copy_string);
		return (NULL);
	}
	token = strtok(copy_string, delim);
	if (token == NULL)
	{
		free(buffer);
		free(copy_string);
		return (NULL);
	}
	first_command = _strdup(token);
	free(copy_string);
	return (first_command);
}
