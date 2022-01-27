/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:42:53 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/27 13:28:52 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_map3d(t_map *map, int j)
{
	int	i;

	i = 0;
	if (map->map3d)
	{
		while (map->map3d[i] && i < j)
		{
			free(map->map3d[i]);
			i++;
		}
		free(map->map3d);
	}
	return (1);
}

int	free_map2d(t_map *map, int j)
{
	int	i;

	i = 0;
	if (map->map2d)
	{
		while (map->map2d[i] && i < j)
		{
			free(map->map2d[i]);
			i++;
		}
		free(map->map2d);
	}
	return (1);
}

void	exit_prog(t_map *map, int status)
{
	if (status == 0 || status == 1)
		free_map3d(map, map->nb_line);
	if (status == 0 || status == 2)
		free_map2d(map, map->nb_line);
	if (status != 5)
	{
		mlx_destroy_window(map->mlx_ptr, map->mlx_win);
		mlx_destroy_image(map->mlx_ptr, map->image.img);
		mlx_destroy_display(map->mlx_ptr);
		free(map->mlx_ptr);
	}
	exit(1);
}
