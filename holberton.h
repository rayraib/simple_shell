#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

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

int _printf(const char *format, ...);
int print_rev(va_list ap);
int _putchar(int c);
int print_char(va_list ap);
int print_str(va_list ap);
int print_int(va_list ap);
/*int print_unsigned(va_list ap);
int print_binary(va_list ap);
int print_octal(va_list ap);
int print_hex_lower(va_list ap);
int print_hex_upper(va_list ap);
int print_rev(va_list ap);
int print_rot(va_list ap);
*/
int spec_func(va_list args, char c);

#endif /* _HOLBERTON_H_ */
