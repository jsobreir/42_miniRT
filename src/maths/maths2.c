#include "minirt.h"

t_point3	point_on_vec3(float t, t_ray *ray)
{
	t_point3	ret;
	ret.x = ray->origin.x + ray->direction.x * t;
	ret.y = ray->origin.y + ray->direction.y * t;
	ret.z = ray->origin.z + ray->direction.z * t;
	return (ret);
}

t_vec3	fill_vec3(t_vec3 *vector, float x, float y, float z)
{
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (*vector);
}
