/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:47:21 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/25 17:18:04 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//z
int	rotate_alpha(t_3Dpoint *point, int rotation)
{
	float	xtmp;
	float	ytmp;

	xtmp = point->x;
	ytmp = point->y;
	point->x = xtmp * cos(rotation) - ytmp * sin(rotation)+ 0.5;
	point->y = xtmp * sin(rotation) + ytmp * cos(rotation)+ 0.5;
	return (1);
}

//y
int	rotate_beta(t_3Dpoint *point, int rotation)
{
	float	xtmp;
	float	ztmp;

	xtmp = point->x;
	ztmp = point->z;
	point->x = xtmp * cos(rotation) + ztmp * sin(rotation)+ 0.5;
	point->z = -xtmp * sin(rotation) + ztmp * cos(rotation)+ 0.5;
	return (1);
}

//x
int	rotate_gamma(t_3Dpoint *point, int rotation)
{
	float	ytmp;
	float	ztmp;

	ytmp = point->y;
	ztmp = point->z;
	point->y = ytmp * cos(rotation) - ztmp * sin(rotation) + 0.5;
	point->z = ytmp * sin(rotation) + ztmp * cos(rotation) + 0.5 ;
	return (1);
}

void	apply_rotate(t_map *map, int z, int y, int x)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->nb_line)
	{
		i = 0;
		while (i < map->len_line)
		{
			rotate_alpha(&map->map3d[j][i], z);
			rotate_beta(&map->map3d[j][i], y);
			rotate_gamma(&map->map3d[j][i], x);
			i++;
		}
		j++;
	}
}
