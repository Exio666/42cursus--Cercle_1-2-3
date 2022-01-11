/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:08:26 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/07 15:32:09 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

# include "mlx.h"
# include "libft.h"

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

typedef struct s_range_error
{
	float actual;
	float x;
	float y;
} t_range_error;

void	ft_algo_de_Bresenham(void *mlx, void *mlx_win,t_2Dpoint point_1, t_2Dpoint point_2);
int		encode_rgb(int red, int green, int blue);

#endif