#include "main.h"
#include <stdarg.h>
#include <stdio.h>

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
	int printed = 0;

	if (!format)
		return -1;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				char c = va_arg(args, int);
				putchar(c);
				printed++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);
				if (s)
				{
					while (*s)
					{
						putchar(*s);
						printed++;
						s++;
					}
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				printf("%d", num);
				printed++;
			}
			else if (*format == '%')
			{
				putchar('%');
				printed++;
			}
		}
		else
		{
			putchar(*format);
			printed++;
		}

		format++;
	}

	va_end(args);

	return printed;
}
