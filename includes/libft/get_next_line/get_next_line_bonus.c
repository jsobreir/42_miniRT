/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:50:11 by jsobreir          #+#    #+#             */
/*   Updated: 2024/06/27 16:32:56 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read && BUFFER_SIZE >= 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
		if (*stash == '\0' || bytes_read < 0)
			return (free(stash), free(buffer), NULL);
		if (ft_strchr_gnl(stash, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

char	*ft_getstash(char *stash)
{
	char	*new_stash;
	int		line_len;

	line_len = ft_strclen(stash, '\n');
	new_stash = ft_strndup(stash + line_len + 1, ft_strlen_gnl(stash));
	if (!new_stash)
		return (NULL);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char		*stash[MAX_FD];
	char			*line;
	int				line_len;

	if (fd < 0 || fd > 4096)
		return (NULL);
	if (!stash[fd])
		stash[fd] = NULL;
	stash[fd] = read_file(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line_len = ft_strclen(stash[fd], '\n');
	line = ft_strndup(stash[fd], line_len + 1);
	if (!line)
		return (NULL);
	stash[fd] = ft_getstash(stash[fd]);
	if (!stash[fd])
		free(stash[fd]);
	return (line);
}
