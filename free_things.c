#include "shell.h"
/**
* free_things - free the argument pointers
* @b: first argument
* @d: second argument
* @st: third argument
* @p: fourth argument
* @f: fifth arguemnt to free
*/
void free_things(char *buffer, char *delim,
				  struct stat *stat, char *path, char *first_arg)
{
	free(buffer);
	free(delim);
	free(stat);
	free(path);
	free(first_arg);
}
