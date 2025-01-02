/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:45:49 by jsobreir          #+#    #+#             */
/*   Updated: 2024/04/23 19:41:22 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(*little))
		return ((char *)big);
	if (!len)
		return (0);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len && big[i + j])
		{
			j++;
			if (!little[j])
				return ((char *)(&big[i]));
		}
		i++;
	}
	return (0);
}

// #include <string.h>
// int main(void)
// {
// 	const char *big;
// 	const char *little;

// 	big = "Ola eu sou o Joao";
// 	little = "Olaa";
// 	// printf("%s%s\n", "1: Ola eu sou o Joao: ", ft_strnstr(big, "Olaa", 2));
// 	// printf("%s%s\n", "2: Ola eu sou o Joao: ", ft_strnstr(big, "Ola", 2));
// 	// printf("%s%s\n", "3: Ola eu sou o Joao: ", ft_strnstr(big, "Ola", 4));
// 	// printf("%s%s\n", "4: Joao: ", ft_strnstr(big, "Joao", 40));
// 	// printf("%s%s\n", "5: Null: ", ft_strnstr(big, "Joao", 2));
// 	// printf("%s%s\n", "6: Null: ", ft_strnstr(big, "Joao", 3));
// 	// printf("%s%s\n", "7: Ola eu sou o Joao: ", ft_strnstr(big, "", 3));
// 	// printf("%s%s\n", "8: Null: ", ft_strnstr(big, "Ola", 0));
// 	// printf("%s%s\n", "9: Null: ", ft_strnstr(big, "eu", 3));
// 	// printf("%s%s\n", "10: Null: ", ft_strnstr(big, "eue", 3));
// 	printf("%s", ft_strnstr("wqqwdqw", "", 0));
// }