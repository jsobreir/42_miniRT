/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_from_matrix3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:43:45 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/08/31 14:31:12 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmatrix.h"

t_matrix2	submatrix3(t_matrix3 a, int i, int j)
{
	t_matrix2	out;
	int			x1;
	int			y1;
	int			x2;
	int			y2;

	y1 = -1;
	y2 = 0;
	while (++y1 < 3)
	{
		if (y1 == i)
			continue ;
		x1 = -1;
		x2 = -1;
		while (++x1 < 3)
		{
			if (x1 == j)
				continue ;
			out.e[y2][++x2] = a.e[y1][x1];
		}
		y2++;
	}
	return (out);
}

float	cofactor3(t_matrix3 a, int i, int j)
{
	if ((i + j) % 2 == 0)
		return (determinant2(submatrix3(a, i, j)));
	return (-determinant2(submatrix3(a, i, j)));
}

float	determinant3(t_matrix3 a)
{
	int		i;
	float	out;

	i = -1;
	out = 0.0;
	while (++i < 3)
		out += a.e[0][i] * cofactor3(a, 0, i);
	return (out);
}
