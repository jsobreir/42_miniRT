/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:43:21 by jsobreir          #+#    #+#             */
/*   Updated: 2024/04/22 11:39:18 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		*((char *)s + i) = 0;
		i++;
		n--;
	}
}

// int main(void)
// {
// 	char str[] = "";
// 	char str1[] = "";

// 	ft_bzero(str, 0);
// 	printf("%s\n", str);
// 	bzero(str1, 0);
// 	printf("%s", str1);
// }