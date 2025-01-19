/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschalh <aschalh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:44:12 by aschalh           #+#    #+#             */
/*   Updated: 2025/01/19 16:07:33 by aschalh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_and_append(int fd, char **stored, char *buffer,
		size_t buffer_size)
{
	ssize_t	read_bytes;
	char	*temp;

	while ((read_bytes = read(fd, buffer, buffer_size)) > 0)
	{
		buffer[read_bytes] = '\0';
		if (!stored[fd])
		{
			if (!(stored[fd] = ft_strdup("")))
				return (NULL);
		}
		if (!(temp = ft_strjoin(stored[fd], buffer)))
			return (NULL);
		free(stored[fd]);
		stored[fd] = temp;
		if (ft_strchr(stored[fd], '\n'))
			break ;
	}
	if (read_bytes < 0)
	{
		free(stored[fd]);
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
	if (!(line = (char *)malloc(i + 1)))
		return (NULL);
	ft_strlcpy(line, *stored, i + 1);
	if ((*stored)[i])
	{
		temp = ft_strdup(*stored + i);
		free(*stored);
		*stored = temp;
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
	if (!(buffer = (char *)malloc(BUFFER_SIZE + 1)))
		return (NULL);
	if (!read_and_append(fd, stored, buffer, BUFFER_SIZE))
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	if (!stored[fd] || stored[fd][0] == '\0')
	{
		free(stored[fd]);
		stored[fd] = NULL;
		return (NULL);
	}
	return (extract_line(&stored[fd]));
}
