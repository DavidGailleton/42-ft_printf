/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:52:23 by dgaillet          #+#    #+#             */
/*   Updated: 2025/11/19 20:48:36 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

typedef struct s_arg
{
	char	arg;
	int		minus;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	int		plus;
}	t_arg;

int		ft_printf(const char *first_arg, ...);

int		ft_putnbr_base(unsigned long long nbr, char *base, int base_size);
char	ft_main_arg(char *str);
t_arg	*ft_create_arg(void);
t_arg	*ft_parsing(char *str);
int		print_chars(int nb, char c);
int		nbr_size_base(unsigned long long nb, int base_size);

int		print_char(t_arg *arg, char c);
int		print_str(t_arg *arg, char *str);
int		print_pointer(t_arg *arg, unsigned long long p);
int		print_number(t_arg *arg, int nbr);
int		print_unsigned(t_arg *arg, unsigned long nbr);
int		print_hex(t_arg *arg, unsigned long long p);

#endif
