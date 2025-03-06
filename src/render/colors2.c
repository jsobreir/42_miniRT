/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:57:21 by bpaiva-f          #+#    #+#             */
/*   Updated: 2025/03/06 11:30:45 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rgb_to_hex(t_vec3 *rgb)
{
	int	r;
	int	g;
	int	b;

	r = fmin(fmax(roundf(rgb->r * 255), 0), 255);
	g = fmin(fmax(roundf(rgb->g * 255), 0), 255);
	b = fmin(fmax(roundf(rgb->b * 255), 0), 255);
	return ((r << 16) | (g << 8) | b);
}

t_vec3	change_brightness(t_vec3 *color, float factor)
{
	t_vec3	new;

	new.r = color->r * factor;
	new.g = color->g * factor;
	new.b = color->b * factor;
	if (new.r > 1)
		new.r = 1;
	if (new.g > 1)
		new.g = 1;
	if (new.b > 1)
		new.b = 1;
	return (new);
}

t_vec3	add_colors(t_vec3 *color1, t_vec3 *color2)
{
	t_vec3	new;

	new.r = color1->r + color2->r;
	new.g = color1->g + color2->g;
	new.b = color1->b + color2->b;
	if (new.r > 1)
		new.r = 1;
	if (new.g > 1)
		new.g = 1;
	if (new.b > 1)
		new.b = 1;
	return (new);
}

void	set_color(t_vec3 *color, int red, int green, int blue)
{
	color->r = (float)red / 255.0f;
	color->g = (float)green / 255.0f;
	color->b = (float)blue / 255.0f;
}

int	light_inside(t_object *obj, t_scene *world)
{
	float	dx;
	float	dz;
	float	distance_squared;
	t_light	*light;

	light = world->light;
	if (obj->type == SPHERE)
	{
		distance_squared = pow(light->position.x - obj->position.x, 2)
			+ pow(light->position.y - obj->position.y, 2)
			+ pow(light->position.z - obj->position.z, 2);
		if (distance_squared < obj->radius * obj->radius)
			return (1);
	}
	else if (obj->type == CYLINDER)
	{
		dx = light->position.x - obj->position.x;
		dz = light->position.z - obj->position.z;
		distance_squared = dx * dx + dz * dz;
		if (distance_squared < obj->radius * obj->radius
			&& light->position.y >= (obj->position.y - obj->height / 2)
			&& light->position.y <= (obj->position.y + obj->height / 2))
			return (1);
	}
	return (0);
}
