/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:56:53 by bpaiva-f          #+#    #+#             */
/*   Updated: 2025/02/26 13:56:54 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	*new_mtx(int rows, int cols)
{
	t_matrix	*new;
	int			i;

	new = malloc(sizeof(t_matrix));
	new->n_rows = rows;
	new->n_cols = cols;
	new->matrix = malloc(rows * sizeof(float *));
	i = 0;
	while (i < rows)
	{
		new->matrix[i] = malloc(cols * sizeof(float));
		i++;
	}
	return (new);
}

t_matrix	*mtx_create_fill(float **data, int rows, int cols)
{
	t_matrix	*new;
	int			i;
	int			j;

	new = new_mtx(rows, cols);
	i = 0;
	j = 0;
	new->n_cols = cols;
	new->n_rows = rows;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			new->matrix[i][j] = data[i][j];
			j++;
		}
		i++;
	}
	return (new);
}

void	mtx_free(t_matrix *mtx)
{
	int	i;

	if (!mtx)
		return ;
	i = mtx->n_rows - 1;
	while (i >= 0)
	{
		free(mtx->matrix[i]);
		i--;
	}
	free(mtx->matrix);
	free(mtx);
}

t_matrix	*mtx_multiply(t_matrix a, t_matrix b)
{
	int			i;
	int			j;
	int			k;
	float		sum;
	t_matrix	*c;

	i = 0;
	if (a.n_cols != b.n_rows)
		return (NULL);
	c = new_mtx(a.n_rows, b.n_cols);
	while (i < a.n_rows)
	{
		j = 0;
		while (j < b.n_cols)
		{
			k = -1;
			sum = 0;
			while (++k < a.n_cols)
				sum += a.matrix[i][k] * b.matrix[k][j];
			c->matrix[i][j] = sum;
			j++;
		}
		i++;
	}
	return (c);
}

t_matrix	*translate(float dx, float dy, float dz)
{
	t_matrix	*t;

	t = mtx_identity(4, 4);
	t->matrix[0][3] = dx;
	t->matrix[1][3] = dy;
	t->matrix[2][3] = dz;
	return (t);
}

// void	mtx_print(t_matrix *mtx)
// {
// 	int	i = 0;
// 	int	j = 0;

// 	printf("[  ");
// 	while (i < mtx->n_rows)
// 	{
// 		j = 0;
// 		while (j < mtx->n_cols)
// 		{
// 			printf("%f", mtx->matrix[i][j]);
// 			printf("  ");
// 			j++;
// 		}
// 		if (i != mtx->n_rows - 1 && j != mtx->n_cols - 1)
// 			printf("\n");
// 		i++;
// 	}
// 	printf("]\n");
// }