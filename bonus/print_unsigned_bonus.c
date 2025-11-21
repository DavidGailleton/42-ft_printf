/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:26:23 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/21 14:22:44 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

static int	padding_size(t_arg *arg, unsigned int nbr)
{
	int	padding;
	int	nbr_size;

	if (arg->padding < 0)
		return (0);
	padding = arg->padding;
	nbr_size = nbr_size_base(nbr, 10);
	if (arg->dot > nbr_size || (arg->dot == 0 && !nbr))
		nbr_size = arg->dot;
	padding = padding - nbr_size;
	return (padding);
}

static int	print_nb_flags(t_arg *arg, unsigned int nbr)
{
	int	count;
	int	padding;

	padding = padding_size(arg, nbr);
	count = 0;
	if (arg->dot >= 0 || arg->zero < 0)
		count += print_chars(padding, ' ');
	return (count);
}

int	print_unsigned(t_arg *arg, unsigned int nbr)
{
	int	count;

	count = 0;
	count += print_nb_flags(arg, nbr);
	if (arg->dot < 0)
		count += print_chars(arg->zero - nbr_size_base(nbr, 10), '0');
	count += print_chars(arg->dot - nbr_size_base(nbr, 10), '0');
	count += ft_putnbr_base(nbr, "0123456789", 10, arg->dot);
	return (count);
}
