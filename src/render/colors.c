#include "minirt.h"

t_vec3 get_light_vec(t_intersections *intersection, t_scene world, t_vec3 point, t_ray *ray)
{
	t_light	light;
	t_vec3	point_to_light;
	
	light = *world.light;
	point = point_on_vec3(intersection->t[0], ray);
	point_to_light = subtract_vec3s(light.position, point);
	point_to_light = normalize(&point_to_light);
	return (point_to_light);
}

t_vec3 get_reflect_vec(t_vec3 vec, t_vec3 normal)
{
	t_vec3 ret;
	ret = subtract_vec3s(vec, normal);
	ret = mult_byscalar(&ret, 2 * dot_product(vec, normal));
	return (ret);
}

t_vec3	calculate_diffuse(t_intersections *intersection, t_scene world)
{
	t_vec3	point_to_light;
	t_light	light;
	float	light_dot_normal;
	t_vec3	normal;
	t_vec3	object_color;
	t_vec3 ret;

	object_color = intersection->object->rgb;
	light = *world.light;
	normal = normal_object(&intersection->point, intersection->object);
	point_to_light.x =  light.position.x - intersection->point.x;
	point_to_light.y =  light.position.y - intersection->point.y;
	point_to_light.z =  light.position.z - intersection->point.z;
	point_to_light = normalize(&point_to_light);
	light_dot_normal = dot_product(point_to_light, normal);
	if (light_dot_normal < 0)
		set_color(&ret, 0, 0, 0);
	else
		ret = change_brightness(&object_color, light_dot_normal);
	return (ret);
}

t_vec3	calculate_specular(t_intersections *intersection, t_scene world, t_ray *ray)
{
	t_vec3	reflect_vec;
	t_vec3	eye;
	float	reflect_dot_eye;
	t_vec3	inverse_light;
	t_vec3	specular;
	t_vec3	normal;
	t_vec3 white;

	inverse_light = get_light_vec(intersection, world, intersection->point, ray);
	inverse_light = mult_byscalar(&inverse_light, -1);
	normal = normal_object(&intersection->point, intersection->object);
	reflect_vec = reflect(inverse_light, normal);
	eye = mult_byscalar(&ray->direction, -1);
	reflect_dot_eye = dot_product(reflect_vec, eye);
	reflect_dot_eye = powf(reflect_dot_eye, 100.0);
	if (reflect_dot_eye <= 0)
		set_color(&specular, 0, 0, 0);
	else
	{
		set_color(&white, 255, 255, 255);
		specular = change_brightness(&white, 0.7 * reflect_dot_eye);
	}
	return (specular);
}

int rgb_to_hex(t_vec3 *rgb)
{
    int r = fmin(fmax(roundf(rgb->r * 255), 0), 255);
    int g = fmin(fmax(roundf(rgb->g * 255), 0), 255);
    int b = fmin(fmax(roundf(rgb->b * 255), 0), 255);

    return (r << 16) | (g << 8) | b;
}

t_vec3 change_brightness(t_vec3 *color, float factor)
{
    t_vec3 new;

    new.r = color->r * factor;
    new.g = color->g * factor;
    new.b = color->b * factor;

    return new;
}

t_vec3	add_colors(t_vec3 *color1, t_vec3 *color2)
{
	t_vec3 new;
	new.r = color1->r + color2->r;
	new.g = color1->g + color2->g;
	new.b = color1->b + color2->b;
	if (new.r > 1)
		new.r = 1;
	if (new.g > 1)
		new.g = 1;
	if (new.b > 1)
		new.b = 1;
	return (new);
}

// t_vec3	multiply_colors(t_vec3 *color1, t_vec3 *color2)
// {
// 	t_vec3 new;
// 	new.r = color1->r * color2->r;
// 	new.g = color1->g * color2->g;
// 	new.b = color1->b * color2->b;
// 	return (new);
// }

void	set_color(t_vec3 *color, int red, int green, int blue)
{
	color->r = (float) red/255.0f;
	color->g = (float) green/255.0f;
	color->b = (float) blue/255.0f;
}
