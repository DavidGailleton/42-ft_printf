/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:26:23 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/17 12:56:40 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	print_number(int nbr)
{
	unsigned int	p_nbr;

	if (nbr == 0)
		return (write(1, "0", 1));
	if (nbr < 0)
	{
		write(1, "-", 1);
		p_nbr = nbr * -1;
		return (1 + ft_putnbr_base(p_nbr, "0123456789", 10));
	}
	return (ft_putnbr_base(nbr, "0123456789", 10));
}
