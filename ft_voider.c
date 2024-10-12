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

int	print_voidpointer(va_list ap)
{
	unsigned long	ptr;

	ptr = (unsigned long)va_arg(ap, void *);
	if (ptr)
	{
		write(1, "0x", 2);
		return (2 + print_digit(ptr, 16));
	}
	return (print_str("(nil)"));
}
