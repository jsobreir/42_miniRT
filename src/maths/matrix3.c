/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:56:59 by bpaiva-f          #+#    #+#             */
/*   Updated: 2025/02/26 13:57:00 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	*mtx_mult_by_float(t_matrix *mtx, float value)
{
	int			i;
	int			j;

	i = 0;
	while (i < mtx->n_rows)
	{
		j = 0;
		while (j < mtx->n_cols)
		{
			mtx->matrix[i][j] *= value;
			j++;
		}
		i++;
	}
	return (mtx);
}

t_matrix	*mtx_identity(int rows, int cols)
{
	int			i;
	int			j;
	t_matrix	*new;

	i = 0;
	new = new_mtx(rows, cols);
	while (i < new->n_rows)
	{
		j = 0;
		while (j < new->n_cols)
		{
			if (i == j)
				new->matrix[i][j] = 1;
			else
				new->matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	return (new);
}

t_matrix	*mtx_add(t_matrix a, t_matrix b)
{
	int			i;
	int			j;
	t_matrix	*new;

	if (a.n_rows != b.n_rows && a.n_cols != b.n_cols)
		return (NULL);
	new = new_mtx(a.n_rows, b.n_cols);
	new->n_rows = a.n_rows;
	new->n_cols = a.n_cols;
	i = 0;
	while (i < new->n_rows)
	{
		j = 0;
		while (j < new->n_cols)
		{
			new->matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
			j++;
		}
		i++;
	}
	return (new);
}

t_vec3	mtx_mult_vec3(t_matrix *mtx, t_vec3 *vec)
{
	t_vec3	result;

	result.x = mtx->matrix[0][0] * vec->x + mtx->matrix[0][1] * vec->y
		+ mtx->matrix[0][2] * vec->z;
	result.y = mtx->matrix[1][0] * vec->x + mtx->matrix[1][1] * vec->y
		+ mtx->matrix[1][2] * vec->z;
	result.z = mtx->matrix[2][0] * vec->x + mtx->matrix[2][1] * vec->y
		+ mtx->matrix[2][2] * vec->z;
	return (result);
}

t_point3	mtx_mult_point3(t_matrix *mtx, t_point3 *point)
{
	t_point3	result;

	result.x = mtx->matrix[0][0] * point->x + mtx->matrix[0][1] * point->y
		+ mtx->matrix[0][2] * point->z + mtx->matrix[0][3];
	result.y = mtx->matrix[1][0] * point->x + mtx->matrix[1][1] * point->y
		+ mtx->matrix[1][2] * point->z + mtx->matrix[1][3];
	result.z = mtx->matrix[2][0] * point->x + mtx->matrix[2][1] * point->y
		+ mtx->matrix[2][2] * point->z + mtx->matrix[2][3];
	return (result);
}
