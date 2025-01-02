/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:35:22 by jsobreir          #+#    #+#             */
/*   Updated: 2024/04/24 16:14:00 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char )c)
		s++;
	if (*s == (char )c || !c)
		return ((char *) s);
	return (NULL);
}

// int main(void)
// {
//     printf("%p\n", ft_strchr("teste", '\0'));
// //     // printf("%s\n", strchr("string", 'i'));
// //     //     printf("%s\n", ft_strchr("string", '\0'));
// //     // printf("%s\n", strchr("string", '\0'));
// //     //     printf("%s\n", ft_strchr("st\0ring", '\0'));
// //     // printf("%s\n", strchr("st\0ring", '\0'));
// //     //     printf("%s\n", ft_strchr("", 'i'));
// //     // printf("%s\n", strchr("", 'i'));
// //     //     printf("%s\n", ft_strchr("yyy", 'k'));
// //     // printf("%s\n", strchr("yyy", 'k'));
// //     //     printf("%s\n", ft_strchr("", 'i'));
// //     // printf("%s\n", strchr("", 'i'));
// }