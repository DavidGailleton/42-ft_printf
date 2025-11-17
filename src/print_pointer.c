/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:19:16 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/17 12:25:20 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

int	print_pointer(unsigned long long p)
{
	ft_putstr_fd("0x", 1);
	return (2 + ft_putnbr_base(p, "0123456789abcdef", 16));
}
