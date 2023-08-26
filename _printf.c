#include <stdarg.h>
#include <stdio.h>
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    char c;

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
                case 'c':
                    c = (char)va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                case 's':
                    {
                        char *str = va_arg(args, char *);
                        while (*str != '\0')
                        {
                            putchar(*str);
                            count++;
                            str++;
                        }
                    }
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}

int main(void)
{
    int len = _printf("Hello, %s! I am a %c%% character.\n", "world", 'F');
    printf("Length: %d\n", len);

    return 0;
}

