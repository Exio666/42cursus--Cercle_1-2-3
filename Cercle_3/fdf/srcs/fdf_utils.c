/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:08:57 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/28 14:16:55 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	set_color2(t_3Dpoint p1, t_3Dpoint p2)
{
	if (p1.z == p2.z)
		return (encode_rgb(255, 255, 255));
	else
		return (encode_rgb(255, 0, 0));
}

void	pixel_put_image(t_data *image, int x, int y, int color)
{
	char	*dst;

	if (x > WIDTH - 1 || y > HEIGHT - 1 || x < 0 || y < 0)
		return ;
	dst = image->addr + (y * image->line_length + x
			* (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	reset_black(t_data *image)
{
	int	y;
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			pixel_put_image(image, x, y, encode_rgb(0, 0, 0));
			y++;
		}
		x++;
	}
}
