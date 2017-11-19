#include "shell.h"
/**
* find_path - finds the PATH environment variable
* Return: index of PATH variable if success, otherwise -1
*/
int find_path(void)
{
	int i, j;
	char *a = "PATH";

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (a[j] != environ[i][j])
				break;
		}
		if (environ[i][j] == '=' && j == 4)
			return (i);
	}
	return (-1);
}
