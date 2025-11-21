/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:06:35 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/21 14:24:18 by dgaillet         ###   ########lyon.fr   */
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
	nbr_size = nbr_size_base(nbr, 16);
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
	if (arg->dot >= 0)
		arg->zero = -1;
	return (count);
}

int	print_hex(t_arg *arg, unsigned int nbr)
{
	int		count;

	count = 0;
	count += print_nb_flags(arg, nbr);
	if (nbr == 0 && arg->dot)
	{
		count += write(1, "0", 1);
		count += print_chars(arg->zero - 1, '0');
		count += print_chars(arg->dot - 1, '0');
	}
	else
	{
		if (arg->hash > 0 && arg->arg == 'X')
			count += write(1, "0X", 2);
		else if (arg->hash > 0)
			count += write(1, "0x", 2);
		count += print_chars(arg->zero - count - nbr_size_base(nbr, 16), '0');
		count += print_chars(arg->dot - nbr_size_base(nbr, 16), '0');
		if (arg->arg == 'X')
			count += ft_putnbr_base(nbr, "0123456789ABCDEF", 16, arg->dot);
		else
			count += ft_putnbr_base(nbr, "0123456789abcdef", 16, arg->dot);
	}
	return (count);
}
