/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:42:58 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/18 18:56:31 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*get_next_line_2(char **keep, int array_len)
{
	int		i;
	char	*array;
	char	*line;

	if (array_len < 0)
		return (NULL);
	if (!*keep && array_len <= 0)
		return (NULL);
	i = 0;
	line = ft_strdup(*keep);
	while (line[i])
	{
		if (line[i] == '\n')
			break ;
		i++;
	}
	if (line[i + 1] != '\0' && array_len > 0)
	{
		ft_free(keep);
		*keep = ft_strdup(&line[i + 1]);
	}
	else
		ft_free(keep);
	line[i + 1] = '\0';
	array = ft_calloc(i + 1);
	if (!array)
		return (NULL);
	i = -1;
	while (line[++i])
		array[i] = line[i];
	ft_free(&line);
	//write(1, "coucou\n", 7);
	return (array);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*keep = NULL;
	int			inspect;
	int			array_len;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX - 1
		|| fd >= OPEN_MAX)
		return (NULL);
	inspect = check(keep, '\n');
	buf = NULL;
	while (inspect == -1)
	{
		buf = ft_calloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		array_len = read(fd, buf, BUFFER_SIZE);
		if (array_len <= 0)
			break ;
		keep = ft_strjoin(keep, buf);
		inspect = check(keep, '\n');
		ft_free(&buf);
	}
	ft_free(&buf);
	return (get_next_line_2(&keep, array_len));
}


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
