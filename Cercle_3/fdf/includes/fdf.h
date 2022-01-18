/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:08:26 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/18 16:39:18 by bsavinel         ###   ########.fr       */
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

# define D_ROT_UPZ 113
# define D_ROT_DOWNZ 97
# define D_ROT_UPX 119
# define D_ROT_DOWNX 115
# define D_ROT_UPY 101
# define D_ROT_DOWNY 100
# define D_TRANS_UP 65362
# define D_TRANS_DOWN 65364
# define D_TRANS_LEFT 65361
# define D_TRANS_RIGHT 65363
# define D_UP_ZOOM 65451
# define D_DOWN_ZOOM 65453
# define D_ESCAPE 65307
# define D_COLOR 99
# define D_RESET 114
# define D_ISOMETRIC 105
# define D_PARALLEL 112

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

typedef struct s_rot
{
	int	rot_x;
	int	rot_y;
	int	rot_z;
}	t_rot;

/*
 *	convertor.c
 */

int			convertor(t_map *map);
t_2Dpoint	isometric_point(t_3Dpoint p3d);

/*
 *	draw_line.c
 */

int			ft_sign(int *a);
void		const_line(void *mlx, void *mlx_win, t_line line);
void		line_hor(void *mlx, void *mlx_win, t_line line);
void		line_ver(void *mlx, void *mlx_win, t_line line);
void		draw_line(void *mlx, void *mlx_win, t_2Dpoint p1, t_2Dpoint p2);

/*
 *	end.c
 */

int			free_map(int **map);

/*
 *	fdf_utils.c
 */

int			encode_rgb(int red, int green, int blue);

/*
 *	parsing.c
 */

t_3Dpoint	set_3D_map(int x, int y, char *z);
int			len_line(char *str);
int			parse_map(int fd, t_map *map);
int			counter_line(int fd, t_map *map);
int			parser(char *file, t_map *map);

/*
 *	rotate.c
 */

int			rotate_alpha(t_3Dpoint *point, int rotation);
int			rotate_beta(t_3Dpoint *point, int rotation);
int			rotate_gamma(t_3Dpoint *point, int rotation);
void		apply_rotate(t_map *map, t_rot rot);

/*
 *	translate_zoom.c
 */

int			translat_horizontal(t_map *map, int tran);
int			translat_vertical(t_map *map, int tran);

#endif