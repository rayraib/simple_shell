#include "shell.h"
/**
 * main - writes a simple UNIX command line interpreter
 * Return: 0 for Success, -1 for failure
 */
int main (void)
{
	size_t n = 0;
	char *buffer = NULL;
	char *array[] = {NULL,NULL};
	char *delim = " \n\t";
	char *token = NULL;
	pid_t child_pid;
	int status;

	while (1)
	{
		if (write(1, "sHELL$ ", 7) == -1)
		{
			perror(" ");
		}
		if (getline(&buffer, &n, stdin) == -1)
		{
			free(buffer);
			return(-1);
		}
		token = strtok(buffer, delim);
		if (token == NULL)
			continue;
		array[0] = token;
		child_pid = fork();
		if (child_pid == -1)
		{
			perror(" ");
			return(-1);
		}
		if (child_pid == 0)
		{
			execve(array[0], array, NULL);
			free(buffer);
			perror("sHELL");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
