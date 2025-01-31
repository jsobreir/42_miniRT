#include "minirt.h"

float	dot_product(t_vec3 a, t_vec3 b)
{
	float dot;

	dot = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	return (dot);
}

t_vec3 add_vectors(t_vec3 *one, t_vec3 *two)
{
	t_vec3 new;

	new.x = one->x + two->x;
	new.y = one->y + two->y;
	new.z = one->z + two->z;
	return (new);
}

t_vec3 subtract_vec3s(t_vec3 one, t_vec3 two)
{
	t_vec3 new;

	new.x = one.x - two.x;
	new.y = one.y - two.y;
	new.z = one.z - two.z;
	return (new);
}

t_vec3 multiply_vectors(t_vec3 *one, t_vec3 *two)
{
	t_vec3 new;

	new.x = one->x * two->x;
	new.y = one->y * two->y;
	new.z = one->z * two->z;
	return (new);
}

t_vec3 divide_vectors(t_vec3 *one, t_vec3 *two)
{
	t_vec3 new;

	new.x = one->x / two->x;
	new.y = one->y / two->y;
	new.z = one->z / two->z;
	return (new);
}
