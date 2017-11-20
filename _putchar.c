#include "shell.h"
#include <unistd.h>

/**
 * _putchar - writes char to stdout
 * @c: input a char
 * Return: number of bytes in count
 */
int _putchar(int c)
{
	return (write(2, &c, 1));
}
