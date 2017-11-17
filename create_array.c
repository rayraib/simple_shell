#include "shell.h"
/**
 * create_array - creates a pointer to array of strings to be used to execute a command
 * @token_cnt: number of tokens
 * @buffer: pointer to string to tokenize
 * Return: pointer to array of strings or NULL if failed to allocate space
 */
char **create_array(int token_cnt, char *buffer)
{
	int i = 0;
	char **array = NULL;
	char *delim = " \t\n";
	char *token = NULL;

	array = malloc((sizeof(char *) * (token_cnt + 1)));
	if (array == NULL)
		return (NULL);
	token = strtok(buffer, delim);
	if (token == NULL)
		return (NULL);
	while (token != NULL)
	{
		array[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	array[i] = NULL;
	return (array);
}
