/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:18:18 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/08 10:10:30 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

/*
 *	ft_printf_bonus.c
 */

int		ft_select_format(char *str, va_list arg);
int		ft_printf(const char *str, ...);

/*
 *	char_bonus.c
 */

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_strlen(char *str);

/*
 *	ft_putnbr_bonus.c
 */

void	ft_putnbr_unsign_base(unsigned long long int nbr, char *base);
void	ft_putnbr_base(long long int nbr, char *base);
int		ft_len_nbr(long long int n, char *base);
int		ft_len_nbr_unsign(unsigned long long int n, char *base);

/*
 *	hexa_and_void_bonus.c
 */

int		ft_format_xup(unsigned int nb, int *tab);
int		ft_format_x(unsigned int nb, int *tab);
int		ft_format_p(void *ad);

/*
 *	decimal_bonus.c
 */

int		ft_format_d(int nb, int *tab);
int		ft_format_u(unsigned int nb);

/*
 *	flag_bonus.c	
 */

int		ft_is_flag(char c);
void	ft_tab_flag(char *str, int *tab);

#endif