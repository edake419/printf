#include "main.h"

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
