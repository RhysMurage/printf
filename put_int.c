#include "main.h"

/**
 * put_int - prints the integer passed
 * @n: the number to be printed
 *
 * Return: the number of characters printed or the number of digits in @n
 */
int put_int(long n)
{
	long i = 1; /* Holds how many digits n has */
	long char_count = 0;

	/**
	 * if n is zero, just print zero
	 */
	if (n == 0)
	{
		_putchar(48);
		return (1); /* Because 0 has 1 digit only */
	}

	/**
	 * If n is negative, put the '-' sign and replace n by its
	 * absolute value
	 */
	if (n < 0)
	{
		n /= -1;
		_putchar(45);
		if (n == -2147483648)
		{
			n = 147483648;
			_putchar(50);
			char_count++;
		}
		char_count++;
	}
	while (n / i >= 10)
	{
		i *= 10;
	}
	while (i != 0)
	{
		_putchar(((n / i) % 10) + 48);
		i /= 10;
		char_count++;
	}

	return (char_count);
}
