/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_arg_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:52:18 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/19 18:29:53 by dgaillet         ###   ########lyon.fr   */
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
	arg->minus = 0;
	arg->zero = 0;
	arg->dot = 0;
	arg->hash = 0;
	arg->space = 0;
	arg->plus = 0;
	return (arg);
}
