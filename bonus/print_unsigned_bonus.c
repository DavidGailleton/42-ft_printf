/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:26:23 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/20 16:17:12 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

int	print_unsigned(t_arg *arg, unsigned int nbr)
{
	int	count;

	count = 0;
	count += print_chars(arg->padding - nbr_size_base(nbr, 10), ' ');
	count += print_chars(arg->zero - nbr_size_base(nbr, 10), '0');
	count += print_chars(arg->dot - nbr_size_base(nbr, 10), '0');
	count += ft_putnbr_base(nbr, "0123456789", 10);
	return (count);
}
