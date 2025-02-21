/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_caps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:06:21 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/09/09 21:07:01 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	check_cap(t_ray ray, float t)
{
	float	x;
	float	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	return ((x * x + z * z) <= 1 + EPSILON);
}

void	intersect_caps(t_cylinder *cyl, t_ray ray, t_intersection **xs)
{
	float	t;

	if (!cyl->closed || ft_fcmp(ray.direction.y, 0))
		return ;
	t = (cyl->minimum - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t))
		int_add_back(xs, intersection(t, cyl));
	t = (cyl->maximum - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t))
		int_add_back(xs, intersection(t, cyl));
}
