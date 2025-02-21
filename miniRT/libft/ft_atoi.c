/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:21:23 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/09/11 09:54:54 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isstr_int(char *str)
{
	if (!str)
		return (false);
	if (!(*str == '-' || *str == '+' || ft_isdigit(*str)))
		return (false);
	str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

int	ft_atoi(const char *nptr)
{
	long	r;
	int		neg;

	neg = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	r = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		r = r * 10 + *nptr - 48;
		nptr += 1;
	}
	r *= neg;
	return ((int)r);
}
