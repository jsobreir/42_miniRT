#include "minirt.h"

void	mtx_rotate_x(t_matrix *mtx, int degrees)
{
	mtx->matrix[1][1] *= cosf(degrees);
	mtx->matrix[1][2] *= sinf(degrees) * -1;
	mtx->matrix[2][1] *= sinf(degrees);
	mtx->matrix[2][2] *= cosf(degrees);
}

void	mtx_rotate_y(t_matrix *mtx, int degrees)
{
	mtx->matrix[0][0] *= cosf(degrees);
	mtx->matrix[0][2] *= sinf(degrees);
	mtx->matrix[2][0] *= sinf(degrees) * -1;
	mtx->matrix[2][2] *= cosf(degrees);
}

void	mtx_rotate_z(t_matrix *mtx, int degrees)
{
	mtx->matrix[0][0] *= cosf(degrees);
	mtx->matrix[0][1] *= sinf(degrees) * -1;
	mtx->matrix[1][0] *= sinf(degrees);
	mtx->matrix[1][1] *= cosf(degrees);
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
