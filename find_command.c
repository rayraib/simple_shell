#include "shell.h"
char *get_first_dir(char *path);
void err_msg(char *filename);
void final_free(char *buffer, struct stat *st, char *path);
/**
* find_command - splits directory, goes into and checks for filename
* @index: index of where PATH variable is
* @filename: command to look for
* @array: pointer to an array of poitners to char
* Return: success 0, otherwise -1
*/
int find_command(int index, char *filename, char **array)
{
	char *buffer, *dir, *cur_dir, *path, *token, *f_arg;
	char *delim = "=:\n";
	int child_ret;
	struct stat *st = NULL;
	(void) index;

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
			child_ret = create_child(array);
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
	err_msg(filename);	
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
*/
void err_msg(char *filename)
{
	if (filename[0] == '/')
	{
		write(1, "-bash: ",7);
		write(1, filename, _strlen(filename));
		perror(" ");
	}
	else
	{
		write(1, filename, _strlen(filename));
		write(1, ": command not found\n", 20);
	}
}
