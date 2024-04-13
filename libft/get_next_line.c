/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:21:51 by nseropia          #+#    #+#             */
/*   Updated: 2023/05/17 13:14:28 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_update_static_buffer(char *static_buffer)
{
	char	*next_line;
	int		i;
	int		j;

	i = 0;
	while (static_buffer[i] != '\n' && static_buffer[i] != '\0')
		i++;
	if (!static_buffer[i])
	{
		free(static_buffer);
		return (NULL);
	}
	next_line = (char *)malloc(sizeof(char) * \
	ft_gnl_strlen(static_buffer) - i + 1);
	if (!next_line)
		return (NULL);
	i += 1;
	j = 0;
	while (static_buffer[i] != '\0')
		next_line[j++] = static_buffer[i++];
	next_line[j] = '\0';
	free(static_buffer);
	return (next_line);
}

char	*ft_get_line(char *static_buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!static_buffer[i])
		return (NULL);
	while (static_buffer[i] != '\n' && static_buffer[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (static_buffer[i] != '\n' && static_buffer[i] != '\0')
	{
		line[i] = static_buffer[i];
		i++;
	}
	if (static_buffer[i] == '\n')
	{
		line[i] = static_buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read_text(int fd, char *static_buffer)
{
	char	*buffer;
	int		read_bytes;

	buffer = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_gnl_strchr(static_buffer, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(static_buffer);
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		static_buffer = ft_gnl_strjoin(static_buffer, buffer);
	}
	free(buffer);
	return (static_buffer);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	static_buffer = ft_read_text(fd, static_buffer);
	if (!static_buffer)
	{
		free(static_buffer);
		return (NULL);
	}
	line = ft_get_line(static_buffer);
	static_buffer = ft_update_static_buffer(static_buffer);
	return (line);
}
