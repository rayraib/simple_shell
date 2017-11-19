#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
void err_msg(char *filename);
int not_valid(int token_cnt, char *buffer, char *f_com, char **array);
char *exec_path(char *dir, char *filename);
extern char **environ;
int _strlen(char *s);
char *check_input(void);
int find_path(void);
char *get_command(char *buffer);
int find_command(int index, char *filename, char **array);
char  *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *s);
int create_child(char **array);
int token_count(char *buffer);
char **create_array(int token_cnt, char *buffer);
void free_array(int token_cnt, char **array);
void free_things(char *b, char *d, struct stat *st, char *p, char *f);
#endif
