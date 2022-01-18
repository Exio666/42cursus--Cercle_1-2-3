/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:08:26 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/18 16:04:12 by bsavinel         ###   ########.fr       */
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
 *	Define windows
 */

# define HEIGHT 1200
# define WEIGHT 2000

/*
 *	Define touche
 */

# define d_rot_upz 113
# define d_rot_downz 97
# define d_rot_upx 119
# define d_rot_downx 115
# define d_rot_upy 101
# define d_rot_downy 100
# define d_trans_up 65362
# define d_trans_down 65364
# define d_trans_left 65361
# define d_trans_right 65363
# define d_up_zoom 65451
# define d_downd_zoom 65453
# define d_escape 65307
# define d_color 99
# define d_reset 114
# define d_isometric 105
# define d_paralel 112

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
 *	convertor.c
 */

int			convertor(t_map *map);
t_2Dpoint	isometric_point(t_3Dpoint p3d);

/*
 *	draw_line.c
 */

void		draw_line(void *mlx, void *mlx_win, t_2Dpoint p1, t_2Dpoint p2);

/*
 *	fdf_utils.c
 */

int			encode_rgb(int red, int green, int blue);

/*
 *	parsing.c
 */

int			parser(char *file, t_map *map);

/*
 *	rotate.c
 */

int			rotate_alpha(t_3Dpoint *point, int rotation);
int			rotate_beta(t_3Dpoint *point, int rotation);
int			rotate_gamma(t_3Dpoint *point, int rotation);
void		apply_rotate(t_map *map, int rotation);

/*
 *	translate_zoom.c
 */

int		translat_horizontal(t_map *map, int tran);
int		translat_vertical(t_map *map, int tran);

/*
 *	free.c
 */

int		free_map(int **map);

#endif