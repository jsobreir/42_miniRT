/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_from_matrix4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:44:13 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/08/31 14:28:15 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmatrix.h"

bool	is_matrix4_invertible(t_matrix4 a)
{
	return (determinant4(a));
}

t_tup4	get_column_from_matrix4(t_matrix4 a, int i)
{
	return (tup4(a.e[0][i], a.e[1][i], a.e[2][i], a.e[3][i]));
}

t_matrix3	submatrix4(t_matrix4 a, int i, int j)
{
	t_matrix3	out;
	int			x1;
	int			y1;
	int			x2;
	int			y2;

	y1 = -1;
	y2 = 0;
	while (++y1 < 4)
	{
		if (y1 == i)
			continue ;
		x1 = -1;
		x2 = -1;
		while (++x1 < 4)
		{
			if (x1 == j)
				continue ;
			out.e[y2][++x2] = a.e[y1][x1];
		}
		y2++;
	}
	return (out);
}

float	cofactor4(t_matrix4 a, int i, int j)
{
	if ((i + j) % 2 == 0)
		return (determinant3(submatrix4(a, i, j)));
	return (-determinant3(submatrix4(a, i, j)));
}

float	determinant4(t_matrix4 a)
{
	int		i;
	float	out;

	i = -1;
	out = 0.0;
	while (++i < 4)
		out += a.e[0][i] * cofactor4(a, 0, i);
	return (out);
}
