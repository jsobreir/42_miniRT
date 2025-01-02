/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:44:40 by jsobreir          #+#    #+#             */
/*   Updated: 2024/04/19 17:42:15 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		*(unsigned char *)(s + i) = (unsigned char )c;
		n--;
		i++;
	}
	return (s);
}

// int main(void)
// {
// 	char s[12];
// 	// char d[12];
// 	printf("%p\n", ft_memset(s, 72, 10));
// 	printf("%p", memset(s, 72, 10));
// }
