/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:26:23 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/19 19:56:04 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

int	print_number(t_arg *arg, int nbr)
{
	unsigned int	p_nbr;
	int				count;

	count = 0;
	p_nbr = nbr;
	if (nbr == 0)
		count += write(1, "0", 1);
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		p_nbr = nbr * -1;
		count += print_chars(arg->zero - nbr_size_base(p_nbr, 10) - 1, '0');
	}
	else
		count += print_chars(arg->zero - nbr_size_base(p_nbr, 10), '0');
	return (count + ft_putnbr_base(p_nbr, "0123456789", 10));
}
