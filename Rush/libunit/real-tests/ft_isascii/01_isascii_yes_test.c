/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_isascii_yes_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:03:02 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/09 10:33:15 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "isascii.h"

int	isascii_yes(void)
{
	if (ft_isascii('A') == 1)
		return (0);
	return (-1);
}
