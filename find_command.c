#include "shell.h"
char *get_first_dir(char *path);
/*void err_msg(char *filename);*/
void final_free(char *buffer, struct stat *st, char *path);
/**
* find_command - splits directory, goes into and checks for filename
* @z: counter of how many times the main function has looped
* @index: index of where PATH variable is
* @filename: command to look for
* @arg: arg[0], executables's name
* @array: pointer to an array of poitners to char
* Return: success 0, otherwise -1
*/
int find_command(int z, char *arg, int index, char *filename, char **array)
{
	char *buffer, *dir, *cur_dir, *path, *token, *f_arg;
	char *delim = "=:\n";
	int child_ret, ch = 1;
	struct stat *st = NULL;

	buffer = cur_dir = path = token = f_arg = NULL;
	path = _strdup(environ[index]);/*copy the PATH env varible string */
	if (path == NULL)
		return (-1);
	token = get_first_dir(path);/*get the first directory to check for filename*/
	if (token == NULL)
		return (-1);
	st = malloc(sizeof(struct stat));
	if (st == NULL)
	{
		free(path);
		free(st);
		return (-1);
	}
	do {
		dir = _strdup(token);/*copy the directory to check for filename*/
		f_arg = exec_path(dir, filename);
		if (stat(f_arg, st) == 0)
		{
			free(array[0]);
			array[0] = f_arg;
			child_ret = create_child(z, ch, filename, arg, array);
			if (child_ret == -1)
				return (1);
			free_things(buffer, dir, st, path, f_arg);
				return (0);
		}
		token = strtok(NULL, delim);/*tokenize next dir*/
		free(dir);
		free(f_arg);
	} while (token != NULL);
	free(array[0]);
	err_msg(z, ch, arg, filename);
	final_free(buffer, st, path);
	return (-1);
}
/**
* get_first_dir - gets the first directory in path
* @path: PATH env variable string
* Return: pointer to the first dir
*/
char *get_first_dir(char *path)
{
	int k;
	char *token = NULL;
	char *delim = "=:\n";

	for (k = 0; k < 1; k++)
	{
		token = strtok(path, delim);
		if (token == NULL)
		{
			free(path);
			return (NULL);
		}
		token = strtok(NULL, delim);
	}
	return (token);
}
/**
* final_free - free three arguemtns
* @buffer: first arg
* @st: second arg
* @path: third arg
*/
void final_free(char *buffer, struct stat *st, char *path)
{
	free(buffer);
	free(st);
	free(path);
}
/**
* err_msg - prints message to stdou
* @filename: pointer to char string
* @count: count of how many times the main function has looped
* @check: flag for where the error msg originatd from
* @arg: name of the executable file
*/
void err_msg(int count, int check, char *arg, char *filename)
{
	if (check == 1)
		_printf("%s: %d: %s: not found\n", arg, count, filename);
	if (check == 2)
		_printf("%s: %d: %s: Permission denied\n", filename, count, arg);
}
