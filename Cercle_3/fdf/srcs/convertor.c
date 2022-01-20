/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:53:14 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/20 13:06:44 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2Dpoint	isometric_point(t_3Dpoint p3d)
{
	t_2Dpoint	p2d;

	p2d.x = (int)((float)p3d.x * cos(0) + (float)p3d.y * cos((2 * M_PI) / 3)
			+ (float)p3d.z * cos(-((2 * M_PI) / 3)));
	p2d.y = (int)((float)p3d.x * sin(0) + (float)p3d.y * sin((2 * M_PI) / 3)
			+ (float)p3d.z * sin(-((2 * M_PI) / 3)));
	return (p2d);
}

int	convertor(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	map->map2d = malloc(sizeof(t_2Dpoint *) * map->nb_line);
	while (j < map->nb_line)
	{
		i = 0;
		map->map2d[j] = malloc(sizeof(t_2Dpoint) * map->len_line);
		while (i < map->len_line)
		{
			map->map2d[j][i] = isometric_point(map->map3d[j][i]);
			i++;
		}
		j++;
	}
	return (1);
}
