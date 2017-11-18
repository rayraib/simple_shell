#include "shell.h"
/**
* check_input - Checks for input from stdin
* Return: Pointer to a buffer with input string, or NULL
*/
char *check_input()
{
	char *buffer = NULL;
	size_t n;

	if (write(1, "sHell$ ", 7) == -1)
	{
		perror(" ");
		return (NULL);
	}
	if (getline(&buffer, &n, stdin) == -1)
	{
		write(1, "\n", 1);
		free (buffer);
		return (NULL);
	}
	return (buffer);
}
