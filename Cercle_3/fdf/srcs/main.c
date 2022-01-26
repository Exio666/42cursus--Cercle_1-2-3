/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:25:54 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/26 14:07:41 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	print_map(t_map	*map)
{
	int	i;
	int	j;
	int	color;

	j = 0;
	reset_black(&map->image);
	convertor(map);
	translat_horizontal(map, map->translation_x);
	translat_vertical(map, map->translation_y);
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
	mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->image.img, 0, 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_map	map;

	map.rot_z = 0;
	map.rot_x = 0;
	map.rot_y = 0;
	map.scaling = 7;
	map.translation_x = 400;
	map.translation_y = 400;
	if (ac != 2)
		return (0);
	map.mlx_ptr = mlx_init();
	parser(av[1], &map);
	map.zoom = intital_zoom(&map);
	map.mlx_win = mlx_new_window(map.mlx_ptr, WIDTH, HEIGHT, av[1]);
	map.image.img = mlx_new_image(map.mlx_ptr, WIDTH, HEIGHT);
	map.image.addr = mlx_get_data_addr(map.image.img, &map.image.bits_per_pixel,
			&map.image.line_length, &map.image.endian);
	malloc_map2d(&map);
	print_map(&map);
	mlx_key_hook(map.mlx_win, select_hook, &map);
	mlx_loop(map.mlx_ptr);
}
