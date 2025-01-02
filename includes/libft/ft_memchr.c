/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:44:14 by jsobreir          #+#    #+#             */
/*   Updated: 2024/04/24 12:55:30 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char )c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	const void *str = "Joao";

// 	printf("%p\n", ft_memchr(str, 'o', 4));
// 	printf("%p", memchr(str, 'o', 4));
// }