/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:45:37 by jsobreir          #+#    #+#             */
/*   Updated: 2024/04/17 10:33:56 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((*s1 == *s2) && *s1 && *s2 && n - 1 > 0)
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

// #include <string.h>
// int main(void)
// {
// 	printf("%d\n", ft_strncmp("test", "testss", 7));
// 	printf("%d\n\n", strncmp("test", "testss", 7));
// 	printf("%d\n", ft_strncmp("", "", 2));
// 	printf("%d\n\n", strncmp("", "", 2));
// 	printf("%d\n", ft_strncmp(" ", " ", 1));
// 	printf("%d\n\n", strncmp(" ", " ", 1));
// 	printf("%d\n", ft_strncmp("M", "J", 1));
// 	printf("%d\n\n", strncmp("M", "J", 1))
// 	printf("%d\n", ft_strncmp("a", "z", 0));
// 	printf("%d\n\n", strncmp("a", "z", 0));
// 	printf("%d\n", ft_strncmp("b", "a", 1));
// 	printf("%d\n\n", strncmp("b", "a", 1));
// 	printf("%d\n", ft_strncmp("abcd", "abco", 4));
// 	printf("%d\n\n", strncmp("abcd", "abco", 4));
// 	printf("%d\n", ft_strncmp("abcd", "abcA", 0));
// 	printf("%d\n", strncmp("abcd", "abcA", 0));
// }