/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:49:23 by bsavinel          #+#    #+#             */
/*   Updated: 2022/02/19 18:51:18 by bsavinel         ###   ########.fr       */
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

void	const_line(t_map *map, t_line line, t_color color)
{
	if (line.dy == 0)
		line.increment = rapport(map, color.p1_z, color.p2_z, line.p2.x
				- line.p1.x);
	if (line.dx == 0)
		line.increment = rapport(map, color.p1_z, color.p2_z, line.p2.y
				- line.p1.y);
	while (line.p1.x != line.p2.x + line.inc_x && line.p1.y
		!= line.p2.y + line.inc_y)
	{
		line.color = line.color + line.increment;
		pixel_put_image(&map->image, line.p1.x, line.p1.y,
			set_gradian((int)line.color));
		if (line.dy == 0)
			line.p1.x += line.inc_x;
		if (line.dx == 0)
			line.p1.y += line.inc_y;
	}
}

void	line_hor(t_map *map, t_line line, t_color color)
{
	line.slope = 2 * line.dy;
	line.error = -line.dx;
	line.error_inc = -2 * line.dx;
	line.increment = rapport(map, color.p1_z, color.p2_z,
			(line.p2.x - line.p1.x) * line.inc_x);
	while (line.p1.x != line.p2.x + line.inc_x)
	{
		line.color = line.color + line.increment;
		pixel_put_image(&map->image, line.p1.x, line.p1.y,
			set_gradian((int)line.color));
		line.error += line.slope;
		if (line.error >= 0)
		{
			line.p1.y += line.inc_y;
			line.error += line.error_inc;
		}
		line.p1.x += line.inc_x;
	}
}

void	line_ver(t_map *map, t_line line, t_color color)
{
	line.slope = 2 * line.dx;
	line.error = -line.dy;
	line.error_inc = -2 * line.dy;
	line.increment = rapport(map, color.p1_z, color.p2_z,
			(line.p2.y - line.p1.y) * line.inc_y);
	while (line.p1.y != line.p2.y + line.inc_y)
	{
		line.color = line.color + line.increment;
		pixel_put_image(&map->image, line.p1.x, line.p1.y,
			set_gradian((int)line.color));
		line.error += line.slope;
		if (line.error >= 0)
		{
			line.p1.x += line.inc_x;
			line.error += line.error_inc;
		}
		line.p1.y += line.inc_y;
	}
}

void	draw_line(t_map *map, t_2Dpoint p1, t_2Dpoint p2, t_color color)
{
	t_line	line;

	line.color = (float)color.color_start;
	line.p1 = p1;
	line.p2 = p2;
	line.dx = p2.x - p1.x;
	line.dy = p2.y - p1.y;
	line.inc_x = ft_sign(&line.dx);
	line.inc_y = ft_sign(&line.dy);
	if (line.dy == 0 || line.dx == 0)
		const_line(map, line, color);
	else if (line.dx >= line.dy)
		line_hor(map, line, color);
	else
		line_ver(map, line, color);
}
