#include "minirt.h"

//apagar depois do parser estar pronto
static t_object *init_sphere(t_object *sphere)
{
	sphere->type = SPHERE;
	sphere->radius = 5;
	sphere->position.x = 0.0;
	sphere->position.y = 0.0;
	sphere->position.z = 0.0;
	sphere->rgb.x = 1;
	sphere->rgb.y = 0;
	sphere->rgb.z = 0;
	return (sphere);
}

int	color_pixel(int x, int y, t_scene *world)
{
	t_ray	ray;

	ray.intersections = NULL;
	generate_ray(x, y, world->camera, &ray);
	intersect(&ray, world);
	print_intersect_ray(ray.intersections);
	return (0);
}

void render_img(t_scene *world, t_camera *camera)
{
	int			x;
	int			y;
	(void)camera;
	x = 0;
	world->objects[0] = init_sphere(world->objects[0]);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mlx_pixel_put(world->mlx, world->mlx_win, x, y, color_pixel(x, y, world));
			y++;
		}
		x++;
	}
}
