/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:56:36 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/20 14:40:30 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>
#include <stdlib.h>

int	print_char(t_arg *arg, char c)
{
	int		count;

	count = 0;
	count += print_chars(arg->padding - 1, ' ');
	if (!arg->minus && arg->zero)
		count += print_chars(arg->zero - 1, ' ');
	count += write(1, &c, 1);
	return (count);
}
