#include "shell.h"
/**
* main - entry point to a basic functional shell
* Return: 0 succes, otherwise -1
*/
int main(void)
{
	char *buffer = NULL;
	char *first_command = NULL;
	int token_counter;
	char **array = NULL;
	int index;
	int command_ret;
	
	while (1)
	{
		buffer = check_input();
		if (buffer == NULL)
		{
			free (buffer);
			return (-1);
		}
		index = find_path();
		if (index == -1)
		{
			perror(" ");
			continue;
		}
		first_command = get_command(buffer);
		if (first_command == NULL)
		{
			continue;
		}
		token_counter = token_count(buffer);
		if (token_counter == -1)
		{
			printf("something here\n");
		}
		array = create_array(token_counter, buffer);
		if (array == NULL)
		{
			return (-1);
		}
		command_ret = find_command(index, first_command, array);
		if (command_ret == -1)
		{
			perror(" ");
		}
		if (not_valid(buffer, first_command, array) == 0)
		{
			free (buffer);
		}
	}
	return (0);
}
