/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:53:14 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/01 12:45:22 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	malloc_map2d(t_map *map)
{
	int	j;

	j = 0;
	map->map2d = malloc(sizeof(t_2Dpoint *) * map->nb_line);
	if (!map->map2d)
		return (0);
	while (j < map->nb_line)
	{
		map->map2d[j] = malloc(sizeof(t_2Dpoint) * map->len_line);
		if (!map->map2d[j])
		{
			free_map3d(map, map->nb_line);
			free_map2d(map, j);
			exit(1);
		}
		j++;
	}
	return (1);
}

t_2Dpoint	isometric_point(t_3Dpoint p3d, float zoom, int scaling, t_map *map)
{
	t_2Dpoint	p2d;

	p3d.x = p3d.x * zoom;
	p3d.y = p3d.y * zoom;
	p3d.z = p3d.z * (zoom / scaling);
	apply_rotate(&p3d, map->rot_z, map->rot_x, map->rot_y);
	p2d.x = (p3d.x - p3d.y) * cos(0.463646716);
	p2d.y = (p3d.x + p3d.y) * sin(0.463646716) - p3d.z;
	return (p2d);
}

t_2Dpoint	parallele_point(t_3Dpoint p3d, float zoom, int scaling, t_map *map)
{
	t_2Dpoint	p2d;

	p3d.x = p3d.x * zoom;
	p3d.y = p3d.y * zoom;
	p3d.z = p3d.z * (zoom / scaling);
	apply_rotate(&p3d, map->rot_z, map->rot_x, map->rot_y);
	p2d.x = p3d.x;
	p2d.y = p3d.y;
	return (p2d);
}

int	convertor(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->nb_line)
	{
		i = 0;
		while (i < map->len_line)
		{
			if (map->projection % 2 == 0)
				map->map2d[j][i] = isometric_point(map->map3d[j][i], map->zoom,
						map->scaling, map);
			else
				map->map2d[j][i] = parallele_point(map->map3d[j][i], map->zoom,
						map->scaling, map);
			i++;
		}
		j++;
	}
	return (1);
}
