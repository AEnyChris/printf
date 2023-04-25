#include "main.h"


/**
 * print_binary - prints unsigned number as binary
 * @types: list of arguments
 * @buffer: Buffer array to handle print
 * @flags:  active flags
 * @width: width of to be printed
 * @precision: precision specification
 * @size: size of bin to be printed
 * Return: number of characters printed.
 */

int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int c, d, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	c = va_arg(types, unsigned int);
	d = 2147483648; /* (2 ^ 31) */
	i = 1;
	a[0] = c / d;
	while (i < 32)
	{
		d /= 2;
		a[i] = (c / d) % 2;
		i++;
	}
	i = 0;
	sum = 0;
	count = 0;
	while (i < 32)
	{
		sum += a[i];
		if (i == 31 || sum)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
		i++;
	}
	return (count);
}
