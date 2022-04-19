#include "main.h"
#include <stdlib.h>

/**
 * put_rot13 - prints the rot13 converted version of @s
 * @s: the string to be converted to rot13
 *
 * Return: the number of characters printed
 */
int put_rot13(char *s)
{
	char *rot13 = malloc(_strlen(s));
	int i, j, x;
	char letter_normal[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char letter__rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";


	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; letter_normal[j] != '\0'; j++)
		{
			if (s[i] == letter_normal[j])
			{
				rot13[i] = letter__rot13[j];
				break;
			}
		}
	}
	x = put_str(rot13);

	free(rot13);
	return (x);
}
