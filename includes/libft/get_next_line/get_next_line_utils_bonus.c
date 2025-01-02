/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:56:45 by jsobreir          #+#    #+#             */
/*   Updated: 2024/06/28 13:41:59 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	while (str != NULL && str[i] != '\0')
		i++;
	return (i);
}

int	ft_strclen(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str != NULL && str[i] != '\0' && str[i] != c)
		i++;
	if (i != 0 && str[i] == '\0')
		i--;
	return (i);
}

char	*ft_strchr_gnl(char *str, char c)
{
	while (*str && *str != c)
		str++;
	if (*str == c || !c)
		return (str);
	return (NULL);
}

char	*ft_strjoin_gnl(char *dest, char *src)
{
	char	*temp;
	char	*dest_temp;
	char	*ret;
	int		len;

	len = ft_strlen_gnl(dest) + ft_strlen_gnl(src);
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	dest_temp = dest;
	temp = ret;
	while (dest != NULL && *dest)
		*(ret++) = *(dest++);
	while (*src)
		*(ret++) = *(src++);
	*ret = '\0';
	if (dest_temp)
		free(dest_temp);
	return (temp);
}

char	*ft_strndup(char *str, int n)
{
	char	*ret;
	char	*temp;

	ret = malloc((n + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	temp = ret;
	while (str != NULL && *str && n > 0)
	{
		*ret = *str;
		str++;
		ret++;
		n--;
	}
	*ret = '\0';
	return (temp);
}
