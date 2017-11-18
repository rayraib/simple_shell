#include "shell.h"
/**
* free_things - free the argument pointers
* @b: first argument
* @d: second argument
* @st: third argument
* @p: fourth argument
* @f: fifth arguemnt to free
*/
void free_things(char *b, char *d, struct stat *st, char *p, char *f)
{
	free(b);
	free(d);
	free(st);
	free(p);
	free(f);
}
