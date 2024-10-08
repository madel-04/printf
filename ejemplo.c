/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejemplo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:15:45 by marvin            #+#    #+#             */
/*   Updated: 2024/10/07 10:15:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		print_char((int)*str);
		++i;
		++str;
	}
	return (i);
}

int	print_digit(long n, int base)
{
	int	i;
	char	*symbols;

	symbols = "0123456789abcdef"
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base) + 1);
	}
	else if (n < base)
		return (print_char(symbols[n]));
	else
	{
		i = print_digit(n / base, base);
		return (i + print_digit(n % base, base));
	}
}

int	print_digit_may(long n, int base)
{
	int	i;
	char	*symbols;

	symbols = "0123456789ABCDEF"
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base) + 1);
	}
	else if (n < base)
		return (print_char(symbols[n]));
	else
	{
		i = print_digit(n / base, base);
		return (i + print_digit(n % base, base));
	}
}

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c') // un solo caracter
		count += print_char(va_arg(ap, int));
	else if (specifier == 's') //un string
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'p') //el puntero void * impreso como hexadecimal
	else if (specifier == 'd') //numero decimal
		count += print_digit((long)(va_arg(ap, int)), 10);
	else if (specifier == 'i') //numero entero en base 10
	else if (specifier == 'u') //numero decimal sin signo
	else if (specifier == 'x') //hexadecimal en minusculas
		count += print_digit((long)(va_arg(ap, unsigned int)), 16)
	else if (specifier == 'X') //hexadecimal en mayusculas
		count += print_digit_may((long)(va_arg(ap, unsigned int)), 16)
	else if (specifier == '%') //imprimir el simbolo del %
		count += print_char('%');
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int	count;
	va_list	ap;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*++format, ap); //*Asociation of unary operation is form R to L
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

/* TYPE PROMOTION
Happends implicitly, in some functions. You can also do it explicitly by casting
In the absence of a function prototype, char and short become int, and float becomes double.

Since the prototype doesn't specify types for optional arguments ina a call to a variadic 
function the default argument promotions are perfomed on the optinal arguments values.
This means the objects of type char or short int are promoted to either int or unsigned int, as appropiate,
and float are promoted to double.
So if the caller passes a char as an optional argument, it is promoted to an int, and the function can access it
with va_arg(ap, int)

Integer type : char < short < int < long
Real type: float < double
*/