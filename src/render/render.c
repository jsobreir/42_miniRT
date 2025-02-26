/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:57:23 by bpaiva-f          #+#    #+#             */
/*   Updated: 2025/02/26 14:10:33 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	fill_ray(t_vec3 *normal, t_intersections *inter1,
			t_scene *world, t_ray *ray)
{
	t_point3		overpoint;
	t_vec3			direction;
	t_vec3			v;

	overpoint = add_vectors(&inter1->point, normal);
	v = subtract_vec3s(world->light->position, inter1->point);
	direction = normalize(&v);
	ray->origin = overpoint;
	ray->direction = direction;
	return (magnitude(v));
}

int	is_shadow(t_intersections *inter1, t_scene *world)
{
	float			distance;
	t_ray			ray;
	t_vec3			normal;
	t_intersections	inter2;

	init_intersections(&inter2);
	if (inter1->object->type == PLANE)
		normal = normalize(&inter1->object->orientation);
	else
		normal = normal_object(&inter1->point, inter1->object);
	if (inter1->object->type == PLANE && dot_product(normal,
			subtract_vec3s(world->light->position, inter1->point)) < 0)
		normal = mult_byscalar(&normal, -EPSILON);
	else if (inter1->object->type != CYLINDER)
		normal = mult_byscalar(&normal, EPSILON);
	distance = fill_ray(&normal, inter1, world, &ray);
	ray.intersections = &inter2;
	intersect(&ray, world);
	if (ray.intersections->t[0] != INFINITY
		&& ray.intersections->t[0] < distance)
		return (free_t(ray.intersections), 1);
	else if (ray.intersections->t[0] != INFINITY)
		return (free_t(ray.intersections), 0);
	else
		return (0);
}

void	put_pixel(int pix, int piy, t_scene *world, int iterations)
{
	char	*addr;
	int		offset;
	int		color;

	color = iterations;
	addr = world->img.addr;
	offset = piy * world->img.line_len + pix * (world->img.bpp / 8);
	addr[offset] = color & 0xFF;
	addr[offset + 1] = (color >> 8) & 0xFF;
	addr[offset + 2] = (color >> 16) & 0xFF;
}

void	handle_pixel(t_scene *world, int pix, int piy)
{
	int			color;

	color = color_pixel(pix, piy, world);
	put_pixel(pix, piy, world, color);
}

void	render_img(t_scene *world)
{
	int	x;
	int	y;

	mlx_clear_window(world->mlx, world->mlx_win);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(world, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(world->mlx, world->mlx_win,
		world->img.img, 0, 0);
}
