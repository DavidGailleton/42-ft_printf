/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:16:44 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/21 15:04:59 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_base_extra(unsigned int nbr, char *base, int base_size)
{
	int		i;
	char	temp;

	if (nbr == 0)
		return (0);
	i = 1 + ft_putnbr_base_extra(nbr / base_size, base, base_size);
	temp = base[nbr % base_size];
	if (write(1, &temp, 1) < 0)
		return (-10000);
	return (i);
}

int	ft_putnbr_base(unsigned int nbr, char *base, int base_size, int limit)
{
	char	temp;

	if (nbr == 0 && limit != 0)
	{
		temp = base[0];
		if (write(1, &temp, 1) < 0)
			return (-10000);
		return (1);
	}
	return (ft_putnbr_base_extra(nbr, base, base_size));
}

static int	ft_putnbr_base_ll_extra(unsigned long long nbr, char *base,
		int base_size)
{
	int		i;
	char	temp;

	if (nbr == 0)
		return (0);
	i = 1 + ft_putnbr_base_ll_extra(nbr / base_size, base, base_size);
	temp = base[nbr % base_size];
	if (write(1, &temp, 1) < 0)
		return (-10000);
	return (i);
}

int	ft_putnbr_base_ll(unsigned long long nbr, char *base, int base_size)
{
	char	temp;

	if (nbr == 0)
	{
		temp = base[0];
		if (write(1, &temp, 1) < 0)
			return (-10000);
		return (1);
	}
	return (ft_putnbr_base_ll_extra(nbr, base, base_size));
}
