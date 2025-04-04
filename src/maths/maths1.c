/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:56:44 by bpaiva-f          #+#    #+#             */
/*   Updated: 2025/03/05 16:36:33 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	mult_byscalar(t_vec3 *vec, float scalar)
{
	t_vec3	new;

	new.x = scalar * vec->x;
	new.y = scalar * vec->y;
	new.z = scalar * vec->z;
	return (new);
}

t_vec3	normalize(t_vec3 *a)
{
	t_vec3	vector;
	double	length;

	(void)vector;
	length = magnitude(*a);
	if (length == 0)
		return (fill_vec3(&vector, 0.0, 0.0, 0.0));
	return (mult_byscalar(a, 1.0 / (float)length));
}

t_vec3	cross_product(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}

t_vec3	reflect(t_vec3 in, t_vec3 normal)
{
	t_vec3	ret;
	float	k;
	t_vec3	temp;

	k = 2 * dot_product(in, normal);
	temp = mult_byscalar(&normal, k);
	ret = subtract_vec3s(in, temp);
	return (ret);
}

t_vec3	multiply_colors(t_scene *world, t_intersections *inters)
{
	t_vec3	one;
	t_vec3	two;
	t_vec3	new;

	one = world->light->ambient_color_rgb;
	two = inters->object->rgb;
	new.x = one.r * two.r;
	new.y = one.g * two.g;
	new.z = one.b * two.b;
	return (new);
}
