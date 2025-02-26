/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:56:23 by bpaiva-f          #+#    #+#             */
/*   Updated: 2025/02/26 13:56:24 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	cyl_cap_plane_check(t_ray *ray, float cap_y, float t[2])
{
	t_point3	point;

	if (t[0] > t[1])
		ft_swap(&t[0], &t[1]);
	if (t[1] < 0)
		return (0);
	if (t[0] < 0)
		t[0] = t[1];
	point = point_on_vec3(t[0], ray);
	if (point.y <= cap_y && point.y >= -cap_y)
		return (1);
	return (0);
}

float	cyl_cap_inters(t_ray *ray, t_object *cyl, float cap_y)
{
	float		t;
	t_point3	point;

	if (ray->direction.y == 0)
		return (-INFINITY);
	t = (cap_y - ray->origin.y) / ray->direction.y;
	point = point_on_vec3(t, ray);
	if (point.x * point.x + point.z * point.z <= cyl->radius * cyl->radius)
		return (t);
	return (-INFINITY);
}

static void	check_cyl_cap(t_ray *trans_ray, t_object *cyl, t_ray *ray)
{
	float	t[2];

	t[0] = cyl_cap_inters(trans_ray, cyl, cyl->height / 2);
	t[1] = cyl_cap_inters(trans_ray, cyl, -cyl->height / 2);
	check_intersections(t, &ray->intersections, cyl, ray);
}

void	hit_cylinder(t_object *cyl, t_ray *trans_ray,
			t_intersections **inters, t_ray *ray)
{
	float	a;
	float	b;
	float	c;
	float	discriminant;
	float	i[2];

	check_cyl_cap(trans_ray, cyl, ray);
	a = trans_ray->direction.x * trans_ray->direction.x
		+ trans_ray->direction.z * trans_ray->direction.z;
	b = 2 * (trans_ray->origin.x * trans_ray->direction.x
			+ trans_ray->origin.z * trans_ray->direction.z);
	c = trans_ray->origin.x * trans_ray->origin.x
		+ trans_ray->origin.z * trans_ray->origin.z - cyl->radius * cyl->radius;
	if (a == 0)
		return ;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return ;
	i[0] = (-b - sqrtf(discriminant)) / (2 * a);
	i[1] = (-b + sqrtf(discriminant)) / (2 * a);
	if (!cyl_cap_plane_check(trans_ray, cyl->height / 2, i))
		return ;
	check_intersections(i, inters, cyl, ray);
}

int	hit_plane(t_object *plane, t_ray *original,
	t_ray *ray, t_intersections **inter)
{
	float	i[2];

	if (fabs(ray->direction.y) < 1e-6)
		return (0);
	i[0] = -ray->origin.y / ray->direction.y;
	i[1] = i[0];
	if (i[0] < 0)
		return (0);
	if (i[0] > 0)
		add_intersect_list(inter, plane, i, original);
	return (1);
}
