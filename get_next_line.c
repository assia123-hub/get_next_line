/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschalh <aschalh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:51:40 by aschalh           #+#    #+#             */
/*   Updated: 2025/01/22 01:07:45 by aschalh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*process_stored(char *stored)
{
	if (!stored)
	{
		stored = ft_strdup("");
		if (!stored)
			return (NULL);
	}
	return (stored);
}

char	*read_and_append(int fd, char *stored, char *buffer, size_t buffer_size)
{
	ssize_t	read_bytes;
	char	*temp;

	stored = process_stored(stored);
	if (!stored)
		return (NULL);
	while (1)
	{
		read_bytes = read(fd, buffer, buffer_size);
		if (read_bytes <= 0)
			break ;
		buffer[read_bytes] = '\0';
		temp = ft_strjoin(stored, buffer);
		if (!temp)
			return (free(stored), NULL);
		(free(stored), stored = temp);
		if (ft_strchr(stored, '\n'))
			break ;
	}
	if (read_bytes < 0)
		return (free(stored), NULL);
	return (stored);
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
		if (!temp)
			return (free(line), NULL);
		(free(*stored), *stored = temp);
	}
	else
		(free(*stored), *stored = NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stored;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	stored = read_and_append(fd, stored, buffer, BUFFER_SIZE);
	free(buffer);
	if (!stored || stored[0] == '\0')
	{
		(free(stored), stored = NULL);
		return (NULL);
	}
	return (extract_line(&stored));
}
