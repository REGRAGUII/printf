#include "main.h"
/**
 * _printf - function that prints a formatted string.
 * @format: Characters of string
 * Return: The number of char printed.
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	unsigned int h = 0;

	r_value = 0;

	for ( ; format[h] != '\0' ; h++)
	{
		if (format[h] != '%')
		{
			putchr(format[h]);
		}
		else if (format[h + 1] == 'c')
		{
			putchr(va_arg(args, int));
			h++;
		}
		else if (format[h + 1] == "%")
		{
			putchr('%');
			h++;
		}
		r_value += 1;
	}
	return (r_value);
}
