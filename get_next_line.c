/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:42:58 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/10 17:44:08 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*array;
	char	*next;
	int		array_len;
	char	*array_start;

	array_len = 1;
	array = ft_calloc(BUFFER_SIZE);
	array_start = array;
	free(array);
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
	while
	return (array_start);
}

/*
int	main()
{
	get_next_line(0);
}
*/