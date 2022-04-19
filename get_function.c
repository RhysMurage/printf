#include "main.h"

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
