/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_to_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:47:21 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/17 10:29:31 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2Dpoint convert_3d(int x, int y, int z, int camera)
{
	t_2Dpoint point;

	point.x = x * cos(camera) + y * cos(camera) + z * cos(camera);
	point.y = x * sin(camera) + y * sin(camera) + z * sin(camera);
	return (point);
}

int converteur(t_map *map)
{
	int i;
	int j;

	j = 0;
	map->map2d = malloc(sizeof(t_2Dpoint *) * map->nb_line);
	if (!map->map2d)
		
	
	while (j < map->nb_line)
	{
		i = 0;
		map->map2d[j] = malloc(sizeof(t_2Dpoint) * map->len_line);
		while (i < map->len_line)
		{
			map->map2d[i][j] = convert_3d(j, i, map->map3d[j][i], map->camera);
			i++;
		}
		j++;
	}
	return (1);
}
