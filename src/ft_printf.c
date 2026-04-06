/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:54:03 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/21 14:47:19 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

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
	int		temp;

	if (!first_arg)
		return (-1);
	nb_print = 0;
	va_start(args, first_arg);
	i = -1;
	while (first_arg[++i])
	{
		temp = nb_print;
		if (first_arg[i] == '%' && first_arg[i + 1] != '\0')
		{
			i++;
			nb_print += ft_print_arg(first_arg[i], args);
		}
		else if (first_arg[i] != '%')
			nb_print += write(1, &first_arg[i], 1);
		if (temp >= nb_print)
			return (-1);
	}
	va_end(args);
	return (nb_print);
}
