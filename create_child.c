#include "shell.h"
/**
 * create_child - creates child process and executes a command and its arguments
 * @array: pointer to array of strings
 * Return: 0 if Success, -1 if failure
 */
int create_child (char **array)
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)/*child process not created */
	{
		perror(" ");
		return (-1);
	}
	if (child_pid == 0)
	{
		execve(array[0], array, NULL);
		perror("execve failed inside create_child ");
		exit(-1);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
