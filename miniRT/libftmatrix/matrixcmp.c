/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:35:49 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/09/09 22:07:12 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmatrix.h"

bool	matrix2cmp(t_matrix2 a, t_matrix2 b)
{
	int	i;

	i = -1;
	while (++i < 2)
	{
		if (!tup2cmp(a.t[i], b.t[i]))
			return (false);
	}
	return (true);
}

bool	matrix3cmp(t_matrix3 a, t_matrix3 b)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (!tup3cmp(a.t[i], b.t[i]))
			return (false);
	}
	return (true);
}

bool	matrix4cmp(t_matrix4 a, t_matrix4 b)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (!tup4cmp(a.t[i], b.t[i]))
			return (false);
	}
	return (true);
}
