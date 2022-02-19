/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:10:45 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/07 10:49:45 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color(t_map *map)
{
	if (map->max_z - map->min_z == 0)
		map->rapport_color = 0;
	else
		map->rapport_color = (float)255 / ((float)map->max_z
				- (float)map->min_z);
}

int	color_z(t_map *map, int z)
{
	int	color;

	color = ((float)z - (float)map->min_z) * map->rapport_color;
	return (color);
}

float	rapport(t_map *map, int z_start, int z_end, int nb_pixel)
{
	float	color_sart;
	float	color_end;

	if (nb_pixel == 0)
		nb_pixel = 1;
	color_sart = ((float)z_start - (float)map->min_z) * map->rapport_color;
	color_end = ((float)z_end - (float)map->min_z) * map->rapport_color;
	return ((color_end - color_sart) / (float)nb_pixel);
}

int	up_color(t_line *line)
{
	float	temp;

	line->rest = line->rest + line->increment;
	temp = line->rest;
	if (line->rest >= 1)
	{
		while (line->rest >= 1)
			line->rest = line->rest - 1;
	}
	return ((int)temp);
}

int	set_gradian(int gradiant)
{
	ft_sign(&gradiant);
	if (gradiant > 255)
		gradiant = 255;
	return (encode_rgb(gradiant, 0, 255 - gradiant));
}
