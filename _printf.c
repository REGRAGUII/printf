#include "header.h"
/**
 * _printf - function that prints a formatted string.
 * @format: Characters of string
 * Return: The number of char printed.
 */
int _printf(const char *format, ...)
{
	int h, r_value = 0;
	va_list args;

	va_start(args, format);

	for (*format != '\0' ; h++)
	{
		if (*format != '%')
		{
			putchr(*format[);
		}
		else if (*format == 'c')
		{
			putchr(va_arg(args, int));
			h++;
		}
		else if (*format == 's')
		{
		int r_val = put_s(va_arg(args, char *));

			r_value += (r_val - 1);
			h++;
		}
		else if (*format == "%")
		{
			putchr('%');
			h++;
		}
		else if ((*format == 'd') || (*format == 'i'))
		{
			put_int(va_arg(args, int));
			h++;
		}
		r_value += 1;
	}
	return (r_value);
}
