/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:42:58 by lyaiche           #+#    #+#             */
/*   Updated: 2021/11/22 22:11:38 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*get_next_line_2(char **keep, int array_len, int inspect)
{
	int		i;
	char	*returned;
	char	*line;

	if (array_len == -1)
	{
		ft_free(keep);
		return (NULL);
	}
	if (!*keep && array_len == 0)
		return (NULL);
	line = ft_strdup(*keep);
	//printf("%s", line);
	if (inspect == -1 && array_len == 0)
	{
		ft_free(keep);
		returned = (ft_strdup(line));
	}
	else
	{
		i = 0;
		while (line[i] && line[i] != '\n')
			i++;
		returned = ft_calloc(i + 1);
		if (!returned)
			return (NULL);
		if (line[i] == '\n' && line[i + 1] != '\0')
		{
			ft_free(keep);
			*keep = ft_strdup(&line[i + 1]);
			if (!*keep)
				return (NULL);
			line[i + 1] = '\0';
			i = -1;
			while (line[++i])
				returned[i] = line[i];
			returned[i] = '\0';
		}
		else if (line[i] == '\n' && line[i + 1] == '\0')
		{
			i = -1;
			while (++i <= inspect)
				returned[i] = line[i];
			returned[i] = '\0';
			ft_free(keep);
		}
	}
	ft_free(&line);
	//printf("%s", returned);
	return (returned);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*keep = NULL;
	int			inspect;
	int			array_len;
	char		*returned;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX - 1
		|| fd >= OPEN_MAX)
		return (NULL);
	//printf("keep =%s\n", keep);
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
	returned = get_next_line_2(&keep, array_len, inspect);
	//printf("%s", returned);
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