#include <stdio.h>
#include <unistd.h>
#include "main.h"
#include <stdarg.h>

/**
  *_printf- function that produces output according to a format
  * @format: pointer to a constant character
  *
  * Return: number of characters printed
  */

int _printf(const char *format, ...)
{
	/* Total number of chars printed to stdout */
	int char_count = 0;

	/* Contains the list of arguments passed after format */
	va_list ap;

	/* Used to loop through all characters in format */
	int i;

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
