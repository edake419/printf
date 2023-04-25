#include "main.h"

/**
*_printf - printf function
*@format: string format
*Return: Printed arguments
*/

int _printf(const char *format, ...)
{
    int printed = 0;
    va_list arguments;
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
                char *s = va_arg(arguments, char*);
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
    return printed;
}
