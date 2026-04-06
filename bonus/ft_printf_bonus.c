/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:54:03 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/21 14:59:50 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

static int	ft_print_arg_flags(t_arg *arg, va_list args)
{
	int	count;

	count = 0;
	if (arg->arg == 'c')
		count += print_char(arg, va_arg(args, int));
	else if (arg->arg == 's')
		count += print_str(arg, va_arg(args, char *));
	else if (arg->arg == 'p')
		count += print_pointer(arg, va_arg(args, long long));
	else if (arg->arg == 'd' || arg->arg == 'i')
		count += print_number(arg, va_arg(args, int));
	else if (arg->arg == 'u')
		count += print_unsigned(arg, va_arg(args, unsigned int));
	else if (arg->arg == 'x' || arg->arg == 'X')
		count += print_hex(arg, va_arg(args, unsigned int));
	if (count < 0)
		return (-1);
	count += print_chars(arg->minus - count, ' ');
	if (count < 0)
		return (-1);
	return (count);
}

static int	ft_print_arg(char *str, va_list args)
{
	t_arg	*arg;
	int		count;

	arg = ft_parsing(str);
	if (!arg)
		return (-1);
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

static int	handle_arg(const char *s, va_list args, int *i)
{
	int	n;

	(*i)++;
	n = ft_print_arg((char *)&s[*i], args);
	*i += ft_to_skip((char *)&s[*i]);
	return (n);
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
	i = -1;
	va_start(args, first_arg);
	while (first_arg[++i])
	{
		temp = nb_print;
		if (first_arg[i] == '%' && first_arg[i + 1])
			nb_print += handle_arg(first_arg, args, &i);
		else if (first_arg[i] != '%')
			nb_print += write(1, &first_arg[i], 1);
		if (temp >= nb_print)
			return (-1);
	}
	va_end(args);
	return (nb_print);
}
