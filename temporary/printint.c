#include "shell.h"

/**
 * print_int - prints an int
 * @ap: va_list input
 * Return: number of chars printed
 */
int print_int(va_list ap)
{
	unsigned int place = 1, result = 0, num;
	int n = va_arg(ap, int);

	if (n < 0)
	{
		num = -n;
		result += (_putchar('-'));
	}
	else
		num = n;
	while (num / place >= 10)
		place *= 10;
	while (place > 0)
	{
		result += _putchar((num / place) % 10 + '0');
		place /= 10;
	}
	return (result);
}
