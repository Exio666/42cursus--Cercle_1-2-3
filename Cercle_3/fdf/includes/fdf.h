/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:08:26 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/15 17:10:48 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

/*
 *	Define
 */

# define HEIGHT 1200
# define WEIGHT 2000

/*
 *	Structur
 */

typedef struct s_2Dpoint
{
	int	x;
	int	y;
}	t_2Dpoint;

typedef struct s_3Dpoint
{
	int	x;
	int	y;
	int	z;
}	t_3Dpoint;

typedef struct s_line
{
	t_2Dpoint	p1;
	t_2Dpoint	p2;
	int			slope;
	int			error;
	int			error_inc;
	int			dx;
	int			dy;
	int			inc_x;
	int			inc_y;
}	t_line;

/*
 *	algo_bresenham.c
 */

void	draw_line(void *mlx, void *mlx_win, t_2Dpoint p1, t_2Dpoint p2);

/*
 *	fdf_utils.c
 */

int		encode_rgb(int red, int green, int blue);

/*
 *	parssing.c
 */

int		**parser(char *file);

#endif