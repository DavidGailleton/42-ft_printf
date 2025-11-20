/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:02:03 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/20 15:34:58 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_bonus.h"

int	print_str(t_arg *arg, char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		if (arg->dot < 6 && arg->dot >= 0)
			return (print_chars(arg->padding, ' '));
		if (arg->padding > 6)
			count += print_chars(arg->padding - 6, ' ');
		return (count + write(1, "(null)", 6));
	}
	if (arg->dot > (int) ft_strlen(str) || arg->dot < 0)
		arg->dot = ft_strlen(str);
	if (arg->padding > 0)
		count += print_chars(arg->padding - arg->dot, ' ');
	else if (!str[0] && arg->space > 0)
		return (write(1, " ", 1));
	return (count + write(1, str, arg->dot));
}
