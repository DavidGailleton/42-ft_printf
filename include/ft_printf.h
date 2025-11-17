/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:52:23 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/17 12:47:41 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *first_arg, ...);

int	ft_putnbr_base(unsigned long long nbr, char *base, int base_size);

int	print_char(char c);
int	print_str(char *str);
int	print_pointer(unsigned long long p);
int	print_number(int nbr);
int	print_unsigned(unsigned int nbr);
int	print_hex(unsigned long long p, int upper);

#endif
