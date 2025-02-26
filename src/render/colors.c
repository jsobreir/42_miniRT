/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:57:17 by bpaiva-f          #+#    #+#             */
/*   Updated: 2025/02/26 14:17:12 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	get_light_vec(t_intersections *intersection, t_scene world,
			t_vec3 point, t_ray *ray)
{
	t_light	light;
	t_vec3	point_to_light;

	light = *world.light;
	point = point_on_vec3(intersection->t[0], ray);
	point_to_light = subtract_vec3s(light.position, point);
	point_to_light = normalize(&point_to_light);
	return (point_to_light);
}

t_vec3	get_reflect_vec(t_vec3 vec, t_vec3 normal)
{
	t_vec3	ret;

	ret = subtract_vec3s(vec, normal);
	ret = mult_byscalar(&ret, 2 * dot_product(vec, normal));
	return (ret);
}

t_vec3	calculate_diffuse(t_intersections *intersection, t_scene world)
{
	t_vec3	point_to_light;
	t_light	light;
	float	light_dot_normal;
	t_vec3	normal;
	t_vec3	object_color;

	object_color = intersection->object->rgb;
	light = *world.light;
	point_to_light.x = light.position.x - intersection->point.x;
	point_to_light.y = light.position.y - intersection->point.y;
	point_to_light.z = light.position.z - intersection->point.z;
	point_to_light = normalize(&point_to_light);
	if (intersection->object->type == PLANE)
		normal = intersection->object->orientation;
	else
		normal = normal_object(&intersection->point, intersection->object);
	if (dot_product(normal, point_to_light) < 0
		&& intersection->object->type == PLANE)
		normal = mult_byscalar(&normal, -1);
	light_dot_normal = dot_product(point_to_light, normal);
	light_dot_normal = fmax(light_dot_normal, 0.0);
	return (change_brightness(&object_color, light_dot_normal));
}

static float	calculate_reflect(t_vec3 inv_light, t_vec3 normal, t_ray *ray)
{
	t_vec3	eye;
	t_vec3	reflect_vec;
	float	reflect_dot_eye;

	reflect_vec = reflect(inv_light, normal);
	eye = mult_byscalar(&ray->direction, -1);
	reflect_dot_eye = dot_product(reflect_vec, eye);
	reflect_dot_eye = fmaxf(dot_product(reflect_vec, eye), 0.0);
	reflect_dot_eye = powf(reflect_dot_eye, 100.0);
	return (reflect_dot_eye);
}

t_vec3	calculate_specular(t_intersections *inter, t_scene world, t_ray *ray)
{
	float	reflect_dot_eye;
	t_vec3	inverse_light;
	t_vec3	specular;
	t_vec3	normal;
	t_vec3	white;

	inverse_light = get_light_vec(inter, world, inter->point, ray);
	inverse_light = mult_byscalar(&inverse_light, -1);
	if (inter->object->type == PLANE)
		normal = normalize(&inter->object->orientation);
	else
		normal = normal_object(&inter->point, inter->object);
	if (dot_product(normal, inverse_light) < 0)
		normal = mult_byscalar(&normal, -1);
	reflect_dot_eye = calculate_reflect(inverse_light, normal, ray);
	if (reflect_dot_eye <= 0)
		set_color(&specular, 0, 0, 0);
	else
	{
		set_color(&white, 255, 255, 255);
		specular = change_brightness(&white, 0.7 * reflect_dot_eye);
	}
	return (specular);
}
