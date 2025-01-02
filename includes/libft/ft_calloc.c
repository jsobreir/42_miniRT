/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:32:52 by jsobreir          #+#    #+#             */
/*   Updated: 2024/04/23 16:37:53 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	if (!size && !nmemb && nmemb > (2147483647 / size))
		return (NULL);
	ret = malloc(nmemb * size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, nmemb * size);
	return (ret);
}

// int	main(void)
// {
// 	char	*arr;
// 	size_t	nmemb;
// 	size_t	size;
// 	size_t	i;

// 	nmemb = 3;
// 	size = 0;
// 	arr = ft_calloc(nmemb, size);
// 	while (nmemb >= 0 && arr)
// 	{
// 		arr[nmemb] = 'a';
// 		nmemb--;
// 	}
// 	i = 0;
// 	printf("%s", arr);
// }
