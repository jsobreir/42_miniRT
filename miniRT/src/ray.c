/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamonte <joamonte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:26:23 by joamonte          #+#    #+#             */
/*   Updated: 2024/09/05 11:51:05 by joamonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ray(t_tup4 origin, t_tup4 direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_tup4	position(t_ray ray, float t)
{
	t_tup4	point;

	point.x = ray.origin.x + ray.direction.x * t;
	point.y = ray.origin.y + ray.direction.y * t;
	point.z = ray.origin.z + ray.direction.z * t;
	point.w = TPOINT;
	return (point);
}

t_ray	transform(t_ray ray, t_matrix4 matrix)
{
	t_ray	new_ray;

	new_ray.origin = matrix4_mult_tup4(matrix, ray.origin);
	new_ray.origin.w = TPOINT;
	new_ray.direction = matrix4_mult_tup4(matrix, ray.direction);
	new_ray.direction.w = TVECTOR;
	return (new_ray);
}
