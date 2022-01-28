/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:10:45 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/28 13:18:55 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color(t_map *map)
{
	if (map->max_z - map->min_z == 0)
		map->rapport_color = 0;
	else
	{
		map->rapport_color = 255 / (map->max_z - map->min_z);
		if (map->rapport_color > 1)
			map->rapport_color = 1;
	}
}

int color_z(t_map *map, int z)
{
	int	color;

	color = (map->min_z + z) * map->rapport_color;
	return (color);
}

void 	rapport(t_map *map, int z_start, int z_end, int nb_pixel)
{
	int	color_sart;
	int	color_end;
	
	color_sart = (map->min_z + z_start) * map->rapport_color;
	color_end = (map->min_z + z_end) * map->rapport_color;
	map->rapport_pixel = (color_end - color_sart) / nb_pixel;
}

int	up_color(t_map *map)
{
	int	retour;

	retour = 0;
	map->rest = map->rest + map->rapport_pixel;
	if (map->rest >= 1)
	{
		retour = (int)map->rest;
		while (map->rest >= 1)
			map->rest =  map->rest - 1;
	}
	return (retour);
}
