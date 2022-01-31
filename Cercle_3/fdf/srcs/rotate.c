/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:47:21 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/31 16:21:18 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rotate_alpha(t_3Dpoint *point, float rotation)
{
	float	xtmp;
	float	ytmp;

	xtmp = point->x;
	ytmp = point->y;
	point->x = xtmp * cos(rotation) - ytmp * sin(rotation)+ 0.5;
	point->y = xtmp * sin(rotation) + ytmp * cos(rotation)+ 0.5;
	return (1);
}

int	rotate_beta(t_3Dpoint *point, float rotation)
{
	float	xtmp;
	float	ztmp;

	xtmp = point->x;
	ztmp = point->z;
	point->x = xtmp * cos(rotation) + ztmp * sin(rotation)+ 0.5;
	point->z = -xtmp * sin(rotation) + ztmp * cos(rotation)+ 0.5;
	return (1);
}

int	rotate_gamma(t_3Dpoint *point, float rotation)
{
	float	ytmp;
	float	ztmp;

	ytmp = point->y;
	ztmp = point->z;
	point->y = ytmp * cos(rotation) - ztmp * sin(rotation) + 0.5;
	point->z = ytmp * sin(rotation) + ztmp * cos(rotation) + 0.5 ;
	return (1);
}

void	apply_rotate(t_3Dpoint *p3d, float z, float y, float x)
{
	rotate_alpha(p3d, z);
	rotate_beta(p3d, y);
	rotate_gamma(p3d, x);
}
