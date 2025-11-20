/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_arg_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:52:18 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/20 14:26:50 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf_bonus.h"

t_arg	*ft_create_arg(void)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	if (!arg)
		return (NULL);
	arg->padding = -1;
	arg->minus = -1;
	arg->zero = -1;
	arg->dot = -1;
	arg->hash = -1;
	arg->space = -1;
	arg->plus = -1;
	return (arg);
}
