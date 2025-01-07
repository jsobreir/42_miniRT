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
    double length = sqrt(a->x * a->x + a->y * a->y + a->z * a->z);
	*a = mult_byscalar(a, 1.0 / length);
    return (*a);
}

t_vec3 cross_product(t_vec3 a, t_vec3 b)
{
    t_vec3 result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return (result);
}