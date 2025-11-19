/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:06:35 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/19 13:35:40 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

int	print_hex(unsigned long long nbr, int upper)
{
	if (nbr == 0)
		return (write(1, "0", 1));
	if (upper)
		return (ft_putnbr_base(nbr, "0123456789ABCDEF", 16));
	else
		return (ft_putnbr_base(nbr, "0123456789abcdef", 16));
}
