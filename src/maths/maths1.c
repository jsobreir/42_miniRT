#include "minirt.h"

t_vec3 mult_byscalar(t_vec3 *vec, float scalar)
{
	t_vec3 new;

	new.x = scalar * vec->x;
	new.y = scalar * vec->y;
	new.z = scalar * vec->z;

	return (new);
}

t_vec3 normalize(t_vec3 *a)
{
	t_vec3	vector;

	(void)vector;
    double length = sqrtf((a->x * a->x) + (a->y * a->y) + (a->z * a->z));
	if (length == 0)
		return (fill_vec3(&vector, 0.0, 0.0, 0.0));
    return (mult_byscalar(a, 1.0 / (float)length));
}

t_vec3 cross_product(t_vec3 a, t_vec3 b)
{
    t_vec3 result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return (result);
}

t_vec3	normal_sphere(t_point3 *point, t_object *object)
{
	t_point3 op;

	op.x = point->x - object->position.x;
	op.y = point->y - object->position.y;
	op.z = point->z - object->position.z;
	op = normalize(&op);
	return (op);
}

t_vec3	reflect(t_vec3 in, t_vec3 normal)
{
	t_vec3	ret;
	float	k;
	t_vec3	temp;

	k = 2 * dot_product(in, normal);
	temp = mult_byscalar(&normal, k);
	ret = subtract_vec3s(in, temp);
	// normalize(&ret);
	return (ret);
}