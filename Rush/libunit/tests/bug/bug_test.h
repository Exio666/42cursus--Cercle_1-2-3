/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bug_test.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:41:50 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/09 11:51:59 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUG_TEST_H
# define BUG_TEST_H

# include "libunit.h"

int		timeout_test(void);
void	timeout_function(void);
int		bus_test(void);
void	bus_function(void);
int		sigfpe_test(void);
int		sigpipe_test(void);
int		sigill_test(void);
int		sigabrt_test(void);

#endif