/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:43:20 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/17 17:28:45 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_width(int len, int with, bool zero)
{
	int	count;

	with -= len;
	while (with > 0 && zero == FALSE)
	{
		write(1, " ", 1);
		count++;
	}
	while (with > 0 && zero == TRUE)
	{
		write(1, "0", 1);
		count++;
	}
	return (count);
}

void	ft_flush_info(t_info info)
{
	info.hastag = FALSE;
	info.plus = FALSE;
	info.space = FALSE;
	info.zero = FALSE;
	info.minus = FALSE;
	info.width = 0;
	info.negative = 0;
	info.precision = 0;
}

void	ft_first_flag(char c, t_info info)
{
	if (c == '#')
		info.hastag = TRUE;
	if (c == ' ')
		info.space = TRUE;
	if (c == '+')
		info.plus = TRUE;
	if (c == '0')
		info.zero = TRUE;
	if (c == '-')
		info.minus = TRUE;
}

void	ft_feed_info(t_info info, va_list arg, char *str)
{
	int	i;

	i = 1;
	while (ft_strchr("# +0-", (int)str[i]))
	{
		ft_first_flag(str[i], info);
		i++;
	}
	if ((!ft_strchr("cspdiuxX%", str[i])) && str[i] != '.' && str[i] != '*')
	{
		info.width = ft_atoi(&str[i]);
		while (ft_isdigit(str[i]) == 1)
			i++;
	}
	else if (str[i++] == '*')
		info.width = va_arg(arg, int);
	if (str[i] == '.')
	{
		info.precision = atoi(&str[++i]);
		while (ft_isdigit(str[i]) == 1)
			i++;
	}
	info.conversion = str[i];
	info.index = info.index + i + 1;
}
