/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_minilibx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:17:04 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/14 11:49:28 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*****************************************************************
* cette lib n'est pas un prototypage des fonction mais un manuel *
******************************************************************/

/*
 * Flag a metre pour la conpil

= Rien compris (chercher puis tester c'est le mieux)

*/

/***************
 *** Couleur ***
 ***************

= Utiliser cette fonction pour obtenir la couleur que vous desirer 
= implementer dans les fonction de la minilibx
 
*/

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/*
 * Structure 
 */

/****************************************************
 **** Image (pas utilise pour du pixel par pixel ****
 ****************************************************/

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/************
 *** Hook ***
 ************/

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

/*
 * fonction minilibx
 */

void	*mlx_init();

/*
= Permet d'initialiser la minilibx
= Retour
=	\Processus ok
= 		\ un pointeur sur void a donner en premier argument des foction de la minilibx
= 	|Processus ratte
= 		\ retourne un pointeur nul
*/

void 	*mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );

/*
= Permet de cree une fenetre de largeur size_x et de hauteur size_y avec pour titre title
= Retour
= 	\Processus ok
= 		\ un pointeur sur void sur la fenetre
= 	|Processus ratte
= 		\ retourne un pointeur nul
*/

int		mlx_clear_window(void *mlx_ptr, void *win_ptr);

/*
= Permet de detruire la fenetre pointer par win_ptr
= Retour
= 	\ Aucun
*/

int		mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

/*
= Permet d'allumer un pixel sur la fenetre pointer par win_ptr au coordonne x y
= Retour
= 	\ Aucun
= couleur
=	\ (voir index couleur au debut de la page)
*/


/***************************************************
 *** Tuto poour des image a faire pixel par pixel ***
 ***************************************************/

void	*mlx_new_image(void *mlx_ptr, int width, int height);

/*
= Initialliation pour une image de largeur width et de hauteur height
= Retour
= 	\  Processus ok
=		| Un pointeur sur l'image
=	| Processus ratte
=		| Un pointeur nul
*/


char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);

/*
 = metre le pointeur sur límage deja creer
 = les autre param on s'en fous
 = Retour
 = 	\  le tableau de data a remplir
 = Conseiller caste le tableau de char en tableau de int
 */

int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
/*
= place l´image  dans la fenetre, les coordone sont celle du point en haut a gauche
*/ 

int		mlx_get_color_value(void *mlx_ptr, int color);

/*
= inutile
*/

int		mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);

int		mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);

int		mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param);

int		mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);

int		mlx_loop (void *mlx_ptr);

int 	mlx_loop_end (void *mlx_ptr);

int		mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);

void	mlx_set_font(void *mlx_ptr, void *win_ptr, char *name);

void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);

void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);

int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);

int		mlx_destroy_image(void *mlx_ptr, void *img_ptr);

int		mlx_destroy_display(void *mlx_ptr);

int		mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);

int		mlx_do_key_autorepeatoff(void *mlx_ptr);

int		mlx_do_key_autorepeaton(void *mlx_ptr);

int		mlx_do_sync(void *mlx_ptr);

int		mlx_mouse_get_pos(void *mlx_ptr, void *win_ptr, int *x, int *y);

int		mlx_mouse_move(void *mlx_ptr, void *win_ptr, int x, int y);

int		mlx_mouse_hide(void *mlx_ptr, void *win_ptr);

int		mlx_mouse_show(void *mlx_ptr, void *win_ptr);

int		mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey)