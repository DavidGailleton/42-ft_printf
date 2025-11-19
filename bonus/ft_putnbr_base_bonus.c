/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:16:44 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/17 12:43:17 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned long long nbr, char *base, int base_size)
{
	int	i;

	if (nbr == 0)
		return (0);
	i = 1 + ft_putnbr_base(nbr / base_size, base, base_size);
	ft_putchar_fd(base[nbr % base_size], 1);
	return (i);
}
