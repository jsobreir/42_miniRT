/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:44:21 by jsobreir          #+#    #+#             */
/*   Updated: 2024/04/24 14:05:19 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)(s1);
	str2 = (unsigned char *)(s2);
	while (i < n)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	// const void *str1 = "Joa", *str2 = "Joao";
// 	// printf("%d\n", ft_memcmp(str1, str2, 3));
// 	// printf("%d\n", memcmp(str1, str2, 3));
// 	printf("%d\n", ft_memcmp("sssA", "sssJ", 4));
// 	// printf("%d\n", memcmp("sssA", "sssJ", 4));
// 	printf("%d\n", ft_memcmp("sssJ", "sssA", 4));
// 	// printf("%d\n", memcmp("sssJ", "sssA", 4));
// // 	printf("%d\n", ft_memcmp("J", "A", 0));
// // 	printf("%d\n", memcmp("J", "A", 0));
// // 	printf("%d\n", ft_memcmp("J", "g\0", 1));
// // 	printf("%d\n", memcmp("J", "g\0", 1));
// }