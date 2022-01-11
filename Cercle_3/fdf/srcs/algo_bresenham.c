/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bresenham.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:28:20 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/07 15:42:44 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_algo_de_Bresenham(void *mlx, void *mlx_win,t_2Dpoint point_1, t_2Dpoint point_2)
{
	t_range_error error;
	int y;
	int dx;
	int dy;
	
	dy = point_1.y - point_2.y;
	dx = point_1.x - point_2.x;
	y = point_1.y;
	error.actual = 0.0;
	error.x = dy / dx;
	error.y = -1.0;
	while (point_1.x <= point_2.x)
	{
		mlx_pixel_put (mlx, mlx_win, point_1.x, y, encode_rgb(255,255,255));
		error.actual = error.actual + error.x;
		if (error.actual >= 0.5)
		{
			y = y + 1;
			error.actual = error.actual + error.y;
		}
		point_1.x++;
	}
}