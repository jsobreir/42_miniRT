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
    double length;

	length = magnitude(*a);
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

t_vec3 normal_object(t_point3 *point, t_object *object)
{
    t_vec3 op, axis, projection, normal;
    double t;

	op.x = 0;
	op.y = 0;
	op.z = 0;
    if (object->type == SPHERE)
    {
        op.x = point->x - object->position.x;
        op.y = point->y - object->position.y;
        op.z = point->z - object->position.z;
        return normalize(&op);
    }
    else if (object->type == CYLINDER)
    {
        axis = normalize(&object->orientation);  // Cylinder's axis direction (should be a unit vector)
        
        // Compute projection of (point - cylinder_center) onto the axis
        op.x = point->x - object->position.x;
        op.y = point->y - object->position.y;
        op.z = point->z - object->position.z;
        
        t = dot_product(op, axis); // Scalar projection
        projection.x = object->position.x + t * axis.x;
        projection.y = object->position.y + t * axis.y;
        projection.z = object->position.z + t * axis.z;
        
        // Compute normal as the difference between the point and its projection on the axis
        normal.x = point->x - projection.x;
        normal.y = point->y - projection.y;
        normal.z = point->z - projection.z;

        return normalize(&normal);
    }
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