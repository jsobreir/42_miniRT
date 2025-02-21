/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:09:34 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/09/16 13:29:56 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tup4	reflect(t_tup4 in, t_tup4 normal)
{
	normal = multiply_tup4(normal, 2 * dot(in, normal));
	return (subtract_tup4(in, normal));
}

static void	direct_lighting(t_light_data *data, t_tup4 effective_color,
							float light_dot_normal)
{
	float	factor;
	float	reflect_dot_eye;

	data->final_diffuse = multiply_tup4(effective_color,
			data->material.diffuse * light_dot_normal);
	reflect_dot_eye = dot(reflect(negate_tup4(data->lightv),
				data->normalv), data->eyev);
	if (reflect_dot_eye <= 0)
		data->final_specular = color(0, 0, 0);
	else
	{
		factor = pow(reflect_dot_eye, data->material.shininess);
		data->final_specular = multiply_tup4(data->light.intensity,
				data->material.specular * factor);
	}
}

t_tup4	lighting(t_light_data *data)
{
	t_tup4	effective_color;
	float	light_dot_normal;

	effective_color = hadamard(data->material.color,
			data->light.intensity);
	data->lightv = normalize(subtract_tup4(data->light.position, data->point));
	data->final_ambient = multiply_tup4(
			hadamard(data->material.color, data->ambient.color),
			data->ambient.ratio);
	light_dot_normal = dot(data->lightv, data->normalv);
	if (light_dot_normal < 0 || data->in_shadow)
	{
		data->final_diffuse = color(0, 0, 0);
		data->final_specular = color(0, 0, 0);
	}
	else
		direct_lighting(data, effective_color, light_dot_normal);
	return (add_tup4(add_tup4(data->final_ambient, data->final_diffuse),
			data->final_specular));
}

bool	is_shadowed(t_world *w, t_tup4 p)
{
	t_tup4			v;
	float			distance;
	t_tup4			direction;
	t_intersection	*h;
	t_intersection	*xs;

	v = subtract_tup4(w->light.position, p);
	distance = magnitude(v);
	direction = normalize(v);
	xs = intersect_world(w, ray(p, direction));
	h = hit(xs);
	if (h && h->t < distance)
		return (intclear(&xs), true);
	return (intclear(&xs), false);
}

t_tup4	shade_hit(t_world *w, t_comps comps)
{
	t_light_data	ld;

	ld.ambient = w->ambient;
	ld.material = ((t_shape *)comps.object)->material;
	ld.light = w->light;
	ld.point = comps.point;
	ld.eyev = comps.eyev;
	ld.normalv = comps.normalv;
	ld.in_shadow = is_shadowed(w, comps.over_point);
	return (lighting(&ld));
}
