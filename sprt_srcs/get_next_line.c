/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:37:05 by mwinter           #+#    #+#             */
/*   Updated: 2020/11/29 15:31:58 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	is_end(char **storage, char **line)
{
	if (ft_strchr(*storage, '\0'))
	{
		*line = ft_strdup(*storage);
		free(*storage);
		*storage = NULL;
	}
	return (0);
}

static int	reading_err(ssize_t reader, char **storage)
{
	if (reader < 0)
	{
		if (*storage)
		{
			free(*storage);
			*storage = NULL;
		}
		return (-1);
	}
	return (0);
}

static int	reading_res(ssize_t reader, char **storage, char **line)
{
	char *tmp;
	char *pnt;

	if (!reader && !*storage)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (reading_err(reader, &*storage))
		return (-1);
	if ((pnt = ft_strchr(*storage, '\n')))
	{
		*pnt++ = '\0';
		*line = ft_strdup(*storage);
		tmp = ft_strdup(pnt);
		if (!tmp || !*line)
			return (-1);
		free(*storage);
		*storage = tmp;
		return (1);
	}
	return (is_end(&*storage, &*line));
}

int			get_next_line(int fd, char **line)
{
	static char	*storage[1025];
	char		*buff;
	char		*tmp;
	ssize_t		reader;

	if (!line || fd < 0 || fd > 1025 || BUFFER_SIZE < 1 ||
		!(buff = (char *)malloc(BUFFER_SIZE + 1)) || (read(fd, buff, 0) < 0))
		return (-1);
	while ((reader = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[reader] = '\0';
		if (!storage[fd])
			storage[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(storage[fd], buff);
			free(storage[fd]);
			storage[fd] = tmp;
		}
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	buff = NULL;
	return (reading_res(reader, &storage[fd], &*line));
}
