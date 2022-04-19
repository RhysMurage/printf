#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int _putchar(char c);
int _printf(const char *format, ...);
int put_str(char *str);
int put_int(long n);
int get_printing_func(char a, va_list *ap);
int put_rot13(char *s);
char *rot13(char *s);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int put_binary(unsigned int n);

#endif /* _MAIN_H_ */
