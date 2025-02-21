/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:10:03 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/09/14 09:38:30 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "errno.h"

#include <stdio.h>

static bool	check_decimals(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

bool	ft_isstr_float(char *str)
{
	if (!str)
		return (false);
	if (!ft_isdigit(*str))
	{
		if (*str != '+' && *str != '-')
			return (false);
		else
			str++;
	}
	if (!ft_isdigit(*str))
		return (false);
	while (*str && *str != '.')
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	if (!*str)
		return (true);
	str++;
	if (!ft_isdigit(*str))
		return (false);
	return (check_decimals(str));
}

static int	is_neg(char **str)
{
	if (**str == '+')
		*str += 1;
	else if (**str == '-')
	{
		*str += 1;
		return (-1);
	}
	return (1);
}

float	ft_atof(char *str)
{
	float	out;
	int		ffactor;
	float	decimal;
	int		neg;

	out = 0;
	neg = is_neg(&str);
	while (*str && *str != '.')
	{
		out = out * 10 + *str - '0';
		str++;
	}
	if (!*str)
		return (out * neg);
	str++;
	decimal = 0;
	ffactor = 0;
	while (*str)
	{
		decimal = decimal * 10 + *str - '0';
		ffactor++;
		str++;
	}
	return ((out + (decimal / ft_pow(10, ffactor))) * neg);
}
