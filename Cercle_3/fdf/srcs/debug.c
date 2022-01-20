/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:45:16 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/20 11:56:43 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void print_point_3d(t_3Dpoint p)
{
	printf("x : %i\n", p.x);
	printf("y : %i\n", p.y);
	printf("z : %i\n", p.z);
}

void print_point_2d(t_2Dpoint p)
{
	printf("x : %i", p.x);
	printf("y : %i", p.y);
}