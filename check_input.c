#include "shell.h"
void check_builtin(char *buffer);
void print_env();
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
	check_builtin(buffer);	
	return (buffer);
}
/**
* check_builtin - checks for builtins and call that fuctionn
* @buffer:
*/
void check_builtin(char *buffer)
{
	char *exit_b = "exit\n";
	char *env_b = "env\n";
	
	if (_strcmp(buffer, exit_b) == 0)
		exit(0);
	else if (_strcmp(buffer, env_b) == 0)
		print_env();
	
}
/**
* print_env - prints the environment variable to stdou
*/
void print_env()
{
	int i  = 0;
	
	while (environ[i] != NULL)
	{
		if (write(1, environ[i], _strlen(environ[i])) == -1)
			perror (" ");
		i++;
		if (write(1, "\n", 1) == -1)
			perror(" ");
	}
}
