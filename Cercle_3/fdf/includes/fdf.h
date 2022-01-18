/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:08:26 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/18 09:12:22 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

/*
 *	Define
 */

# define HEIGHT 1200
# define WEIGHT 2000
//# define M_PI	3.14159265358979323846
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
	int	z;
	int	x;
	int	y;
}	t_3Dpoint;

typedef struct s_angle
{
	int	alpha;
	int	beta;
	int	gamma;
}	t_angle;

typedef struct s_map
{
	t_angle		*angle;
	void		*mlx_ptr;
	void		*mlx_win;
	t_3Dpoint	**map3d;
	t_2Dpoint	**map2d;
	int			len_line;
	int			nb_line;
	int			camera;
}	t_map;

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
 *	parsing.c
 */

int		parser(char *file, t_map *map);

/*
 *	rotate.c
 */

int rotate_alpha(t_3Dpoint *point, int rotation);
int rotate_beta(t_3Dpoint *point, int rotation);
int rotate_gamma(t_3Dpoint *point, int rotation);
void	apply_rotate(t_map *map, int rotation);

/*
 *	free.c
 */

int	free_map(int **map);

#endif