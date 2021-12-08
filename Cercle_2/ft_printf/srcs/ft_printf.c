/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:52:37 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/08 10:13:21 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_select_format(char *str, va_list arg)
{
	int	tab[45];

	ft_tab_flag(str, tab);
	if (str[tab[0]] == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (str[tab[0]] == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (str[tab[0]] == 'p')
		return (ft_format_p(va_arg(arg, void *)));
	if (str[tab[0]] == 'd' || str[tab[0]] == 'i')
		return (ft_format_d(va_arg(arg, int), tab));
	if (str[tab[0]] == 'u')
		return (ft_format_u(va_arg(arg, unsigned int)));
	if (str[tab[0]] == 'x')
		return (ft_format_x(va_arg(arg, unsigned int), tab));
	if (str[tab[0]] == 'X')
		return (ft_format_xup(va_arg(arg, unsigned int), tab));
	if (str[tab[0]] == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		counter;

	va_start (arg, str);
	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			counter = counter + ft_select_format((char *)&str[++i], arg);
			while (ft_is_flag(str[i]) == 0)
				i++;
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			counter++;
			i++;
		}
	}
	va_end(arg);
	return (counter);
}
