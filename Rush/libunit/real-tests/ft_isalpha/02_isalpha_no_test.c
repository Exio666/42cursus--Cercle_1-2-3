/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_isalpha_no_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:03:02 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/09 10:32:54 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "isalpha.h"

int	isalpha_no(void)
{
	if (ft_isalpha('1') == 0)
		return (0);
	return (-1);
}