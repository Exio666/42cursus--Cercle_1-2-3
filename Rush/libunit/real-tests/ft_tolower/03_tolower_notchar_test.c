/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_tolower_notchar_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:03:02 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/09 14:11:51 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tolower.h"

int	tolower_notchar_test(void)
{
	if (ft_tolower('1') == '1')
		return (0);
	return (-1);
}