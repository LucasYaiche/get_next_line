/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:42:58 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/17 19:30:14 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*keep;
	int			inspect;
	int			array_len;
	char		*returned;
	char		*array;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	inspect = -1;
	returned = ft_strdup(keep);
	while (inspect == -1)
	{
		buf = ft_calloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		array_len = read(fd, buf, BUFFER_SIZE);
		if (array_len < 0)
		{
			free(returned);
			free(keep);
			free(buf);
			return (NULL);
		}
		if (array_len == 0)
		{
			free(buf);
			break ;
		}
		returned = ft_strjoin(returned, buf);
		inspect = check(returned, '\n');
		free(buf);
	}
	if (inspect != -1)
	{
		inspect++;
		i = inspect;
	}
	else
		i = ft_strlen(returned);
	array = ft_calloc(i + 1);
	if (!array)
		return (NULL);
	i = 0;
	if (inspect != -1)
	{
		while (inspect > i)
		{
			array[i] = returned[i];
			i++;
		}
	}
	else
		array = ft_strdup(returned);
	free(returned);
	//printf("%p\n", array);
	return (array);
}
/*
int main(void)
{
	int fd = open("text", O_RDONLY);
	char *gnl;

	while ((gnl = get_next_line(fd)))
	{
		printf("%s", gnl);
		free(gnl);
		gnl = NULL;
	}
	return 0;
}
*/