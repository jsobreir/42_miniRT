/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamonte <joamonte@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 08:59:50 by joamonte          #+#    #+#             */
/*   Updated: 2024/09/12 09:05:04 by joamonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strlen_at(const char *str, int avoid)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != avoid)
		i++;
	return (i);
}

char	*find_chr(const char *buffer, int to_find)
{
	if (!buffer)
		return (NULL);
	while (*buffer)
	{
		if (*(unsigned char *)buffer == (unsigned char)to_find)
			return ((char *)buffer);
		buffer++;
	}
	if (*(unsigned char *)buffer == (unsigned char)to_find)
		return ((char *)buffer);
	return (NULL);
}

char	*cpy_buffer(const char *buffer, size_t len)
{
	char	*cpy;
	size_t	i;

	cpy = (char *) malloc(len + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (buffer[i] && i < len)
	{
		cpy[i] = buffer[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*merge_previous_and_current(char *previous, const char *current)
{
	size_t	len_prev;
	size_t	len_curr;
	char	*merge;

	len_prev = 0;
	len_curr = 0;
	if (previous)
		len_prev = strlen_at(previous, '\0');
	len_curr = strlen_at(current, '\0');
	merge = (char *)malloc(len_prev + len_curr + 1);
	if (!merge)
		return (NULL);
	if (previous)
		ft_memcpy(merge, previous, len_prev);
	ft_memcpy(merge + len_prev, current, len_curr);
	merge[len_prev + len_curr] = '\0';
	if (previous)
		free(previous);
	return (merge);
}
