/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschalh <aschalh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:44:12 by aschalh           #+#    #+#             */
/*   Updated: 2025/01/22 01:04:26 by aschalh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*process_stored(char **stored, int fd)
{
	if (!stored[fd])
	{
		stored[fd] = ft_strdup("");
		if (!stored[fd])
			return (NULL);
	}
	return (stored[fd]);
}

char	*read_and_append(int fd, char **stored, char *buffer,
		size_t buffer_size)
{
	ssize_t	read_bytes;
	char	*temp;

	while (1)
	{
		read_bytes = read(fd, buffer, buffer_size);
		if (read_bytes <= 0)
			break ;
		buffer[read_bytes] = '\0';
		if (!process_stored(stored, fd))
			return (NULL);
		temp = ft_strjoin(stored[fd], buffer);
		if (!temp)
			return (NULL);
		(free(stored[fd]), stored[fd] = temp);
		if (ft_strchr(stored[fd], '\n'))
			break ;
	}
	if (read_bytes < 0)
	{
		(free(stored[fd]), stored[fd] = NULL);
		return (NULL);
	}
	return (stored[fd]);
}

char	*extract_line(char **stored)
{
	char	*line;
	char	*temp;
	int		i;

	if (!stored || !*stored || **stored == '\0')
		return (NULL);
	i = 0;
	while ((*stored)[i] && (*stored)[i] != '\n')
		i++;
	if ((*stored)[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, *stored, i + 1);
	if ((*stored)[i])
	{
		temp = ft_strdup(*stored + i);
		(free(*stored), *stored = temp);
	}
	else
		(free(*stored), *stored = NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stored[1024];
	char		*buffer;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!read_and_append(fd, stored, buffer, BUFFER_SIZE))
		return (free(buffer), NULL);
	free(buffer);
	if (!stored[fd] || stored[fd][0] == '\0')
	{
		(free(stored[fd]), stored[fd] = NULL);
		return (NULL);
	}
	return (extract_line(&stored[fd]));
}
