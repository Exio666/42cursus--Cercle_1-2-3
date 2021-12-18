/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:47:18 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/18 16:54:32 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_d(int nb, t_info *info)
{
	int	count;

	count = ft_len_nbr(nb, "0123456789");
	if (count < info->precision)
		count = info->precision;
	if (info->minus == FALSE && ((info->plus == TRUE
				|| info->space == TRUE) && nb >= 0))
		count += ft_width(count + 1, info->width, info->zero);
	else if (info->minus == FALSE)
		count += ft_width(count, info->width, info->zero);
	if (info->plus == TRUE && nb >= 0)
		count += ft_putchar_fd('+', 1);
	else if (info->space == TRUE && nb >= 0 && info->plus == FALSE)
		count += ft_putchar_fd(' ', 1);
	while (ft_len_nbr(nb, "0123456789") < info->precision)
	{
		count += ft_putchar_fd('0', 1);
		info->precision--;
	}
	ft_putnbr_base(nb, "0123456789");
	if (info->minus == TRUE)
		count += ft_width(count, info->width, FALSE);
	return (count);
}

int	ft_format_u(unsigned int nb, t_info *info)
{
	int		count;

	count = ft_len_nbr_unsign(nb, "0123456789");
	if (count < info->precision)
		count = info->precision;
	if (info->minus == FALSE)
		count += ft_width(count, info->width, info->zero);
	while (ft_len_nbr(nb, "0123456789") < info->precision)
	{
		ft_putchar_fd('0', 1);
		info->precision--;
	}
	ft_putnbr_unsign_base(nb, "0123456789");
	if (info->minus == TRUE)
		count += ft_width(count, info->width, FALSE);
	return (count);
}
