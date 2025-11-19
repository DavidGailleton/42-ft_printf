/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:35:15 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/19 19:09:25 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

static int	next_not_digit(char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

static int	nb_to_skip(char *str)
{
	if (*str == '-')
		return (1 + next_not_digit(&str[1]));
	else if (*str == '0')
		return (1 + next_not_digit(&str[1]));
	else if (*str == '.')
		return (1 + next_not_digit(&str[1]));
	return (1);
}

t_arg	*ft_parsing(char *str)
{
	t_arg	*arg;
	char	main_arg;

	main_arg = ft_main_arg(str);
	arg = ft_create_arg();
	if (!arg)
		return (0);
	arg->arg = main_arg;
	while (*str != main_arg)
	{
		if (*str == '-')
			arg->minus = ft_atoi(&str[1]);
		else if (*str == '0')
			arg->zero = ft_atoi(&str[1]);
		else if (*str == '.')
			arg->dot = ft_atoi(&str[1]);
		else if (*str == '#')
			arg->hash = 1;
		else if (*str == ' ')
			arg->space = 1;
		else if (*str == '+')
			arg->zero = 1;
		str += nb_to_skip(str);
	}
	return (arg);
}
