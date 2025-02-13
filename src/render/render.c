#include "minirt.h"

int	color_pixel(int x, int y, t_scene *world)
{
	t_ray			ray;
	t_vec3			ambient_rgb;
	t_intersections	intersections;
	t_vec3 			diffuse;
	t_vec3 			specular;
	int final_color;

	init_intersections(&intersections);
	ray.intersections = &intersections;
	generate_ray(x, y, world->camera, &ray);
	intersections = *intersect(&ray, world);
	if (intersections.t[0] != INFINITY && intersections.t[0] != -INFINITY)
	{
		ambient_rgb = change_brightness(&world->light->ambient_color_rgb, world->light->ambient_lighting_ratio);
		if (is_shadow(&intersections, world))
			return (rgb_to_hex(&ambient_rgb));
		diffuse = calculate_diffuse(&intersections, *world);
		diffuse = change_brightness(&diffuse, world->light->brightness);
		if (diffuse.r || diffuse.g || diffuse.b)
			specular = calculate_specular(&intersections, *world, &ray);
		else
			set_color(&diffuse, 0, 0, 0);
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
	// free_intersections(ray.intersections);
	return (final_color);
}

int	is_shadow(t_intersections *inter1, t_scene *world)
{
	t_vec3			v;
	t_intersections inter2;
	float			distance;
	t_vec3			direction;
	t_ray			ray;
	t_point3		overpoint;
	t_vec3			normal;

	if (inter1->object->type == PLANE)
		normal = normalize(&inter1->object->orientation);
	else
		normal = normal_object(&inter1->point, inter1->object);
	//normal = normal_object(&inter1->point, inter1->object);
	normal = mult_byscalar(&normal, EPSILON);
	overpoint = add_vectors(&inter1->point, &normal);
	init_intersections(&inter2);
	v = subtract_vec3s(world->light->position, inter1->point);
	distance = magnitude(v);
	direction = normalize(&v);
	ray.origin = overpoint;
	ray.direction = direction;
	ray.intersections = &inter2;
	inter2 = *intersect(&ray, world);
	if (inter2.t[0] != INFINITY && inter2.t[0] < distance)
		return (1);
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

void render_img(t_scene *world)
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
