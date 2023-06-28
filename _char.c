#include "main.h"
/**
 * print_char - characters.
 * @vl: arguments.
 * Return: 1.
 */
int print_char(va_list vl)
{
	char str;

	str = va_arg(vl, int);
	_putchar(str);
	return (1);
}
