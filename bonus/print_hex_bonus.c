/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:06:35 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/19 20:14:08 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

int	print_hex(t_arg *arg, unsigned long long nbr)
{
	int		count;

	count = 0;
	if (nbr == 0)
		count += write(1, "0", 1);
	else
	{
		if (arg->hash && arg->arg == 'X')
			count += write(1, "0X", 2);
		else if (arg->hash)
			count += write(1, "0x", 2);
		count += print_chars(arg->zero - count - nbr_size_base(nbr, 16), '0');
		if (arg->arg == 'X')
			count += ft_putnbr_base(nbr, "0123456789ABCDEF", 16);
		else
			count += ft_putnbr_base(nbr, "0123456789abcdef", 16);
	}
	return (count);
}
