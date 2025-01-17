#include "minirt.h"

// t_ray* generate_ray(int x, int y, t_camera *camera, t_ray *ray)
// {
//     ray->origin = camera->position;
// 	float viewport_width;
// 	float viewport_height;
    
//     // Calculate camera basis vectors
//     t_vec3 forward = camera->orientation;  // Already normalized
//     t_vec3 right, up;
    
//     // Calculate right vector (cross product of forward and world-up)
//     t_vec3 world_up;
// 	world_up.x = 0;
// 	world_up.y = 1;
// 	world_up.z = 0;
//     right = cross_product(forward, world_up);
//     right = normalize(&right);
    
//     // Calculate up vector
//     up = cross_product(right, forward);
//     up = normalize(&up);
    
//     // Calculate viewport dimensions
//     float fov = camera->fov * (PI / 180.0);
// 	if (ASPECT_RATIO >= 1)
// 	{
// 		viewport_width = 2 * tan(fov / 2.0f);
// 		viewport_height = viewport_width * ASPECT_RATIO;	
// 	}
// 	else
// 	{
// 		viewport_height = 2 * tan(fov / 2.0f);
// 		viewport_width = viewport_height * ASPECT_RATIO;
// 	}
//     // Convert pixel coordinates to viewport coordinates
//     // float px = (((2.0f * (float)x) / WIDTH) - 1.0f) * viewport_width *0.5;
//     // float py = (1.0f - ((2.0f * (float)y) / HEIGHT)) * viewport_height *0.5;
// 	float pixel_size = viewport_width / WIDTH;
// 	float px, py;
// 	px = (x + 0.5) * pixel_size;
// 	py = (y + 0.5) * pixel_size;

//     // Calculate ray direction using camera basis vectors
//     t_vec3 direction;
//     direction.x = px * right.x + py * up.x + forward.x;
//     direction.y = px * right.y + py * up.y + forward.y;
//     direction.z = px * right.z + py * up.z + forward.z;
//     if ((x == 0 && y==0) || (x == 402 && y == 402) || (x == 400 && y == 400))
// 	{
// 		printf("%d | %d : dx = %f, dy = %f and dz = %f\n", x, y, direction.x, direction.y, direction.z);
// 	}
//     ray->direction = normalize(&direction);
// 	    if ((x == 0 && y==0)|| (x == 402 && y == 402) || (x == 400 && y == 400))
// 	{
// 		printf("%d | %d : dx = %f, dy = %f and dz = %f\n", x, y, direction.x, direction.y, direction.z);
// 	}
//     return ray;
// }

t_ray *generate_ray(int x, int y, t_camera *camera, t_ray *ray)
{
	float wall_size = 7;
	float pixel_size = wall_size/HEIGHT;
	float world_x;
	float world_y;
	float wall_z = 10;
	(void)camera;
	world_x = -wall_size/2 + pixel_size * x;
	world_y = wall_size/2 - pixel_size * y;
	ray->direction.x = world_x;
	ray->direction.y = world_y;
	ray->direction.z = wall_z;
	ray->origin.x = 0;
	ray->origin.y = 0;
	ray->origin.z = -5;
	ray->direction = normalize(&ray->direction);
	return ray;
}