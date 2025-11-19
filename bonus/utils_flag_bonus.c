/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_flag_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:07:22 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/19 19:53:38 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	nbr_size_base(unsigned long long nb, int base_size)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		count++;
		nb /= base_size;
	}
	return (count);
}

int	print_chars(int nb, char c)
{
	int	count;

	count = 0;
	while (nb > 0)
	{
		count += write(1, &c, 1);
		nb--;
	}
	return (count);
}
