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

t_matrix *mtx_identity(int rows, int cols)
{
	int	i;
	int	j;
	t_matrix *new;

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