/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:44:35 by jsobreir          #+#    #+#             */
/*   Updated: 2024/04/19 18:36:53 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	i = (int)n - 1;
	if (!src && !dest)
		return (NULL);
	if (dest > src)
	{
		while (i >= 0)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dest);
}
// int	main(void)
// {
// 	char		*dest;
// 	const char	*src;
// 	src = "JodfBart";
// 	dest = "Joaotdddd";
// 	printf("%p\n", dest);
// 	ft_memmove(dest, src, 5);
// }
