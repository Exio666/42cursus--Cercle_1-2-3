/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:53:15 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/17 17:36:03 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_putstr_null(t_info info)
{
	
}

int	ft_format_c(char c, t_info info)
{
	int	count;

	count = 1;
	if (info.minus == FALSE)
		ft_width(1, info.width, FALSE);
	write(1, &c, 1);
	if (info.minus == TRUE)
		ft_width(1, info.width, FALSE);
	return (count);
}

int	ft_format_s(char *str, t_info info)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(str);
	if (j > info.precision)
		j = info.precision;
	if (!str)
		return (ft_putstr_null(info));
	if (info.minus == FALSE)
		ft_width(j, info.width, FALSE);
	while (str[i] && i < info.precision)
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	if (info.minus == FALSE)
		ft_width(j, info.width, FALSE);
	return (i);
}
