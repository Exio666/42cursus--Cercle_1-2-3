/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:25:54 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/18 16:07:17 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

// TODO initialiser->parser->rotation_de_base->convertir_en_2d->tracer_la_map->attendre des instruction->remmtre_noir	->mollete->zoom
//																														->esc->exit_poprement
//																														->fleche->bouger
//																														->wasd->rotation
//																														->c->couleur
// TODO modif draw line pour image

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	printf("Touche : %i\n", keycode);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}

/*
int main(int ac, char **av)
{
	int 	i = 0;
	int 	j = 0;
	t_map	*map;

	if (ac != 2)
		return (0);
	map = malloc(sizeof(t_map));
	parser(av[1], map);
	while (i != map->nb_line)
	{
		j = 0;
		while (j != map->len_line)
		{
			printf("%5i ", map->map3d[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}


int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		return (0);
	map = malloc(sizeof(t_map));
	parser(av[1], map);
	map->mlx_ptr = mlx_init();
	parser(av[1], map);
	map->mlx_win = mlx_new_window (map->mlx_ptr, WEIGHT, HEIGHT, "Fdf 42");
	
	
	mlx_destroy_window(map->mlx_ptr, map->mlx_win);
	mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
}


******************************
* main pour tarcer des ligne *
******************************
int	main(void)
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_2Dpoint	point_1;
	t_2Dpoint	point_2;
	t_2Dpoint	point_3;
	t_2Dpoint	point_4;
	t_2Dpoint	point_5;
	t_2Dpoint	point_6;
	t_2Dpoint	point_7;
	t_2Dpoint	point_8;
	t_2Dpoint	point_9;

	point_1.x = 150;
	point_1.y = 150;
	point_2.x = 150;
	point_2.y = 300;
	point_3.x = 300;
	point_3.y = 300;
	point_4.x = 300;
	point_4.y = 150;
	point_5.x = 207;
	point_5.y = 528;
	point_6.x = 7;
	point_6.y = 22;
	point_7.x = 1022;
	point_7.y = 57;
	point_8.x = 1022;
	point_8.y = 1150;
	point_9.x = 20;
	point_9.y = 200;
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window (mlx_ptr, WEIGHT, HEIGHT, "Le titre");
	draw_line(mlx_ptr, mlx_win, point_1, point_2);
	draw_line(mlx_ptr, mlx_win, point_1, point_1);
	draw_line(mlx_ptr, mlx_win, point_2, point_3);
	draw_line(mlx_ptr, mlx_win, point_3, point_4);
	draw_line(mlx_ptr, mlx_win, point_4, point_1);
	draw_line(mlx_ptr, mlx_win, point_5, point_1);
	draw_line(mlx_ptr, mlx_win, point_6, point_1);
	draw_line(mlx_ptr, mlx_win, point_7, point_1);
	draw_line(mlx_ptr, mlx_win, point_8, point_1);
	draw_line(mlx_ptr, mlx_win, point_9, point_1);
	draw_line(mlx_ptr, mlx_win, point_2, point_4);
	draw_line(mlx_ptr, mlx_win, point_3, point_1);
	draw_line(mlx_ptr, mlx_win, point_2, point_5);
	draw_line(mlx_ptr, mlx_win, point_3, point_5);
	draw_line(mlx_ptr, mlx_win, point_4, point_5);
	draw_line(mlx_ptr, mlx_win, point_2, point_6);
	draw_line(mlx_ptr, mlx_win, point_3, point_6);
	draw_line(mlx_ptr, mlx_win, point_4, point_6);
	draw_line(mlx_ptr, mlx_win, point_5, point_6);
	draw_line(mlx_ptr, mlx_win, point_2, point_7);
	draw_line(mlx_ptr, mlx_win, point_3, point_7);
	draw_line(mlx_ptr, mlx_win, point_4, point_7);
	draw_line(mlx_ptr, mlx_win, point_5, point_7);
	draw_line(mlx_ptr, mlx_win, point_6, point_7);
	draw_line(mlx_ptr, mlx_win, point_2, point_8);
	draw_line(mlx_ptr, mlx_win, point_3, point_8);
	draw_line(mlx_ptr, mlx_win, point_4, point_8);
	draw_line(mlx_ptr, mlx_win, point_5, point_8);
	draw_line(mlx_ptr, mlx_win, point_6, point_8);
	draw_line(mlx_ptr, mlx_win, point_7, point_8);
	draw_line(mlx_ptr, mlx_win, point_2, point_9);
	draw_line(mlx_ptr, mlx_win, point_3, point_9);
	draw_line(mlx_ptr, mlx_win, point_4, point_9);
	draw_line(mlx_ptr, mlx_win, point_5, point_9);
	draw_line(mlx_ptr, mlx_win, point_6, point_9);
	draw_line(mlx_ptr, mlx_win, point_7, point_9);
	draw_line(mlx_ptr, mlx_win, point_8, point_9);
	draw_line(mlx_ptr, mlx_win, point_9, point_9);
	while (1)
		;
	mlx_destroy_window(mlx_ptr, mlx_win);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}*/
