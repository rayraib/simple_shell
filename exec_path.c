#include "shell.h"
/**
* exec_path - concatenates two string with '/' in between, '\0' terminated
* @dir: first string to concatenate
* @filename: second string to concatenate
* Return: pointer to the new concatenated string, NULL if failure
*/
char *exec_path(char *dir, char *filename)
{
	int dir_len;
	int file_len;
	int i, j;
	char *f_arg;

	dir_len = _strlen(dir);
	file_len = _strlen(filename);
	f_arg = malloc(sizeof(char) * (file_len + dir_len + 2));/*for new string*/
	if (f_arg == NULL)
		return (NULL);
	for (i = 0; dir[i] != '\0'; i++)
	{
		f_arg[i] = dir[i];
	}
	f_arg[i] = '/';
	i++;
	for (j = 0; filename[j] != '\0'; j++)
	{
		f_arg[i] = filename[j];
		i++;
	}
	f_arg[i] = '\0';
	return (f_arg);
}
