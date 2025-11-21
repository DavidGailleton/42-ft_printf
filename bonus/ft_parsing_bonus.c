/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:35:15 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/21 11:49:23 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

static void	get_padding(t_arg *arg, char *str)
{
	str--;
	while (ft_isdigit(*str) && *str != '%')
		str--;
	str++;
	arg->padding = ft_atoi(str);
}

static void	ft_parse_str(t_arg *arg, char *str, char main_arg)
{
	while (*str != main_arg && *str != '.')
	{
		if (*str == '-')
			arg->minus = ft_atoi(&str[1]);
		else if (*str == '0' && !ft_isdigit(str[-1]))
			arg->zero = ft_atoi(&str[1]);
		else if (*str == '#')
			arg->hash = 1;
		else if (*str == ' ')
			arg->space = ft_atoi(&str[1]);
		else if (*str == '+')
			arg->plus = 1;
		str++;
	}
	if (*str == '.')
	{
		arg->dot = ft_atoi(str + 1);
		if (!(arg->minus >= 0 || arg->hash >= 0
				|| arg->space >= 0 || arg->plus >= 0))
			get_padding(arg, str);
	}
	else if (!(arg->minus >= 0 || arg->hash >= 0
			|| arg->space >= 0 || arg->plus >= 0))
		get_padding(arg, str);
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
	ft_parse_str(arg, str, main_arg);
	return (arg);
}
