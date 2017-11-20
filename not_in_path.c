#include "shell.h"
/**
* not_valid - checks if an argument is an executable file path
* @buffer: pointere to string of arguments
* @f_com: pointer to string argument with the executable string
* @array: double pointer to array of pointers to string
* @token_cnt: Count of tokens
* Return: 0 succes, otherwise -1 for failure
*/
int not_valid(char *ar, int token_cnt, char *buffer, char *f_com, char **array)
{
	struct stat *st;
	int child_return;

	st = malloc(sizeof(struct stat));
	if (st == NULL)
	{
		free(st);
		return (-1);
	}
	if (stat(f_com, st) == 0)
	{
		child_return = create_child(ar, array);
		if (child_return == -1)/* failure at child process */
		{
			free(st);
			free(array[0]);
			free_array(token_cnt, array);
			return (1);
		}
		free(buffer);
		free(array[0]);
		free_array(token_cnt, array);
		free(st);
		return (0);
	}
	/* stat failed, command not found */
	free(st);
	return (-1);
}
