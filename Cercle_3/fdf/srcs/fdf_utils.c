/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:08:57 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/21 13:38:31 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	set_color(t_3Dpoint p1, t_3Dpoint p2)
{
	if (p1.z == 0 && p2.z == 0)
		return (encode_rgb(255, 255, 255));
	else
		return (encode_rgb(255, 0, 0));
}
