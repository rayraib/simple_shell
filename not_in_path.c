#include "shell.h"
/**
* not_valid - checks if an argument is an executable file path
* @z: count of loops for main function
* @ar: argv[0], executable filename
* @buffer: pointere to string of arguments
* @f_c: pointer to string argument with the executable string
* @array: double pointer to array of pointers to string
* @t_c: Count of tokens
* Return: 0 succes, otherwise -1 for failure
*/
int not_valid(int z, char *ar, int t_c, char *buffer, char *f_c, char **array)
{
	struct stat *st;
	int child_return;

	st = malloc(sizeof(struct stat));
	if (st == NULL)
	{
		free(st);
		return (-1);
	}
	if (f_c[0] == '/' && stat(f_c, st) == 0)
	{
		child_return = create_child(z, f_c, ar, array);
		if (child_return == -1)/* failure at child process */
		{
			free(st);
			free(array[0]);
			free_array(t_c, array);
			return (1);
		}
		free(buffer);
		free(array[0]);
		free_array(t_c, array);
		free(st);
		return (0);
	}
	/* stat failed, command not found */
	free(st);
	return (-1);
}
