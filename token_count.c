#include "shell.h"
/**
 * token_count - counts the number of tokens
 * @buffer: Pointer to string to tokenize
 * Return: number of tokens
 */
int token_count (char *buffer)
{
	char *string_copy = NULL;
	char *token = NULL;
	char *delim = " \t\n";
	int token_cnt = 0;

	string_copy = _strdup(buffer);
	if (string_copy == NULL)
		return (-1);
	token = strtok (string_copy, delim);
	while (token != NULL)
	{
		token = strtok(NULL, delim);
		token_cnt++;
	}
	free (string_copy);
	return (token_cnt);
}
