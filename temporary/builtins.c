#include "shell.h"
/**
* _my_exit - Exits a process/our shell. execute an Exit command.
* @buffer: Pointer to string of chars containing arg command.
*/
void _my_exit(char *buffer)
{
	free(buffer);
	exit(1);
}
/**
* _print_env - Prints environment variables to stdout.
* @buffer: Pointer to string of char
*/
void _print_env(char *buffer)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (write(1, environ[i], _strlen(environ[i])) == -1)
		{
			free(buffer);
			perror(" ");
		}
		if (write(1, "\n", 1) == -1)
		{
			free(buffer);
			perror(" ");
		}
	}
}
