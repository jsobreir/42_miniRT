/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:43:42 by jsobreir          #+#    #+#             */
/*   Updated: 2024/04/12 15:43:45 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// int	main(void)
// {
// 	char c = 'f';
// 	char d = 'A';
// 	// char f = 'Z';
// 	// char z = 'z';

// 	printf("%d", ft_isascii(c));
// 	printf("%d", ft_isascii(d));
// 	printf("%d", ft_isascii(' '));
// 	printf("%d", ft_isascii(2));
// }