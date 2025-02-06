#include "minirt.h"

void	mtx_rotate_x(t_matrix *mtx, int degrees)
{
	degrees *= PI/180;
	mtx->matrix[1][1] *= cosf(degrees);
	mtx->matrix[1][2] *= sinf(degrees) * -1;
	mtx->matrix[2][1] *= sinf(degrees);
	mtx->matrix[2][2] *= cosf(degrees);
}

void	mtx_rotate_y(t_matrix *mtx, int degrees)
{
	degrees *= PI/180;
	mtx->matrix[0][0] *= cosf(degrees);
	mtx->matrix[0][2] *= sinf(degrees);
	mtx->matrix[2][0] *= sinf(degrees) * -1;
	mtx->matrix[2][2] *= cosf(degrees);
}

void	mtx_rotate_z(t_matrix *mtx, int degrees)
{
	degrees *= PI/180;
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

// t_matrix	*find_rotation_mtx(t_object *obj)
// {
// 	t_vec3		v;
// 	t_vec3		dir;
// 	t_matrix	*r_matrix;
// 	t_matrix	*temp;
// 	t_matrix	*k;
// 	float		cos_theta;
// 	float		sin_theta;

// 	dir = obj->orientation;
// 	fill_vec3(&v, -dir.y, dir.x, 0);
// 	cos_theta = dir.z;
// 	sin_theta = sqrtf(dir.x * dir.x + dir.y * dir.y);
// 	temp = mtx_mult_by_float(skew_symmetric(dir.x, dir.y, dir.z), sin_theta);
// 	r_matrix = mtx_add(*mtx_identity(3, 3), *temp);
// 	mtx_free(temp);

// }