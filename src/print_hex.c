/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:06:35 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/17 12:38:35 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
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
