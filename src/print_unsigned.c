/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:26:23 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/17 12:44:47 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	print_unsigned(unsigned int nbr)
{
	if (nbr == 0)
		return (write(1, "0", 1));
	return (ft_putnbr_base(nbr, "0123456789", 10));
}
