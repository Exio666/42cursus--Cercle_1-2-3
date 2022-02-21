/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_zoom_trans.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:10:01 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/18 15:49:57 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	calcul_zoom_hor(t_map *map)
{
	float		zoom;
	t_2Dpoint	p1;
	t_2Dpoint	p2;

	zoom = 1;
	p1 = isometric_point(map->map3d[0][0], zoom, 7, map);
	p2 = isometric_point(map->map3d[map->nb_line - 1][map->len_line - 1],
			zoom, 7, map);
	while (ft_abs(p2.y - p1.y) < 900)
	{
		p1 = isometric_point(map->map3d[0][0], zoom, 7, map);
		p2 = isometric_point(map->map3d[map->nb_line - 1][map->len_line - 1],
				zoom, 7, map);
		zoom = zoom * V_ZOOM;
	}
	while (ft_abs(p2.y - p1.y) > 1000)
	{
		p1 = isometric_point(map->map3d[0][0], zoom, 7, map);
		p2 = isometric_point(map->map3d[map->nb_line - 1][map->len_line - 1],
				zoom, 7, map);
		zoom = zoom / V_ZOOM;
	}
	return (zoom);
}

float	calcul_zoom_ver(t_map *map)
{
	float		zoom;
	t_2Dpoint	p1;
	t_2Dpoint	p2;

	zoom = 1;
	p1 = isometric_point(map->map3d[map->nb_line - 1][0], zoom, 7, map);
	p2 = isometric_point(map->map3d[0][map->len_line - 1], zoom, 7, map);
	while (ft_abs(p2.x - p1.x) < 1700)
	{
		p1 = isometric_point(map->map3d[map->nb_line - 1][0], zoom, 7, map);
		p2 = isometric_point(map->map3d[0][map->len_line - 1], zoom, 7, map);
		zoom = zoom * V_ZOOM;
	}
	while (ft_abs(p2.x - p1.x) > 1800)
	{
		p1 = isometric_point(map->map3d[map->nb_line - 1][0], zoom, 7, map);
		p2 = isometric_point(map->map3d[0][map->len_line - 1], zoom, 7, map);
		zoom = zoom / V_ZOOM;
	}
	return (zoom);
}

float	intital_zoom(t_map *map)
{
	float	zoom_ver;
	float	zoom_hot;

	if (map->len_line == 1 && map->nb_line == 1)
		return (1);
	zoom_ver = calcul_zoom_ver(map);
	zoom_hot = calcul_zoom_hor(map);
	if (zoom_hot > zoom_ver)
		return (zoom_ver / V_ZOOM);
	else
		return (zoom_hot / V_ZOOM);
}

void	init_translat(t_map *map)
{
	if (map->len_line == 1 && map->nb_line == 1)
		return ;
	while (map->map2d[map->nb_line - 1][0].x < 100)
	{
		translat_horizontal(map, 25);
		map->translation_x += 25;
	}
	while (map->map2d[0][0].y < 100)
	{
		translat_vertical(map, 25);
		map->translation_y += 25;
	}
	while (map->map2d[map->nb_line - 1][0].x > 100)
	{
		translat_horizontal(map, -25);
		map->translation_x -= 25;
	}
	while (map->map2d[0][0].y > 100)
	{
		translat_vertical(map, -25);
		map->translation_y -= 25;
	}
}
