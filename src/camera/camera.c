/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:56:16 by bpaiva-f          #+#    #+#             */
/*   Updated: 2025/02/26 13:56:17 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	calculate_dir(int x, int y, float fov, t_ray *ray)
{
	float	viewport_wh[2];
	t_vec3	direction;

	if (((float)HEIGHT / (float)WIDTH) < 1)
	{
		viewport_wh[0] = 2 * tan(fov / 2.0f) * ((float)HEIGHT / (float)WIDTH);
		viewport_wh[1] = 2 * tan(fov / 2.0f);
	}
	else
	{
		viewport_wh[0] = 2 * tan(fov / 2.0f);
		viewport_wh[1] = viewport_wh[0] / ((float)HEIGHT / (float)WIDTH);
	}
	ray->px = ((x + 0.5) / WIDTH) * viewport_wh[0] - (viewport_wh[0] / 2.0);
	ray->py = (viewport_wh[1] / 2.0) - ((y + 0.5) / HEIGHT) * viewport_wh[1];
	direction.x = ray->px * ray->right.x + ray->py * ray->up.x + ray->forward.x;
	direction.y = ray->px * ray->right.y + ray->py * ray->up.y + ray->forward.y;
	direction.z = ray->px * ray->right.z + ray->py * ray->up.z + ray->forward.z;
	ray->direction = normalize(&direction);
}

t_ray	*generate_ray(int x, int y, t_camera *camera, t_ray *ray)
{
	float	fov;
	t_vec3	world_up;

	fov = camera->fov * (PI / 180.0);
	ray->forward = camera->orientation;
	ray->origin = camera->position;
	if (fabs(ray->forward.y) > 0.9999)
		fill_vec3(&world_up, 0, 0, 1);
	else
		fill_vec3(&world_up, 0, 1, 0);
	ray->right = cross_product(ray->forward, world_up);
	ray->right = normalize(&ray->right);
	ray->up = cross_product(ray->right, ray->forward);
	ray->up = normalize(&ray->up);
	calculate_dir(x, y, fov, ray);
	return (ray);
}

// Nao tamos ainda a usar a camera. Os rays sao estaticos
// t_ray *generate_ray(int x, int y, t_camera *camera, t_ray *ray)
// {
// 	float wall_size = 7;
// 	float pixel_size = wall_size/HEIGHT;
// 	float world_x;
// 	float world_y;
// 	float wall_z = 10;
// 	(void)camera;
// 	world_x = -wall_size/2 + pixel_size * x;
// 	world_y = wall_size/2 - pixel_size * y;
// 	ray->direction.x = world_x;
// 	ray->direction.y = world_y;
// 	ray->direction.z = wall_z;
// 	ray->origin.x = 0;
// 	ray->origin.y = 0;
// 	ray->origin.z = -5;
// 	ray->direction = normalize(&ray->direction);
// 	return ray;
// }