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
		else if (format[h + 1] == 's')
		{
		int r_val = put_s(va_arg(args, char *));

			r_value += (r_val - 1);
			h++;
		}
		else if (format[h + 1] == "%")
		{
			putchr('%');
			h++;
		}
		else if ((format[h + 1] == 'd') || (format[h + 1] == 'i'))
		{
			put_int(va_arg(args, int));
			h++;
		}
		r_value += 1;
	}
	return (r_value);
}
