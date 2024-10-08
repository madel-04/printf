#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

// Función auxiliar para escribir un carácter
void ft_putchar(char c)
{
    write(1, &c, 1);
}

// Función auxiliar para escribir una cadena
void ft_putstr(char *str)
{
    while (*str)
        ft_putchar(*str++);
}

// Función auxiliar para convertir un número en base
char *ft_convert_base(unsigned long long num, int base, int uppercase)
{
    char *digits;
    char buffer[65];
    char *ptr;

    digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    ptr = &buffer[64];
    *ptr = '\0';
    if (num == 0)
        return (strdup("0"));
    while (num)
    {
        *--ptr = digits[num % base];
        num /= base;
    }
    return (strdup(ptr));
}

// Función para imprimir con padding y alineación
void print_padded(char *str, int width, char pad_char, int left_align)
{
    int len = 0;
    while (str[len])
        len++;
    if (!left_align && pad_char != '\0')
        while (width-- > len)
            ft_putchar(pad_char);
    ft_putstr(str);
    if (left_align)
        while (width-- > len)
            ft_putchar(' ');
}

// Parsing de flags, ancho y precisión
void parse_flags(const char **format, int *width, int *left_align, char *pad_char, int *precision)
{
    *width = 0;
    *left_align = 0;
    *pad_char = ' ';
    *precision = -1;

    if (**format == '-')
    {
        *left_align = 1;
        (*format)++;
    }
    if (**format == '0')
    {
        *pad_char = '0';
        (*format)++;
    }
    while (**format >= '0' && **format <= '9')
    {
        *width = *width * 10 + (*(*format)++ - '0');
    }
    if (**format == '.')
    {
        *precision = 0;
        (*format)++;
        while (**format >= '0' && **format <= '9')
        {
            *precision = *precision * 10 + (*(*format)++ - '0');
        }
    }
}

// Manejo de conversiones
void handle_conversion(const char **format, va_list args, int width, int left_align, char pad_char, int precision)
{
    if (**format == 'c')
        print_padded((char[]){(char)va_arg(args, int), '\0'}, width, pad_char, left_align);
    else if (**format == 's')
        print_padded(va_arg(args, char *), width, pad_char, left_align);
    else if (**format == 'd' || **format == 'i')
        print_padded(ft_convert_base(va_arg(args, int), 10, 0), width, pad_char, left_align);
    else if (**format == 'u')
        print_padded(ft_convert_base(va_arg(args, unsigned int), 10, 0), width, pad_char, left_align);
    else if (**format == 'x')
        print_padded(ft_convert_base(va_arg(args, unsigned int), 16, 0), width, pad_char, left_align);
    else if (**format == 'X')
        print_padded(ft_convert_base(va_arg(args, unsigned int), 16, 1), width, pad_char, left_align);
    else if (**format == 'p')
        print_padded(ft_convert_base((unsigned long long)va_arg(args, void *), 16, 0), width, pad_char, left_align);
    else if (**format == '%')
        ft_putchar('%');
}

// Función principal ft_printf refactorizada
void ft_printf(const char *format, ...)
{
    va_list args;
    int width, left_align, precision;
    char pad_char;

    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            parse_flags(&format, &width, &left_align, &pad_char, &precision);
            handle_conversion(&format, args, width, left_align, pad_char, precision);
        }
        else
            ft_putchar(*format);
        format++;
    }
    va_end(args);
}

int main()
{
    ft_printf("Hello %s!\n", "world");
    ft_printf("Char: %c, Int: %d, Hex: %x\n", 'A', 12345, 255);
    return 0;
}
