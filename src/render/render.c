#include "minirt.h"

int	color_pixel(int x, int y, t_scene *world)
{
	t_ray	ray;
	t_vec3	ambient_rgb;
	t_intersections	intersections;
	t_vec3 	diffuse;
	t_vec3 	specular;
	int final_color;

	intersections.t[0] = INFINITY;
	intersections.t[1] = INFINITY;
	intersections.next = NULL;
	intersections.object = NULL;
	ray.intersections = &intersections;
	generate_ray(x, y, world->camera, &ray);
	intersections = *intersect(&ray, world);
	if (intersections.t[0] != INFINITY)
	{
		// set_color(&ambient_rgb, 0, 0 ,0);
		ambient_rgb = change_brightness(&world->light->ambient_color_rgb, 0.2);
		diffuse = calculate_diffuse(&intersections, *world, &ray);
		diffuse = change_brightness(&diffuse, 0.6);
		specular = calculate_specular(&intersections, *world, &ray);
	}
	else
	{
		set_color(&diffuse, 0, 0, 0);
		set_color(&specular, 0, 0, 0);
		set_color(&ambient_rgb, 0, 0 ,0);
	}
	ambient_rgb = add_colors(&ambient_rgb, &diffuse);
	ambient_rgb = add_colors(&ambient_rgb, &specular);
	final_color = rgb_to_hex(&ambient_rgb);
	return (final_color);
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

void render_img(t_scene *world, t_camera *camera)
{
	int	x;
	int	y;
	(void)camera;
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
