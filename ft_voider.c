/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voider.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:10:42 by marvin            #+#    #+#             */
/*   Updated: 2024/10/10 15:10:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit_min(unsigned long n, unsigned int base)
{
	int			i;
	char		*symbols;

	symbols = "0123456789abcdef";
	if (n == 0)
		return (print_char('0'));
	else if (n < base)
		return (print_char(symbols[n]));
	else
	{
		i = print_digit_min(n / base, base);
		return (i + print_digit_min(n % base, base));
	}
}

int	print_voidpointer(va_list ap)
{
	void	*ptr;

	ptr = va_arg(ap, void *);
	if (ptr)
	{
		write(1, "0x", 2);
		return (2 + print_digit_min((unsigned long)ptr, 16));
	}
	return (print_str("(nil)"));
}
