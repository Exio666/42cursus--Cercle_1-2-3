/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_to_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:47:21 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/15 13:53:51 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2Dpoint	convertor(t_3Dpoint start)
{
	t_2Dpoint end;

	end.x = (sqrt(2) / 2) * (start.x - start.y);
	end.y = sqrt(2/3) - 
	return (end);
}