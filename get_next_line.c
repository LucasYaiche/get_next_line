/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:42:58 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/10 23:33:27 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*array;
	int		array_len;
	char	*returned;
	int		i;
	int		pos;

	array_len = 1;
	while (array_len != 0)
	{
		array = ft_calloc(BUFFER_SIZE);
		if (!array)
			return (NULL);
		array_len = read(fd, array, BUFFER_SIZE);
		if (array_len < 0)
			return (NULL);
		if (!array_len)
			break ;
		array += array_len;
	}
	pos = 0;
	while (*array != '\n' || *array != '\0')
	{
		returned = ft_calloc(BUFFER_SIZE);
		i = BUFFER_SIZE;
		while (i-- > 0)
			returned[pos++] = *array++;
	}
	return (returned);
}

/*
int	main()
{
	get_next_line(0);
}
*/