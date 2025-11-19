/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:54:03 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/19 20:50:02 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf_bonus.h"
#include <stdlib.h>

static int	ft_print_arg_flags(t_arg *arg, va_list args)
{
	int	count;

	count = 0;
	if (arg->arg == 'c')
		count += print_char(arg, va_arg(args, int));
	else if (arg->arg == 's')
		count += print_str(arg, va_arg(args, char *));
	else if (arg->arg == 'p')
		count += print_pointer(arg, va_arg(args, unsigned long long));
	else if (arg->arg == 'd' || arg->arg == 'i')
		count += print_number(arg, va_arg(args, int));
	else if (arg->arg == 'u')
		count += print_unsigned(arg, va_arg(args, unsigned long));
	else if (arg->arg == 'x' || arg->arg == 'X')
		count += print_hex(arg, va_arg(args, unsigned int));
	count += print_chars(arg->minus - count, ' ');
	return (count);
}

static int	ft_print_arg(char *str, va_list args)
{
	t_arg	*arg;
	int		count;

	arg = ft_parsing(str);
	if (!arg)
		return (0);
	if (arg->arg == '%')
		count = write(1, "%", 1);
	else
		count = ft_print_arg_flags(arg, args);
	free(arg);
	return (count);
}

static int	ft_to_skip(char *str)
{
	int	count;

	count = 0;
	while (!(*str == 'c' || *str == 's' || *str == 'p' || *str == 'd'
			|| *str == 'i' || *str == 'u' || *str == 'x' || *str == 'X'
			|| *str == '%') && *str)
	{
		count++;
		str++;
	}
	return (count);
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
			nb_print += ft_print_arg((char *) &first_arg[i], args);
			i += ft_to_skip((char *) &first_arg[i]);
		}
		else
			nb_print += write(1, &first_arg[i], 1);
		i++;
	}
	va_end(args);
	return (nb_print);
}
