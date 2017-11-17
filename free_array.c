#include "shell.h"
void free_array(char **grid, int height)
{
/* 	int i;*/

	if (grid == NULL || height == 0)
		return;
/*	for (i = 0; i < height; i++)
		free(grid[i]);
*/
	free(grid);
}
