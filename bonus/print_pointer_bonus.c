/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:19:16 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/21 15:46:51 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_bonus.h"
#include <unistd.h>

int	print_pointer(t_arg *arg, unsigned long long p)
{
	int	count;

	count = 0;
	if (!p)
	{
		count += print_chars(arg->padding - 5, ' ');
		if (write(1, "(nil)", 5) < 0)
			return (-10000);
		return (5 + count);
	}
	count += print_chars(arg->padding - nbr_size_base(p, 16) - 2, ' ');
	if (write(1, "0x", 2) < 0)
		return (-10000);
	return (count + 2 + ft_putnbr_base_ll(p, "0123456789abcdef", 16));
}
