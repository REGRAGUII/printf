#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
/**
 * struct types - specifier structure for printf
 * @ch: pointer to char specifier
 * @func_ptr: pointer to va_list functuions.
 *
 */
typedef struct types
{
	char ch;
	int (*func_ptr)(va_list);
} print_func;

int _printf(const char *format, ...);
int _putchar(char q);
int print_c(va_list c);
int print_string(va_list s);
int (*func(const char a))(va_list);
int print_num(va_list n);
int print_int(va_list n);




#endif
