/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:54:03 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/19 17:52:14 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static int	ft_print_arg(char c, va_list args)
{
	if (c == 'c')
		return (print_char(va_arg(args, int)));
	else if (c == 's')
		return (print_str(va_arg(args, char *)));
	else if (c == 'p')
		return (print_pointer(va_arg(args, unsigned long long)));
	else if (c == 'd' || c == 'i')
		return (print_number(va_arg(args, int)));
	else if (c == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (print_hex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (print_hex(va_arg(args, unsigned int), 1));
	else if (c == '%')
		return (print_char('%'));
	return (0);
}

int	ft_printf(const char *first_arg, ...)
{
	va_list	args;
	int		nb_print;
	int		i;

	nb_print = 0;
	va_start(args, first_arg);
	i = 0;
	while (first_arg[i])
	{
		if (first_arg[i] == '%')
		{
			i++;
			nb_print += ft_print_arg(first_arg[i], args);
		}
		else
			nb_print += write(1, &first_arg[i], 1);
		i++;
	}
	va_end(args);
	return (nb_print);
}
