#include "minirt.h"
/// @brief Returns a new matrix corresponding to the transpose of the matrix passed.
/// @param mtx
/// @return 
t_matrix	*mtx_transpose(t_matrix *mtx)
{
	int	i;
	int	j;
	t_matrix *new;

	new = new_mtx(mtx->n_cols, mtx->n_rows);
	i = 0;
	while (i < mtx->n_rows)
	{
		j = 0;
		while (j < mtx->n_cols)
		{
			new->matrix[j][i] = mtx->matrix[i][j];
			j++;
		}
		i++;
	}
	return (new);
}

t_matrix	*mtx_minor(int row, int col, t_matrix *mtx)
{
	t_matrix	*minor;
	int			i;
	int			j;
	int			k;
	int			m;

	minor = new_mtx(mtx->n_rows - 1, mtx->n_cols - 1);
	i = 0;
	k = 0;
	while (k < minor->n_rows)
	{
		if (i == row)
			i++;
		j = 0;
		m = 0;
		while (m < minor->n_cols)
		{
			if (j == col)
				j++;
			minor->matrix[k][m] = mtx->matrix[i][j];
			j++;
			m++;
		}
		i++;
		k++;
	}
	return (minor);
}

t_matrix	*mtx_cofactor(t_matrix *mtx)
{
	int			i;
	int			j;
	t_matrix	*c;
	t_matrix	*minor;

	i = 0;
	c = new_mtx(mtx->n_rows, mtx->n_cols);
	while (i < mtx->n_rows)
	{
		j = 0;
		while (j < mtx->n_cols)
		{
			minor = mtx_minor(i, j, mtx);
			c->matrix[i][j] = powf(-1, i + j) * mtx_determinant(minor);
			mtx_free(minor);
			j++;
		}
		i++;
	}
	return (c);
}

t_matrix *mtx_inverse(t_scene *scene, t_matrix *mtx)
{
	t_matrix	*inv;
	t_matrix	*cof;
	float		det;
	t_matrix	*ret;

	if (mtx->n_cols != mtx->n_rows)
		clean_exit(scene, "Non-square matrix is not invertible!");
	cof = mtx_cofactor(mtx);
	inv = mtx_transpose(cof);
	mtx_free(cof);
	det = mtx_determinant(mtx);
	ret = mtx_mult_by_float(inv, 1/det);
	return (ret);
}

float	mtx_determinant(t_matrix *mtx)
{
	int		j;
	float	det;
	float	minor_det;
	t_matrix	*minor;

	j = 0;
	det = 0.0f;
	if (mtx->n_cols == 2)
		det = mtx->matrix[0][0] * mtx->matrix[1][1] - mtx->matrix[1][0] * mtx->matrix[0][1];
	else if (mtx->n_cols == 1)
		det = mtx->matrix[0][0];
	else
	{
		while (j < mtx->n_cols)
		{
			minor = mtx_minor(0, j, mtx);
			minor_det = mtx_determinant(minor);
			mtx_free(minor);
			det += powf(-1, j) * mtx->matrix[0][j] * minor_det;
			j++;
		}
	}
	return (det);
}
