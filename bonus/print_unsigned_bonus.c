/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:26:23 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/19 20:56:30 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

int	print_unsigned(t_arg *arg, unsigned long nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		count += write(1, "0", 1);
	count += print_chars(arg->zero - nbr_size_base(nbr, 10), '0');
	count += ft_putnbr_base(nbr, "0123456789", 10);
	return (count);
}
