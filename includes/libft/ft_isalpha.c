/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:43:37 by jsobreir          #+#    #+#             */
/*   Updated: 2024/04/24 15:13:59 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	else
		return (0);
}

// int	main(void)
// {
// 	char c = 'f';
// 	char d = 'A';
// 	// char f = 'Z';
// 	// char z = 'z';

// 	printf("%d", ft_isalpha(c));
// 	printf("%d", ft_isalpha(d));
// 	printf("%d", ft_isalpha(' '));
// 	printf("%d", ft_isalpha(2));
// }