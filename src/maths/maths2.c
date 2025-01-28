/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:19:34 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/28 13:50:24 by bpaiva-f         ###   ########.fr       */
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