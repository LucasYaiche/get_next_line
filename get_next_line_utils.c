/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:15:41 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/11 15:33:51 by lyaiche          ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*answer;
	char	*returned;

	if (!s1 || !s2)
		return (NULL);
	answer = ft_calloc(ft_strlen(s1) + ft_strlen(s2));
	returned = answer;
	if (!answer)
		return (NULL);
	while (*s1)
		*answer++ = *s1++;
	while (*s2)
		*answer++ = *s2++;
	*answer = '\0';
	return (returned);
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
