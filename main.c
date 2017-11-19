#include "shell.h"
/**
* main - entry point to a basic functional shell
* Return: 0 succes, otherwise -1
*/
int main(void)
{
	char *buffer, *first_command = NULL;
	int token_counter;
	char **array = NULL;
	int index, not_valid_ret;/*, command_ret;*/

	while (1)
	{
		buffer = check_input();/*gets arguments from stdin*/
		if (buffer == NULL)
		/*	free(buffer);*/
			return (-1);
		index = find_path();/*index of PATH varible*/
		if (index == -1)
			continue;
		first_command = get_command(buffer);/*get the first argument*/
		if (first_command == NULL)
			continue;
		token_counter = token_count(first_command, buffer);/*number of args passed*/
		if (token_counter == -1)
			continue;
		array = create_array(first_command, token_counter, buffer);
								/*array of pointers to args*/
		if (array == NULL)
			return (-1);
		not_valid_ret = not_valid(token_counter, buffer, first_command, array);/*command executed */
		if (not_valid_ret == 0 || not_valid_ret == 1)
		{
			free(first_command);
			continue;
		}
		find_command(index, first_command, array);/*find cmmnd & exec*/
		free(buffer);
		free_array(token_counter, array);
		free(first_command);
	}
	return (0);
}
