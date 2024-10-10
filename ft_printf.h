/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maydel-va <madel-va@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:54:35 by maydel-va         #+#    #+#             */
/*   Updated: 2024/10/10 11:54:35 by maydel-va        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	print_char(int c);
int	print_str(char *str);
int	print_digit(long n, int base);
int	print_digit_noline(long n, int base);
int	print_digit_may(long n, int base);
int	print_voidpointer(va_list ap);
int	ft_printf(const char *format, ...);

#endif