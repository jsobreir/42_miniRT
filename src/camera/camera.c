#include "minirt.h"

t_ray* generate_ray(int x, int y, t_camera *camera, t_ray *ray)
{
	t_vec3	right;
	t_vec3	up;
	t_vec3	forward;
    t_vec3	world_up;
    t_vec3	direction;
	float	viewport_width;
	float	viewport_height;
	float	px;
	float	py;
	//float	pixel_size;
    float	fov = camera->fov * (PI / 180.0);

	forward = camera->orientation;//Already normalized
    ray->origin = camera->position;
	fill_vec3(&world_up, 0, 1, 0);
    right = cross_product(forward, world_up);
    right = normalize(&right);
    up = cross_product(right, forward);// Calculate Up vector (of the camera window)
    up = normalize(&up);
	if (ASPECT_RATIO < 1)
	{
		viewport_width = 2 * tan(fov / 2.0f) * ASPECT_RATIO;
		viewport_height = 2 * tan(fov / 2.0f);
	} else
	{
		viewport_width = 2 * tan(fov / 2.0f);
		viewport_height = viewport_width / ASPECT_RATIO;
	}
	//pixel_size  = viewport_width / WIDTH;
	px = ((x + 0.5) / WIDTH) * viewport_width - (viewport_width / 2.0);
	py = (viewport_height / 2.0) - ((y + 0.5) / HEIGHT) * viewport_height;
	direction.x = px * right.x + py * up.x + forward.x;
	direction.y = px * right.y + py * up.y + forward.y;
	direction.z = px * right.z + py * up.z + forward.z;
	ray->direction = normalize(&direction);
    return ray;
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