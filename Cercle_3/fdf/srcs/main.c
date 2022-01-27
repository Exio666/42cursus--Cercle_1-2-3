/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:25:54 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/27 14:52:57 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	reset_map(t_map *map)
{
	map->first = 0;
	map->rot_z = 0;
	map->rot_x = 0;
	map->rot_y = 0;
	map->scaling = 7;
	map->projection = 0;
	map->translation_x = 0;
	map->translation_y = 0;
}

void	draw_map(t_map *map)
{
	int	i;
	int	j;
	int	color;

	j = 0;
	while (j < map->nb_line)
	{
		i = 0;
		while (i < map->len_line)
		{
			if (i < map->len_line - 1)
			{
				color = set_color(map->map3d[j][i], map->map3d[j][i + 1]);
				draw_line(map, map->map2d[j][i], map->map2d[j][i + 1], color);
			}
			if (j < map->nb_line - 1)
			{
				color = set_color(map->map3d[j][i], map->map3d[j + 1][i]);
				draw_line(map, map->map2d[j][i], map->map2d[j + 1][i], color);
			}
			i++;
		}
		j++;
	}
}

int	print_map(t_map	*map)
{
	if (map->first == 0)
		map->zoom = intital_zoom(map);
	reset_black(&map->image);
	convertor(map);
	if (map->first == 0)
		init_translat(map);
	else
	{
		translat_horizontal(map, map->translation_x);
		translat_vertical(map, map->translation_y);
	}
	map->first = 1;
	draw_map(map);
	mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->image.img, 0, 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (0);
	map.min_z = 0;
	map.max_z = 0;
	reset_map(&map);
	if (parser(av[1], &map) == 0)
		exit_prog(&map, 5);
	malloc_map2d(&map);
	map.mlx_ptr = mlx_init();
	map.mlx_win = mlx_new_window(map.mlx_ptr, WIDTH, HEIGHT, av[1]);
	map.image.img = mlx_new_image(map.mlx_ptr, WIDTH, HEIGHT);
	map.image.addr = mlx_get_data_addr(map.image.img, &map.image.bits_per_pixel,
			&map.image.line_length, &map.image.endian);
	print_map(&map);
	mlx_key_hook(map.mlx_win, select_hook, &map);
	mlx_loop(map.mlx_ptr);
	return (1);
}
