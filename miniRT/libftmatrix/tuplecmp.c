/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuplecmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:40:56 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/09/09 10:55:08 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmatrix.h"

bool	tup2cmp(t_tup2 a, t_tup2 b)
{
	int	i;

	i = -1;
	while (++i < 2)
	{
		if (!(fabs(a.e[i] - b.e[i]) < EPSILON))
			return (false);
	}
	return (true);
}

bool	tup3cmp(t_tup3 a, t_tup3 b)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (!(fabs(a.e[i] - b.e[i]) < EPSILON))
			return (false);
	}
	return (true);
}

bool	tup4cmp(t_tup4 a, t_tup4 b)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (!(fabs(a.e[i] - b.e[i]) < EPSILON))
			return (false);
	}
	return (true);
}
