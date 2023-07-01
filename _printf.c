#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - prints a formatted string to stdout, similar to printf.
 * @format: the format of the string to be printed.
 *
 * This function prints a formatted string to the stdout stream. It
 * accepts a format string as its first argument and any additional arguments
 * will be used to replace format specifiers in the format string.
 *
 * Return: the number of characters printed to the stdout stream.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, printed = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	for (; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				printed += putchar('%');
				i++;
				continue;
			}
			else if (format[i + 1] == 'c')
			{
				char c = va_arg(args, int);
				printed += putchar(c);
				i++;
				continue;
			}
			else if (format[i + 1] == 's')
			{
				char *s = va_arg(args, char *);
				if (s)
					printed += puts(s);
				else
					printed += puts("(null)");
				i++;
				continue;
			}
			else
			{
				printed += putchar('%');
				continue;
			}
		}

		printed += putchar(format[i]);
	}

	va_end(args);
	return (printed);
}
