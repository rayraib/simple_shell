#include "shell.h"
#include <stdio.h>
/**
 * _strcmp - function that compares two strings to see if they match
 * @s1: first string to compare
 * @s2: second string to compare/
 * Return: 0 if two strings are same, else a non-zero int.
 */
int _strcmp(char *s1, char *s2)
{
	int i;
    /* loop through until a null byte is reached for either string
        and compare each char at the same index */
	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] == s2[i])
		continue;
		else
			break;
	}
	return (s1[i] - s2[i]);
}

/**
 * _printf - Print output to stdout according to a format
 * @format: pointer to a char string to print
 * Return: num of chars printed, or -1 if format is NULL
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
			result += spec_func(args, format[j]);
		}
	}
	va_end(args);
	return (result);
}

/**
 * _putchar - writes char to stdout
 * @c: input a char
 * Return: number of bytes in count
 */
int _putchar(int c)
{
	return (write(2, &c, 1));
}
/**
 * _strcpy - copy one string into another array
 * @dest: pointer to an array
 * @src: pointer to a string
 * Return: Always 0.
 */
char  *_strcpy(char *dest, char *src)
{

	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
/**
 * _strdup - copy string to a new mememory location
 * @s: pointer to string that is to be copied
 * Return: pointer to newly allocated memory location
 */
char *_strdup(char *s)
{
	int len;
	char *new_location;

	len = _strlen(s);
	new_location = malloc(len + 1);
	if (new_location == NULL)
		return (NULL);
	_strcpy(new_location, s);
	return (new_location);
}
/**
 * _strlen - calculate the length of a string
 * @s: string
 * Return: Always i.
 */
int _strlen(char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
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
