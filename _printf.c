#include "main.h"
#include <stdlib.h>

/**
 * get_printing_func - runs a function based on the specifier @a passed
 * @a: the format specifier
 * @ap: the list of arguments passed to the _printf function
 *
 * Return: the number of characters printed (depends on which function is
 * called)
 *		  1 if there is there is no corresponding function for the specifier
 */
int get_printing_func(char a, va_list *ap)
{
	char *s, *ss;
	int x;

	if (a == 'c')
		return (_putchar(va_arg(*ap, int)));
	else if (a == 's')
		return (put_str(va_arg(*ap, char*)));
	else if (a == 'i' || a == 'd')
		return (put_int(va_arg(*ap, int)));
	else if (a == 'b')
		return (put_binary((unsigned int) va_arg(*ap, int)));
	else if (a == 'R')
	{
		ss = va_arg(*ap, char *);
		s = malloc(sizeof(char) * _strlen(ss));
		_strcpy(s, ss);

		x = put_rot13(s);

		free(s);
		return (x);
	}

	/**
	 * If all if's fail, just print % and the passed character without
	 * considering it as a format specifier
	 */
	 _putchar('%');
	if (a == '%')
	{
		return (1);  /* Only % will be printed if a is % */
	}

	_putchar(a);
	return (2); /* Since the number of characters printed is 2 only */
}

/**
 * _printf - clone of the function printf in stdio.h
 * @format: the string to be printed along with format specifiers preceded by %
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int char_count = 0; /* Total number of chars printed to stdout */
	va_list ap; /* Contains the list of arguments passed after format */
	int i; /* Used to loop through all characters in format */

	va_start(ap, format);

	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != 0; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			char_count++;
			continue;
		}

		if (format[i + 1] == '\0')
		{
			return (-1);
		}

		char_count += get_printing_func(format[i + 1], &ap);
		i++;
	}
	return (char_count);
}
