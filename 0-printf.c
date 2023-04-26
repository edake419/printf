#include "main.h"

/**
 * _printf - Print formatted output.
 * @format: Format string.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	va_list arguments;
	int printed = 0;

	va_start(arguments, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				char c = va_arg(arguments, int);
				putchar(c);
				printed++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(arguments, char *);

				while (*s)
				{
					putchar(*s);
					s++;
					printed++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				printed++;
			}
		}
		else
		{
			putchar(*format);
			printed++;
		}

		format++;
	}

	va_end(arguments);

	return (printed);
}
