/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:55:33 by bpaiva-f          #+#    #+#             */
/*   Updated: 2025/02/26 13:55:34 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_atof(char *nbr)
{
	float	ret;
	int		int_part;
	int		frac_part;
	int		frac_pow;

	frac_part = 0;
	frac_pow = 1;
	int_part = ft_atoi(nbr);
	while (nbr && *nbr && *nbr != '.')
		nbr++;
	if (nbr && *nbr && *nbr == '.')
		nbr++;
	while (nbr && *nbr && (*nbr >= '0' && *nbr <= '9'))
	{
		nbr++;
		frac_pow *= 10;
	}
	frac_part = ft_atoi(nbr);
	ret = int_part + frac_part / frac_pow;
	return (ret);
}
