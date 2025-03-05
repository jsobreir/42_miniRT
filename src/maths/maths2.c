/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:56:46 by bpaiva-f          #+#    #+#             */
/*   Updated: 2025/03/05 15:41:06 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// t_vec3	normal_cyl(t_point3 *point, t_vec3 op, t_object *object)
// {
// 	t_vec3	axis;
// 	t_vec3	projection;
// 	t_vec3	normal;
// 	t_vec3 	res;
// 	double	t;

// 	axis = normalize(&object->orientation);
// 	op.x = point->x - object->position.x;
// 	op.y = point->y - object->position.y;
// 	op.z = point->z - object->position.z;
// 	t = dot_product(op, axis);
// 	projection.x = object->position.x + t * axis.x;
// 	projection.y = object->position.y + t * axis.y;
// 	projection.z = object->position.z + t * axis.z;
// 	normal.x = point->x - projection.x;
// 	normal.y = point->y - projection.y;
// 	normal.z = point->z - projection.z;
// 	if (fabs(t - (object->height / 2)) < EPSILON)
// 		return (fill_vec3(&res, axis.x, axis.y, axis.z));
// 	else if (fabs(t + (object->height / 2)) < EPSILON)
// 		return (fill_vec3(&res, -axis.x, -axis.y, -axis.z));
// 	return (normal);
// }

t_vec3	normal_cyl(t_object *object, t_point3 *point)
{
	float	dist;
	t_vec3	res;

	dist = point->x * point->x + point->z * point->z;
	if (dist < (object->radius * object->radius)
		&& point->y >= (object->height / 2) - EPSILON)
		return (fill_vec3(&res, 0, -1, 0));
	else if (dist < (object->radius * object->radius)
		&& point->y <= -(object->height / 2) + EPSILON)
		return (fill_vec3(&res, 0, 1, 0));
	return (fill_vec3(&res, point->x, 0, point->z));
}

t_vec3	normal_object(t_intersections *inter, t_object *object)
{
	t_vec3	op;
	t_vec3	normal;

	op.x = 0;
	op.y = 0;
	op.z = 0;
	if (object->type == SPHERE)
	{
		op.x = inter->poriginal.x - object->position.x;
		op.y = inter->poriginal.y - object->position.y;
		op.z = inter->poriginal.z - object->position.z;
		return (normalize(&op));
	}
	else if (object->type == CYLINDER)
	{
		normal = normal_cyl(object, &inter->point);
		return (normalize(&normal));
	}
	return (op);
}
