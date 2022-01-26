/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:10:01 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/26 14:29:55 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	calcul_zoom_hor(t_map *map)
{
	int			zoom;
	t_2Dpoint	p1;
	t_2Dpoint	p2;

	zoom = 1;
	p1 = isometric_point(map->map3d[0][0], zoom, 7, map);
	p2 = isometric_point(map->map3d[map->nb_line - 1][map->len_line - 1],
			zoom, 7, map);
	while (p2.y - p1.y < 900)
	{
		p1 = isometric_point(map->map3d[0][0], zoom, 7, map);
		p2 = isometric_point(map->map3d[map->nb_line - 1][map->len_line - 1],
				zoom, 7, map);
		zoom++;
	}
	printf("2 : %i diff : %i\n", zoom, p2.y - p1.y);
	if (p2.y - p1.y > 1000 && zoom != 1)
		return (zoom - 2);
	return (zoom - 1);
}

int	calcul_zoom_ver(t_map *map)
{
	int			zoom;
	t_2Dpoint	p1;
	t_2Dpoint	p2;

	zoom = 1;
	p1 = isometric_point(map->map3d[map->nb_line - 1][0], zoom, 7, map);
		p2 = isometric_point(map->map3d[0][map->len_line - 1], zoom, 7, map);
	while (p2.x - p1.x < 1700)
	{
		p1 = isometric_point(map->map3d[map->nb_line - 1][0], zoom, 7, map);
		p2 = isometric_point(map->map3d[0][map->len_line - 1], zoom, 7, map);
		zoom++;
	}
	printf("2 : %i diff : %i\n", zoom, p2.x - p1.x);
	if (p2.x - p1.x > 1800 && zoom != 1)
		return (zoom - 2);
	return (zoom - 1);
}

int	intital_zoom(t_map *map)
{
	int	zoom_ver;
	int	zoom_hot;

	zoom_ver = calcul_zoom_ver(map);
	zoom_hot = calcul_zoom_hor(map);
	if (zoom_hot > zoom_ver)
		return (zoom_ver);
	else
		return (zoom_hot);
}
