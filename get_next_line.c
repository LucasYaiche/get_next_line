/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:42:58 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/11 16:40:00 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*array;
	int			array_len;
	int			i;

	array = ft_calloc(BUFFER_SIZE + 1);
	if (!array)
		return (NULL);
	array_len = read(fd, array, BUFFER_SIZE);
	if (array_len < 0)
		return (NULL);
	while (array_len != 0)
	{
		buf = ft_calloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		array_len = read(fd, buf, BUFFER_SIZE);
		if (array_len < 0)
			return (NULL);
		ft_strjoin(array, buf);
		free(buf);
	}
	i = 0;
	while (array[i] != '\n')
		i++;
	buf = ft_calloc(i + 1);
	i = -1;
	while (*array != '\n')
		buf[i] = *array++;
	array++;
	return (buf);
}

/*
int	main()
{
	get_next_line(0);
}
*/