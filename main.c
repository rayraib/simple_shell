#include "shell.h"
/**
* main - entry point to a basic functional shell
* Return: 0 succes, otherwise -1
*/
int main(void)
{
	char *buffer, *first_command = NULL;
/*	char *first_command = NULL;*/
	int token_counter;
	char **array = NULL;
	int index;/*, command_ret;*/
	
	while (1)
	{
		buffer = check_input();/*gets arguments from stdin:/BUFFER)*/
		if (buffer == NULL)
		{
			free (buffer);
			return (-1);
		}
		index = find_path();/*index of PATH varible::/BUFFER */
		if (index == -1)
		{
			perror(" ");
			continue;
		}
		first_command = get_command(buffer);/*get the first argument/ BUFFER, FIRST_COMMAND */
		if (first_command == NULL)
		{
			free (buffer);
			continue;/*no need free FIRST_COMMAND because never exited >> Null)*/
		}
		token_counter = token_count(buffer);/*number of arguments pased >> BUFFER, FIRST_COMMAND */
		if (token_counter == -1)
		{
			free (buffer);
			free (first_command);
			printf("something here\n");
		}
		array = create_array(token_counter, buffer);/*array of pointers to args>> BUFFER, FIRST_cOMMAND, ARRAY*/
		if (array == NULL)
		{
			free (buffer);
			free (first_command);
			return (-1);
		}
		if (not_valid(buffer, first_command, array) == 0)/*it was successfull, command executed */
		{
			free (first_command);
			perror (first_command);
			continue;	
		}
		find_command(index, first_command, array);/*find command and execute it>> BUFFER, FIRST_COMMAND, ARRAY*/
	/*	if (command_ret == -1)
		{
			perror(" ");
		}
	*/
		free (buffer);
		free (array);
		free (first_command);
	}
	return (0);
}
