/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:45:22 by jsobreir          #+#    #+#             */
/*   Updated: 2024/04/23 16:37:05 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	if ((!dst || !src) && !size)
		return (0);
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	i = 0;
	if (size > 0 && dest_len < size - 1)
	{
		while (src[i] && dest_len + i < size - 1)
		{
			dst[dest_len + i] = src[i];
			i++;
		}
		dst[dest_len + i] = '\0';
	}
	if (dest_len >= size)
		dest_len = size;
	return (dest_len + src_len);
}

// int main(void)
// {
// 	char	dst[20] = "Joao";
// 	char	dst1[20] = "Joao";
// 	char	dst2[20] = "Joao";
// 	char	dst3[20] = "Joao";
// 	char	dst4[1] = "f";
// 	char	dst5[2] = ";k";
// 	char	dst6[0] = "";
// 	// printf("%ld\n", ft_strlcat(dst, "Barbot", 5));
// 	ft_strlcat(dst, "Barbot", 5);
// 	printf("%s\n", dst);
// 	ft_strlcat(dst1, "Barbot", 25);
// 	printf("%s\n", dst1);
// 	ft_strlcat(dst2, "Barbot", 0);
// 	printf("%s\n", dst2);
// 	ft_strlcat(dst3, "\0", 5);
// 	printf("%s\n", dst3);
// 	ft_strlcat(dst4, "Barbot", 4);
// 	printf("%s\n", dst4);
// 	ft_strlcat(dst5, "Barbot", 2);
// 	printf("%s\n", dst5);
// 	ft_strlcat(dst6, "lorem ipsum dolor sit amet", 0);
// 	printf("%s\n", dst6);
// 	printf("%ld\n", ft_strlcat(NULL, NULL, 0));
// }