/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:43:29 by jsobreir          #+#    #+#             */
/*   Updated: 2024/04/24 12:53:29 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c - 'A' <= 25 && c - 'A' >= 0) || (c - 'a' <= 25 && c - 'a' >= 0))
		return (1);
	else if (c - '0' < 10 && c - '0' >= 0)
		return (1);
	else
		return (0);
}

// #include <ctype.h>

// int	main(void)
// {
// 	char c = 'f';
// 	char d = 'A';
// 	// char f = 'Z';
// 	// char z = 'z';

// 	printf("%d\n", ft_isalnum(c));
// 	printf("%d\n\n", isalnum(c));
// 	printf("%d\n", ft_isalnum(d));
// 	printf("%d\n\n", isalnum(d));
// 	printf("%d\n", ft_isalnum(' '));
// 	printf("%d\n\n", isalnum(' '));
// 	printf("%d\n", ft_isalnum('2'));
// 	printf("%d\n\n", isalnum('2'));
// }