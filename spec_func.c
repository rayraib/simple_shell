#include "shell.h"

/**
 * spec_func - chooses function based on format specifier
 * @args: va_list
 * @c: input a char
 * Return: number of chars printed
 */
int spec_func(va_list args, char c)
{
	int i = 0;
	func_f arg_list[] = {
		{'s', print_str},
		{'d', print_int},
		{'i', print_int},
		{'\0', NULL},
	};

	while (arg_list[i].c)
	{
		if (c == arg_list[i].c)
			return (arg_list[i].f(args));
		i++;
	}
	if (c == '%')
		return (_putchar('%'));
	else if (c == '\0' || c == ' ')
		return (-1);
	return (_putchar('%') + _putchar(c));
}
