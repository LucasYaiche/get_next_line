/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:43:20 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/17 16:36:59 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_calloc(size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
int		check(char *s, char c);
char	*ft_strdup(char *s);

#endif