/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:42:58 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/12 15:29:46 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*keep;
	char		*inspect;
	char		*array;
	int			array_len;
	int			i;
	char		*returned;

	array = ft_calloc(BUFFER_SIZE + 1);
	if (!array)
		return (NULL);
	inspect = NULL;
	
	while (inspect == NULL)
	{
		buf = ft_calloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		array_len = read(fd, buf, BUFFER_SIZE);
		if (array_len < 0)
			return (NULL);
		array = ft_strjoin(array, buf);
		inspect = check(array, '\n', ft_strlen(array));
		free(buf);
		if (array_len == 0)
			break ;
	}
	inspect++;
	keep = ft_strdup(inspect);
	//free(inspect);
	i = 0;
	while (array[i] != '\n')
		i++;
	returned = ft_calloc(i + 1);
	if (!returned)
		return (NULL);
	i = -1;
	while (array[++i] != '\n' && array[i] != '\0')
		returned[i] = array[i];
	if (array_len != 0)
		returned[i] = '\n';
	else
		returned[i] = '\0';
	free(array);
	return (returned);
}

/*
int	main()
{
	get_next_line(0);
}
*/