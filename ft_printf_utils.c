/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madel-va <madel-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:07:27 by madel-va          #+#    #+#             */
/*   Updated: 2024/10/16 13:19:34 by madel-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (print_str("(null)"));
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
	int		i;
	char	*symbols;

	symbols = "0123456789abcdef";
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

int	print_digit_noline(long n, int base) //
{
	int		i;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
		n = (unsigned int)n;
	if (n == 0)
	{
		return (print_char('0'));
	}
	else if (n < base)
		return (print_char(symbols[n]));
	else
	{
		i = print_digit_noline(n / base, base);
		return (i + print_digit_noline(n % base, base));
	}
}

int	print_digit_may(unsigned long n, unsigned int base)
{
	int					i;
	char				*symbols;

	symbols = "0123456789ABCDEF";
	if (n == 0)
		return (print_char('0'));
	else if (n < base)
		return (print_char(symbols[n]));
	else
	{
		i = print_digit_may(n / base, base);
		return (i + print_digit_may(n % base, base));
	}
}
