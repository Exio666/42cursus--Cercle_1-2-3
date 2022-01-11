/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:21:27 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/09 14:46:00 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ATOI_H
# define FT_ATOI_H

# include "libunit.h"

int	ft_atoi(const char *nptr);
int	atoi_0(void);
int	atoi_positive(void);
int	atoi_negative(void);
int	atoi_intmin(void);
int	atoi_intmax(void);
int	atoi_overflow(void);
int	atoi_plus(void);
int	atoi_plus_minus(void);
int	atoi_whitespaces(void);

#endif