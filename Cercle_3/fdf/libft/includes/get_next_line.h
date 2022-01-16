/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 08:36:07 by bsavinel          #+#    #+#             */
/*   Updated: 2022/01/16 12:49:06 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define BUFFER_SIZE 100

/*
 *  get_next_line.c
 */

char	*ft_joinstr(char *str, char *buf);
int		ft_new_line(char *str);
void	ft_replace(char *str);
char	*get_next_line(int fd);
char	*ft_line_return(char *str, char *tab);

/*
 *  get_next_line_utils.c
 */

void	ft_replace2(char *str, char *tmp, int i, int j);
void	ft_joinstr2(char *str, char *buf, char *ret);
void	ft_bzero(void *s, size_t n);
char	*ft_end(char *str);

#endif
