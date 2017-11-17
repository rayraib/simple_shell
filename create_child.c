#include "shell.h"
/**
 * create_child - creates a child process and executes a command and its arguments
 * @array: pointer to array of strings
 * Return: 0 if Success, -1 if failure
 */
int create_child (char **array, char *buffer)
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		free(array);
		free(buffer);
		perror(" ");
		return (-1);
	}
	if (child_pid == 0)
	{
		execve(array[0], array, NULL);
		perror(" ");
		exit(-1);
	}
	else
		wait(&status);
	return (0);
}
