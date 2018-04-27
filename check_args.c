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
		free(buffer);
		return (NULL);
	}
	check4builtin(buffer);
	return (buffer);
}
/**
* check4builtin - checks if the buffer contains string "exit" or "env"
* 				- if yes, call the corresponding function to execute the command
* @buffer: Pointer to string to check
*/
void check4builtin(char *buffer)
{
	buil_t run_built[] = {
		{"exit\n", _my_exit},
		{"env\n", _print_env},
		{NULL, NULL}
	};
	int index = 0;

	while (run_built[index].builtin != NULL)
	{
		if (_strcmp(buffer, run_built[index].builtin) == 0)
			run_built[index].builtcmd(buffer);
		index++;
	}
}

/**
* _my_exit - exits a process
* @buffer: Pointer to string of chars
*/
void _my_exit(char *buffer)
{
	free(buffer);
	exit(1);
}

/**
* _print_env - prints environment variables to stdout
* @buffer: pointer to string of char
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
