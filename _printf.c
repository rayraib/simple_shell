#include "shell.h"

/**
 * _printf - produces output according to a format
 * @format: char string
 * Return: num of chars printed, -1 if format is NULL
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int j, result = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format); /* pts to 1st optional arg */
	for (j = 0; format[j]; j++)
	{
		if (format[j] != '%')
			result += _putchar(format[j]);
		else
		{
			j++;
			result += spec_func(args, format[j]); /* each loop makes successive calls to va_arg */
		}
	}
	va_end(args);
	return (result);
}
