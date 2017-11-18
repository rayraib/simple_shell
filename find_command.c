#include "shell.h"
/**
* find-command: splits directory, goes into and checks for filename
* @index: index of where PATH variable is
* Return: success 0, otherwise -1
*/
int find_command(int index, char *filename, char **array)
{
	char *buffer, *dir, *cur_dir, *path, *token, *f_arg;
	char *delim = "=:\n";
	int child_ret;
	struct stat *st = NULL;

	buffer = cur_dir = path = token = f_arg = NULL;
	path = _strdup(environ[index]);/*copy the PATH env varible string */
	if (path == NULL)
		return (-1);
	token = strtok(path, delim);/*tokenize the string to get the first directory to check for filename*/
	if (token == NULL)
	{
		free (path);
		return (-1);
	}
	token = strtok(NULL, delim);/*tokenize the string to get the first directory to check for filename*/
	if (token == NULL)
	{
		free (path);
		return (-1);
	}
	st = malloc(sizeof(struct stat));
	if (st == NULL)
	{
		free (path);
		free (st);
		return (-1);
	}
/*	cur_dir = getcwd(buffer, n);*//*get the current directory of the user*/
	/* CHECK CUR_DIR ?? */
	do
	{
		dir = _strdup(token);/*copy the directory to check for filename*/
		f_arg = exec_path(dir, filename);
		if (stat (f_arg, st) == 0)
		{
			array[0] = f_arg;	
			child_ret = create_child(array);
			if (child_ret == -1)
				return (-1); 
			free_things(buffer, dir, st, path, f_arg);
				return (0);
		}
		token = strtok(NULL, delim);/* filename not found yet, tokenize the next directory to check for filename again*/
		free (dir);
		free (f_arg);
	} while (token != NULL);
/*	chdir(cur_dir); *//*change back to previous directory of user*/
	perror ("CNT in find_command ");
	free_things(buffer, dir, st, path, f_arg);
	return (-1);
}
