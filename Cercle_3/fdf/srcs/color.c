/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:10:45 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/27 16:17:01 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color(t_map *map)
{
	map->rapport_color = 255 / (map->max_z - map->min_z);
	if (map->rapport_color > 1)
		map->rapport_color = 1;
}

void 	rapport(t_map *map, int z_start, int z_end, int nb_pixel)
{
	int color_sart;
	int color_end;
	
	color_sart = (map->min_z + z_start) * map->rapport_color;
	color_end = (map->min_z + z_start) * map->rapport_color;
	map->rapport_pixel = (color_end - color_sart) / nb_pixel;
}

int	up_color(t_map *map)
{
	map->rest = 
}