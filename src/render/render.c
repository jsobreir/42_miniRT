#include "minirt.h"

int	color_pixel(int x, int y, t_scene *world)
{
	t_ray	ray;
	t_intersections	intersections;
	int diffuse;
	int ambient;

	intersections.t[0] = INFINITY;
	intersections.t[1] = INFINITY;
	intersections.next = NULL;
	intersections.object = NULL;
	ray.intersections = &intersections;
	generate_ray(x, y, world->camera, &ray);
	intersections = *intersect(&ray, world);
	diffuse = 0;
	if (intersections.t[0] != INFINITY)
	{
		ambient = rgb_to_hex(world->light.ambient_color_rgb);
		diffuse = calculate_diffuse(&intersections, *world, &ray);
	}
	else
	{
		ambient = 0;
	}
	return (ambient + diffuse);
}

void render_img(t_scene *world, t_camera *camera)
{
	int			x;
	int			y;
	(void)camera;
	x = 0;
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
