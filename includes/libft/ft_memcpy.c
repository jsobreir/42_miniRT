/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:44:27 by jsobreir          #+#    #+#             */
/*   Updated: 2024/04/19 17:43:31 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char		*source;
	char			*destination;
	size_t			i;

	source = src;
	destination = dest;
	if (!n || (!dest && !src))
		return (dest);
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	dest = destination;
	return (dest);
}

// int main(void)
// {
// 	char	dest[100];
// 	char	dest1[100];
// 	int		n;
// 	const char	*src;
// 	const char *src1;
// 	src = "Joao";
// 	src1 = "Joao";

// 	n = 3;
// 	ft_memcpy(dest, src, n);
// 	memcpy(dest1, src1, n);
// 	// printf("%p\n", ft_memcpy(dest, src, 3));
// 	//printf("%p\n", dest);
// 	// printf("%p\n", memcpy(dest, src, 3));
// 	while(n >= 0)
// 	{
// 		printf("%d\n", dest[n]);
// 		n--;
// 	}
// 	n = 3;
// 	while(n >= 0)
// 	{
// 		printf("%d\n", dest1[n]);
// 		n--;
// 	}
// }