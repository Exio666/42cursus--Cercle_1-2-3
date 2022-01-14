/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:08:26 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/14 15:01:05 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "mlx.h"
# include "libft.h"

/*
 *	Define
 */

#define HEIGHT 1200
#define WEIGHT 2000

/*
 *	Structur
 */

typedef struct s_2Dpoint
{
	int x;
	int y;
} t_2Dpoint;

typedef struct s_3Dpoint
{
	int x;
	int y;
	int z;
} t_3Dpoint;

typedef struct s_line
{
	t_2Dpoint p1;
	t_2Dpoint p2;
	int	slope;
	int	error;
	int	error_inc;
	int	dx;
	int	dy;
	int	inc_x;
	int	inc_y;
} t_line;

/*
 *	main.c
 */



/*
 *	algo_bresenham.c
 */

void	draw_line(void *mlx, void *mlx_win,t_2Dpoint point_1, t_2Dpoint point_2);

/*
 *	file.c
 */


/*
 *	fdf_utils.c
 */

int		encode_rgb(int red, int green, int blue);

#endif