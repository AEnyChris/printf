#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - the main printf function
 * @format: format string to print
 * Return: count of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, char_count = 0;
	int flag, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];
	
	i =0;
	if (format == NULL)
		return (-1);
	va_start(list, format);
	while (format && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			char_count++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flag = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
					flag, width, precision, size);
			if (printed == -1)
				return (-1);
			char_count += printed;
		}
		i++;
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (char_count);
}
/**
 * print_buffer - Prints the contents of the buffer
 * @buffer: Array of characters
 * @buff_ind: Index of the next char.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
