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
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(arguments, int);
				if (num < 0)
				{
					num = -num;
					putchar('-');
					printed++;
				}
				printed += print_number(num);
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

/**
 * print_number - Print a number.
 * @n: Number to print.
 *
 * Return: Number of digits printed.
 */
int print_number(int n)
{
	int digits = 0;
	int i;
	int divisor = 1000000000;

	if (n == 0)
	{
		putchar('0');
		return (1);
	}

	while (n / divisor == 0 && divisor > 1)
		divisor /= 10;

	for (i = divisor; i >= 1; i /= 10)
	{
		if (n / i != 0 || digits > 0 || i == 1)
		{
			putchar('0' + n / i);
			n %= i;
			digits++;
		}
	}

	return (digits);
}
