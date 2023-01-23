#include <unistd.h>
#include <stdarg.h>

/**
 * lq_strlen - Retrieves the length of a string
 *
 * @s: Input string
 *
 * Return: Length of s
 */
int lq_strlen(char *s)
{
    if (s == NULL || s[0] == 0)
        return (0);
    return (1 + lq_strlen(&s[1]));
}

/**
 * _prints - Prints a string to the standard output
 *
 * @s: Input string
 *
 * Return: Number of bytes written to STDOUT
 */
int _prints(char *s)
{
    if (s == NULL)
        return (0);
    return (write(STDOUT_FILENO, s, lq_strlen(s)));
}

/**
 * _printc - Prints a string to the standard output
 *
 * @c: Input character
 *
 * Return: Number of bytes written to STDOUT (1)
 */
int _printc(char c)
{
    return (write(STDOUT_FILENO, &c, 1));
}

/**
 * _printf - Prints the arguments passed to the standard output
 *
 * @format: Character string to be outputted to the standard output
 *
 * Return: Number of bytes written to the stdout
 */
int _printf(const char *format, ...)
{
    int count;
    va_list args;

    count = 0;
    va_start(args, format);
    while (*format)
    {
            char tmp;
    
            tmp = *format++;
            if (tmp == '%')
            {
	                tmp = *format++;
	                switch (tmp)
	                {
			            case 'c':
			                count += _printc(va_arg(args, int));
			                break;
			            case 's':
			                count += _prints(va_arg(args, char *));
			                break;
			            default:
			                break;
			            }
	            } else
            {
	                count += _printc(tmp);
	            }
        }
    va_end(args);
    return (count);
}
