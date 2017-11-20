#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdarg.h>
/**
 * struct func_e - struct to store specifier with respective function
 * @c: format specifier
 * @f: function ptr that takes parameter of type va_list
 */
typedef struct func_e
{
	char c;
	int (*f)(va_list);
} func_f;
/**
* struct run_built - struct to store input command with respective function
* @builtin:  pointer to input string
* @builtcmd: pointer to a function
*/
typedef struct run_built
{
	char *builtin;
	void (*builtcmd)(char *buffer);
} buil_t;

int _printf(const char *format, ...);
int print_rev(va_list ap);
int _putchar(int c);
int print_char(va_list ap);
int print_str(va_list ap);
int print_int(va_list ap);
int spec_func(va_list args, char c);
void check4builtin(char *buffer);
void _my_exit(char *buffer);
void _print_env(char *buffer);
void err_msg(int z, int ch, char *f_com, char *arg);
int not_valid(int z, char *ar, int t_c, char *buffer, char *f_c, char **array);
char *exec_path(char *dir, char *filename);
extern char **environ;
int _strlen(char *s);
char *check_input(void);
int find_path(void);
char *get_command(char *buffer);
int find_command(int z, char *arg, int index, char *filename, char **array);
char  *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *s);
int create_child(int z, int ch, char *f_com, char *arg, char **array);
int token_count(char *f_com, char *buffer);
char **create_array(char *first_com, int token_cnt, char *buffer);
void free_array(int token_cnt, char **array);
void free_things(char *b, char *d, struct stat *st, char *p, char *f);
#endif
