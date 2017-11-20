#include "shell.h"
/**
* create_child - creates child process and executes a command
* @array: pointer to array of strings
* @arg: Pointer to string of char (
* @z: count of how many times the function has looped
* @ch: flag for where the error msg is originating
* @f_com : pointer to string of chars(first command arg input in shell)
* Return: 0 if Success, -1 if failure
*/
int create_child(int z, char *f_com, char *arg, char **array)
{
	int status, ch;
	pid_t child_pid;

	ch = 2;
	child_pid = fork();
	if (child_pid == -1)/*child process not created */
	{
		perror(" ");
		return (-1);
	}
	if (child_pid == 0)
	{
		execve(array[0], array, NULL);
		err_msg(z, ch, f_com, arg);
		exit(-1);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
