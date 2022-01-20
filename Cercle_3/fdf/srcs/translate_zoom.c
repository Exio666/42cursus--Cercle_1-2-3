/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_zoom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:57:47 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/20 14:10:23 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	up_zoom(t_map *map, int zoom)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->nb_line)
	{
		i = 0;
		printf("ICI\n");
		while (i < map->len_line)
		{
			map->map2d[j][i].x *= zoom;
			map->map2d[j][i].y *= zoom;
			printf("LA\n");
			i++;
		}
		j++;
	}
	return (1);
}

int	down_zoom(t_map *map, int zoom)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->nb_line)
	{
		i = 0;
		while (i < map->len_line)
		{
			map->map2d[j][i].x -= zoom * j;
			map->map2d[j][i].y -= zoom * i;
			i++;
		}
		j++;
	}
	return (1);
}

int	translat_horizontal(t_map *map, int tran)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->nb_line)
	{
		i = 0;
		while (i < map->len_line)
		{
			map->map2d[j][i].x += tran;
			i++;
		}
		j++;
	}
	return (1);
}

int	translat_vertical(t_map *map, int tran)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->nb_line)
	{
		i = 0;
		while (i < map->len_line)
		{
			map->map2d[j][i].y += tran;
			i++;
		}
		j++;
	}
	return (1);
}
