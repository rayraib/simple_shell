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
	int index;/*, command_ret;*/

	while (1)
	{
		buffer = check_input();/*gets arguments from stdin*/
		if (buffer == NULL)
		{
			free(buffer);
			return (-1);
		}
		index = find_path();/*index of PATH varible*/
		if (index == -1)
		{
			perror("path not found in main ");
			continue;
		}
		first_command = get_command(buffer);/*get the first argument*/
		if (first_command == NULL)
		{
			free(buffer);
			continue;
		}
		token_counter = token_count(buffer);/*number of args passed*/
		if (token_counter == -1)
		{
			free(buffer);
			free(first_command);
			printf("something here in main\n");
		}
		array = create_array(token_counter, buffer);
								/*array of pointers to args*/
		if (array == NULL)
		{
			free(buffer);
			free(first_command);
			return (-1);
		}
		if (not_valid(buffer, first_command, array) == 0)/*command executed */
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
