#include "shell.h"
/**
* token_count - counts the number of tokens
* @f_com: pointer to string of char- first command input in shell
* @buffer: Pointer to string to tokenize
* Return: number of tokens
*/
int token_count(char *f_com, char *buffer)
{
	char *string_copy = NULL;
	char *token = NULL;
	char *delim = " \t\n";
	int token_cnt = 0;

	string_copy = _strdup(buffer);
	if (string_copy == NULL)
	{
		free(buffer);
		free(f_com);
		return (-1);
	}
	token = strtok(string_copy, delim);
	while (token != NULL)
	{
		token = strtok(NULL, delim);
		token_cnt++;
	}
	free(string_copy);
	return (token_cnt);
}
