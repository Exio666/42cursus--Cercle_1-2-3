/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:28:20 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/24 18:14:55 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	ft_sign(int *a)
{
	if (*a > 0)
		return (1);
	else
	{
		*a = -(*a);
		return (-1);
	}
}

void	const_line(t_map *map, t_line line)
{
	while (line.p1.x != line.p2.x + line.inc_x && line.p1.y
		!= line.p2.y + line.inc_y)
	{
		mlx_pixel_put(map->mlx_ptr, map->mlx_win, line.p1.x, line.p1.y,
			line.color);
		if (line.dy == 0)
			line.p1.x += line.inc_x;
		if (line.dx == 0)
			line.p1.y += line.inc_y;
	}
}

void	line_hor(t_map *map, t_line line)
{
	line.slope = 2 * line.dy;
	line.error = -line.dx;
	line.error_inc = -2 * line.dx;
	while (line.p1.x != line.p2.x + line.inc_x)
	{
		mlx_image(map->mlx_ptr, map->mlx_win, line.p1.x, line.p1.y,
			line.color);
		line.error += line.slope;
		if (line.error >= 0)
		{
			line.p1.y += line.inc_y;
			line.error += line.error_inc;
		}
		line.p1.x += line.inc_x;
	}
}

void	line_ver(t_map *map, t_line line)
{
	line.slope = 2 * line.dx;
	line.error = -line.dy;
	line.error_inc = -2 * line.dy;
	while (line.p1.y != line.p2.y + line.inc_y)
	{
		mlx_pixel_put(map->mlx_ptr, map->mlx_win, line.p1.x, line.p1.y,
			line.color);
		line.error += line.slope;
		if (line.error >= 0)
		{
			line.p1.x += line.inc_x;
			line.error += line.error_inc;
		}
		line.p1.y += line.inc_y;
	}
}

void	draw_line(t_map *map, t_2Dpoint p1, t_2Dpoint p2, int color)
{
	t_line	line;

	line.color = color;
	line.p1 = p1;
	line.p2 = p2;
	line.dx = p2.x - p1.x;
	line.dy = p2.y - p1.y;
	line.inc_x = ft_sign(&line.dx);
	line.inc_y = ft_sign(&line.dy);
	if (line.dy == 0 || line.dx == 0)
		const_line(map, line);
	else if (line.dx >= line.dy)
		line_hor(map, line);
	else
		line_ver(map, line);
}

/*
int	ft_sign(int *a)
{
	if (*a > 0)
		return (1);
	else
	{
		*a = -(*a);
		return (-1);
	}
}

void	const_line(void *mlx, void *mlx_win, t_line line)
{
	while (line.p1.x != line.p2.x + line.inc_x && line.p1.y
		!= line.p2.y + line.inc_y)
	{
		mlx_pixel_put(mlx, mlx_win, line.p1.x, line.p1.y,
			line.color);
		if (line.dy == 0)
			line.p1.x += line.inc_x;
		if (line.dx == 0)
			line.p1.y += line.inc_y;
	}
}

void	line_hor(void *mlx, void *mlx_win, t_line line)
{
	line.slope = 2 * line.dy;
	line.error = -line.dx;
	line.error_inc = -2 * line.dx;
	while (line.p1.x != line.p2.x + line.inc_x)
	{
		mlx_pixel_put(mlx, mlx_win, line.p1.x, line.p1.y,
			line.color);
		line.error += line.slope;
		if (line.error >= 0)
		{
			line.p1.y += line.inc_y;
			line.error += line.error_inc;
		}
		line.p1.x += line.inc_x;
	}
}

void	line_ver(void *mlx, void *mlx_win, t_line line)
{
	line.slope = 2 * line.dx;
	line.error = -line.dy;
	line.error_inc = -2 * line.dy;
	while (line.p1.y != line.p2.y + line.inc_y)
	{
		mlx_pixel_put(mlx, mlx_win, line.p1.x, line.p1.y,
			line.color);
		line.error += line.slope;
		if (line.error >= 0)
		{
			line.p1.x += line.inc_x;
			line.error += line.error_inc;
		}
		line.p1.y += line.inc_y;
	}
}

void	draw_line(t_map *map, t_2Dpoint p1, t_2Dpoint p2, int color)
{
	t_line	line;

	line.color = color;
	line.p1 = p1;
	line.p2 = p2;
	line.dx = p2.x - p1.x;
	line.dy = p2.y - p1.y;
	line.inc_x = ft_sign(&line.dx);
	line.inc_y = ft_sign(&line.dy);
	if (line.dy == 0 || line.dx == 0)
		const_line(map->mlx_ptr, map->mlx_win, line);
	else if (line.dx >= line.dy)
		line_hor(map->mlx_ptr, map->mlx_win, line);
	else
		line_ver(map->mlx_ptr, map->mlx_win, line);
}
*/
/* Code save*/
/*
void	draw_line(void *mlx, void *mlx_win, t_2Dpoint p1, t_2Dpoint p2)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	inc_x;
	int	inc_y;
	int	slope;
	int	error;
	int	error_inc;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	==============================
	if (dx > 0)
		inc_x = 1;
	else
	{
		inc_x = -1;								-->				inc_x = ft_sign(&dx);
		dx = -dx;								-->				inc_y = ft_sign(&dy);										
	}
	if (dy > 0)
		inc_y = 1;
	else
	{
		inc_y = -1;
		dy = -dy;
	}
	==============================
	if (dy == 0 || dx == 0)
	{
		while (p1.x != p2.x + inc_x && p1.y != p2.y + inc_y)
		{
			mlx_pixel_put(mlx, mlx_win, p1.x, p1.y, encode_rgb(255, 255, 255));
			if (dy == 0)
				p1.x += inc_x;
			if (dx == 0)
				p1.y += inc_y;
		}
	}
	else if (dx >= dy)
	{
		slope = 2 * dy;
		error = -dx;
		error_inc = -2 * dx;
		y = p1.y;
		while (p1.x != p2.x + inc_x)
		{
			mlx_pixel_put(mlx, mlx_win, p1.x, y, encode_rgb(255, 255, 255));
			error += slope;
			if (error >= 0)
			{
				y += inc_y;
				error += error_inc;
			}
			p1.x += inc_x;
		}
	}
	else
	{
		slope = 2 * dx;
		error = -dy;
		error_inc = -2 * dy;
		x = p1.x;
		while (p1.y != p2.y + inc_y)
		{
			mlx_pixel_put(mlx, mlx_win, x, p1.y, encode_rgb(255, 255, 255));
			error += slope;
			if (error >= 0)
			{
				x += inc_x;
				error += error_inc;
			}
			p1.y += inc_y;
		}
	}
}
*/
