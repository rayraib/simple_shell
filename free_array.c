#include "shell.h"
/**
* free_array - frees an array of pointers
* @token_cnt: number of array members to be freed
* @array: pointer to the array of pointers
*/
void free_array(int token_cnt, char **array)
{
	/*
	while (array != NULL)
	{
		free(array[token_cnt - 1]);
		token_cnt--;
	}
	*/
	printf("token counter :   %d\n", token_cnt);
	free (array);
}
