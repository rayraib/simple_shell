#include "shell.h"

/**
 * print_str - prints string
 * @ap: input a va_list
 * Return: number of chars printed
 */
int print_str(va_list ap)
{
	int result = 0;
	char *s = va_arg(ap, char *);

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (-1);
	}
	for ( ; *s != '\0'; s++, result++)
		_putchar(*s);
	return (result);
}
