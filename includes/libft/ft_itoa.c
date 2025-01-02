/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:44:01 by jsobreir          #+#    #+#             */
/*   Updated: 2024/04/23 16:33:15 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int num)
{
	int	i;

	i = 1;
	while (num <= -10 || num >= 10)
	{
		num = num / 10;
		i++;
	}
	if (num < 0)
		return (i + 1);
	else
		return (i);
}

char	*ft_itoa(int n)
{
	int				sign;
	long int		num;
	char			*ret;
	long int		len;

	num = n;
	len = intlen(num);
	ret = malloc((len + 1) * sizeof(char));
	sign = 1;
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	if (num < 0)
		sign *= -1;
	num *= sign;
	while (len-- > 0)
	{
		ret[len] = '0' + (num % 10);
		num /= 10;
	}
	if (sign == -1)
		ret[0] = '-';
	return (ret);
}

// int main (void)
// {
//     // printf("%s\num", ft_itoa());
// 	printf("%s\n", ft_itoa(-384));
// 	printf("%s\n", ft_itoa(-2147483648LL));
// 	printf("%s\n", ft_itoa(2147483647));
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(-2));
// 	printf("%s\n", ft_itoa(2));
// }