/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:45:16 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/25 14:10:50 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	print_point_3d(t_3Dpoint p)
{
	printf("[%3i]", p.x);
	printf("[%3i]", p.y);
	printf("[%3i] ", p.z);
}

void	print_point_2d(t_2Dpoint p)
{
	printf("x : %i", p.x);
	printf("y : %i", p.y);
}
