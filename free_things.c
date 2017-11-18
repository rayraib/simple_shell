#include "shell.h"
/**
* free_things - free the argument pointers
* @dir: first argument
* @cur_dir: second argument
* @st: third argument
* @path: fourth argument
*/
void free_things(char *b, char *d, struct stat *st, char *p, char *f)
{
	free (b);
	free (d);
	free (st);
	free (p);
	free (f);
}
	
