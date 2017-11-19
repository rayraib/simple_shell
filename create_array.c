#include "shell.h"
/**
* create_array - create an array of pointers to string(commands from stdin)
* @token_cnt: Size of the array to be allocated
* @buffer: Pointer to string of chars(commands frm stdin)
* Return: Pointer to the array of pointers
*/
char **create_array(char *first_com, int token_cnt, char *buffer)
{
	char **array;
	const char *delim = " \t\n";
	int i = 0;
	char *token = NULL;

	array = malloc((sizeof(char *)) * (token_cnt + 1));
	if (array == NULL)
	{
		free(buffer);
		free(first_com);
		return (NULL);/*no allocation, no free necessary */
	}
	token = strtok(buffer, delim);/*tokenize buffer and receive the first arg */
	while (token != NULL)
	{
		array[i] = _strdup(token);/*MALLOC occured in strdup*/
		token = strtok(NULL, delim);/*tokenize again to get the next arg */
		i++;
	}
	array[i] = NULL;
	return (array);
}
