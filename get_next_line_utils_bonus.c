/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:15:41 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/29 09:26:21 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_calloc(size_t len)
{
	char	*tab;
	size_t	count;

	tab = malloc(sizeof(char) * len);
	if (!tab)
		return (NULL);
	count = 0;
	while (len > count)
		tab[count++] = '\0';
	return (tab);
}

char	*ft_strdup(char *s)
{
	size_t			len;
	char			*s2;
	size_t			i;

	if (!s)
		return (NULL);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*returned;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	returned = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!returned)
		return (NULL);
	i = 0;
	j = -1;
	while (s1[++j])
		returned[i++] = s1[j];
	ft_free(&s1);
	j = -1;
	while (s2[++j])
		returned[i++] = s2[j];
	return (returned);
}

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	if (str)
		while (str[len])
			len++;
	return (len);
}

int	check(char *s, char c)
{
	int	i;

	if (s)
	{	
		i = 0;
		while (s[i])
		{
			if (s[i] == c)
				return (i);
			i++;
		}
	}
	return (-1);
}
