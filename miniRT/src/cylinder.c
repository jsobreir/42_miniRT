/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:48:01 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/09/12 18:19:50 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cylinder	*cylinder(void)
{
	t_cylinder	*c;

	c = (t_cylinder *)ft_calloc(1, sizeof(t_cylinder));
	c->type = CYLINDER;
	c->transform = identity_matrix4();
	c->i_transform = identity_matrix4();
	c->material = material();
	c->minimum = -INFINITY;
	c->maximum = INFINITY;
	c->closed = true;
	return (c);
}

static void	add_cyl_intersections(t_cylinder *cylinder, t_ray ray,
				t_intersection **xs, float *i_value)
{
	float	y[2];
	float	tmp;

	if (i_value[0] > i_value[1])
	{
		tmp = i_value[0];
		i_value[0] = i_value[1];
		i_value[1] = tmp;
	}
	y[0] = ray.origin.y + i_value[0] * ray.direction.y;
	if (cylinder->minimum < y[0] && y[0] < cylinder->maximum)
		int_add_back(xs, intersection(i_value[0], cylinder));
	y[1] = ray.origin.y + i_value[1] * ray.direction.y;
	if (cylinder->minimum < y[1] && y[1] < cylinder->maximum)
		int_add_back(xs, intersection(i_value[1], cylinder));
	intersect_caps(cylinder, ray, xs);
}

t_intersection	*cylinder_intersect(t_cylinder *cylinder, t_ray ray)
{
	float			var[4];
	float			i_value[2];
	t_intersection	*xs;

	xs = NULL;
	var[0] = ray.direction.x * ray.direction.x
		+ ray.direction.z * ray.direction.z;
	if (ft_fcmp(var[0], 0))
		return (intersect_caps(cylinder, ray, &xs), xs);
	var[1] = 2 * ray.origin.x * ray.direction.x
		+ 2 * ray.origin.z * ray.direction.z;
	var[2] = ray.origin.x * ray.origin.x
		+ ray.origin.z * ray.origin.z - 1;
	var[3] = var[1] * var[1] - 4 * var[0] * var[2];
	if (var[3] < 0)
		return (NULL);
	i_value[0] = (-var[1] - sqrt(var[3])) / (2 * var[0]);
	i_value[1] = (-var[1] + sqrt(var[3])) / (2 * var[0]);
	xs = NULL;
	add_cyl_intersections(cylinder, ray, &xs, i_value);
	return (xs);
}

t_tup4	cylinder_normal_at(t_cylinder *c, t_tup4 object_p)
{
	float	dist;

	dist = object_p.x * object_p.x + object_p.z * object_p.z;
	if (dist < 1 && object_p.y >= c->maximum - EPSILON)
		return (vector(0, 1, 0));
	else if (dist < 1 && object_p.y <= c->minimum + EPSILON)
		return (vector(0, -1, 0));
	return (vector(object_p.x, 0, object_p.z));
}
