#include "main.h"

/**
 * print_char - prints a character to stdout
 * @typs: list of args
 * @buff: buffer array to carry print strings
 * @flg:  the active flags
 * @wid: Width
 * @precs: handles precision specification
 * @size: specified size
 * Return: number of printed characters
 */

int print_char(va_list typs, char buff[],
		int flg, int wid, int precs, int size)
{
	char c = va_arg(typs, int);

	return (handle_write_char(c, buff, flg, wid, precs, size));
}

/**
 * print_string - prints a string
 * @typs: list of args
 * @buff: buffer array to carry print strings
 * @flg:  the active flags
 * @wid: Width
 * @precs: handles precision specification
 * @size: specified size
 * Return: number of printed characters
 */


int print_string(va_list typs, char buff[],
		int flg, int wid, int precs, int size)
{
	int len = 0, i;
	char *str = va_arg(typs, char *);

	UNUSED(buff);
	UNUSED(flg);
	UNUSED(wid);
	UNUSED(precs);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precs >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;
	if (precs >= 0 && precs < len)
		len = precs;
	if (wid > len)
	{
		if (flg & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = wid - len; i > 0; i--)
				write(1, " ", 1);
			return (wid);
		}
		else
		{
			for (i = wid - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (wid);
		}
	}
	return (write(1, str, len));
}


/**
 * print_percent - prints the percent sign
 * @typs: list of args
 * @buff: buffer array to carry print strings
 * @flg:  the active flags
 * @wid: Width
 * @precs: handles precision specification
 * @size: specified size
 * Return: number of printed characters
 */

int print_percent(va_list typs, char buff[],
		int flg, int wid, int precs, int size)
{
	UNUSED(typs);
	UNUSED(buff);
	UNUSED(flg);
	UNUSED(wid);
	UNUSED(precs);
	UNUSED(size);
	return (write(1, "%%", 1));
}
