/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:47:21 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/18 09:12:06 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int rotate_alpha(t_3Dpoint *point, int rotation) //z
{
	float xtmp;
	float ytmp;

	xtmp = (float)point->x;
	ytmp = (float)point->y;
	point->x = (int)(xtmp * cos(rotation) - ytmp * sin(rotation));
	point->y = (int)(xtmp * sin(rotation) + ytmp * cos(rotation));
	return (1);
}

int rotate_beta(t_3Dpoint *point, int rotation) //y
{
	float xtmp;
	float ztmp;

	xtmp = (float)point->x;
	ztmp = (float)point->z;
	point->x = (int)((xtmp * cos(rotation)) + (ztmp * sin(rotation)));
	point->z = (int)((-xtmp * sin(rotation)) + (ztmp * cos(rotation)));
	return (1);
}

int rotate_gamma(t_3Dpoint *point, int rotation) //x
{
	float ytmp;
	float ztmp;

	ytmp = (float)point->y;
	ztmp = (float)point->z;
	point->y = (int)((ytmp * cos(rotation)) - (ztmp * sin(rotation)));
	point->z = (int)((ytmp * sin(rotation)) + (ztmp * cos(rotation)));
	return (1);
}

void	apply_rotate(t_map *map, int rotation)
{
	int i;
	int j;

	j = 0;
	while (j < map->nb_line)
	{
		i = 0;
		while (i < map->len_line)
		{
			rotate_alpha(&map->map3d[j][i], rotation);
			rotate_beta(&map->map3d[j][i], rotation);
			rotate_gamma(&map->map3d[j][i], rotation);
			i++;
		}
		j++;
	}
	return (1);
}