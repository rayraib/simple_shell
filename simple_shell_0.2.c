#include "shell.h"
/**
 * main - UNIX command line interpreter that handles arguments
 * Return: 0 if Success, -1 if failure
 */
int main (void)
{
	size_t n = 0;
	int child_return;
	int token_cnt;
	char *buffer = NULL;
	char **array = NULL;

	while (1)
	{
		buffer = NULL;
		if (write(1, "sHELL$ ", 7) == -1)
			perror(" ");
		if (getline(&buffer, &n, stdin) == -1)
		{
			free(buffer);
			return (-1);
		}
		token_cnt = token_count(buffer);
		array = create_array(token_cnt, buffer);
		if (array == NULL)
		{
			free(buffer);
			free(array);
			continue;
		}
		/*{
			free(buffer);
			perror(" ");
			return (-1);
		}*/
		child_return = create_child(array, buffer);
		if (child_return == -1)
		{
			free(buffer);
			free(array);
			perror(" ");
			return (-1);
		}
		free(buffer);
		free_array(array, token_cnt);
		perror(" ");
	}
	return (0);
}
