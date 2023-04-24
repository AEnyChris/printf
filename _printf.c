#include <stdarg.h>
#include "main.h"
#include <stdio.h>
/**
 * print_all - print formated string
 * @format: string of types of input argument
 *
 * Return: void
 */

int _printf(const char *const format, ...)
{
	va_list ar;
	int i = 0;
	int j = 0;
	int char_count = 0;
	char *str;

	va_start(ar, format);
	if (format)
	{
	while (format[i])
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					_putchar(va_arg(ar, int));
					char_count++;
					break;
				case 's':
					str = va_arg(ar, char *);
					while (*str != '\0')
					{
						_putchar(str[j]);
						char_count++;
						j++;
					}
					break;
				case '%':
					_putchar('%');
					char_count++;
					break;
				default:
					i++;
					continue;
			}
		}
		_putchar(format[i]);
		char_count++;
		i++;
	}
	}

	va_end(ar);
	return (char_count);
}
