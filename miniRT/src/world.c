/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:31:27 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/09/17 19:08:15 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_world	*world(void)
{
	t_world	*w;

	w = (t_world *)ft_calloc(1, sizeof(t_world));
	if (!w)
		return (NULL);
	w->ambient.color = color(0, 0, 0);
	w->ambient.ratio = 0;
	w->camera = NULL;
	return (w);
}

t_intersection	*intersect_world(t_world *w, t_ray r)
{
	t_list			*current_obj_node;
	t_shape			*object;
	t_intersection	*world_xs;

	world_xs = NULL;
	current_obj_node = w->objects;
	while (current_obj_node)
	{
		object = current_obj_node->content;
		lstadd_xs_sorted(&world_xs, intersect(object, r));
		current_obj_node = current_obj_node->next;
	}
	return (world_xs);
}

t_comps	prepare_computations(t_intersection *intersection, t_ray ray)
{
	t_comps	comps;

	comps.t = intersection->t;
	comps.object = intersection->o;
	comps.point = position(ray, comps.t);
	comps.eyev = negate_tup4(ray.direction);
	comps.normalv = normal_at(comps.object, comps.point);
	if (dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = true;
		comps.normalv = negate_tup4(comps.normalv);
	}
	else
		comps.inside = false;
	comps.over_point = add_tup4(comps.point,
			multiply_tup4(comps.normalv, EPSILON * 20));
	return (comps);
}

void	put_pixel(t_canvas *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length
			+ x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	render(t_root *r)
{
	int		y;
	int		x;
	t_ray	ray;
	t_tup4	color;

	y = -1;
	while (++y < r->world->camera->vsize)
	{
		x = -1;
		while (++x < r->world->camera->hsize)
		{
			ray = ray_for_pixel(r->world->camera, x, y);
			color = color_at(r->world, ray);
			put_pixel(r->canvas, x, y, tuple_to_color(color));
		}
	}
	if (r->current_object == CAMERA)
		frame_window(r->canvas);
	mlx_put_image_to_window(r->mlx, r->win, r->canvas->img, 0, 0);
}
