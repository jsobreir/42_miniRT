/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:50:20 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/09/09 22:07:20 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmatrix.h"

t_matrix4	transpose_matrix4(t_matrix4 a)
{
	return (matrix4(get_column_from_matrix4(a, 0),
			get_column_from_matrix4(a, 1),
			get_column_from_matrix4(a, 2),
			get_column_from_matrix4(a, 3)));
}

t_tup4	matrix4_mult_tup4(t_matrix4 m, t_tup4 t)
{
	return (tup4(dot(m.t[0], t), dot(m.t[1], t),
			dot(m.t[2], t), dot(m.t[3], t)));
}

t_matrix4	multiply_matrix4(t_matrix4 a, t_matrix4 b)
{
	t_matrix4	result;
	int			row;
	int			col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			result.e[row][col] = dot(a.t[row], get_column_from_matrix4(b, col));
			col++;
		}
		row++;
	}
	return (result);
}

t_matrix4	invert_matrix4(t_matrix4 a)
{
	t_matrix4	transposed_cofactors;
	float		determinant;
	int			i;
	int			j;

	transposed_cofactors = transpose_matrix4(get_cofactor_matrix(a));
	determinant = determinant4(a);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			a.e[i][j] = transposed_cofactors.e[i][j] / determinant;
	}
	return (a);
}

t_matrix4	get_cofactor_matrix(t_matrix4 a)
{
	int			i;
	int			j;
	t_matrix4	out;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			out.e[i][j] = cofactor4(a, i, j);
	}
	return (out);
}
