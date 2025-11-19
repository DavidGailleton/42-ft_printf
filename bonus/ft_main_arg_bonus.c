/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:38:58 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/19 15:45:26 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

static int	is_main_arg(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

char	ft_main_arg(char *str)
{
	while (*str)
	{
		if (is_main_arg(*str))
			break ;
		str++;
	}
	return (*str);
}
