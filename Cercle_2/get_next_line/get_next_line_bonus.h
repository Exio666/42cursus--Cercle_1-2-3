/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 08:36:07 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/06 13:40:11 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

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
int		ft_strlen(char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_end(char *str);

#endif
