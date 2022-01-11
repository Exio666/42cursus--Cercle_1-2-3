/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 10:47:32 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/09 14:09:43 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISPRINT_H
# define ISPRINT_H

# include "libunit.h"
# include <stddef.h>

int	isprint_yes(void);
int	isprint_no(void);
int	isprint_limitinf(void);
int	isprint_limitsup(void);
int	ft_isprint(int c);

#endif
