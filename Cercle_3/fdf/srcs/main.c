/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:25:54 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/07 16:05:27 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void *mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );

int    encode_rgb(int red, int green, int blue)
{
    return (red << 16 | green << 8 | blue);
}

int main()
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_2Dpoint point_1;
	t_2Dpoint point_2;

	point_1.x = 1000;
	point_1.y = 3;
	point_2.x = 2;
	point_2.y = 1100;
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window (mlx_ptr, 2000, 3000, "Le titre");
	ft_algo_de_Bresenham(mlx_ptr, mlx_win, point_1, point_2);
	while (1)
		;
	mlx_destroy_window(mlx_ptr, mlx_win);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}