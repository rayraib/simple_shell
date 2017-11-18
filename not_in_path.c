#include "shell.h"
/**
* not_valid - checks if an argument is an executable file path
* @buffer: pointere to string of arguments
* @first_command: pointer to string argument with the executable string
* @array: double pointer to array of pointers to string
* Return: 0 succes, otherwise -1 for failure
*/
int not_valid(char *buffer, char *first_command, char **array)
{
	struct stat *st;
	int child_return;

	st = malloc(sizeof(struct stat));
	if (st == NULL)
	{
		free (st);
		return (-1);
	}
	if (stat (first_command, st) == 0)
	{
		child_return = create_child(array);
		if (child_return == -1)/* failure at child process */
		{
			free (st);
			return (-1);
		}/* execution at child process was successfull, command found and executed */
		free (buffer);
		/*free (first_command);*/
		free (array);
		free (st);
		return (0);
	}
	/* stat failed, command not found */
	free (st);
	return (-1);
}
