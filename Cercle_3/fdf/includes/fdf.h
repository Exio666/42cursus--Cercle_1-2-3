/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:08:26 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/28 13:19:47 by bsavinel         ###   ########.fr       */
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
# include <stdio.h>

/*
 *	Define windows
 */

# define HEIGHT 1200
# define WIDTH 2000
# define ROTATION 0.01
# define TRANSLATION 10
# define V_ZOOM 1

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
# define D_PROJECTION 112

/*
 *	Structure
 */

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

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
	float		rot_z;
	float		rot_y;
	float		rot_x;
	t_data		image;
	t_angle		*angle;
	void		*mlx_ptr;
	void		*mlx_win;
	t_3Dpoint	**map3d;
	t_2Dpoint	**map2d;
	int			len_line;
	int			nb_line;
	int			zoom;
	int			camera;
	int			scaling;
	int			first;
	int			translation_x;
	int			translation_y;
	int			projection;
	int			max_z;
	int			min_z;
	float		rapport_color;
	float		rapport_pixel;
	float		rest;
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
	int			color;
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
t_2Dpoint	isometric_point(t_3Dpoint p3d, int zoom, int scaling, t_map *map);
int			malloc_map2d(t_map *map);

/*
 *	draw_line.c
 */

int			ft_sign(int *a);
void		const_line(t_map *map, t_line line);
void		line_hor(t_map *map, t_line line);
void		line_ver(t_map *map, t_line line);
void		draw_line(t_map *map, t_2Dpoint p1, t_2Dpoint p2, int color);

/*
 *	end.c
 */

int			free_map3d(t_map *map, int j);
int			free_map2d(t_map *map, int j);
void		exit_prog(t_map *map, int status);

/*
 *	fdf_utils.c
 */

void		reset_black(t_data *image);
void		pixel_put_image(t_data *image, int x, int y, int color);
int			encode_rgb(int red, int green, int blue);
int			set_color2(t_3Dpoint p1, t_3Dpoint p2);

/*
 *	main.c
 */

int			print_map(t_map	*map);
void		start_fdf(t_map *map);
void		reset_map(t_map *map);

/*
 *	parsing.c
 */

void		set_3D_map(int x, int y, char *z);
int			len_line(char *str);
int			parse_map(int fd, t_map *map);
int			counter_line(int fd, t_map *map);
int			parser(char *file, t_map *map);

/*
 *	rotate.c
 */

int			rotate_alpha(t_3Dpoint *point, float rotation);
int			rotate_beta(t_3Dpoint *point, float rotation);
int			rotate_gamma(t_3Dpoint *point, float rotation);
void		apply_rotate(t_3Dpoint *p3d, float z, float y, float x);

/*
 *	select_hook.c
 */

int			select_hook(int hook, t_map *map);
void		select_hook2(int hook, t_map *map);

/*
 *	translate_zoom.c
 */

int			up_zoom(t_map *map, int zoom);
int			down_zoom(t_map *map, int zoom);
int			translat_horizontal(t_map *map, int tran);
int			translat_vertical(t_map *map, int tran);

/*
 *	init_zoom_trans.c
 */

int			calcul_zoom_hor(t_map *map);
int			calcul_zoom_ver(t_map *map);
int			intital_zoom(t_map *map);
void		init_translat(t_map *map);

/*
 *	color.c
 */

void		set_color(t_map *map);
int			color_z(t_map *map, int z);
void		rapport(t_map *map, int z_start, int z_end, int nb_pixel);
int			up_color(t_map *map);

#endif