/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:15:41 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/10 16:24:00 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_bzero(char *s, size_t n)
{
	size_t	count;

	count = 0;
	while (n > count)
	{
		s[count] = '\0';
		count++;
	}
	return (s);
}

char	*ft_calloc(size_t len)
{
	char	*tab;

	tab = malloc(sizeof(tab) * len);
	if (!tab)
		return (NULL);
	ft_bzero(tab, len);
	return (tab);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t;

	if (n != 0)
	{	
		t = (unsigned char *)s;
		while (n > 0)
		{
			if (*t == ((unsigned char) c))
				return (t);
			t++;
			n--;
		}
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_free(char **ptr)
{
	free(ptr);
	ptr = NULL;
}
