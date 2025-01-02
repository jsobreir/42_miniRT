/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:43:48 by jsobreir          #+#    #+#             */
/*   Updated: 2024/04/19 18:43:29 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c - '0' < 10 && c - '0' >= 0)
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

// 	printf("%d", ft_isdigit(c));
// 	printf("%d", ft_isdigit(d));
// 	printf("%d", ft_isdigit('0'));
// 	printf("%d", ft_isdigit('9'));
// 	printf("%d", ft_isdigit());
// }