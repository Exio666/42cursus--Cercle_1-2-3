/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 10:24:47 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/09 10:34:04 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRLEN_H
# define STRLEN_H

# include "libunit.h"

size_t	ft_strlen(const char *s);
int		strlen_emptystr_test(void);
int		strlen_nullstr_test(void);
int		strlen_longstr_test(void);

#endif
