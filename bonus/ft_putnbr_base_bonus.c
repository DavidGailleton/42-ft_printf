/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:16:44 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/21 12:16:33 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_base_extra(unsigned int nbr, char *base, int base_size)
{
	int	i;

	if (nbr == 0)
		return (0);
	i = 1 + ft_putnbr_base_extra(nbr / base_size, base, base_size);
	ft_putchar_fd(base[nbr % base_size], 1);
	return (i);

}
int	ft_putnbr_base(unsigned int nbr, char *base, int base_size, int limit)
{
	if (nbr == 0 && limit != 0)
	{
		ft_putchar_fd(base[0], 1);
		return (1);
	}
	return (ft_putnbr_base_extra(nbr, base, base_size));
}

static int	ft_putnbr_base_ll_extra(unsigned long long nbr
		, char *base, int base_size)
{
	int	i;

	if (nbr == 0)
		return (0);
	i = 1 + ft_putnbr_base_ll_extra(nbr / base_size, base, base_size);
	ft_putchar_fd(base[nbr % base_size], 1);
	return (i);
}

int	ft_putnbr_base_ll(unsigned long long nbr, char *base, int base_size)
{
	if (nbr == 0)
	{
		ft_putchar_fd(base[0], 1);
		return (1);
	}
	return (ft_putnbr_base_ll_extra(nbr, base, base_size));
}
