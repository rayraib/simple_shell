#include "holberton.h"

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
/*		{'c', print_char},*/
		{'s', print_str},
		{'d', print_int},
		{'i', print_int},
	/*	{'u', print_unsigned},
		{'b', print_binary},
		{'o', print_octal},
		{'x', print_hex_lower},
		{'X', print_hex_upper},
		{'S', custom_s},
		{'r', print_rev},
		{'R', print_rot},
	*/	
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
