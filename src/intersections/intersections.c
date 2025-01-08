#include "minirt.h"

int hit_sphere(t_object *sphere, t_ray *ray)
{
	// Livro pagina 62
	float	i1;
	float	i2;
	float	t[2];
	t_vec3 oc;

	oc = subtract_vec3s(&ray->origin, &sphere->position);
    float a = dot_product(ray->direction, ray->direction);
    float b = 2 * dot_product(ray->direction, oc);
    float c = dot_product(oc, oc) - sphere->radius*sphere->radius;
    float discriminant = b*b - 4*a*c;
	if (discriminant < 0)
		return (0);
	i1 = -b - sqrtf(discriminant) / (2 * a);
	i2 = -b + sqrtf(discriminant) / (2 * a);
	if (i1 == i2)
	{
		t[0] = i1;
		t[1] = i1;
		return (add_intersect_list(ray, sphere, t), 1);
	}
	else if (i1 > i2) //Substituir por um ft_swap para norminette
	{
		t[0] = i1;
		t[1] = i2;
	}
	else
	{
		t[0] = i2;
		t[1] = i1;
	}
	return (add_intersect_list(ray, sphere, t), 2);
}

t_intersections	*intersect(t_ray *ray, t_scene *world)
{
	t_object			**objects;
	t_intersections		*temp;
	int			i;

	i = 0;
	objects = world->objects;
	temp = ray->intersections;
	while (objects[i])
	{
		if (objects[i]->type == SPHERE)
		{
			hit_sphere(objects[i], ray);
			temp = temp->next;
		}
	}
	return (ray->intersections);
}
