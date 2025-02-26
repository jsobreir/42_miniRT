#include "minirt.h"

static void	reset_colors(t_vec3 *ambient, t_vec3 *diffuse, t_vec3 *specular)
{
	set_color(diffuse, 0, 0, 0);
	set_color(specular, 0, 0, 0);
	set_color(ambient, 0, 0, 0);
}

static int	calculate_final_color(t_vec3 ambient, t_vec3 diffuse,
		t_vec3 specular, t_ray *ray)
{
	int		final_color;

	ambient = add_colors(&ambient, &diffuse);
	ambient = add_colors(&ambient, &specular);
	final_color = rgb_to_hex(&ambient);
	if (ray->intersections)
		free_t(ray->intersections);
	return (final_color);
}

int	color_pixel(int x, int y, t_scene *world)
{
	t_ray	ray;
	t_vec3	ambient;
	t_vec3	diffuse;
	t_vec3	specular;

	ray.intersections = NULL;
	generate_ray(x, y, world->camera, &ray);
	ray.intersections = intersect(&ray, world);
	if (ray.intersections && ray.intersections->t[0] != INFINITY
		&& ray.intersections->t[0] != -INFINITY)
	{
		ambient = change_brightness(&world->light->ambient_color_rgb,
				world->light->ambient_lighting_ratio);
		if (is_shadow(ray.intersections, world))
			return (free_t(ray.intersections), rgb_to_hex(&ambient));
		diffuse = calculate_diffuse(ray.intersections, *world);
		diffuse = change_brightness(&diffuse, world->light->brightness);
		if (diffuse.r || diffuse.g || diffuse.b)
			specular = calculate_specular(ray.intersections, *world, &ray);
		else
			set_color(&specular, 0, 0, 0);
	}
	else
		reset_colors(&ambient, &diffuse, &specular);
	return (calculate_final_color(ambient, diffuse, specular, &ray));
}
