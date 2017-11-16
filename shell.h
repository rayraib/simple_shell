#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int _strlen(char *s);
char  *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char * _strdup(char *s);
void free_array(char **grid, int height);
int create_child (char **array);
int token_count(char *buffer);
char **create_array(int token_cnt, char *buffer);
void free_array(char **grid, int height);
#endif
