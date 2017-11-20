#include "shell.h"
/**
* check4builtin - checks if the buffer contains string "exit" or "env"
* @buffer: Pointer to string to check
*/
void check4builtin(char *buffer)
{
	buil_t run_built[] = {
		{"exit\n", _my_exit},
		{"env\n", _print_env},
		{NULL, NULL}
	};
	int index = 0;

	while (run_built[index].builtin != NULL)
	{
		if (_strcmp(buffer, run_built[index].builtin) == 0)
			run_built[index].builtcmd(buffer);
		index++;
	}
}
