/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:02:27 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/16 17:16:35 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	calculate_diffuse(t_intersections *intersection, t_scene world, t_ray *ray)
{
	t_point3 point;
	t_vec3	light_to_point;
	t_light	light;
	float	light_dot_normal;
	t_vec3	normal;
	int		object_color;

	object_color = rgb_to_hex(intersection->object->rgb);
	light = world.light;
	point = point_on_vec3(intersection->t[0], &ray->direction);
	normal = normal_sphere(&point, intersection->object);
	light_to_point.x = point.x - light.position.x;
	light_to_point.y = point.y - light.position.y;
	light_to_point.z = point.z - light.position.z;
	light_to_point = normalize(&light_to_point);
	light_dot_normal = dot_product(light_to_point, normal);
	return (object_color * light_dot_normal);
}

int	rgb_to_hex(int rgb[3])
{
	int	ret;
	ret = rgb[0] * rgb[1] * rgb[2];

	return (ret);
}
