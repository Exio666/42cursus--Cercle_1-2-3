/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:25:54 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/19 14:30:28 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_map(t_map *map)
{
	map->first = 0;
	map->rot_z = 0;
	map->rot_x = 0;
	map->rot_y = 0;
	map->scaling = SCALING;
	map->projection = 0;
	map->translation_x = 0;
	map->translation_y = 0;
}

void	draw_map(t_map *map)
{
	int		i;
	int		j;
	t_color	color;

	j = -1;
	while (++j < map->nb_line)
	{
		i = -1;
		while (++i < map->len_line)
		{
			color.color_start = color_z(map, map->map3d[j][i].z);
			color.p1_z = map->map3d[j][i].z;
			if (i < map->len_line - 1)
			{
				color.p2_z = map->map3d[j][i + 1].z;
				draw_line(map, map->map2d[j][i], map->map2d[j][i + 1], color);
			}
			if (j < map->nb_line - 1)
			{
				color.p2_z = map->map3d[j + 1][i].z;
				draw_line(map, map->map2d[j][i], map->map2d[j + 1][i], color);
			}
		}
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

void	print_action(void)
{
	ft_printf("You can rotate with: 'q' 'w' 'e' 'a' 's' 'd'\n");
	ft_printf("You can moove the map with: directional arrow\n");
	ft_printf("You can zoom with: '+' '-'\n");
	ft_printf("You can change view with: 'p'\n");
	ft_printf("You can reset view with: 'r'\n");
	ft_printf("You can close window with: 'esc' or the cross\n");
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (0);
	map.min_z = 0;
	map.max_z = 0;
	map.mlx_ptr = mlx_init();
	if (!map.mlx_ptr)
		return (0);
	reset_map(&map);
	if (parser(av[1], &map) == 0)
		exit_prog(&map, 5);
	set_color(&map);
	malloc_map2d(&map);
	map.mlx_win = mlx_new_window(map.mlx_ptr, WIDTH, HEIGHT, av[1]);
	map.image.img = mlx_new_image(map.mlx_ptr, WIDTH, HEIGHT);
	map.image.addr = mlx_get_data_addr(map.image.img, &map.image.bits_per_pixel,
			&map.image.line_length, &map.image.endian);
	print_map(&map);
	print_action();
	mlx_hook(map.mlx_win, 17, 0, exit_prog2, &map);
	mlx_key_hook(map.mlx_win, select_hook, &map);
	mlx_loop(map.mlx_ptr);
	return (1);
}
