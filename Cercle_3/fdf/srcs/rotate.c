/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:47:21 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/24 11:42:14 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//z
int	rotate_alpha(t_3Dpoint *point, int rotation)
{
	int	xtmp;
	int	ytmp;

	xtmp = point->x;
	ytmp = point->y;
	point->x = xtmp * cos(rotation) - ytmp * sin(rotation);
	point->y = xtmp * sin(rotation) + ytmp * cos(rotation);
	return (1);
}

//y
int	rotate_beta(t_3Dpoint *point, int rotation)
{
	int	xtmp;
	int	ztmp;

	xtmp = point->x;
	ztmp = point->z;
	point->x = xtmp * cos(rotation) + ztmp * sin(rotation);
	point->z = -xtmp * sin(rotation) + ztmp * cos(rotation);
	return (1);
}

//x
int	rotate_gamma(t_3Dpoint *point, int rotation)
{
	int	ytmp;
	int	ztmp;

	ytmp = point->y;
	ztmp = point->z;
	point->y = ytmp * cos(rotation) - ztmp * sin(rotation);
	point->z = ytmp * sin(rotation) + ztmp * cos(rotation);
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
