#include "shell.h"
/**
* free_things - frees the argument pointers
* @dir: first argument
* @cur_dir: second argument
* @st: third argument
* @path: fourth argument
*/
void free_things(char *d, char *cd, struct stat *st, char *p, char *f)
{
	free (d);
	free (cd);
	free (st);
	free (p);
	free (f);
}
	
