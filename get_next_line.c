/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:42:58 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/16 18:24:49 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*keep;
	char		*inspect;
	int			array_len;
	char		*returned;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	inspect = NULL;
	returned = ft_strdup(keep);
	while (inspect == NULL)
	{
		buf = ft_calloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		array_len = read(fd, buf, BUFFER_SIZE);
		if (array_len < 0)
		{
			free(buf);
			if (returned)
				free(returned);
			return (NULL);
		}
		if (array_len == 0)
		{
			free(buf);
			break ;
		}
		returned = ft_strjoin(returned, buf);
		inspect = check(buf, '\n', ft_strlen(buf));
		if (ft_strlen(inspect) > 1)
			inspect++;
		inspect = ft_strdup(inspect);
		free(buf);
	}
	if (!keep && array_len == 0)
		return (NULL);
	if (array_len != 0)
		keep = inspect++;
	if (ft_strlen(keep) == 0 || (array_len == 0 && !inspect))
	{
		free(keep);
		keep = 0;
	}
	return (returned);
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