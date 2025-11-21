/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:26:23 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/21 12:18:58 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

static int	padding_size(int space, int plus, t_arg *arg, int nbr)
{
	int	padding;
	int	nbr_size;

	if (arg->padding < 0)
		return (0);
	padding = arg->padding - space - plus;
	if (nbr < 0)
		nbr_size = nbr_size_base(nbr * -1, 10);
	else
		nbr_size = nbr_size_base(nbr, 10);
	if (arg->dot > nbr_size || arg->dot == 0)
		nbr_size = arg->dot;
	padding = padding - nbr_size;
	if (nbr < 0)
		padding--;
	return (padding);
}

static int	print_nb_flags(t_arg *arg, int nbr)
{
	int	count;
	int	space;
	int	padding;
	int	plus;

	if (arg->plus >= 0 && nbr > 0)
		plus = 1;
	else
		plus = 0;
	if (arg->plus >= 0 || arg->space < 0)
		space = 0;
	else
		space = 1;
	padding = padding_size(space, plus, arg, nbr);
	count = 0;
	if (arg->dot >= 0 || arg->zero < 0)
		count += print_chars(padding, ' ');
	count += print_chars(space, ' ');
	count += print_chars(plus, '+');
	return (count);
}

int	print_number(t_arg *arg, int nbr)
{
	unsigned int	p_nbr;
	int				count;

	count = 0;
	p_nbr = nbr;
	count += print_nb_flags(arg, nbr);
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		p_nbr = nbr * -1;
		if (arg->dot < 0)
			count += print_chars(arg->zero - nbr_size_base(p_nbr, 10) - 1, '0');
	}
	else if (arg->dot < 0)
		count += print_chars(arg->zero - nbr_size_base(p_nbr, 10), '0');
	count += print_chars(arg->dot - nbr_size_base(p_nbr, 10), '0');
	count += ft_putnbr_base(p_nbr, "0123456789", 10, arg->dot);
	return (count);
}
