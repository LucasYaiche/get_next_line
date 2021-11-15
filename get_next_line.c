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
	int			array_len;
	int			i;
	char		*returned;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	inspect = NULL;
	while (inspect == NULL)
	{
		buf = ft_calloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		array_len = read(fd, buf, BUFFER_SIZE);
		if (array_len < 0)
		{
			free(buf);
			free(keep);
			return (NULL);
		}
		if (array_len == 0)
		{
			free(buf);
			break ;
		}
		keep = ft_strjoin(keep, buf);
		inspect = check(buf, '\n', ft_strlen(buf));
		free(buf);
	}
	if (!keep && array_len == 0)
		return (NULL);
	i = 0;
	while (keep[i] != '\n' && keep[i] != '\0')
		i++;
	returned = ft_calloc(i + 1);
	if (!returned)
		return (NULL);
	i = -1;
	while (keep[++i] != '\n' && keep[i] != '\0')
		returned[i] = keep[i];
	if (inspect != 0)
	{
		returned[i] = '\n';
		inspect++;
		keep = ft_strdup(inspect);
		free(inspect);
	}
	else
		free(keep);
	return (returned);
}
