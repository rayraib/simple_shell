#include "shell.h"
/**
* main - entry point to a basic functional shell
* @ac: count of arguments passed
* @argv: Pointer to an array of pointer to string of arguments passed in cmdl
* Return: 0 succes, otherwise -1
*/
int main(int ac, char **argv)
{
	char *buffer, *fc = NULL;
	char **array = NULL;
	int z, tok_cnt, index, not_va_ret;/*, command_ret;*/
	(void) ac;

	z = 0;
	while (1)
	{
		z++;
		buffer = check_input();/*gets arguments from stdin*/
		if (buffer == NULL)
		/*	free(buffer);*/
			return (-1);
		index = find_path();/*index of PATH varible*/
		if (index == -1)
			continue;
		fc = get_command(buffer);/*get the first argument*/
		if (fc == NULL)
			continue;
		tok_cnt = token_count(fc, buffer);/*number of args passed*/
		if (tok_cnt == -1)
			continue;
		array = create_array(fc, tok_cnt, buffer);
								/*array of pointers to args*/
		if (array == NULL)
			return (-1);
		not_va_ret = not_valid(z, argv[0], tok_cnt, buffer, fc, array);
		if (not_va_ret == 0 || not_va_ret == 1)
		{
			free(fc);
			continue;
		}
		find_command(z, argv[0], index, fc, array);/*find cmmnd & exec*/
		free(buffer);
		free_array(tok_cnt, array);
		free(fc);
	}
	return (0);
}
