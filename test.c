/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:11:53 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/20 16:19:29 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf_bonus.h"
#include <limits.h>

int	main(void)
{
	printf("===\t-\t===\n\n");
	printf("%d - ", printf("...%8.5i...\n", 34));
	printf("%d\n\n", ft_printf("...%8.5i...\n", 34));
}
