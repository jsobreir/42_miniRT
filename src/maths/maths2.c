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

float	magnitude(t_vec3 a)
{
	float	mag;

	mag = sqrtf((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
	return (mag);
}

t_vec3	normal_cyl(t_point3 *point, t_vec3 op, t_object *object)
{
	t_vec3	axis;
	t_vec3	projection;
	t_vec3	normal;
	double	t;

	axis = normalize(&object->orientation);
	op.x = point->x - object->position.x;
	op.y = point->y - object->position.y;
	op.z = point->z - object->position.z;
	t = dot_product(op, axis);
	projection.x = object->position.x + t * axis.x;
	projection.y = object->position.y + t * axis.y;
	projection.z = object->position.z + t * axis.z;
	normal.x = point->x - projection.x;
	normal.y = point->y - projection.y;
	normal.z = point->z - projection.z;
	return (normal);
}

t_vec3	normal_object(t_point3 *point, t_object *object)
{
	t_vec3	op;
	t_vec3	normal;

	op.x = 0;
	op.y = 0;
	op.z = 0;
	if (object->type == SPHERE)
	{
		op.x = point->x - object->position.x;
		op.y = point->y - object->position.y;
		op.z = point->z - object->position.z;
		return (normalize(&op));
	}
	else if (object->type == CYLINDER)
	{
		normal = normal_cyl(point, op, object);
		return (normalize(&normal));
	}
	return (op);
}
