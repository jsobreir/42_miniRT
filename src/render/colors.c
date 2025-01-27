/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:02:27 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/18 23:25:07 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	calculate_diffuse(t_intersections *intersection, t_scene world, t_ray *ray)
{
	t_point3 point;
	t_vec3	point_to_light;
	t_light	light;
	float	light_dot_normal;
	t_vec3	normal;
	t_vec3	object_color;
	t_vec3 ret;

	object_color = intersection->object->rgb;
	light = world.light;
	point = point_on_vec3(intersection->t[0], &ray->direction);
	normal = normal_sphere(&point, intersection->object);
	point_to_light.x =  light.position.x - point.x;
	point_to_light.y =  light.position.y - point.y;
	point_to_light.z =  light.position.z - point.z;
	point_to_light = normalize(&point_to_light);
	light_dot_normal = dot_product(point_to_light, normal);
	if (light_dot_normal < 0)
		set_color(&ret, 0, 0, 0);
	else
		ret = change_brightness(&object_color, light_dot_normal);
	return (ret);
}

int rgb_to_hex(t_vec3 *rgb)
{
    int ret;
	int color[3];

	color[0] = (int) roundf(rgb->r * 255);
	color[1] = (int) roundf(rgb->g * 255);
	color[2] = (int) roundf(rgb->b * 255);
    ret = (color[0] << 16) | (color[1] << 8) | color[2];
    return (ret);
}

t_vec3 change_brightness(t_vec3 *color, float factor)
{
    t_vec3 new;

    new.r = color->r * factor;
    new.g = color->g * factor;
    new.b = color->b * factor;

    return new;
}



t_vec3	add_colors(t_vec3 *color1, t_vec3 *color2)
{
	t_vec3 new;
	new.r = color1->r + color2->r;
	new.g = color1->g + color2->g;
	new.b = color1->b + color2->b;
	return (new);
}

t_vec3	multiply_colors(t_vec3 *color1, t_vec3 *color2)
{
	t_vec3 new;
	new.r = color1->r * color2->r;
	new.g = color1->g * color2->g;
	new.b = color1->b * color2->b;
	return (new);
}

void	set_color(t_vec3 *color, int red, int green, int blue)
{
	color->r = red/255;
	color->g = green/255;
	color->b = blue/255;
}