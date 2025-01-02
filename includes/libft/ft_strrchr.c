/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:32:36 by jsobreir          #+#    #+#             */
/*   Updated: 2024/04/24 15:49:26 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

// int main(void)
// {
// 	// char	*str = "iJoa";
//     // printf("%s\n", ft_strrchr("teste", '\0'));
//     // printf("%s\n", strrchr("sitrio", 's'));
//     //     printf("%s\n", ft_strrchr(str, '\0'));
//     // printf("%s\n", strrchr(str, '\0'));
//     //     printf("%s\n", ft_strrchr("st\0ring", '\0'));
//     // printf("%s\n", strrchr("st\0ring", '\0'));
//     //     printf("%s\n", ft_strrchr("", 'i'));
//     // printf("%s\n", strrchr("", 'i'));
//     //     printf("%s\n", ft_strrchr("yyy", 'k'));
//     // printf("%s\n", strrchr("yyy", 'k'));
//     //     printf("%s\n", ft_strrchr(str + 2, 'i'));
//     // printf("%s\n", strrchr(str + 2, 'i'));
// 	//  	 printf("%s\n", ft_strrchr("", '\0'));
//     // printf("%s\n", strrchr("", '\0'));
// 	// 	printf("%s\n", ft_strrchr("", 'i'));
//     // printf("%s\n", strrchr("", 'i'));
// 	// 	printf("%s\n", ft_strrchr("si\0d", 'i'));
//     // printf("%s\n", strrchr("si\0d", 'i'));
// }