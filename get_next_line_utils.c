/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:15:41 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/16 15:51:02 by lyaiche          ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*answer;
	char	*returned;

	answer = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	returned = answer;
	if (!answer)
		return (NULL);
	if (s1)
	{
		while (*s1)
			*answer++ = *s1++;
	}
	while (*s2 && *s2 != '\n')
		*answer++ = *s2++;
	if (check(s2, '\n', ft_strlen(s2)))
		*answer = '\n';
	return (returned);
}

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	if (str)
	{
		while (str[len])
			len++;
	}
	return (len);
}

char	*check(char *s, char c, size_t n)
{
	char	*t;

	if (n != 0)
	{	
		t = s;
		while (n > 0)
		{
			if (*t == c)
				return (t);
			t++;
			n--;
		}
	}
	return (NULL);
}

char	*ft_strdup(char *s)
{
	size_t			len;
	char			*s2;
	size_t			i;

	len = ft_strlen(s);
	i = 0;
	s2 = ft_calloc(len + 1);
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = s[i];
		i++;
	}
	return (s2);
}
